/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c45d0 (35b): similar pattern with different params
 *   push    esi
 *   mov     esi, [iat]
 *   push    edi
 *   push    0x2e
 *   call    esi
 *   push    8
 *   mov     edi, eax
 *   call    esi
 *   push    4
 *   add     edi, eax
 *   call    esi
 *   lea     eax, [edi + eax*2]
 *   pop     edi
 *   mov     [0x00f9f7bc], eax
 *   pop     esi
 *   ret
 */
extern unsigned int g_state_00f9f7bc;
extern unsigned int g_iat_004d21b0;

void CallThreeSumLea_004c45d0(void) {
    typedef unsigned int (__stdcall *fn_t)(unsigned int);
    fn_t fn = (fn_t)g_iat_004d21b0;
    unsigned int s;
    unsigned int c;
    s = fn(0x2e);
    s += fn(8);
    c = fn(4);
    g_state_00f9f7bc = c + s * 2;
}
