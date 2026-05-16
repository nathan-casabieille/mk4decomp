/**
 * Fortieth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c6510 (45b)
 *   call F; mul-by-N pattern via lea/shl on [eax + 0x14];
 *   ((x * 13 << 4) + x) << 8 - x → effectively x * (13<<12 - 1) etc.
 *   adds 0x269ec3, stores back, returns shr 0x10 & 0x7fff.
 */
extern void *PendingMatch_004c9df0(void);
__declspec(naked) void Crt_rand(void) {
    __asm {
        call    PendingMatch_004c9df0
        mov     ecx, dword ptr [eax + 0x14]
        lea     edx, [ecx + ecx*2]
        lea     edx, [ecx + edx*4]
        shl     edx, 4
        add     edx, ecx
        shl     edx, 8
        sub     edx, ecx
        lea     ecx, [ecx + edx*4 + 0x00269ec3]
        mov     dword ptr [eax + 0x14], ecx
        mov     eax, ecx
        shr     eax, 0x10
        and     eax, 0x7fff
        ret
    }
}

/* @addr 0x004c67f0 (48b)
 *   if (g_state_0051ffd8) (*g_state_0051ffd8)();
 *   call 0x4c6940(0x4d501c, 0x4d5024); add esp 8;
 *   call 0x4c6940(0x4d5000, 0x4d5018); add esp 8; ret.
 */
extern void (*g_iat_0051ffd8)(void);
extern int IterFnPtrs_004c6940(void *, void *);
extern void *g_data_004d5000;
extern void *g_data_004d5018;
extern void *g_data_004d501c;
extern void *g_data_004d5024;
__declspec(naked) void _init_premain(void) {
    __asm {
        mov     eax, dword ptr [g_iat_0051ffd8]
        test    eax, eax
        _emit   74h
        _emit   02h
        call    eax
        push    OFFSET g_data_004d5024
        push    OFFSET g_data_004d501c
        call    IterFnPtrs_004c6940
        add     esp, 8
        push    OFFSET g_data_004d5018
        push    OFFSET g_data_004d5000
        call    IterFnPtrs_004c6940
        add     esp, 8
        ret
    }
}

/* @addr 0x004c6960 (53b)
 *   call F1(arg); if (eax != 0) return -1;
 *   if (arg.flags & 0x4000) return arg.field10 ? -1 : 0;
 *   else return 0.
 */
extern int FFlushImpl_004c69a0(int);
extern int FileTableClose_004cb700(int);
__declspec(naked) void CallTestPushSubCall_004c6960(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        push    esi
        call    FFlushImpl_004c69a0
        add     esp, 4
        test    eax, eax
        _emit   74h
        _emit   05h
        or      eax, 0xffffffff
        pop     esi
        ret
        mov     eax, dword ptr [esi + 0x0c]
        test    ah, 0x40
        _emit   74h
        _emit   12h
        mov     eax, dword ptr [esi + 0x10]
        push    eax
        call    FileTableClose_004cb700
        add     esp, 4
        neg     eax
        sbb     eax, eax
        pop     esi
        ret
        xor     eax, eax
        pop     esi
        ret
    }
}

/* @addr 0x004c6e90 (39b)
 *   if g_state_00f9f84c == 1, call F; then call F2(arg);
 *   call IAT [g_iat_004d2154](0xff); ret.
 *   (variant of 0x004c6e60 with different IAT.)
 */
extern unsigned int g_state_00f9f84c_ee;
extern void func_004cc030_ee(void);
extern void func_004cc070_ee(int);
extern void (*g_iat_004d2154)(int);
__declspec(naked) void CmpCallPushIATCall2_004c6e90(void) {
    __asm {
        cmp     dword ptr [g_state_00f9f84c_ee], 1
        _emit   75h
        _emit   05h
        call    func_004cc030_ee
        mov     eax, dword ptr [esp + 4]
        push    eax
        call    func_004cc070_ee
        add     esp, 4
        push    0xff
        call    dword ptr [g_iat_004d2154]
        ret
    }
}

/* @addr 0x004c6ee0 (55b)
 *   call IAT [g_iat_004d216c](0, 0x1000, 0); store result;
 *   if (result == 0) return; call 0x4c70d0;
 *   if (eax == 0) call IAT [g_iat_004d2158](result); xor eax; ret;
 *   else return 1.
 */
extern void * (*g_iat_004d216c)(int, int, int);
extern void (*g_iat_004d2158)(void *);
extern void * g_state_00fa0ee4;
extern int VirtualHeapAlloc_004c70d0(void);
__declspec(naked) void CallIATIfThenCall_004c6ee0(void) {
    __asm {
        push    0
        push    0x1000
        push    0
        call    dword ptr [g_iat_004d216c]
        test    eax, eax
        mov     dword ptr [g_state_00fa0ee4], eax
        _emit   75h
        _emit   01h
        ret
        call    VirtualHeapAlloc_004c70d0
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     eax, dword ptr [g_state_00fa0ee4]
        push    eax
        call    dword ptr [g_iat_004d2158]
        xor     eax, eax
        ret
        mov     eax, 1
        ret
    }
}

/* @addr 0x004c8300 (57b)
 *   loop: call 0x4c82b0(arg1, arg2, arg3); decrement count;
 *   break if [arg3] == -1 or count == 0. Calls with raw 3 args.
 */
extern void WriteCharBuffered_004c82b0(int, int, int);
__declspec(naked) void PaddedLoopFunc_004c8300(void) {
    __asm {
        push    ebx
        push    ebp
        mov     ebp, dword ptr [esp + 0x10]
        push    esi
        mov     eax, ebp
        dec     ebp
        test    eax, eax
        push    edi
        _emit   7eh
        _emit   25h
        mov     esi, dword ptr [esp + 0x20]
        mov     edi, dword ptr [esp + 0x1c]
        mov     ebx, dword ptr [esp + 0x14]
loop_top:
        push    esi
        push    edi
        push    ebx
        call    WriteCharBuffered_004c82b0
        mov     eax, dword ptr [esi]
        add     esp, 0x0c
        cmp     eax, 0xffffffff
        _emit   74h
        _emit   07h
        mov     ecx, ebp
        dec     ebp
        test    ecx, ecx
        _emit   7fh
        _emit   0e7h
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}

/* @addr 0x004c8340 (61b)
 *   loop: read sbyte at esi, increment esi; call 0x4c82b0(byte, arg2, arg3);
 *   break if [arg3] == -1 or count == 0.
 */
__declspec(naked) void PaddedLoopByteFunc_004c8340(void) {
    __asm {
        push    ebx
        push    ebp
        mov     ebp, dword ptr [esp + 0x10]
        push    esi
        mov     eax, ebp
        dec     ebp
        test    eax, eax
        push    edi
        _emit   7eh
        _emit   29h
        mov     edi, dword ptr [esp + 0x20]
        mov     ebx, dword ptr [esp + 0x1c]
        mov     esi, dword ptr [esp + 0x14]
loop_top2:
        movsx   eax, byte ptr [esi]
        push    edi
        push    ebx
        push    eax
        inc     esi
        call    WriteCharBuffered_004c82b0
        mov     eax, dword ptr [edi]
        add     esp, 0x0c
        cmp     eax, 0xffffffff
        _emit   74h
        _emit   07h
        mov     ecx, ebp
        dec     ebp
        test    ecx, ecx
        _emit   7fh
        _emit   0e3h
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}

/* @addr 0x004bd890 (58b)
 *   walk table 0x00ab4e78..0x00ab5034 step 4;
 *   each non-zero entry's deref [eax*4+0] yields word at +4;
 *   if word == arg call F.
 */
extern unsigned int g_table_004ab4e78_ee[];
extern void GeoLoadFixupLoop_004bd8e0(void);
__declspec(naked) void TableWalkBoundedCmp_004bd890(void) {
    __asm {
        push    esi
        push    edi
        mov     edi, dword ptr [esp + 0x0c]
        mov     esi, OFFSET g_table_004ab4e78_ee
loop_top3:
        mov     eax, dword ptr [esi]
        test    eax, eax
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   7eh
        _emit   16h
        mov     eax, dword ptr [eax*4 + 0]
        xor     ecx, ecx
        mov     cx,  word  ptr [eax + 4]
        cmp     ecx, edi
        _emit   75h
        _emit   05h
        call    GeoLoadFixupLoop_004bd8e0
        add     esi, 4
        cmp     esi, 0x00ab5034
        _emit   7ch
        _emit   0d4h
        pop     edi
        pop     esi
        ret
    }
}

/* @addr 0x004c5d70 (55b)
 *   call F to get state; if !state ret;
 *   call 0x4c9200(arg1, arg2, arg3, state, edi); store ret;
 *   call 0x4c7040(state); restore ret; ret.
 */
extern void * HeapScanInit_004c9440(void);
extern int func_004c9200(int, int, int, void *, int);
extern void func_004c7040(void *);
__declspec(naked) void WrapperCallSelf_004c5d70(void) {
    __asm {
        push    esi
        call    HeapScanInit_004c9440
        mov     esi, eax
        test    esi, esi
        _emit   75h
        _emit   02h
        pop     esi
        ret
        mov     eax, dword ptr [esp + 0x10]
        mov     ecx, dword ptr [esp + 0x0c]
        mov     edx, dword ptr [esp + 8]
        push    edi
        push    esi
        push    eax
        push    ecx
        push    edx
        call    func_004c9200
        add     esp, 0x10
        mov     edi, eax
        push    esi
        call    func_004c7040
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        ret
    }
}
