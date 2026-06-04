/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

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
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int StrLen(char *param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    pcVar1 = param_1 + 1;
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 1;
    cVar2 = *pcVar1;
  }
  return iVar3;
}
#else
__declspec(naked) void StrLen(void) {
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
#endif
