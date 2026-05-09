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

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_GEO_H */
