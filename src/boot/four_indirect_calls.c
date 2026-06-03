/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004c6f20 (43b): four indirect calls
 *   mov     eax, [g_fnptr_005200b4]
 *   push    esi
 *   mov     esi, [iat]
 *   push    eax
 *   call    esi
 *   mov     ecx, [g_fnptr_005200a4]
 *   push    ecx
 *   call    esi
 *   mov     edx, [g_fnptr_00520094]
 *   push    edx
 *   call    esi
 *   mov     eax, [g_fnptr_00520074]
 *   push    eax
 *   call    esi
 *   pop     esi
 *   ret
 */
extern void *g_fnptr_005200b4;
extern void *g_fnptr_005200a4;
extern void *g_fnptr_00520094;
extern void *g_fnptr_00520074;
extern void (__stdcall *g_iat_InitializeCriticalSection)(void *);
void FourIndirectCalls(void) {
    void (__stdcall *f)(void *) = g_iat_InitializeCriticalSection;
    f(g_fnptr_005200b4);
    f(g_fnptr_005200a4);
    f(g_fnptr_00520094);
    f(g_fnptr_00520074);
}
