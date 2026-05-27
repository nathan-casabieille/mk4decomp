/**
 * GEO loader entry points.
 */
#include "engine/geo.h"
#include "engine/fsys.h"
#include "engine/scenegraph.h"

/*
 * Convenience wrapper: load .geo textures with the default flag (0).
 *
 * @addr 0x004bd5b0
 */
void LoadGeoAsset_Default(void)
{
    LoadGeoAsset_Textures(0);
}

static const char $SG_geofmt[] = "c:\\source\\mk4\\win\\geogfx\\%s";

/*
 * @addr 0x004bd6e0
 *
 * Naked + __asm: scaled-base addressing (`[reg*4 + 0]`) plus the
 * mid-function rep-loop's reuse of the same `*ebp = 0` early-out
 * tail (after only `pop edi/esi/ebp/ebx`) makes the natural C form
 * unrepresentable. The original also clamps the texture-slot search
 * with a wrap-around using a register-pair counter that pure C will
 * not produce identically.
 *
 * Reads the .geo texture chunk (see geo_tex_chunk / geo_tex_entry in
 * include/engine/geo.h). Mapping of the raw offsets:
 *   mov eax,[esi+4]; lea esi,[eax+esi+4] ; esi = geo_tex_chunk (node+4+relofs)
 *   mov ax,[esi]; add esi,4              ; count = chunk->count; esi -> entries
 * tex_loop, per geo_tex_entry (esi = entry):
 *   mov ax,[esi]                         ; entry->width  -> Tex_DecodeRLE16 row_pixels
 *   mov cx,[esi+2]                       ; entry->height -> Tex_DecodeRLE16 row_count
 *   add esi,4; mov ebp,[esi]; add esi,4  ; ebp = entry->data_size; esi -> rle_data
 *   ...; lea esi,[esi+ebp*2]             ; advance past this entry's RLE stream
 */
__declspec(naked) void LoadGeoAsset_Textures(s32 flag)
{
    __asm {
        mov     eax, dword ptr [g_currentNodeIdx]
        push    ebx
        push    ebp
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [esi + 4]
        test    eax, eax
        lea     ebp, [esi + 4]
        push    edi
        jne     done_main
        call    Helper_GeoLoadPre
        mov     eax, dword ptr [esp + 0x14]
        mov     edx, dword ptr [esi]
        lea     ecx, [eax + eax*2]
        mov     eax, dword ptr [edx + ecx*4]
        push    eax
        push    offset $SG_geofmt
        lea     edi, [edx + ecx*4]
        push    offset g_geoAssetPath
        call    Helper_Sprintf
        add     esp, 0xc
        push    offset g_geoAssetPath
        call    FSYS_fsize
        mov     ebx, eax
        add     esp, 4
        test    ebx, ebx
        jne     have_size
        mov     dword ptr [ebp], eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
have_size:
        push    1
        push    ebx
        push    ebp
        call    Mem_Malloc
        mov     esi, eax
        add     esp, 0xc
        test    esi, esi
        jne     have_buf
        mov     dword ptr [ebp], eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
have_buf:
        push    ebx
        push    esi
        push    offset g_geoAssetPath
        call    FSYS_fload
        mov     edx, dword ptr [g_currentNodeIdx]
        xor     ecx, ecx
        mov     cx, word ptr [edi + 6]
        add     esp, 0xc
        mov     dword ptr [ecx*4 + g_texNodeIdx], edx
        mov     eax, dword ptr [esi + 4]
        xor     ecx, ecx
        mov     cx, word ptr [edi + 6]
        lea     esi, [eax + esi + 4]
        xor     eax, eax
        mov     ax, word ptr [esi]
        add     esi, 4
        test    eax, eax
        mov     dword ptr [ecx*4 + g_texCount], eax
        jle     post
        mov     edi, esi
        mov     dword ptr [esp + 0x14], eax
tex_loop:
        xor     eax, eax
        xor     ecx, ecx
        mov     ax, word ptr [esi]
        mov     cx, word ptr [esi + 2]
        add     esi, 2
        add     esi, 2
        mov     ebp, dword ptr [esi]
        add     esi, 4
        mov     word ptr [edi], 0xffff
        mov     edx, dword ptr [g_curTexSlot]
        xor     ebx, ebx
slot_scan:
        cmp     edx, 0xf
        jl      check_slot
        xor     edx, edx
check_slot:
        cmp     word ptr [edx*2 + g_texSlots], 0
        je      slot_free
        inc     ebx
        inc     edx
        cmp     ebx, 0xf
        jl      slot_scan
        mov     dword ptr [g_curTexSlot], edx
        jmp     advance
slot_free:
        push    esi
        push    ecx
        push    eax
        push    edx
        mov     dword ptr [g_curTexSlot], edx
        call    Tex_DecodeRLE16
        mov     dx, word ptr [g_curTexSlot]
        add     esp, 0x10
        mov     word ptr [edi], dx
        mov     ax, word ptr [g_curTexSlot]
        mov     word ptr [edi + 2], ax
        mov     ecx, dword ptr [g_curTexSlot]
        mov     word ptr [ecx*2 + g_texSlots], 0xffff
advance:
        mov     eax, dword ptr [esp + 0x14]
        add     edi, 4
        sar     ebp, 1
        dec     eax
        lea     esi, [esi + ebp*2]
        mov     dword ptr [esp + 0x14], eax
        jne     tex_loop
post:
        call    Helper_GeoLoadPost
done_main:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
