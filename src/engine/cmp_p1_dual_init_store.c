/**
 * 2 "compare-with-player1 + dual scaled init + store" helpers (66b).
 *
 * Pattern:
 *   mov     edx, [g_fightGroupHead]
 *   push    esi
 *   mov     esi, [g_player1NodeIdx]
 *   mov     eax, IMM_A
 *   mov     ecx, IMM_B
 *   shr     eax, 2
 *   shr     ecx, 2
 *   cmp     edx, esi
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [g_scaledInit_00542048], ecx
 *   je      .same
 *   mov     eax, ecx                     ; not p1: A = B
 *   mov     [g_scaledInit_00542044], eax
 * .same:
 *   mov     ecx, [g_walkCallback]
 *   pop     esi
 *   mov     [eax*4 + 0], ecx              ; SIB+0 store
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_scaledInit_00542048;
extern unsigned int g_data_0053a1a0;
extern unsigned int g_data_0053a518;
extern unsigned int g_data_0053a3e4;
extern unsigned int g_data_0053a474;

/* @addr 0x00433d30
 *   NON-COAXABLE: MSVC assigns eax to the later-declared symbol (0x0053a518)
 *   but orig has the lower-address symbol (0x0053a1a0) in eax. Register
 *   allocation order is address-dependent, not controllable from C source.
 */

__declspec(naked) void CmpP1DualInitStore_00433d30(void) {
    __asm {
        mov     edx, dword ptr [g_fightGroupHead]
        push    esi
        mov     esi, dword ptr [g_player1NodeIdx]
        mov     eax, 0x0053a1a0
        mov     ecx, 0x0053a518
        shr     eax, 2
        shr     ecx, 2
        cmp     edx, esi
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_scaledInit_00542048], ecx
        je      short L_p1same_a
        mov     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
    L_p1same_a:
        mov     ecx, dword ptr [g_walkCallback]
        pop     esi
        mov     dword ptr [eax*4 + 0], ecx
        ret
    }
}

/* @addr 0x00482ab0
 *   NON-COAXABLE: same pattern - MSVC assigns eax to higher-address symbol
 *   (0x0053a474 > 0x0053a3e4), but orig has lower in eax. Same blocker.
 */
__declspec(naked) void CmpP1DualInitStore_00482ab0(void) {
    __asm {
        mov     edx, dword ptr [g_fightGroupHead]
        push    esi
        mov     esi, dword ptr [g_player1NodeIdx]
        mov     eax, 0x0053a3e4
        mov     ecx, 0x0053a474
        shr     eax, 2
        shr     ecx, 2
        cmp     edx, esi
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_scaledInit_00542048], ecx
        je      short L_p1same_b
        mov     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
    L_p1same_b:
        mov     ecx, dword ptr [g_walkCallback]
        pop     esi
        mov     dword ptr [eax*4 + 0], ecx
        ret
    }
}
