/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b1de0 (29b)
 *   mov     eax, [g_fsys_archive]
 *   test    eax, eax
 *   je      .skip
 *   push    eax
 *   call    F
 *   add     esp, 4
 * .skip:
 *   mov     [g_fsys_archive], 0
 *   ret
 */
extern void * g_fsys_archive;
extern void Helper_FClose(void *p);
void TestCallZero_004b1de0(void) {
    void *v = (void *)g_fsys_archive;
    if (v != 0) {
        Helper_FClose(v);
    }
    g_fsys_archive = 0;
}
