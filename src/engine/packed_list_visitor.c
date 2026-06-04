/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004b5c90 (80b)
 *   Walks a packed list at 0x7b41a0 (entries 12+ bytes each):
 *   each entry's first dword has top-2-bit flag (0xc0000000 →
 *   skip) and a 24-bit "next-offset". When passing target arg,
 *   match if 0xff (any) or if (entry.tag6bit) == arg.
 *   Calls helper(entry+0xc) on match. Loops until offset
 *   exceeds 0xab4194.
 */
extern u8 g_memHeapStart[];
extern void Mem_Free(void *);
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PackedListVisitor(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = &g_memHeapStart;
  do {
    if (((*puVar2 & 0xc0000000) == 0) &&
       ((param_1 == 0xffffffff || (param_1 == (*puVar2 >> 0x18 & 0x3f))))) {
      if (((undefined4 *)puVar2[1] == (undefined4 *)0x0) ||
         (puVar1 = *(uint **)puVar2[1], puVar1 == (uint *)0x0)) {
        puVar1 = puVar2 + 3;
      }
      Mem_Free(puVar1);
    }
    puVar2 = (uint *)((int)puVar2 + (*puVar2 & 0xffffff));
  } while (puVar2 < &g_memHeapEnd);
  return;
}
#else
__declspec(naked) void PackedListVisitor(void) {
    __asm {
        push    esi
        push    edi
        mov     edi, dword ptr [esp + 0x0c]
        mov     esi, OFFSET g_memHeapStart
loop_top:
        mov     eax, dword ptr [esi]
        test    eax, 0xc0000000
        _emit   75h
        _emit   28h
        cmp     edi, -1
        _emit   74h
        _emit   0ah
        shr     eax, 0x18
        and     eax, 0x3f
        cmp     edi, eax
        _emit   75h
        _emit   19h
        mov     eax, dword ptr [esi + 4]
        test    eax, eax
        _emit   74h
        _emit   06h
        mov     eax, dword ptr [eax]
        test    eax, eax
        _emit   75h
        _emit   03h
        lea     eax, [esi + 0x0c]
        push    eax
        call    Mem_Free
        add     esp, 4
        mov     eax, dword ptr [esi]
        and     eax, 0xffffff
        add     esi, eax
        cmp     esi, 0x00ab4194
        jb      loop_top
        pop     edi
        pop     esi
        ret
    }
}
#endif
