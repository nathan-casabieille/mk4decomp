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
extern int ArgSarStoreJmp_004594f0(void *);
extern void *g_dispatchSave1249_004e5120;
extern void CountdownStoreCallChain_0043d5a0(void);
void PushCallRetNopJmp_0043d580(void) {
    ArgSarStoreJmp_004594f0(&g_dispatchSave1249_004e5120);
}
