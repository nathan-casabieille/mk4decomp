/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0043d580 (14b)
 *   push    0x004e5120
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int func_00459500(void *);
extern void *g_data_004e5120;
extern void func_0043d590(void);
void PushCallRetNopJmp_0043d580(void) {
    func_00459500(&g_data_004e5120);
}
