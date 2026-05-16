/**
 * 2 "dirty-guard literal-call or tail-jmp" helpers (28 bytes each).
 *
 * Pattern:
 *   cmp     [g_xformScratch2088], 1
 *   jne     .literal_path
 *   jmp     NextFunc                  ; equal: tail-jmp into follow-up
 * .literal_path:
 *   push    LITERAL
 *   call    Sink
 *   add     esp, 4
 *   ret
 *
 * Branches on a scratch flag: if it's exactly 1, defers to the
 * adjacent function; otherwise calls a sink with a per-helper data
 * pointer.
 */
#include "engine/scenegraph.h"

extern void *g_lit_004ed6d0;
extern void *g_lit_004f17a8;
extern void DualEntryInstallScaledChain_0047ef60(void);
extern void Alarm4EntryInstallCountdown_00496960(void);
extern int  ArgSarStoreJmp_004594f0(void *p);

/* @addr 0x0047ef40 */
void DirtyGuardLitOrJmp_0047ef40(void) {
    if (g_xformScratch2088 == 1) {
        DualEntryInstallScaledChain_0047ef60();
        return;
    }
    ArgSarStoreJmp_004594f0(&g_lit_004ed6d0);
}

/* @addr 0x00496940 */
void DirtyGuardLitOrJmp_00496940(void) {
    if (g_xformScratch2088 == 1) {
        Alarm4EntryInstallCountdown_00496960();
        return;
    }
    ArgSarStoreJmp_004594f0(&g_lit_004f17a8);
}
