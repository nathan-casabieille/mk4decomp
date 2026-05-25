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
extern unsigned int g_word_00ab41a8;
extern unsigned int g_word_00ab41aa;
extern unsigned int g_word_00ab41b0;
extern unsigned int g_word_00ab41b2;
extern unsigned int g_word_00ab41ba;
extern unsigned int g_word_00ab41bc;
extern unsigned int g_word_00ab41c2;
extern unsigned int g_dispatchSave1474_00ab41b4;
extern unsigned int g_dispatchSave1475_00ab41b5;
extern unsigned int g_dispatchSave1476_00ab41b8;
extern unsigned int g_dispatchSave1477_00ab41b9;
extern void Helper_DrawCursor(void);

void Helper_DrawMenu_PostRender(void) {
    __asm {
        mov     ecx, dword ptr [esp + 8]
        mov     eax, dword ptr [esp + 4]
        mov     word ptr [g_word_00ab41a8], ax
        push    offset g_word_00ab41a8
        lea     edx, [ecx + 2]
        mov     word ptr [g_word_00ab41ba], 0
        mov     word ptr [g_word_00ab41aa], dx
        mov     edx, dword ptr [esp + 0x10]
        add     edx, eax
        mov     eax, dword ptr [esp + 0x14]
        add     eax, ecx
        mov     word ptr [g_word_00ab41b0], dx
        mov     word ptr [g_word_00ab41b2], ax
        mov     al, 0x7e
        mov     byte ptr [g_dispatchSave1474_00ab41b4], al
        mov     byte ptr [g_dispatchSave1475_00ab41b5], al
        mov     al, 0xfe
        mov     word ptr [g_word_00ab41c2], 0x22f
        mov     byte ptr [g_dispatchSave1476_00ab41b8], al
        mov     byte ptr [g_dispatchSave1477_00ab41b9], al
        mov     word ptr [g_word_00ab41bc], 0x7fff
        call    Helper_DrawCursor
        add     esp, 4
        }
}


