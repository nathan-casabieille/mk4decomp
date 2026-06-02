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
extern void SetWorkType02CountFFB(void);
extern void AudioInstall3StateSubXform(void);
void TestEqJmpInitFightGroup(void) {
    if (g_eventQueueEnd) {
        SetWorkType02CountFFB();
        return;
    }
    g_eventQueueWorkType = 0xfef20000;
    ((FightGroupNode *)(g_fightGroupHead * 4))->tag = 0x25a;
    g_walkCallback = (void(*)(void))0x50000;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x6c) = 0x50000;
    AudioInstall3StateSubXform();
}
