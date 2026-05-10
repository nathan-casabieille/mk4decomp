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
 * occupy: data_a is at &block.ofs_a + ofs_a, etc. */
typedef struct geo_block {
    u16 type;             /* 1 = standard mesh in characters */
    u16 count;            /* element count (varies by type) */
    s32 ofs_a;            /* relative offset to vertex stream */
    s32 ofs_b;            /* relative offset to header stream */
    s32 ofs_c;            /* relative offset to end / extra */
} geo_block;

/* Per-vertex layout in the mesh stream (12 bytes total). */
typedef struct geo_vertex {
    s16 pos_x, pos_y, pos_z;   /* 16-bit fixed-point model space */
    s16 nrm_x, nrm_y, nrm_z;   /* normal (suspected) */
} geo_vertex;

/* Triangle-strip header pair (4 bytes). Read until count < 0. */
typedef struct geo_strip_header {
    u16 flag;             /* bit 0 = winding direction */
    s16 count;            /* triangle count (sentinel: < 0 ends block) */
} geo_strip_header;

/* Texture chunk entry (8-byte header + raw RLE-555 data). */
typedef struct geo_tex_entry {
    u16 width;
    u16 height;
    u32 data_size;
    /* u8 rle_data[data_size]; */
} geo_tex_entry;

/* === API ====================================================== */

/* Default-flag wrapper around LoadGeoAsset_Textures. */
void LoadGeoAsset_Default(void);                         /* 0x004bd5b0 */

/* Load a .geo asset's textures. The flag argument controls the
 * texture-load behavior; LoadGeoAsset_Default passes 0. */
void LoadGeoAsset_Textures(s32 flag);                    /* 0x004bd6e0 */

/* Decode a RLE-555 texture block into the staging buffer at
 * 0xf4d050. row_width is clamped to 14 (or kept at <=14) and
 * passed to the upload helper at the end. */
void Tex_DecodeRLE16(s32 row_width, s32 row_pixels, s32 row_count,
                     const u8 *src, s32 arg5);           /* 0x004bd5f0 */

/* === Joystick subsystem ===================================== */

/* Joystick / gamepad enumeration + calibration. Iterates up to
 * 16 joystick devices, calls joyGetPos + joyGetDevCapsA on each,
 * pre-computes per-device calibration tables (magic-divide-by-50
 * unsigned division of the (max-min)*33 scaled deltas), and runs
 * a 256-iteration tail loop for input-mapping initialization. */
void Joystick_Init(void);                                /* 0x004b5230 */

/* Helper called 256 times in the Joystick_Init tail loop with
 * the iteration index as the arg. */
void Helper_JoyButtonInit(s32 idx);                      /* 0x004b5450 */

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
