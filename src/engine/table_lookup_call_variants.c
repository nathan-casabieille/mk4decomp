/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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
extern unsigned short g_eventTbl_50[];
extern int TaggedSceneDispatch(int);
void TableLookupCall_g_eventTbl_50(void) {
    unsigned int idx = (unsigned int)g_walkCallback;
    unsigned short val;
    if (idx > 0x32) return;
    val = g_eventTbl_50[idx];
    if (val == 0) return;
    ((int (*)(unsigned short))TaggedSceneDispatch)(val);
}

/* @addr 0x00489ff0 (33b): same shape with cmp=0x70, table=0x004efa00 */
extern unsigned short g_eventTbl_112[];
void TableLookupCall_g_eventTbl_112(void) {
    unsigned int idx = (unsigned int)g_walkCallback;
    unsigned short val;
    if (idx > 0x70) return;
    val = g_eventTbl_112[idx];
    if (val == 0) return;
    ((int (*)(unsigned short))TaggedSceneDispatch)(val);
}

/* @addr 0x0048a130 (33b): same shape with cmp=0x41, table=0x004efd18 */
extern unsigned short g_eventTbl_65[];
void TableLookupCall_g_eventTbl_65(void) {
    unsigned int idx = (unsigned int)g_walkCallback;
    unsigned short val;
    if (idx > 0x41) return;
    val = g_eventTbl_65[idx];
    if (val == 0) return;
    ((int (*)(unsigned short))TaggedSceneDispatch)(val);
}

/* @addr 0x0048a160 (33b): same shape with cmp=0x13, table=0x004efae0 */
extern unsigned short g_eventTbl_19[];
void TableLookupCall_g_eventTbl_19(void) {
    unsigned int idx = (unsigned int)g_walkCallback;
    unsigned short val;
    if (idx > 0x13) return;
    val = g_eventTbl_19[idx];
    if (val == 0) return;
    ((int (*)(unsigned short))TaggedSceneDispatch)(val);
}
