/**
 * Process entry point.
 *
 * Sets up the SEH frame, stashes the standard WinMain args, creates
 * the single-instance file mapping (named "Mortal Kombat 4"), then
 * runs Boot + AppInit and enters the per-frame loop. Any unhandled
 * exception is swallowed by the __except handler.
 */
#include "platform/win32.h"

/*
 * @addr 0x004c53c0
 *
 * The body never returns under normal operation - the for(;;) loop
 * runs forever. The __except clause is the only path that reaches
 * the function tail.
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev,
                   LPSTR lpCmdLine, int nCmdShow)
{
    __try {
        char _scratch[1024];                 /* unused, but the orig allocates */
        s32  _pad;                            /* 4-byte tail to hit -0x40c */
        g_hInstance = hInstance;
        g_cmdLine   = lpCmdLine;
        g_nCmdShow  = nCmdShow;
        g_hAppMutex = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL,
                                         PAGE_READONLY, 0, 0x20,
                                         "Mortal Kombat 4");
        if (GetLastError() != 0) {
            ExitGame();
        }
        Boot();
        AppInit(g_hMainWindow);
        for (;;) {
            MainLoopStep();
            MainLoopStep();
            PumpMessages();
        }
    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
    return 0;
}
