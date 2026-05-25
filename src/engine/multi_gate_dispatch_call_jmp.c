/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x004779d0 (80b)
 *   Multi-gate dispatch: if [0x54355c]: ret;
 *   if [0x543714] == 0: tail-call F1 then jmp T (no early ret);
 *   if [0x53a408] != 0: call F1, pause → ret;
 *   if [0x537e88] != 0: tail-call F2.
 */
extern unsigned int g_data_0054355c;
extern unsigned int g_data_00543714;
extern unsigned int g_active_0053a408;
extern unsigned int g_active_00537e88;
extern void DualSeqBranchInit_00477a20(void);
extern void YRiseSpawnerCluster_00477bd0(void);
__declspec(naked) void MultiGateDispatchCallJmp_004779d0(void) {
    __asm {
        mov     eax, dword ptr [g_data_0054355c]
        test    eax, eax
        _emit   75h
        _emit   33h
        mov     eax, dword ptr [g_data_00543714]
        test    eax, eax
        _emit   74h
        _emit   2bh
        mov     eax, dword ptr [g_active_0053a408]
        test    eax, eax
        _emit   74h
        _emit   0eh
        call    DualSeqBranchInit_00477a20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        mov     eax, dword ptr [g_active_00537e88]
        test    eax, eax
        _emit   74h
        _emit   0ah
        call    YRiseSpawnerCluster_00477bd0
        mov     eax, dword ptr [g_framePauseFlag]
ret_label:
        ret
        call    DualSeqBranchInit_00477a20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     ret_label
        jmp     YRiseSpawnerCluster_00477bd0
    }
}
