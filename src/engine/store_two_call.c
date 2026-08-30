/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x00421c40 (16b): push 0x71; push DATA_PTR; call F; add esp,8; ret */
#ifndef NON_MATCHING
extern void StoreTwoCall(int, int);
#endif
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern void *g_dispatchSave1150;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1150 (*(unsigned int *)MK4_VA(unsigned int, 0x48caa0u))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#endif

#ifdef NON_MATCHING
#include "portable/mem_model.h"



/* @addr 0x0049cb40 (28b) - NATIVE ONLY; the matching build synthesizes it.
 *
 * The first argument is a CODE VA: AllocateNode stores it raw into the node's
 * +0xd8 slot, which is exactly what BootScheduledNodeTimerWalk later resolves
 * and calls. Parks the work type alongside and allocates. */
void StoreTwoCall(unsigned int handler_va, unsigned int worktype)
{
#ifdef TARGET_SDL
    /* MK4_TRACE_FREEPOP family: every controller spawn with the ambient
     * group it will capture (+0x2c). A cursor-looking group here is a
     * spawn firing in array-pump context. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int f = -1; static int n;
      if (f < 0) f = getenv("MK4_TRACE_FREEPOP") != 0;
      if (f && n < 120) { n++;
          SDL_Log("SPAWN cb=%x type=%x amb5c=%x amb44=%x",
                  handler_va, worktype,
                  *MK4_VA(unsigned int, 0x54205cu),
                  *MK4_VA(unsigned int, 0x542044u)); } }
#endif
    g_eventQueueWorkType = worktype;
    g_pendingNodeType = handler_va;
    AllocateNode(handler_va);
}
#else
/* no matching-side C - the synthesizer provides 0x0049cb40; the empty branch
 * exists because the co-exec extractor recognises a twin only as an
 * ifdef/else pair. */
#endif

void Push71_Push48caa0(void) {
#ifdef NON_MATCHING
    /* the alias names original CODE bytes; UNPTR recovers their VA */
    StoreTwoCall(MK4_UNPTR(&g_dispatchSave1150), 0x71);
#else
    StoreTwoCall(&g_dispatchSave1150, 0x71);
#endif
}
