/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern void *CrtInitPerThreadData(void);

/* @addr 0x004c8bb0 (9b) */
void *Crt_doserrno(void) {
    return (char *)CrtInitPerThreadData() + 0xc;
}
