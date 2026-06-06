/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"

/* @addr 0x004b5a80 (52b)
 *   rep stos zero-fill 0xc0000 dwords starting at 0x007b41a0;
 *   then mask + or bits, set [0x007b41a8] = 0x007b41a0 (self-link list head).
 */
extern u8 g_memHeapStart[];
extern unsigned int g_dispatchSave1654;
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void AppInit_Misc2(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &g_memHeapStart;
  for (iVar1 = 0xc0000; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  g_dispatchSave1654 = &g_memHeapStart;
  g_memHeapStart = g_memHeapStart & 0xff2ffff4 | 0x802ffff4;
  return;
}
#else
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
#endif

