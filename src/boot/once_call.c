/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00401340 (39b)
 *   mov     al, byte ptr [g_bootOnceCallByte]
 *   test    al, al
 *   jne     .skip
 *   push    0
 *   push    0
 *   push    0x004d5084
 *   mov     byte ptr [g_bootOnceCallByte], 1
 *   call    F
 *   add     esp, 0xc
 *   jmp     +0x0a
 * .skip:
 *   ret
 */
extern unsigned char g_bootOnceCallByte;
extern void *g_dispatchSave1161;
extern int Anim_LoadPackFile(void *p, int a, int b);
extern void Init0AndMax(void);
void OnceCall(void) {
    if (g_bootOnceCallByte != 0) {
        return;
    }
    g_bootOnceCallByte = 1;
    Anim_LoadPackFile(&g_dispatchSave1161, 0, 0);
    Init0AndMax();
}
