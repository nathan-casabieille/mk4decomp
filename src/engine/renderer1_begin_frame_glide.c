/**
 * Renderer1 (Glide backend) frame begin - sound channel disable gate.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b4650 (68b)
 *   Sound channel disable gate.
 *   if g_soundEnabled (0x7affe4) == 0: ret;
 *   if g_soundDisabled1 (0x7afff4) != 0: ret;
 *   if g_soundDisabled2 (0x7afff0) != 0: ret;
 *   if arg0 != 0: call IAT[0x7b000c](0, 0, 0xffff)
 *   set byte [0x4f4b4c] = 0xff; set [0x7afff4] = 1; ret.
 */
extern int g_renderer1_active;
extern int g_renderer1_surface;
extern int g_renderer1_busy;
extern unsigned char g_byte_004f4b4c;
extern void (__stdcall *g_iat_007b000c)(int, int, int);
void Renderer1_BeginFrame_Glide(int arg) {
    if (g_renderer1_active == 0) {
        return;
    }
    if (g_renderer1_surface != 0) {
        return;
    }
    if (g_renderer1_busy != 0) {
        return;
    }
    if (arg != 0) {
        g_iat_007b000c(0, 0, 0xffff);
    }
    g_byte_004f4b4c = 0xff;
    g_renderer1_surface = 1;
}
