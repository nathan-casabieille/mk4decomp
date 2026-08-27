/**
 * Eurocom heap allocator: first-fit walker with split.
 */
#include "engine/geo.h"
#include "platform/win32.h"
#include "audio/sound.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_memHeapEnd ((unsigned char *)MK4_VA(unsigned char, 0xab4194u))
#define g_memHeapStart ((unsigned char *)MK4_VA(unsigned char, 0x7b41a0u))
#endif


/* The "Mem_Malloc()" string literal. MSVC folds duplicate strings
 * across .obj inputs in the .rdata pool at link time, so the
 * matching diff masks the relocation regardless of which copy ends
 * up at the original VA. */
static const char k_memMallocMsg[] = "Mem_Malloc()";

/*
 * @addr 0x004b5bc0
 *
 * Naked + __asm: the function walks an in-place free list with
 * very specific bit operations on the 32-bit header word
 * (high bit = free, top byte = tag, low 24 bits = size). Everything
 * threads through eax/ecx/edx/edi/esi in a way pure C wouldn't
 * match.
 *
 * Args (cdecl): arg1 = out_ptr, arg2 = size, arg3 = tag.
 */
#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void ShowErrorMessage(const char *msg);
extern void Helper_MemMalloc_Post(void);

/* Portable twin, and the header format is Mem_Free's: high bit free, top byte
 * tag, low 24 bits size.
 *
 * Two things about the walk are not what the "first-fit" comment claims and
 * are transcribed as written. It keeps scanning after a hit and OVERWRITES the
 * candidate, so what it takes is the LAST free block large enough, not the
 * first. And when nothing fits it reports the error and then falls through to
 * dereference the null candidate anyway - so a failed allocation crashes here
 * rather than returning null. Neither is corrected.
 *
 * It carves the request off the END of the chosen block, which is why the
 * survivor keeps the original address and only its size word changes.
 *
 * out_ptr is a HOST pointer - the original dereferences it - but everything it
 * stores is a VA: the user pointer into the caller's slot, and the slot's own
 * address into the block's owner word, which is exactly what Mem_Free later
 * reads back. */
s32 Mem_Malloc(void **out_ptr, s32 size, s32 tag)
{
    /* One arena base, then plain VA indexing - the header words are all at
     * absolute VAs, and this keeps the twin self-contained for the co-exec
     * harness (which compiles the function body alone). */
    unsigned char *A = (unsigned char *)MK4_PTR(0u);
    unsigned int need = ((unsigned int)size + 0x1bu) & ~3u;
    unsigned int blk  = 0x007b41a0u;              /* g_memHeapStart */
    unsigned int best = 0;
    unsigned int hdr, room, orig;

    do {
        hdr = *(unsigned int *)(A + blk);
        if ((hdr & 0x80000000u) && (hdr & 0xffffffu) >= need)
            best = blk;                 /* keeps scanning: LAST fit wins */
        blk += hdr & 0xffffffu;
    } while (blk < 0x00ab4194u);         /* g_memHeapEnd */

    if (best == 0)
        /* the original pushes the pooled literal's own VA */
        ShowErrorMessage((const char *)MK4_PTR(0x004f4f20u));

    need -= 0xc;
    orig  = *(unsigned int *)(A + best);
    room  = (orig & 0xffffffu) - need;
    blk   = best + room;                 /* carve off the END of the block */

    *(unsigned int *)(A + blk + 4) = (unsigned int)MK4_UNPTR(out_ptr);
    *(unsigned int *)(A + blk)     = (need & 0xffffffu)
                                   | (((unsigned int)tag & 0x3fu) << 24);

    if ((orig & 0xffffffu) != need) {
        unsigned int prev = *(unsigned int *)(A + best);
        unsigned int next;

        *(unsigned int *)(A + blk + 8) = best;
        /* replace only the low 24 bits, keeping the tag and the free bit */
        *(unsigned int *)(A + best) =
            ((((prev - need) ^ prev) & 0xffffffu) ^ prev) | 0x80000000u;

        next = blk + (*(unsigned int *)(A + blk) & 0xffffffu);
        if (next < 0x00ab4194u)
            *(unsigned int *)(A + next + 8) = blk;
    }

    *(unsigned int *)out_ptr = blk + 0xc;
    Helper_MemMalloc_Post();
    return (s32)*(unsigned int *)out_ptr;
}
#else
__declspec(naked) s32 Mem_Malloc(void **out_ptr, s32 size, s32 tag)
{
    __asm {
        mov     eax, dword ptr [esp + 8]            ; arg2 (size)
        push    ebx
        push    esi
        push    edi
        lea     edi, [eax + 0x1b]                   ; size + 27
        mov     ecx, offset g_memHeapStart
        and     edi, 0xfffffffc                     ; round to mult of 4
        xor     esi, esi
walk:
        mov     eax, dword ptr [ecx]
        test    eax, 0x80000000                     ; free?
        jz      not_free
        mov     edx, eax
        and     edx, 0x00ffffff
        cmp     edx, edi
        jb      not_free
        mov     esi, ecx                            ; remember candidate
not_free:
        and     eax, 0x00ffffff
        add     ecx, eax
        cmp     ecx, offset g_memHeapEnd
        jb      walk
        test    esi, esi
        jne     found
        push    offset k_memMallocMsg                         ; "Mem_Malloc()"
        call    ShowErrorMessage
        add     esp, 4
found:
        mov     ecx, dword ptr [esi]
        sub     edi, 12
        and     ecx, 0x00ffffff
        mov     eax, esi
        sub     ecx, edi
        mov     ebx, dword ptr [esp + 0x10]         ; arg1 (out_ptr)
        add     esi, ecx                            ; esi = end of free remainder = start of alloc
        mov     ecx, dword ptr [esp + 0x18]         ; arg3 (tag)
        mov     edx, edi
        and     ecx, 0x3f
        and     edx, 0x00ffffff
        mov     dword ptr [esi + 4], ebx
        shl     ecx, 24
        or      edx, ecx
        mov     dword ptr [esi], edx
        mov     edx, dword ptr [eax]                ; orig free header
        and     edx, 0x00ffffff
        cmp     edx, edi
        je      tail
        mov     dword ptr [esi + 8], eax            ; alloc.prev = old block start
        mov     ecx, dword ptr [eax]
        mov     edx, ecx
        sub     edx, edi
        xor     edx, ecx
        and     edx, 0x00ffffff
        xor     edx, ecx                            ; preserve tag, replace size
        or      edx, 0x80000000                     ; mark free
        mov     dword ptr [eax], edx
        mov     eax, dword ptr [esi]
        and     eax, 0x00ffffff
        add     eax, esi                            ; end of new alloc
        cmp     eax, offset g_memHeapEnd
        jae     tail
        mov     dword ptr [eax + 8], esi            ; next-block.prev = our alloc
tail:
        add     esi, 12
        mov     dword ptr [ebx], esi
        call    Helper_MemMalloc_Post
        mov     eax, dword ptr [ebx]
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}

#endif
