/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * R2_Init6 - 175b stage-1 install (engine.install).
 *   Allocates 0x208 stack frame, zeros two regions (esp+4 size 0x5c, esp+0x60 size 0x1ac),
 *   fills struct fields with hard-coded device caps (0x1005 flags, sizes 0x38/8, magic 0x1ac at +0x60).
 *   If g_renderer2CapsIface != 0: vtable call [ecx+0x1c] (this+capsout); stash HRESULT to g_renderer2_present_rc.
 *   If still != 0: vtable call [ecx+0x20] (this+pinst+g_comptr_0058c7b4+&g_renderer2SurfIface); stash HRESULT.
 *   Return: (g_renderer2SurfIface != 0) as 0/1.
 */
extern unsigned int g_renderer2CapsIface;
extern unsigned int g_renderer2SurfIface;
extern unsigned int g_comptr_0058c7b4;
extern int g_renderer2_present_rc;

__declspec(naked) void R2_Init6(void)
{
    __asm
    {
        sub     esp, 0x208
        push    edi
        mov     ecx, 0x17
        xor     eax, eax
        lea     edi, [esp + 4]
        rep     stosd
        mov     ecx, 0x6b
        lea     edi, [esp + 0x60]
        rep     stosd
        mov     eax, dword ptr [g_renderer2CapsIface]
        mov     dword ptr [esp + 4], 0x5c
        test    eax, eax
        mov     dword ptr [esp + 8], 0x1005
        mov     dword ptr [esp + 0x10], 2
        mov     dword ptr [esp + 0xc], 1
        mov     dword ptr [esp + 0x28], 0x38
        mov     dword ptr [esp + 0x48], 8
        mov     dword ptr [esp + 0x60], 0x1ac
        je      short L_ret_check
        mov     ecx, dword ptr [eax]
        lea     edx, [esp + 0x60]
        push    edx
        lea     edx, [esp + 8]
        push    edx
        push    eax
        call    dword ptr [ecx + 0x1c]
        mov     dword ptr [g_renderer2_present_rc], eax
        mov     eax, dword ptr [g_renderer2CapsIface]
        test    eax, eax
        je      short L_ret_check
        mov     edx, dword ptr [g_comptr_0058c7b4]
        mov     ecx, dword ptr [eax]
        push    offset g_renderer2SurfIface
        push    edx
        lea     edx, [esp + 0x6c]
        push    edx
        push    eax
        call    dword ptr [ecx + 0x20]
        mov     dword ptr [g_renderer2_present_rc], eax
    L_ret_check:
        mov     ecx, dword ptr [g_renderer2SurfIface]
        xor     eax, eax
        test    ecx, ecx
        setne   al
        pop     edi
        add     esp, 0x208
        ret
    }
}

