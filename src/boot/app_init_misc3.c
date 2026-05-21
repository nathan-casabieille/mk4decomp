/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b2ac0 (17b): zero a buffer using rep stosd
 *   push    edi
 *   mov     ecx, 0x2a
 *   xor     eax, eax
 *   mov     edi, 0x007af958
 *   rep     stosd
 *   pop     edi
 *   ret
 */
extern unsigned int g_data_007af958[];
extern void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
void AppInit_Misc3(void) {
    memset(g_data_007af958, 0, 0x2a * 4);
}

