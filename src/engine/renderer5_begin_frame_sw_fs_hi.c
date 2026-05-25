/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b28a0 (140b engine.app) - validated audio buffer setup:
 *   if (!g_renderer4_active || g_renderer4_surface || !arg2 || !arg3 || !arg4) return 0;
 *   *arg3 = 0x280; *arg2 = g_x_007af94c; *arg4 = 0; g_renderer4_surface = 1;
 *   if (arg1 && g_x_007af94c): memset(g_x_007af94c, 0x10001, *arg3 * 60 / 4).
 *   Return 1.
 */
extern int g_renderer4_active;
extern int g_renderer4_surface;
extern unsigned int g_x_007af94c;

__declspec(naked) int Renderer5_BeginFrame_SW_FS_Hi(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        mov     eax, dword ptr [g_renderer4_active]
        push    esi
        test    eax, eax
        push    edi
        _emit   74h
        _emit   78h
        mov     eax, dword ptr [g_renderer4_surface]
        test    eax, eax
        _emit   75h
        _emit   6fh
        mov     edx, dword ptr [ebp + 0x0c]
        test    edx, edx
        _emit   74h
        _emit   68h
        mov     eax, dword ptr [ebp + 0x10]
        test    eax, eax
        _emit   74h
        _emit   61h
        mov     ecx, dword ptr [ebp + 0x14]
        test    ecx, ecx
        _emit   74h
        _emit   5ah
        mov     dword ptr [eax], 0x280
        mov     esi, dword ptr [g_x_007af94c]
        mov     dword ptr [edx], esi
        mov     dword ptr [ecx], 0
        mov     ecx, dword ptr [ebp + 8]
        mov     dword ptr [g_renderer4_surface], 1
        test    ecx, ecx
        _emit   74h
        _emit   2ch
        mov     ecx, dword ptr [g_x_007af94c]
        test    ecx, ecx
        _emit   74h
        _emit   22h
        mov     eax, dword ptr [eax]
        lea     eax, [eax + eax*2]
        lea     eax, [eax + eax*4]
        shl     eax, 4
        sar     eax, 2
        mov     dword ptr [ebp + 0x0c], eax
        cld
        mov     edi, dword ptr [g_x_007af94c]
        mov     ecx, dword ptr [ebp + 0x0c]
        mov     eax, 0x10001
        rep     stosd
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebp
        ret
        pop     edi
        xor     eax, eax
        pop     esi
        pop     ebp
        ret
    }
}

