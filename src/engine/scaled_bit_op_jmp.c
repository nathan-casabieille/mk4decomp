/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x00476e00 (32b)
 *   mov     ecx, [g_currentNodeIdx]
 *   mov     eax, [ecx*4 + 0x20]
 *   or      al, 4
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x20], eax
 *   jmp     T
 */
extern void CondInstallDispatch_00476e20(void);
void ScaledOr4Jmp(void) {
    unsigned int scaled = g_currentNodeIdx;
    unsigned int v = ((ScenegraphNode *)MK4_PTR((scaled * 4)))->flags | 4;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)MK4_PTR((scaled * 4)))->flags = v;
    CondInstallDispatch_00476e20();
}

/* @addr 0x00476fe0 (32b): same shape, and al, 0xfb */
extern void CondInstallDispatch_00477000(void);
void ScaledAndFBJmp(void) {
    unsigned int scaled = g_currentNodeIdx;
    unsigned int v = ((ScenegraphNode *)MK4_PTR((scaled * 4)))->flags & 0xfffffffbu;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)MK4_PTR((scaled * 4)))->flags = v;
    CondInstallDispatch_00477000();
}
