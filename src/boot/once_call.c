/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x00401340 (39b)
 *   mov     al, byte ptr [g_bootOnceCallByte]
 *   test    al, al
 *   jne     .skip
 *   push    0
 *   push    0
 *   push    0x004d5084
 *   mov     byte ptr [g_bootOnceCallByte], 1
 *   call    F
 *   add     esp, 0xc
 *   jmp     +0x0a
 * .skip:
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned char g_bootOnceCallByte;
extern void *g_dispatchSave1161;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_bootOnceCallByte (*(unsigned char *)MK4_VA(unsigned char, 0x52435cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1161 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5084u))
#endif

extern int Anim_LoadPackFile(void *p, int a, int b);
extern void Init0AndMax(void);
void OnceCall(void) {
    if (g_bootOnceCallByte != 0) {
        return;
    }
    g_bootOnceCallByte = 1;
    Anim_LoadPackFile(&g_dispatchSave1161, 0, 0);
    Init0AndMax();
}
