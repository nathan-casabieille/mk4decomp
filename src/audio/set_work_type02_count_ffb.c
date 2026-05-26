/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1790 (54b)
 *   load fightGroupHead; set g_eventQueueWorkType=0x01020000;
 *   set [eax*4 + 0x30]=0x25b; reload fightGroupHead → ecx;
 *   mov eax,0xfffb0000; store walk and [ecx*4 + 0x6c]=eax; jmp T.
 */
extern void AudioInstall3StateSubXform_004a17d0(void);
void SetWorkType02CountFFB_004a1790(void) {
    g_eventQueueWorkType = 0x01020000;
    ((FightGroupNode *)(g_fightGroupHead * 4))->tag = 0x25b;
    g_walkCallback = (void(*)(void))0xfffb0000;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x6c) = 0xfffb0000;
    AudioInstall3StateSubXform_004a17d0();
}
