/**
 * Arena loader for the relocated memory model (portable / WASM).
 *
 * `g_mk4Arena` is the base of a single reserved linear region holding the
 * original mapped PE image, so that
 *     g_mk4Arena[ va - MK4_ORIG_IMAGE_BASE ]
 * is the byte the original process saw at `va`. The packed-ptr / absolute
 * accessors in include/portable/mem_model.h index through it.
 *
 * Build the blob with tools/decomp/extract_arena.py (-> build/arena.bin),
 * then load it once at startup (native: from file; WASM: from a preloaded
 * asset buffer).
 */
#ifndef MK4_PORTABLE_ARENA_H
#define MK4_PORTABLE_ARENA_H

extern unsigned char *g_mk4Arena;      /* base of the reserved arena */
extern unsigned int   g_mk4ArenaSize;  /* bytes; 0 until initialized  */

/* Copy `size` bytes of image blob into a freshly reserved arena.
 * Returns 1 on success, 0 on allocation/size failure. */
int MK4_ArenaInitFromMemory(const void *image, unsigned size);

/* Convenience native loader: read the whole file into the arena.
 * Returns 1 on success, 0 on any I/O failure. */
int MK4_ArenaInitFromFile(const char *path);

#endif /* MK4_PORTABLE_ARENA_H */
