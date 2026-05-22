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
 *   mov     [g_scaledInit_00542044], eax
 *   shr     ecx, 2
 *   mov     [g_eventQueueEnd], ecx
 *   mov     ecx, [eax*4 + 0x34]
 *   push    edx
 *   mov     [g_acc_00542078], ecx
 *   call    Func
 *   add     esp, 4
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_acc_00542078;

extern void ChainPickArgScaledInit_0045dd90(int);

/* @addr 0x0045dcd0 */
extern void ChainPickArgScaledInit_0045dd90(void);

__declspec(naked) void DualPlayerSetupCall_0045dcd0(void) {
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
        mov     dword ptr [g_scaledInit_00542044], eax
        shr     ecx, 2
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     ecx, dword ptr [eax*4 + 0x34]
        push    edx
        mov     dword ptr [g_acc_00542078], ecx
        call    ChainPickArgScaledInit_0045dd90
        add     esp, 4
        ret
    }
}

/* @addr 0x0045dd30 */
__declspec(naked) void DualPlayerSetupCall_0045dd30(void) {
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
        mov     dword ptr [g_scaledInit_00542044], eax
        shr     ecx, 2
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     ecx, dword ptr [eax*4 + 0x34]
        push    edx
        mov     dword ptr [g_acc_00542078], ecx
        call    ChainPickArgScaledInit_0045dd90
        add     esp, 4
        ret
    }
}

