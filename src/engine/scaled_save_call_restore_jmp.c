/**
 * 2 "scaled save + call + pause restore + tail-jmp" helpers (50b).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [eax*4 + 0x30]
 *   mov     [g_scaledInit_00542044], ecx
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     edx, [g_A]                         ; reload A
 *   mov     [g_scaledInit_00542044], edx       ; restore base
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

extern unsigned int g_scaledInit_00542044;
extern void InstallSelfMagicShift_00472fe0(void);
extern void MStackPush2ChainLLInsert_00406790(void);

/* @addr 0x00472f40 */
void ScaledSaveCallRestoreJmp_00472f40(void) {
    g_scaledInit_00542044 = *(unsigned int*)(g_eventQueueEnd * 4 + 0x30);
    InstallSelfMagicShift_00472fe0();
    if (g_framePauseFlag) return;
    g_scaledInit_00542044 = g_eventQueueEnd;
    MStackPush2ChainLLInsert_00406790();
}

/* @addr 0x00472f80 */
void ScaledSaveCallRestoreJmp_00472f80(void) {
    g_scaledInit_00542044 = *(unsigned int*)(g_eventQueueIdx * 4 + 0x30);
    InstallSelfMagicShift_00472fe0();
    if (g_framePauseFlag) return;
    g_scaledInit_00542044 = g_eventQueueIdx;
    MStackPush2ChainLLInsert_00406790();
}
