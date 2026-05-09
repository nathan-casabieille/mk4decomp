/**
 * Audio subsystem - DirectSound + AuxAudio + ESF/ECM playback.
 */
#ifndef MK4_AUDIO_SOUND_H
#define MK4_AUDIO_SOUND_H

#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* === Init ==================================================== */

void DSound_Init(void *hwnd);                            /* 0x004c3ef0 */
void AuxAudio_Init(void *hwnd);                          /* 0x004ac8f0 */
void AuxAudio_SetVolume(s32 vol);                        /* 0x004aca10 */

/* Aux-out (Windows multimedia) channel inventory. AuxAudio_Init
 * populates this with the system's available auxiliary devices and
 * stores how many were found. Each entry is the device id + a
 * 4-byte pad (caps slot or similar). */
typedef struct AuxChannel {
    u32 deviceId;
    u32 _pad;
} AuxChannel;

extern s32         g_auxCount;        /* 0x005438a0 */
extern AuxChannel  g_auxChannels[];   /* 0x005438a8 */

/* === Per-frame ticks (called from GameLogicStep) ============== */

void Audio_TimerTick(void);                              /* 0x004ac4b0 */
void Audio_UpdateChannels(u32 param);                    /* 0x004c37f0 */

/* Re-arms the audio timer: stores arg1..arg4 into the four
 * timer-state globals (active, start_sec, end_sec, handle). */
void Audio_TimerSet(u32 active, u32 start_sec,
                    u32 end_sec, u32 handle);            /* 0x004ac650 */

/* Audio timer state - watched by Audio_TimerTick each frame.
 * When timeGetTime() - lastNow >= (end - start) * 1000 the timer
 * fires Audio_TimerSet to re-seed itself. */
extern u32 g_timerActive;     /* 0x005438ec */
extern u32 g_timerStartSec;   /* 0x005438f0 */
extern u32 g_timerEndSec;     /* 0x005438f4 */
extern u32 g_timerHandle;     /* 0x005438f8 */
extern u32 g_timerLastNow;    /* 0x005438fc - last timeGetTime() in ms */
extern u32 g_timerFlag;       /* 0x00543904 */

/* === Debug placeholders (empty; compiled-out hooks) =========== */
void DebugStub_NoOp_B(void);                             /* 0x004a4150 */
void DebugStub_NoOp_A(void);                             /* 0x004a4170 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_AUDIO_SOUND_H */
