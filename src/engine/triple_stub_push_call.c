/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_dispatchSave1233_004e4890;
extern unsigned int g_dispatchSave1234_004e48d0;
extern unsigned int g_dispatchSave1235_004e4910;
extern void func_004399be(unsigned int *);
extern void func_004399be_b(unsigned int *);
extern void func_004399be_c(unsigned int *);

/* @addr 0x00438ea0 (14b) entry A */
void TripleStubPushCall_00438ea0(void) {
    func_004399be(&g_dispatchSave1233_004e4890);
}

/* @addr 0x00438eb0 (14b) entry B */
void func_00438eb0(void) {
    func_004399be_b(&g_dispatchSave1234_004e48d0);
}

/* @addr 0x00438ec0 (14b) entry C */
void func_00438ec0(void) {
    func_004399be_c(&g_dispatchSave1235_004e4910);
}
