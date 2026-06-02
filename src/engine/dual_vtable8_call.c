/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/com.h"

/* @addr 0x004af650 (56b)
 *   if g_renderer2_r7_data != 0:
 *     load [eax]; call vtable[+8](eax); store ret to g_renderer2_present_rc;
 *   load g_renderer2_state7; clear g_renderer2_r7_data;
 *   if g_renderer2_state7 != 0: call vtable[+8](eax);
 *   clear g_renderer2_state7; ret.
 */
extern Mk4ComObj *g_renderer2_r7_data;
extern Mk4ComObj *g_renderer2_state7;
extern int g_renderer2_present_rc;
void DualVtable8Call(void) {
    Mk4ComObj *p1 = g_renderer2_r7_data;
    Mk4ComObj *p2;
    if (p1) {
        g_renderer2_present_rc = p1->vtbl->Release(p1);
    }
    p2 = g_renderer2_state7;
    g_renderer2_r7_data = 0;
    if (p2) {
        p2->vtbl->Release(p2);
    }
    g_renderer2_state7 = 0;
}
