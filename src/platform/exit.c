/**
 * Process-exit path.
 *
 * AppShutdown teardown + window close + handle cleanup, then
 * exit(0) into the CRT.
 */
#include "platform/win32.h"
#include <stdlib.h>

#ifndef WM_CLOSE
#define WM_CLOSE 0x0010
#endif

/*
 * @addr 0x004c4870
 */
void ExitGame(void)
{
    AppShutdown();
    if (g_hMainWindow != NULL) {
        SendNotifyMessageA(g_hMainWindow, WM_CLOSE, 0, 0);
    }
    if (g_hAppMutex != NULL) {
        CloseHandle(g_hAppMutex);
    }
    g_hAppMutex = NULL;
    exit(0);
}
