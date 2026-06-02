/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0047e600 (51b)
 *   mov     ecx, [g_baseSel]
 *   mov     eax, 0x1017
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x74], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0d
 *   push    0x004ed5e0
 *   call    F2
 *   add     esp, 4
 *   ret
 */
extern void ScaledAndAldf(void);
extern int ArgSarStoreJmp(void *p);
extern void *g_dispatchSave1306_004ed5e0;
void Set1017CallPausePush(void) {
    g_walkCallback = (void (*)(void))0x1017;
    ((ScenegraphNode *)(g_baseSel * 4))->fsm_state = 0x1017;
    ScaledAndAldf();
    if (g_framePauseFlag != 0) return;
    ArgSarStoreJmp(&g_dispatchSave1306_004ed5e0);
}
