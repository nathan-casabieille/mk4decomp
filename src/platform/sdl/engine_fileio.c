/**
 * Host stdio behind the engine's CRT file helpers (TARGET=sdl).
 *
 * FSYS_fopen / FSYS_fread / FSYS_fseek reach the disk through four MSVC CRT
 * wrappers - Helper_FOpen, Helper_FRead, Helper_FSeek, Helper_FClose - each of
 * which is a locking shim around _fopen_nolock and friends. Those are C
 * runtime internals, not engine code, so the port REPLACES them rather than
 * converting them, the same way SDL replaces DirectDraw.
 *
 * The one thing that cannot be a straight passthrough is the handle. The
 * engine keeps the archive handle in a 32-bit slot (g_fsys_archive at
 * 0x007af4e0), and a host FILE * does not fit in 32 bits, so handles are
 * indices into a small table here. Index 0 is never handed out - the engine
 * treats a zero handle as failure.
 *
 * Paths: the game asks for "filesys.dat" relative to the working directory it
 * had in 1998. MK4_GAME_DIR overrides where that is; it defaults to "game",
 * which is where this repo keeps the disc contents. The lookup also retries
 * the upper- and lower-case spellings, since the original ran on a
 * case-insensitive filesystem and the shipped names are not consistent.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <SDL2/SDL.h>

#define MK4_MAX_FILES 16

static FILE *g_files[MK4_MAX_FILES];

static const char *game_dir(void)
{
    const char *d = getenv("MK4_GAME_DIR");
    return (d && *d) ? d : "game";
}

/* "C:\SOURCE\MK4\...\FOO.GEO" or "filesys.dat" -> the basename the port can
 * actually find. The engine's own paths are DOS absolutes baked in at build
 * time in 1998; only the last component means anything here. */
static const char *basename_of(const char *path)
{
    const char *p, *last = path;

    for (p = path; *p; p++)
        if (*p == '\\' || *p == '/' || *p == ':')
            last = p + 1;
    return last;
}

static FILE *open_case_insensitive(const char *name, const char *mode)
{
    char buf[512];
    FILE *f;
    size_t i, n;

    if (snprintf(buf, sizeof buf, "%s/%s", game_dir(), name) >= (int)sizeof buf)
        return NULL;
    if ((f = fopen(buf, mode)) != NULL)
        return f;

    n = strlen(buf);
    for (i = strlen(game_dir()) + 1; i < n; i++)
        buf[i] = (char)toupper((unsigned char)buf[i]);
    if ((f = fopen(buf, mode)) != NULL)
        return f;

    for (i = strlen(game_dir()) + 1; i < n; i++)
        buf[i] = (char)tolower((unsigned char)buf[i]);
    return fopen(buf, mode);
}

__attribute__((weak)) int Helper_FOpen(const char *path, const char *mode)
{
    FILE *f;
    int i;

    if (path == NULL)
        return 0;
    f = open_case_insensitive(basename_of(path), (mode && *mode) ? mode : "rb");
    if (f == NULL) {
        SDL_Log("Helper_FOpen: cannot open '%s' under %s", path, game_dir());
        return 0;
    }
    for (i = 1; i < MK4_MAX_FILES; i++) {
        if (g_files[i] == NULL) {
            g_files[i] = f;
            return i;
        }
    }
    SDL_Log("Helper_FOpen: handle table full");
    fclose(f);
    return 0;
}

__attribute__((weak)) int Helper_FRead(void *buf, unsigned int size,
                                       unsigned int count, int fh)
{
    if (fh <= 0 || fh >= MK4_MAX_FILES || g_files[fh] == NULL || size == 0)
        return 0;
    return (int)fread(buf, size, count, g_files[fh]);
}

__attribute__((weak)) int Helper_FSeek(int fh, int offset, int whence)
{
    if (fh <= 0 || fh >= MK4_MAX_FILES || g_files[fh] == NULL)
        return -1;
    return fseek(g_files[fh], (long)offset, whence);
}

__attribute__((weak)) void Helper_FClose(int fh)
{
    if (fh > 0 && fh < MK4_MAX_FILES && g_files[fh] != NULL) {
        fclose(g_files[fh]);
        g_files[fh] = NULL;
    }
}
