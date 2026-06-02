/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0043d580 (14b)
 *   push    0x004e5120
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int ArgSarStoreJmp(void *);
extern void *g_dispatchSave1249;
extern void CountdownStoreCallChain(void);
void PushCallRetNopJmp(void) {
    ArgSarStoreJmp(&g_dispatchSave1249);
}
