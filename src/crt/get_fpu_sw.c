/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004cf710 (16b)
 *   push    ebp
 *   mov     ebp, esp
 *   push    ecx
 *   wait
 *   fnstcw  word ptr [ebp-2]
 *   movsx   eax, word ptr [ebp-2]
 *   mov     esp, ebp
 *   pop     ebp
 *   ret
 */
__declspec(naked) void GetFpuSw(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        push    ecx
        fstsw   word ptr [ebp - 2]
        movsx   eax, word ptr [ebp - 2]
        mov     esp, ebp
        pop     ebp
        ret
    }
}
