/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041fd10 (91b)
 *   call F0; set g_state_0053a1f0=2; call F1; pause → ret;
 *   call F2; pause → ret; call F3; pause → ret; call F4; pause → ret;
 *   call F5; pause → ret; jmp T.
 */
extern unsigned int g_state_0053a1f0;
extern void Wrapper_0041fd00(void);
extern void func_0041f260(void);
extern void func_004135b0(void);
extern void func_00481fc0(void);
extern void func_00422280(void);
extern void func_0040517a(void);
extern void func_004012f0(void);
void Set2FiveCallPauseJmp_0041fd10(void) {
    Wrapper_0041fd00();
    g_state_0053a1f0 = 2;
    func_0041f260();
    if (g_framePauseFlag) return;
    func_004135b0();
    if (g_framePauseFlag) return;
    func_00481fc0();
    if (g_framePauseFlag) return;
    func_00422280();
    if (g_framePauseFlag) return;
    func_0040517a();
    if (g_framePauseFlag) return;
    func_004012f0();
}
