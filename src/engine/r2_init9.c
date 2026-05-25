/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004af190 (127b engine.install) - DirectInput EnumDevices
 *   bootstrap: copies a 108-byte DIDATAFORMAT template from
 *   0x544298; if IDirectInput exists, EnumDevices into 0x58c7c8;
 *   if the device was created, calls CreateDevice via the 0x4d28f0
 *   GUID; returns 1 on full success, 0 otherwise.
 */
extern unsigned int g_installCountdownBase_00544298;
extern unsigned int g_comptr_0058c7ac;
extern unsigned int g_renderer2_state9_0058c7c8;
extern unsigned int g_renderer2_var2_0058c7cc;
extern int g_renderer2_present_rc;

__declspec(naked) void R2_Init9(void) {
    __asm {
        sub     esp, 0x6c
        mov     eax, dword ptr [g_comptr_0058c7ac]
        push    esi
        push    edi
        mov     ecx, 0x1b
        mov     esi, offset g_installCountdownBase_00544298
        lea     edi, [esp + 8]
        rep     movsd
        test    eax, eax
        mov     dword ptr [esp + 0x70], 0x1800
        je      step2
        mov     ecx, dword ptr [eax]
        push    0
        lea     edx, [esp + 0xc]
        push    offset g_renderer2_state9_0058c7c8
        push    edx
        push    eax
        call    dword ptr [ecx + 0x18]
        mov     dword ptr [g_renderer2_present_rc], eax
step2:
        mov     eax, dword ptr [g_renderer2_state9_0058c7c8]
        test    eax, eax
        je      failPath
        mov     ecx, dword ptr [eax]
        push    offset g_renderer2_var2_0058c7cc
        push    0x004d28f0
        push    eax
        call    dword ptr [ecx]
        mov     dword ptr [g_renderer2_present_rc], eax
        mov     eax, dword ptr [g_renderer2_state9_0058c7c8]
        test    eax, eax
        je      failPath
        mov     eax, dword ptr [g_renderer2_var2_0058c7cc]
        test    eax, eax
        je      failPath
        mov     eax, 1
        pop     edi
        pop     esi
        add     esp, 0x6c
        ret
failPath:
        pop     edi
        xor     eax, eax
        pop     esi
        add     esp, 0x6c
        ret
    }
}

