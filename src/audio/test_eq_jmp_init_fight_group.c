/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1740 (68b)
 *   if g_eventQueueEnd != 0 jmp T0; else
 *   load g_fightGroupHead, set g_eventQueueWorkType = 0xfef20000,
 *   set fightGroup[+0x30] = 0x25a, set walk = 0x50000, set
 *   fightGroup[+0x6c] = walk, jmp T1.
 */
extern void SetWorkType02CountFFB_004a1790(void);
extern void AudioInstall3StateSubXform_004a17d0(void);
void TestEqJmpInitFightGroup_004a1740(void) {
    if (g_eventQueueEnd) {
        SetWorkType02CountFFB_004a1790();
        return;
    }
    g_eventQueueWorkType = 0xfef20000;
    ((FightGroupNode *)(g_fightGroupHead * 4))->tag = 0x25a;
    g_walkCallback = (void(*)(void))0x50000;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x6c) = 0x50000;
    AudioInstall3StateSubXform_004a17d0();
}
