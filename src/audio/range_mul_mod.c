/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004ab2a0 (89b)
 * 16.16 fixed-point divide: g_walkCallback = (g_walkCallback << 16) /
 * g_eventQueueCurrent. If the divisor is 0, returns it unchanged. The
 * fast path (numerator in [-0x8000, 0x8000)) uses a 32-bit shl+idiv;
 * larger numerators take a 64-bit path (__allshl via func_004c5740 +
 * the 64-bit signed Alldiv at 0x004c5690) to avoid overflowing the
 * <<16. Both paths compute the same quotient - the "MulMod" in the old
 * name was wrong; it is a divide. Used to normalise a delta by a range
 * (e.g. the inter-fighter facing components in helper_per_player_tick).
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_eventQueueCurrent_mm2;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueCurrent_mm2 (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

extern void func_004c5740_mm(void);
extern int Alldiv(int, int, int, int);

#ifdef NON_MATCHING
/* 16.16 fixed divide through the global convention: num in g_walkCallback,
 * denominator in g_eventQueueCurrent, quotient back in g_walkCallback.
 * The original splits on |num| < 0x8000 (32-bit idiv of num << 16) vs the
 * UllShlAndInit + Alldiv 64-bit path; one signed 64-bit division computes
 * both exactly wherever the original does not fault. The old Ghidra lift
 * called __allshl()/__alldiv() with NO arguments - implicit-int garbage -
 * so every divide with |num| >= 0x8000 (all the camera-axis divides)
 * returned junk. */
void FixedDiv16(void)

{
  int den = (int)g_eventQueueCurrent;

  if (den == 0) {
    g_walkCallback = 0;
    return;
  }
  g_walkCallback = (unsigned int)(int)
      (((long long)(int)g_walkCallback << 16) / den);
}
#else
__declspec(naked) void FixedDiv16(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [g_eventQueueCurrent_mm2]
        test    esi, esi
        push    edi
        _emit   75h
        _emit   09h
        mov     dword ptr [g_walkCallback], esi
        pop     edi
        pop     esi
        ret
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0xffff8000
        _emit   7ch
        _emit   15h
        cmp     eax, 0x00008000
        _emit   7dh
        _emit   0eh
        shl     eax, 0x10
        cdq
        idiv    esi
        mov     dword ptr [g_walkCallback], eax
        pop     edi
        pop     esi
        ret
        cdq
        mov     ecx, 0x10
        call    func_004c5740_mm
        mov     ecx, eax
        mov     eax, esi
        mov     edi, edx
        cdq
        push    edx
        push    eax
        push    edi
        push    ecx
        call    Alldiv
        pop     edi
        mov     dword ptr [g_walkCallback], eax
        pop     esi
        ret
    }
}
#endif
