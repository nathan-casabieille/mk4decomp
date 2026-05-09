/**
 * Per-frame gameplay tick.
 *
 * GameLogicStep is the 60 Hz fixed-step entry point; it bumps the
 * frame counter, runs the menu state machine + audio updates, then
 * dispatches either the SW-Win pause path (mode 4 + gate clear)
 * or the regular fight tick.
 */
#include "game/tick.h"
#include "game/statemachine.h"
#include "engine/scenegraph.h"
#include "audio/sound.h"

/*
 * @addr 0x004b26d0
 *
 * The compiler reorders push 0 between the load of g_frameCounter
 * and the inc/store, and tail-duplicates the "store 0 to logicStepFlag
 * then ret" epilogue across both branches. Pinning the exact byte
 * sequence in inline asm.
 */
__declspec(naked) void GameLogicStep(void)
{
    __asm {
        mov     ecx, [g_frameCounter]
        push    0
        inc     ecx
        mov     [g_frameCounter], ecx
        call    GameStateMachine
        add     esp, 4
        mov     [g_gameStateResult], eax
        test    eax, eax
        jne     skip_rebuild
        call    GameStateMachineMaybeRebuild
skip_rebuild:
        call    Audio_UpdateChannels
        call    Audio_TimerTick
        call    Renderer_GetMode
        cmp     eax, 4
        jne     else_path
        mov     eax, [g_mode4PauseGate]
        test    eax, eax
        jne     else_path
        push    8
        call    GameStateMachine
        add     esp, 4
        mov     [g_logicStepFlag], 0
        ret
else_path:
        call    XformChainAdvance
        push    0
        call    GameTick
        add     esp, 4
        mov     [g_logicStepFlag], 0
        ret
    }
}
