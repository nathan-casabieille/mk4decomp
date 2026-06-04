/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004cca00 (29b): copy 3 dwords from src to dst with stride
 *   mov     eax, [esp+8]
 *   mov     ecx, [esp+4]
 *   push    esi
 *   sub     ecx, eax
 *   mov     edx, 3
 * .loop:
 *   mov     esi, [eax]
 *   mov     [eax + ecx], esi
 *   add     eax, 4
 *   dec     edx
 *   jne     .loop
 *   pop     esi
 *   ret
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Copy3Dwords(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  param_1 = param_1 - (int)param_2;
  iVar1 = 3;
  do {
    *(undefined4 *)((int)param_2 + param_1) = *param_2;
    param_2 = param_2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}
#else
__declspec(naked) void Copy3Dwords(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        mov     ecx, dword ptr [esp + 4]
        push    esi
        sub     ecx, eax
        mov     edx, 3
        mov     esi, dword ptr [eax]
        mov     dword ptr [eax + ecx], esi
        add     eax, 4
        dec     edx
        _emit   75h
        _emit   0f5h
        pop     esi
        ret
    }
}
#endif
