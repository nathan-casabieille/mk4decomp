/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern void *CrtInitPerThreadData_004c9df0(void);

/* @addr 0x004c8ba0 (9b) */
void *Crt_errno_004c8ba0(void) {
    return (char *)CrtInitPerThreadData_004c9df0() + 8;
}
