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

/* DSound_Init declared further below (returns s32). */
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

/* === IMA ADPCM decoder ====================================== */

/* 4-bit IMA ADPCM → 16-bit PCM decoder. State packs (predictor << 8)
 * | step_index in 32 bits at *state. */
void ESF_DecodeADPCM(const u8 *src, s16 *dst, s32 sample_count,
                     u32 *state);                       /* 0x004ac200 */

/* IMA step-size and index-adjustment LUTs (in .rdata). */
extern s32 g_imaStepTable[89];   /* 0x004f4520 */
extern s32 g_imaIndexTable[16];  /* 0x004f44e0 */

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

/* Cross-checks (1) that CheckInstallPath chdir'd into a valid
 * directory, (2) that the EXE lives on a fixed-disk drive,
 * (3) that the saved registry config blob is valid. Caches the
 * result in g_validInstall. Returns 1 on success, 0 on any
 * failure. */
s32 ValidateInstall(void);                               /* 0x004ad270 */

/* Reset the cached config blob to defaults. */
void ResetConfigToDefaults(void);                        /* 0x004acf90 */

/* Two anonymous helpers between ResetConfigToDefaults and
 * ValidateInstall (compute config-blob hash / validation). */
s32  Helper_ValidateA(void);                             /* 0x004ad20e */
void Helper_ValidateB(void);                             /* 0x004ad24e */

/* CRT-side helpers used by ValidateInstall. */
void Helper_StrCopy(char *dst, s32 size);                /* 0x004c499d */
void Helper_SplitPath(char *path, char *drv, char *dir,
                      char *fname, char *ext);            /* 0x004c5dfe */

/* CRT helpers used by Helper_ComputeExeHash. */
void Helper_ChkStk(void);                                /* 0x004c5dd0 */
void *Helper_FOpen(const char *path, const char *mode);  /* 0x004c5db0 */
s32  Helper_FRead(void *buf, u32 sz, u32 n, void *fp);   /* 0x004c5b70 */
s32  Helper_FSeek(void *fp, s32 off, s32 whence);        /* 0x004c5a90 */
s32  Helper_FTell(void *fp);                             /* 0x004c58b0 */
void Helper_FOpenPostInit(void *fp);                     /* 0x004c5cf0 */
extern void Helper_FClose(void *file);                   /* 0x004c5800 */

extern s32  g_validInstall;     /* 0x00543f78 */
extern u8   g_configBuffer[588];/* 0x00543928 */
extern u32  g_configChecksum;   /* 0x0054392c */

/* Default-config table read by ResetConfigToDefaults (26 dwords
 * from .rdata, copied into the live config region in pairs). */
extern const u32 g_resetCfgDefaults[26];   /* 0x004f46a0 */

/* Live config region populated/touched by ResetConfigToDefaults. The
 * function writes 58 dwords from base (0x00543a84) to +0xe8. */
extern u32  g_resetCfgRegion[58];          /* 0x00543a84 */

/* === UpdateWindowTitle state ================================ */

/* Once per frame compares 8 (mode, sub-mode) state pairs - if any
 * differs from its previous "saved" value, re-issues SetWindowTextA
 * with the right title and re-syncs the audio/state helpers, then
 * snapshots the 8 current values back into the "saved" slots. */
void UpdateWindowTitle(void);                                    /* 0x004b22e0 */

/* The 8 "saved-state" snapshots (compared first thing each call). */
extern u32  g_titleSaved[8];                                     /* 0x004f4ad0 */

/* Window handle and "audio active" flag the title checks each frame. */
extern void *g_titleHwnd;                                        /* 0x007af924 */
extern u32   g_titleAudioFlag;                                   /* 0x007af928 */

/* The 8 "current" state values feeding the comparison (note: NOT
 * laid out contiguously in memory; the function loads them from
 * disjoint addresses in this exact order). */
extern u32 g_titleMode;            /* 0x00f9f7f0 */
extern u32 g_titleSub;             /* 0x00f9f7ec */
extern u32 g_titleSlot;            /* 0x00f9f7e8 */
extern u32 g_titlePauseGate;       /* 0x004ffd7c */
extern u32 g_titleStateE;          /* 0x00543a8c */
extern u32 g_titleStateF;          /* 0x00543a84 */
extern u32 g_titleStateG;          /* 0x00543a90 */
extern u32 g_titleStateH;          /* 0x00543a88 */

/* Audio-state probe checked late in the function. */
extern u32 g_titleAudioState;      /* 0x00ab5748 */

/* IAT slot for SetWindowTextA (`call ds:[g_iat_SetWindowTextA]`
 * forms a single 6-byte instruction with the IAT address). */
extern void *g_iat_SetWindowTextA;  /* 0x004d21bc */

/* === DSound_Init state ====================================== */

/* Direct-sound init: builds a per-channel volume curve table
 * (256x256 .word entries, two pointers per (i,j)), zero-clears the
 * audio channel queue, calls DirectSoundCreate, then sets the
 * cooperative level + creates the primary buffer. */
s32  DSound_Init(void *hwnd);                            /* 0x004c3ef0 */

/* DSound init globals. */
extern void *g_dsoundHwnd;       /* 0x00f9efd0 */
extern u32   g_dsoundFieldE0;    /* 0x00f9efe0 */
extern u32   g_dsoundFieldE4;    /* 0x00f9efe4 */
extern u32   g_dsoundFieldE8;    /* 0x00f9efe8 */
extern void *g_dsoundContext;    /* 0x00f9efc8 (IDirectSound*) */
extern void *g_dsoundPrimary;    /* 0x00f9efcc (LPDIRECTSOUNDBUFFER) */
extern u8    g_dsoundFieldDc;    /* 0x00f9efdc */

/* Constants (qword/doubles in .rdata) used by the volume-curve
 * inner loop. */
extern double k_dsoundC1;    /* 0x004d2a68 */
extern double k_dsoundC2;    /* 0x004d2a70 */
extern double k_dsoundC3;    /* 0x004d2a78 */
extern double k_dsoundC4;    /* 0x004d2a80 */
extern double k_dsoundC5;    /* 0x004d2a88 */
extern double k_dsoundC6;    /* 0x004d2a90 */

/* Big working scratch the function zero-clears. */
extern u8 g_dsoundScratch[];  /* 0x00f8fac8 (0x3c28 dwords) */

/* CRT _ftol used inside the FP loop. */
s32  _ftol(void);                                          /* 0x004c57d0 */

/* DirectSoundCreate import thunk. */
s32  DirectSoundCreate_thunk(void *guid, void **ppDS,
                             void *unused);                 /* 0x004d12d8 */

/* Two post-init helpers + the volume-set helper. */
void Helper_DSI_post1(s32 a);                              /* 0x004c4110 */
void Helper_DSI_post2(s32 a);                              /* 0x004c3e30 */

/* Helper functions invoked by UpdateWindowTitle on the "changed"
 * path. Each fires under specific state transitions. */
void Helper_TitleAudioReset(void);                               /* 0x004b5840 */
void Helper_AudioStart(void);                                    /* 0x004c4390 */
void Helper_AudioStartFresh(void);                               /* 0x004c4360 */
void Helper_TitleEnterStateA(void);                              /* 0x004ac780 */
void Helper_TitleEnterStateB(void);                              /* 0x004ac570 */
void Helper_TitleEnterStateC(void);                              /* 0x004ac520 */
void Helper_TitleAudioStop(void);                                /* 0x004c42f0 */
void Helper_TitleAudioCleanup(void);                             /* 0x004bea40 */
void Helper_TitleSetMaxVolume(s32 max);                          /* 0x004c3eb0 */

/* Where CheckInstallPath stashes the registry-resolved install
 * directory before chdir'ing. */
extern char g_installPath[1024];        /* 0x00543b78 */

/* fopen("rb") + hash worker called by GetExeDirectory. Stores
 * the computed hash into g_exeIntegrityValue{A,B}. */
s32 Helper_ComputeExeHash(const char *path);             /* 0x004acae0 */

extern u32 g_exeIntegrityValueA;    /* 0x00543920 - computed lo */
extern u32 g_exeIntegrityValueB;    /* 0x00543924 - computed hi */
extern u32 g_exeIntegrityRefA;      /* 0x004f4690 - expected lo */
extern u32 g_exeIntegrityRefB;      /* 0x004f4694 - expected hi */
extern u32 g_exeIntegrityFoundPos;  /* 0x00543918 - file pos where sig was found (0 = not yet) */

#ifdef __cplusplus
}
#endif

#endif /* MK4_AUDIO_SOUND_H */
