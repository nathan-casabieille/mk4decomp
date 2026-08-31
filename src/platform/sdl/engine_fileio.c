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
#include "portable/mem_model.h"
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

/* MK4_TRACE_FILES=1 logs every archive lookup the engine makes, in order.
 * The loader opens assets by name out of records the .exe carries, so this
 * is how a wrong record shows itself: the name is empty or nonsense long
 * before anything else goes visibly wrong. */
void MK4_NativeTraceOpen(const char *path)
{
    static int on = -1;

    if (on < 0) on = SDL_getenv("MK4_TRACE_FILES") != NULL;
    if (on) SDL_Log("fsys open: '%s' (node=%x entity=%x)",
                    path ? path : "(null)",
                    *MK4_VA(unsigned int, 0x542044u),
                    *MK4_VA(unsigned int, 0x542048u));
}

/* ---------------------------------------------------------------------------
 * MK4_CRASH_TRACE=1: report a fault with the faulting address AND the
 * function it happened in, resolved through dladdr.
 *
 * The macOS crash reporter de-duplicates identical faults, so after the
 * first one a re-run with a fix applied still shows the OLD report - which
 * is a good way to waste an hour. It also symbolicates to the nearest
 * preceding exported symbol, so a fault inside a static or inlined helper
 * is attributed to whatever came before it. This prints what actually
 * faulted, every time.
 */
#include <signal.h>
#include <dlfcn.h>

static void mk4_fault(int sig, siginfo_t *si, void *uctx)
{
    Dl_info info;
    void *pc = NULL;
#if defined(__aarch64__)
    ucontext_t *uc = (ucontext_t *)uctx;
    if (uc && uc->uc_mcontext) pc = (void *)uc->uc_mcontext->__ss.__pc;
#endif
    SDL_Log("FAULT sig=%d at %p  pc=%p", sig, si ? si->si_addr : NULL, pc);
    if (pc && dladdr(pc, &info) && info.dli_sname)
        SDL_Log("  in %s + 0x%lx", info.dli_sname,
                (unsigned long)((char *)pc - (char *)info.dli_saddr));
    /* the stub histogram is the frontier work-list; a crash is exactly when
     * it is wanted, and _exit skips the atexit that would print it */
    { extern void MK4_StubTraceReportNow(void); MK4_StubTraceReportNow(); }
    _exit(139);
}

void MK4_NativeInstallFaultHandler(void)
{
    struct sigaction sa;

    if (!SDL_getenv("MK4_CRASH_TRACE")) return;
    SDL_memset(&sa, 0, sizeof sa);
    sa.sa_sigaction = mk4_fault;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);
    sigaction(SIGBUS, &sa, NULL);
}
