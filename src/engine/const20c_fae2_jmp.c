/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00486510 (25b)
 *   mov     [g_walkCallback], 0x20c
 *   mov     [g_eventQueueCurrent], -1   ; sort of, the imm = "ff ff ff ff" via loop?
 *   actually:
 *   c7 05 6c 20 54 00 0c 02 00 00       mov [g_walkCallback], 0x20c
 *   c7 05 70 20 54 00 e2 fa ff ff       mov [g_eventQueueCurrent], 0xfffffae2
 *   e9 27 a8 ff ff                       jmp T
 *
 * Wait the actual bytes: c7 05 70 20 54 00 e2 fa ff ff has imm=0xfffffae2,
 * which is -0x51e in signed.
 */
extern void TwoPhaseInstallScaledPackedPtr_00480d50(void);
void Const20cFae2Jmp_00486510(void) {
    g_walkCallback = (void(*)(void))0x20c;
    g_eventQueueCurrent = 0xfffffae2;
    TwoPhaseInstallScaledPackedPtr_00480d50();
}
