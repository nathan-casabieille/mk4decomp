/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004578e0 (21b): strlen-style counter
 *   mov     ecx, [esp+4]
 *   xor     eax, eax
 *   cmp     byte ptr [ecx], 0
 *   je      .ret
 * .loop:
 *   mov     dl, [ecx+1]
 *   inc     eax
 *   inc     ecx
 *   test    dl, dl
 *   jne     .loop
 * .ret:
 *   ret
 */
__declspec(naked) void StrLen_004578e0(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        xor     eax, eax
        cmp     byte ptr [ecx], 0
        _emit   74h
        _emit   09h
        mov     dl, byte ptr [ecx + 1]
        inc     eax
        inc     ecx
        test    dl, dl
        _emit   75h
        _emit   0f7h
        ret
    }
}
