/**
 * Auto-split from misc_matchesE.c
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
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#endif


/* @addr 0x0041f840 (38b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0xd8]
 *   test    ecx, ecx
 *   je      .skip
 *   mov     [eax*4 + 0xd8], -1
 *   mov     [g_framePauseFlag], 1
 * .skip:
 *   ret
 */
void ScaledNeg1SetPause(void) {
    ScenegraphNode *node = (ScenegraphNode *)MK4_PTR((g_baseSel * 4));
    if (node->ptr_field != 0) {
#ifdef TARGET_SDL
        /* MK4_TRACE_RELEASE: which controller marks itself done. +0xd8 is
         * the callback VA until this sets it to -1, and the node pump then
         * unlinks it - so this line names the controller that is about to
         * be freed. */
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          static int n;
          if (getenv("MK4_TRACE_RELEASE") && n < 20) { n++;
              SDL_Log("RELEASE node=%x cb=%08x", g_baseSel, node->ptr_field); } }
#endif
        node->ptr_field = 0xffffffff;
        g_framePauseFlag = 1;
    }
}
