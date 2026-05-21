/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00489f60 (33b)
 *   mov     eax, [g_walkCallback]
 *   cmp     eax, 0x32
 *   ja      .skip
 *   mov     ax, word ptr [eax*2 + 0x004ef998]
 *   test    ax, ax
 *   je      .skip
 *   push    eax
 *   call    F
 *   add     esp, 4
 * .skip:
 *   ret
 */
extern unsigned short g_table_004ef998[];
extern int TaggedSceneDispatch_004be690(int);
void TableLookupCall_00489f60(void) {
    unsigned int idx = (unsigned int)g_walkCallback;
    unsigned short val;
    if (idx > 0x32) return;
    val = g_table_004ef998[idx];
    if (val == 0) return;
    ((int (*)(unsigned short))TaggedSceneDispatch_004be690)(val);
}

/* @addr 0x00489ff0 (33b): same shape with cmp=0x70, table=0x004efa00 */
extern unsigned short g_table_004efa00[];
void TableLookupCall_00489ff0(void) {
    unsigned int idx = (unsigned int)g_walkCallback;
    unsigned short val;
    if (idx > 0x70) return;
    val = g_table_004efa00[idx];
    if (val == 0) return;
    ((int (*)(unsigned short))TaggedSceneDispatch_004be690)(val);
}

/* @addr 0x0048a130 (33b): same shape with cmp=0x41, table=0x004efd18 */
extern unsigned short g_table_004efd18[];
void TableLookupCall_0048a130(void) {
    unsigned int idx = (unsigned int)g_walkCallback;
    unsigned short val;
    if (idx > 0x41) return;
    val = g_table_004efd18[idx];
    if (val == 0) return;
    ((int (*)(unsigned short))TaggedSceneDispatch_004be690)(val);
}

/* @addr 0x0048a160 (33b): same shape with cmp=0x13, table=0x004efae0 */
extern unsigned short g_table_004efae0[];
void TableLookupCall_0048a160(void) {
    unsigned int idx = (unsigned int)g_walkCallback;
    unsigned short val;
    if (idx > 0x13) return;
    val = g_table_004efae0[idx];
    if (val == 0) return;
    ((int (*)(unsigned short))TaggedSceneDispatch_004be690)(val);
}
