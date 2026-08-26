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

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_gameState (*(unsigned int *)MK4_VA(unsigned int, 0xab438cu))
#define g_gsmActiveFlag (*(unsigned int *)MK4_VA(unsigned int, 0xab4334u))
#define g_gsmDirty1 (*(unsigned int *)MK4_VA(unsigned int, 0xab4374u))
#define g_gsmDirty2 (*(unsigned int *)MK4_VA(unsigned int, 0xab4378u))
#define g_gsmDirty3 (*(unsigned int *)MK4_VA(unsigned int, 0xab437cu))
#define g_gsmFlag (*(unsigned int *)MK4_VA(unsigned int, 0x543930u))
#define g_gsmOut1 (*(unsigned int *)MK4_VA(unsigned int, 0x543818u))
#define g_gsmOut2 (*(unsigned int *)MK4_VA(unsigned int, 0x543814u))
#define g_gsmOut3 (*(unsigned int *)MK4_VA(unsigned int, 0x543810u))
#define g_gsmOut4 (*(unsigned int *)MK4_VA(unsigned int, 0x543820u))
#define g_gsmStateAa4 (*(unsigned int *)MK4_VA(unsigned int, 0x543aa4u))
#endif


extern void Helper_TitleAudioReset(void);   /* 0x004b5840, see audio/sound.h */

/*
 * @addr 0x004b6340
 *
 * Naked + __asm: the byte-to-jump-index switch idiom MSVC emits
 * for sparse switches, plus the dispatch tables (which live as
 * data in the same .text section after the function), plus the
 * fall-through "set_state -> check_state -> audio re-arm" tail
 * are all hand-tuned.  Pure C wouldn't reproduce identically.
 */
#ifdef NON_MATCHING
/* Portable twin. The two dispatch tables read out as:
 *
 *   byte table @0x4b6580, state 0..0x1c -> case index; every state not listed
 *   below maps to case 15, which is the shared tail.
 *   jump table @0x4b6540, case index -> block.
 *   jump table @0x4b65a0, (cmd - 1) for state 0 -> the new state.
 *
 * State 0's sub-dispatch is the subtle one. ECX still holds g_gameState (zero,
 * since we are in state 0) all the way to the audio check, so both the
 * out-of-range `cmd` and the g_gsmFlag == 0 path reach that check with ECX
 * still zero and re-arm nothing. Only a case that actually assigned a new
 * state gets the audio. `next` models that register.
 *
 * The state-6 block is six SEQUENTIAL ifs in the original, not else-ifs; the
 * values are mutually exclusive anyway, so it is written as it reads.
 *
 * Both range checks (`cmp ecx, 0x1c` and `cmp eax, 7`) are `ja`, i.e. UNSIGNED,
 * which is what rejects a negative cmd.
 */
s32 GameStateMachine(s32 cmd)
{
    unsigned int state = (unsigned int)g_gameState;
    unsigned int next;
    s32 r;

    switch (state > 0x1cu ? 0xffffffffu : state) {
    case 0:                                     /* main menu: sub-dispatch */
        next = 0;
        if ((unsigned int)(cmd - 1) <= 7u) {
            switch (cmd) {
            case 1: next = 5; break;
            case 2: if (g_gsmFlag != 0) next = 6; break;
            case 3: next = 7; break;
            case 4: next = 9; break;
            case 5: next = 0xa; break;
            case 6: next = 8; break;
            case 7: next = 0xb; break;
            case 8: next = 0xc; break;
            }
            if (next != 0)
                g_gameState = (s32)next;
        }
        if (next != 0) {
            Helper_AudioRelease(0x4a);
            Audio_PlaySoundId(0x4a, -1, -1);
        }
        break;

    case 4:                                     /* title / attract */
        if (DrawMenu(0, -1) == 0) {
            g_gameState = 0;
            Helper_TitleAudioReset();
            if (g_gsmDirty1 != 0) { g_gsmDirty1 = 0; g_gsmOut1 = 1; }
            if (g_gsmDirty2 != 0) { g_gsmDirty2 = 0; g_gsmOut2 = 1; }
            if (g_gsmDirty3 != 0) { g_gsmDirty3 = 0; g_gsmOut3 = 1; }
        }
        break;

    case 6:                                     /* in-game event pump */
        r = Helper_GSM_HandleEvent();
        if (r == 0x45) g_gameState = 4;
        if (r == 0x18) g_gameState = r;
        if (r == 0x19) g_gameState = r;
        if (r == 0x1a) g_gameState = r;
        if (r == 0x1b) g_gameState = r;
        if (r == 0x1c) g_gameState = r;
        break;

    /* modal dialogs and menus: 0x45 means "back to the title" */
    case 5:  r = Menu_HelpScreen();                    goto menu_done;
    case 7:  r = Menu_PauseMenu();                     goto menu_done;
    case 8:  r = Menu_GlideUnavailableDialog();        goto menu_done;
    case 9:  r = Menu_Direct3DUnavailableDialog();     goto menu_done;
    case 10: r = Menu_DirectDrawUnavailableDialog();   goto menu_done;
    case 11: r = Menu_InsertCDDialog();                goto menu_done;
    case 12: r = Menu_ColorDepthErrorDialog();
    menu_done:
        if (r == 0x45)
            g_gameState = 4;
        break;

    /* mode screens: 3 means "start the match" */
    case 24: r = Helper_GSM_VS();          goto mode_done;
    case 25: r = Helper_GSM_Tournament();  goto mode_done;
    case 26: r = Helper_GSM_Practice();    goto mode_done;
    case 27: r = Helper_GSM_Options();
    mode_done:
        if (r == 3)
            g_gameState = 6;
        break;

    case 28:                                    /* config screen */
        if (Helper_GSM_Config() == 3) {
            s32 music = g_gsmStateAa4;

            g_gameState = 6;
            Helper_GSM_PlayMusic(music);
        }
        break;

    default:
        break;
    }

    g_gsmOut4 = 0;
    g_gsmActiveFlag = (g_gameState != 0);
    return g_gameState;
}
#else
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
        call    Audio_PlaySoundId
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
        call    Menu_HelpScreen
        jmp     SHORT share_check_45
case_sub19:
        call    Menu_GlideUnavailableDialog
        jmp     SHORT share_check_45
case_sub1a:
        call    Menu_Direct3DUnavailableDialog
        jmp     SHORT share_check_45
case_sub1b:
        call    Menu_DirectDrawUnavailableDialog
        jmp     SHORT share_check_45
case_sub1c:
        call    Menu_PauseMenu
        jmp     SHORT share_check_45
case_other1:
        call    Menu_ColorDepthErrorDialog
        jmp     SHORT share_check_45
case_other2:
        call    Menu_InsertCDDialog
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
        /* dispatch tables (3-byte align NOP, two jump tables, byte-index table)
         * absorbed from orig 0x4b653d..0x4b65c0; absolute VAs valid only when this
         * function is placed at 0x4b6340. */
        _emit    0x8d
        _emit    0x49
        _emit    0x00
        _emit    0x61
        _emit    0x63
        _emit    0x4b
        _emit    0x00
        _emit    0xc9
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0x89
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0xdd
        _emit    0x63
        _emit    0x4b
        _emit    0x00
        _emit    0xa5
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0x90
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0x97
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0x9e
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0xb3
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0xac
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0x2c
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0x33
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0x3a
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0x41
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0x5e
        _emit    0x64
        _emit    0x4b
        _emit    0x00
        _emit    0x23
        _emit    0x65
        _emit    0x4b
        _emit    0x00
        _emit    0x00
        _emit    0x0f
        _emit    0x0f
        _emit    0x0f
        _emit    0x01
        _emit    0x02
        _emit    0x03
        _emit    0x04
        _emit    0x05
        _emit    0x06
        _emit    0x07
        _emit    0x08
        _emit    0x09
        _emit    0x0f
        _emit    0x0f
        _emit    0x0f
        _emit    0x0f
        _emit    0x0f
        _emit    0x0f
        _emit    0x0f
        _emit    0x0f
        _emit    0x0f
        _emit    0x0f
        _emit    0x0f
        _emit    0x0a
        _emit    0x0b
        _emit    0x0c
        _emit    0x0d
        _emit    0x0e
        _emit    0x8d
        _emit    0x49
        _emit    0x00
        _emit    0x89
        _emit    0x63
        _emit    0x4b
        _emit    0x00
        _emit    0x90
        _emit    0x63
        _emit    0x4b
        _emit    0x00
        _emit    0xad
        _emit    0x63
        _emit    0x4b
        _emit    0x00
        _emit    0x7b
        _emit    0x63
        _emit    0x4b
        _emit    0x00
        _emit    0x82
        _emit    0x63
        _emit    0x4b
        _emit    0x00
        _emit    0x74
        _emit    0x63
        _emit    0x4b
        _emit    0x00
        _emit    0x9f
        _emit    0x63
        _emit    0x4b
        _emit    0x00
        _emit    0xa6
        _emit    0x63
        _emit    0x4b
        _emit    0x00
    }
}
#endif
