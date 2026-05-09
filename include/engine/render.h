/**
 * Render pipeline - frame phases, draw queue, viewport.
 *
 * Per-frame structure: BeginFrame → DrawScene → PresentFrame.
 * Draw entries are accumulated into a 28-byte queue and flushed
 * via counting sort by depth bucket. Per-mode dispatchers handle
 * Glide / D3D / SW rendering.
 */
#ifndef MK4_ENGINE_RENDER_H
#define MK4_ENGINE_RENDER_H

#include "../types.h"
#include "../platform/win32.h"  /* HWND */

#ifdef __cplusplus
extern "C" {
#endif

/* Renderer modes (set in g_currentRendererMode). */
#define RENDERER_MODE_GLIDE       1   /* 3dfx Glide via glide2x.dll */
#define RENDERER_MODE_D3D         2   /* Direct3D card */
#define RENDERER_MODE_SW_FS       3   /* Software fullscreen */
#define RENDERER_MODE_SW_WINDOWED 4   /* Software windowed (always available) */
#define RENDERER_MODE_SW_FS_HI    5   /* Software fullscreen hi-res */

#define DRAW_QUEUE_SIZE     28        /* bytes per entry */
#define DRAW_QUEUE_MAX     3000       /* max entries before drop */
#define DRAW_QUEUE_BUCKETS 1024       /* counting-sort histogram */

/* === Pipeline phases ========================================= */

void BeginFrame(int flag);                               /* 0x004b4200 */
void DrawScene(void);                                    /* 0x004b42e0 */
void PresentFrame(void);                                 /* 0x004b3e90 */
void FlushDrawQueue(void);                               /* 0x004bf460 */

void SubmitDrawEntry(s16 *entry);                        /* 0x004c3360 */
void SetViewport(int x, int y, int w, int h);            /* 0x004bf330 */

/* === Renderer init / dispatch ================================ */

int  SetRendererMode(int mode);                          /* 0x004b40a0 */
int  TryInitRenderer(void);                              /* 0x004b3ed0 */

int Renderer1_Init_Glide(HWND hwnd);                     /* 0x004b49a0 */
int Renderer2_Init_D3D(HWND hwnd);                       /* 0x004ad6a0 */
int Renderer3_Init_SW_FS(HWND hwnd, void *param);        /* 0x004af8c0 */
int Renderer5_Init_SW_FS_Hi(HWND hwnd, void *param);     /* 0x004b00f0 */

/* === Sort key LUT (z-bucketing) ============================== */

/* 128 KB sort-key lookup. Built once at startup by BuildSortKeyLUT.
 * Maps z (0..65535) → bucket via hyperbolic 1/z:
 *   bucket(z) = 65536 * z / (31 * z + 65536) */
void BuildSortKeyLUT(void);                              /* 0x004bf290 */
extern u16 g_zSortKeyLUT[65536];                         /* 0x00b0d008 */

/* === Globals ================================================= */

extern int g_currentRendererMode;    /* 0x004f4b3c */
extern int g_clampedRendererMode;    /* 0x004f4b38 */
extern int g_viewportX, g_viewportY; /* 0x00f85b50, 0x00f85b54 */
extern int g_viewportW, g_viewportH; /* 0x004ffd44, 0x004ffd48 */

/* Per-renderer state. Each EndScene_* checks "is this renderer
 * active and does it own a presentable surface" before clearing. */
extern int g_renderer4_active;       /* 0x007af940 */
extern int g_renderer4_surface;      /* 0x007af948 */

extern int g_renderer1_active;       /* 0x007affe4 */
extern int g_renderer1_busy;         /* 0x007afff0 */
extern int g_renderer1_surface;      /* 0x007afff4 */

extern u32  g_drawQueueSize;         /* 0x00f85b40 */
extern u8   g_drawQueue[DRAW_QUEUE_MAX * DRAW_QUEUE_SIZE]; /* 0x00f71310 */
extern u32  g_drawQueueBuckets[DRAW_QUEUE_BUCKETS];       /* 0x00f6d050 */

extern u32  g_drawSceneTimeMs;       /* 0x007afa00 - profiling */

/* The DAT_*  references above use VAs - the matching build pulls
 * them in via the linker script which places the BSS segments at
 * those exact addresses. Don't change names. */

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_RENDER_H */
