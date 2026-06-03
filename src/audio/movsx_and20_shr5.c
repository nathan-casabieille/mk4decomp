/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004a1cf0 (14b)
 *   movsx   eax, byte ptr [0x004d50c0]
 *   and     eax, 0x20
 *   shr     eax, 5
 *   ret
 *
 * MSVC SP3 rewrites `((char)g_byte & 4) >> 2` as `(g_byte >> 2) & 1`,
 * picking `mov al, m8` + `sar eax, 2` + `and eax, 1` (12b) instead of
 * `movsx eax, m8` + `and eax, 4` + `shr eax, 2` (13b). Different
 * bytes, different upper-eax semantics - left as naked.
 */
extern unsigned int g_byte_004d50c0;

void MovsxAnd20Shr5(void) {
    __asm {
        movsx   eax, byte ptr [g_byte_004d50c0]
        and     eax, 0x20
        shr     eax, 5
        }
}

