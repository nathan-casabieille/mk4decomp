/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041f810 (28b)
 *   mov     eax, [g_pendingNodeType]
 *   shl     eax, 2
 *   mov     ecx, [eax + 0xd8]
 *   test    ecx, ecx
 *   je      .ret
 *   push    eax
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern void func_0041f700(unsigned int);
void LoadShlDerefCallSkip_0041f810(void) {
    unsigned int p = g_pendingNodeType * 4;
    if (*(unsigned int*)(p + 0xd8)) {
        func_0041f700(p);
    }
}
