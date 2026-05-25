/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b2950 (232b engine.app) - SW renderer one-shot init.
 *   If g_renderer4_active != 0: already initialized -> return 1.
 *   If arg0 == 0: return 0.
 *   Save arg0 into g_data_007af944, clear g_renderer4_surface.
 *   RegisterWindowMessage via IAT[0x4d21b8] -> g_data_007af938; if 0 -> teardown.
 *   Allocate 0x42c bytes (LoadArgPushCall_004c54b0) -> g_data_007af934; if 0 -> teardown.
 *   Zero struct (rep stosd 0x10b). Fill fields and call IAT[0x4d202c] (CreateWindow).
 *   Set g_renderer4_active = 1; return 1.
 */
extern unsigned int g_data_007af934;
extern unsigned int g_data_007af938;
extern unsigned int g_data_007af93c;
extern int g_renderer4_active;
extern unsigned int g_data_007af944;
extern int g_renderer4_surface;
extern unsigned int g_data_007af94c;
extern unsigned int g_iat_004d202c;
extern unsigned int g_iat_004d21b8;
extern void LoadArgPushCall_004c54b0(void);
extern void RendererTeardownSW_004b2a40(void);

__declspec(naked) void Helper_GfxInit2(void) {
    __asm {
        mov     eax, dword ptr [g_renderer4_active]
        push    esi
        xor     esi, esi
        push    edi
        cmp     eax, esi
        jz      short L_si_check
        mov     eax, 1
        pop     edi
        pop     esi
        ret
    L_si_check:
        mov     eax, [esp + 0xc]
        cmp     eax, esi
        jne     short L_si_doInit
        xor     eax, eax
        pop     edi
        pop     esi
        ret
    L_si_doInit:
        push    eax
        mov     dword ptr [g_renderer4_surface], esi
        mov     dword ptr [g_data_007af944], eax
        call    dword ptr [g_iat_004d21b8]
        cmp     eax, esi
        mov     dword ptr [g_data_007af938], eax
        jz      short L_si_teardown
        push    0x42c
        call    LoadArgPushCall_004c54b0
        mov     edi, eax
        add     esp, 4
        cmp     edi, esi
        mov     dword ptr [g_data_007af934], edi
        jne     short L_si_zero
    L_si_teardown:
        call    RendererTeardownSW_004b2a40
        mov     dword ptr [g_renderer4_active], esi
        xor     eax, eax
        pop     edi
        pop     esi
        ret
    L_si_zero:
        mov     ecx, 0x10b
        xor     eax, eax
        rep     stosd
        mov     eax, dword ptr [g_data_007af934]
        mov     edi, 1
        push    esi
        push    esi
        mov     dword ptr [eax], 0x28
        mov     ecx, dword ptr [g_data_007af934]
        push    0x007af94c
        push    esi
        mov     word ptr [ecx + 0xc], di
        mov     edx, dword ptr [g_data_007af934]
        mov     word ptr [edx + 0xe], 0x10
        mov     eax, dword ptr [g_data_007af934]
        mov     [eax + 0x10], esi
        mov     ecx, dword ptr [g_data_007af934]
        mov     dword ptr [ecx + 4], 0x140
        mov     edx, dword ptr [g_data_007af934]
        mov     dword ptr [edx + 8], 0xffffff10
        mov     eax, dword ptr [g_data_007af934]
        mov     ecx, dword ptr [g_data_007af938]
        push    eax
        push    ecx
        mov     dword ptr [g_data_007af94c], esi
        call    dword ptr [g_iat_004d202c]
        mov     dword ptr [g_data_007af93c], eax
        mov     dword ptr [g_renderer4_active], edi
        mov     eax, edi
        pop     edi
        pop     esi
        ret
    }
}

