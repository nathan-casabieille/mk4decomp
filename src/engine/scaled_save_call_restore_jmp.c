/**
 * 2 "scaled save + call + pause restore + tail-jmp" helpers (50b).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [eax*4 + 0x30]
 *   mov     [g_currentNodeIdx], ecx
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     edx, [g_A]                         ; reload A
 *   mov     [g_currentNodeIdx], edx       ; restore base
 *   jmp     Tail
 * .ret:
 *   ret
 *
 * Saves a scaled base derived from g_A, calls a worker, then if no
 * pause occurred, restores the scaled base from g_A again and tail-
 * jumps into the continue handler.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern void InstallSelfMagicShift(void);
extern void MStackPush2ChainLLInsert(void);

/* @addr 0x00472f40 */
void ScaledSaveCallRestoreJmp_InstallSelfMagicShift_then_MStackPush2ChainLLInsert_00472f40(void) {
    g_currentNodeIdx = *(unsigned int*)(g_eventQueueEnd * 4 + 0x30);
    InstallSelfMagicShift();
    if (g_framePauseFlag) return;
    g_currentNodeIdx = g_eventQueueEnd;
    MStackPush2ChainLLInsert();
}

/* @addr 0x00472f80 */
void ScaledSaveCallRestoreJmp_InstallSelfMagicShift_then_MStackPush2ChainLLInsert_00472f80(void) {
    g_currentNodeIdx = *(unsigned int*)(g_eventQueueIdx * 4 + 0x30);
    InstallSelfMagicShift();
    if (g_framePauseFlag) return;
    g_currentNodeIdx = g_eventQueueIdx;
    MStackPush2ChainLLInsert();
}
