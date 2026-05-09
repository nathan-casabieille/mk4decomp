/**
 * ESF - Eurocom Sound Format.
 *
 * Game audio container. Two variants:
 *   - 8-bit raw unsigned PCM (centered at 0x80)
 *   - 16-bit IMA ADPCM (4:1 compression, MS-IMA spec)
 *
 * Both can be 11025 / 22050 Hz and mono / stereo. See
 * analysis/notes/architecture.md for the full bit-packed header.
 */
#ifndef MK4_ENGINE_ESF_H
#define MK4_ENGINE_ESF_H

#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ESF_MAGIC  0x06465345   /* 'E','S','F',0x06 */

/* === Public API ============================================== */

/* Open and parse an ESF file. Writes bits/rate/channels to out args.
 * Returns the decoded byte count or 0 on failure. */
int ESF_Open(const char *filename, int *bits, int *rate, int *channels);  /* 0x004b1090 */

/* Read decoded PCM into the destination buffer (decoding ADPCM if needed). */
void ESF_ReadData(void *dst);                            /* 0x004b1150 */

/* Close the currently-opened ESF file. */
void ESF_Close(void);                                    /* 0x004b1200 */

/* === Internal ================================================ */

/* IMA ADPCM decoder. Args:
 *   src                 - encoded nibble stream
 *   dst                 - output buffer (16-bit PCM LE)
 *   decoded_byte_count  - how many bytes to write to dst
 *   state               - packed (predictor << 8 | step_index), in/out
 */
void ESF_DecodeADPCM(const u8 *src, u8 *dst, u32 decoded_byte_count, u32 *state);  /* 0x004ac200 */

/* IMA ADPCM tables (89 step entries, 16 index deltas). */
extern const s32 g_imaIndexTable[16];   /* 0x004f44e0 */
extern const s32 g_imaStepTable[89];    /* 0x004f4520 */

/* 8-byte file header read at Open() time:
 *   magic   = ESF_MAGIC                (0x06465345 = "ESF\x06")
 *   state   = packed PCM-format word
 * Both reads happen at offset 0..7 of the file. */
extern u32 g_esf_magic;                 /* 0x007ab088 */
extern u32 g_esf_state;                 /* 0x007ab08c */

/* Currently-open ESF file handle (FSYS handle id, 0 = closed). */
extern int g_esf_handle;                /* 0x007ab090 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_ESF_H */
