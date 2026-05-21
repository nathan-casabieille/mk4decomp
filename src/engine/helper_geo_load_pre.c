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
extern int __cdecl func_00444c98(int);
void Helper_GeoLoadPre(void) {
    func_00444c98(4);
    func_00444c98(2);
}

