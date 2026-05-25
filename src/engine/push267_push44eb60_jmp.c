/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00489220 (23b): push 0x267; push DATA; call F; add esp,8; jmp -0xc7 */
extern int func_0049cb40_c(int, void *);
extern void *g_dispatchSave1146_0044eb60;
extern void func_0048915f(void);
void Push267_Push44eb60_Jmp_00489220(void) {
    func_0049cb40_c((int)&g_dispatchSave1146_0044eb60, 0x267);
    func_0048915f();
}
