/**
 * Submit a 28-byte draw entry (DrawEntry, see
 * include/engine/render_types.h) to g_drawQueue.
 *
 * Bounds-checks the entry against the viewport in two loops: first the
 * Y coords (DrawEntry.y0/y1/y2 at +2/+6/+0xa) against the height
 * envelope (480/580), then the X coords (DrawEntry.x0/x1/x2 at
 * +0/+4/+8) against the width envelope (640/740). Skips the entry if
 * out-of-bounds; otherwise copies it into g_drawQueue[g_drawQueueSize]
 * and rewrites DrawEntry.sort_key at +0x12 via g_zSortKeyLUT. Vertex 1
 * (x1/y1) is skipped in both loops when flags (+0x1a) bit 0x20 is set.
 */
#include "engine/render.h"
#include "engine/render_types.h"

/*
 * @addr 0x004c3360
 *
 * Naked + __asm: the body has two near-identical X/Y bounds
 * loops that mutate the same g_clipMin/g_clipMax scratch globals,
 * different field offsets per loop, then a rep movsd copy
 * + word patch through g_zSortKeyLUT.
 */
#ifdef NON_MATCHING
/*
 * Portable twin (verified by co-exec, tools/decomp/verify_submit.py - NOT
 * byte-matched; the naked branch below is the matching one). Faithful
 * asm-shaped C: two clip-envelope passes (Y fields +2/+6/+0xa, then X fields
 * +0/+4/+8) tracking min->g_clipMinScratch / max->g_clipMaxScratch, vertex 1
 * (+6 / +4) skipped when flag (+0x1a) bit 0x20 is set; reject out-of-envelope;
 * else copy the 28-byte (7-dword) entry into g_drawQueue[g_drawQueueSize], patch
 * the sort key at +0x12 through g_zSortKeyLUT, and bump g_drawQueueSize.
 *
 * &g_drawQueue / &g_zSortKeyLUT are taken with explicit casts (no direct `[` on
 * the name) so verify_coexec.gdef types them as scalar-base = the VA, not a
 * dword-indexed array.
 */
void Helper_DrawCursor(short *pe)
{
    short *esi = pe;
    int eax, edx, ecx;
    unsigned char cl;
    unsigned int qsize = g_drawQueueSize;
    unsigned char *dst;
    int i;

    if ((int)qsize >= 3000)
        return;

    /* ---- Y envelope ---- */
    eax = esi[1];                                  /* +2  v0.y (sign-extended) */
    edx = eax;
    g_clipMaxScratch = eax;
    g_clipMinScratch = edx;
    cl = ((unsigned char *)esi)[0x1a];
    if (!(cl & 0x20)) {                            /* vertex 1 (+6) */
        ecx = esi[3];
        if (ecx < eax) { edx = ecx; g_clipMinScratch = edx; }
        else           { eax = ecx; g_clipMaxScratch = eax; }
    }
    ecx = esi[5];                                  /* +0xa v2.y */
    if (ecx < edx) { edx = ecx; g_clipMinScratch = edx; }
    ecx = esi[5];
    if (ecx > eax) { eax = ecx; g_clipMaxScratch = eax; }
    if (eax < 0)        return;
    if (edx > 0x1e0)    return;                     /* 480 */
    if (edx < -100) { if (eax > 0x244) return; }    /* 580 */

    /* ---- X envelope ---- */
    eax = esi[0];                                  /* +0  v0.x */
    edx = eax;
    g_clipMaxScratch = eax;
    g_clipMinScratch = edx;
    cl = ((unsigned char *)esi)[0x1a];
    if (!(cl & 0x20)) {                            /* vertex 1 (+4) */
        ecx = esi[2];
        if (ecx < eax) { edx = ecx; g_clipMinScratch = edx; }
        else           { eax = ecx; g_clipMaxScratch = eax; }
    }
    ecx = esi[4];                                  /* +8  v2.x */
    if (ecx < edx) { edx = ecx; g_clipMinScratch = edx; }
    ecx = esi[4];
    if (ecx > eax) { eax = ecx; g_clipMaxScratch = eax; }
    if (eax < 0)        return;
    if (edx > 0x280)    return;                     /* 640 */
    if (edx < -100) { if (eax > 0x2e4) return; }    /* 740 */

    /* ---- enqueue: copy 7 dwords into the queue slot, patch sort key ---- */
    dst = (unsigned char *)&g_drawQueue + qsize * 0x1c;
    for (i = 0; i < 7; i++)
        ((unsigned int *)dst)[i] = ((unsigned int *)esi)[i];
    {
        unsigned int key = *(unsigned short *)(dst + 0x12);
        *(unsigned short *)(dst + 0x12) = ((unsigned short *)&g_zSortKeyLUT)[key];
    }
    g_drawQueueSize = qsize + 1;
}
#else
__declspec(naked) void Helper_DrawCursor(s16 *entry)
{
    __asm {
        push    esi
        push    edi
        mov     edi, dword ptr [g_drawQueueSize]
        cmp     edi, 3000
        jge     done                                       ; long form
        mov     esi, dword ptr [esp + 0xc]
        movsx   eax, word ptr [esi + 2]
        mov     edx, eax
        mov     dword ptr [g_clipMaxScratch], eax         ; first: a3 form
        mov     dword ptr [g_clipMinScratch], edx         ; second: 89 15 form
        mov     cl, byte ptr [esi + 0x1a]
        test    cl, 0x20
        jne     skip_field6
        movsx   ecx, word ptr [esi + 6]
        cmp     ecx, eax
        jge     set_max_field6
        mov     edx, ecx
        mov     dword ptr [g_clipMinScratch], edx
        jmp     skip_field6
set_max_field6:
        mov     eax, ecx
        mov     dword ptr [g_clipMaxScratch], eax
skip_field6:
        movsx   ecx, word ptr [esi + 0xa]
        cmp     ecx, edx
        jge     skip_min_a
        mov     edx, ecx
        mov     dword ptr [g_clipMinScratch], edx
skip_min_a:
        movsx   ecx, word ptr [esi + 0xa]
        cmp     ecx, eax
        jle     skip_max_a
        mov     eax, ecx
        mov     dword ptr [g_clipMaxScratch], eax
skip_max_a:
        test    eax, eax
        jl      done
        cmp     edx, 0x1e0                                 ; 480
        jg      done
        cmp     edx, -100                                  ; 0xffffff9c sign-extended
        jge     y_block
        cmp     eax, 0x244                                 ; 580
        jg      done
y_block:
        movsx   eax, word ptr [esi]
        mov     edx, eax
        mov     dword ptr [g_clipMaxScratch], eax
        mov     dword ptr [g_clipMinScratch], edx
        mov     cl, byte ptr [esi + 0x1a]
        test    cl, 0x20
        jne     skip_field4
        movsx   ecx, word ptr [esi + 4]
        cmp     ecx, eax
        jge     set_max_field4
        mov     edx, ecx
        mov     dword ptr [g_clipMinScratch], edx
        jmp     skip_field4
set_max_field4:
        mov     eax, ecx
        mov     dword ptr [g_clipMaxScratch], eax
skip_field4:
        movsx   ecx, word ptr [esi + 8]
        cmp     ecx, edx
        jge     skip_min_8
        mov     edx, ecx
        mov     dword ptr [g_clipMinScratch], edx
skip_min_8:
        movsx   ecx, word ptr [esi + 8]
        cmp     ecx, eax
        jle     skip_max_8
        mov     eax, ecx
        mov     dword ptr [g_clipMaxScratch], eax
skip_max_8:
        test    eax, eax
        jl      done
        cmp     edx, 0x280                                 ; 640
        jg      done
        cmp     edx, -100                                  ; 0xffffff9c sign-extended
        jge     ok
        cmp     eax, 0x2e4                                 ; 740
        jg      done
ok:
        mov     eax, edi
        mov     ecx, 7
        shl     eax, 3
        sub     eax, edi
        lea     eax, [eax*4 + g_drawQueue]
        mov     edi, eax
        rep     movsd
        xor     ecx, ecx
        mov     cx, word ptr [eax + 0x12]
        mov     dx, word ptr [ecx*2 + g_zSortKeyLUT]
        mov     word ptr [eax + 0x12], dx
        mov     eax, dword ptr [g_drawQueueSize]
        inc     eax
        mov     dword ptr [g_drawQueueSize], eax
done:
        pop     edi
        pop     esi
        ret
    }
}
#endif
