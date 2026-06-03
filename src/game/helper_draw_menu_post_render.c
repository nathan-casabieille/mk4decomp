/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004b6880 (114b game.menu) - menu-quad submit: builds a
 *   30-byte draw command at 0x00ab41a8 (x,y / w+x,y+h / 0x7e mask /
 *   0xfe alpha / z=0x7fff / mode=0x22f) and dispatches via
 *   Helper_DrawCursor.
 */
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
extern void Helper_DrawCursor(void);

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


