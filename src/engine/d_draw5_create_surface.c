/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b0540 (297b engine.ecm) - third twin DSoundModeSetup for 640x480
 *   with ECM-group state globals. Same shape as 0x4aeae0/0x4afd10.
 *   Calls DialogProbeDispatch640_004b0670.
 */
extern unsigned int g_data_004f47b0;
extern unsigned int g_data_0058c8d8;
extern unsigned int g_data_0058c8dc;
extern unsigned int g_dsmi_3a0_main;
extern unsigned int g_dsmi_3a0_ret;
extern unsigned int g_190_iface;
extern unsigned int g_iat_004d219c;
extern unsigned int g_iat_004d21a4;
extern unsigned int g_iat_004d21ac;
extern void DialogProbeDispatch640_004b0670(void);

__declspec(naked) void DDraw5_CreateSurface(void) {
    __asm {
        mov     ecx, dword ptr [g_data_004f47b0]
        mov     eax, [esp + 4]
        sub     esp, 0x6c
        cmp     ecx, eax
        push    edi
        jz      L_dms3_okRet
        cmp     ecx, -1
        jne     short L_dms3_doSwitch
        test    eax, eax
        jz      L_dms3_okRet
    L_dms3_doSwitch:
        test    eax, eax
        mov     dword ptr [g_data_004f47b0], eax
        jz      L_dms3_release
        push    offset g_data_0058c8d8
        call    dword ptr [g_iat_004d21ac]
        push    0
        call    dword ptr [g_iat_004d219c]
        call    DialogProbeDispatch640_004b0670
        mov     eax, dword ptr [g_dsmi_3a0_main]
        test    eax, eax
        jz      short L_dms3_skipPair
        mov     edx, dword ptr [g_190_iface]
        mov     ecx, [eax]
        push    0x55
        push    edx
        push    eax
        call    dword ptr [ecx + 0x50]
        mov     dword ptr [g_dsmi_3a0_ret], eax
        mov     eax, dword ptr [g_dsmi_3a0_main]
        test    eax, eax
        jz      short L_dms3_skipPair
        mov     ecx, [eax]
        push    0x10
        push    0x1e0
        push    0x280
        push    eax
        call    dword ptr [ecx + 0x54]
        mov     dword ptr [g_dsmi_3a0_ret], eax
    L_dms3_skipPair:
        call    DialogProbeDispatch640_004b0670
        mov     ecx, 0x1b
        xor     eax, eax
        lea     edi, [esp + 4]
        rep     stosd
        mov     eax, dword ptr [g_dsmi_3a0_main]
        mov     dword ptr [esp + 4], 0x6c
        test    eax, eax
        jz      short L_dms3_validate
        mov     edx, [eax]
        lea     ecx, [esp + 4]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x30]
        mov     dword ptr [g_dsmi_3a0_ret], eax
    L_dms3_validate:
        cmp     dword ptr [esp + 0x10], 0x280
        jne     short L_dms3_fail
        cmp     dword ptr [esp + 0xc], 0x1e0
        jz      L_dms3_okRet
    L_dms3_fail:
        xor     eax, eax
        pop     edi
        add     esp, 0x6c
        ret
    L_dms3_release:
        mov     eax, dword ptr [g_dsmi_3a0_main]
        test    eax, eax
        jz      short L_dms3_restoreCursor
        mov     edx, [eax]
        push    eax
        call    dword ptr [edx + 0x4c]
        mov     dword ptr [g_dsmi_3a0_ret], eax
        mov     eax, dword ptr [g_dsmi_3a0_main]
        test    eax, eax
        jz      short L_dms3_restoreCursor
        mov     edx, dword ptr [g_190_iface]
        mov     ecx, [eax]
        push    0xc
        push    edx
        push    eax
        call    dword ptr [ecx + 0x50]
        mov     dword ptr [g_dsmi_3a0_ret], eax
    L_dms3_restoreCursor:
        mov     eax, dword ptr [g_data_0058c8dc]
        mov     ecx, dword ptr [g_data_0058c8d8]
        push    eax
        push    ecx
        call    dword ptr [g_iat_004d21a4]
        push    1
        call    dword ptr [g_iat_004d219c]
    L_dms3_okRet:
        mov     eax, 1
        pop     edi
        add     esp, 0x6c
        ret
    }
}

