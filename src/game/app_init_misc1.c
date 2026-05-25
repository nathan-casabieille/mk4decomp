/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b6180 (300b game.menu) - HUD font precache: trims dot-prefix names,
 *   opens font file, fread'd page-by-page into a backbuffer, then issues two
 *   matched draw passes via PaletteFillLineHybrid_004b5ce0 with float positions for each glyph.
 */
extern unsigned int g_dispatchSave529_004d29f8;
extern unsigned int g_dispatchSave528_004d29fc;
extern unsigned int g_dispatchVar40_004d505c;
extern unsigned int g_dispatchSave526_004f5398;
extern unsigned int g_dispatchSave525_004f5798;
extern unsigned int g_dispatchSave524_004f613c;
extern u16 g_texStripeBuf[];
extern unsigned int g_dispatchSave1348_00f6ce50;
extern unsigned int g_iat_004d21c4;
extern void FSYS_fclose(void);
extern void FSYS_fopen(void);
extern void FSYS_fread(void);
extern void FSYS_fseek(void);
extern void Helper_TexUpload(void);
extern void PaletteFillLineHybrid_004b5ce0(void);

__declspec(naked) void AppInit_Misc1(void) {
    __asm {
        sub     esp, 8
        push    ebx
        mov     ebx, dword ptr [g_iat_004d21c4]
        push    esi
        push    edi
        xor     edi, edi
        mov     esi, offset g_dispatchSave526_004f5398
    L_hfp_namelp:
        mov     eax, [esi]
        test    eax, eax
        jz      short L_hfp_nameadv
        cmp     byte ptr [eax], 0x2e
        jne     short L_hfp_nameadv
        push    2
        push    edi
        call    ebx
        mov     ecx, [esi]
        mov     [ecx], al
    L_hfp_nameadv:
        add     esi, 4
        inc     edi
        cmp     esi, offset g_dispatchSave525_004f5798
        jl      short L_hfp_namelp
        push    offset g_dispatchVar40_004d505c
        push    offset g_dispatchSave524_004f613c
        call    FSYS_fopen
        add     esp, 8
        mov     edi, eax
        push    0
        push    0x12
        push    edi
        call    FSYS_fseek
        add     esp, 0xc
        mov     esi, offset g_dispatchSave1348_00f6ce50
    L_hfp_readlp:
        push    edi
        push    1
        push    0x200
        push    esi
        call    FSYS_fread
        sub     esi, 0x200
        add     esp, 0x10
        cmp     esi, offset g_texStripeBuf
        jge     short L_hfp_readlp
        push    edi
        call    FSYS_fclose
        add     esp, 4
        push    0x100
        push    0x100
        push    0
        push    0
        push    0x0f
        call    Helper_TexUpload
        add     esp, 0x14
        mov     dword ptr [esp + 0xc], 0
        mov     esi, 1
    L_hfp_glyph:
        fild    dword ptr [esp + 0xc]
        fmul    dword ptr [g_dispatchSave529_004d29f8]
        fmul    dword ptr [g_dispatchSave528_004d29fc]
        fstp    dword ptr [esp + 0x10]
        mov     edi, [esp + 0x10]
        push    edi
        push    edi
        push    0x41f00000
        push    0x3f800000
        push    0
        push    0
        push    5
        push    0
        push    0x50
        push    esi
        call    PaletteFillLineHybrid_004b5ce0
        add     esp, 0x28
        push    0x3f800000
        push    0
        push    0
        push    edi
        push    edi
        push    0x41f00000
        push    5
        push    0
        push    0x55
        push    esi
        call    PaletteFillLineHybrid_004b5ce0
        mov     edx, [esp + 0x34]
        add     esp, 0x28
        add     esi, 3
        inc     edx
        cmp     esi, 0x61
        mov     [esp + 0xc], edx
        jl      short L_hfp_glyph
        push    0x100
        push    0x100
        push    0
        push    0
        push    0x0f
        call    Helper_TexUpload
        add     esp, 0x14
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 8
        ret
    }
}

