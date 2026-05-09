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
