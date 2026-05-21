/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_state_00537e94;
extern packed_ptr g_fightGroupHead;

/* @addr 0x00474010 (63b)
 *   inc g_state_004d57ac twice, push g_scaledInit_00542044 and g_fightGroupHead
 *   onto stack[idx*4]; mov g_scaledInit_00542044 = 0x7c; jmp T.
 */
extern void HalveChainTriplePop2_004740d0(void);
void DoubleStackPushAndJmp_00474010(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_scaledInit_00542044;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_fightGroupHead;
    g_scaledInit_00542044 = 0x7c;
    HalveChainTriplePop2_004740d0();
}
