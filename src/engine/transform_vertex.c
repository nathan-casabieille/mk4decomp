/**
 * Vertex shading: apply two diffuse lights to a working RGB555.
 *
 * Computes (arg1*Lx + arg2*Ly + arg3*Lz) for each of two light
 * vectors, clips negative dot products to zero, and adds per-
 * channel scaled contributions to the unpacked RGB components of
 * g_vtxColor. Each channel is clamped to 5 bits and the result is
 * repacked back into g_vtxColor.
 */
#include "engine/render.h"

/*
 * @addr 0x004b3310
 *
 * Naked + __asm: no matching C form found. Patterns look like
 * hand-written __asm in the original source (common for 1997-era
 * per-vertex inner loops on MSVC 4.x/5.0):
 *   - inconsistent scale loads: `xor ebx,ebx; mov bl, [scale_r]`
 *     vs `mov ebx, [scale_g]; and ebx, 0xff` on same-type globals
 *   - useless spill/reload of ebx through [esp+0x18]
 *   - fail-first tail layout with explicit jmp from the success path
 */
__declspec(naked) void TransformVertex(s16 x, s16 y, s16 z)
{
    __asm {
        push    ecx
        mov     ax, word ptr [g_vtxColorSaved]
        mov     cx, word ptr [g_vtxColor]
        mov     word ptr [g_vtxColorCopy], ax
        mov     eax, dword ptr [g_vtxColorPrev]
        push    ebx
        mov     ebx, dword ptr [g_vtxLight0_z]
        push    ebp
        and     eax, 0xffff
        movsx   ebp, word ptr [esp + 0x18]                ; arg2 (y)
        push    esi
        mov     word ptr [g_vtxColorSaved], cx
        mov     ecx, eax
        mov     esi, eax
        push    edi
        and     eax, 0x1f                                  ; B (bits 0-4)
        movsx   edi, word ptr [esp + 0x18]                ; arg1 (x)
        imul    ebx, ebp
        mov     dword ptr [esp + 0x10], eax                ; save B
        mov     eax, dword ptr [g_vtxLight0_x]
        imul    eax, edi
        movsx   edx, word ptr [esp + 0x1c]                ; arg3 (z)
        add     eax, ebx
        mov     ebx, dword ptr [g_vtxLight0_y]
        imul    ebx, edx
        add     eax, ebx
        shr     ecx, 10
        shr     esi, 5
        sar     eax, 12
        and     ecx, 0x1f                                  ; R (bits 10-14)
        and     esi, 0x1f                                  ; G (bits 5-9)
        test    eax, eax
        jle     skip_light0
        xor     ebx, ebx
        mov     bl, byte ptr [g_vtxRGBScale0_r]
        imul    ebx, eax
        sar     ebx, 12
        add     ecx, ebx                                   ; R += scale_r * dot
        mov     ebx, dword ptr [g_vtxRGBScale0_g]
        and     ebx, 0xff
        imul    ebx, eax
        sar     ebx, 12
        add     esi, ebx                                   ; G += scale_g * dot
        xor     ebx, ebx
        mov     bl, byte ptr [g_vtxRGBScale0_b]
        imul    ebx, eax
        sar     ebx, 12
        mov     dword ptr [esp + 0x18], ebx
        mov     ebx, dword ptr [esp + 0x10]
        mov     eax, dword ptr [esp + 0x18]
        add     ebx, eax
        jmp     light1_dot
skip_light0:
        mov     ebx, dword ptr [esp + 0x10]
light1_dot:
        mov     eax, dword ptr [g_vtxLight1_x]
        imul    eax, edi
        mov     edi, dword ptr [g_vtxLight1_y]
        imul    edi, ebp
        add     eax, edi
        mov     edi, dword ptr [g_vtxLight1_z]
        imul    edi, edx
        add     eax, edi
        sar     eax, 12
        test    eax, eax
        jle     clamp_r
        xor     edx, edx
        mov     dl, byte ptr [g_vtxRGBScale1_r]
        imul    edx, eax
        sar     edx, 12
        add     ecx, edx
        xor     edx, edx
        mov     dl, byte ptr [g_vtxRGBScale1_g]
        imul    edx, eax
        sar     edx, 12
        add     esi, edx
        xor     edx, edx
        mov     dl, byte ptr [g_vtxRGBScale1_b]
        imul    edx, eax
        sar     edx, 12
        add     ebx, edx
clamp_r:
        cmp     ecx, 0x1f
        jle     r_ok
        mov     ecx, 0x1f
r_ok:
        mov     eax, dword ptr [g_vtxColor]
        and     ecx, 0x1f
        and     eax, 0x83ff
        shl     ecx, 10
        or      eax, ecx
        cmp     esi, 0x1f
        mov     word ptr [g_vtxColor], ax
        mov     eax, 0x1f
        jg      g_clamped
        mov     eax, esi
g_clamped:
        mov     ecx, dword ptr [g_vtxColor]
        and     eax, 0x1f
        and     ecx, 0xfc1f
        shl     eax, 5
        or      ecx, eax
        cmp     ebx, 0x1f
        mov     word ptr [g_vtxColor], cx
        mov     eax, 0x1f
        jg      b_clamped
        mov     eax, ebx
b_clamped:
        mov     dl, byte ptr [g_vtxColor]
        pop     edi
        xor     dl, al
        pop     esi
        and     edx, 0x1f
        pop     ebp
        xor     cx, dx
        pop     ebx
        mov     word ptr [g_vtxColor], cx
        pop     ecx
        ret
    }
}
