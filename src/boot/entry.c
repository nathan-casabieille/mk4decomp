/**
 * MSVC 5.0 CRT entry point (`mainCRTStartup` equivalent for a
 * Win32 GUI build). Pushes a standard SEH frame and dispatches to
 * WinMain via the canonical (hInstance, hPrevInstance, lpCmdLine,
 * nShowCmd) sequence.
 */
#include "platform/win32.h"

/*
 * @addr 0x004c6cb0
 *
 * Naked + __asm: the SEH frame layout (push -1 / push scope_table /
 * push handler / push fs:[0] / mov fs:[0], esp), the
 * `add esp, -0x58` (rather than `sub esp, 0x58`) form MSVC's CRT
 * uses, and the dual-tail (mainline ret followed by a separate
 * "no-quote argv" path that jumps back into the whitespace-skip
 * loop) all come straight from MSVC's stock CRT - any C body would
 * differ.
 */
__declspec(naked) void entry(void)
{
    __asm {
        push    ebp
        mov     ebp, esp
        push    -1
        push    offset g_seh_scope_table
        push    offset _except_handler3
        mov     eax, dword ptr fs:[0]
        push    eax
        mov     dword ptr fs:[0], esp
        add     esp, -0x58
        push    ebx
        push    esi
        push    edi
        mov     dword ptr [ebp - 0x18], esp
        call    dword ptr [g_iat_GetVersion]
        xor     edx, edx
        mov     dl, ah
        mov     dword ptr [g_winverMajor], edx
        mov     ecx, eax
        and     ecx, 0xff
        mov     dword ptr [g_winverMinor], ecx
        shl     ecx, 8
        add     ecx, edx
        mov     dword ptr [g_winverCombined], ecx
        shr     eax, 0x10
        mov     dword ptr [g_winverBuild], eax
        call    _heap_init
        test    eax, eax
        jne     SHORT after_heap
        push    0x1c
        call    _amsg_exit
        add     esp, 4
after_heap:
        call    _ioinit
        test    eax, eax
        jne     SHORT after_ioinit
        push    0x10
        call    _amsg_exit
        add     esp, 4
after_ioinit:
        mov     dword ptr [ebp - 0x4], 0
        call    _setargv
        call    _setenvp
        call    dword ptr [g_iat_GetCommandLineA]
        mov     dword ptr [g_cmdline], eax
        call    _crt_startup_check
        mov     dword ptr [g_initRet], eax
        test    eax, eax
        je      SHORT do_exit_neg1
        mov     eax, dword ptr [g_cmdline]
        test    eax, eax
        jne     SHORT do_init
do_exit_neg1:
        push    -1
        call    _exit
        add     esp, 4
do_init:
        call    _cinit
        call    _init_main
        call    _init_premain
        mov     esi, dword ptr [g_cmdline]
        mov     dword ptr [ebp - 0x64], esi
        cmp     byte ptr [esi], 0x22
        jne     no_quote
ws_inquote_loop:
        inc     esi
        mov     dword ptr [ebp - 0x64], esi
        mov     al, byte ptr [esi]
        cmp     al, 0x22
        je      SHORT past_quote
        test    al, al
        je      SHORT past_quote
        and     eax, 0xff
        push    eax
        call    _isspace_crt
        add     esp, 4
        test    eax, eax
        je      SHORT ws_inquote_loop
        inc     esi
        mov     dword ptr [ebp - 0x64], esi
        jmp     SHORT ws_inquote_loop
past_quote:
        cmp     byte ptr [esi], 0x22
        jne     SHORT skip_close
        inc     esi
        mov     dword ptr [ebp - 0x64], esi
skip_close:
        mov     al, byte ptr [esi]
        test    al, al
        je      SHORT call_winmain
        cmp     al, 0x20
        ja      SHORT call_winmain
        inc     esi
        mov     dword ptr [ebp - 0x64], esi
        jmp     SHORT skip_close
call_winmain:
        mov     dword ptr [ebp - 0x30], 0
        lea     eax, [ebp - 0x5c]
        push    eax
        call    dword ptr [g_iat_GetStartupInfoA]
        test    byte ptr [ebp - 0x30], 1
        je      SHORT use_default_show
        mov     eax, dword ptr [ebp - 0x2c]
        and     eax, 0xffff
        jmp     SHORT have_show
use_default_show:
        mov     eax, 0xa
have_show:
        push    eax
        push    esi
        push    0
        push    0
        call    dword ptr [g_iat_GetModuleHandleA]
        push    eax
        call    WinMain
        mov     dword ptr [ebp - 0x60], eax
        push    eax
        call    _exit
        jmp     SHORT seh_unwind
        ; --- SEH filter (reached only via the SEH dispatcher) ---
        mov     eax, dword ptr [ebp - 0x14]
        mov     ecx, dword ptr [eax]
        mov     ecx, dword ptr [ecx]
        mov     dword ptr [ebp - 0x68], ecx
        push    eax
        push    ecx
        call    _XcptFilter
        add     esp, 8
        ret
        ; --- SEH __except handler ---
        mov     esp, dword ptr [ebp - 0x18]
        mov     edx, dword ptr [ebp - 0x68]
        push    edx
        call    _exit_post
seh_unwind:
        add     esp, 4
        mov     dword ptr [ebp - 0x4], -1
        mov     ecx, dword ptr [ebp - 0x10]
        mov     dword ptr fs:[0], ecx
        pop     edi
        pop     esi
        pop     ebx
        mov     esp, ebp
        pop     ebp
        ret
no_quote:
        cmp     byte ptr [esi], 0x20
        jbe     skip_close
        inc     esi
        mov     dword ptr [ebp - 0x64], esi
        jmp     SHORT no_quote
    }
}
