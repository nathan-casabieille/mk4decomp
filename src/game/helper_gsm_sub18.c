/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/*
 * Menu_HelpScreen - 255b menu navigation dispatcher.
 *   al = g_menuHelpScreenFlags. If bit 0 not set: set it, push (0, &table); TableSearchAsc; store eax.
 *   Else: load saved g_dispatchSave1473. Switch on g_dispatchSave1494 = 0/2/0x45/default.
 *     If 0 → set 0x00ab4364=2 + DrawMenu epilogue.
 *     If 2 → call Menu_PollNavInput(1); check bit 0x8000; bl&1: TableSearchDesc; check esi;
 *       bl&2: TableSearchAsc again; bl&0x10: load word from g_dispatchSave516[eax*8] → g_dispatchSave1494;
 *       bl&0x20: g_dispatchSave1494=0x45.
 *     If 0x45 → set 0x00ab4364=0.
 *     Final epilogue: push (eax, &g_gsmSub18Base); DrawMenu; pop ret.
 */
extern unsigned int g_menuHelpScreenFlags;
extern unsigned int g_gsmSub18Base;
extern unsigned int g_dispatchSave1473;
extern unsigned int g_dispatchSave1494;
extern void DrawMenu(void);
extern void Menu_PollNavInput(void);
extern void Menu_FindNextSelectable(void);
extern void Menu_FindPrevSelectable(void);

extern unsigned int g_dispatchSave516;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int Menu_HelpScreen(void)

{
  uint uVar1;
  
  if ((g_menuHelpScreenFlags & 1) == 0) {
    g_menuHelpScreenFlags = g_menuHelpScreenFlags | 1;
    g_dispatchSave1473 = Menu_FindNextSelectable(0,&g_gsmSub18Base);
  }
  if (g_dispatchSave1494 == 0) {
    g_dispatchSave1494 = 2;
  }
  else if (g_dispatchSave1494 == 2) {
    uVar1 = Menu_PollNavInput(1);
    if (((uVar1 & 0x8000) == 0) && ((uVar1 & 1) != 0)) {
      g_dispatchSave1473 = Menu_FindPrevSelectable(g_dispatchSave1473,&g_gsmSub18Base);
    }
    if ((uVar1 & 0x8000) == 0) {
      if ((uVar1 & 2) != 0) {
        g_dispatchSave1473 = Menu_FindNextSelectable(g_dispatchSave1473,&g_gsmSub18Base);
      }
      if ((uVar1 & 0x10) != 0) {
        g_dispatchSave1494 = (int)*(short *)(&g_dispatchSave516 + g_dispatchSave1473 * 8);
      }
      if ((uVar1 & 0x20) != 0) {
        g_dispatchSave1494 = 0x45;
      }
    }
  }
  else if (g_dispatchSave1494 == 0x45) {
    g_dispatchSave1494 = 0;
  }
  DrawMenu(&g_gsmSub18Base,g_dispatchSave1473);
  return g_dispatchSave1494;
}
#else
__declspec(naked) void Menu_HelpScreen(void)
{
    __asm
    {
        mov     al, byte ptr [g_menuHelpScreenFlags]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_skipSet
        mov     bl, al
        push    offset g_gsmSub18Base
        or      bl, 1
        push    0
        mov     byte ptr [g_menuHelpScreenFlags], bl
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1473], eax
        jmp     short L_afterFirst
    L_skipSet:
        mov     eax, dword ptr [g_dispatchSave1473]
    L_afterFirst:
        mov     ecx, dword ptr [g_dispatchSave1494]
        sub     ecx, 0
        je      L_case0
        sub     ecx, 2
        je      short L_case2
        sub     ecx, 0x43
        jne     L_drawMenu
        mov     dword ptr [g_dispatchSave1494], 0
        jmp     L_drawMenu
    L_case2:
        push    1
        call    Menu_PollNavInput
        mov     ebx, eax
        add     esp, 4
        mov     esi, ebx
        and     esi, 0x8000
        jne     short L_skipDesc
        test    bl, 1
        je      short L_skipDesc
        mov     eax, dword ptr [g_dispatchSave1473]
        push    offset g_gsmSub18Base
        push    eax
        call    Menu_FindPrevSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1473], eax
        jmp     short L_checkBit2
    L_skipDesc:
        mov     eax, dword ptr [g_dispatchSave1473]
    L_checkBit2:
        test    esi, esi
        jne     short L_drawMenu
        test    bl, 2
        je      short L_checkBit4
        push    offset g_gsmSub18Base
        push    eax
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1473], eax
    L_checkBit4:
        test    esi, esi
        jne     short L_drawMenu
        test    bl, 0x10
        je      short L_checkBit5
        movsx   ecx, word ptr [eax*8 + g_dispatchSave516]
        mov     dword ptr [g_dispatchSave1494], ecx
    L_checkBit5:
        test    esi, esi
        jne     short L_drawMenu
        test    bl, 0x20
        je      short L_drawMenu
        mov     dword ptr [g_dispatchSave1494], 0x45
        jmp     short L_drawMenu
    L_case0:
        mov     dword ptr [g_dispatchSave1494], 2
    L_drawMenu:
        push    eax
        push    offset g_gsmSub18Base
        call    DrawMenu
        mov     eax, dword ptr [g_dispatchSave1494]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}
#endif

