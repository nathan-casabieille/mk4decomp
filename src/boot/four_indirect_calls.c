/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c6f20 (43b): four indirect calls
 *   mov     eax, [g_iat_005200b4]
 *   push    esi
 *   mov     esi, [iat]
 *   push    eax
 *   call    esi
 *   mov     ecx, [g_iat_005200a4]
 *   push    ecx
 *   call    esi
 *   mov     edx, [g_iat_00520094]
 *   push    edx
 *   call    esi
 *   mov     eax, [g_iat_00520074]
 *   push    eax
 *   call    esi
 *   pop     esi
 *   ret
 */
extern void *g_iat_005200b4;
extern void *g_iat_005200a4;
extern void *g_iat_00520094;
extern void *g_iat_00520074;
extern void (__stdcall *g_iat_004d215c)(void *);
void FourIndirectCalls_004c6f20(void) {
    void (__stdcall *f)(void *) = g_iat_004d215c;
    f(g_iat_005200b4);
    f(g_iat_005200a4);
    f(g_iat_00520094);
    f(g_iat_00520074);
}
