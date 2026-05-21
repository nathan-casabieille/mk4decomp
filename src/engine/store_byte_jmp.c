/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0042f840 (12b)
 *   mov     byte ptr [g_byte_00538148], 0
 *   jmp     T
 */
extern unsigned char g_byte_00538148;
extern void func_0041a608(void);
void StoreByteJmp_0042f840(void) {
    g_byte_00538148 = 0;
    func_0041a608();
}
