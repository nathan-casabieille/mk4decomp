/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_gsmSubOther1Base;
extern unsigned int g_dispatchSave572;
extern unsigned int g_dispatchSave1482;
extern unsigned int g_dispatchSave1485;
extern unsigned int g_dispatchSave1499;
/* Real signatures. The auto-generated placeholders all said `(void)`, but the
 * original pushes two stack args for the two selectable-scanners and one for
 * the poll, and every caller uses the returned value. */
extern int          DrawMenu(void *menu, int sel);
extern unsigned int Menu_PollNavInput(int mode);
extern unsigned int Menu_FindNextSelectable(int cur, void *menu);
extern unsigned int Menu_FindPrevSelectable(int cur, void *menu);
extern void Helper_GSM_PlayMusic(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int Menu_ColorDepthErrorDialog(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((g_dispatchSave1482 & 1) == 0) {
    g_dispatchSave1482 = g_dispatchSave1482 | 1;
    g_dispatchSave1485 = Menu_FindNextSelectable(0,&g_gsmSubOther1Base);
  }
  if (g_dispatchSave1499 == 0) {
    g_dispatchSave1499 = 2;
  }
  else if (g_dispatchSave1499 == 2) {
    uVar1 = Menu_PollNavInput(1);
    uVar3 = uVar1 & 0x8000;
    if ((uVar3 == 0) && ((uVar1 & 1) != 0)) {
      g_dispatchSave1485 = Menu_FindPrevSelectable(g_dispatchSave1485,&g_gsmSubOther1Base);
    }
    if ((uVar3 == 0) && ((uVar1 & 2) != 0)) {
      g_dispatchSave1485 = Menu_FindNextSelectable(g_dispatchSave1485,&g_gsmSubOther1Base);
    }
    if ((uVar3 == 0) && ((uVar1 & 0x20) != 0)) {
      g_dispatchSave1499 = 0x45;
    }
    iVar2 = Renderer_GetMode();
    if ((iVar2 != 4) || (g_mode4PauseGate != 0)) {
      g_dispatchSave1499 = 0x45;
    }
    switch(*(undefined2 *)((unsigned char *)&g_dispatchSave572 + g_dispatchSave1485 * 8)) {
    case 0xd:
      if ((uVar3 == 0) && ((uVar1 & 0x10) != 0)) {
        Helper_GSM_PlayMusic(1);
        g_dispatchSave1499 = 0x45;
      }
      break;
    case 0xe:
      if ((uVar3 == 0) && ((uVar1 & 0x10) != 0)) {
        Helper_GSM_PlayMusic(2);
        g_dispatchSave1499 = 0x45;
      }
      break;
    case 0xf:
      if ((uVar3 == 0) && ((uVar1 & 0x10) != 0)) {
        Helper_GSM_PlayMusic(3);
        g_dispatchSave1499 = 0x45;
      }
      break;
    case 0x10:
      if ((uVar3 == 0) && ((uVar1 & 0x10) != 0)) {
        Helper_GSM_PlayMusic(5);
        g_dispatchSave1499 = 0x45;
      }
    }
  }
  else if (g_dispatchSave1499 == 0x45) {
    g_dispatchSave1499 = 0;
  }
  DrawMenu(&g_gsmSubOther1Base,g_dispatchSave1485);
  return g_dispatchSave1499;
}
#else
__declspec(naked) void Menu_ColorDepthErrorDialog(void)
{
    __asm {
        mov      al, byte ptr [g_dispatchSave1482]
        push     ebx
        push     esi
        push     edi
        test     al, 1
        jne      short L_8bfb
        mov      bl, al
        push     OFFSET g_gsmSubOther1Base
        or       bl, 1
        push     0
        mov      byte ptr [g_dispatchSave1482], bl
        call     Menu_FindNextSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1485], eax
    L_8bfb:
        mov      eax, dword ptr [g_dispatchSave1499]
        sub      eax, 0
        je       L_8d31
        sub      eax, 2
        je       short L_8c26
        sub      eax, 0x43
        jne      L_8d3b
        mov      dword ptr [g_dispatchSave1499], 0
        jmp      L_8d3b
    L_8c26:
        push     1
        call     Menu_PollNavInput
        mov      ebx, eax
        add      esp, 4
        mov      esi, ebx
        and      esi, 0x8000
        jne      short L_8c59
        test     bl, 1
        je       short L_8c59
        mov      eax, dword ptr [g_dispatchSave1485]
        push     OFFSET g_gsmSubOther1Base
        push     eax
        call     Menu_FindPrevSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1485], eax
    L_8c59:
        test     esi, esi
        jne      short L_8c7b
        test     bl, 2
        je       short L_8c7b
        mov      ecx, dword ptr [g_dispatchSave1485]
        push     OFFSET g_gsmSubOther1Base
        push     ecx
        call     Menu_FindNextSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1485], eax
    L_8c7b:
        test     esi, esi
        mov      edi, 0x45
        jne      short L_8c8f
        test     bl, 0x20
        je       short L_8c8f
        mov      dword ptr [g_dispatchSave1499], edi
    L_8c8f:
        call     Renderer_GetMode
        cmp      eax, 4
        jne      short L_8ca2
        mov      eax, dword ptr [g_mode4PauseGate]
        test     eax, eax
        je       short L_8ca8
    L_8ca2:
        mov      dword ptr [g_dispatchSave1499], edi
    L_8ca8:
        mov      edx, dword ptr [g_dispatchSave1485]
        movsx    eax, word ptr [edx*8 + g_dispatchSave572]
        add      eax, -0xd
        cmp      eax, 3
        ja       short L_8d3b
        jmp      dword ptr [eax*4 + L_bd0_jmptbl]
    L_8cc5:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     1
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_dispatchSave1499], edi
        jmp      short L_8d3b
    L_8ce0:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     2
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_dispatchSave1499], edi
        jmp      short L_8d3b
    L_8cfb:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     3
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_dispatchSave1499], edi
        jmp      short L_8d3b
    L_8d16:
        test     esi, esi
        jne      short L_8d3b
        test     bl, 0x10
        je       short L_8d3b
        push     5
        call     Helper_GSM_PlayMusic
        add      esp, 4
        mov      dword ptr [g_dispatchSave1499], edi
        jmp      short L_8d3b
    L_8d31:
        mov      dword ptr [g_dispatchSave1499], 2
    L_8d3b:
        mov      eax, dword ptr [g_dispatchSave1485]
        push     eax
        push     OFFSET g_gsmSubOther1Base
        call     DrawMenu
        mov      eax, dword ptr [g_dispatchSave1499]
        add      esp, 8
        pop      edi
        pop      esi
        pop      ebx
        ret
        nop
    L_bd0_jmptbl:
        _emit    0xc5
        _emit    0x8c
        _emit    0x4b
        _emit    0x00
        _emit    0xe0
        _emit    0x8c
        _emit    0x4b
        _emit    0x00
        _emit    0xfb
        _emit    0x8c
        _emit    0x4b
        _emit    0x00
        _emit    0x16
        _emit    0x8d
        _emit    0x4b
        _emit    0x00
    }
}
#endif

