/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern void *CrtInitPerThreadData(void);

/* @addr 0x004c8ba0 (9b) */
void *Crt_errno(void) {
    return (char *)CrtInitPerThreadData() + 8;
}
