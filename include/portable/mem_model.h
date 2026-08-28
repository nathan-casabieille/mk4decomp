/**
 * Memory-model seam: packed-pointer node pool + absolute-VA globals.
 *
 * See tools/decomp/AGENT_PORTABLE_MIGRATION.md (Phase 1).
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
 * RELOCATED targets (ANY non-matching backend - native SDL, WASM, etc. -
 * since a normal toolchain will not place data at the original 0x4xxxxx /
 * 0x5xxxxx VAs): the node pool + data/rdata blobs are loaded into one
 * reserved arena and these macros add the base translation. This is the
 * memory model, NOT a platform choice - it is gated on `MK4_ARENA`
 * (orthogonal to whichever TARGET_* platform backend is linked).
 *
 *   ***  DECIDED (2026-06-11): see analysis/notes/native_memory_model.md  ***
 * Host MAP_FIXED at 0x400000 is impossible (macOS), so translation is
 * mandatory: arena at an arbitrary base, EVERY fixed-VA/packed-ptr/global
 * access through this seam. The node pool is a fixed-VA array (g_nodeSlotsArea
 * @0x53e368) already inside the arena, so MK4_NODE below is correct as-is.
 * Remaining: re-route raw idx*4 twins through MK4_NODE; make globals MK4_VA
 * macros (not C vars) for name/VA consistency; add a VA->native code-ptr
 * trampoline. Wiring requires:
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

#if defined(MK4_ARENA)

/* --- Relocated arena (any backend; inert until MK4_ARENA is set) --- */
extern unsigned char *g_mk4Arena;       /* base of the reserved data arena */
#define MK4_ORIG_IMAGE_BASE  0x00400000u

#if defined(MK4_ARENA_CHECK)
/* Diagnostic build: report the VA instead of dying somewhere unrecognisable.
 *
 * A VA below the image base wraps - `(unsigned)(0 - 0x400000)` is 0xffc00000 -
 * so a null packed pointer does not fault at address 0 the way it would in the
 * original, it faults about 4 GB above the arena with nothing to say for
 * itself. Twice now that has cost a debugging round. Under MK4_ARENA_CHECK
 * every deref is range-checked and the offending VA is printed with the call
 * site, which turns "EXC_BAD_ACCESS somewhere in a twin" into a line number.
 *
 * Off by default: the check costs a compare and a branch on every single
 * memory access the engine makes. */
void *MK4_PtrChecked(unsigned va, const char *file, int line);
#define MK4_PTR(va)  MK4_PtrChecked((unsigned)(va), __FILE__, __LINE__)
#else
/* The offset is SIGNED, and that is load-bearing rather than tidiness.
 *
 * A BASE-0 packed table is spelled MK4_VA(T, 0) and indexed by the VA itself -
 * g_siblingTable[idx] with idx = VA/4 - so the base is deliberately below the
 * image and the index adds the VA back. Computed unsigned, `0 - 0x400000` is
 * 0xffc00000, and adding THAT to a 64-bit pointer does not wrap back: the
 * access lands 4 GB high and dies. Signed, the base is arena - 4 MB and the
 * index brings it home. In-range VAs are unaffected either way. */
#define MK4_PTR(va) \
    ((void *)(g_mk4Arena + ((long)(unsigned)(va) - (long)MK4_ORIG_IMAGE_BASE)))
#endif
#define MK4_NODE(T, idx)     ((T *)MK4_PTR((unsigned)(idx) * 4u))
#define MK4_VA(T, va)        ((T *)MK4_PTR((unsigned)(va)))
/* Inverse of MK4_PTR: a host pointer INTO the arena -> the original 32-bit VA
 * it stands for. Needed where the engine stores a pointer it later re-reads as
 * a VA-sized slot (e.g. FlushDrawQueue's sorted[] record table). On a 64-bit
 * host the raw pointer would truncate; this keeps the stored value a real VA. */
#define MK4_UNPTR(p) \
    ((unsigned)((unsigned char *)(p) - g_mk4Arena) + MK4_ORIG_IMAGE_BASE)

#else

/* --- Identity (matching + flat 32-bit): exactly the inline form --- */
/* MK4_PTR is the VA-deref seam. Under a flat 32-bit layout (the matching
 * build, and the co-exec verifier's unicorn arena mapped at real VAs) a VA IS
 * the address, so this is the identity - the twins' bytes are unchanged and
 * the 100+ existing verifications are untouched. Under MK4_ARENA (above) it
 * adds the base translation, which is what lets the SAME verified twin source
 * run on a 64-bit host. */
#define MK4_PTR(va)          ((void *)(unsigned long)(va))
#define MK4_UNPTR(p)         ((unsigned)(unsigned long)(p))
#define MK4_NODE(T, idx)     ((T *)((idx) * 4))
#define MK4_VA(T, va)        ((T *)(va))

#endif

/* --- arena-resident scratch stack (packed pointers to LOCALS) ---------------
 *
 * Five functions hand a pointer to one of their own STACK locals to the engine
 * as a packed pointer - `lea eax, [esp]; sar eax, 2` - and the callee then
 * reads it back through the packed-ptr seam (NodeApplyTransform_B_Swapped,
 * RenderSceneNode, RegionFlushChain, MStackBracket7_DispatchAndChain,
 * PushStackAllocCall).
 *
 * A C local CANNOT carry that round trip on a 64-bit host. MK4_UNPTR narrows
 * (pointer - arena) to 32 bits, and measured on macOS arm64 the stack sits
 * about 46 GB from a malloc'd arena - and on the far side of it, so the
 * difference is both negative and far past 32 bits. MK4_PTR(MK4_UNPTR(local))
 * does not come back to `local`, and the callee reads somewhere else entirely.
 *
 * So the scratch has to live INSIDE the arena. This is a bump stack at a fixed
 * VA above the reserved video regions: push on entry, pop on every exit. It is
 * macro-only on purpose - a twin compiled by the co-exec harness may not call
 * an external helper (no original VA to relocate to) nor name a new `g_`
 * global (no entry in extras_map). MK4_SCRATCH_TOP self-initialises because
 * the at-rest arena the verifier loads has a zero there.
 *
 * Discipline: every MK4_ALLOCA needs a matching MK4_ALLOCA_FREE on EVERY path
 * out, early returns included - the originals pop their stack unconditionally.
 */
#define MK4_SCRATCH_TOP_VA  0x01600000u
#define MK4_SCRATCH_BASE    0x01600010u
#define MK4_SCRATCH_END     0x01610000u
#define MK4_SCRATCH_SIZE    (MK4_SCRATCH_END - MK4_SCRATCH_TOP_VA)

#define MK4_SCRATCH_TOP     (*(unsigned int *)MK4_VA(unsigned int, MK4_SCRATCH_TOP_VA))
#define MK4_SCRATCH_ROUND(n) (((unsigned)(n) + 3u) & ~3u)

#define MK4_ALLOCA(n) \
    (MK4_SCRATCH_TOP = (MK4_SCRATCH_TOP < MK4_SCRATCH_BASE \
                        ? MK4_SCRATCH_BASE : MK4_SCRATCH_TOP) \
                       + MK4_SCRATCH_ROUND(n), \
     MK4_PTR(MK4_SCRATCH_TOP - MK4_SCRATCH_ROUND(n)))

#define MK4_ALLOCA_FREE(n)  (MK4_SCRATCH_TOP -= MK4_SCRATCH_ROUND(n))

/* Typed access to a node field at byte offset `off` from the packed index
 * `idx` - i.e. the original `[idx*4 + off]` form. Used by the asm->C
 * lifter (tools/decomp/lift_asm.py) so converted twins read/write node
 * fields through the seam instead of raw pointer arithmetic. */
#define MK4_NODE_AT(T, idx, off) \
    (*(T *)((unsigned char *)MK4_NODE(unsigned char, (idx)) + (off)))

/* The Win32 alt-tab courtesy check at the head of Input_PollPlayerKeyboard.
 * The original asks the GetAsyncKeyState import whether Alt is held and
 * skips the whole poll while it is, so a window switch does not land as a
 * fistful of inputs. Under the arena the import slot holds no callable
 * target and SDL owns window focus, so it reports "not held"; everywhere
 * else (matching, and the co-exec harness at identity) it is the original
 * call. It lives here rather than in the twin because a #ifdef inside a
 * twin body ends the co-exec extractor's block scan early. */
#ifdef MK4_ARENA
#define MK4_ALT_KEY_DOWN()   0
#else
#define MK4_ALT_KEY_DOWN()                                              \
    (((int (__stdcall *)(int))                                          \
      MK4_ResolveCode(*MK4_VA(unsigned int, 0x4d21c0u)))(0x12))
#endif

/* Indirect-call seam: a stored function pointer holds an ORIGINAL code VA.
 * Under the relocated native build it must be mapped to the native function;
 * everywhere else (matching, verifier identity, flat 32-bit) it is the VA
 * itself. Twins wrap indirect calls as ((fn)MK4_ResolveCode(target))(args) so
 * the same source is verify-correct (identity) and native-correct (trampoline).
 * The real table is src/platform/sdl/native_codeptr_table.c (MK4_NATIVE_FULL). */
#if defined(MK4_NATIVE_FULL)
extern void *MK4_ResolveCode(unsigned va);
#else
#define MK4_ResolveCode(va) ((void *)(unsigned long)(va))
#endif

#endif /* MK4_PORTABLE_MEM_MODEL_H */
