/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00493ed0 (29b)
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, 0x004f1e20
 *   sar     eax, 2
 *   cmp     eax, ecx
 *   mov     [g_bootInitSaveSlot_00541dc4], eax
 *   jne     +4
 *   jmp     +4
 *   ret
 */
extern unsigned int g_bootInitSaveSlot_00541dc4;
extern void func_00493edd(void);
extern unsigned int g_table_004f1e20;
void LoadCmpAddrJmp_00493ed0(void) {
    unsigned int packed = (unsigned int)((int)&g_table_004f1e20 >> 2);
    g_bootInitSaveSlot_00541dc4 = packed;
    if ((unsigned int)g_walkCallback == packed) {
        func_00493edd();
    }
}
