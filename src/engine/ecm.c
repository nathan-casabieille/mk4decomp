/**
 * ECM (Eurocom Custom Movie) per-frame dispatcher.
 */
#include "engine/ecm.h"

/*
 * Parse the next frame's 12-byte header out of state->buffer:
 *   buffer[0..2] = "EDL" magic
 *   buffer[3]   = high bit -> flag, low 7 bits -> mode (0..1)
 *   buffer[4..7]  -> offset_a
 *   buffer[8..11] -> offset_b
 *
 * Sets state->status to 0 / -3 / -4 to signal the result.
 *
 * @addr 0x004b1c30
 */
void ECM_ParseFrameHeader(ecm_state *state)
{
    u8 *buf;
    s32 mode;

    buf = state->buffer;
    if (buf[0] != 'E' || buf[1] != 'D' || buf[2] != 'L') {
        state->status = -3;
        return;
    }
    state->flag = buf[3] >> 7;
    mode = buf[3] & 0x7f;
    state->mode = mode;
    if (mode < 0 || mode > 1) {
        state->status = -4;
        return;
    }
    state->status = 0;
    state->offset_a = *(s32 *)(buf + 4);
    state->offset_b = *(s32 *)(buf + 8);
}

/*
 * Parse the next frame's header, then dispatch to the right
 * decoder based on its mode byte.
 *
 * @addr 0x004b1bf0
 */
void ECM_DecodeFrameDispatch(ecm_state *state)
{
    ECM_ParseFrameHeader(state);
    if (state->status != 0) {
        return;
    }
    switch (state->mode) {
        case 0:
            ECM_DecodeFrame_Raw(state);
            return;
        case 1:
            ECM_DecodeFrame_Huffman(state);
            return;
    }
}
