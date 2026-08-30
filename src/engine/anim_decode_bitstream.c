/**
 * Anim_DecodeBitstream - 0x004013a0 (1989b): the COMPRESSED animation
 * decoder. Every fighter clip in the game is compressed, so with this
 * hollow the pose pipeline decodes nothing: ExtractBitsToVec3 gets zero
 * words, every bone rotation reads zero, and the characters stand in bind
 * pose. The engine's own stub trace says so - "ANIM compressed path hit,
 * poses from this anim are zeroed", 196 times in a 380-frame run.
 *
 * It reads a bit stream and produces ONE PACKED WORD PER BONE in the same
 * 11/11/10 layout ExtractBitsToVec3 unpacks, plus three scalars.
 *
 * Stream layout:
 *   6 header dwords  - three (scale, bias) pairs for the three scalars
 *   then a bit stream, LSB-first within each dword, refilled a dword at a
 *   time. The reader is (buf, bits, cursor): `bits` is how much of `buf`
 *   is still valid, and a read that runs past it pulls the next dword and
 *   splices the two halves.
 *
 * Three passes over the bones (the count is at 0x523b20, three components
 * each):
 *   1. per component: a 1-bit KEYED flag, then an 11-bit signed delta
 *      (10 bits for the third component, and each is shifted back up by
 *      the component index >> 1 - the 11/11/10 packing), then an 8-bit
 *      span when the flag is set.
 *   2. per keyed component: a 4-bit nibble; when it is zero, either an
 *      8-bit signed value or a skip, depending on the frame counter.
 *   3. the same walk again but nibble-coded through the 256-entry table at
 *      0x524158 - low four bits of the entry say how many bits it
 *      consumed, the rest is a delta added into the nibble.
 * A leading 13-bit field and a 12-bit field are BIT-OFFSET SEEKS: the
 * stream jumps forward by that many bits, which is how the format skips
 * whole frames. Those seeks are computed on the VA, not on a host
 * pointer - the original does `edi*8` and masks with 0xe0000000, which is
 * only meaningful in the game's own address space.
 *
 * Finally each bone's three components are recombined into one word:
 *   value = keyed ? (nibble ? span * (nibble - 1) + delta
 *                           : (signed char)extra << 3)
 *                 : delta
 * masked to 11 bits, shifted down by the component index >> 1 and packed
 * at 0, 11 and 22 bits.
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

#define g_animSkipBits   (*(unsigned int *)MK4_VA(unsigned int, 0x523ae0u))
#define g_animSrcPtr     (*(unsigned int *)MK4_VA(unsigned int, 0x523ae4u))
#define g_animOutPtr     (*(unsigned int *)MK4_VA(unsigned int, 0x523b1cu))
#define g_animBoneCount  (*(unsigned int *)MK4_VA(unsigned int, 0x523b20u))
#define g_animFrameLimit (*(unsigned int *)MK4_VA(unsigned int, 0x523b24u))
#define ANIM_NIBTAB      ((unsigned short *)MK4_VA(unsigned short, 0x524158u))

/* the original's frame is 0x260 bytes: four byte arrays of 68 and one
 * dword array of 62, i.e. three components for up to twenty-odd bones */
#define ANIM_MAXB   68
#define ANIM_MAXW   62

/* --- the bit reader, held as a VA so the seeks stay in game space ---- */
typedef struct {
    unsigned int va;      /* cursor, VA of the NEXT dword to pull */
    unsigned int buf;     /* current bits, LSB first */
    int          bits;    /* how many of buf are still valid */
} AnimBits;

static unsigned int anim_pull(AnimBits *b)
{
    unsigned int w = *(unsigned int *)MK4_PTR(b->va);
    b->va += 4;
    return w;
}

/* read n bits (n < 32), LSB first, splicing across the dword boundary */
static unsigned int anim_read(AnimBits *b, int n)
{
    unsigned int mask = (n >= 32) ? 0xffffffffu : ((1u << n) - 1u);
    unsigned int out;
    int had = b->bits;

    b->bits -= n;
    if (b->bits < 0) {
        unsigned int nw = anim_pull(b);
        out = ((nw << had) + b->buf) & mask;
        b->buf = nw >> (-b->bits);
        b->bits += 32;
    } else {
        out = b->buf & mask;
        b->buf >>= n;
    }
    return out;
}

static void anim_skip(AnimBits *b, int n)
{
    (void)anim_read(b, n);
}

/* a bit-offset seek: jump `delta` bits forward from the current position */
static void anim_seek(AnimBits *b, unsigned int delta)
{
    unsigned int pos = b->va * 8u - (unsigned int)b->bits + delta;
    unsigned int keep = b->va & 0xe0000000u;
    unsigned int frac = pos & 0x1fu;

    b->va  = keep + ((pos >> 3) & 0x1ffffffcu);
    b->bits = 32 - (int)frac;
    b->buf = anim_pull(b) >> frac;
}

void Anim_DecodeBitstream(void)
{
    unsigned char keyed[ANIM_MAXB];   /* esp+0x58  */
    unsigned char extra[ANIM_MAXB];   /* esp+0x9c  */
    unsigned char nib[ANIM_MAXB];     /* esp+0xe0  */
    unsigned char span[ANIM_MAXB];    /* esp+0x124 */
    int           delta[ANIM_MAXW];   /* esp+0x168 */

    AnimBits b;
    unsigned int scale0, bias0, scale1, bias1, scale2, bias2;
    unsigned int outp = g_animOutPtr;
    unsigned int nbones = g_animBoneCount;
    unsigned int skip = g_animSkipBits;
    unsigned int s0, s1, s2;
    int  repeats;
    unsigned int i, k, i3, wi;

    b.va = g_animSrcPtr;
    b.bits = 32;

    scale0 = anim_pull(&b); bias0 = anim_pull(&b);
    scale1 = anim_pull(&b); bias1 = anim_pull(&b);
    scale2 = anim_pull(&b); bias2 = anim_pull(&b);
    b.buf = anim_pull(&b);

    /* leading 13-bit seeks, one per 16 units of the skip counter */
    for (;;) {
        unsigned int d = anim_read(&b, 13);
        if ((int)skip < 0x10)
            break;
        skip -= 0x10;
        anim_seek(&b, d);
    }

    /* pass 1: keyed flag, signed delta, span */
    if ((int)nbones > 0) {
        i3 = 0; wi = 0;
        for (i = 0; i < nbones; i++) {
            for (k = 0; k < 3; k++) {
                unsigned int flag = anim_read(&b, 1);
                int          shift = (int)(k >> 1);
                int          nb = 11 - shift;
                int          v;

                keyed[i3 + k] = (unsigned char)flag;
                v = (int)(anim_read(&b, nb) << shift);
                if (v & 0x400)
                    v -= 0x800;
                delta[wi + k] = v;
                if (flag)
                    span[i3 + k] = (unsigned char)anim_read(&b, 8);
            }
            i3 += 3; wi += 3;
        }
    }

    /* how many extra frames this block carries */
    if ((int)skip > 7) {
        repeats = (int)skip - 7;
    } else {
        int lim = 7;
        unsigned int last = g_animFrameLimit - 1u;

        if ((int)g_animSkipBits >= (int)(last & 0xfffffff0u)) {
            int low = (int)(last & 0xfu);
            if (low < lim)
                lim = low;
        }
        repeats = lim - (int)skip;
    }

    s0 = anim_read(&b, 8);
    s1 = anim_read(&b, 8);
    s2 = anim_read(&b, 8);

    /* pass 2: the nibble, and its 8-bit payload on the final frame */
    if ((int)nbones > 0) {
        i3 = 0;
        for (i = 0; i < nbones; i++) {
            for (k = 0; k < 3; k++) {
                unsigned int n4;

                if (keyed[i3 + k] == 0)
                    continue;
                n4 = anim_read(&b, 4);
                nib[i3 + k] = (unsigned char)n4;
                if (n4 != 0)
                    continue;
                if (repeats == 0)
                    extra[i3 + k] = (unsigned char)anim_read(&b, 8);
                else
                    anim_skip(&b, 8);
            }
            i3 += 3;
        }
    }

    /* a 12-bit seek closes the block */
    {
        unsigned int d = anim_read(&b, 12);
        if ((int)skip > 7)
            anim_seek(&b, d);
    }

    /* the remaining frames: nibble-coded through the 256-entry table */
    while (repeats-- > 0) {
        if (repeats == 0) {
            s0 = anim_read(&b, 8);
            s1 = anim_read(&b, 8);
            s2 = anim_read(&b, 8);
        } else {
            anim_skip(&b, 24);
        }
        if ((int)nbones <= 0)
            continue;
        i3 = 0;
        for (i = 0; i < nbones; i++) {
            for (k = 0; k < 3; k++) {
                unsigned int look, ent, used;
                int          add, sum;

                if (keyed[i3 + k] == 0)
                    continue;
                look = b.buf & 0xffu;
                ent  = ANIM_NIBTAB[look];
                used = ent & 0xfu;
                add  = (int)ent >> 7;
                anim_skip(&b, (int)used);
                sum = (int)nib[i3 + k] + add;
                nib[i3 + k] = (unsigned char)(sum & 0xf);
                if ((sum & 0xf) != 0)
                    continue;
                if (repeats == 0)
                    extra[i3 + k] = (unsigned char)anim_read(&b, 8);
                else
                    anim_skip(&b, 8);
            }
            i3 += 3;
        }
    }

    /* the three scalars: scale by the header pair and publish */
    *(unsigned int *)MK4_PTR(outp)     = ((s0 & 0xffu) * scale0 >> 8) + bias0;
    *(unsigned int *)MK4_PTR(outp + 4) = ((s1 & 0xffu) * scale1 >> 8) + bias1;
    *(unsigned int *)MK4_PTR(outp + 8) = ((s2 & 0xffu) * scale2 >> 8) + bias2;
    outp += 12;

    /* recombine each bone into one 11/11/10 packed word */
    if ((int)nbones > 0) {
        i3 = 0; wi = 0;
        for (i = 0; i < nbones; i++) {
            unsigned int packed = 0;
            int          shift = 0;

            for (k = 0; k < 3; k++) {
                int v;

                if (keyed[i3 + k] == 0) {
                    v = delta[wi + k];
                } else if (nib[i3 + k] == 0) {
                    v = (int)(signed char)extra[i3 + k] << 3;
                } else {
                    v = (int)span[i3 + k] * ((int)nib[i3 + k] - 1)
                      + delta[wi + k];
                }
                v &= 0x7ff;
                v >>= (int)(k >> 1);
                packed += (unsigned int)v << shift;
                shift += 11;
            }
            *(unsigned int *)MK4_PTR(outp) = packed;
            outp += 4;
            i3 += 3; wi += 3;
        }
    }
}

#endif /* NON_MATCHING */
