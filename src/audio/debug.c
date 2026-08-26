/**
 * Audio debug stubs.
 *
 * Two empty placeholder functions left in by Eurocom. Likely
 * compiled-out debug callbacks (DSound trace hooks, perhaps).
 * Both compile to a single `ret` (0xc3).
 */
#include "audio/sound.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#endif


/* @addr 0x004a4150 */
void DebugStub_NoOp_B(void)
{
}

/* @addr 0x004a4170 */
void DebugStub_NoOp_A(void)
{
}
