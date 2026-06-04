/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0042afc0 (64b)
 *   modulo using 32x32->64 magic-number division: ecx %= 0x6487e (range modulus).
 *   Bound-clamps and adds offsets via g_pendingMatchVar3..00d4d532c.
 */
extern unsigned int g_pendingMatchVar3;
extern unsigned int g_pendingMatchVar;
extern unsigned int g_pendingMatchVar5;
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int ModuloMagic(int param_1)

{
  for (; g_pendingMatchVar3 < param_1; param_1 = param_1 - g_pendingMatchVar) {
  }
  if (param_1 <= g_pendingMatchVar5) {
    param_1 = param_1 + (((g_pendingMatchVar5 - param_1) + 0x6487eU) / 0x6487e) * 0x6487e;
  }
  return param_1;
}
#else
__declspec(naked) void ModuloMagic(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        mov     eax, dword ptr [g_pendingMatchVar3]
        cmp     ecx, eax
        _emit   7eh
        _emit   0ch
        mov     edx, dword ptr [g_pendingMatchVar]
sub_loop:
        sub     ecx, edx
        cmp     ecx, eax
        _emit   7fh
        _emit   0fah
        mov     edx, dword ptr [g_pendingMatchVar5]
        cmp     ecx, edx
        _emit   7fh
        _emit   1ah
        sub     edx, ecx
        mov     eax, 0xa2f99905
        add     edx, 0x6487e
        mul     edx
        shr     edx, 0x12
        imul    edx, edx, 0x6487e
        add     ecx, edx
        mov     eax, ecx
        ret
    }
}
#endif
