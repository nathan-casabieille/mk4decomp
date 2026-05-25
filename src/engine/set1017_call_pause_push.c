/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0047e600 (51b)
 *   mov     ecx, [g_baseSel_00542060]
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
extern void func_004fa320(void);
extern int func_0046d4d8(void *p);
extern void *g_dispatchSave1306_004ed5e0;
void Set1017CallPausePush_0047e600(void) {
    g_walkCallback = (void (*)(void))0x1017;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x74) = 0x1017;
    func_004fa320();
    if (g_framePauseFlag != 0) return;
    func_0046d4d8(&g_dispatchSave1306_004ed5e0);
}
