/**
 * FSYS - asset archive subsystem.
 *
 * The game's bulk assets live in a single archive file (filesys.dat)
 * indexed by hashed filename. This header exposes the public API:
 * Init, Open, Read, Close, etc.
 *
 * On-disk layout (see analysis/notes/architecture.md):
 *   - 12 KB header: array of (hash, offset, size) triples
 *   - Payload data referenced by header offsets
 *
 * Filenames are hashed via FSYS_HashName after path normalization.
 */
#ifndef MK4_ENGINE_FSYS_H
#define MK4_ENGINE_FSYS_H

#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Maximum normalized path length (including drive + null). */
#define FSYS_PATH_MAX  1024

/* Size of the on-disk header (in bytes). 12 KB = up to 1024 entries
 * × 12 bytes each, terminated by a zero entry. */
#define FSYS_HEADER_SIZE  0x3000

/* Per-entry layout in the header table. */
typedef struct fsys_entry {
    u32 hash;
    u32 offset;
    u32 size;
} fsys_entry;

/* === Internal state ============================================ */

/* Open-file table indexed by file handle. -1 means slot is free.
 * 0x401 entries (handles 0..0x400 inclusive). Lives at 0x7ae0dc. */
extern int g_fsys_files[];

/* Static scratch buffer used by FSYS_NormalizePath to return the
 * uppercased + drive-prefixed result. Lives at 0x7af0e0. */
extern char g_fsys_normalized_path[FSYS_PATH_MAX];

/* In-memory copy of the FILESYS.DAT header table (1024 entries
 * x 12 bytes = 0x3000 bytes). Sorted by hash. Lives at 0x7ab0d8. */
extern fsys_entry g_fsys_entries[1024];

/* Number of populated entries in g_fsys_entries (set by FSYS_Init).
 * Lives at 0x7af4e4. */
extern int g_fsys_entry_count;

/* === Public API ============================================== */

/* Open the archive and load its header table. */
void FSYS_Init(void);                                    /* 0x004b1cf0 */

/* Open one asset by its full path (e.g. "c:\\source\\mk4\\...").
 * Mode follows fopen() conventions; the engine only ever uses "rb". */
int  FSYS_fopen(const char *path, const char *mode);     /* 0x004b1e00 */

/* Sequential I/O on an open asset. */
int  FSYS_fread(void *buf, u32 size, u32 count, int fh); /* 0x004b1fb0 */
int  FSYS_fseek(int fh, u32 off, int whence);            /* 0x004b2070 */
int  FSYS_ftell(int fh);                                 /* 0x004b2100 */
int  FSYS_fclose(int fh);                                /* 0x004b1f90 */

/* Convenience: open + read entire file + close. Reports
 * "FSYS_fload()" on read mismatch but does not return a status. */
void FSYS_fload(const char *path, void *buf, u32 size);  /* 0x004b2160 */

/* Query: file size by name. */
u32  FSYS_fsize(const char *path);                       /* 0x004b2120 */

/* === Internal helpers ========================================== */

/* Uppercases the path in place (writes to a static buffer). */
char *FSYS_NormalizePath(const char *path);              /* 0x004b1ec0 */

/* Computes the byte-position-shifted XOR hash of a normalized path. */
u32   FSYS_HashName(const char *normalized_path);        /* 0x004b1f50 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_FSYS_H */
