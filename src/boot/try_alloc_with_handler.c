/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004c54d0 (68b)
 *   CRT _new_handler-style malloc retry: takes (size, retry_flag).
 *   Calls SmallMalloc(size); if NULL and retry_flag, invokes
 *   IndirectCall(size) and loops back. Returns NULL if size > -32
 *   (overflow guard).
 */
extern void *SmallMalloc(unsigned int n);
extern int IndirectCall(unsigned int n);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int TryAllocWithHandler(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_1 < 0xffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      if (param_1 < 0xffffffe1) {
        iVar1 = SmallMalloc(param_1);
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 != 0) {
        return iVar1;
      }
      if (param_2 == 0) {
        return 0;
      }
      iVar1 = IndirectCall(param_1);
    } while (iVar1 != 0);
  }
  return 0;
}
#else
__declspec(naked) void TryAllocWithHandler(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        cmp     esi, -32
        push    edi
        _emit   77h
        _emit   34h
        test    esi, esi
        _emit   75h
        _emit   05h
        mov     esi, 1
        mov     edi, dword ptr [esp + 0x10]
loop_top:
        cmp     esi, -32
        _emit   77h
        _emit   0bh
        push    esi
        call    SmallMalloc
        add     esp, 4
        jmp     short skip_zero
        xor     eax, eax
skip_zero:
        test    eax, eax
        _emit   75h
        _emit   13h
        test    edi, edi
        _emit   74h
        _emit   0fh
        push    esi
        call    IndirectCall
        add     esp, 4
        test    eax, eax
        jne     loop_top
        xor     eax, eax
        pop     edi
        pop     esi
        ret
    }
}
#endif
