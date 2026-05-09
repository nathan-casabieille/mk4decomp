/**
 * Submit a 28-byte draw entry to g_drawQueue.
 *
 * Bounds-checks the entry's X coords (fields at +2/+6/+a) and Y
 * coords (fields at +0/+4/+8) against viewport thresholds, skips
 * the entry if out-of-bounds. Otherwise copies it into
 * g_drawQueue[g_drawQueueSize] and rewrites the 16-bit sort key
 * at +0x12 via g_zSortKeyLUT.
 */
#include "engine/render.h"

/*
 * @addr 0x004c3360
 *
 * Naked + __asm: the body has two near-identical X/Y bounds
 * loops that mutate the same g_clipMin/g_clipMax scratch globals,
 * different field offsets per loop, then a rep movsd copy
 * + word patch through g_zSortKeyLUT.
 */
__declspec(naked) void SubmitDrawEntry(s16 *entry)
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
