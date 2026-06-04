/**
 * Memory-model seam: packed-pointer node pool + absolute-VA globals.
 *
 * See tools/decomp/AGENT_PORTABLE_WASM_MIGRATION.md (Phase 1).
 *
 * The original engine addresses everything by raw virtual address:
 *   - a node reference is a "packed pointer" = VA / 4, dereferenced as
 *     `(T *)(idx * 4)`.
 *   - globals live at fixed VAs (0x4xxxxx / 0x5xxxxx).
 *
 * MATCHING build, and any flat 32-bit target where data sits at its
 * original VA: these macros are the IDENTITY of what the code already
 * writes inline, so routing existing accesses through them changes no
 * bytes. This is the default branch.
 *
 * RELOCATED targets (WASM, whose linear memory starts at 0; or a native
 * build without a VA-pinning linker script): the node pool + data/rdata
 * blobs are loaded into one reserved arena and these macros add the base
 * translation.
 *
 *   ***  The relocated branch is the next open decision  ***
 * It is gated behind `MK4_ARENA` (defined once the arena loader exists)
 * so it stays inert until designed. Wiring it requires:
 *   1. reserving `g_mk4Arena` large enough to span the original data
 *      VAs touched (see config/extras_map.yaml for the address range);
 *   2. a loader that copies the initialized data/rdata bytes
 *      (src/data.c / src/data_section.c / src/rdata_section.c) into the
 *      arena at their (VA - MK4_ORIG_IMAGE_BASE) offsets;
 *   3. ensuring every packed-ptr round-trips through MK4_NODE so stored
 *      indices stay arena-consistent (do NOT mix raw `idx*4` with the
 *      translated form).
 */
#ifndef MK4_PORTABLE_MEM_MODEL_H
#define MK4_PORTABLE_MEM_MODEL_H

#if defined(MK4_ARENA) || defined(TARGET_WEB)

/* --- Relocated arena (Phase 1 target; inert until MK4_ARENA is set) --- */
extern unsigned char *g_mk4Arena;       /* base of the reserved data arena */
#define MK4_ORIG_IMAGE_BASE  0x00400000u
#define MK4_PTR(va) \
    ((void *)(g_mk4Arena + ((unsigned)(va) - MK4_ORIG_IMAGE_BASE)))
#define MK4_NODE(T, idx)     ((T *)MK4_PTR((unsigned)(idx) * 4u))
#define MK4_VA(T, va)        ((T *)MK4_PTR((unsigned)(va)))

#else

/* --- Identity (matching + flat 32-bit): exactly the inline form --- */
#define MK4_NODE(T, idx)     ((T *)((idx) * 4))
#define MK4_VA(T, va)        ((T *)(va))

#endif

#endif /* MK4_PORTABLE_MEM_MODEL_H */
