/**
 * Build 3x3 rotation matrix - axis order A.
 *
 * Same machinery as BuildRotMatrix_OrderC but the multiplication
 * tree differs - the orig stores into matrix slots in a different
 * order matching a different axis composition.
 */
#include "engine/scenegraph.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_sinTable (*(unsigned int *)MK4_VA(unsigned int, 0x7b01a0u))
#endif



/*
 * @addr 0x004b3800
 */
#ifdef NON_MATCHING
/* Co-exec verified (tools/decomp/verify_rot.py).
 *
 * g_sinTable is 4096 s32 entries indexed by BAM (0x1000 = 2 PI). Every read is
 * `>> 16`, and the products are `>> 12`, so the table holds sin * 2^28 and the
 * working values are Q12 - the same fixed point as the matrix itself.
 * Per the engine's identity cos(a) = -sinTable[(a - 0x400) & 0xfff]; the raw
 * (un-negated) table value is what the formulas below use, so the sign is
 * folded into the expressions exactly as the original does. Only entry +0xa is
 * a bare negation.
 *
 * NOTE: g_sinTable is ALL-ZERO in the static image - it is built at runtime,
 * like g_zSortKeyLUT and g_div3Table. Seed it or every matrix comes out 0.
 */
void BuildRotMatrix_OrderA(short *angles, short *mat3x3)
{
    const int *tab = (const int *)&g_sinTable;
    int x = angles[0], y = angles[1], z = angles[2];
    int sx  = tab[x & 0xfff] >> 16;
    int cxr = tab[(x - 0x400) & 0xfff] >> 16;
    int syr = tab[y & 0xfff] >> 16;
    int cyr = tab[(y - 0x400) & 0xfff] >> 16;
    int szr = tab[z & 0xfff] >> 16;
    int czr = tab[(z - 0x400) & 0xfff] >> 16;
    /* the orig truncates these two intermediates to 16 bits (movsx bx,bx) */
    int a = (short)((cyr * cxr) >> 12);
    int b = (short)((cxr * syr) >> 12);

    mat3x3[0] = (short)((czr * a + szr * syr) >> 12);
    mat3x3[1] = (short)((szr * a - czr * syr) >> 12);
    mat3x3[2] = (short)((cyr * sx) >> 12);
    mat3x3[3] = (short)((czr * sx) >> 12);
    mat3x3[4] = (short)((szr * sx) >> 12);
    mat3x3[5] = (short)(-cxr);
    mat3x3[6] = (short)((czr * b - cyr * szr) >> 12);
    mat3x3[7] = (short)((szr * b + czr * cyr) >> 12);
    mat3x3[8] = (short)((syr * sx) >> 12);
}
#else
__declspec(naked) void BuildRotMatrix_OrderA(s16 *angles, s16 *mat3x3)
{
    __asm {
        push    ecx                                       ; stack slot
        mov     eax, dword ptr [esp + 8]                  ; angles
        push    ebx
        push    ebp
        push    esi
        movsx   ecx, word ptr [eax]
        mov     edx, ecx
        add     ecx, 0xfffffc00
        and     edx, 0xfff
        and     ecx, 0xfff
        push    edi
        mov     esi, dword ptr [edx*4 + g_sinTable]
        mov     edx, dword ptr [ecx*4 + g_sinTable]
        movsx   ecx, word ptr [eax + 2]
        mov     edi, ecx
        add     ecx, 0xfffffc00
        and     ecx, 0xfff
        and     edi, 0xfff
        sar     esi, 16
        mov     ebx, dword ptr [ecx*4 + g_sinTable]
        mov     edi, dword ptr [edi*4 + g_sinTable]
        movsx   ecx, word ptr [eax + 4]
        sar     ebx, 16
        mov     ebp, ebx
        mov     eax, ecx
        imul    ebp, esi
        add     ecx, 0xfffffc00
        mov     dword ptr [esp + 0x18], esi
        mov     esi, dword ptr [esp + 0x1c]
        and     eax, 0xfff
        and     ecx, 0xfff
        mov     dword ptr [esp + 0x10], ebx
        mov     eax, dword ptr [eax*4 + g_sinTable]
        mov     ecx, dword ptr [ecx*4 + g_sinTable]
        sar     ebp, 12
        sar     edx, 16
        mov     word ptr [esi + 4], bp
        mov     ebp, edx
        neg     ebp
        imul    ebx, edx
        sar     edi, 16
        mov     word ptr [esi + 0xa], bp
        mov     ebp, edi
        imul    ebp, dword ptr [esp + 0x18]
        imul    edx, edi
        sar     ebx, 12
        sar     ebp, 12
        sar     ecx, 16
        movsx   ebx, bx
        mov     word ptr [esi + 0x10], bp
        mov     ebp, ecx
        sar     eax, 16
        imul    ebp, ebx
        mov     dword ptr [esp + 0x1c], ebx
        mov     ebx, eax
        imul    ebx, edi
        add     ebp, ebx
        mov     ebx, eax
        imul    ebx, dword ptr [esp + 0x1c]
        sar     ebp, 12
        mov     word ptr [esi], bp
        mov     ebp, ecx
        imul    ebp, edi
        sub     ebx, ebp
        mov     ebp, ecx
        sar     ebx, 12
        mov     word ptr [esi + 2], bx
        mov     ebx, dword ptr [esp + 0x18]
        imul    ebp, ebx
        sar     ebp, 12
        mov     word ptr [esi + 6], bp
        mov     ebp, eax
        imul    ebp, ebx
        mov     edi, dword ptr [esp + 0x10]
        mov     ebx, ecx
        sar     edx, 12
        sar     ebp, 12
        movsx   edx, dx
        mov     word ptr [esi + 8], bp
        mov     ebp, edi
        imul    ebx, edx
        imul    ebp, eax
        imul    eax, edx
        imul    ecx, edi
        sub     ebx, ebp
        add     eax, ecx
        sar     ebx, 12
        sar     eax, 12
        mov     word ptr [esi + 0xc], bx
        mov     word ptr [esi + 0xe], ax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
#endif
