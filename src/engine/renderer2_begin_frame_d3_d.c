/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_data_004f4790;
extern unsigned int g_data_004f4794;
extern unsigned int g_data_004f4798;
extern unsigned int g_data_004f479c;
extern u8 g_renderer2_buf2[];
extern unsigned int g_data_0058c760;
extern unsigned int g_comptr_0058c7b0;
extern unsigned int g_comptr_0058c7b4;
extern unsigned int g_renderer2_obj;
extern unsigned int g_data_0058c7c4;
extern unsigned int g_data_0058c7d0;
extern int g_renderer2_present_rc;
extern int g_renderer2_active;
extern int g_renderer2_surface;
extern int g_renderer2_paused;

__declspec(naked) void Renderer2_BeginFrame_D3D(void)
{
    __asm {
        mov      eax, dword ptr [g_renderer2_active]
        sub      esp, 0x10
        test     eax, eax
        push     esi
        je       L_dc15
        mov      eax, dword ptr [g_renderer2_surface]
        test     eax, eax
        jne      L_dc15
        mov      eax, dword ptr [g_renderer2_paused]
        test     eax, eax
        jne      L_dc15
        mov      eax, dword ptr [g_comptr_0058c7b0]
        test     eax, eax
        je       L_da5c
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x60]
        cmp      eax, 0x887601c2
        jne      L_da5c
        mov      eax, dword ptr [g_comptr_0058c7b0]
        push     eax
        mov      edx, dword ptr [eax]
        call     dword ptr [edx + 0x6c]
    L_da5c:
        mov      eax, dword ptr [g_comptr_0058c7b4]
        test     eax, eax
        je       L_da7d
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x60]
        cmp      eax, 0x887601c2
        jne      L_da7d
        mov      eax, dword ptr [g_comptr_0058c7b4]
        push     eax
        mov      edx, dword ptr [eax]
        call     dword ptr [edx + 0x6c]
    L_da7d:
        mov      esi, OFFSET g_renderer2_buf2
    L_da82:
        mov      eax, dword ptr [esi]
        test     eax, eax
        je       L_da9d
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x60]
        cmp      eax, 0x887601c2
        jne      L_da9d
        mov      eax, dword ptr [esi]
        push     eax
        mov      edx, dword ptr [eax]
        call     dword ptr [edx + 0x6c]
    L_da9d:
        add      esi, 4
        cmp      esi, OFFSET g_data_0058c760
        jl       L_da82
        mov      eax, dword ptr [esp + 0x18]
        test     eax, eax
        je       L_daed
        mov      eax, dword ptr [g_data_0058c7c4]
        mov      dword ptr [esp + 4], 0
        test     eax, eax
        mov      dword ptr [esp + 8], 0
        mov      dword ptr [esp + 0xc], 0x280
        mov      dword ptr [esp + 0x10], 0x1e0
        je       L_daed
        mov      ecx, dword ptr [eax]
        lea      edx, [esp + 4]
        push     1
        push     edx
        push     1
        push     eax
        call     dword ptr [ecx + 0x30]
        mov      dword ptr [g_renderer2_present_rc], eax
    L_daed:
        mov      eax, dword ptr [g_renderer2_obj]
        test     eax, eax
        je       L_db06
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x28]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
    L_db06:
        test     eax, eax
        mov      dword ptr [g_renderer2_surface], 1
        mov      byte ptr [g_data_004f4790], 0xff
        mov      byte ptr [g_data_0058c7d0], 0
        je       L_dc15
        mov      edx, dword ptr [eax]
        push     1
        push     0x1f
        push     eax
        call     dword ptr [edx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
        test     eax, eax
        je       L_dc15
        mov      esi, dword ptr [g_data_004f479c]
        mov      ecx, dword ptr [eax]
        xor      edx, edx
        test     esi, esi
        setne    dl
        inc      edx
        push     edx
        push     9
        push     eax
        call     dword ptr [ecx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
        test     eax, eax
        je       L_dc15
        mov      ecx, dword ptr [eax]
        push     0
        push     0x1d
        push     eax
        call     dword ptr [ecx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
        test     eax, eax
        je       L_dc15
        mov      esi, dword ptr [g_data_004f4794]
        mov      edx, dword ptr [eax]
        xor      ecx, ecx
        test     esi, esi
        setne    cl
        inc      ecx
        push     ecx
        push     0x11
        push     eax
        call     dword ptr [edx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
        test     eax, eax
        je       L_dc15
        mov      esi, dword ptr [g_data_004f4794]
        mov      edx, dword ptr [eax]
        xor      ecx, ecx
        test     esi, esi
        setne    cl
        inc      ecx
        push     ecx
        push     0x12
        push     eax
        call     dword ptr [edx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
        test     eax, eax
        je       L_dc15
        mov      ecx, dword ptr [g_data_004f4798]
        mov      edx, dword ptr [eax]
        push     ecx
        push     0x1a
        push     eax
        call     dword ptr [edx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
        test     eax, eax
        je       L_dc15
        mov      edx, dword ptr [eax]
        push     1
        push     0x29
        push     eax
        call     dword ptr [edx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
        test     eax, eax
        je       L_dc15
        mov      ecx, dword ptr [eax]
        push     0
        push     0x1b
        push     eax
        call     dword ptr [ecx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
    L_dc15:
        pop      esi
        add      esp, 0x10
        ret
    }
}

