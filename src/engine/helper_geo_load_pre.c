/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004bd570 (21b)
 *   push    4
 *   call    F1
 *   add     esp, 4
 *   push    2
 *   call    F1
 *   add     esp, 4
 *   ret
 */
extern int __cdecl PackedListVisitor_004b5c90(int);
void Helper_GeoLoadPre(void) {
    PackedListVisitor_004b5c90(4);
    PackedListVisitor_004b5c90(2);
}

