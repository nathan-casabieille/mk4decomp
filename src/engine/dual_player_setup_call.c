/**
 * 2 "dual-player setup + scaled load + 1-arg call" helpers (86b).
 *
 * Pattern:
 *   mov     edx, [g_player2NodeIdx]
 *   mov     eax, IMM_A
 *   shr     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     eax, [g_player1NodeIdx]
 *   mov     ecx, IMM_B
 *   mov     [g_fightGroupHead], eax
 *   mov     eax, [g_gtPlayerProbe*]
 *   mov     [g_eventQueueIdx], edx
 *   mov     edx, [esp+4]
 *   mov     [g_currentNodeIdx], eax
 *   shr     ecx, 2
 *   mov     [g_eventQueueEnd], ecx
 *   mov     ecx, [eax*4 + 0x34]
 *   push    edx
 *   mov     [g_chainAccumCur], ecx
 *   call    Func
 *   add     esp, 4
 *   ret
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_chainAccumCur;

extern void ChainPickArgScaledInit(int);

/* @addr 0x0045dcd0 */
extern void ChainPickArgScaledInit(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DualPlayerSetupCall_ChainPickArgScaledInit_0045dcd0(undefined4 param_1)

{
  g_dualD = 0x14aac6;
  g_cj_0054205c = g_player1NodeIdx;
  g_cj_00542058 = g_player2NodeIdx;
  (g_currentNodeIdx) = g_dualB_00538038;
  g_cj_00542054 = 0x14e8a8;
  g_chainAccumCur = MK4_NODE_AT(undefined4, g_dualB_00538038, 0x34);
  ChainPickArgScaledInit(param_1);
  return;
}
#else
__declspec(naked) void DualPlayerSetupCall_ChainPickArgScaledInit_0045dcd0(void) {
    __asm {
        mov     edx, dword ptr [g_player2NodeIdx]
        mov     eax, 0x0052ab18
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     ecx, 0x0053a2a0
        mov     dword ptr [g_fightGroupHead], eax
        mov     eax, dword ptr [g_gtPlayerProbe2]
        mov     dword ptr [g_eventQueueIdx], edx
        mov     edx, dword ptr [esp + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        shr     ecx, 2
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     ecx, dword ptr [eax*4 + 0x34]
        push    edx
        mov     dword ptr [g_chainAccumCur], ecx
        call    ChainPickArgScaledInit
        add     esp, 4
        ret
    }
}
#endif

/* @addr 0x0045dd30 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DualPlayerSetupCall_ChainPickArgScaledInit_0045dd30(undefined4 param_1)

{
  g_dualD = 0x150780;
  g_cj_0054205c = g_player2NodeIdx;
  g_cj_00542058 = g_player1NodeIdx;
  (g_currentNodeIdx) = g_dualB_0053803c;
  g_cj_00542054 = 0x14e8be;
  g_chainAccumCur = MK4_NODE_AT(undefined4, g_dualB_0053803c, 0x34);
  ChainPickArgScaledInit(param_1);
  return;
}
#else
__declspec(naked) void DualPlayerSetupCall_ChainPickArgScaledInit_0045dd30(void) {
    __asm {
        mov     edx, dword ptr [g_player1NodeIdx]
        mov     eax, 0x00541e00
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     eax, dword ptr [g_player2NodeIdx]
        mov     ecx, 0x0053a2f8
        mov     dword ptr [g_fightGroupHead], eax
        mov     eax, dword ptr [g_gtPlayerProbe1]
        mov     dword ptr [g_eventQueueIdx], edx
        mov     edx, dword ptr [esp + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        shr     ecx, 2
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     ecx, dword ptr [eax*4 + 0x34]
        push    edx
        mov     dword ptr [g_chainAccumCur], ecx
        call    ChainPickArgScaledInit
        add     esp, 4
        ret
    }
}
#endif

