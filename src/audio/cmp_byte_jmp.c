/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a4180 (19b)
 *   cmp     byte ptr [0x00543590], 1
 *   jne     +5
 *   jmp     T1
 *   jmp     T2
 */
extern unsigned char g_byte_00543590;
extern void Helper_AudioStub_4160(void);
extern void Helper_AudioStub_4140(void);
void CmpByteJmp_004a4180(void) {
    if (g_byte_00543590 == 1) {
        Helper_AudioStub_4160();
        return;
    }
    Helper_AudioStub_4140();
}
