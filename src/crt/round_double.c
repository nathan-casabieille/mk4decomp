/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"

extern unsigned int g_currentNodeIdx;

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
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
float10 RoundDouble(double param_1)

{
  return (float10)ROUND(param_1);
}
#else
__declspec(naked) void RoundDouble(void) {
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
#endif
