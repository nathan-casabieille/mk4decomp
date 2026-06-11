#!/usr/bin/env python3
"""MK4 no-Wine boot via embedded x86 emulation. Iteration 2: boot-critical
stubs (heap/module/startup) + correct __stdcall cleanup, to push past CRT init."""
import struct
from unicorn import *
from unicorn.x86_const import *

EXE='game/MK4.EXE'; IMG=0x400000; STACK=0x200000; STACK_SZ=0x100000
TEB=0x7efdd000; PEB=0x7efde000; GDT=0x80000000; HOOK=0x70000000
HEAP=0x10000000; HEAP_END=0x18000000

d=open(EXE,'rb').read(); pe=struct.unpack_from('<I',d,0x3c)[0]
nsec=struct.unpack_from('<H',d,pe+6)[0]; opt=pe+24; sh=opt+struct.unpack_from('<H',d,pe+20)[0]
secs=[]
for i in range(nsec):
    o=sh+i*40; secs.append(struct.unpack_from('<IIII',d,o+8))  # vsz,va,rsz,rptr
imp_rva=struct.unpack_from('<I',d,opt+96+8)[0]
def rva2off(rva):
    for vsz,va,rsz,rptr in secs:
        if va<=rva<va+max(vsz,rsz): return rptr+(rva-va)
    return None

uc=Uc(UC_ARCH_X86,UC_MODE_32)
uc.mem_map(IMG,0x1000000)
for vsz,va,rsz,rptr in secs: uc.mem_write(IMG+va,d[rptr:rptr+rsz])
uc.mem_map(STACK,STACK_SZ); uc.mem_map(TEB&~0xfff,0x4000); uc.mem_map(GDT,0x1000)
uc.mem_map(HOOK,0x1000); uc.mem_map(HEAP, HEAP_END-HEAP)
uc.mem_write(TEB+0x18,struct.pack('<I',TEB)); uc.mem_write(TEB+0x30,struct.pack('<I',PEB))
def g(base,lim,acc,fl): return struct.pack('<Q',(lim&0xffff)|((base&0xffffff)<<16)|((acc&0xff)<<40)|(((lim>>16)&0xf)<<48)|((fl&0xf)<<52)|(((base>>24)&0xff)<<56))
uc.mem_write(GDT+0x08,g(0,0xfffff,0x9b,0xc)); uc.mem_write(GDT+0x10,g(0,0xfffff,0x93,0xc)); uc.mem_write(GDT+0x18,g(TEB,0xfff,0x93,0x4))
uc.reg_write(UC_X86_REG_GDTR,(0,GDT,0x1000,0)); 
for r in (UC_X86_REG_DS,UC_X86_REG_ES,UC_X86_REG_SS): uc.reg_write(r,0x10)
uc.reg_write(UC_X86_REG_CS,0x08); uc.reg_write(UC_X86_REG_FS,0x18)
uc.reg_write(UC_X86_REG_ESP,STACK+STACK_SZ-0x100); uc.reg_write(UC_X86_REG_EBP,STACK+STACK_SZ-0x100)

slot2name={}; sent=HOOK
io=rva2off(imp_rva); dn=0
while True:
    oft,ts,fwd,namerva,ft=struct.unpack_from('<IIIII',d,io+dn*20)
    if namerva==0 and ft==0: break
    dll=d[rva2off(namerva):].split(b'\x00')[0].decode('latin1'); lookup=oft or ft; k=0
    while True:
        ent=struct.unpack_from('<I',d,rva2off(lookup)+k*4)[0]
        if ent==0: break
        fn=('%s#%d'%(dll,ent&0xffff)) if ent&0x80000000 else d[rva2off(ent)+2:].split(b'\x00')[0].decode('latin1')
        uc.mem_write(IMG+ft+k*4,struct.pack('<I',sent)); slot2name[sent]=fn; sent+=4; k+=1
    dn+=1

hp=[HEAP+0x1000]
def halloc(n):
    p=hp[0]; hp[0]=(hp[0]+n+0xf)&~0xf; return p if hp[0]<HEAP_END else 0
STRP=halloc(0x100); uc.mem_write(STRP,b'MK4.EXE\x00')
# name -> (argcount, handler(args)->eax)
def H(fn,esp):
    a=lambda i: struct.unpack('<I',uc.mem_read(esp+4+i*4,4))[0]
    if fn=='GetVersion': return 0,0xC0000A04
    if fn in('HeapCreate',): return 3, (HEAP|1)
    if fn=='HeapAlloc': return 3, halloc(a(2) or 16)
    if fn=='HeapReAlloc': return 4, halloc(a(3) or 16)
    if fn in('HeapFree','HeapDestroy'): return (3 if fn=='HeapFree' else 1),1
    if fn=='VirtualAlloc': return 4, halloc(a(1) or 0x1000)
    if fn=='GetModuleHandleA': return 1, IMG
    if fn=='GetCommandLineA': return 0, STRP
    if fn=='GetStartupInfoA': uc.mem_write(a(0),b'\x00'*0x44); return 1,0
    if fn=='GetStdHandle': return 1,1
    if fn=='GetCurrentProcess' or fn=='GetCurrentThread': return 0,0xffffffff
    if fn in('GetACP','GetOEMCP'): return 0,437
    if fn=='GetCPInfo': return 2,1
    if fn.startswith('GetEnvironmentStrings'): return 0,STRP
    if fn=='GetModuleFileNameA': uc.mem_write(a(1),b'C:\\MK4.EXE\x00'); return 3,9
    if fn in('InitializeCriticalSection','EnterCriticalSection','LeaveCriticalSection','DeleteCriticalSection'): return 1,0
    # default: assume 0 args cleanup-wise is unsafe; guess from a small table else 1
    return None, 0
ARGS={
 # kernel32
 'TlsAlloc':0,'TlsSetValue':2,'TlsGetValue':1,'TlsFree':1,'SetHandleCount':1,'GetFileType':1,
 'GetStdHandle':1,'GetStringTypeW':5,'GetStringTypeA':5,'LCMapStringW':6,'LCMapStringA':6,
 'MultiByteToWideChar':6,'WideCharToMultiByte':8,'GetProcAddress':2,'LoadLibraryA':1,'FreeLibrary':1,
 'GetLastError':0,'SetLastError':1,'GetCurrentThreadId':0,'GetTickCount':0,'GetSystemTimeAsFileTime':1,
 'QueryPerformanceCounter':1,'RtlUnwind':4,'GetProcessHeap':0,'SetUnhandledExceptionFilter':1,
 'UnhandledExceptionFilter':1,'ExitProcess':1,'TerminateProcess':2,'CloseHandle':1,'CreateFileA':7,
 'CreateFileMappingA':6,'MapViewOfFile':5,'UnmapViewOfFile':1,'ReadFile':5,'WriteFile':5,'SetFilePointer':4,
 'GetFileSize':2,'FlushFileBuffers':1,'CreateThread':6,'GetCurrentThread':0,'GetCurrentProcess':0,
 'GetThreadPriority':1,'SetThreadPriority':2,'GetPriorityClass':1,'SetPriorityClass':2,'Sleep':1,
 'GetCommandLineA':0,'GetModuleHandleA':1,'GetModuleFileNameA':3,'GetStartupInfoA':1,'GetVersion':0,
 'GetVersionExA':1,'GetACP':0,'GetOEMCP':0,'GetCPInfo':2,'GetEnvironmentStrings':0,'GetEnvironmentStringsW':0,
 'FreeEnvironmentStringsA':1,'FreeEnvironmentStringsW':1,'GetEnvironmentVariableA':3,'GetDriveTypeA':1,
 'GetLogicalDrives':0,'GetFileAttributesA':1,'HeapAlloc':3,'HeapFree':3,'HeapReAlloc':4,'HeapCreate':3,
 'HeapDestroy':1,'HeapSize':3,'VirtualAlloc':4,'VirtualFree':3,'InitializeCriticalSection':1,
 'EnterCriticalSection':1,'LeaveCriticalSection':1,'DeleteCriticalSection':1,'InterlockedIncrement':1,
 'InterlockedDecrement':1,'GetLocaleInfoA':4,'GetLocaleInfoW':4,'SetStdHandle':2,
 # user32
 'RegisterClassA':1,'RegisterClassExA':1,'CreateWindowExA':12,'DefWindowProcA':4,'DestroyWindow':1,
 'ShowWindow':2,'UpdateWindow':1,'GetMessageA':4,'PeekMessageA':5,'TranslateMessage':1,'DispatchMessageA':1,
 'PostQuitMessage':1,'PostMessageA':4,'SendMessageA':4,'GetActiveWindow':0,'SetActiveWindow':1,
 'GetForegroundWindow':0,'SetForegroundWindow':1,'GetClientRect':2,'GetWindowRect':2,'AdjustWindowRect':3,
 'GetWindowLongA':2,'SetWindowLongA':3,'GetWindowPlacement':2,'SetWindowPlacement':2,'GetSystemMetrics':1,
 'LoadCursorA':2,'LoadIconA':2,'GetAsyncKeyState':1,'GetKeyState':1,'MapVirtualKeyA':2,'GetCursorPos':1,
 'SetCursorPos':2,'ShowCursor':1,'GetMenu':1,'BeginPaint':2,'EndPaint':2,'InvalidateRect':3,'FillRect':3,
 'MessageBoxA':4,'MessageBeep':1,'wsprintfA':-1,'GetDC':1,'ReleaseDC':2,
 # gdi32
 'CreateDIBSection':6,'DeleteObject':1,'GetDeviceCaps':2,'GetStockObject':1,'GdiFlush':0,
 'BitBlt':9,'StretchBlt':11,'SetDIBitsToDevice':12,
 # ddraw/dsound/winmm
 'DirectDrawCreate':3,'DirectDrawEnumerateA':2,'DirectSoundCreate':3,
 'timeGetTime':0,'timeBeginPeriod':1,'timeEndPeriod':1,'mciSendCommandA':4,'auxGetVolume':2,'auxSetVolume':2,
}
calls=[]; stop=[None]; unhandled=set()
def hook_code(uc,addr,size,ud):
    if HOOK<=addr<HOOK+0x1000:
        fn=slot2name.get(addr,'?'); calls.append(fn)
        esp=uc.reg_read(UC_X86_REG_ESP)
        nargs,eax=H(fn,esp)
        if nargs is None:
            nargs=ARGS.get(fn,None)
            if nargs is None: unhandled.add(fn); nargs=0
        ret=struct.unpack('<I',uc.mem_read(esp,4))[0]
        uc.reg_write(UC_X86_REG_ESP, esp+4+nargs*4)
        uc.reg_write(UC_X86_REG_EAX, eax); uc.reg_write(UC_X86_REG_EIP, ret)
uc.hook_add(UC_HOOK_CODE,hook_code,begin=HOOK,end=HOOK+0x1000)
def unm(uc,acc,addr,size,val,ud):
    stop[0]='unmapped 0x%x eip=0x%x'%(addr,uc.reg_read(UC_X86_REG_EIP)); return False
uc.hook_add(UC_HOOK_MEM_UNMAPPED,unm)
entry=IMG+struct.unpack_from('<I',d,opt+16)[0]
try: uc.emu_start(entry,0,count=5000000); stop[0]='cap/done'
except UcError as e: stop[0]='%s eip=0x%x'%(e,uc.reg_read(UC_X86_REG_EIP))
seen=[]
for c in calls:
    if not seen or seen[-1]!=c: seen.append(c)
print('stop:',stop[0]); print('IAT calls:',len(calls),'distinct seq:',len(seen))
print('  '+' '.join(seen[:80]))
if unhandled: print('UNHANDLED (need arg counts):', sorted(unhandled))
