/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004d03c0 (51b)
 *   string convert: each digit '0'..'9' becomes 0..9 in place;
 *   semicolon (';') triggers a memmove-left tail to remove that char and continue.
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void StringDigitConvert(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  
  cVar2 = *param_1;
  do {
    if (cVar2 == '\0') {
      return;
    }
    if ((cVar2 < '0') || ('9' < cVar2)) {
      pcVar3 = param_1;
      if (cVar2 != ';') goto LAB_004d03d6;
      do {
        *pcVar3 = pcVar3[1];
        pcVar1 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar1 != '\0');
    }
    else {
      *param_1 = cVar2 + -0x30;
LAB_004d03d6:
      param_1 = param_1 + 1;
    }
    cVar2 = *param_1;
  } while( true );
}
#else
__declspec(naked) void StringDigitConvert(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
loop_a:
        mov     al,  byte  ptr [ecx]
        test    al, al
        _emit   74h
        _emit   13h
        cmp     al, 0x30
        _emit   7ch
        _emit   10h
        cmp     al, 0x39
        _emit   7fh
        _emit   0ch
        sub     al, 0x30
        mov     byte ptr [ecx], al
loop_inc:
        inc     ecx
        mov     al,  byte  ptr [ecx]
        test    al, al
        _emit   75h
        _emit   0edh
        ret
        cmp     al, 0x3b
        _emit   75h
        _emit   0f4h
        mov     eax, ecx
shift_loop:
        mov     dl,  byte  ptr [eax + 1]
        mov     byte ptr [eax], dl
        mov     dl,  byte  ptr [eax + 1]
        inc     eax
        test    dl, dl
        _emit   75h
        _emit   0f3h
        _emit   0ebh
        _emit   0e4h
    }
}
#endif
