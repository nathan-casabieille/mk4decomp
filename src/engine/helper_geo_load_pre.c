/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#endif


/* @addr 0x004bd570 (21b)
 *   push    4
 *   call    F1
 *   add     esp, 4
 *   push    2
 *   call    F1
 *   add     esp, 4
 *   ret
 */
extern int __cdecl PackedListVisitor(int);
void Helper_GeoLoadPre(void) {
    PackedListVisitor(4);
    PackedListVisitor(2);
}

