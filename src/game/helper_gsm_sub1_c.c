/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_gsmHelperBase;
extern unsigned int g_dispatchSave573;
extern u32 g_gsmOut4;
extern unsigned int g_dispatchSave1480;
extern unsigned int g_dispatchSave1483;
extern u32 g_gsmDirty1;
extern u32 g_gsmDirty2;
extern u32 g_gsmDirty3;
extern unsigned int g_dispatchSave1498;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_dispatchSave1480 (*(unsigned int *)MK4_VA(unsigned int, 0xab42ccu))
#define g_dispatchSave1483 (*(unsigned int *)MK4_VA(unsigned int, 0xab42dcu))
#define g_dispatchSave1498 (*(unsigned int *)MK4_VA(unsigned int, 0xab4380u))
#define g_dispatchSave573 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4f34u))
#define g_gsmDirty1 (*(unsigned int *)MK4_VA(unsigned int, 0xab4374u))
#define g_gsmDirty2 (*(unsigned int *)MK4_VA(unsigned int, 0xab4378u))
#define g_gsmDirty3 (*(unsigned int *)MK4_VA(unsigned int, 0xab437cu))
#define g_gsmHelperBase (*(unsigned int *)MK4_VA(unsigned int, 0x4f4f30u))
#define g_gsmOut4 (*(unsigned int *)MK4_VA(unsigned int, 0x543820u))
#endif

/* Real signatures. The auto-generated placeholders all said `(void)`, but the
 * original pushes two stack args for the two selectable-scanners and one for
 * the poll, and every caller uses the returned value. */
extern int          DrawMenu(void *menu, int sel);
extern unsigned int Menu_PollNavInput(int mode);
extern unsigned int Menu_FindNextSelectable(int cur, void *menu);
extern unsigned int Menu_FindPrevSelectable(int cur, void *menu);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int Menu_PauseMenu(void)

{
  uint uVar1;
  uint uVar2;
  
  if ((g_dispatchSave1480 & 1) == 0) {
    g_dispatchSave1480 = g_dispatchSave1480 | 1;
    g_dispatchSave1483 = Menu_FindNextSelectable(0,&g_gsmHelperBase);
  }
  if (g_dispatchSave1498 == 0) {
    g_dispatchSave1498 = 2;
    g_dispatchSave1483 = Menu_FindNextSelectable(0,&g_gsmHelperBase);
  }
  else if (g_dispatchSave1498 == 2) {
    uVar1 = Menu_PollNavInput(1);
    uVar2 = uVar1 & 0x8000;
    if ((uVar2 == 0) && ((uVar1 & 1) != 0)) {
      g_dispatchSave1483 = Menu_FindPrevSelectable(g_dispatchSave1483,&g_gsmHelperBase);
    }
    if ((uVar2 == 0) && ((uVar1 & 2) != 0)) {
      g_dispatchSave1483 = Menu_FindNextSelectable(g_dispatchSave1483,&g_gsmHelperBase);
    }
    if ((uVar2 == 0) && ((uVar1 & 0x20) != 0)) {
      g_dispatchSave1498 = 0x45;
    }
    if (g_gsmOut4 == 0) {
      g_dispatchSave1498 = 0x45;
    }
    switch(*(undefined2 *)((unsigned char *)&g_dispatchSave573 + g_dispatchSave1483 * 8)) {
    case 0x14:
      if ((uVar2 == 0) && ((uVar1 & 0x10) != 0)) {
        g_dispatchSave1498 = 0x45;
      }
      break;
    case 0x15:
      if ((uVar2 == 0) && ((uVar1 & 0x10) != 0)) {
        g_dispatchSave1498 = 0x45;
        g_gsmDirty1 = 1;
      }
      break;
    case 0x16:
      if ((uVar2 == 0) && ((uVar1 & 0x10) != 0)) {
        g_dispatchSave1498 = 0x45;
        g_gsmDirty2 = 1;
      }
      break;
    case 0x17:
      if ((uVar2 == 0) && ((uVar1 & 0x10) != 0)) {
        g_dispatchSave1498 = 0x45;
        g_gsmDirty3 = 1;
      }
    }
  }
  else if (g_dispatchSave1498 == 0x45) {
    g_dispatchSave1498 = 0;
  }
  DrawMenu(&g_gsmHelperBase,g_dispatchSave1483);
  return g_dispatchSave1498;
}
#else
__declspec(naked) void Menu_PauseMenu(void)
{
    __asm {
        mov      al, byte ptr [g_dispatchSave1480]
        push     ebx
        test     al, 1
        push     esi
        jne      short L_8a5c
        mov      bl, al
        push     OFFSET g_gsmHelperBase
        or       bl, 1
        push     0
        mov      byte ptr [g_dispatchSave1480], bl
        call     Menu_FindNextSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1483], eax
        jmp      short L_8a61
    L_8a5c:
        mov      eax, dword ptr [g_dispatchSave1483]
    L_8a61:
        mov      ecx, dword ptr [g_dispatchSave1498]
        sub      ecx, 0
        je       L_8b84
        sub      ecx, 2
        je       short L_8a8d
        sub      ecx, 0x43
        jne      L_8ba2
        mov      dword ptr [g_dispatchSave1498], 0
        jmp      L_8ba2
    L_8a8d:
        push     1
        call     Menu_PollNavInput
        mov      ebx, eax
        add      esp, 4
        mov      esi, ebx
        and      esi, 0x8000
        jne      short L_8ac2
        test     bl, 1
        je       short L_8ac2
        mov      eax, dword ptr [g_dispatchSave1483]
        push     OFFSET g_gsmHelperBase
        push     eax
        call     Menu_FindPrevSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1483], eax
        jmp      short L_8ac7
    L_8ac2:
        mov      eax, dword ptr [g_dispatchSave1483]
    L_8ac7:
        test     esi, esi
        jne      short L_8ae3
        test     bl, 2
        je       short L_8ae3
        push     OFFSET g_gsmHelperBase
        push     eax
        call     Menu_FindNextSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1483], eax
    L_8ae3:
        test     esi, esi
        mov      edx, 0x45
        jne      short L_8af7
        test     bl, 0x20
        je       short L_8af7
        mov      dword ptr [g_dispatchSave1498], edx
    L_8af7:
        mov      ecx, dword ptr [g_gsmOut4]
        test     ecx, ecx
        jne      short L_8b07
        mov      dword ptr [g_dispatchSave1498], edx
    L_8b07:
        movsx    ecx, word ptr [eax*8 + g_dispatchSave573]
        add      ecx, -0x14
        cmp      ecx, 3
        ja       L_8ba2
        jmp      dword ptr [ecx*4 + L_a30_jmptbl]
    L_8b22:
        test     esi, esi
        jne      short L_8ba2
        test     bl, 0x10
        je       short L_8ba2
        mov      dword ptr [g_dispatchSave1498], edx
        mov      dword ptr [g_gsmDirty1], 1
        jmp      short L_8ba2
    L_8b3d:
        test     esi, esi
        jne      short L_8ba2
        test     bl, 0x10
        je       short L_8ba2
        mov      dword ptr [g_dispatchSave1498], edx
        mov      dword ptr [g_gsmDirty2], 1
        jmp      short L_8ba2
    L_8b58:
        test     esi, esi
        jne      short L_8ba2
        test     bl, 0x10
        je       short L_8ba2
        mov      dword ptr [g_dispatchSave1498], edx
        mov      dword ptr [g_gsmDirty3], 1
        jmp      short L_8ba2
    L_8b73:
        test     esi, esi
        jne      short L_8ba2
        test     bl, 0x10
        je       short L_8ba2
        mov      dword ptr [g_dispatchSave1498], edx
        jmp      short L_8ba2
    L_8b84:
        push     OFFSET g_gsmHelperBase
        push     0
        mov      dword ptr [g_dispatchSave1498], 2
        call     Menu_FindNextSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1483], eax
    L_8ba2:
        push     eax
        push     OFFSET g_gsmHelperBase
        call     DrawMenu
        mov      eax, dword ptr [g_dispatchSave1498]
        add      esp, 8
        pop      esi
        pop      ebx
        ret
    L_a30_jmptbl:
        _emit    0x73
        _emit    0x8b
        _emit    0x4b
        _emit    0x00
        _emit    0x22
        _emit    0x8b
        _emit    0x4b
        _emit    0x00
        _emit    0x3d
        _emit    0x8b
        _emit    0x4b
        _emit    0x00
        _emit    0x58
        _emit    0x8b
        _emit    0x4b
        _emit    0x00
    }
}
#endif

