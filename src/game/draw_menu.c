/**
 * Per-frame menu renderer + slide-in animator.
 *
 * Walks the (text, _, next) linked list off `menu_items`, finding the
 * longest entry to compute the cursor box dimensions, animates the
 * menu position via g_menuCounter (0..100, magic-divide-by-100
 * interpolation), draws each entry centered horizontally, then draws
 * a cursor box around the selected entry. Detects a fresh-open by
 * comparing the new pointer to g_menuPrev and resets the animation
 * counter when they differ.
 */
#include "game/statemachine.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_menuCounter (*(unsigned int *)MK4_VA(unsigned int, 0xab4344u))
#define g_menuCurrent (*(unsigned int *)MK4_VA(unsigned int, 0xab433cu))
#define g_menuCursorBuf ((unsigned int *)MK4_VA(unsigned int, 0xab41a8u))
#define g_menuExtraDelta (*(unsigned int *)MK4_VA(unsigned int, 0xab4348u))
#define g_menuExtraSign (*(unsigned int *)MK4_VA(unsigned int, 0x4f579cu))
#define g_menuPrev (*(unsigned int *)MK4_VA(unsigned int, 0xab4340u))
#endif


/*
 * @addr 0x004b65c0
 *
 * Naked + __asm: the multi-pass layout (count entries, compute max
 * strlen, compute extents, animate in, draw loop, cursor render)
 * uses a stack-frame layout the C compiler wouldn't reproduce
 * verbatim - in particular `[esp+0x14]` and `[esp+0x18]` are reused
 * for both "extents-out" slots and animation scratch slots in a way
 * pure C struct locals don't compose.
 */
#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin.
 *
 * A menu is an array of 8-byte entries, [+0] a char* label, terminated by a
 * null label. The pass structure is: count the entries and the longest label,
 * ask Helper_GetMenuExtents for the screen box, centre the block, slide it in
 * or out over 100 counter units in steps of 14, draw each label centred, then
 * put the cursor quad around the selected row.
 *
 * The interpolation is a magic-multiply divide by 100 (0x51eb851f with the
 * sar 5 / sign fixup), written here as a plain signed `/ 100` - the compiler
 * emits the same reciprocal and both truncate toward zero.
 *
 * All three of `(width - textw) / 2`, `(height - texth) / 2` and the counter
 * interpolation are SIGNED in the original (`cdq ; sub ; sar`), so each keeps
 * an explicit int - see `make signed-audit`.
 *
 * The label pointers and the menu table itself are VAs, hence the MK4_PTR
 * derefs; a host pointer would not survive the round trip the engine does
 * through g_menuPrev / g_menuCurrent.
 *
 * The cursor quad is positioned from the row origin BEFORE the draw loop runs
 * - the original keeps it in a stack slot ([esp+0x28]) precisely because the
 * loop walks its own copy down the rows.
 *
 * Careful reading that block: it runs with the Helper_DrawCursor argument
 * already pushed, so every [esp+N] inside it is shifted by 4. The `[esp+0x1c]`
 * that sets the quad's right edge is therefore the TEXT WIDTH slot, not the
 * screen height - x + textw - 9, which is (scr_w + textw) / 2 - 9.
 */
s32 DrawMenu(void *menu_items, s32 selection)
{
    unsigned int  table = MK4_UNPTR(menu_items);
    unsigned int  cur   = g_menuCurrent;
    unsigned char *e;
    const char *txt;
    int count = 0, maxlen = 0, n;
    int textw, texth, scr_w, scr_h, x, y, ybase, yrow;
    int i;

    if (g_menuPrev != table) {
        if (cur == 0) {
            cur = g_menuPrev;
            g_menuCurrent = cur;
        }
        g_menuPrev = table;
        if (cur != 0)
            g_menuCounter = 0;
    }
    if (cur != 0)
        table = cur;
    if (table == 0)
        return 0;

    /* pass 1: entry count and longest label */
    e = (unsigned char *)MK4_PTR(table);
    while (*(unsigned int *)e != 0) {
        txt = (const char *)MK4_PTR(*(unsigned int *)e);
        for (n = 0; txt[n] != 0; n++)          /* the original inlines scasb */
            ;
        if (n > maxlen)
            maxlen = n;
        count++;
        e += 8;
    }

    textw = (maxlen + 4) * 9;
    texth = (count + 4) * 10;
    Helper_GetMenuExtents(&scr_w, &scr_h);

    x = (scr_w - textw) / 2;
    y = (scr_h - texth) / 2;

    /* pass 2: slide. The counter runs 0..100 in steps of 14; g_menuCurrent set
     * means the OLD menu is sliding out, clear means the new one slides in. */
    if (g_menuCurrent != 0) {
        g_menuCounter += 0xe;
        if (g_menuCounter >= 0x64) {
            g_menuCurrent = 0;
            g_menuCounter = 0x64;
        }
        y += (scr_h - y) * g_menuCounter / 100;
        if (g_menuCounter >= 0x64)
            g_menuCounter = 0;
    } else {
        g_menuCounter += 0xe;
        if (g_menuCounter >= 0x64)
            g_menuCounter = 0x64;
        y += (scr_h - y) * (0x64 - g_menuCounter) / 100;
    }

    /* pass 3: the labels, each centred on its own length */
    ybase = y;
    yrow  = y + 0x14;
    e = (unsigned char *)MK4_PTR(table);
    for (i = 0; i < count; i++) {
        txt = (const char *)MK4_PTR(*(unsigned int *)e);
        for (n = 0; txt[n] != 0; n++)
            ;
        Helper_DrawMenuText((s32)((unsigned int)(scr_w - n * 9) >> 1),
                            (s32)yrow, txt, 0, 0x7fff);
        yrow += 0xa;
        e += 8;
    }

    /* pass 4: the cursor quad, skipped entirely for a negative selection */
    if (selection >= 0) {
        /* &buf[0], not the bare name: as an arena alias - and in the co-exec
         * harness's generated defines - a bare global name is the VALUE at
         * that address, and indexing element zero is what yields the ADDRESS.
         * Spelled the other way the quad is written through a null pointer. */
        unsigned char *q = (unsigned char *)&g_menuCursorBuf[0];
        int pulse;

        g_menuExtraDelta += g_menuExtraSign;
        if (g_menuExtraDelta >= 0x20) {
            g_menuExtraDelta = 0x1f;
            g_menuExtraSign = -1;
        }
        if (g_menuExtraDelta < 0) {
            g_menuExtraDelta = 0;
            g_menuExtraSign = 1;
        }
        pulse = (unsigned char)(g_menuExtraDelta * 3) + 1;

        *(short *)(q + 0x00) = (short)(x + 9);
        *(short *)(q + 0x02) = (short)(y + 0x14 + selection * 10);
        *(short *)(q + 0x08) = (short)(x + textw - 9);
        *(short *)(q + 0x0a) = (short)(y + 0x14 + selection * 10 + 0xa);
        q[0x0c] = (unsigned char)pulse;
        q[0x0d] = 0x50;
        q[0x10] = (unsigned char)pulse;
        q[0x11] = 0x5b;
        *(short *)(q + 0x12) = 0;
        *(short *)(q + 0x14) = 0x7fff;
        *(short *)(q + 0x1a) = 0x3af;
        Helper_DrawCursor(q);
    }

    Helper_DrawMenu_PostRender((s32)x, (s32)ybase, (s32)textw, (s32)texth);
    return 1;
}
#else
__declspec(naked) s32 DrawMenu(void *menu_items, s32 selection)
{
    __asm {
        mov     ecx, dword ptr [g_menuPrev]
        mov     edx, dword ptr [esp + 4]
        mov     eax, dword ptr [g_menuCurrent]
        sub     esp, 0x20
        cmp     ecx, edx
        push    ebx
        push    ebp
        push    esi
        push    edi
        je      SHORT skip_save_check
        test    eax, eax
        jne     SHORT skip_set_cur
        mov     eax, ecx
        mov     dword ptr [g_menuCurrent], eax
skip_set_cur:
        test    eax, eax
        mov     dword ptr [g_menuPrev], edx
        je      SHORT exit_zero
        mov     dword ptr [g_menuCounter], 0
skip_save_check:
        test    eax, eax
        je      SHORT exit_zero
        mov     dword ptr [esp + 0x34], eax
        mov     edx, eax
exit_zero:
        test    edx, edx
        jne     SHORT have_items
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x20
        ret
have_items:
        mov     edi, dword ptr [edx]
        xor     ebx, ebx
        xor     esi, esi
        mov     dword ptr [esp + 0x10], ebx
        test    edi, edi
        je      SHORT count_done
count_loop:
        or      ecx, -1
        xor     eax, eax
        repne   scasb
        not     ecx
        dec     ecx
        cmp     ecx, esi
        jle     SHORT skip_max
        mov     esi, ecx
skip_max:
        mov     edi, dword ptr [edx + 8]
        add     edx, 8
        inc     ebx
        test    edi, edi
        jne     SHORT count_loop
        mov     dword ptr [esp + 0x10], ebx
count_done:
        lea     eax, [esi + 4]
        lea     ecx, [esp + 0x14]
        lea     edi, [eax + eax*8]
        lea     eax, [ebx + 4]
        mov     dword ptr [esp + 0x18], edi
        lea     ebp, [eax + eax*4]
        lea     eax, [esp + 0x1c]
        shl     ebp, 1
        push    eax
        push    ecx
        mov     dword ptr [esp + 0x28], ebp
        call    Helper_GetMenuExtents
        mov     esi, dword ptr [esp + 0x1c]
        add     esp, 8
        mov     eax, esi
        sub     eax, edi
        mov     edi, dword ptr [esp + 0x1c]
        cdq
        sub     eax, edx
        mov     ebx, eax
        mov     eax, edi
        sub     eax, ebp
        cdq
        sub     eax, edx
        mov     ecx, eax
        mov     eax, dword ptr [g_menuCurrent]
        sar     ebx, 1
        sar     ecx, 1
        test    eax, eax
        mov     eax, dword ptr [g_menuCounter]
        je      SHORT inactive_anim
        add     eax, 0xe
        cmp     eax, 0x64
        mov     dword ptr [g_menuCounter], eax
        jl      SHORT no_clamp_active
        mov     dword ptr [g_menuCurrent], 0
        mov     dword ptr [g_menuCounter], 0x64
no_clamp_active:
        sub     edi, ecx
        mov     eax, 0x51eb851f
        imul    edi, dword ptr [g_menuCounter]
        imul    edi
        sar     edx, 5
        mov     eax, edx
        shr     eax, 0x1f
        add     edx, eax
        mov     eax, dword ptr [g_menuCounter]
        add     ecx, edx
        cmp     eax, 0x64
        jl      SHORT after_anim
        mov     dword ptr [g_menuCounter], 0
        jmp     SHORT after_anim
inactive_anim:
        add     eax, 0xe
        cmp     eax, 0x64
        mov     dword ptr [g_menuCounter], eax
        jl      SHORT no_clamp_inactive
        mov     dword ptr [g_menuCounter], 0x64
no_clamp_inactive:
        mov     eax, dword ptr [g_menuCounter]
        mov     edx, 0x64
        sub     edi, ecx
        sub     edx, eax
        imul    edi, edx
        mov     eax, 0x51eb851f
        imul    edi
        sar     edx, 5
        mov     eax, edx
        shr     eax, 0x1f
        add     edx, eax
        add     ecx, edx
after_anim:
        mov     eax, dword ptr [esp + 0x10]
        mov     dword ptr [esp + 0x2c], ecx
        mov     edi, ebx
        add     ecx, 0x14
        test    eax, eax
        mov     dword ptr [esp + 0x24], edi
        mov     dword ptr [esp + 0x28], ecx
        mov     ebx, ecx
        jle     SHORT skip_draw_loop
        mov     ebp, dword ptr [esp + 0x34]
        mov     ecx, eax
        mov     dword ptr [esp + 0x34], ecx
        jmp     SHORT draw_loop_init
draw_loop_top:
        mov     esi, dword ptr [esp + 0x14]
draw_loop_init:
        mov     edx, dword ptr [ebp + 0]
        or      ecx, -1
        mov     edi, edx
        xor     eax, eax
        repne   scasb
        not     ecx
        dec     ecx
        push    0x7fff
        push    0
        push    edx
        lea     eax, [ecx + ecx*8]
        push    ebx
        sub     esi, eax
        shr     esi, 1
        push    esi
        call    Helper_DrawMenuText
        mov     eax, dword ptr [esp + 0x48]
        add     esp, 0x14
        add     ebx, 0xa
        add     ebp, 8
        dec     eax
        mov     dword ptr [esp + 0x34], eax
        jne     SHORT draw_loop_top
        mov     ebp, dword ptr [esp + 0x20]
        mov     edi, dword ptr [esp + 0x24]
        mov     ecx, dword ptr [esp + 0x28]
skip_draw_loop:
        mov     edx, dword ptr [esp + 0x38]
        test    edx, edx
        jl      skip_cursor
        mov     eax, dword ptr [g_menuExtraDelta]
        mov     ebx, dword ptr [g_menuExtraSign]
        add     eax, ebx
        cmp     eax, 0x20
        mov     dword ptr [g_menuExtraDelta], eax
        jl      SHORT no_max_clamp
        mov     eax, 0x1f
        mov     dword ptr [g_menuExtraSign], -1
        mov     dword ptr [g_menuExtraDelta], eax
no_max_clamp:
        test    eax, eax
        jge     SHORT no_min_clamp
        xor     eax, eax
        mov     dword ptr [g_menuExtraSign], 1
        mov     dword ptr [g_menuExtraDelta], eax
no_min_clamp:
        lea     edx, [edx + edx*4]
        push    offset g_menuCursorBuf
        mov     byte ptr [g_menuCursorBuf + 0xd], 0x50
        mov     byte ptr [g_menuCursorBuf + 0x11], 0x5b
        lea     ecx, [ecx + edx*2]
        lea     edx, [edi + 9]
        mov     word ptr [g_menuCursorBuf + 2], cx
        add     ecx, 0xa
        mov     word ptr [g_menuCursorBuf + 0xa], cx
        mov     cl, 3
        imul    cl
        mov     word ptr [g_menuCursorBuf + 0], dx
        mov     edx, dword ptr [esp + 0x1c]
        inc     al
        mov     word ptr [g_menuCursorBuf + 0x12], 0
        lea     edx, [edi + edx - 9]
        mov     byte ptr [g_menuCursorBuf + 0x10], al
        mov     word ptr [g_menuCursorBuf + 8], dx
        mov     byte ptr [g_menuCursorBuf + 0xc], al
        mov     word ptr [g_menuCursorBuf + 0x1a], 0x3af
        mov     word ptr [g_menuCursorBuf + 0x14], 0x7fff
        call    Helper_DrawCursor
        add     esp, 4
skip_cursor:
        mov     edx, dword ptr [esp + 0x18]
        mov     eax, dword ptr [esp + 0x2c]
        push    ebp
        push    edx
        push    eax
        push    edi
        call    Helper_DrawMenu_PostRender
        add     esp, 0x10
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x20
        ret
    }
}
#endif
