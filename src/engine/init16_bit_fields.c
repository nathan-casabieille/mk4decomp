/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004bcc50 (24b)
 *   xor     eax, eax
 *   mov     word ptr [0x00ab47fc], 0x1000
 *   mov     word ptr [0x00ab47f8], ax
 *   mov     word ptr [0x00ab47fa], ax
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned short g_camRotZBam;
extern unsigned short g_camRotXBam;
extern unsigned short g_camRotYBam;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_camRotXBam (*(unsigned short *)MK4_VA(unsigned short, 0xab47f8u))
#define g_camRotYBam (*(unsigned short *)MK4_VA(unsigned short, 0xab47fau))
#define g_camRotZBam (*(unsigned short *)MK4_VA(unsigned short, 0xab47fcu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#endif

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Identical body; the guard pair exists because the co-exec extractor
 * recognises a twin only as an ifdef/else pair, and the three BAM words are
 * spelled at their real width by VA. */
void Init16BitFields(void) {
    *MK4_VA(unsigned short, 0xab47fcu) = 0x1000;   /* g_camRotZBam */
    *MK4_VA(unsigned short, 0xab47f8u) = 0;        /* g_camRotXBam */
    *MK4_VA(unsigned short, 0xab47fau) = 0;        /* g_camRotYBam */
}
#else
void Init16BitFields(void) {
    g_camRotZBam = 0x1000;
    g_camRotXBam = 0;
    g_camRotYBam = 0;
}
#endif
