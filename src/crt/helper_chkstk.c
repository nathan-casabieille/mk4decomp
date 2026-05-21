/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004c5dd0 (48b): MSVC CRT __chkstk (a.k.a. __alloca_probe).
 *
 * Stack-probing helper inserted automatically by MSVC at the prologue
 * of any function that allocates more than 4 KB on the stack. Cannot
 * be expressed in pure C - the argument arrives in EAX (non-cdecl ABI),
 * and the body directly mutates ESP and uses `push eax; ret` to splice
 * the original return address back after the stack adjustment. This
 * function is shipped verbatim from MSVC 5.0's CRT (chkstk.asm in
 * libc.lib / libcmt.lib); the orig MK4.EXE links it statically. Keep
 * naked.
 *
 *   push    ecx                  ; save scratch
 *   cmp     eax, 0x1000          ; if request <= 1 page, skip the probe loop
 *   lea     ecx, [esp+8]         ; ecx = original esp (before the push ecx + ret addr)
 *   jb      .commit
 * .probe_loop:
 *   sub     ecx, 0x1000          ; step down one page
 *   sub     eax, 0x1000          ; account for the page
 *   test    [ecx], eax           ; probe the page (forces VM commit by page fault)
 *   cmp     eax, 0x1000
 *   jae     .probe_loop
 * .commit:
 *   sub     ecx, eax             ; ecx = final new esp
 *   mov     eax, esp             ; eax = current esp (= addr of saved ecx)
 *   test    [ecx], eax           ; final probe at the new bottom
 *   mov     esp, ecx             ; commit the stack adjustment
 *   mov     ecx, [eax]           ; restore caller's ecx (from the saved slot at old top)
 *   mov     eax, [eax+4]         ; eax = caller's return address
 *   push    eax                  ; push it back so ret picks it up
 *   ret
 *   int 3                        ; unreachable padding
 */
__declspec(naked) void Helper_ChkStk(void) {
    __asm {
        push    ecx
        cmp     eax, 0x1000
        lea     ecx, [esp + 8]
        _emit   72h
        _emit   14h
        sub     ecx, 0x1000
        sub     eax, 0x1000
        test    dword ptr [ecx], eax
        cmp     eax, 0x1000
        _emit   73h
        _emit   0ech
        sub     ecx, eax
        mov     eax, esp
        test    dword ptr [ecx], eax
        mov     esp, ecx
        mov     ecx, dword ptr [eax]
        mov     eax, dword ptr [eax + 4]
        push    eax
        ret
        _emit   0cch
    }
}

