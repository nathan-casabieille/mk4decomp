/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1ce0 (14b)
 *   movsx   eax, byte ptr [0x004d50c0]
 *   and     eax, 4
 *   shr     eax, 2
 *   ret
 */
extern char g_byte_004d50c0;
void MovsxAnd4Shr_004a1ce0(void) {
    __asm {
        movsx   eax, byte ptr [g_byte_004d50c0]
        and     eax, 4
        shr     eax, 2
        }
}
