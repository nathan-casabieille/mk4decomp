/**
 * Register and create the main MK4 window.
 *
 * Builds a WNDCLASS (style, WndProc, hInstance, default cursor,
 * dark gray brush, "Mortal Kombat 4" class name) and registers
 * it. Picks a window position centered in the work area (with
 * SystemParametersInfo SPI_GETWORKAREA), creates the window
 * 640x480 + margins, ShowWindow (twice - once with the cmd-line
 * show, once with SW_NORMAL), UpdateWindow, then runs
 * Helper_PostCreateWindow whose return value is stashed into
 * g_mode4PauseGate.
 */
#include "platform/win32.h"
#include "game/tick.h"
#include <string.h>

extern void ShowErrorMessage(const char *msg);

static const char $SG_mk4[]     = "Mortal Kombat 4";
static const char $SG_regfail[] = "RegisterClass()";
static const char $SG_winfail[] = "CreateWindow()";

#define G_WC ((WNDCLASSA *)&g_wndClassStyle)

/*
 * @addr 0x004c5070
 */
void Boot(void)
{
    RECT workArea;
    int  window_w, window_h;
    int  work_w, work_h;
    int  x, y;

    memset(G_WC, 0, sizeof(WNDCLASSA));
    G_WC->style         = 0x102b;
    G_WC->lpfnWndProc   = WndProc;
    G_WC->hInstance     = g_hInstance;
    G_WC->hIcon         = LoadIconA(g_hInstance, MAKEINTRESOURCEA(0x80));
    G_WC->hCursor       = LoadCursorA(NULL, MAKEINTRESOURCEA(0x7f00));
    G_WC->hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    G_WC->lpszClassName = $SG_mk4;

    if (!(unsigned short)RegisterClassA(G_WC)) {
        ShowErrorMessage($SG_regfail);
    }

    window_w = g_clientWidth  + 0x140;
    window_h = g_clientHeight + 0xf0;
    SystemParametersInfoA(SPI_GETWORKAREA, 0, &workArea, 0);

    work_w = workArea.right  - workArea.left;
    work_h = workArea.bottom - workArea.top;

    if (window_w >= work_w) {
        window_w = work_w;
        x = 0;
    } else {
        x = workArea.left + (work_w - window_w) / 2;
    }
    if (window_h >= work_h) {
        window_h = work_h;
        y = 0;
    } else {
        y = workArea.top + (work_h - window_h) / 2;
    }

    g_hMainWindow = CreateWindowExA(0x300, $SG_mk4, $SG_mk4, 0xcb0000,
                                     x, y, window_w, window_h,
                                     NULL, NULL, g_hInstance, NULL);
    if (!g_hMainWindow) {
        ShowErrorMessage($SG_winfail);
    }

    ShowWindow(g_hMainWindow, g_nCmdShow);
    ShowWindow(g_hMainWindow, 10);
    UpdateWindow(g_hMainWindow);
    g_mode4PauseGate = Helper_PostCreateWindow();
}
