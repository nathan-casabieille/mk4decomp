/**
 * 2 "triple install + tail-jmp" helpers (39 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [g_B]
 *   mov     edx, [g_C]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [g_pendingNodeType], ecx
 *   mov     [g_scaledInit_00542048], edx
 *   jmp     Tail
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_scaledInit_00542048;
extern unsigned int g_extra_00535e68;
extern unsigned int g_extra_0053a280;

extern void func_0045daf0(void);

/* @addr 0x0045da80 */
__declspec(naked) void TripleInstallJmp_0045da80(void) {
    __asm {
        mov     eax, dword ptr [g_gtPlayerProbe2]
        mov     ecx, dword ptr [g_player1NodeIdx]
        mov     edx, dword ptr [g_extra_00535e68]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_scaledInit_00542048], edx
        jmp     func_0045daf0
    }
}

/* @addr 0x0045dab0 */
__declspec(naked) void TripleInstallJmp_0045dab0(void) {
    __asm {
        mov     eax, dword ptr [g_gtPlayerProbe1]
        mov     ecx, dword ptr [g_player2NodeIdx]
        mov     edx, dword ptr [g_extra_0053a280]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_scaledInit_00542048], edx
        jmp     func_0045daf0
    }
}
