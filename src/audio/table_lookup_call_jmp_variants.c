/**
 * Auto-split from misc_matchesL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004aa990 (41b)
 *   mov     eax, [g_walkCallback]
 *   mov     ecx, [eax*4 + 0x004f3f40]
 *   sar     ecx, 2
 *   mov     [g_xformEntityIdx], ecx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void *g_table_004f3f40[];
extern void *g_table_004f3f90[];
extern void func_004073f0(void);
extern void func_004093f0(void);
void TableLookupCallJmp_004aa990(void) {
    g_xformEntityIdx = (unsigned int)((int)g_table_004f3f40[(unsigned int)g_walkCallback] >> 2);
    func_004073f0();
    if (g_framePauseFlag != 0) return;
    func_004093f0();
}

/* @addr 0x004aa9c0 (41b): same shape with table=0x004f3f90 */
extern void func_00407420(void);
extern void MStackPush2GatedTail_00409420(void);
void TableLookupCallJmp_004aa9c0(void) {
    g_xformEntityIdx = (unsigned int)((int)g_table_004f3f90[(unsigned int)g_walkCallback] >> 2);
    func_00407420();
    if (g_framePauseFlag != 0) return;
    MStackPush2GatedTail_00409420();
}
