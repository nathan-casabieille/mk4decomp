/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern void *CrtInitPerThreadData_004c9df0(void);

/* @addr 0x004c8bb0 (9b) */
void *Crt_doserrno_004c8bb0(void) {
    return (char *)CrtInitPerThreadData_004c9df0() + 0xc;
}
