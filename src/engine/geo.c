/**
 * GEO loader entry points.
 */
#include "engine/geo.h"
#include "engine/fsys.h"
#include "engine/scenegraph.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#endif


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
#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern int  Helper_Sprintf(char *buf, const char *fmt, ...);
extern void Helper_GeoLoadPre(void);
extern void Helper_GeoLoadPost(void);
extern s32  Mem_Malloc(void **out_ptr, s32 size, s32 tag);
extern void Tex_DecodeRLE16(s32 slot, s32 width, s32 height, const u8 *src);

/* Portable twin. Loads one .geo file's texture chunk into the page.
 *
 * Node field +4 caches the loaded block, so a node that already has one is a
 * no-op - and on either failure (missing file, or the allocator handing back
 * nothing) it stores the failing value there, which leaves the node marked
 * unloaded and lets the next call retry.
 *
 * The name comes out of a table hanging off node field +0 at a stride of 12,
 * and is formatted into the 1998 build path "c:\source\mk4\win\geogfx\%s"
 * - the port's file layer reduces that to a basename.
 *
 * Slot allocation is a WRAPPING scan of the sixteen-entry occupancy table at
 * 0x00ab4e00, starting from wherever the last one left off and giving up after
 * fifteen tries. On giving up it still advances the cursor and skips the
 * decode, so the entry keeps the 0xffff it was pre-marked with rather than
 * pointing at somebody else's texture.
 *
 * Every pointer that lives in a 32-bit slot here - the node's block, the name,
 * the table base - is a VA, so it goes through the seam; the buffers handed to
 * the file layer and the decoder are host pointers. */
#ifdef TARGET_SDL
static int g_texGot, g_texLost, g_texSeen;
#endif

void LoadGeoAsset_Textures(s32 index)
{
    unsigned int node = g_currentNodeIdx * 4u;
    unsigned int entry, blk, chunk, rec, slotkey;
    unsigned int size;
    int count;

    if (*(unsigned int *)MK4_PTR(node + 4) != 0)
        return;

    Helper_GeoLoadPre();

    entry = *(unsigned int *)MK4_PTR(node) + (unsigned int)index * 12u;
    Helper_Sprintf(MK4_VA(char, 0x00ab43d8u),
                   (const char *)MK4_PTR(0x004f6584u),
                   (const char *)MK4_PTR(*(unsigned int *)MK4_PTR(entry)));

    size = FSYS_fsize(MK4_VA(char, 0x00ab43d8u));
#ifdef TARGET_SDL
    /* MK4_TRACE_GEO: every asset this loader is ASKED for, and whether the
     * archive actually has it. A fight that renders only fighters looks the
     * same whether the stage was never requested or was requested and
     * missing - this separates the two. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      if (getenv("MK4_TRACE_GEO"))
        SDL_Log("GEOLOAD \"%s\" size=%u node=%x%s",
                (const char *)MK4_VA(char, 0x00ab43d8u),
                size, g_currentNodeIdx, size ? "" : "  <-- ABSENT"); }
#endif
    if (size == 0) {
        *(unsigned int *)MK4_PTR(node + 4) = 0;
        return;
    }

    blk = (unsigned int)Mem_Malloc((void **)MK4_PTR(node + 4), (s32)size, 1);
    if (blk == 0) {
        *(unsigned int *)MK4_PTR(node + 4) = 0;
        return;
    }

    FSYS_fload(MK4_VA(char, 0x00ab43d8u), MK4_PTR(blk), size);

    slotkey = *(unsigned short *)MK4_PTR(entry + 6);
    *(unsigned int *)MK4_PTR(0x00ab4e78u + slotkey * 4u) = g_currentNodeIdx;

    chunk = blk + 4u + *(unsigned int *)MK4_PTR(blk + 4);
    count = *(unsigned short *)MK4_PTR(chunk);
    chunk += 4;
    *(unsigned int *)MK4_PTR(0x00ab5038u + slotkey * 4u) = (unsigned int)count;

    /* Two cursors, both starting at the chunk: `rec` walks the four-byte slot
     * records at a fixed stride, `chunk` walks the variable-length data. They
     * are the same address only on the first texture. */
    rec = chunk;
    while (count > 0) {
        unsigned int w     = *(unsigned short *)MK4_PTR(chunk);
        unsigned int h     = *(unsigned short *)MK4_PTR(chunk + 2);
        unsigned int words;
        unsigned int slot;
        int tries, found;

        chunk += 4;
        words = *(unsigned int *)MK4_PTR(chunk);
        chunk += 4;

        *(unsigned short *)MK4_PTR(rec) = 0xffff;

        slot  = *(unsigned int *)MK4_PTR(0x00ab4e74u);
        tries = 0;
        found = 0;
        for (;;) {
            if ((int)slot >= 0xf)
                slot = 0;
            if (*(unsigned short *)MK4_PTR(0x00ab4e00u + slot * 2u) == 0) {
                found = 1;
                break;
            }
            tries++;
            slot++;
            if (tries >= 0xf)
                break;
        }
        /* the cursor advances on BOTH exits - giving up still moves it on */
        *(unsigned int *)MK4_PTR(0x00ab4e74u) = slot;

#ifdef TARGET_SDL
        /* MK4_TRACE_TEX: how many textures actually get a page slot. There
         * are only fifteen (0xab4e00, 15 entries), and the claim loop gives
         * up silently when they are all taken - the record then keeps
         * whatever slot it had, which reads on screen as scrambled texels
         * rather than as a missing texture. */
        { extern char *getenv(const char *); extern void SDL_Log(const char *, ...);
          if (getenv("MK4_TRACE_TEX")) {
              if (found) g_texGot++; else g_texLost++;
              SDL_Log("TEXSLOT %s slot=%u %ux%u %s",
                      (const char *)MK4_VA(char, 0x00ab43d8u) + 24,
                      slot, w, h, found ? "" : "DENIED"); } }
#endif
        if (found) {
            Tex_DecodeRLE16((s32)slot, (s32)w, (s32)h, (const u8 *)MK4_PTR(chunk));
            slot = *(unsigned int *)MK4_PTR(0x00ab4e74u);
            *(unsigned short *)MK4_PTR(rec)     = (unsigned short)slot;
            *(unsigned short *)MK4_PTR(rec + 2) = (unsigned short)slot;
            *(unsigned short *)MK4_PTR(0x00ab4e00u + slot * 2u) = 0xffff;
        }

        rec   += 4;
        chunk += (unsigned int)(((int)words >> 1) * 2);
        count--;
    }

#ifdef TARGET_SDL
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      if (getenv("MK4_TRACE_TEX"))
          SDL_Log("TEX \"%s\": %d textures, claimed=%d denied=%d",
                  (const char *)MK4_VA(char, 0x00ab43d8u),
                  g_texGot + g_texLost - g_texSeen, g_texGot, g_texLost);
      g_texSeen = g_texGot + g_texLost; }
#endif
    Helper_GeoLoadPost();
}
#else
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
#endif
