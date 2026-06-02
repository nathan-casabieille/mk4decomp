/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_dispatchSave1233;
extern unsigned int g_dispatchSave1234;
extern unsigned int g_dispatchSave1235;
extern void CmpDualPatchScaledRangeJmp(unsigned int *);
extern void CmpDualPatchScaledRangeJmp(unsigned int *);
extern void CmpDualPatchScaledRangeJmp(unsigned int *);

/* @addr 0x00438ea0 (14b) entry A */
void TripleStubPushCall(void) {
    CmpDualPatchScaledRangeJmp(&g_dispatchSave1233);
}

/* @addr 0x00438eb0 (14b) entry B */
void func_00438eb0(void) {
    CmpDualPatchScaledRangeJmp(&g_dispatchSave1234);
}

/* @addr 0x00438ec0 (14b) entry C */
void func_00438ec0(void) {
    CmpDualPatchScaledRangeJmp(&g_dispatchSave1235);
}
