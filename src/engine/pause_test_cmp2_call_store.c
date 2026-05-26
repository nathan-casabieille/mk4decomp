/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0045bfe0 (60b)
 *   mov     ecx, [g_framePauseFlag]
 *   xor     eax, eax
 *   mov     al, byte ptr [g_dispatchSave403_00542071]
 *   test    ecx, ecx
 *   mov     [g_walkCallback], eax
 *   jne     +0x25
 *   cmp     eax, 2
 *   jne     +0x20
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x12
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [g_walkCallback]
 *   mov     [ecx*4 + 0x24], eax
 *   ret
 */
extern unsigned char g_byte_00542071;
extern void func_0045c005(void);
void PauseTestCmp2CallStore_0045bfe0(void) {
    unsigned int pause;
    unsigned int b;
    pause = g_framePauseFlag;
    b = (unsigned int)g_byte_00542071;
    g_walkCallback = (void (*)(void))b;
    if (pause != 0) return;
    if (b != 2) return;
    func_0045c005();
    if (g_framePauseFlag != 0) return;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_walkCallback;
}
