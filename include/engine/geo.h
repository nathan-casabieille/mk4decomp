/**
 * GEO - Eurocom geometry + texture format.
 *
 * .geo files are scene-graph + texture archives. Each contains:
 *   - 12-byte header (magic "0.1v" + tex_offset + file_size)
 *   - Mesh region: scene-graph node tree (16-byte block headers,
 *     fixed-point 16-bit vertex streams, triangle strips)
 *   - Texture chunk: RLE-555 compressed atlases (256x256 typical)
 *
 * See analysis/notes/architecture.md for the full byte-level layout.
 */
#ifndef MK4_ENGINE_GEO_H
#define MK4_ENGINE_GEO_H

#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GEO_MAGIC  0x76312E30   /* '0','.','1','v' */

/* File header (12 bytes). */
typedef struct geo_header {
    u32 magic;            /* GEO_MAGIC */
    u32 tex_offset;       /* offset of texture chunk */
    u32 file_size;
} geo_header;

/* Mesh block header - one per submesh / skeleton joint, 16 bytes.
 * `ofs_a`, `ofs_b`, `ofs_c` are RELATIVE offsets from the field they
 * occupy. Verified against DrawMeshBlock @0x004bb250, which derives:
 *     verts  = (geo_vertex *)((u8 *)block + 4 + block->ofs_a);
 *     header = (geo_strip_header *)((u8 *)block + 8 + block->ofs_b);
 * i.e. data_a is at &block->ofs_a + ofs_a (block+4+ofs_a). */
typedef struct geo_block {
    u16 type;             /* +0x00 1 = standard mesh in characters       */
    u16 count;            /* +0x02 element count (6..112 in characters)  */
    s32 ofs_a;            /* +0x04 rel. offset to VERTEX stream          */
    s32 ofs_b;            /* +0x08 rel. offset to strip HEADER stream    */
    s32 ofs_c;            /* +0x0C rel. offset to end of block's data    */
} geo_block;

/* Per-vertex layout in the mesh stream (12 bytes total).
 * DrawMeshBlock reads 2 base vertices (24 bytes) per strip, then one
 * fresh vertex (12 bytes) per triangle of the strip. The pos triple
 * feeds the screen-space tri-strip ring; the nrm triple is run through
 * TransformVertex (a pure rotation - normals rotate, UVs would not,
 * hence the "normal" reading). */
typedef struct geo_vertex {
    s16 pos_x, pos_y, pos_z;   /* +0x00/+0x02/+0x04 16-bit fixed-point model space */
    s16 nrm_x, nrm_y, nrm_z;   /* +0x06/+0x08/+0x0A rotated by TransformVertex (normal) */
} geo_vertex;

/* Triangle-strip header pair (4 bytes), one per strip in a block.
 * DrawMeshBlock walks the header stream reading these until count < 0. */
typedef struct geo_strip_header {
    u16 flag;             /* +0x00 bit 0 = winding (XOR'd with mode_param);
                                    bit 8 -> draw-entry flag-byte bit 7   */
    s16 count;            /* +0x02 triangle count (sentinel: < 0 ends block) */
} geo_strip_header;

/* Texture chunk header: a count followed by `count` geo_tex_entry.
 * LoadGeoAsset_Textures @0x004bd6e0 reaches it through the node's
 * runtime pointer (node[+4] + relative offset), and the offset lands
 * directly on `count`. On disk the count is preceded by a 4-byte
 * sub-header (two WORDs, e.g. 38b1 38b1 - see architecture.md ".geo
 * format"); the relative offset skips past it, so the parser never
 * reads the sub-header. */
typedef struct geo_tex_chunk {
    u32 count;            /* +0x00 number of geo_tex_entry that follow   */
    /* geo_tex_entry entries[count]; */
} geo_tex_chunk;

/* Texture chunk entry (8-byte header + raw RLE-555 data). Parsed by the
 * tex_loop in LoadGeoAsset_Textures: width/height become Tex_DecodeRLE16's
 * row_pixels/row_count, then the stream advances past data_size bytes. */
typedef struct geo_tex_entry {
    u16 width;            /* +0x00 always 256 in observed files          */
    u16 height;           /* +0x02 always 256 in observed files          */
    u32 data_size;        /* +0x04 byte length of the RLE-555 stream      */
    /* u8 rle_data[data_size]; */     /* +0x08 see Tex_DecodeRLE16        */
} geo_tex_entry;

/* === API ====================================================== */

/* Default-flag wrapper around LoadGeoAsset_Textures. */
void LoadGeoAsset_Default(void);                         /* 0x004bd5b0 */

/* Load a .geo asset's textures. The flag argument controls the
 * texture-load behavior; LoadGeoAsset_Default passes 0. */
void LoadGeoAsset_Textures(s32 flag);                    /* 0x004bd6e0 */

/* Pre/post hooks invoked by LoadGeoAsset_Textures. The "pre" pair
 * frees a couple of memory tags (4 and 2); the "post" hook is empty
 * in the shipping build (a single ret). */
void Helper_GeoLoadPre(void);                            /* 0x004bd570 */
void Helper_GeoLoadPost(void);                           /* 0x004bd6d0 */

/* sprintf wrapper used by LoadGeoAsset_Textures to build the
 * "c:\\source\\mk4\\win\\geogfx\\<name>" path. */
s32  Helper_Sprintf(char *buf, const char *fmt, ...);    /* 0x004c5580 */

/* Static path/asset-table state used by LoadGeoAsset_Textures: */
extern char g_geoAssetPath[1024];                         /* 0x00ab43d8 */
extern u32  g_curTexSlot;                                 /* 0x00ab4e74 */
extern u16  g_texSlots[16];                               /* 0x00ab4e00 */
extern u32  g_texNodeIdx[];                               /* 0x00ab4e78 */
extern u32  g_texCount[];                                 /* 0x00ab5038 */

/* Decode a RLE-555 texture block into the 256-pixel-wide staging
 * buffer at 0xf4d050, then upload the rectangle. The first argument
 * is the TEXTURE SLOT, clamped unsigned to 14, and it is what the
 * upload helper receives - it is not a width. LoadGeoAsset_Textures
 * pushes exactly four arguments; the fifth this used to declare does
 * not exist. */
void Tex_DecodeRLE16(s32 slot, s32 width, s32 height,
                     const u8 *src);                     /* 0x004bd5f0 */

/* === Joystick subsystem ===================================== */

/* Joystick / gamepad enumeration + calibration. Iterates up to
 * 16 joystick devices, calls joyGetPos + joyGetDevCapsA on each,
 * pre-computes per-device calibration tables (magic-divide-by-50
 * unsigned division of the (max-min)*33 scaled deltas), and runs
 * a 256-iteration tail loop for input-mapping initialization. */
void Joystick_Init(void);                                /* 0x004b5230 */

/* Helper called 256 times in the Joystick_Init tail loop with
 * the iteration index as the arg. */
s32  Input_GetAsyncKey(s32 vk);                        /* 0x004b5450 - (GetAsyncKeyState(vk) >> 15) & 1 */

extern u32 g_joyCalA[16];        /* 0x007b00c8 */
extern u32 g_joyCalB[16];        /* 0x007b0088 */
extern u32 g_joyCalC[16];        /* 0x007b0108 */
extern u8  g_joyButtonState[16]; /* 0x007b0188 */
extern u32 g_joyCount;           /* 0x007b0198 */

/* Upload helper invoked by Tex_DecodeRLE16 once the staging buffer
 * is filled - 5-arg cdecl wrapper. */
void Helper_TexUpload(s32 a, s32 b, s32 c, s32 d, s32 e);/* 0x004bf370 */

/* Texture stripe staging area (64 KB at 0xf4d050) and the XOR key
 * applied to RLE codes when their masked value is non-zero. */
extern u16 g_texStripeBuf[];                             /* 0x00f4d050 */
extern u32 g_texXorKey;                                   /* 0x007af91c */

/* === Mem heap allocator ===================================== */

/* First-fit splitting allocator over the [g_memHeapStart..g_memHeapEnd)
 * region. Each block has a 12-byte header:
 *   +0x00 (header)  - high bit = "free" flag, top byte = tag, low 24 bits = size
 *   +0x04 (caller)  - caller-supplied output pointer or metadata
 *   +0x08 (prev)    - back-link used to walk the heap
 * User data lives at &block + 0x0c. */
s32  Mem_Malloc(void **out_ptr, s32 size, s32 tag);     /* 0x004b5bc0 */

/* Post-allocation hook (rebuilds free-list shadow caches). */
void Helper_MemMalloc_Post(void);                        /* 0x004b5ad0 */

extern u8  g_memHeapStart[];     /* 0x007b41a0 */
extern u8  g_memHeapEnd[];       /* 0x00ab4194 - one past last byte */

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_GEO_H */
