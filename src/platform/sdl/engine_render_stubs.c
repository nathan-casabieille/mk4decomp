/**
 * Weak stubs for the renderer backends the native port never takes.
 *
 * src/engine/render.c dispatches BeginFrame / PresentFrame / EndScene across
 * five backends: Glide (1), Direct3D (2), software fullscreen (3), software
 * windowed (4) and software fullscreen hi-res (5). The native port runs mode 5
 * with an arena framebuffer (see engine_video.c), so the other four are dead
 * paths - but render.c still references them, and their COM/DirectDraw state
 * globals are not in the generated global set.
 *
 * These weak definitions close the link without pretending the paths work. A
 * real conversion of any backend overrides its stub automatically.
 */
#include "engine/render.h"

#ifdef MK4_NATIVE_FULL

__attribute__((weak)) void Renderer1_BeginFrame_Glide(int flag) { (void)flag; }
__attribute__((weak)) void Renderer2_BeginFrame_D3D(int flag)   { (void)flag; }
__attribute__((weak)) void Renderer3_BeginFrame_SW_FS(int flag, int *a, int *b, int *c)
{ (void)flag; if (a) *a = 0; if (b) *b = 0; if (c) *c = 0; }
__attribute__((weak)) void Renderer4_BeginFrame_SW_Win(int flag, int *a, int *b, int *c)
{ (void)flag; if (a) *a = 0; if (b) *b = 0; if (c) *c = 0; }

__attribute__((weak)) void Renderer1_PresentFrame(void) { }
__attribute__((weak)) void Renderer2_PresentFrame(void) { }
__attribute__((weak)) void Renderer3_PresentFrame(void) { }
__attribute__((weak)) void Renderer4_PresentFrame(void) { }
/* mode 5 presents through the platform layer after the frame body */
__attribute__((weak)) void Renderer5_PresentFrame(void) { }

/* --- backend state the generated global set does not carry --------------
 * Types match include/engine/render.h. Mode 5's four are what the engine's
 * own EndScene tests; with obj == 0 it is a no-op, which is right here since
 * the present happens through the platform layer. */
__attribute__((weak)) int g_renderer1_active;
__attribute__((weak)) int g_renderer1_busy;
__attribute__((weak)) int g_renderer1_surface;
__attribute__((weak)) D3DObj *g_renderer2_obj;
__attribute__((weak)) int g_renderer2_active;
__attribute__((weak)) int g_renderer2_surface;
__attribute__((weak)) int g_renderer2_present_rc;
__attribute__((weak)) int g_renderer2_paused;
__attribute__((weak)) s32 g_renderer2_batchCount;
__attribute__((weak)) u8  g_renderer2_vertexBatch[0x1000];
__attribute__((weak)) DDSurface *g_renderer3_obj;
__attribute__((weak)) int g_renderer3_active;
__attribute__((weak)) int g_renderer3_present_rc;
__attribute__((weak)) int g_renderer3_surface;
__attribute__((weak)) int g_renderer4_surface;
__attribute__((weak)) DDSurface *g_renderer5_obj;
__attribute__((weak)) int g_renderer5_active;
__attribute__((weak)) int g_renderer5_present_rc;
__attribute__((weak)) int g_renderer5_surface;

#endif /* MK4_NATIVE_FULL */
