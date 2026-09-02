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

extern unsigned int Anim_LoadPackFile(unsigned int name_va);
extern void Init0AndMax(void);
void OnceCall(void) {
    if (g_bootOnceCallByte != 0) {
        return;
    }
    g_bootOnceCallByte = 1;
    /* Unconditional, as the original is: `push 0; push 0; push 0x4d5084;
     * call F`. This used to sit behind MK4_ANIM_PACK as port scaffolding,
     * and the gate had a cost far from here - with no pack loaded,
     * Anim_AcquireFrameData finds an empty header, falls back to the record
     * at 0x4ffe88 which is empty too, and returns 0. Its caller then stores
     * `0 + 3` into the entity cursor at 0x542048 and the bone walk in
     * BootChainStreamWalkExtract dereferences packed index 3, faulting at
     * arena + 0xc. Neither the original nor the twin guards that return
     * value, because in the original it is never zero here. */
    Anim_LoadPackFile(0x4d5084u);   /* the "anim" name in .data */
    Init0AndMax();
}
