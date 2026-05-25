/**
 * Auto-split from misc_matchesOO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer_00537e94;

/* @addr 0x0048e380 (62b): push lit + call PackedAdvanceCallContinue;
 * if !pause set workType=0x3c, call func_00489fd0; if !pause set walk
 * and state_00537e94 to 0xfff. Entry A of the original 84-byte packed
 * block; entry B (call+pause+tail-jmp) lives in func_0048e3c0. The
 * 2-byte nop gap is filled by 0x90-fill. */
extern void *g_data_004f12f8;
extern int PackedAdvanceCallContinue_0048e630(void *);
extern void func_00489fd0(void);
extern void func_004312e0(void);
extern void func_00431470(void);
void PushCallPauseSetMaxThenCallPauseJmp_0048e380(void) {
    int v;
    PackedAdvanceCallContinue_0048e630(&g_data_004f12f8);
    if (g_framePauseFlag != 0) return;
    g_eventQueueWorkType = 0x3c;
    func_00489fd0();
    if (g_framePauseFlag != 0) return;
    v = 0xfff;
    g_walkCallback = (void (*)(void))v;
    g_phaseTimer_00537e94 = v;
}
