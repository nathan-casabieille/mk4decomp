/* MK4_TRACE_STUBS - which weak no-op stubs the running game actually calls.
 *
 * The codeptr trace (MK4_TRACE_CODE) only sees calls that go through
 * MK4_ResolveCode. A converted function calling a hollow one directly in C
 * never appears there, so a stub can be hit thousands of times a frame and
 * stay invisible. That blind spot is why the fight's "29 dispatched VAs, all
 * REAL" reading looked like full coverage while the scene-construction path
 * was quietly returning 0 everywhere.
 *
 * Every function stub in engine_autostubs.c calls MK4_StubHit with its own
 * name (applied by tools/decomp/stamp_stub_trace.py, which is idempotent and
 * must be re-run if that generated file is ever rebuilt). Counting is off
 * unless MK4_TRACE_STUBS is set, so the cost in a normal run is one load and
 * a predictable branch.
 *
 * The report is ordered by call count: the top of that list is the work-list,
 * because those are hollow functions on the live path.
 */
#ifdef MK4_NATIVE_FULL

#include <stdlib.h>
#include <string.h>

extern void SDL_Log(const char *, ...);

#define MK4_STUBTRACE_MAX 512

static const char *g_stubNames[MK4_STUBTRACE_MAX];
static unsigned int g_stubHits[MK4_STUBTRACE_MAX];
static int g_stubCount;
static int g_stubEnabled = -1;
static int g_stubRegistered;

static void MK4_StubTraceReport(void)
{
    int i, j, best;
    unsigned int total = 0;

    if (g_stubCount <= 0)
        return;
    for (i = 0; i < g_stubCount; i++)
        total += g_stubHits[i];

    SDL_Log("stub-trace: %d distinct hollow functions called, %u calls total",
            g_stubCount, total);

    /* selection sort by count - at most a few hundred entries, once */
    for (i = 0; i < g_stubCount; i++) {
        best = i;
        for (j = i + 1; j < g_stubCount; j++)
            if (g_stubHits[j] > g_stubHits[best])
                best = j;
        if (best != i) {
            unsigned int c = g_stubHits[i];  const char *n = g_stubNames[i];
            g_stubHits[i] = g_stubHits[best]; g_stubNames[i] = g_stubNames[best];
            g_stubHits[best] = c;             g_stubNames[best] = n;
        }
        SDL_Log("STUBHIT %8u  %s", g_stubHits[i], g_stubNames[i]);
    }
}

/* the crash handler's copy of the atexit report - safe enough for a
 * SIGSEGV path: reads static arrays and calls SDL_Log, same as the
 * handler already does */
void MK4_StubTraceReportNow(void)
{
    MK4_StubTraceReport();
}

void MK4_StubHit(const char *name)
{
    int i;

    if (g_stubEnabled < 0)
        g_stubEnabled = getenv("MK4_TRACE_STUBS") != 0;
    if (!g_stubEnabled)
        return;
    if (!g_stubRegistered) {
        g_stubRegistered = 1;
        atexit(MK4_StubTraceReport);
    }

    /* The stubs pass string literals, so the pointer alone identifies the
     * name in the common case; strcmp only covers a compiler that chose not
     * to merge duplicate literals. */
    for (i = 0; i < g_stubCount; i++)
        if (g_stubNames[i] == name || strcmp(g_stubNames[i], name) == 0) {
            g_stubHits[i]++;
            return;
        }
    if (g_stubCount < MK4_STUBTRACE_MAX) {
        g_stubNames[g_stubCount] = name;
        g_stubHits[g_stubCount] = 1;
        g_stubCount++;
    }
}

#endif /* MK4_NATIVE_FULL */
