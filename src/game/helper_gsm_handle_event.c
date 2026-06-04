/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_gsmEventBase;
extern unsigned int g_dispatchSave870;
extern unsigned int g_dispatchSave1478;
extern unsigned int g_dispatchSave1484;
extern unsigned int g_dispatchSave1493;
extern void DrawMenu(void);
extern void Menu_PollNavInput(void);
extern void Menu_FindNextSelectable(void);
extern void Menu_FindPrevSelectable(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int Helper_GSM_HandleEvent(void)

{
  uint uVar1;
  
  if ((g_dispatchSave1484 & 1) == 0) {
    g_dispatchSave1484 = g_dispatchSave1484 | 1;
    g_dispatchSave1478 = Menu_FindNextSelectable(0,&g_gsmEventBase);
  }
  switch(g_dispatchSave1493) {
  case 0:
    g_dispatchSave1493 = 2;
    break;
  case 2:
    uVar1 = Menu_PollNavInput(1);
    if (((uVar1 & 0x8000) == 0) && ((uVar1 & 1) != 0)) {
      g_dispatchSave1478 = Menu_FindPrevSelectable(g_dispatchSave1478,&g_gsmEventBase);
    }
    if ((uVar1 & 0x8000) == 0) {
      if ((uVar1 & 2) != 0) {
        g_dispatchSave1478 = Menu_FindNextSelectable(g_dispatchSave1478,&g_gsmEventBase);
      }
      if ((uVar1 & 0x10) != 0) {
        g_dispatchSave1493 = (int)*(short *)(&g_dispatchSave870 + g_dispatchSave1478 * 8);
      }
      if ((uVar1 & 0x20) != 0) {
        g_dispatchSave1493 = 0x45;
      }
    }
    break;
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x45:
    g_dispatchSave1493 = 0;
  }
  DrawMenu(&g_gsmEventBase,g_dispatchSave1478);
  return g_dispatchSave1493;
}
#else
__declspec(naked) void Helper_GSM_HandleEvent(void)
{
    __asm {
        mov      al, byte ptr [g_dispatchSave1484]
        push     ebx
        test     al, 1
        push     esi
        jne      short L_84fc
        mov      bl, al
        push     OFFSET g_gsmEventBase
        or       bl, 1
        push     0
        mov      byte ptr [g_dispatchSave1484], bl
        call     Menu_FindNextSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1478], eax
        jmp      short L_8501
    L_84fc:
        mov      eax, dword ptr [g_dispatchSave1478]
    L_8501:
        mov      ecx, dword ptr [g_dispatchSave1493]
        cmp      ecx, 0x45
        ja       L_85ba
        xor      edx, edx
        mov      dl, byte ptr [ecx + L_4d0_byidx]
        jmp      dword ptr [edx*4 + L_4d0_jmptbl]
    L_851f:
        mov      dword ptr [g_dispatchSave1493], 2
        jmp      L_85ba
    L_852e:
        push     1
        call     Menu_PollNavInput
        mov      ebx, eax
        add      esp, 4
        mov      esi, ebx
        and      esi, 0x8000
        jne      short L_8563
        test     bl, 1
        je       short L_8563
        mov      eax, dword ptr [g_dispatchSave1478]
        push     OFFSET g_gsmEventBase
        push     eax
        call     Menu_FindPrevSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1478], eax
        jmp      short L_8568
    L_8563:
        mov      eax, dword ptr [g_dispatchSave1478]
    L_8568:
        test     esi, esi
        jne      short L_85ba
        test     bl, 2
        je       short L_8584
        push     OFFSET g_gsmEventBase
        push     eax
        call     Menu_FindNextSelectable
        add      esp, 8
        mov      dword ptr [g_dispatchSave1478], eax
    L_8584:
        test     esi, esi
        jne      short L_85ba
        test     bl, 0x10
        je       short L_859b
        movsx    ecx, word ptr [eax*8 + g_dispatchSave870]
        mov      dword ptr [g_dispatchSave1493], ecx
    L_859b:
        test     esi, esi
        jne      short L_85ba
        test     bl, 0x20
        je       short L_85ba
        mov      dword ptr [g_dispatchSave1493], 0x45
        jmp      short L_85ba
    L_85b0:
        mov      dword ptr [g_dispatchSave1493], 0
    L_85ba:
        push     eax
        push     OFFSET g_gsmEventBase
        call     DrawMenu
        mov      eax, dword ptr [g_dispatchSave1493]
        add      esp, 8
        pop      esi
        pop      ebx
        ret
    L_4d0_jmptbl:
        _emit 0x1f
        _emit 0x85
        _emit 0x4b
        _emit 0x00
        _emit 0x2e
        _emit 0x85
        _emit 0x4b
        _emit 0x00
        _emit 0xb0
        _emit 0x85
        _emit 0x4b
        _emit 0x00
        _emit 0xb0
        _emit 0x85
        _emit 0x4b
        _emit 0x00
        _emit 0xba
        _emit 0x85
        _emit 0x4b
        _emit 0x00
    L_4d0_byidx:
        _emit 0x00
        _emit 0x04
        _emit 0x01
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x02
        _emit 0x02
        _emit 0x02
        _emit 0x02
        _emit 0x02
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x04
        _emit 0x03
    }
}
#endif

