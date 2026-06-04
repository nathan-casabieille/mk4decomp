/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004cd920 (47b)
 *   strnlen(arg, n): scan up to n bytes for NUL; return offset or n.
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int StrNLen(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = param_2;
  for (pcVar1 = param_1; (iVar2 != 0 && (iVar2 = iVar2 + -1, *pcVar1 != '\0')); pcVar1 = pcVar1 + 1)
  {
  }
  if (*pcVar1 != '\0') {
    return param_2;
  }
  return (int)pcVar1 - (int)param_1;
}
#else
__declspec(naked) void StrNLen(void) {
    __asm {
        mov     edx, dword ptr [esp + 8]
        push    esi
        mov     esi, dword ptr [esp + 8]
        test    edx, edx
        push    edi
        mov     eax, esi
        lea     ecx, [edx - 1]
        _emit   74h
        _emit   0dh
loop_b:
        cmp     byte ptr [eax], 0
        _emit   74h
        _emit   08h
        inc     eax
        mov     edi, ecx
        dec     ecx
        test    edi, edi
        _emit   75h
        _emit   0f3h
done:
        cmp     byte ptr [eax], 0
        _emit   75h
        _emit   05h
        sub     eax, esi
        pop     edi
        pop     esi
        ret
        pop     edi
        pop     esi
        mov     eax, edx
        ret
    }
}
#endif
