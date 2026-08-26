/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "game/statemachine.h"   /* Helper_DrawCursor, g_menuCursorBuf */

/*
 * @addr 0x004b6880 (114b game.menu) - menu-quad submit: builds a
 *   30-byte draw command at 0x00ab41a8 (x,y / w+x,y+h / 0x7e mask /
 *   0xfe alpha / z=0x7fff / mode=0x22f) and dispatches via
 *   Helper_DrawCursor.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cursorQuad_x0;
extern unsigned int g_cursorQuad_y0;
extern unsigned int g_cursorQuad_x2;
extern unsigned int g_cursorQuad_y2;
extern unsigned int g_cursorQuad_pad;
extern unsigned int g_cursorQuad_sortKey;
extern unsigned int g_cursorQuad_flags;
extern unsigned int g_dispatchSave1474;
extern unsigned int g_dispatchSave1475;
extern unsigned int g_dispatchSave1476;
extern unsigned int g_dispatchSave1477;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_cursorQuad_flags (*(unsigned int *)MK4_VA(unsigned int, 0xab41c2u))
#define g_cursorQuad_pad (*(unsigned int *)MK4_VA(unsigned int, 0xab41bau))
#define g_cursorQuad_sortKey (*(unsigned int *)MK4_VA(unsigned int, 0xab41bcu))
#define g_cursorQuad_x0 (*(unsigned int *)MK4_VA(unsigned int, 0xab41a8u))
#define g_cursorQuad_x2 (*(unsigned int *)MK4_VA(unsigned int, 0xab41b0u))
#define g_cursorQuad_y0 (*(unsigned int *)MK4_VA(unsigned int, 0xab41aau))
#define g_cursorQuad_y2 (*(unsigned int *)MK4_VA(unsigned int, 0xab41b2u))
#define g_dispatchSave1474 (*(unsigned int *)MK4_VA(unsigned int, 0xab41b4u))
#define g_dispatchSave1475 (*(unsigned int *)MK4_VA(unsigned int, 0xab41b5u))
#define g_dispatchSave1476 (*(unsigned int *)MK4_VA(unsigned int, 0xab41b8u))
#define g_dispatchSave1477 (*(unsigned int *)MK4_VA(unsigned int, 0xab41b9u))
#define g_menuCursorBuf ((unsigned int *)MK4_VA(unsigned int, 0xab41a8u))
#endif


#ifdef NON_MATCHING

/* Portable twin - the frame around the menu block, drawn as one quad.
 *
 * Note the argument slots: the `push 0xab41a8` happens before the last two are
 * read, so the original's [esp+0x10] / [esp+0x14] are arguments 3 and 4, the
 * text width and height.
 *
 * `&buf[0]` rather than the bare name: as an arena alias - and in the co-exec
 * harness's generated defines - a bare global name is the VALUE at that
 * address, not the address itself. */
void Helper_DrawMenu_PostRender(int x, int y, int textw, int texth)
{
    unsigned char *q = (unsigned char *)&g_menuCursorBuf[0];

    *(short *)(q + 0x00) = (short)x;
    *(short *)(q + 0x12) = 0;
    *(short *)(q + 0x02) = (short)(y + 2);
    *(short *)(q + 0x08) = (short)(textw + x);
    *(short *)(q + 0x0a) = (short)(texth + y);
    q[0x0c] = 0x7e;
    q[0x0d] = 0x7e;
    *(short *)(q + 0x1a) = 0x22f;
    q[0x10] = 0xfe;
    q[0x11] = 0xfe;
    *(short *)(q + 0x14) = 0x7fff;
    Helper_DrawCursor(q);
}
#else
void Helper_DrawMenu_PostRender(void) {
    __asm {
        mov     ecx, dword ptr [esp + 8]
        mov     eax, dword ptr [esp + 4]
        mov     word ptr [g_cursorQuad_x0], ax
        push    offset g_cursorQuad_x0
        lea     edx, [ecx + 2]
        mov     word ptr [g_cursorQuad_pad], 0
        mov     word ptr [g_cursorQuad_y0], dx
        mov     edx, dword ptr [esp + 0x10]
        add     edx, eax
        mov     eax, dword ptr [esp + 0x14]
        add     eax, ecx
        mov     word ptr [g_cursorQuad_x2], dx
        mov     word ptr [g_cursorQuad_y2], ax
        mov     al, 0x7e
        mov     byte ptr [g_dispatchSave1474], al
        mov     byte ptr [g_dispatchSave1475], al
        mov     al, 0xfe
        mov     word ptr [g_cursorQuad_flags], 0x22f
        mov     byte ptr [g_dispatchSave1476], al
        mov     byte ptr [g_dispatchSave1477], al
        mov     word ptr [g_cursorQuad_sortKey], 0x7fff
        call    Helper_DrawCursor
        add     esp, 4
        }
}
#endif


