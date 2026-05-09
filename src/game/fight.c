/**
 * Fight subsystem outer dispatcher.
 *
 * Three iterations of (set up entity-queue head pair + extra
 * scratch pointers, call FightFrameStep_Inner, check pause flag).
 * Pairs come from a 6-entry array; extras come from three triples
 * of unrelated tables.
 */
#include "game/tick.h"
#include "engine/scenegraph.h"

/*
 * @addr 0x0045c5c0
 *
 * Naked + __asm: each setup is a fixed 5-store block of packed_ptrs
 * (`mov reg, imm32; shr reg, 2; mov [global], reg`) and the third
 * setup tail-jmps into FightFrameStep_Inner instead of call+ret.
 * Pure C wouldn't naturally produce the precise register rotation
 * across the three setups (eax/ecx/edx cycling on each one).
 */
__declspec(naked) void FightFrameStep(void)
{
    __asm {
        ; ===== Setup #1 =====
        mov     eax, offset g_fightGroupHeads
        mov     ecx, offset g_fightGroupHeads + 4
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     edx, offset g_fightTableA0
        mov     eax, offset g_fightTableB0
        mov     ecx, offset g_fightTableC0
        shr     edx, 2
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_fightGroupHead], ecx
        call    FightFrameStep_Inner
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     done                             ; long form: > 127 bytes forward
        ; ===== Setup #2 =====
        mov     edx, offset g_fightGroupHeads + 8
        mov     eax, offset g_fightGroupHeads + 12
        shr     edx, 2
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, offset g_fightTableA1
        mov     edx, offset g_fightTableB1
        mov     eax, offset g_fightTableC1
        shr     ecx, 2
        shr     edx, 2
        shr     eax, 2
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_eventQueueTotal], edx
        mov     dword ptr [g_fightGroupHead], eax
        call    FightFrameStep_Inner
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     done_short
        ; ===== Setup #3 (tail-jmp) =====
        mov     ecx, offset g_fightGroupHeads + 16
        mov     edx, offset g_fightGroupHeads + 20
        shr     ecx, 2
        shr     edx, 2
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_xformEntityIdx], edx
        mov     eax, offset g_fightTableA2
        mov     ecx, offset g_fightTableB2
        mov     edx, offset g_fightTableC2
        shr     eax, 2
        shr     ecx, 2
        shr     edx, 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_eventQueueTotal], ecx
        mov     dword ptr [g_fightGroupHead], edx
        jmp     FightFrameStep_Inner
done_short:
done:
        ret
    }
}
