/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0041fcc0 (37b)
 *   mov     eax, [esp+4]
 *   push    esi
 * .loop:
 *   mov     edx, [eax]
 *   mov     ecx, [eax + 4]
 *   add     eax, 4
 *   add     eax, 4
 *   test    ecx, ecx
 *   jne     .skip1
 *   test    edx, edx
 *   je      .ret
 * .skip1:
 *   mov     esi, [edx]
 *   sar     ecx, 2
 *   or      esi, ecx
 *   mov     [edx], esi
 *   jmp     .loop
 * .ret:
 *   pop     esi
 *   ret
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void OrListLoop(int *param_1)

{
  int *piVar1;
  uint *puVar2;
  
  while( true ) {
    puVar2 = (uint *)*param_1;
    piVar1 = param_1 + 1;
    param_1 = param_1 + 2;
    if ((*piVar1 == 0) && (puVar2 == (uint *)0x0)) break;
    *puVar2 = *puVar2 | *piVar1 >> 2;
  }
  return;
}
#else
__declspec(naked) void OrListLoop(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        mov     edx, dword ptr [eax]
        mov     ecx, dword ptr [eax + 4]
        add     eax, 4
        add     eax, 4
        test    ecx, ecx
        _emit   75h
        _emit   04h
        test    edx, edx
        _emit   74h
        _emit   0bh
        mov     esi, dword ptr [edx]
        sar     ecx, 2
        or      esi, ecx
        mov     dword ptr [edx], esi
        _emit   0ebh
        _emit   0e2h
        pop     esi
        ret
    }
}
#endif
