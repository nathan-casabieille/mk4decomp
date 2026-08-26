/**
 * 2 "compare-with-player1 + dual scaled init + store" helpers (66b).
 *
 * Pattern:
 *   mov     edx, [g_fightGroupHead]
 *   push    esi
 *   mov     esi, [g_player1NodeIdx]
 *   mov     eax, IMM_A
 *   mov     ecx, IMM_B
 *   shr     eax, 2
 *   shr     ecx, 2
 *   cmp     edx, esi
 *   mov     [g_currentNodeIdx], eax
 *   mov     [g_xformEntityIdx], ecx
 *   je      .same
 *   mov     eax, ecx                     ; not p1: A = B
 *   mov     [g_currentNodeIdx], eax
 * .same:
 *   mov     ecx, [g_walkCallback]
 *   pop     esi
 *   mov     [eax*4 + 0], ecx              ; SIB+0 store
 *   ret
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_phaseThunkArr3;
extern unsigned int g_phaseThunkArr2;
extern unsigned int g_roundResetSlot;
extern unsigned int g_phaseThunkArr;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_phaseThunkArr (*(unsigned int *)MK4_VA(unsigned int, 0x53a474u))
#define g_phaseThunkArr2 (*(unsigned int *)MK4_VA(unsigned int, 0x53a518u))
#define g_phaseThunkArr3 (*(unsigned int *)MK4_VA(unsigned int, 0x53a1a0u))
#define g_player1NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_roundResetSlot (*(unsigned int *)MK4_VA(unsigned int, 0x53a3e4u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


/* @addr 0x00433d30
 *   NON-COAXABLE: MSVC assigns eax to the later-declared symbol (0x0053a518)
 *   but orig has the lower-address symbol (0x0053a1a0) in eax. Register
 *   allocation order is address-dependent, not controllable from C source.
 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void CmpP1DualInitStore_00433d30(void)

{
  int iVar1;
  
  (g_currentNodeIdx) = 0x14e868;
  g_eventQueuePending = 0x14e946;
  iVar1 = 0x14e868;
  if (g_cj_0054205c != g_player1NodeIdx) {
    (g_currentNodeIdx) = 0x14e946;
    iVar1 = 0x14e946;
  }
  MK4_NODE_AT(undefined4, iVar1, 0) = g_walkCallback;
  return;
}
#else
__declspec(naked) void CmpP1DualInitStore_00433d30(void) {
    __asm {
        mov     edx, dword ptr [g_fightGroupHead]
        push    esi
        mov     esi, dword ptr [g_player1NodeIdx]
        mov     eax, 0x0053a1a0
        mov     ecx, 0x0053a518
        shr     eax, 2
        shr     ecx, 2
        cmp     edx, esi
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        je      short L_p1same_a
        mov     eax, ecx
        mov     dword ptr [g_currentNodeIdx], eax
    L_p1same_a:
        mov     ecx, dword ptr [g_walkCallback]
        pop     esi
        mov     dword ptr [eax*4 + 0], ecx
        ret
    }
}
#endif

/* @addr 0x00482ab0
 *   NON-COAXABLE: same pattern - MSVC assigns eax to higher-address symbol
 *   (0x0053a474 > 0x0053a3e4), but orig has lower in eax. Same blocker.
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void CmpP1DualInitStore_00482ab0(void)

{
  int iVar1;
  
  (g_currentNodeIdx) = 0x14e8f9;
  g_eventQueuePending = 0x14e91d;
  iVar1 = 0x14e8f9;
  if (g_cj_0054205c != g_player1NodeIdx) {
    (g_currentNodeIdx) = 0x14e91d;
    iVar1 = 0x14e91d;
  }
  MK4_NODE_AT(undefined4, iVar1, 0) = g_walkCallback;
  return;
}
#else
__declspec(naked) void CmpP1DualInitStore_00482ab0(void) {
    __asm {
        mov     edx, dword ptr [g_fightGroupHead]
        push    esi
        mov     esi, dword ptr [g_player1NodeIdx]
        mov     eax, 0x0053a3e4
        mov     ecx, 0x0053a474
        shr     eax, 2
        shr     ecx, 2
        cmp     edx, esi
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        je      short L_p1same_b
        mov     eax, ecx
        mov     dword ptr [g_currentNodeIdx], eax
    L_p1same_b:
        mov     ecx, dword ptr [g_walkCallback]
        pop     esi
        mov     dword ptr [eax*4 + 0], ecx
        ret
    }
}
#endif
