/**
 * Renderer4 (SW-Win backend) frame presentation - DirectDraw Blt-style call.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b2840 (74b)
 *   if [0x7af940] != 0: call helper; load 3 globals as args;
 *   push 9 fixed-args + 3 globals (DirectDraw Blt-style call);
 *   IAT call; tail-jmp to second IAT slot. Else: ret.
 */
extern int g_renderer4_active;
extern unsigned int g_dispatchSave1620_007af934;
extern unsigned int g_dispatchSave1624_007af94c;
extern unsigned int g_dispatchSave1621_007af938;
extern void (__stdcall *g_iat_004d2034)(unsigned int, int, int, int, int, int, int, int, int, unsigned int, unsigned int, int);
extern void (__stdcall *g_iat_004d2040)(void);
extern void Renderer4_EndScene_SW_Win(void);
void Renderer4_PresentFrame(void) {
    if (!g_renderer4_active) return;
    Renderer4_EndScene_SW_Win();
    g_iat_004d2034(g_dispatchSave1621_007af938, 0, 0, 0x140, 0xf0, 0, 0, 0, 0xf0, g_dispatchSave1624_007af94c, g_dispatchSave1620_007af934, 0);
    g_iat_004d2040();
}
