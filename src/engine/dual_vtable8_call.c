/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/com.h"

/* @addr 0x004af650 (56b)
 *   if g_renderer2_r7_data_0058c7d4 != 0:
 *     load [eax]; call vtable[+8](eax); store ret to g_renderer2_present_rc;
 *   load g_renderer2_state7_0058c7c4; clear g_renderer2_r7_data_0058c7d4;
 *   if g_renderer2_state7_0058c7c4 != 0: call vtable[+8](eax);
 *   clear g_renderer2_state7_0058c7c4; ret.
 */
extern Mk4ComObj *g_renderer2_r7_data_0058c7d4;
extern Mk4ComObj *g_renderer2_state7_0058c7c4;
extern int g_renderer2_present_rc;
void DualVtable8Call_004af650(void) {
    Mk4ComObj *p1 = g_renderer2_r7_data_0058c7d4;
    Mk4ComObj *p2;
    if (p1) {
        g_renderer2_present_rc = p1->vtbl->Release(p1);
    }
    p2 = g_renderer2_state7_0058c7c4;
    g_renderer2_r7_data_0058c7d4 = 0;
    if (p2) {
        p2->vtbl->Release(p2);
    }
    g_renderer2_state7_0058c7c4 = 0;
}
