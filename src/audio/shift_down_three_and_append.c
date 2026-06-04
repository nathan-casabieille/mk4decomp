/**
 * Auto-split from misc_matchesL.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004aa3f0 (32b)
 *   mov     edx, [esp+4]
 *   push    esi
 *   mov     eax, edx
 *   mov     ecx, 3
 *   mov     esi, [eax + 4]
 *   mov     [eax], esi
 *   add     eax, 4
 *   dec     ecx
 *   jne     -10
 *   mov     eax, [esp+0x0c]
 *   pop     esi
 *   mov     [edx + 0x0c], eax
 *   ret
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void ShiftDownThreeAndAppend(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 3;
  puVar1 = param_1;
  do {
    *puVar1 = puVar1[1];
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[3] = param_2;
  return;
}
#else
__declspec(naked) void ShiftDownThreeAndAppend(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        mov     eax, edx
        mov     ecx, 3
        mov     esi, dword ptr [eax + 4]
        mov     dword ptr [eax], esi
        add     eax, 4
        dec     ecx
        _emit   75h
        _emit   0f5h
        mov     eax, dword ptr [esp + 0x0c]
        pop     esi
        mov     dword ptr [edx + 0x0c], eax
        ret
    }
}
#endif
