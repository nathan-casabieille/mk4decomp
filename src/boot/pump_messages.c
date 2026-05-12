/**
 * Win32 message pump driver.
 *
 * Pumps up to 20 messages per call, then dispatches state machine
 * actions based on TryInitRenderer's return code (a 5-way switch
 * over rc + 5 in the range [0, 4]). Each switch arm clears one of
 * the 4 per-renderer-mode flags and conditionally invokes
 * GameStateMachine with a mode argument.
 *
 * After UpdateWindowTitle, blocks on WaitMessage if either of two
 * "needs more work" globals is clear; loops back if so.
 */
#include "platform/win32.h"
#include "engine/render.h"
#include "game/statemachine.h"

extern int  TryInitRenderer(void);                       /* 0x004b3ed0 */
extern void UpdateWindowTitle(void);                     /* 0x004b22e0 */

extern u32  g_pumpFlagD8;        /* 0x00f9f7d8 */
extern u32  g_pumpFlagDC;        /* 0x00f9f7dc */
extern u32  g_pumpFlagE0;        /* 0x00f9f7e0 */
extern u32  g_pumpFlagE4;        /* 0x00f9f7e4 */
extern u32  g_pumpFlagE8;        /* 0x00f9f7e8 */
extern u32  g_pumpFlagEC;        /* 0x00f9f7ec */
extern u32  g_pumpFlagF0;        /* 0x00f9f7f0 */
extern u32  g_rendererCheckVal;  /* 0x00ab5748 */

const u32 PumpMsg_JumpTable[5] = {0, 0, 0, 0, 0};

/*
 * @addr 0x004c52a0
 */
void PumpMessages(void)
{
    BOOL (WINAPI *p_trans)(const MSG *) = TranslateMessage;
    LRESULT (WINAPI *p_disp)(const MSG *) = DispatchMessageA;
    MSG msg;
    int i;

    g_pumpFlagEC = 0;

    do {
        for (i = 0; i < 20; i++) {
            if (!PeekMessageA(&msg, NULL, 0, 0, 0)) {
                break;
            }
            if (!GetMessageA(&msg, NULL, 0, 0)) {
                ExitGame();
            }
            p_trans(&msg);
            p_disp(&msg);
        }

        if (g_pumpFlagF0 == 1) {
            g_pumpFlagF0 = 0;
        }

        switch (TryInitRenderer()) {
        case -1:
            g_pumpFlagD8 = 0;
            if (g_rendererCheckVal == 0) {
                GameStateMachine(6);
            }
            break;
        case -2:
            g_pumpFlagDC = 0;
            if (g_rendererCheckVal == 0) {
                GameStateMachine(4);
            }
            break;
        case -3:
            g_pumpFlagE0 = 0;
            if (g_rendererCheckVal == 0) {
                GameStateMachine(5);
            }
            break;
        case -5:
            g_pumpFlagE4 = 0;
            if (g_rendererCheckVal == 0) {
                GameStateMachine(5);
            }
            break;
        }

        UpdateWindowTitle();

        if (g_pumpFlagF0 == 0 || g_pumpFlagE8 != 0) {
            WaitMessage();
        }
    } while (g_pumpFlagF0 == 0 || g_pumpFlagE8 != 0);
}
