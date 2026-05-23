/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

extern void *PendingMatch_004c9df0(void);

void Crt_srand(int x) {
    *(int *)((unsigned char *)PendingMatch_004c9df0() + 0x14) = x;
}

