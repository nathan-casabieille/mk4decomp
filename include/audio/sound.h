/**
 * Audio subsystem - DirectSound + AuxAudio + ESF/ECM playback.
 */
#ifndef MK4_AUDIO_SOUND_H
#define MK4_AUDIO_SOUND_H

#include "../types.h"
#include "../platform/win32.h"

#ifdef __cplusplus
extern "C" {
#endif

/* === Init ==================================================== */

void DSound_Init(void *hwnd);                            /* 0x004c3ef0 */
s32  AuxAudio_Init(HWND hwnd);                           /* 0x004ac8f0 */
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
void Audio_UpdateChannels(void);                         /* 0x004c37f0 */

/* Active-channel queue iterated by Audio_UpdateChannels: 16
 * entries of (u16 channel_id, u16 owner_id), terminated by an
 * entry with channel_id = 0xffff. */
extern u16 g_audioChannelQueue[32]; /* 0x00f9eb80 */

/* 28-bytes-per-entry state table indexed by channel_id from the
 * queue. Field +0x16 (= 0xf8fade) is a flags byte; bit 1 means
 * "needs release". */
extern u8  g_audioChannelTable[];   /* 0x00f8fac8 */

/* Global "audio fully active" flag - when 0, the channel update
 * keeps walking; when set, certain branches abort early. */
extern u8  g_audioMute;             /* 0x00f9efd4 */

/* Inner helpers invoked by Audio_UpdateChannels per channel. */
void Helper_AudioStop(s32 ch);                          /* 0x004c3710 */
void Helper_AudioRelease(s32 ch);                       /* 0x004c3490 */

/* Re-arms the audio timer: stores arg1..arg4 into the four
 * timer-state globals (active, start_sec, end_sec, handle). */
void Audio_TimerSet(u32 active, u32 start_sec,
                    u32 end_sec, u32 handle);            /* 0x004ac650 */

/* Audio timer state - watched by Audio_TimerTick each frame.
 * When timeGetTime() - lastNow >= (end - start) * 1000 the timer
 * fires Audio_TimerSet to re-seed itself. */
extern u32 g_audioPreState;   /* 0x005438e8 */
extern u32 g_timerActive;     /* 0x005438ec */
extern u32 g_timerStartSec;   /* 0x005438f0 */
extern u32 g_timerEndSec;     /* 0x005438f4 */
extern u32 g_timerHandle;     /* 0x005438f8 */
extern u32 g_timerLastNow;    /* 0x005438fc - last timeGetTime() in ms */
extern u32 g_audioState00;    /* 0x00543900 */
extern u32 g_timerFlag;       /* 0x00543904 */
extern u32 g_audioState08;    /* 0x00543908 */
extern u32 g_audioState0C;    /* 0x0054390c */
extern HWND g_auxAudioHwnd;   /* 0x00543910 */

/* Sub-helper called at the end of AuxAudio_Init - probably installs
 * a multimedia timer callback. */
void Helper_AuxAudio_PostInit(void);                    /* 0x004ac320 */

/* === Debug placeholders (empty; compiled-out hooks) =========== */
void DebugStub_NoOp_B(void);                             /* 0x004a4150 */
void DebugStub_NoOp_A(void);                             /* 0x004a4170 */

/* === EXE-integrity check (audio install gate) =============== */

/* Pulls the EXE path with GetModuleFileNameA, reads the file in
 * binary mode, and computes a hash that must match the two
 * compile-time constants in .rdata. Returns 0 if both halves
 * match, -1 if GetModuleFileNameA failed, -10 on hash mismatch,
 * or the helper's nonzero rc on lower-level failures. */
s32 GetExeDirectory(void);                               /* 0x004aca60 */

/* HKLM\Software\GT Interactive\Mortal Kombat 4\1.00\Path
 * lookup + SetCurrentDirectoryA. Returns 1 if the install path
 * was read and chdir'd into, 0 otherwise. */
s32 CheckInstallPath(void);                              /* 0x004acc50 */

/* Where CheckInstallPath stashes the registry-resolved install
 * directory before chdir'ing. */
extern char g_installPath[1024];        /* 0x00543b78 */

/* fopen("rb") + hash worker called by GetExeDirectory. Stores
 * the computed hash into g_exeIntegrityValue{A,B}. */
s32 Helper_ComputeExeHash(const char *path);             /* 0x004acae0 */

extern u32 g_exeIntegrityValueA;    /* 0x00543920 - computed lo */
extern u32 g_exeIntegrityValueB;    /* 0x00543924 - computed hi */
extern u32 g_exeIntegrityRefA;      /* 0x004f4698 - expected lo */
extern u32 g_exeIntegrityRefB;      /* 0x004f469c - expected hi */

#ifdef __cplusplus
}
#endif

#endif /* MK4_AUDIO_SOUND_H */
