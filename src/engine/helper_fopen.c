/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004c5db0 (21b)
 *   mov     eax, [esp+8]
 *   mov     ecx, [esp+4]
 *   push    0x40
 *   push    eax
 *   push    ecx
 *   call    F
 *   add     esp, 0xc
 *   ret
 */
extern int __cdecl func_004c5d68(int, int, int);
int Helper_FOpen(int a, int b) {
    return func_004c5d68(a, b, 0x40);
}

