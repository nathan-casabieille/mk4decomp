/**
 * Submit a 28-byte draw entry (DrawEntry, see
 * include/engine/render_types.h) to g_drawQueue.
 *
 * Bounds-checks the entry against the viewport in two loops: first the
 * Y coords (DrawEntry.y0/y1/y2 at +2/+6/+0xa) against the height
 * envelope (480/580), then the X coords (DrawEntry.x0/x1/x2 at
 * +0/+4/+8) against the width envelope (640/740). Skips the entry if
 * out-of-bounds; otherwise copies it into g_drawQueue[g_drawQueueSize]
 * and rewrites DrawEntry.sort_key at +0x12 via g_zSortKeyLUT. Vertex 1
 * (x1/y1) is skipped in both loops when flags (+0x1a) bit 0x20 is set.
 */
#include "engine/render.h"
#include "engine/render_types.h"

/*
 * @addr 0x004c3360
 *
 * Naked + __asm: the body has two near-identical X/Y bounds
 * loops that mutate the same g_clipMin/g_clipMax scratch globals,
 * different field offsets per loop, then a rep movsd copy
 * + word patch through g_zSortKeyLUT.
 */
__declspec(naked) void Helper_DrawCursor(s16 *entry)
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
