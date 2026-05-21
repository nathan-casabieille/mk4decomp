/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004cdff0 (21b)
 *   push    ebp
 *   mov     ebp, esp
 *   sub     esp, 8
 *   fld     qword ptr [ebp+8]
 *   frndint
 *   fstp    qword ptr [ebp-8]
 *   fld     qword ptr [ebp-8]
 *   mov     esp, ebp
 *   pop     ebp
 *   ret
 */
__declspec(naked) void RoundDouble_004cdff0(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        sub     esp, 8
        fld     qword ptr [ebp + 8]
        frndint
        fstp    qword ptr [ebp - 8]
        fld     qword ptr [ebp - 8]
        mov     esp, ebp
        pop     ebp
        ret
    }
}
