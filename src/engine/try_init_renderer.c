/**
 * Attempt renderer init for g_clampedRendererMode.
 *
 * If g_appInitFlag2 is set or the requested mode equals the
 * current mode, returns -1 (no-op). Otherwise tears down all
 * three DirectDraw paths via Helper_RendererPreInit + R2_Cleanup +
 * DDraw3_Cleanup + DDraw5_Cleanup, then dispatches via a 5-arm
 * jump table to the matching Renderer*_Init_* helper. On
 * success, runs Helper_PaletteInit + BeginFrame(1) + DrawScene +
 * PresentFrame and Helper_RendererPostInit, then returns -mode.
 */
#include "engine/render.h"
#include "engine/scenegraph.h"
#include "platform/win32.h"

extern s32 g_pumpFlagD8, g_pumpFlagDC, g_pumpFlagE0, g_pumpFlagE4;

const u32 TryInit_JumpTable[5] = {0, 0, 0, 0, 0};

/*
 * @addr 0x004b3ed0
 *
 * Naked + __asm: 5-arm jump table on (mode - 1), each per-renderer
 * arm captures the success-mode in esi while clearing the
 * "tried" flag for that renderer. Tail does a forced fallback
 * to mode 4 if no renderer succeeded.
 */
__declspec(naked) s32 TryInitRenderer(void)
{
    __asm {
        push    ecx
        mov     eax, dword ptr [g_appInitFlag2]
        push    ebx
        push    esi
        xor     ebx, ebx
        xor     esi, esi
        cmp     eax, ebx
        mov     eax, dword ptr [g_currentRendererMode]
        jne     return_skip                              ; long form
        mov     ecx, dword ptr [g_clampedRendererMode]
        cmp     ecx, eax
        je      return_skip                              ; long form
        cmp     ecx, 1
        mov     dword ptr [g_gfxSavedMode], eax
        jne     check_mode2
        cmp     dword ptr [g_gfxFlagA], ebx
        jz      noop_ret
check_mode2:
        cmp     ecx, 2
        jne     check_mode3
        cmp     dword ptr [g_gfxFlagB], ebx
        jz      noop_ret
check_mode3:
        cmp     ecx, 3
        jne     do_init
        cmp     dword ptr [g_gfxFlagC], ebx
        jne     do_init
noop_ret:
        mov     dword ptr [g_clampedRendererMode], eax
        mov     eax, ecx
        neg     eax
        pop     esi
        pop     ebx
        pop     ecx
        ret
do_init:
        mov     dword ptr [g_appInitFlag2], 1
        call    Helper_RendererPreInit
        call    R2_Cleanup
        call    DDraw3_Cleanup
        call    DDraw5_Cleanup
        mov     eax, dword ptr [g_clampedRendererMode]
        dec     eax
        cmp     eax, 4
        ja      after_switch                              ; long form
        jmp     dword ptr [eax*4 + TryInit_JumpTable]
case_glide:
        mov     ecx, dword ptr [g_gfxHwnd]
        push    ecx
        call    Renderer1_Init_Glide
        add     esp, 4
        test    eax, eax
        jne     g1_set
        mov     esi, 1
g1_set:
        cmp     esi, ebx
        jz      g1_skip
        mov     dword ptr [g_pumpFlagD8], ebx
g1_skip:
        mov     eax, dword ptr [g_pumpFlagD8]
        mov     byte ptr [esp + 0xb], bl
        cmp     eax, ebx
        jz      after_switch
        mov     dword ptr [g_pumpFlagDC], ebx
        jmp     after_switch
case_d3d:
        mov     edx, dword ptr [g_gfxHwnd]
        push    edx
        call    Renderer2_Init_D3D
        add     esp, 4
        test    eax, eax
        jne     d3_set
        mov     esi, 2
d3_set:
        cmp     esi, ebx
        jz      d3_skip
        mov     dword ptr [g_pumpFlagDC], ebx
d3_skip:
        mov     byte ptr [esp + 0xb], bl
        jmp     after_switch
case_swfs:
        mov     ecx, dword ptr [g_gfxHwnd]
        lea     eax, [esp + 0xb]
        push    eax
        push    ecx
        call    Renderer3_Init_SW_FS
        add     esp, 8
        test    eax, eax
        jne     s3_set
        mov     esi, 3
s3_set:
        cmp     esi, ebx
        jz      after_switch
        mov     dword ptr [g_pumpFlagE0], ebx
        jmp     after_switch
case_swfshi:
        mov     eax, dword ptr [g_gfxHwnd]
        lea     edx, [esp + 0xb]
        push    edx
        push    eax
        call    Renderer5_Init_SW_FS_Hi
        add     esp, 8
        test    eax, eax
        jne     s5_set
        mov     esi, 5
s5_set:
        cmp     esi, ebx
        jz      after_switch
        mov     dword ptr [g_gfxFlagD], ebx
after_switch:
        mov     eax, dword ptr [g_clampedRendererMode]
        cmp     eax, 4
        je      force_mode4
        cmp     esi, ebx
        jz      success_path
force_mode4:
        mov     eax, 4
        mov     byte ptr [esp + 0xb], bl
        mov     dword ptr [g_clampedRendererMode], eax
success_path:
        movsx   ecx, byte ptr [esp + 0xb]
        push    ecx
        mov     dword ptr [g_currentRendererMode], eax
        call    Helper_PaletteInit
        add     esp, 4
        push    1
        call    BeginFrame
        add     esp, 4
        call    DrawScene
        call    PresentFrame
        mov     eax, dword ptr [g_gfxPostInitArg]
        mov     edx, dword ptr [g_currentRendererMode]
        push    eax
        mov     dword ptr [g_appInitFlag2], ebx
        mov     dword ptr [g_gfxSavedMode], edx
        call    Helper_RendererPostInit
        mov     eax, esi
        add     esp, 4
        neg     eax
return_skip:
        pop     esi
        pop     ebx
        pop     ecx
        ret
    }
}
