/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x0048bc40 (174b game) - mstack-push 2, table-search nonzero, mstack-pop 2. */
void Helper_DownloadSetup(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_x_0054206c]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + g_data_004d57ac_arr], ecx
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [g_data_00535e48]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + g_data_004d57ac_arr], edx
        mov     eax, dword ptr [g_x_0054206c]
        mov     edx, 0x004f02d0
        lea     ecx, [eax*8 + 0]
        shr     edx, 2
        mov     dword ptr [g_data_00535e48], ecx
        mov     dword ptr [g_scaledInit_00542044], edx
        lea     eax, [edx + ecx]
        mov     eax, dword ptr [eax*4 + 0]
        test    eax, eax
        mov     dword ptr [g_x_0054206c], eax
        _emit   75h
        _emit   0bh
        add     ecx, 8
        mov     dword ptr [g_data_00535e48], ecx
        _emit   0ebh
        _emit   0e2h
        _emit   7dh
        _emit   0ah
        xor     ecx, ecx
        mov     dword ptr [g_data_00535e48], ecx
        _emit   0ebh
        _emit   0d6h
        mov     eax, dword ptr [g_state_004d57ac]
        add     edx, ecx
        mov     dword ptr [g_scaledInit_00542044], edx
        mov     ecx, dword ptr [eax*4 + g_data_004d57ac_arr]
        dec     eax
        mov     dword ptr [g_data_00535e48], ecx
        mov     dword ptr [g_state_004d57ac], eax
        mov     edx, dword ptr [eax*4 + g_data_004d57ac_arr]
        dec     eax
        mov     dword ptr [g_x_0054206c], edx
        mov     dword ptr [g_state_004d57ac], eax
        }
}

