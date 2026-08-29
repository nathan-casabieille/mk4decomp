/**
 * ScaledLitAddJmp - 0x00480fb0 (38b): the state-table dispatcher for the
 * round-setup band. It takes an index from 0x54206c, looks up the code
 * table at 0x4ef4d0 (76+ entries), leaves the target VA in
 * g_xformEntityIdx and tail-jumps into ScaledChainCallPauseSetJmp, which
 * installs it as the controller's callback.
 *
 * This is the only route to AppInit_Misc7's packed state machine: index
 * 185 is 0x465ae0, the state that installs 0x465c00, which is the sole
 * caller of the animation track installer. With this function stubbed,
 * nothing could ever enter that machine.
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void ScaledChainCallPauseSetJmp(void);

#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_walkSlot6c     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))

void ScaledLitAddJmp(void)
{
    unsigned int slot = (0x4ef4d0u >> 2) + g_walkSlot6c;

    g_currentNodeIdx = slot;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(slot * 4);
    ScaledChainCallPauseSetJmp();        /* jmp in the original */
}

#endif /* NON_MATCHING */
