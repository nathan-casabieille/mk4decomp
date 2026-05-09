/**
 * MK4 base typedefs.
 *
 * Match MSVC 5.0 / Win32 conventions used in the original binary.
 * Most fixed-point math in the engine uses 16-bit signed integers
 * with various scaling (vertices, BAM angles, etc.).
 */
#ifndef MK4_TYPES_H
#define MK4_TYPES_H

#ifdef _WIN32
#include <windows.h>
#endif

/* Fixed-width integers — MSVC 5.0 predates <stdint.h>. */
typedef signed char         s8;
typedef unsigned char       u8;
typedef short               s16;
typedef unsigned short      u16;
typedef int                 s32;
typedef unsigned int        u32;
typedef long long           s64;
typedef unsigned long long  u64;

typedef float               f32;
typedef double              f64;

/* Engine-specific aliases used in the decomp.
 * BAM = binary angle measure; 0x1000 = 2π in this engine.
 * FX12 = fixed-point with 12 fractional bits (>> 12 = "/4096"). */
typedef s16  bam16;       /* 16-bit binary angle */
typedef s32  fx12;        /* fixed-point .12 */
typedef u32  rgb555;      /* 16-bit RGB-555 packed */

/* Packed pointer convention: many scene-graph indices in the engine
 * are stored as (pointer / 4) to fit more bits — multiply by 4 to
 * recover the actual address. PSX/N64 idiom carried over. */
typedef u32  packed_ptr;

#define NULL_NODE  ((packed_ptr)0)

#endif /* MK4_TYPES_H */
