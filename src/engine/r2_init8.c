/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004aec90 (274b engine.install) - DSound primary buffer + format callback pair.
 *   Sub-1 (112b): zero g_data_00544298 (108-byte WAVEFORMAT), call vtbl[0x24]
 *     on g_renderer2_obj with the format callback at L_psn_cb (= 0x4aed00).
 *     If g_data_0054429c stays 0, return 0; else fill format defaults
 *     (size, frequency 0x100, flags, channels) and return 1.
 *   Sub-2 (162b, "L_psn_cb"): per-format probe; checks mask bits 0xf800 / 0x7c00
 *     and 0x1f matching expected layout, copies caller's struct into our buffer.
 */
extern unsigned int g_data_004f478c;
extern unsigned int g_data_00544298;
extern unsigned int g_data_0054429c;
extern unsigned int g_data_005442a0;
extern unsigned int g_data_005442a4;
extern unsigned int g_data_005442e0;
extern unsigned int g_data_00544300;
extern unsigned int g_renderer2_obj;

__declspec(naked) void R2_Init8(void) {
    __asm {
        push    edi
        mov     ecx, 0x1b
        xor     eax, eax
        mov     edi, offset g_data_00544298
        rep     stosd
        mov     eax, dword ptr [g_renderer2_obj]
        test    eax, eax
        jz      short L_psn_check
        mov     ecx, [eax]
        push    0
        push    offset L_psn_cb
        push    eax
        call    dword ptr [ecx + 0x24]
    L_psn_check:
        mov     eax, dword ptr [g_data_0054429c]
        test    eax, eax
        jne     short L_psn_fill
        xor     eax, eax
        pop     edi
        ret
    L_psn_fill:
        mov     eax, 0x100
        mov     dword ptr [g_data_00544298], 0x6c
        mov     dword ptr [g_data_005442a4], eax
        mov     dword ptr [g_data_005442a0], eax
        mov     dword ptr [g_data_0054429c], 0x1007
        mov     dword ptr [g_data_00544300], 0x04005000
        mov     dword ptr [g_data_005442e0], 0x20
        mov     eax, 1
        pop     edi
        ret
    L_psn_cb:
        push    esi
        mov     esi, [esp + 8]
        push    edi
        mov     eax, [esi + 4]
        test    ah, 0x10
        jz      L_psn_cb_fail
        mov     eax, [esi + 0x4c]
        test    al, 2
        jne     L_psn_cb_fail
        test    al, 1
        jne     L_psn_cb_fail
        test    al, 0x40
        jz      L_psn_cb_fail
        cmp     dword ptr [esi + 0x54], 0x10
        jne     L_psn_cb_fail
        mov     eax, [esi + 0x58]
        mov     ecx, 0x1f
        cmp     eax, 0xf800
        jne     short L_psn_cb_alt
        cmp     dword ptr [esi + 0x5c], 0x7e0
        jne     short L_psn_cb_alt
        cmp     dword ptr [esi + 0x60], ecx
        jne     short L_psn_cb_alt
        mov     ecx, 0x1b
        mov     edi, offset g_data_00544298
        rep     movsd
        mov     dword ptr [g_data_004f478c], 1
        mov     eax, 1
        pop     edi
        pop     esi
        ret     8
    L_psn_cb_alt:
        cmp     eax, 0x7c00
        jne     short L_psn_cb_fail
        cmp     dword ptr [esi + 0x5c], 0x3e0
        jne     short L_psn_cb_fail
        cmp     dword ptr [esi + 0x60], ecx
        jne     short L_psn_cb_fail
        mov     eax, dword ptr [g_data_0054429c]
        test    eax, eax
        jne     short L_psn_cb_fail
        mov     ecx, 0x1b
        mov     edi, offset g_data_00544298
        rep     movsd
        mov     dword ptr [g_data_004f478c], 0
    L_psn_cb_fail:
        pop     edi
        mov     eax, 1
        pop     esi
        ret     8
    }
}

