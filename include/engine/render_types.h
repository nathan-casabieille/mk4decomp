/**
 * Render-pipeline data structures (geometry / draw-queue / device).
 *
 * These are kept OUT of render.h on purpose: render.h is included by
 * the pure-C render.c translation unit, and adding type definitions
 * there shifts MSVC SP3's internal local-label ($L*) numbering, which
 * the byte-exact synthesizer resolves through a curated extras_map.
 * Defining the structs in this separate header - included only by the
 * naked __asm consumers (which have no compiler-generated $L labels) -
 * keeps `make matching` byte-identical (Mismatches: 0).
 *
 * Nothing here is referenced by C code yet; the consumers are still
 * naked and read these layouts via raw offsets. The typedefs exist as
 * the verified, named reference those offsets map onto (see the
 * cross-reference comments in submit_draw.c, draw_mesh_block.c,
 * glide_tri_batch_emit.c and renderer1_init_glide.c).
 */
#ifndef MK4_ENGINE_RENDER_TYPES_H
#define MK4_ENGINE_RENDER_TYPES_H

#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* One queued triangle (DRAW_QUEUE_SIZE = 28 bytes) in g_drawQueue.
 * DrawMeshBlock fills it from the screen-space tri-strip ring (writing
 * the three vertices as packed X:low / Y:high dwords at +0/+4/+8), then
 * SubmitDrawEntry frustum-culls and copies it into g_drawQueue.
 *
 * Verified against SubmitDrawEntry @0x004c3360: the X coords (+0/+4/+8)
 * are bounds-checked against the 640/740 width envelope, the Y coords
 * (+2/+6/+0x0a) against the 480/580 height envelope. The flags byte's
 * bit 0x20 marks a triangle (vs quad), causing vertex 1 to be skipped
 * in both bounds loops. */
typedef struct DrawEntry {
    s16 x0, y0;          /* +0x00/+0x02 vertex 0 screen X / Y          */
    s16 x1, y1;          /* +0x04/+0x06 vertex 1 (skipped if flags&0x20) */
    s16 x2, y2;          /* +0x08/+0x0A vertex 2 screen X / Y          */
    u8  _0c[6];          /* +0x0C..+0x11 coords / UVs / colors         */
    u16 sort_key;        /* +0x12 z key, rewritten to bucket id via g_zSortKeyLUT */
    u8  _14[6];          /* +0x14..+0x19 UVs / shaded RGB555 colors    */
    u8  flags;           /* +0x1A bit 0x20 = skip vertex 1 (tri vs quad);
                                  bit 0x400 carries the facing/valid bit */
    u8  _1b;             /* +0x1B                                       */
} DrawEntry;             /* 28 bytes (DRAW_QUEUE_SIZE) */

/* Direct3D 2 transformed-and-lit vertex (D3DVT_TLVERTEX = 3, the vertex
 * type Renderer2_FlushBatch_D3D passes to DrawPrimitive). 32 bytes -
 * already screen-space, so no device transform is applied.
 *
 * Verified against GlideTriBatchEmit, which writes 3 of these
 * per triangle (stride 96 = batchCount*3*32): sx/sy from the projected
 * screen coords, sz/rhw pinned to 1.0 (0x3f800000), color packed from
 * the RGB555 palette (g_palette), specular left untouched, and
 * tu/tv looked up in the perspective table g_renderer2_lutTable. */
typedef struct D3DTLVertex {
    f32 sx, sy;          /* +0x00/+0x04 screen-space X / Y             */
    f32 sz;              /* +0x08 screen-space Z (depth) - pinned 1.0   */
    f32 rhw;             /* +0x0C reciprocal homogeneous W - pinned 1.0 */
    u32 color;           /* +0x10 D3DCOLOR (packed ARGB from palette)   */
    u32 specular;        /* +0x14 D3DCOLOR specular (not written here)  */
    f32 tu, tv;          /* +0x18/+0x1C texture coords (g_renderer2_lutTable) */
} D3DTLVertex;           /* 32 bytes */

/* 3dfx Glide hardware-config struct (GrHwConfiguration, 0x25 = 37
 * dwords) that Renderer1_Init_Glide zero-clears then fills via the
 * grSstQueryHardware function pointer (g_glideFnTable+0x44). The game
 * only reads num_sst (must be >= 1, i.e. at least one Voodoo board);
 * the rest is opaque and only handed back to grSstWinOpen by pointer
 * (g_glideFnTable+0x48). Lives at g_glideAdapterInfo (0x007afeb0). */
typedef struct GrHwConfiguration {
    s32 num_sst;          /* +0x00 number of 3dfx SST boards detected   */
    u32 sst_boards[36];   /* +0x04..+0x90 per-board descriptors (opaque) */
} GrHwConfiguration;      /* 37 dwords = 0x94 bytes */

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_RENDER_TYPES_H */
