/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/*
 * @addr 0x004b3dc0 (96b): screen-size lookup keyed by g_currentRendererMode.
 *   Two code blocks (640x480 vs 320x240) selected via a 5-entry jump
 *   table; out-of-range and null-arg cases fall through to early ret.
 */
extern int g_currentRendererMode;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Helper_GetMenuExtents(undefined4 *param_1,undefined4 *param_2)

{
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    *param_1 = 0;
    switch(g_clampedRendererMode) {
    case 1:
    case 2:
    case 5:
      *param_1 = 0x280;
      *param_2 = 0x1e0;
      return;
    case 3:
    case 4:
      *param_1 = 0x140;
      *param_2 = 0xf0;
    }
  }
  return;
}
#else
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
        mov     edx, dword ptr [g_currentRendererMode]
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
#endif

