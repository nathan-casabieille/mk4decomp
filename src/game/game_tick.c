/**
 * Per-frame fight-mode tick.
 *
 * Calls the fight frame-step + dispatch + post-fight chain, then
 * gates a 4-player overlay update (each player checks state field
 * +0x30 == player_index, plus a global probe ptr, then either OR
 * 0x10 into [+0x34] high byte or AND with mask). Tail interpolates
 * three "axis" sticky lows toward 0x8000 in 1/8 increments and
 * resets g_gameMode if it was -1 (sentinel).
 */
#include "game/tick.h"
#include "engine/scenegraph.h"
#include "audio/sound.h"   /* DebugStub_NoOp_A/B */

/*
 * @addr 0x0041fd70
 *
 * Naked + __asm: cascade of pause-flag checks (call X; cmp
 * [g_framePauseFlag], 0; jne exit) plus 4 near-identical per-player
 * branches with shared structure but different table addresses,
 * plus the tail's three axis-interpolations (load word, sub from
 * 0x8000, sar 3, add back) reuses ax/cx/edx in a way pure C
 * wouldn't reproduce.
 */
__declspec(naked) void GameTick(s32 param)
{
    __asm {
        mov     eax, dword ptr [g_gameMode]
        push    ebx
        push    esi
        push    edi
        test    eax, eax
        je      SHORT after_pause_check
        cmp     dword ptr [g_gtPauseMode], 2
        jne     SHORT pause_alt
        call    DebugStub_NoOp_B
        jmp     SHORT after_pause_check
pause_alt:
        call    DebugStub_NoOp_A
after_pause_check:
        mov     eax, dword ptr [g_gtOtherFlag]
        mov     ebx, 1
        cmp     eax, ebx
        jne     SHORT after_other_flag
        cmp     byte ptr [g_gtModeFlag], bl
        jne     SHORT other_alt
        call    DebugStub_NoOp_A
        jmp     SHORT after_other_flag
other_alt:
        call    DebugStub_NoOp_B
after_other_flag:
        cmp     dword ptr [g_gtConfig4f], 2
        je      SHORT after_config_check
        mov     eax, dword ptr [g_gtState438]
        test    eax, eax
        je      SHORT after_config_check
        cmp     byte ptr [g_gtModeFlag], bl
        jne     SHORT skip_noop_a
        call    DebugStub_NoOp_A
skip_noop_a:
        cmp     byte ptr [g_gtModeFlag], 2
        jne     SHORT after_config_check
        call    DebugStub_NoOp_B
after_config_check:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     SHORT skip_fight_step
        call    FightFrameStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     exit_early
        inc     dword ptr [g_gtFightTickCounter]
        call    DispatchEventQueue
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     exit_early
skip_fight_step:
        call    Helper_TickFrame_Misc
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     exit_early
        call    Helper_TickFrame_PostFight
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     exit_early
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     SHORT skip_player_tick
        mov     eax, dword ptr [g_player1NodeIdx]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      SHORT skip_per_player_call
        call    Helper_PerPlayerTick
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     exit_early
skip_per_player_call:
        call    Helper_PostPlayerTick
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     exit_early
        call    Helper_TickFrameTail
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     exit_early
skip_player_tick:
        mov     eax, dword ptr [esp + 0x10]
        test    eax, eax
        jne     sticky_check
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     edi, 0xffffefff
        test    eax, eax
        mov     esi, 0xffff0000
        mov     edx, 0x501
        je      SHORT p2_check
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x30]
        cmp     ecx, ebx
        jne     SHORT p2_check
        mov     ecx, dword ptr [g_gtPlayerProbe1]
        test    ecx, ecx
        je      SHORT p2_check
        cmp     dword ptr [ecx*4 + 0x74], edx
        je      SHORT p2_check
        mov     cl, byte ptr [g_gtPlayerEnabled]
        test    cl, cl
        je      SHORT p1_clear
        cmp     dword ptr [eax*4 + 0x58], esi
        jle     SHORT p1_clear
        mov     ecx, dword ptr [eax*4 + 0x34]
        or      ch, 0x10
        mov     dword ptr [g_walkCallback], ecx
        jmp     SHORT p1_done
p1_clear:
        mov     ecx, dword ptr [eax*4 + 0x34]
        and     ecx, edi
p1_done:
        mov     dword ptr [eax*4 + 0x34], ecx
p2_check:
        mov     eax, dword ptr [g_player2NodeIdx]
        test    eax, eax
        je      SHORT p3_check
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x30]
        cmp     ecx, 2
        jne     SHORT p3_check
        mov     ecx, dword ptr [g_gtPlayerProbe2]
        test    ecx, ecx
        je      SHORT p3_check
        cmp     dword ptr [ecx*4 + 0x74], edx
        je      SHORT p3_check
        mov     cl, byte ptr [g_gtPlayerEnabled]
        test    cl, cl
        je      SHORT p2_clear
        cmp     dword ptr [eax*4 + 0x58], esi
        jle     SHORT p2_clear
        mov     ecx, dword ptr [eax*4 + 0x34]
        or      ch, 0x10
        mov     dword ptr [g_walkCallback], ecx
        jmp     SHORT p2_done
p2_clear:
        mov     ecx, dword ptr [eax*4 + 0x34]
        and     ecx, edi
p2_done:
        mov     dword ptr [eax*4 + 0x34], ecx
p3_check:
        mov     eax, dword ptr [g_player3NodeIdx]
        test    eax, eax
        je      SHORT p4_check
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x30]
        cmp     ecx, 3
        jne     SHORT p4_check
        mov     cl, byte ptr [g_gtPlayerEnabled]
        test    cl, cl
        je      SHORT p3_clear
        cmp     dword ptr [eax*4 + 0x58], esi
        jle     SHORT p3_clear
        mov     ecx, dword ptr [eax*4 + 0x34]
        or      ch, 0x10
        mov     dword ptr [g_walkCallback], ecx
        jmp     SHORT p3_done
p3_clear:
        mov     ecx, dword ptr [eax*4 + 0x34]
        and     ecx, edi
p3_done:
        mov     dword ptr [eax*4 + 0x34], ecx
p4_check:
        mov     eax, dword ptr [g_player4NodeIdx]
        test    eax, eax
        je      SHORT skip_overlay
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x30]
        cmp     ecx, 4
        jne     SHORT skip_overlay
        mov     cl, byte ptr [g_gtPlayerEnabled]
        test    cl, cl
        je      SHORT p4_clear
        cmp     dword ptr [eax*4 + 0x58], esi
        jle     SHORT p4_clear
        mov     ecx, dword ptr [eax*4 + 0x34]
        or      ch, 0x10
        mov     dword ptr [g_walkCallback], ecx
        jmp     SHORT p4_done
p4_clear:
        mov     ecx, dword ptr [eax*4 + 0x34]
        and     ecx, edi
p4_done:
        mov     dword ptr [eax*4 + 0x34], ecx
skip_overlay:
        call    FrameFinalize
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     SHORT exit_early
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     SHORT sticky_check
        mov     ax, word ptr [g_gtAxisX]
        xor     ecx, ecx
        mov     cx, ax
        mov     edx, 0x8000
        sub     edx, ecx
        xor     ecx, ecx
        sar     edx, 3
        add     ax, dx
        mov     edx, 0x8000
        mov     word ptr [g_gtAxisX], ax
        mov     ax, word ptr [g_gtAxisY]
        mov     cx, ax
        sub     edx, ecx
        xor     ecx, ecx
        sar     edx, 3
        add     ax, dx
        mov     edx, 0x8000
        mov     word ptr [g_gtAxisY], ax
        mov     ax, word ptr [g_gtAxisZ]
        mov     cx, ax
        sub     edx, ecx
        sar     edx, 3
        add     ax, dx
        mov     word ptr [g_gtAxisZ], ax
sticky_check:
        cmp     dword ptr [g_gameMode], -1
        jne     SHORT exit_early
        mov     dword ptr [g_gameMode], 0
exit_early:
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
