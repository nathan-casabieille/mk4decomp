/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_phaseThunkInst;
extern unsigned int g_dispatchSave537;
extern unsigned int g_dispatchSave536;
extern unsigned int g_dispatchSave630;
extern unsigned int g_dispatchSave629;
extern unsigned int g_dispatchSave535;
extern unsigned int g_dispatchSave534;
extern unsigned int g_dispatchSave628;
extern unsigned int g_dispatchSave627;
extern unsigned int g_renderer2_var7;
extern unsigned int g_renderer2_var6;
extern unsigned int g_dispatchSave518;
extern unsigned int g_dispatchSave517;
extern unsigned int g_dispatchSave533;
extern unsigned int g_dispatchSave532;
extern unsigned int g_dispatchSave626;
extern unsigned int g_dispatchSave625;
extern unsigned int g_renderer2_var5;
extern u32 g_demoModeFlag;
extern unsigned int g_dispatchSave27;
extern unsigned int g_dispatchSave26;
extern unsigned int g_dispatchSave25;
extern unsigned int g_dispatchVar39;
extern u32 g_appInitFlag1;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_appInitFlag1 (*(unsigned int *)MK4_VA(unsigned int, 0x7af920u))
#define g_demoModeFlag (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd7cu))
#define g_dispatchSave1323 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4e98u))
#define g_dispatchSave25 (*(unsigned int *)MK4_VA(unsigned int, 0x543370u))
#define g_dispatchSave26 (*(unsigned int *)MK4_VA(unsigned int, 0x54336cu))
#define g_dispatchSave27 (*(unsigned int *)MK4_VA(unsigned int, 0x543368u))
#define g_dispatchSave517 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4df4u))
#define g_dispatchSave518 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4df0u))
#define g_dispatchSave532 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dfcu))
#define g_dispatchSave533 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4df8u))
#define g_dispatchSave534 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4ddcu))
#define g_dispatchSave535 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dd8u))
#define g_dispatchSave536 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dccu))
#define g_dispatchSave537 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dc8u))
#define g_dispatchSave625 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4e04u))
#define g_dispatchSave626 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4e00u))
#define g_dispatchSave627 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4de4u))
#define g_dispatchSave628 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4de0u))
#define g_dispatchSave629 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dd4u))
#define g_dispatchSave630 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dd0u))
#define g_dispatchVar39 (*(unsigned int *)MK4_VA(unsigned int, 0x54357cu))
#define g_fightTableC0 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50a4u))
#define g_fightTableC1 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50a8u))
#define g_fightTableC2 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50b0u))
#define g_gameStateResult (*(unsigned int *)MK4_VA(unsigned int, 0x7af918u))
#define g_phaseThunkInst (*(unsigned int *)MK4_VA(unsigned int, 0x4d50acu))
#define g_renderer2_var5 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4e98u))
#define g_renderer2_var6 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4decu))
#define g_renderer2_var7 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4de8u))
#endif

/* Real signatures - the auto-generated placeholders said `(void)` and the twin
 * calls all three with a player/key argument (and uses GetAsyncKey's result). */
extern s32  Input_GetAsyncKey(s32 vk);
extern void Input_PollPlayerJoystick(s32 player);
extern void Input_PollPlayerKeyboard(s32 player);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Input_TickPlayers(void)

{
  int iVar1;
  
  g_fightTableC2 = 0;
  g_fightTableC0 = 0;
  g_fightTableC1 = 0;
  g_phaseThunkInst = 0;
  if ((g_demoModeFlag != 0) && (g_gameStateResult == 0)) {
    Input_PollPlayerKeyboard(0);
    Input_PollPlayerKeyboard(1);
    Input_PollPlayerJoystick(0);
    Input_PollPlayerJoystick(1);
    if (g_dispatchSave1323 != 0) {
      if ((((g_fightTableC2 == 0) && (g_fightTableC0 == 0)) && (g_fightTableC1 == 0)) &&
         (g_phaseThunkInst == 0)) {
        iVar1 = Input_GetAsyncKey(0x1b);
        if (iVar1 == 0) {
          iVar1 = Input_GetAsyncKey(0x20);
          if (iVar1 == 0) {
            iVar1 = Input_GetAsyncKey(0xd);
            if (iVar1 == 0) {
              g_dispatchSave1323 = 0;
            }
          }
        }
      }
      g_fightTableC2 = 0;
      g_fightTableC0 = 0;
      g_fightTableC1 = 0;
      g_phaseThunkInst = 0;
    }
    if (g_appInitFlag1 != 0) {
      *MK4_VA(uint, g_renderer2_var6) = *MK4_VA(uint, g_renderer2_var6) & ~g_renderer2_var7;
      *MK4_VA(uint, g_dispatchSave517) = *MK4_VA(uint, g_dispatchSave517) & ~g_dispatchSave518;
    }
  }
  if ((*MK4_VA(uint, g_dispatchSave536) & g_dispatchSave537) != 0) {
    *MK4_VA(uint, g_dispatchSave534) = *MK4_VA(uint, g_dispatchSave534) & ~g_dispatchSave535;
  }
  if ((*MK4_VA(uint, g_dispatchSave629) & g_dispatchSave630) != 0) {
    *MK4_VA(uint, g_dispatchSave627) = *MK4_VA(uint, g_dispatchSave627) & ~g_dispatchSave628;
  }
  if ((*MK4_VA(uint, g_renderer2_var6) & g_renderer2_var7) != 0) {
    *MK4_VA(uint, g_dispatchSave532) = *MK4_VA(uint, g_dispatchSave532) & ~g_dispatchSave533;
  }
  if ((*MK4_VA(uint, g_dispatchSave517) & g_dispatchSave518) != 0) {
    *MK4_VA(uint, g_dispatchSave625) = *MK4_VA(uint, g_dispatchSave625) & ~g_dispatchSave626;
  }
  g_phaseThunkInst = ~g_phaseThunkInst;
  g_fightTableC2 = ~g_fightTableC2;
  g_fightTableC0 = ~g_fightTableC0;
  g_fightTableC1 = ~g_fightTableC1;
  g_dispatchSave27 = g_phaseThunkInst;
  g_dispatchVar39 = g_fightTableC2;
  g_dispatchSave26 = g_fightTableC0;
  g_dispatchSave25 = g_fightTableC1;
  return;
}
#else
__declspec(naked) void Input_TickPlayers(void)
{
    __asm {
        mov     eax, dword ptr [g_demoModeFlag]
        push    esi
        xor     esi, esi
        cmp     eax, esi
        mov     dword ptr [g_fightTableC2], esi
        mov     dword ptr [g_fightTableC0], esi
        mov     dword ptr [g_fightTableC1], esi
        mov     dword ptr [g_phaseThunkInst], esi
        je      L_idep_after_clear_masks
        cmp     dword ptr [g_gameStateResult], esi
        jne     L_idep_after_clear_masks
        push    esi
        call    Input_PollPlayerKeyboard
        add     esp, 4
        push    1
        call    Input_PollPlayerKeyboard
        add     esp, 4
        push    esi
        call    Input_PollPlayerJoystick
        add     esp, 4
        push    1
        call    Input_PollPlayerJoystick
        mov     eax, dword ptr [g_renderer2_var5]
        add     esp, 4
        cmp     eax, esi
        je      L_idep_pause_gate2
        cmp     dword ptr [g_fightTableC2], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_fightTableC0], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_fightTableC1], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_phaseThunkInst], esi
        jne     L_idep_clear_loop
        push    0x1B
        call    Input_GetAsyncKey
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        push    0x20
        call    Input_GetAsyncKey
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        push    0x0D
        call    Input_GetAsyncKey
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        mov     dword ptr [g_renderer2_var5], esi
    L_idep_clear_loop:
        mov     dword ptr [g_fightTableC2], esi
        mov     dword ptr [g_fightTableC0], esi
        mov     dword ptr [g_fightTableC1], esi
        mov     dword ptr [g_phaseThunkInst], esi
    L_idep_pause_gate2:
        cmp     dword ptr [g_appInitFlag1], esi
        je      L_idep_after_clear_masks
        mov     eax, dword ptr [g_renderer2_var6]
        mov     ecx, dword ptr [g_renderer2_var7]
        not     ecx
        mov     edx, dword ptr [eax]
        and     edx, ecx
        mov     dword ptr [eax], edx
        mov     eax, dword ptr [g_dispatchSave517]
        mov     edx, dword ptr [g_dispatchSave518]
        mov     ecx, dword ptr [eax]
        not     edx
        and     ecx, edx
        mov     dword ptr [eax], ecx
    L_idep_after_clear_masks:
        mov     ecx, dword ptr [g_dispatchSave536]
        mov     eax, dword ptr [g_dispatchSave537]
        test    dword ptr [ecx], eax
        je      L_idep_skip1
        mov     eax, dword ptr [g_dispatchSave534]
        mov     edx, dword ptr [g_dispatchSave535]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip1:
        mov     ecx, dword ptr [g_dispatchSave629]
        mov     eax, dword ptr [g_dispatchSave630]
        test    dword ptr [ecx], eax
        je      L_idep_skip2
        mov     eax, dword ptr [g_dispatchSave627]
        mov     edx, dword ptr [g_dispatchSave628]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip2:
        mov     ecx, dword ptr [g_renderer2_var6]
        mov     eax, dword ptr [g_renderer2_var7]
        test    dword ptr [ecx], eax
        je      L_idep_skip3
        mov     eax, dword ptr [g_dispatchSave532]
        mov     edx, dword ptr [g_dispatchSave533]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip3:
        mov     ecx, dword ptr [g_dispatchSave517]
        mov     eax, dword ptr [g_dispatchSave518]
        test    dword ptr [ecx], eax
        je      L_idep_skip4
        mov     eax, dword ptr [g_dispatchSave625]
        mov     edx, dword ptr [g_dispatchSave626]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip4:
        mov     esi, dword ptr [g_phaseThunkInst]
        mov     eax, dword ptr [g_fightTableC2]
        mov     ecx, dword ptr [g_fightTableC0]
        mov     edx, dword ptr [g_fightTableC1]
        not     esi
        not     eax
        not     ecx
        not     edx
        mov     dword ptr [g_phaseThunkInst], esi
        mov     dword ptr [g_dispatchSave27], esi
        mov     dword ptr [g_fightTableC2], eax
        mov     dword ptr [g_fightTableC0], ecx
        mov     dword ptr [g_fightTableC1], edx
        mov     dword ptr [g_dispatchVar39], eax
        mov     dword ptr [g_dispatchSave26], ecx
        mov     dword ptr [g_dispatchSave25], edx
        pop     esi
        ret
    }
}
#endif

