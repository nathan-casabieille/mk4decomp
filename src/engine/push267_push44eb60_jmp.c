/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00489220 (23b): push 0x267; push DATA; call F; add esp,8; jmp -0xc7 */
extern int StoreTwoCall_0049cb40(int, void *);
extern void *g_dispatchSave1146_0044eb60;
extern void InstallSelfFiveStoreCalls_00489170(void);
void Push267_Push44eb60_Jmp_00489220(void) {
    StoreTwoCall_0049cb40((int)&g_dispatchSave1146_0044eb60, 0x267);
    InstallSelfFiveStoreCalls_00489170();
}
