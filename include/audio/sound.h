/**
 * Audio subsystem — DirectSound + AuxAudio + ESF/ECM playback.
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
void AuxAudio_SetVolume(u32 vol);                        /* 0x004aca10 */

/* === Per-frame ticks (called from GameLogicStep) ============== */

void Audio_TimerTick(void);                              /* 0x004ac4b0 */
void Audio_UpdateChannels(u32 param);                    /* 0x004c37f0 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_AUDIO_SOUND_H */
