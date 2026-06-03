/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00489220 (23b): push 0x267; push DATA; call F; add esp,8; jmp -0xc7 */
extern int StoreTwoCall(int, void *);
extern void *g_dispatchSave1146;
extern void InstallSelfFiveStoreCalls(void);
void Push267_Push44eb60_Jmp(void) {
    StoreTwoCall((int)&g_dispatchSave1146, 0x267);
    InstallSelfFiveStoreCalls();
}
