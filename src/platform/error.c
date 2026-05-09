/**
 * Fatal-error display path.
 *
 * Tears down subsystems via Helper_GfxCleanup, drains the message
 * queue while the user is still alive, pops up a MessageBox if a
 * message was supplied, then ExitGame()s. Re-entry while already
 * in the error handler skips straight to ExitGame.
 */
#include "platform/win32.h"
#include "engine/render.h"
#include "game/tick.h"

#ifndef WM_QUIT
#define WM_QUIT 0x0012
#endif

/*
 * @addr 0x004c48c0
 */
void ShowErrorMessage(const char *msg)
{
    MSG  msg_local;
    s32  i;

    if (g_inErrorHandler != 0) {
        ExitGame();
    }
    g_inErrorHandler = 1;
    Helper_GfxCleanup();
    if (msg != NULL) {
        if (Renderer_GetMode() == 4 || Renderer_GetMode() == 0) {
            InvalidateRect(g_hMainWindow, NULL, TRUE);
            for (i = 0; i < 1000; i++) {
                if (!PeekMessageA(&msg_local, NULL, 0, 0, PM_REMOVE)) {
                    break;
                }
            }
            MessageBoxA(g_hMainWindow, msg,
                        "Mortal Kombat 4 Error", MB_ICONHAND);
        }
    }
    ExitGame();
}
