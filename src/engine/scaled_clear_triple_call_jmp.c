/**
 * Scaled-clear + triple-call dispatcher.
 *
 * Reads/clears [g_baseSel*4 + 0x84]; if the cleared value was 0, calls
 * an OR-store helper; then unconditionally runs two more calls and
 * tail-jmps to the final dispatcher on pause-not-set.
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern u32 g_framePauseFlag;

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
    unsigned int v = ((ScenegraphNode *)(base * 4))->install_flag;
    ((ScenegraphNode *)(base * 4))->install_flag = 0;
    if (v == 0) {
        ZeroState();
    }
    Init6Struct();
    StateInitShuffle();
    if (g_framePauseFlag != 0) return;
    Screen_ArcadeEnding();
}
