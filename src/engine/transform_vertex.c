/**
 * Vertex shading: apply two diffuse lights to a working RGB555.
 *
 * Computes (arg1*Lx + arg2*Ly + arg3*Lz) for each of two light
 * vectors, clips negative dot products to zero, and adds per-
 * channel scaled contributions to the unpacked RGB components of
 * g_vtxColor. Each channel is clamped to 5 bits and the result is
 * repacked back into g_vtxColor.
 */
#include "engine/render.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_vtxColor (*(unsigned int *)MK4_VA(unsigned int, 0x7af9fcu))
#define g_vtxColorCopy (*(unsigned int *)MK4_VA(unsigned int, 0x7af9f8u))
#define g_vtxColorPrev (*(unsigned int *)MK4_VA(unsigned int, 0x7af9f0u))
#define g_vtxColorSaved (*(unsigned int *)MK4_VA(unsigned int, 0x7af9fau))
#define g_vtxLight0_x (*(unsigned int *)MK4_VA(unsigned int, 0x7af9d8u))
#define g_vtxLight0_y (*(unsigned int *)MK4_VA(unsigned int, 0x7af9dcu))
#define g_vtxLight0_z (*(unsigned int *)MK4_VA(unsigned int, 0x7af9e0u))
#define g_vtxLight1_x (*(unsigned int *)MK4_VA(unsigned int, 0x7af9e4u))
#define g_vtxLight1_y (*(unsigned int *)MK4_VA(unsigned int, 0x7af9ecu))
#define g_vtxLight1_z (*(unsigned int *)MK4_VA(unsigned int, 0x7af9e8u))
#define g_vtxRGBScale0_b (*(unsigned int *)MK4_VA(unsigned int, 0x7af9f2u))
#define g_vtxRGBScale0_g (*(unsigned int *)MK4_VA(unsigned int, 0x7af9f4u))
#define g_vtxRGBScale0_r (*(unsigned int *)MK4_VA(unsigned int, 0x7af9f6u))
#define g_vtxRGBScale1_b (*(unsigned int *)MK4_VA(unsigned int, 0x7af9f3u))
#define g_vtxRGBScale1_g (*(unsigned int *)MK4_VA(unsigned int, 0x7af9f5u))
#define g_vtxRGBScale1_r (*(unsigned int *)MK4_VA(unsigned int, 0x7af9f7u))
#endif


/*
 * @addr 0x004b3310
 *
 * Naked + __asm: no matching C form found. Patterns look like
 * hand-written __asm in the original source (common for 1997-era
 * per-vertex inner loops on MSVC 4.x/5.0):
 *   - inconsistent scale loads: `xor ebx,ebx; mov bl, [scale_r]`
 *     vs `mov ebx, [scale_g]; and ebx, 0xff` on same-type globals
 *   - useless spill/reload of ebx through [esp+0x18]
 *   - fail-first tail layout with explicit jmp from the success path
 */
#ifdef NON_MATCHING
/* Co-exec verified (tools/decomp/verify_project.py, pos/neg/mixed seeds).
 *
 * Argument mapping, recovered by counting the pushes (two of the comments in
 * the naked body below are off): at 3 pushes `[esp+0x18]` is Z, and at 5
 * pushes `[esp+0x18]` / `[esp+0x1c]` are X / Y. So edi=x, edx=y, ebp=z.
 *
 * Access widths matter here and are all explicit through the address:
 *   - the six RGB scales are PACKED BYTES at 0x7af9f2..f7, so a 32-bit read
 *     would pull in its neighbours (the original reads g_vtxRGBScale0_g as a
 *     dword and masks 0xff, which is the same byte);
 *   - g_vtxColor / g_vtxColorSaved / g_vtxColorCopy are stored as WORDS.
 *
 * Light 1's operand pairing looks wrong and is not: g_vtxLight1_y multiplies
 * Z and g_vtxLight1_z multiplies Y. The two NAMES are swapped relative to
 * their VAs (0x7af9e8 / 0x7af9ec), the arithmetic is the natural one.
 */
void TransformVertex(short x, short y, short z)
{
    int r, g, b, dot, t;
    unsigned int prev;
    /* One 16-bit accessor for the working colour: every read AND write below
       goes through it. Mixing a 32-bit read (the gdef lvalue) with a 16-bit
       store is a strict-aliasing violation and -O2 hoists the reads, so only
       the last store survives. */
    unsigned short *col = (unsigned short *)&g_vtxColor;

    /* two-deep colour history shift (16-bit each) */
    *(unsigned short *)&g_vtxColorCopy  = *(unsigned short *)&g_vtxColorSaved;
    *(unsigned short *)&g_vtxColorSaved = *col;

    prev = g_vtxColorPrev & 0xffff;
    r = (int)((prev >> 10) & 0x1f);
    g = (int)((prev >> 5) & 0x1f);
    b = (int)(prev & 0x1f);

    /* light 0 - products accumulate through unsigned (signed overflow is UB) */
    dot = (int)((unsigned)((int)g_vtxLight0_x * (int)x)
              + (unsigned)((int)g_vtxLight0_y * (int)y)
              + (unsigned)((int)g_vtxLight0_z * (int)z)) >> 0xc;
    if (dot > 0) {
        t = (int)((unsigned)*(unsigned char *)&g_vtxRGBScale0_r * (unsigned)dot);
        r += t >> 0xc;
        t = (int)((unsigned)*(unsigned char *)&g_vtxRGBScale0_g * (unsigned)dot);
        g += t >> 0xc;
        t = (int)((unsigned)*(unsigned char *)&g_vtxRGBScale0_b * (unsigned)dot);
        b += t >> 0xc;
    }

    /* light 1 - see the note above about the y/z naming */
    dot = (int)((unsigned)((int)g_vtxLight1_x * (int)x)
              + (unsigned)((int)g_vtxLight1_y * (int)z)
              + (unsigned)((int)g_vtxLight1_z * (int)y)) >> 0xc;
    if (dot > 0) {
        t = (int)((unsigned)*(unsigned char *)&g_vtxRGBScale1_r * (unsigned)dot);
        r += t >> 0xc;
        t = (int)((unsigned)*(unsigned char *)&g_vtxRGBScale1_g * (unsigned)dot);
        g += t >> 0xc;
        t = (int)((unsigned)*(unsigned char *)&g_vtxRGBScale1_b * (unsigned)dot);
        b += t >> 0xc;
    }

    /* repack one channel at a time, each step storing g_vtxColor as a word.
       Note these are NOT clamps to [0,31]: a negative channel keeps its value
       and is folded by the following mask, exactly as the original does. */
    if (r > 0x1f)
        r = 0x1f;
    *col = (unsigned short)((*col & 0x83ff) | (unsigned)((r & 0x1f) << 10));

    t = (g > 0x1f) ? 0x1f : g;
    *col = (unsigned short)((*col & 0xfc1f) | (unsigned)((t & 0x1f) << 5));

    t = (b > 0x1f) ? 0x1f : b;
    /* blue goes in by XOR: cx ^= (colour ^ blue) & 0x1f */
    *col = (unsigned short)(*col ^ ((*col ^ (unsigned)t) & 0x1f));
}
#else
__declspec(naked) void TransformVertex(s16 x, s16 y, s16 z)
{
    __asm {
        push    ecx
        mov     ax, word ptr [g_vtxColorSaved]
        mov     cx, word ptr [g_vtxColor]
        mov     word ptr [g_vtxColorCopy], ax
        mov     eax, dword ptr [g_vtxColorPrev]
        push    ebx
        mov     ebx, dword ptr [g_vtxLight0_z]
        push    ebp
        and     eax, 0xffff
        movsx   ebp, word ptr [esp + 0x18]                ; arg2 (y)
        push    esi
        mov     word ptr [g_vtxColorSaved], cx
        mov     ecx, eax
        mov     esi, eax
        push    edi
        and     eax, 0x1f                                  ; B (bits 0-4)
        movsx   edi, word ptr [esp + 0x18]                ; arg1 (x)
        imul    ebx, ebp
        mov     dword ptr [esp + 0x10], eax                ; save B
        mov     eax, dword ptr [g_vtxLight0_x]
        imul    eax, edi
        movsx   edx, word ptr [esp + 0x1c]                ; arg3 (z)
        add     eax, ebx
        mov     ebx, dword ptr [g_vtxLight0_y]
        imul    ebx, edx
        add     eax, ebx
        shr     ecx, 10
        shr     esi, 5
        sar     eax, 12
        and     ecx, 0x1f                                  ; R (bits 10-14)
        and     esi, 0x1f                                  ; G (bits 5-9)
        test    eax, eax
        jle     skip_light0
        xor     ebx, ebx
        mov     bl, byte ptr [g_vtxRGBScale0_r]
        imul    ebx, eax
        sar     ebx, 12
        add     ecx, ebx                                   ; R += scale_r * dot
        mov     ebx, dword ptr [g_vtxRGBScale0_g]
        and     ebx, 0xff
        imul    ebx, eax
        sar     ebx, 12
        add     esi, ebx                                   ; G += scale_g * dot
        xor     ebx, ebx
        mov     bl, byte ptr [g_vtxRGBScale0_b]
        imul    ebx, eax
        sar     ebx, 12
        mov     dword ptr [esp + 0x18], ebx
        mov     ebx, dword ptr [esp + 0x10]
        mov     eax, dword ptr [esp + 0x18]
        add     ebx, eax
        jmp     light1_dot
skip_light0:
        mov     ebx, dword ptr [esp + 0x10]
light1_dot:
        mov     eax, dword ptr [g_vtxLight1_x]
        imul    eax, edi
        mov     edi, dword ptr [g_vtxLight1_y]
        imul    edi, ebp
        add     eax, edi
        mov     edi, dword ptr [g_vtxLight1_z]
        imul    edi, edx
        add     eax, edi
        sar     eax, 12
        test    eax, eax
        jle     clamp_r
        xor     edx, edx
        mov     dl, byte ptr [g_vtxRGBScale1_r]
        imul    edx, eax
        sar     edx, 12
        add     ecx, edx
        xor     edx, edx
        mov     dl, byte ptr [g_vtxRGBScale1_g]
        imul    edx, eax
        sar     edx, 12
        add     esi, edx
        xor     edx, edx
        mov     dl, byte ptr [g_vtxRGBScale1_b]
        imul    edx, eax
        sar     edx, 12
        add     ebx, edx
clamp_r:
        cmp     ecx, 0x1f
        jle     r_ok
        mov     ecx, 0x1f
r_ok:
        mov     eax, dword ptr [g_vtxColor]
        and     ecx, 0x1f
        and     eax, 0x83ff
        shl     ecx, 10
        or      eax, ecx
        cmp     esi, 0x1f
        mov     word ptr [g_vtxColor], ax
        mov     eax, 0x1f
        jg      g_clamped
        mov     eax, esi
g_clamped:
        mov     ecx, dword ptr [g_vtxColor]
        and     eax, 0x1f
        and     ecx, 0xfc1f
        shl     eax, 5
        or      ecx, eax
        cmp     ebx, 0x1f
        mov     word ptr [g_vtxColor], cx
        mov     eax, 0x1f
        jg      b_clamped
        mov     eax, ebx
b_clamped:
        mov     dl, byte ptr [g_vtxColor]
        pop     edi
        xor     dl, al
        pop     esi
        and     edx, 0x1f
        pop     ebp
        xor     cx, dx
        pop     ebx
        mov     word ptr [g_vtxColor], cx
        pop     ecx
        ret
    }
}
#endif
