/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a56a0 (25b)
 *   mov     ecx, [g_count]
 *   test    ecx, ecx
 *   jle     .ret
 *   mov     eax, OFFSET g_target
 * .loop:
 *   mov     [eax], 1
 *   add     eax, 0x18
 *   dec     ecx
 *   jne     .loop
 * .ret:
 *   ret
 */
extern unsigned int g_count;
extern unsigned char g_target_005435a2;
void Memset18Step(void) {
    int n = (int)g_count;
    unsigned char *p;
    if (n <= 0) return;
    p = &g_target_005435a2;
    do {
        *p = 1;
        p += 0x18;
    } while (--n);
}
