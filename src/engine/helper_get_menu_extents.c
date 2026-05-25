/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004b3dc0 (96b): screen-size lookup keyed by g_clampedRendererMode.
 *   Two code blocks (640x480 vs 320x240) selected via a 5-entry jump
 *   table; out-of-range and null-arg cases fall through to early ret.
 */
extern int g_clampedRendererMode;

__declspec(naked) void Helper_GetMenuExtents(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        test    ecx, ecx
        je      done
        mov     eax, dword ptr [esp + 8]
        test    eax, eax
        je      done
        mov     dword ptr [eax], 0
        mov     dword ptr [ecx], 0
        mov     edx, dword ptr [g_clampedRendererMode]
        dec     edx
        cmp     edx, 4
        _emit   77h
        _emit   20h
        _emit   0ffh
        _emit   24h
        _emit   95h
        _emit   0ch
        _emit   3eh
        _emit   4bh
        _emit   00h
        mov     dword ptr [ecx], 0x280
        mov     dword ptr [eax], 0x1e0
        ret
        mov     dword ptr [ecx], 0x140
        mov     dword ptr [eax], 0xf0
done:
        ret
        _emit   8dh
        _emit   49h
        _emit   00h
        _emit   0efh
        _emit   3dh
        _emit   4bh
        _emit   00h
        _emit   0efh
        _emit   3dh
        _emit   4bh
        _emit   00h
        _emit   0fch
        _emit   3dh
        _emit   4bh
        _emit   00h
        _emit   0fch
        _emit   3dh
        _emit   4bh
        _emit   00h
        _emit   0efh
        _emit   3dh
        _emit   4bh
        _emit   00h
    }
}

