/**
 * Build the z-sort-key LUT and the i/3 byte table.
 *
 * Two-pass init called once at boot:
 *  - clear g_paletteScratch (1 MB), then run Helper_PaletteInit
 *  - fill g_zSortKeyLUT[i] = round(i * 65536 / (31 * i + 65536))
 *    for i in [0..65535]
 *  - fill g_div3Table[i] = i / 3 for i in [0..767]
 */
#include "engine/scenegraph.h"
#include "engine/render.h"

extern void _ftol(void);                            /* 0x004c57d0 */

static const double k_31         = 31.0;            /* 0x004d2a50 */
static const double k_inv_65536  = 1.52587890625e-05; /* 0x004d2a58 = 1/65536 */
static const double k_neg_one    = -1.0;            /* 0x004d2a60 */

/*
 * @addr 0x004bf290
 *
 * Naked + __asm because:
 *  - The prologue uses `push ecx` as a 1-byte stack-slot allocation
 *    (vs `sub esp, 4` = 3 bytes); MSVC won't emit that from a C
 *    "u32 i" local declaration.
 *  - The FPU sequence (fld st(0); fmul; fmul; fsub neg-one; fdivr)
 *    encodes one specific evaluation tree of the bucket formula -
 *    pure C would re-associate.
 *  - The 768-entry tail uses the imul-magic / sar 0x1f / add idiom
 *    for n/3, which is hard to coax from `n / 3` literally.
 */
__declspec(naked) void BuildSortKeyLUT(void)
{
    __asm {
        push    ecx                              ; allocate stack slot for `i`
        push    esi
        push    edi
        mov     ecx, 0x108000
        xor     eax, eax
        mov     edi, offset g_paletteScratch
        push    eax                              ; arg=0 for Helper_PaletteInit
        rep     stosd                            ; clear g_paletteScratch
        call    Helper_PaletteInit
        add     esp, 4
        mov     dword ptr [esp + 8], 0           ; i = 0
        mov     esi, offset g_zSortKeyLUT
loop_top:
        fild    dword ptr [esp + 8]              ; st0 = (double)i
        fld     st(0)                            ; st1 = i, st0 = i
        fmul    qword ptr [k_31]                 ; st0 = 31*i
        fmul    qword ptr [k_inv_65536]          ; st0 = 31*i/65536
        fsub    qword ptr [k_neg_one]            ; st0 = 31*i/65536 + 1
        fdivr   st(0), st(1)                     ; st0 = i / (31*i/65536 + 1)
        call    _ftol                            ; eax = (s32)st0; pop FPU
        mov     ecx, dword ptr [esp + 8]
        mov     word ptr [esi], ax
        add     esi, 2
        inc     ecx
        cmp     esi, offset g_zSortKeyLUT + 0x20000
        mov     dword ptr [esp + 8], ecx
        fstp    st(0)                            ; pop the dup'd st1
        jl      loop_top
        xor     ecx, ecx
div3_top:
        mov     eax, 0x55555556
        imul    ecx
        mov     eax, edx
        shr     eax, 31
        add     edx, eax
        mov     byte ptr [ecx + g_div3Table], dl
        inc     ecx
        cmp     ecx, 0x300
        jl      div3_top
        pop     edi
        pop     esi
        pop     ecx
        ret
    }
}
