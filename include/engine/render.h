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
int Renderer3_Init_SW_FS(HWND hwnd, char *param);        /* 0x004af8c0 */
int Renderer5_Init_SW_FS_Hi(HWND hwnd, char *param);     /* 0x004b00f0 */

/* Renderer 3 / 5 sub-helpers (DDraw fullscreen path). */
s32  DDraw3_Create(void);                                /* 0x004afb30 */
void DDraw3_PostCreate(void);                            /* 0x004af960 */
s32  DDraw3_CreateSurface(s32 mode);                     /* 0x004afd10 */
s32  DDraw3_SetCooperativeLevel(void);                   /* 0x004afb70 */
void DDraw3_GetSurface(void);                            /* 0x004afb00 */
void DDraw3_Cleanup(void);                               /* 0x004afa10 */

s32  DDraw5_Create(void);                                /* 0x004b0360 */
void DDraw5_PostCreate(void);                            /* 0x004b0190 */
s32  DDraw5_CreateSurface(s32 mode);                     /* 0x004b0540 */
s32  DDraw5_SetCooperativeLevel(void);                   /* 0x004b03a0 */
void DDraw5_GetSurface(void);                            /* 0x004b0330 */
void DDraw5_Cleanup(void);                               /* 0x004b0240 */

extern u32 g_renderer3_hwnd_obj;        /* 0x0058c87c */
extern s32 g_renderer3_surface_active;  /* 0x0058c884 */
extern u8  g_renderer3_initByte;        /* 0x004f47a4 */

extern u32 g_renderer5_hwnd_obj;        /* 0x0058c8fc */
extern s32 g_renderer5_surface_active;  /* 0x0058c904 */
extern u8  g_renderer5_initByte;        /* 0x004f47ac */

void Renderer1_PresentFrame(void);                       /* 0x004b46d0 */
void Renderer2_PresentFrame(void);                       /* 0x004ae950 */
void Renderer3_PresentFrame(void);                       /* 0x004af690 */
void Renderer4_PresentFrame(void);                       /* 0x004b2840 */
void Renderer5_PresentFrame(void);                       /* 0x004afec0 */

/* Per-renderer EndScene (called from DrawScene per the active mode). */
void Renderer1_EndScene_Glide(void);                     /* 0x004b46a0 */
void Renderer2_EndScene_D3D(void);                       /* 0x004adc20 */
void Renderer3_EndScene_SW_FS(void);                     /* 0x004af880 */
void Renderer4_EndScene_SW_Win(void);                    /* 0x004b2930 */
void Renderer5_EndScene_SW_FS_Hi(void);                  /* 0x004b00b0 */

/* BeginFrame fan-out. Cases 3 / 4 / 5 receive output args for the
 * computed viewport rect; cases 1 / 2 take just the flag. */
void Renderer1_BeginFrame_Glide(int flag);                                            /* 0x004b4650 */
void Renderer2_BeginFrame_D3D(int flag);                                              /* 0x004ada10 */
void Renderer3_BeginFrame_SW_FS(int flag, int *out_a, int *out_b, int *out_c);        /* 0x004af730 */
void Renderer4_BeginFrame_SW_Win(int flag, int *out_a, int *out_b, int *out_c);       /* 0x004aff60 */
void Renderer5_BeginFrame_SW_FS_Hi(int flag, int *out_a, int *out_b, int *out_c);     /* 0x004b28a0 */

/* === Sort key LUT (z-bucketing) ============================== */

/* 128 KB sort-key lookup. Built once at startup by BuildSortKeyLUT.
 * Maps z (0..65535) → bucket via hyperbolic 1/z:
 *   bucket(z) = 65536 * z / (31 * z + 65536) */
void BuildSortKeyLUT(void);                              /* 0x004bf290 */
extern u16 g_zSortKeyLUT[65536];                         /* 0x00b0d008 */

/* === Engine init ============================================== */

/* Bring up the renderer pipeline. Returns 1 on success, 0 on
 * failure (after invoking ShowErrorMessage). Tries hwnd-driven
 * SW-windowed init (mode 4) by default. */
s32 Gfx_Init(HWND hwnd);                                 /* 0x004b4370 */

/* Sub-helpers used by Gfx_Init and called from a few other places. */
s32  Helper_GfxInit2(HWND hwnd);                         /* 0x004b2950 */
void Helper_GfxCleanup(void);                            /* 0x004b4410 */

extern s32  g_gfxInited;        /* 0x007afa08 */
extern HWND g_gfxHwnd;          /* 0x007afa04 */
extern s32  g_gfxFlagA;         /* 0x007afa0c */
extern s32  g_gfxFlagB;         /* 0x007afa10 */
extern s32  g_gfxFlagC;         /* 0x007afa14 */

/* === Vertex transform state ================================== */

/* Input local-space coords (16-bit, packed at +0x6 stride to match
 * the orig - actually they're at base + 0, +6, +12 because the
 * struct layout interleaves with another field). */
extern s16  g_vtxIn_x;          /* 0x007af95c */
extern s16  g_vtxIn_y;          /* 0x007af962 */
extern s16  g_vtxIn_z;          /* 0x007af968 */

/* Camera/object matrix. 3 rows of 3 s16 columns; column-major or
 * row-major depending on the mul order in ProjectVertex. */
extern s16  g_vtxMat[9];        /* 0x007af990 */

/* Translation (s32 each). */
extern s32  g_vtxTransX;        /* 0x007af9a4 */
extern s32  g_vtxTransY;        /* 0x007af9a8 */
extern s32  g_vtxTransZ;        /* 0x007af9ac */

/* Output world-space coords (s32 each). */
extern s32  g_vtxOut_x;         /* 0x007af974 */
extern s32  g_vtxOut_y;         /* 0x007af980 */
extern s32  g_vtxOut_z;         /* 0x007af98c */

/* "Vertex valid" flag and projected screen coords (s16 each). */
extern s32  g_vtxValid;         /* 0x007af9b0 */
extern s16  g_vtxScreenX;       /* 0x007af9bc */
extern s16  g_vtxScreenY;       /* 0x007af9be */

/* Project g_vtxIn_* through g_vtxMat / g_vtxTrans*, store the
 * world coords to g_vtxOut_*, then perspective-divide and scale
 * into g_vtxScreen{X,Y}. */
void ProjectVertex(void);                                /* 0x004b2e80 */

/* Apply vertex-light shading on the working RGB555 color in
 * g_vtxColor. Uses two light directions (g_vtxLight0/1) and per-
 * channel intensities g_vtxRGBScale0/1; result is clamped to 5
 * bits per channel and stored back to g_vtxColor. */
void TransformVertex(s16 x, s16 y, s16 z);              /* 0x004b3310 */

/* Light directions and per-channel scale bytes used by
 * TransformVertex - layout is two adjacent (s32 x, y, z) blocks
 * followed by 6 per-channel byte intensities, then the working
 * RGB555 color. */
extern s32 g_vtxLight0_x;       /* 0x007af9d8 */
extern s32 g_vtxLight0_y;       /* 0x007af9dc */
extern s32 g_vtxLight0_z;       /* 0x007af9e0 */
extern s32 g_vtxLight1_x;       /* 0x007af9e4 */
extern s32 g_vtxLight1_z;       /* 0x007af9e8 */
extern s32 g_vtxLight1_y;       /* 0x007af9ec */

/* Working color (RGB555). Read at 0x7af9fc, copy at 0x7af9f8. */
extern u32 g_vtxColorPrev;      /* 0x007af9f0 */
extern u8  g_vtxRGBScale1_b;    /* 0x007af9f2 */
extern u8  g_vtxRGBScale1_g;    /* 0x007af9f3 */
extern u8  g_vtxRGBScale0_g;    /* 0x007af9f4 */
extern u8  g_vtxRGBScale1_r;    /* 0x007af9f5 */
extern u8  g_vtxRGBScale0_r;    /* 0x007af9f6 */
extern u8  g_vtxRGBScale0_b;    /* 0x007af9f7 */
extern u16 g_vtxColorCopy;      /* 0x007af9f8 */
extern u16 g_vtxColorSaved;     /* 0x007af9fa */
extern u16 g_vtxColor;          /* 0x007af9fc */

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

/* Renderer 3 (Software Fullscreen) holds an IDirectDrawSurface*-like
 * COM object whose vtable method at slot 32 (offset 0x80) is invoked
 * each EndScene with arg=0. Likely IDirectDrawSurface::Flip(NULL). */
typedef struct DDSurface DDSurface;
typedef long (__stdcall *DDSurface_Method)(DDSurface *self, int flags);
typedef struct DDSurfaceVtbl {
    void *m_0_to_31[32];               /* unused-by-us slots 0..31 */
    DDSurface_Method method32;         /* slot 32 = offset 0x80 */
} DDSurfaceVtbl;
struct DDSurface {
    DDSurfaceVtbl *vtbl;
};

extern DDSurface *g_renderer3_obj;       /* 0x0058c868 */
extern int       g_renderer3_active;     /* 0x0058c874 */
extern int       g_renderer3_present_rc; /* 0x0058c878 (last Flip return) */
extern int       g_renderer3_surface;    /* 0x0058c880 */

extern DDSurface *g_renderer5_obj;       /* 0x0058c8e8 */
extern int       g_renderer5_active;     /* 0x0058c8f4 */
extern int       g_renderer5_present_rc; /* 0x0058c8f8 */
extern int       g_renderer5_surface;    /* 0x0058c900 */

/* Renderer 2 (Direct3D) holds a COM-like object whose vtable method
 * at slot 11 (offset 0x2c) is invoked each EndScene with no extra
 * args - likely IDirect3DDevice2::EndScene or an IDirectDrawSurface
 * Flip variant on the Direct3D back buffer. Slot 29 is the
 * primitive-draw call invoked by FlushBatch. */
typedef struct D3DObj D3DObj;
typedef long (__stdcall *D3DObj_Method)(D3DObj *self);
typedef long (__stdcall *D3DObj_DrawMethod)(D3DObj *self, u32 ptype, u32 vtype,
                                            void *verts, u32 count, u32 flags);
typedef struct D3DObjVtbl {
    void *m_0_to_10[11];               /* unused-by-us slots 0..10 */
    D3DObj_Method method11;            /* slot 11 = offset 0x2c */
    void *m_12_to_28[17];              /* unused-by-us slots 12..28 */
    D3DObj_DrawMethod method29;        /* slot 29 = offset 0x74 */
} D3DObjVtbl;
struct D3DObj {
    D3DObjVtbl *vtbl;
};

extern D3DObj *g_renderer2_obj;          /* 0x0058c7c0 */
extern u32    g_renderer2_hwnd;          /* 0x0058c7d8 */
extern int    g_renderer2_present_rc;    /* 0x0058c7dc */
extern int    g_renderer2_active;        /* 0x0058c7e0 */
extern int    g_renderer2_surface;       /* 0x0058c7e4 */
extern int    g_renderer2_initOk;        /* 0x0058c7e8 */
extern int    g_renderer2_paused;        /* 0x0058c7ec - skip flag */

extern u8     g_renderer2_buf1[64];      /* 0x0058c768 */
extern u8     g_renderer2_buf2[64];      /* 0x0058c720 */
extern u8     g_renderer2_buf3[64];      /* 0x00544258 */
extern f32    g_renderer2_lutTable[];    /* 0x00544308 - 256 floats */

/* The increment constant for filling g_renderer2_lutTable. */
extern f32    g_renderer2_lutStep;       /* 0x004d2960 */

/* Renderer 2 sub-helpers (matched stubs). */
s32  R2_Init1(void);                     /* 0x004adde0 */
s32  R2_Init2(void);                     /* 0x004aef00 */
s32  R2_Init3(void);                     /* 0x004ae990 */
s32  R2_Init4(s32 mode);                 /* 0x004aeae0 */
s32  R2_Init5(void);                     /* 0x004af250 */
s32  R2_Init6(void);                     /* 0x004aef50 */
s32  R2_Init7(void);                     /* 0x004af480 */
s32  R2_Init8(void);                     /* 0x004aec90 */
s32  R2_Init9(void);                     /* 0x004af190 */
void R2_Init10(void);                    /* 0x004aedb0 */
s32  R2_Init11(s32 idx);                 /* 0x004af020 */
void R2_Cleanup(void);                   /* 0x004ad7c0 */
extern s32    g_renderer2_batchCount;    /* 0x0058c7f0 - queued tris (count) */

/* Buffer of pending D3D primitives flushed by Renderer2_FlushBatch_D3D. */
extern u8     g_renderer2_vertexBatch[]; /* 0x00544718 */

/* Submit any pending D3D primitive batch and reset the queued
 * vertex counter. Called from Renderer2_EndScene_D3D. */
void Renderer2_FlushBatch_D3D(void);                    /* 0x004adc60 */

extern u32  g_drawQueueSize;         /* 0x00f85b40 */
extern u8   g_drawQueue[DRAW_QUEUE_MAX * DRAW_QUEUE_SIZE]; /* 0x00f71310 */
extern u32  g_drawQueueBuckets[DRAW_QUEUE_BUCKETS];       /* 0x00f6d050 */

/* Per-frame clip-rect scratch reused by SubmitDrawEntry's two
 * bounds-loops (X then Y). */
extern s32  g_clipMinScratch;        /* 0x00f70f70 */
extern s32  g_clipMaxScratch;        /* 0x00f70f78 */

extern u32  g_drawSceneTimeMs;       /* 0x007afa00 - profiling */

/* The DAT_*  references above use VAs - the matching build pulls
 * them in via the linker script which places the BSS segments at
 * those exact addresses. Don't change names. */

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_RENDER_H */
