/**
 * Menu_PollNavInput - portable twin.
 *
 * Lives in its own file: the auto-split menu_input_poll.c that this function is
 * named for also carries a second copy of Menu_HelpScreen, so linking it into
 * the native build would duplicate a symbol helper_gsm_sub18.c already
 * provides.
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_joySelP0;            /* 0x00543b68 */
extern unsigned int g_joySelP1;            /* 0x00543b6c */
extern unsigned int g_dispatchSave1491;    /* 0x00ab4338 */
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_dispatchSave1491 (*(unsigned int *)MK4_VA(unsigned int, 0xab4338u))
#define g_joySelP0 (*(unsigned int *)MK4_VA(unsigned int, 0x543b68u))
#define g_joySelP1 (*(unsigned int *)MK4_VA(unsigned int, 0x543b6cu))
#endif


/*
 * @addr 0x004b7020 (312b) - menu navigation poll.
 *
 * Folds the arrow keys, Return/Space, Escape and Backspace, plus both
 * joysticks, into one bit set:
 *
 *     1 up   2 down   4 left   8 right   0x10 select   0x20 back
 *     0x60 = Escape, which is back AND select-ish
 *     0x8000 = "held over from last frame", see below
 *
 * g_dispatchSave1491 holds the previous frame's bits. When it was non-zero and
 * this frame is also non-zero the input is a HOLD, so 0x8000 goes up and the
 * caller ignores it; only a fresh press updates the saved value. The click is
 * played on a fresh press only, for the same reason.
 *
 * The joystick's low 28 bits count as "select" but only when the caller passes
 * a non-zero argument.
 *
 * There is no matching-build definition - the function is still synthesized
 * from the original bytes - so this branch is NON_MATCHING-only.
 */
#ifdef NON_MATCHING
extern int          Input_GetAsyncKey(int vk);
extern unsigned int Input_PollJoystick(int which);
extern void         Helper_AudioRelease(int channel);
extern void         Audio_PlaySoundId(int a, int b, int c);

unsigned int Menu_PollNavInput(int joy_selects)
{
    unsigned int bits = 0;
    unsigned int joy;

    if (Input_GetAsyncKey(0x26)) bits  = 1;        /* up     */
    if (Input_GetAsyncKey(0x28)) bits |= 2;        /* down   */
    if (Input_GetAsyncKey(0x0d)) bits |= 0x10;     /* Return */
    if (Input_GetAsyncKey(0x20)) bits |= 0x10;     /* Space  */
    if (Input_GetAsyncKey(0x25)) bits |= 4;        /* left   */
    if (Input_GetAsyncKey(0x27)) bits |= 8;        /* right  */
    if (Input_GetAsyncKey(0x1b)) bits |= 0x60;     /* Escape */
    if (Input_GetAsyncKey(0x08)) bits |= 0x20;     /* Back   */

    joy  = Input_PollJoystick(g_joySelP0);
    joy |= Input_PollJoystick(g_joySelP1);

    if (joy & 0x40000000u) bits |= 1;
    if (joy & 0x80000000u) bits |= 2;
    if (joy & 0x10000000u) bits |= 4;
    if (joy & 0x20000000u) bits |= 8;
    if (joy_selects != 0 && (joy & 0x0fffffffu) != 0)
        bits |= 0x10;

    if (g_dispatchSave1491 != 0 && bits != 0)
        bits |= 0x8000;
    else
        g_dispatchSave1491 = bits;

    if ((bits & 0x8000) == 0 && bits != 0) {
        Helper_AudioRelease(0xa0);
        Audio_PlaySoundId(0xa0, -1, -1);
    }
    return bits;
}
#else
/* matching build: synthesized from the original bytes, nothing to compile */
#endif
