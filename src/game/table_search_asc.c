/**
 * Auto-split from misc_matchesDD.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004b5a80 (52b)
 *   rep stos zero-fill 0xc0000 dwords starting at 0x007b41a0;
 *   then mask + or bits, set [0x007b41a8] = 0x007b41a0 (self-link list head).
 */
extern u8 g_memHeapStart[];
extern unsigned int g_dispatchSave1654;
__declspec(naked) void AppInit_Misc2(void) {
    __asm {
        push    edi
        mov     ecx, 0xc0000
        xor     eax, eax
        mov     edi, OFFSET g_memHeapStart
        rep stosd
        mov     eax, dword ptr [g_memHeapStart]
        mov     dword ptr [g_dispatchSave1654], OFFSET g_memHeapStart
        and     eax, 0xff2ffff4
        pop     edi
        or      eax, 0x002ffff4
        or      eax, 0x80000000
        mov     dword ptr [g_memHeapStart], eax
        ret
    }
}

/* @addr 0x004b6300 (58b)
 *   table search ascending from arg+1; clamps arg < -1 to -1; returns count
 *   of contiguous valid entries (each 8 bytes; .second must equal 1, .next != 0).
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int Menu_FindNextSelectable(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 < -1) {
    param_1 = -1;
  }
  iVar2 = param_1 + 1;
  iVar1 = *(int *)(param_2 + iVar2 * 8);
  for (param_2 = param_2 + iVar2 * 8;
      (iVar3 = param_1, iVar1 != 0 && (iVar3 = iVar2, *(short *)(param_2 + 4) == 1));
      param_2 = param_2 + 8) {
    iVar1 = *(int *)(param_2 + 8);
    iVar2 = iVar2 + 1;
  }
  return iVar3;
}
#else
__declspec(naked) void Menu_FindNextSelectable(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        cmp     edx, 0xffffffff
        push    edi
        _emit   7dh
        _emit   03h
        or      edx, 0xffffffff
        mov     ecx, dword ptr [esp + 0x10]
        lea     eax, [edx + 1]
        mov     esi, dword ptr [ecx + eax*8]
        lea     ecx, [ecx + eax*8]
        test    esi, esi
        _emit   74h
        _emit   16h
        mov     esi, 1
        cmp     word  ptr [ecx + 4], si
        _emit   75h
        _emit   0dh
        mov     edi, dword ptr [ecx + 8]
        add     ecx, 8
        inc     eax
        test    edi, edi
        _emit   75h
        _emit   0efh
        mov     eax, edx
        pop     edi
        pop     esi
        ret
    }
}
#endif
