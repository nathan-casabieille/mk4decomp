/**
 * Build 3x3 rotation matrix - axis order C.
 *
 * Reads three 16-bit BAM angles from `angles[0..2]`, looks up
 * sin/cos via g_sinTable (4096-entry, 12-bit BAM input), and
 * multiplies them in a specific axis order to form a 3x3 16-bit
 * rotation matrix written to `mat3x3[0..8]`.
 */
#include "engine/scenegraph.h"

/*
 * @addr 0x004b36c0
 *
 * Naked + __asm: per-element computation interleaves the s16
 * matrix writes with the next sin/cos product, all using imul
 * + sar 12 + sar 16 fixed-point reductions and mov [esi + N]
 * stores. Pure C wouldn't reproduce the precise scheduling.
 */
#ifdef NON_MATCHING
/* Co-exec verified (tools/decomp/verify_rot.py).
 *
 * Axis order C. Same machinery as OrderA - g_sinTable is sin * 2^28 read
 * `>> 16` into Q12, products `>> 12` - but a different multiplication tree.
 * Note the NEGATE-BEFORE-SHIFT in three places: the original does
 * `neg / sar 0xc`, not `sar 0xc / neg`, and those differ for negative values.
 */
void BuildRotMatrix_OrderC(short *angles, short *mat3x3)
{
    const int *tab = (const int *)&g_sinTable;
    int x = angles[0], y = angles[1], z = angles[2];
    int sx  = tab[x & 0xfff] >> 16;
    int cxr = tab[(x - 0x400) & 0xfff] >> 16;
    int sy  = tab[y & 0xfff] >> 16;
    int cyr = tab[(y - 0x400) & 0xfff] >> 16;
    int sz  = tab[z & 0xfff] >> 16;
    int czr = tab[(z - 0x400) & 0xfff] >> 16;
    int p = (short)((cyr * cxr) >> 12);
    int q = (short)((-(cyr * sx)) >> 12);

    mat3x3[0] = (short)((sz * sy) >> 12);
    mat3x3[1] = (short)((-(czr * sy)) >> 12);
    mat3x3[2] = (short)cyr;
    mat3x3[3] = (short)((sz * p + czr * sx) >> 12);
    mat3x3[4] = (short)((sz * sx - czr * p) >> 12);
    mat3x3[5] = (short)((-(cxr * sy)) >> 12);
    mat3x3[6] = (short)((sz * q + czr * cxr) >> 12);
    mat3x3[7] = (short)((cxr * sz - czr * q) >> 12);
    mat3x3[8] = (short)((sy * sx) >> 12);
}
#else
__declspec(naked) void BuildRotMatrix_OrderC(s16 *angles, s16 *mat3x3)
{
    __asm {
        mov     eax, dword ptr [esp + 4]                  ; angles
        push    ebx
        push    ebp
        push    esi
        movsx   ecx, word ptr [eax]                       ; angles[0]
        mov     edx, ecx
        add     ecx, 0xfffffc00                            ; -0x400
        and     ecx, 0xfff
        and     edx, 0xfff
        push    edi
        mov     esi, dword ptr [esp + 0x18]               ; mat3x3
        mov     ebp, dword ptr [ecx*4 + g_sinTable]       ; sin?
        mov     edi, dword ptr [edx*4 + g_sinTable]       ; cos?
        movsx   ecx, word ptr [eax + 2]                   ; angles[1]
        mov     edx, ecx
        add     ecx, 0xfffffc00
        and     edx, 0xfff
        and     ecx, 0xfff
        sar     ebp, 16
        mov     ebx, dword ptr [edx*4 + g_sinTable]
        mov     dword ptr [esp + 0x14], ebp
        movsx   edx, word ptr [eax + 4]                   ; angles[2]
        sar     ebx, 16
        imul    ebp, ebx
        mov     ecx, dword ptr [ecx*4 + g_sinTable]
        mov     eax, edx
        add     edx, 0xfffffc00
        and     eax, 0xfff
        and     edx, 0xfff
        mov     eax, dword ptr [eax*4 + g_sinTable]
        mov     edx, dword ptr [edx*4 + g_sinTable]
        neg     ebp
        sar     ebp, 12
        mov     word ptr [esi + 0xa], bp
        mov     ebp, ebx
        sar     edi, 16
        imul    ebp, edi
        sar     ebp, 12
        sar     eax, 16
        mov     word ptr [esi + 0x10], bp
        mov     ebp, eax
        imul    ebp, ebx
        sar     ebp, 12
        sar     edx, 16
        mov     word ptr [esi], bp
        mov     ebp, edx
        sar     ecx, 16
        imul    ebp, ebx
        mov     ebx, ecx
        mov     word ptr [esi + 4], cx
        imul    ebx, dword ptr [esp + 0x14]
        imul    ecx, edi
        neg     ebp
        sar     ebx, 12
        sar     ebp, 12
        movsx   ebx, bx
        mov     word ptr [esi + 2], bp
        mov     ebp, edx
        mov     dword ptr [esp + 0x18], ebx
        imul    ebp, ebx
        mov     ebx, eax
        imul    ebx, edi
        sub     ebx, ebp
        mov     ebp, edx
        sar     ebx, 12
        imul    ebp, edi
        mov     word ptr [esi + 8], bx
        mov     ebx, eax
        imul    ebx, dword ptr [esp + 0x18]
        mov     edi, dword ptr [esp + 0x14]
        add     ebx, ebp
        neg     ecx
        sar     ecx, 12
        sar     ebx, 12
        movsx   ecx, cx
        mov     word ptr [esi + 6], bx
        mov     ebx, edx
        mov     ebp, edi
        imul    ebx, ecx
        imul    ebp, eax
        sub     ebp, ebx
        imul    eax, ecx
        imul    edx, edi
        add     eax, edx
        pop     edi
        sar     ebp, 12
        sar     eax, 12
        mov     word ptr [esi + 0xe], bp
        mov     word ptr [esi + 0xc], ax
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
#endif
