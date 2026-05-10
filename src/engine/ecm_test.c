/* Variant: dst declared first */
#include "engine/ecm.h"

void ECM_DecodeFrame_Raw(ecm_state *state)
{
    u8 *dst = (u8 *)state->dst;
    u8 *src = state->buffer + 12;
    s32 count = state->offset_b;

    if (dst > src && dst < src + count) {
        u8 *d = (dst + count) - 1;
        u8 *s = (src + count) - 1;
        while (count--) {
            *d-- = *s--;
        }
    } else {
        while (count--) {
            *dst++ = *src++;
        }
    }
}
