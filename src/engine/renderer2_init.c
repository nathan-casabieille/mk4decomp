/**
 * Renderer 2 (Direct3D) init.
 *
 * Brings up the D3D pipeline by clearing 3 small state buffers,
 * filling a 256-entry float LUT (linear ramp scaled by
 * g_renderer2_lutStep), then chaining 11 sub-init helpers. On any
 * failure, calls R2_Cleanup and returns 0; on full success sets
 * g_renderer2_active = 1 and returns 1.
 */
#include "engine/render.h"
#include "platform/win32.h"

/*
 * @addr 0x004ad6a0
 *

 * Naked + __asm: the 11-helper chain has a specific layout where
 * each test eax/jz redirects to the same R2_Cleanup tail; the FPU
 * loop fills the LUT table without spilling to memory between
 * iterations; and the 16-iteration final loop on R2_Init11 uses
 * esi as the index. Pure C wouldn't reproduce the chain's exact
 * register threading.
 */

__declspec(naked) int Renderer2_Init_D3D(HWND hwnd)
{
    __asm {
        mov     eax, dword ptr [g_renderer2_active]
        push    ebx
        xor     ebx, ebx
        push    esi
        cmp     eax, ebx
        push    edi
        jz      do_init
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebx
        ret
do_init:
        mov     eax, dword ptr [esp + 0x10]               ; hwnd
        cmp     eax, ebx
        jne     have_hwnd
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebx
        ret
have_hwnd:
        mov     dword ptr [g_renderer2_hwnd], eax
        mov     ecx, 16
        xor     eax, eax
        mov     edi, offset g_renderer2_buf1
        rep     stosd
        mov     ecx, 16
        mov     edi, offset g_renderer2_obj                ; same area, 0x58c720
        rep     stosd
        mov     ecx, 16
        mov     edi, offset g_renderer2_buf3
        rep     stosd
        mov     dword ptr [g_renderer2_surface], ebx
        mov     dword ptr [g_renderer2_present_rc], ebx
        mov     dword ptr [g_renderer2_paused], ebx
        mov     dword ptr [esp + 0x10], ebx                ; hwnd slot reused as float counter
        mov     eax, offset g_renderer2_lutTable
fill_loop:
        fild    dword ptr [esp + 0x10]
        mov     esi, dword ptr [esp + 0x10]
        add     eax, 4
        inc     esi
        cmp     eax, offset g_renderer2_lutTable + 0x400
        fmul    dword ptr [g_renderer2_lutStep]
        mov     dword ptr [esp + 0x10], esi
        fstp    dword ptr [eax - 4]
        jl      fill_loop
        call    R2_Init1
        test    eax, eax
        jz      cleanup
        call    R2_Init2
        test    eax, eax
        jz      cleanup
        call    R2_Init3
        mov     edi, 1
        push    edi
        call    R2_Init4
        add     esp, 4
        test    eax, eax
        jz      cleanup
        mov     dword ptr [g_renderer2_initOk], edi
        call    R2_Init5
        test    eax, eax
        jz      cleanup
        call    R2_Init6
        test    eax, eax
        jz      cleanup
        call    R2_Init7
        test    eax, eax
        jz      cleanup
        call    R2_Init8
        test    eax, eax
        jz      cleanup
        call    R2_Init9
        test    eax, eax
        jz      cleanup
        call    R2_Init10
        xor     esi, esi
init11_loop:
        push    esi
        call    R2_Init11
        add     esp, 4
        test    eax, eax
        jz      cleanup
        inc     esi
        cmp     esi, 16
        jl      init11_loop
        mov     dword ptr [g_renderer2_active], edi
        mov     eax, edi
        pop     edi
        pop     esi
        pop     ebx
        ret
cleanup:
        call    R2_Cleanup
        mov     dword ptr [g_renderer2_active], ebx
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
