/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* Menu_Direct3DUnavailableDialog - sister of 0x4b8630 for 0x004f5050 menu. */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_menuD3dUnavailFlags;
extern unsigned int g_gsmVar2;
extern unsigned int g_dispatchSave868;
extern unsigned int g_dispatchSave1486;
extern unsigned int g_dispatchSave1496;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_dispatchSave1486 (*(unsigned int *)MK4_VA(unsigned int, 0xab4304u))
#define g_dispatchSave1496 (*(unsigned int *)MK4_VA(unsigned int, 0xab436cu))
#define g_dispatchSave868 (*(unsigned int *)MK4_VA(unsigned int, 0x4f5054u))
#define g_gsmVar2 (*(unsigned int *)MK4_VA(unsigned int, 0x4f5050u))
#define g_menuD3dUnavailFlags (*(unsigned int *)MK4_VA(unsigned int, 0xab42ecu))
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
int Menu_Direct3DUnavailableDialog(void)

{
  uint uVar1;
  
  if ((g_menuD3dUnavailFlags & 1) == 0) {
    g_menuD3dUnavailFlags = g_menuD3dUnavailFlags | 1;
    g_dispatchSave1486 = Menu_FindNextSelectable(0,&g_gsmVar2);
  }
  if (g_dispatchSave1496 == 0) {
    g_dispatchSave1496 = 2;
  }
  else if (g_dispatchSave1496 == 2) {
    uVar1 = Menu_PollNavInput(1);
    if (((uVar1 & 0x8000) == 0) && ((uVar1 & 1) != 0)) {
      g_dispatchSave1486 = Menu_FindPrevSelectable(g_dispatchSave1486,&g_gsmVar2);
    }
    if ((uVar1 & 0x8000) == 0) {
      if ((uVar1 & 2) != 0) {
        g_dispatchSave1486 = Menu_FindNextSelectable(g_dispatchSave1486,&g_gsmVar2);
      }
      if ((uVar1 & 0x10) != 0) {
        g_dispatchSave1496 = (int)*(short *)((unsigned char *)&g_dispatchSave868 + g_dispatchSave1486 * 8);
      }
      if ((uVar1 & 0x20) != 0) {
        g_dispatchSave1496 = 0x45;
      }
    }
  }
  else if (g_dispatchSave1496 == 0x45) {
    g_dispatchSave1496 = 0;
  }
  DrawMenu(&g_gsmVar2,g_dispatchSave1486);
  return g_dispatchSave1496;
}
#else
__declspec(naked) void Menu_Direct3DUnavailableDialog(void)
{
    __asm
    {
        mov     al, byte ptr [g_menuD3dUnavailFlags]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_b83_skipSet
        mov     bl, al
        push    offset g_gsmVar2
        or      bl, 1
        push    0
        mov     byte ptr [g_menuD3dUnavailFlags], bl
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1486], eax
        jmp     short L_b83_afterFirst
    L_b83_skipSet:
        mov     eax, dword ptr [g_dispatchSave1486]
    L_b83_afterFirst:
        mov     ecx, dword ptr [g_dispatchSave1496]
        sub     ecx, 0
        je      L_b83_case0
        sub     ecx, 2
        je      short L_b83_case2
        sub     ecx, 0x43
        jne     L_b83_drawMenu
        mov     dword ptr [g_dispatchSave1496], 0
        jmp     L_b83_drawMenu
    L_b83_case2:
        push    1
        call    Menu_PollNavInput
        mov     ebx, eax
        add     esp, 4
        mov     esi, ebx
        and     esi, 0x8000
        jne     short L_b83_skipDesc
        test    bl, 1
        je      short L_b83_skipDesc
        mov     eax, dword ptr [g_dispatchSave1486]
        push    offset g_gsmVar2
        push    eax
        call    Menu_FindPrevSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1486], eax
        jmp     short L_b83_checkBit2
    L_b83_skipDesc:
        mov     eax, dword ptr [g_dispatchSave1486]
    L_b83_checkBit2:
        test    esi, esi
        jne     short L_b83_drawMenu
        test    bl, 2
        je      short L_b83_checkBit4
        push    offset g_gsmVar2
        push    eax
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1486], eax
    L_b83_checkBit4:
        test    esi, esi
        jne     short L_b83_drawMenu
        test    bl, 0x10
        je      short L_b83_checkBit5
        movsx   ecx, word ptr [eax*8 + g_dispatchSave868]
        mov     dword ptr [g_dispatchSave1496], ecx
    L_b83_checkBit5:
        test    esi, esi
        jne     short L_b83_drawMenu
        test    bl, 0x20
        je      short L_b83_drawMenu
        mov     dword ptr [g_dispatchSave1496], 0x45
        jmp     short L_b83_drawMenu
    L_b83_case0:
        mov     dword ptr [g_dispatchSave1496], 2
    L_b83_drawMenu:
        push    eax
        push    offset g_gsmVar2
        call    DrawMenu
        mov     eax, dword ptr [g_dispatchSave1496]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}
#endif

