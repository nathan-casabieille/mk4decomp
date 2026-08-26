/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* Menu_DirectDrawUnavailableDialog - sister of 0x4b8630 for 0x004f5070 menu. */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_menuFlagsSub1b;
extern unsigned int g_gsmVar;
extern unsigned int g_dispatchSave869;
extern unsigned int g_dispatchSave1487;
extern unsigned int g_dispatchSave1497;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_dispatchSave1487 (*(unsigned int *)MK4_VA(unsigned int, 0xab4310u))
#define g_dispatchSave1497 (*(unsigned int *)MK4_VA(unsigned int, 0xab4370u))
#define g_dispatchSave869 (*(unsigned int *)MK4_VA(unsigned int, 0x4f5074u))
#define g_gsmVar (*(unsigned int *)MK4_VA(unsigned int, 0x4f5070u))
#define g_menuFlagsSub1b (*(unsigned int *)MK4_VA(unsigned int, 0xab4308u))
#endif

/* Real signatures. The auto-generated placeholders all said `(void)`, but the
 * original pushes two stack args for the two selectable-scanners and one for
 * the poll, and every caller uses the returned value. */
extern int          DrawMenu(void *menu, int sel);
extern unsigned int Menu_PollNavInput(int mode);
extern unsigned int Menu_FindNextSelectable(int cur, void *menu);
extern unsigned int Menu_FindPrevSelectable(int cur, void *menu);

#ifdef NON_MATCHING
/* Portable twin. Instruction for instruction the same shape as
 * Menu_Direct3DUnavailableDialog (71 instructions each, identical mnemonic
 * sequence) - only the flag byte, the menu base and the two state slots
 * differ, so this is that verified twin with those substituted.
 *
 * The menu table strides 8 BYTES per entry with a s16 at +4, hence the char
 * pointer: on a uint pointer the offset strides 32. */
int Menu_DirectDrawUnavailableDialog(void)
{
    unsigned int nav;

    if ((g_menuFlagsSub1b & 1) == 0) {
        g_menuFlagsSub1b = g_menuFlagsSub1b | 1;
        g_dispatchSave1487 = Menu_FindNextSelectable(0, &g_gsmVar);
    }
    if (g_dispatchSave1497 == 0) {
        g_dispatchSave1497 = 2;
    } else if (g_dispatchSave1497 == 2) {
        nav = Menu_PollNavInput(1);
        if (((nav & 0x8000) == 0) && ((nav & 1) != 0)) {
            g_dispatchSave1487 = Menu_FindPrevSelectable(g_dispatchSave1487, &g_gsmVar);
        }
        if ((nav & 0x8000) == 0) {
            if ((nav & 2) != 0) {
                g_dispatchSave1487 = Menu_FindNextSelectable(g_dispatchSave1487, &g_gsmVar);
            }
            if ((nav & 0x10) != 0) {
                g_dispatchSave1497 = (int)*(short *)((unsigned char *)&g_dispatchSave869
                                                     + g_dispatchSave1487 * 8);
            }
            if ((nav & 0x20) != 0) {
                g_dispatchSave1497 = 0x45;
            }
        }
    } else if (g_dispatchSave1497 == 0x45) {
        g_dispatchSave1497 = 0;
    }
    DrawMenu(&g_gsmVar, g_dispatchSave1487);
    return g_dispatchSave1497;
}
#else
__declspec(naked) void Menu_DirectDrawUnavailableDialog(void)
{
    __asm
    {
        mov     al, byte ptr [g_menuFlagsSub1b]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_b93_skipSet
        mov     bl, al
        push    offset g_gsmVar
        or      bl, 1
        push    0
        mov     byte ptr [g_menuFlagsSub1b], bl
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1487], eax
        jmp     short L_b93_afterFirst
    L_b93_skipSet:
        mov     eax, dword ptr [g_dispatchSave1487]
    L_b93_afterFirst:
        mov     ecx, dword ptr [g_dispatchSave1497]
        sub     ecx, 0
        je      L_b93_case0
        sub     ecx, 2
        je      short L_b93_case2
        sub     ecx, 0x43
        jne     L_b93_drawMenu
        mov     dword ptr [g_dispatchSave1497], 0
        jmp     L_b93_drawMenu
    L_b93_case2:
        push    1
        call    Menu_PollNavInput
        mov     ebx, eax
        add     esp, 4
        mov     esi, ebx
        and     esi, 0x8000
        jne     short L_b93_skipDesc
        test    bl, 1
        je      short L_b93_skipDesc
        mov     eax, dword ptr [g_dispatchSave1487]
        push    offset g_gsmVar
        push    eax
        call    Menu_FindPrevSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1487], eax
        jmp     short L_b93_checkBit2
    L_b93_skipDesc:
        mov     eax, dword ptr [g_dispatchSave1487]
    L_b93_checkBit2:
        test    esi, esi
        jne     short L_b93_drawMenu
        test    bl, 2
        je      short L_b93_checkBit4
        push    offset g_gsmVar
        push    eax
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1487], eax
    L_b93_checkBit4:
        test    esi, esi
        jne     short L_b93_drawMenu
        test    bl, 0x10
        je      short L_b93_checkBit5
        movsx   ecx, word ptr [eax*8 + g_dispatchSave869]
        mov     dword ptr [g_dispatchSave1497], ecx
    L_b93_checkBit5:
        test    esi, esi
        jne     short L_b93_drawMenu
        test    bl, 0x20
        je      short L_b93_drawMenu
        mov     dword ptr [g_dispatchSave1497], 0x45
        jmp     short L_b93_drawMenu
    L_b93_case0:
        mov     dword ptr [g_dispatchSave1497], 2
    L_b93_drawMenu:
        push    eax
        push    offset g_gsmVar
        call    DrawMenu
        mov     eax, dword ptr [g_dispatchSave1497]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}
#endif

