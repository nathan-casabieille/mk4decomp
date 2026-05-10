/**
 * 2 "scaled chain + dec + tail-jmp" helpers (36 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x24]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 4]
 *   dec     ecx
 *   mov     [g_walkCallback], ecx
 *   jmp     Tail
 *
 * Walks one level deeper into the fight-group chain (offset 0x24),
 * caches the chained pointer in a scaled-base global, then loads
 * and decrements the per-chain counter at offset 4 before tail-
 * jumping into the dispatch handler.
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

extern void func_004293b0(void);
extern void func_00429960(void);

/* @addr 0x00429470 */
__declspec(naked) void ScaledChainJmp_00429470(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 4]
        dec     ecx
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_004293b0
    }
}

/* @addr 0x004298e0 */
__declspec(naked) void ScaledChainJmp_004298e0(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 4]
        dec     ecx
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_00429960
    }
}
