/**
 * Eurocom heap allocator: first-fit walker with split.
 */
#include "engine/geo.h"
#include "platform/win32.h"
#include "audio/sound.h"

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

