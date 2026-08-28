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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern int g_renderer1_active;
extern int g_renderer1_surface;
extern int g_renderer1_busy;
extern unsigned char g_glideColorFlushByte;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_fnptr_007b000c (*(unsigned int (**)())MK4_VA(unsigned int, 0x7b000cu))
#define g_glideColorFlushByte (*(unsigned char *)MK4_VA(unsigned char, 0x4f4b4cu))
#define g_renderer1_active (*(int *)MK4_VA(int, 0x7affe4u))
#define g_renderer1_busy (*(int *)MK4_VA(int, 0x7afff0u))
#define g_renderer1_surface (*(int *)MK4_VA(int, 0x7afff4u))
#endif

#ifndef MK4_ARENA
extern void (__stdcall *g_fnptr_007b000c)(int, int, int);
#endif
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
        g_fnptr_007b000c(0, 0, 0xffff);
    }
    g_glideColorFlushByte = 0xff;
    g_renderer1_surface = 1;
}
