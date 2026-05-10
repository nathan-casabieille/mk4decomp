/**
 * ECM - Eurocom Custom Movie.
 *
 * Cinematic container format (intro, character bios, endings).
 * Combines IMA ADPCM audio (22050 Hz mono) with Huffman-compressed
 * video frames at 15 fps, grouped 15 frames per "SEC" block.
 *
 * See analysis/notes/architecture.md for the full format.
 */
#ifndef MK4_ENGINE_ECM_H
#define MK4_ENGINE_ECM_H

#include "../types.h"
#include "../platform/win32.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ECM_MAGIC      0x024D4345   /* 'E','C','M',0x02 - file magic */
#define ECM_GROUP_MAGIC 0x00434553   /* 'S','E','C',0x00 - per-group magic */
#define ECM_FRAME_MAGIC_EDL  0x004C4445  /* 'E','D','L',0    - per-frame magic */

#define ECM_HEADER_SIZE     0x0E18  /* 3608 bytes - magic+count+900 offsets */
#define ECM_FRAMES_PER_GROUP 15
#define ECM_AUDIO_BYTES_PER_GROUP  0xAC44  /* 44100 = 1 sec @ 22050 Hz mono */

/* Per-frame parser state. 32 bytes total.
 * Layout reverse-engineered from ECM_ParseFrameHeader / Dispatch. */
typedef struct ecm_state {
    void *dst;           /* +0x00 - destination buffer (decoded output) */
    u8 *buffer;          /* +0x04 - source bitstream buffer */
    s32 offset_a;        /* +0x08 - copied from buffer[4..7] */
    s32 offset_b;        /* +0x0c - copied from buffer[8..11] (decoded byte count) */
    s32 mode;            /* +0x10 - 0=raw, 1=huffman, else=skip */
    u32 _14;             /* +0x14 - reserved/scratch (zero-init by ECM_DecodeFrame) */
    s32 flag;            /* +0x18 - high bit of magic byte 3 */
    s32 status;          /* +0x1c - 0=ok, -3=bad magic, -4=bad mode */
} ecm_state;

/* === Public API ============================================== */

/* Open + start playback worker thread. Returns frame count or 0. */
u32 ECM_Open(const char *filename, void *dsound_iface,
             u32 unused, u32 frame_skip);                /* 0x004b06f0 */

/* Stop playback, release DSound buffer + worker thread, close file. */
void ECM_Cleanup(void);                                  /* 0x004b0cb0 */

/* Worker thread function (passed to CreateThread). */
DWORD __stdcall ECM_PlayThread(LPVOID param);            /* 0x004b0a50 */

/* === Globals touched by ECM_Cleanup ========================== */

/* DirectSound buffer object used for the cinematic audio track.
 * Vtable methods invoked by ECM_Cleanup (offsets in bytes):
 *   +0x08 = IUnknown::Release
 *   +0x3c = IDirectSoundBuffer::SetVolume
 *   +0x48 = IDirectSoundBuffer::Stop
 */
typedef struct DSBuf DSBuf;
typedef long (__stdcall *DSBuf_Release)(DSBuf *self);
typedef long (__stdcall *DSBuf_SetVolume)(DSBuf *self, s32 vol);
typedef long (__stdcall *DSBuf_Stop)(DSBuf *self);
typedef struct DSBufVtbl {
    void           *m_0_to_1[2];           /* QueryInterface, AddRef */
    DSBuf_Release   Release;               /* slot 2 = offset 0x08 */
    void           *m_3_to_14[12];         /* unused-by-us */
    DSBuf_SetVolume SetVolume;             /* slot 15 = offset 0x3c */
    void           *m_16_to_17[2];         /* unused-by-us */
    DSBuf_Stop      Stop;                  /* slot 18 = offset 0x48 */
} DSBufVtbl;
struct DSBuf {
    DSBufVtbl *vtbl;
};

extern void  *g_ecmFile;          /* 0x007ab04c - FILE* (or HANDLE) */
extern DSBuf *g_ecmDSBuffer;      /* 0x007ab05c */
extern HANDLE g_ecmThread;        /* 0x007ab06c */
extern u32    g_ecmThreadStatus;  /* 0x007ab078 - non-zero while thread alive */
extern u32    g_ecmHeaderBuf[902];/* 0x007aa230 - 3608 bytes scratch */

/* === ECM_Open state ========================================= */

/* Sticky play state - 0=running, -1/-2=error sentinels read by
 * ECM_PlayThread to short-circuit. */
extern u32 g_ecmPlayState;        /* 0x007ab074 */

/* Opaque DSound context handed in via ECM_Open's 2nd arg, used to
 * call CreateSoundBuffer in the (vtbl)[+0x0c] slot. */
extern void *g_ecmDsContext;      /* 0x007ab058 */

/* Frame-size-divided-by-8 (= start_frame * magic / 8) cached for
 * ECM_PlayThread. */
extern u32 g_ecmFrameSizeDiv8;    /* 0x007ab050 */

/* "Run flag" + reserved + thread-id-out filled by ECM_Open before
 * CreateThread. */
extern u32 g_ecmRunFlag;          /* 0x007ab060 (= 1 set by ECM_Open) */
extern u32 g_ecmReserved;         /* 0x007ab064 */
extern u32 g_ecmThreadIdOut;      /* 0x007ab068 (CreateThread out param) */

/* Cached _ftol(volume_db) the function passes to SetVolume. */
extern u32 g_ecmVolumeFromFtol;   /* 0x007ab070 */

/* Frame index (-1 == not yet) and total-frame-count cache used by
 * the play thread. */
extern u32 g_ecmFrameIdx;         /* 0x004f47b4 */
extern u32 g_ecmFrameTotal;       /* 0x004f47b8 */

/* Constants (qword/double) used inside ECM_Open's volume curve. */
extern double k_ecmC1;            /* 0x004d2978 */
extern double k_ecmC2;            /* 0x004d2980 */
extern double k_ecmC3;            /* 0x004d2988 (clamp max) */
extern double k_ecmC4;            /* 0x004d2990 (clamp min) */

/* IAT slots. */
extern void *g_iat_CreateThread;  /* 0x004d2070 */
extern void *g_iat_Sleep;         /* 0x004d2074 */

/* Inner helper called by ECM_Cleanup to flush internal state. */
void Helper_ECM_PostCleanup(s32 zero_arg);              /* 0x004b09a0 */

/* CRT-style fclose used by ECM_Cleanup. */
void Helper_FClose(void *file);                          /* 0x004c5800 */

/* === Internal ================================================ */

s32  ECM_DecodeFrame(const void *src, void *dst);        /* 0x004b1c90 */
void ECM_DecodeFrameDispatch(ecm_state *state);          /* 0x004b1bf0 */
void ECM_ParseFrameHeader(ecm_state *state);             /* 0x004b1c30 */
void ECM_DecodeFrame_Raw(ecm_state *state);              /* 0x004b1220 */
void ECM_DecodeFrame_Huffman(ecm_state *state);          /* 0x004b1270 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_ECM_H */
