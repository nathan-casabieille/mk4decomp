/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004ad7c0 (141b engine.install) - shutdown sequence:
 *   Renderer2_EndScene_D3D, VtRelease_Modal, ReleaseVtableSlot 0..15;
 *   ComRelease 4x, DSoundBufferInit146(0), 3 more releases; if g_x_0058c7e8:
 *   SetEvent via IAT@4d2210; clear g_x_0058c7e8; ret.
 */
__declspec(naked) void R2_Cleanup(void) {
    __asm {
        push    esi
        call    Renderer2_EndScene_D3D
        call    VtRelease_Modal_004ad590
        mov     eax, dword ptr [g_x_0058c7ac]
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x28]
        mov     dword ptr [g_x_0058c7dc], eax
        xor     esi, esi
loop4ad7c0:
        push    esi
        call    ReleaseVtableSlots_004af130
        add     esp, 4
        inc     esi
        cmp     esi, 0x10
        _emit   7ch
        _emit   0f1h
        call    ComRelease_004aedc0
        call    DSoundDualEntryRelease_004af210
        call    DualVtable8Call_004af650
        call    ComRelease_004af000
        call    ComReleasePair_004af440
        push    0
        call    DSoundBufferInit146_004aea40
        add     esp, 4
        call    ComRelease_004aef30
        call    ComReleaseCapture_004aeee0
        call    DSoundBufferInit146_004aea40
        mov     eax, dword ptr [g_x_0058c7e8]
        mov     dword ptr [g_x_0058c7e0], 0
        test    eax, eax
        _emit   74h
        _emit   0ch
        push    1
        push    0
        push    0
        call    dword ptr [g_iat_004d2210]
        mov     dword ptr [g_x_0058c7e8], 0
        pop     esi
        ret
    }
}

