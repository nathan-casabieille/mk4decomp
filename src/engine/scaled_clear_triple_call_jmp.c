/**
 * Scaled-clear + triple-call dispatcher.
 *
 * Reads/clears [g_baseSel*4 + 0x84]; if the cleared value was 0, calls
 * an OR-store helper; then unconditionally runs two more calls and
 * tail-jmps to the final dispatcher on pause-not-set.
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern u32 g_framePauseFlag;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#endif


/* @addr 0x004202c0 (57b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x84]
 *   mov     [eax*4 + 0x84], 0
 *   test    ecx, ecx
 *   jne     +5
 *   call    F1
 *   call    F2
 *   call    F3
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     +8
 *   ret
 */
extern void ZeroState(void);
extern void Init6Struct(void);
extern void StateInitShuffle(void);
extern void Screen_ArcadeEnding(void);
void ScaledClearTripleCallJmp(void) {
    unsigned int base = g_baseSel;
#ifdef MK4_ARENA
    unsigned int v = ((ScenegraphNode *)MK4_NODE(unsigned char, base))->install_flag;
    ((ScenegraphNode *)MK4_NODE(unsigned char, base))->install_flag = 0;
#else
    unsigned int v = ((ScenegraphNode *)(base * 4))->install_flag;
    ((ScenegraphNode *)(base * 4))->install_flag = 0;
#endif
    if (v == 0) {
        ZeroState();
    }
    Init6Struct();
    StateInitShuffle();
    if (g_framePauseFlag != 0) return;
#ifdef TARGET_SDL
    /* MK4_TRACE_SAE: which Screen_ArcadeEnding states the live path visits.
     * The FSM reads its command from node+0x84; log it BEFORE the call. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static unsigned hits[32], n;
      if (getenv("MK4_TRACE_SAE")) {
          unsigned st = ((ScenegraphNode *)MK4_NODE(unsigned char, g_baseSel))->install_flag;
          hits[st < 32 ? st : 31]++;
          if (++n % 10 == 0)
              SDL_Log("SAE cmds 0=%u 2=%u 3=%u 4=%u 5=%u 6=%u 7=%u 8=%u 9=%u 10=%u 11=%u 12=%u 13+=%u",
                      hits[0]+hits[1], hits[2], hits[3], hits[4], hits[5], hits[6], hits[7],
                      hits[8], hits[9], hits[10], hits[11], hits[12],
                      hits[13]+hits[14]+hits[15]+hits[16]+hits[17]+hits[18]); } }
#endif
    Screen_ArcadeEnding();
}
