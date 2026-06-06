/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004b7160 (73b)
 *   Tokenizer: walks string at *arg0, finds first ':' (sets flag),
 *   then for each char after the ':', writes the next char from
 *   arg1 (or ' ' if arg1 is empty). Effectively a one-shot
 *   substitute-after-delim helper.
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Menu_FillColonField(undefined4 *param_1,char *param_2)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char cVar4;
  
  bVar2 = false;
  pcVar1 = (char *)*param_1;
  iVar3 = 0;
  cVar4 = *pcVar1;
  do {
    if (cVar4 == '\0') {
      return;
    }
    if (pcVar1[iVar3] == ':') {
      if (bVar2) {
LAB_004b718d:
        cVar4 = *param_2;
        if (cVar4 == '\0') {
          cVar4 = ' ';
        }
        else {
          param_2 = param_2 + 1;
        }
        pcVar1[iVar3] = cVar4;
      }
      else {
        bVar2 = true;
        iVar3 = iVar3 + 1;
      }
    }
    else if (bVar2) goto LAB_004b718d;
    pcVar1 = (char *)*param_1;
    iVar3 = iVar3 + 1;
    cVar4 = pcVar1[iVar3];
  } while( true );
}
#else
__declspec(naked) void Menu_FillColonField(void) {
    __asm {
        push    ebp
        mov     ebp, dword ptr [esp + 8]
        push    esi
        xor     esi, esi
        mov     ecx, dword ptr [ebp + 0]
        xor     eax, eax
        cmp     byte ptr [ecx], 0
        _emit   74h
        _emit   34h
        push    edi
        mov     edi, dword ptr [esp + 0x14]
loop_top:
        cmp     byte ptr [eax + ecx*1], 0x3a
        _emit   75h
        _emit   0ch
        test    esi, esi
        _emit   75h
        _emit   0ch
        mov     esi, 1
        inc     eax
        _emit   0ebh
        _emit   12h
        test    esi, esi
        _emit   74h
        _emit   0eh
        mov     dl, byte ptr [edi]
        test    dl, dl
        _emit   74h
        _emit   03h
        inc     edi
        _emit   0ebh
        _emit   02h
        mov     dl, 0x20
        mov     byte ptr [eax + ecx*1], dl
        mov     ecx, dword ptr [ebp + 0]
        inc     eax
        cmp     byte ptr [eax + ecx*1], 0
        jne     loop_top
        pop     edi
        pop     esi
        pop     ebp
        ret
    }
}
#endif
