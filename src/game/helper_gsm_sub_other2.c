/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b8d70 (311b game.menu) - menu state poll with init guard.
 *   On first invocation (bit 0 of g_dispatchSave1488 clear), sets bit 0 and
 *   initializes g_dispatchSave1481 = TableSearchAsc(0x4f4fd0, 0).
 *   Then dispatches on g_dispatchSave1500 (state): 0 → set state=2; 2 →
 *   read input via Menu_PollNavInput, OR with 0x8000 mask, walk the
 *   table at 0x4f4fd0 via Asc/Desc moves if bit 0/1 of input set, and if
 *   bit 5 set transition to state 0x45. Then reads movsx eax,
 *   [g_dispatchSave1481*8 + 0x4f4fd4] (entry-type tag), subtracts 0x11 and
 *   dispatches: type 0x11 (eax==0) → call Thunk_ExitGame; type 0x12 →
 *   fallthrough; type 0x13 → AppInit_Misc8, and on
 *   g_demoModeFlag non-zero transition to state 0x45. Tail-calls
 *   DrawMenu(0x4f4fd0, g_dispatchSave1481) and returns the current state.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_gsmVar4;
extern unsigned int g_dispatchSave866;
extern u32 g_demoModeFlag;
extern unsigned int g_dispatchSave1481;
extern unsigned int g_dispatchSave1488;
extern unsigned int g_dispatchSave1500;
#endif
extern void AppInit_Misc8(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_titlePauseGate;   /* 0x004ffd7c */
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_demoModeFlag (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd7cu))
#define g_dispatchSave1481 (*(unsigned int *)MK4_VA(unsigned int, 0xab42d0u))
#define g_dispatchSave1488 (*(unsigned int *)MK4_VA(unsigned int, 0xab431cu))
#define g_dispatchSave1500 (*(unsigned int *)MK4_VA(unsigned int, 0xab4388u))
#define g_dispatchSave866 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4fd4u))
#define g_gsmVar4 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4fd0u))
#define g_titlePauseGate (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd7cu))
#endif

/* Real signatures. The auto-generated placeholders all said `(void)`, but the
 * original pushes two stack args for the two selectable-scanners and one for
 * the poll, and every caller uses the returned value. */
extern int          DrawMenu(void *menu, int sel);
extern unsigned int Menu_PollNavInput(int mode);
extern unsigned int Menu_FindNextSelectable(int cur, void *menu);
extern unsigned int Menu_FindPrevSelectable(int cur, void *menu);
extern void Thunk_ExitGame(void);

#ifdef NON_MATCHING
/* Portable twin. The head and the navigation block are the shared menu-dialog
 * shape, but this one has a tail the others do not: after the poll it reads a
 * COMMAND from the selected row - the s16 at +4 of the 8-byte entry - and acts
 * on 0x11 / 0x12 / 0x13.
 *
 * That command switch runs whether or not the input was a hold; each case
 * re-tests the hold bit itself, which is why the flag is kept in a local
 * rather than folded into the enclosing condition.
 *
 * 0x11 retries the CD check and only closes the dialog if the gate came back
 * set; 0x12 closes it; 0x13 leaves the game. */
int Menu_InsertCDDialog(void)
{
    unsigned int nav = 0, held = 0;
    int cmd;

    if ((g_dispatchSave1488 & 1) == 0) {
        g_dispatchSave1488 = g_dispatchSave1488 | 1;
        g_dispatchSave1481 = Menu_FindNextSelectable(0, &g_gsmVar4);
    }

    if (g_dispatchSave1500 == 0) {
        g_dispatchSave1500 = 2;
    } else if (g_dispatchSave1500 == 2) {
        nav  = Menu_PollNavInput(1);
        held = nav & 0x8000;

        if (held == 0 && (nav & 1) != 0)
            g_dispatchSave1481 = Menu_FindPrevSelectable(g_dispatchSave1481, &g_gsmVar4);
        if (held == 0) {
            if ((nav & 2) != 0)
                g_dispatchSave1481 = Menu_FindNextSelectable(g_dispatchSave1481, &g_gsmVar4);
            if ((nav & 0x20) != 0)
                g_dispatchSave1500 = 0x45;
        }

        cmd = (int)*(short *)((unsigned char *)&g_dispatchSave866
                              + g_dispatchSave1481 * 8);
        if (cmd == 0x11) {
            if (held == 0 && (nav & 0x10) != 0) {
                AppInit_Misc8();
                if (g_titlePauseGate != 0)
                    g_dispatchSave1500 = 0x45;
            }
        } else if (cmd == 0x12) {
            if (held == 0 && (nav & 0x10) != 0)
                g_dispatchSave1500 = 0x45;
        } else if (cmd == 0x13) {
            if (held == 0 && (nav & 0x10) != 0)
                Thunk_ExitGame();
        }
    } else if (g_dispatchSave1500 == 0x45) {
        g_dispatchSave1500 = 0;
    }

    DrawMenu(&g_gsmVar4, g_dispatchSave1481);
    return g_dispatchSave1500;
}
#else
__declspec(naked) void Menu_InsertCDDialog(void) {
    __asm {
        mov     al, byte ptr [g_dispatchSave1488]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_mps_haveInit
        mov     bl, al
        push    offset g_gsmVar4
        or      bl, 1
        push    0
        mov     byte ptr [g_dispatchSave1488], bl
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1481], eax
    L_mps_haveInit:
        mov     eax, dword ptr [g_dispatchSave1500]
        sub     eax, 0
        je      L_mps_state0
        sub     eax, 2
        je      short L_mps_state2
        sub     eax, 0x43
        jne     L_mps_drawTail
        mov     dword ptr [g_dispatchSave1500], 0
        jmp     L_mps_drawTail
    L_mps_state2:
        push    1
        call    Menu_PollNavInput
        mov     ebx, eax
        add     esp, 4
        mov     esi, ebx
        and     esi, 0x8000
        jne     short L_mps_skipAsc
        test    bl, 1
        je      short L_mps_skipAsc
        mov     eax, dword ptr [g_dispatchSave1481]
        push    offset g_gsmVar4
        push    eax
        call    Menu_FindPrevSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1481], eax
    L_mps_skipAsc:
        test    esi, esi
        jne     short L_mps_skipDesc
        test    bl, 2
        je      short L_mps_skipDescCall
        mov     ecx, dword ptr [g_dispatchSave1481]
        push    offset g_gsmVar4
        push    ecx
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1481], eax
    L_mps_skipDescCall:
        test    esi, esi
        jne     short L_mps_skipDesc
        test    bl, 0x20
        je      short L_mps_skipDesc
        mov     dword ptr [g_dispatchSave1500], 0x45
    L_mps_skipDesc:
        mov     edx, dword ptr [g_dispatchSave1481]
        movsx   eax, word ptr [edx*8 + g_dispatchSave866]
        sub     eax, 0x11
        je      short L_mps_type11
        dec     eax
        je      short L_mps_type12
        dec     eax
        jne     short L_mps_drawTail
        test    esi, esi
        jne     short L_mps_drawTail
        test    bl, 0x10
        je      short L_mps_drawTail
        call    Thunk_ExitGame
        jmp     short L_mps_drawTail
    L_mps_type12:
        test    esi, esi
        jne     short L_mps_drawTail
        test    bl, 0x10
        jmp     short L_mps_type11_check
    L_mps_type11:
        test    esi, esi
        jne     short L_mps_drawTail
        test    bl, 0x10
        je      short L_mps_drawTail
        call    AppInit_Misc8
        mov     eax, dword ptr [g_demoModeFlag]
        test    eax, eax
    L_mps_type11_check:
        je      short L_mps_drawTail
        mov     dword ptr [g_dispatchSave1500], 0x45
        jmp     short L_mps_drawTail
    L_mps_state0:
        mov     dword ptr [g_dispatchSave1500], 2
    L_mps_drawTail:
        mov     eax, dword ptr [g_dispatchSave1481]
        push    eax
        push    offset g_gsmVar4
        call    DrawMenu
        mov     eax, dword ptr [g_dispatchSave1500]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}
#endif

