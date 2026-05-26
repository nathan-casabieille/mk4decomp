/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004be790 (16b)
 *   mov     eax, [esp+4]
 *   push    eax
 *   push    -1
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int __cdecl Snd3DSourceCleanup_004c3ad0(int, int);
int PushArgPushNeg1Call_004be790(int x) {
    return Snd3DSourceCleanup_004c3ad0(-1, x);
}
