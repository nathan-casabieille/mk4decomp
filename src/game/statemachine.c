/**
 * Top-level menu/game-mode state machine.
 *
 * Per-frame entry. Looks up g_gameState (0..0x1c) in a 29-entry
 * byte-to-jump-index table, then dispatches via a 16-entry indirect
 * jump table. State 0 (main menu) takes a sub-dispatch on `cmd`
 * (1..8) via a second 8-entry jump table; the chosen handler sets
 * a new state and falls through to an audio re-arm.  Other states
 * call into per-state helpers (Helper_GSM_VS / Tournament / ...).
 * The shared tail (default:) updates g_gsmActiveFlag = (state != 0).
 */
#include "game/statemachine.h"

/*
 * @addr 0x004b6340
 *
 * Naked + __asm: the byte-to-jump-index switch idiom MSVC emits
 * for sparse switches, plus the dispatch tables (which live as
 * data in the same .text section after the function), plus the
 * fall-through "set_state -> check_state -> audio re-arm" tail
 * are all hand-tuned.  Pure C wouldn't reproduce identically.
 */
__declspec(naked) s32 GameStateMachine(s32 cmd)
{
    __asm {
        mov     ecx, dword ptr [g_gameState]
        push    esi
        xor     esi, esi
        cmp     ecx, 0x1c
        ja      tail
        xor     eax, eax
        mov     al, byte ptr [ecx + g_gsmByteTable]
        jmp     dword ptr [eax*4 + g_gsmJumpTable1]
state_main_menu:
        mov     edx, dword ptr [esp + 8]
        lea     eax, [edx - 1]
        cmp     eax, 7
        ja      check_state
        jmp     dword ptr [eax*4 + g_gsmJumpTable2]
sub_practice:
        mov     ecx, 8
        jmp     SHORT set_state
sub_options:
        mov     ecx, 9
        jmp     SHORT set_state
sub_settings:
        mov     ecx, 0xa
        jmp     SHORT set_state
sub_arcade:
        mov     ecx, 5
        jmp     SHORT set_state
sub_options_gated:
        cmp     dword ptr [g_gsmFlag], esi
        je      SHORT check_state
        mov     ecx, 6
        jmp     SHORT set_state
sub_credits:
        mov     ecx, 0xb
        jmp     SHORT set_state
sub_config:
        mov     ecx, 0xc
        jmp     SHORT set_state
sub_settings_alt:
        mov     ecx, 7
set_state:
        mov     dword ptr [g_gameState], ecx
check_state:
        cmp     ecx, esi
        je      tail
        push    0x4a
        call    Helper_AudioRelease2
        add     esp, 4
        push    -1
        push    -1
        push    0x4a
        call    Helper_AudioStartMusic
        add     esp, 0xc
        jmp     tail
case_handle_event:
        call    Helper_GSM_HandleEvent
        cmp     eax, 0x45
        jne     SHORT check_18
        mov     dword ptr [g_gameState], 4
check_18:
        cmp     eax, 0x18
        jne     SHORT check_19
        mov     dword ptr [g_gameState], eax
check_19:
        cmp     eax, 0x19
        jne     SHORT check_1a
        mov     dword ptr [g_gameState], eax
check_1a:
        cmp     eax, 0x1a
        jne     SHORT check_1b
        mov     dword ptr [g_gameState], eax
check_1b:
        cmp     eax, 0x1b
        jne     SHORT check_1c
        mov     dword ptr [g_gameState], eax
check_1c:
        cmp     eax, 0x1c
        jne     tail
        mov     dword ptr [g_gameState], eax
        jmp     tail
case_vs:
        call    Helper_GSM_VS
        jmp     SHORT share_check_3
case_tour:
        call    Helper_GSM_Tournament
        jmp     SHORT share_check_3
case_practice_vs:
        call    Helper_GSM_Practice
        jmp     SHORT share_check_3
case_options_vs:
        call    Helper_GSM_Options
share_check_3:
        cmp     eax, 3
        jne     tail
        mov     dword ptr [g_gameState], 6
        jmp     tail
case_config:
        call    Helper_GSM_Config
        cmp     eax, 3
        jne     tail
        mov     eax, dword ptr [g_gsmStateAa4]
        mov     dword ptr [g_gameState], 6
        push    eax
        call    Helper_GSM_PlayMusic
        add     esp, 4
        jmp     tail
case_sub18:
        call    Helper_GSM_Sub18
        jmp     SHORT share_check_45
case_sub19:
        call    Helper_GSM_Sub19
        jmp     SHORT share_check_45
case_sub1a:
        call    Helper_GSM_Sub1A
        jmp     SHORT share_check_45
case_sub1b:
        call    Helper_GSM_Sub1B
        jmp     SHORT share_check_45
case_sub1c:
        call    Helper_GSM_Sub1C
        jmp     SHORT share_check_45
case_other1:
        call    Helper_GSM_Sub_Other1
        jmp     SHORT share_check_45
case_other2:
        call    Helper_GSM_Sub_Other2
share_check_45:
        cmp     eax, 0x45
        ; orig short-form jne (75 66); MASM's __asm picks long-form
        ; for forward jcc, so _emit it.
        _emit   75h
        _emit   66h
        mov     dword ptr [g_gameState], 4
        ; orig short-form jmp
        _emit   0EBh
        _emit   5Ah
case_drawmenu:
        push    -1
        push    esi
        call    DrawMenu
        add     esp, 8
        test    eax, eax
        ; orig short-form jne (75 4b)
        _emit   75h
        _emit   4Bh
        mov     dword ptr [g_gameState], esi
        call    Helper_GSM_Reset
        mov     ecx, dword ptr [g_gsmDirty1]
        mov     eax, 1
        cmp     ecx, esi
        je      SHORT check_dirty2
        mov     dword ptr [g_gsmDirty1], esi
        mov     dword ptr [g_gsmOut1], eax
check_dirty2:
        cmp     dword ptr [g_gsmDirty2], esi
        je      SHORT check_dirty3
        mov     dword ptr [g_gsmDirty2], esi
        mov     dword ptr [g_gsmOut2], eax
check_dirty3:
        cmp     dword ptr [g_gsmDirty3], esi
        je      SHORT tail
        mov     dword ptr [g_gsmDirty3], esi
        mov     dword ptr [g_gsmOut3], eax
tail:
        mov     eax, dword ptr [g_gameState]
        xor     ecx, ecx
        cmp     eax, esi
        mov     dword ptr [g_gsmOut4], esi
        setne   cl
        mov     dword ptr [g_gsmActiveFlag], ecx
        pop     esi
        ret
    }
}
