/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004c5800 (61b)
 *   if (arg[0xc] & 0x40) zero arg[0xc] and return -1;
 *   else: call 0x4c6ff0(arg); call 0x4c5840(arg) → save eax;
 *   call 0x4c7060(arg); restore eax; return.
 */
extern void func_004c6ff0_hh(void *);
extern int FCloseImpl_004c5840(void *);
extern void func_004c7060_hh(void *);
__declspec(naked) void Helper_FClose(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        push    edi
        or      edi, 0xffffffff
        test    byte ptr [esi + 0x0c], 0x40
        _emit   74h
        _emit   0ch
        mov     dword ptr [esi + 0x0c], 0
        mov     eax, edi
        pop     edi
        pop     esi
        ret
        push    esi
        call    func_004c6ff0_hh
        add     esp, 4
        push    esi
        call    FCloseImpl_004c5840
        add     esp, 4
        mov     edi, eax
        push    esi
        call    func_004c7060_hh
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        ret
    }
}

