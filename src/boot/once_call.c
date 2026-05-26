/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00401340 (39b)
 *   mov     al, byte ptr [g_byte_0052435c]
 *   test    al, al
 *   jne     .skip
 *   push    0
 *   push    0
 *   push    0x004d5084
 *   mov     byte ptr [g_byte_0052435c], 1
 *   call    F
 *   add     esp, 0xc
 *   jmp     +0x0a
 * .skip:
 *   ret
 */
extern unsigned char g_byte_0052435c;
extern void *g_dispatchSave1161_004d5084;
extern int FileLoaderTwoStage_00401120(void *p, int a, int b);
extern void Init0AndMax_00401370(void);
void OnceCall_00401340(void) {
    if (g_byte_0052435c != 0) {
        return;
    }
    g_byte_0052435c = 1;
    FileLoaderTwoStage_00401120(&g_dispatchSave1161_004d5084, 0, 0);
    Init0AndMax_00401370();
}
