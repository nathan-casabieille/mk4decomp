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

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_frameCounter (*(unsigned int *)MK4_VA(unsigned int, 0x7af930u))
#define g_gameStateResult (*(unsigned int *)MK4_VA(unsigned int, 0x7af918u))
#define g_logicStepFlag (*(unsigned int *)MK4_VA(unsigned int, 0x54381cu))
#define g_mode4PauseGate (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd78u))
#endif


/*
 * @addr 0x004b26d0
 */
void GameLogicStep(void)
{
    ++g_frameCounter;
    g_gameStateResult = GameStateMachine(0);
    if (g_gameStateResult == 0) {
        Input_TickPlayers();
    }
    Audio_UpdateChannels();
    Audio_TimerTick();
    if (Renderer_GetMode() == 4 && g_mode4PauseGate == 0) {
        GameStateMachine(8);
    } else {
        XformChainAdvance();
        GameTick(0);
    }
    g_logicStepFlag = 0;
}
