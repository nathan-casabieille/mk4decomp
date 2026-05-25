/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b8d70 (311b game.menu) - menu state poll with init guard.
 *   On first invocation (bit 0 of g_data_00ab431c clear), sets bit 0 and
 *   initializes g_data_00ab42d0 = TableSearchAsc(0x4f4fd0, 0).
 *   Then dispatches on g_data_00ab4388 (state): 0 → set state=2; 2 →
 *   read input via MenuInputPoll_004b7020, OR with 0x8000 mask, walk the
 *   table at 0x4f4fd0 via Asc/Desc moves if bit 0/1 of input set, and if
 *   bit 5 set transition to state 0x45. Then reads movsx eax,
 *   [g_data_00ab42d0*8 + 0x4f4fd4] (entry-type tag), subtracts 0x11 and
 *   dispatches: type 0x11 (eax==0) → call Thunk_004c48b0; type 0x12 →
 *   fallthrough; type 0x13 → AppInit_Misc8, and on
 *   g_demoModeFlag non-zero transition to state 0x45. Tail-calls
 *   DrawMenu(0x4f4fd0, g_data_00ab42d0) and returns the current state.
 */
extern unsigned int g_gsmVar4_004f4fd0;
extern unsigned int g_dispatchSave866_004f4fd4;
extern u32 g_demoModeFlag;
extern unsigned int g_data_00ab42d0;
extern unsigned int g_data_00ab431c;
extern unsigned int g_data_00ab4388;
extern void AppInit_Misc8(void);
extern void DrawMenu(void);
extern void MenuInputPoll_004b7020(void);
extern void TableSearchAsc_004b6300(void);
extern void TableSearchDesc_004b62c0(void);
extern void Thunk_004c48b0(void);

__declspec(naked) void Helper_GSM_Sub_Other2(void) {
    __asm {
        mov     al, byte ptr [g_data_00ab431c]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_mps_haveInit
        mov     bl, al
        push    offset g_gsmVar4_004f4fd0
        or      bl, 1
        push    0
        mov     byte ptr [g_data_00ab431c], bl
        call    TableSearchAsc_004b6300
        add     esp, 8
        mov     dword ptr [g_data_00ab42d0], eax
    L_mps_haveInit:
        mov     eax, dword ptr [g_data_00ab4388]
        sub     eax, 0
        je      L_mps_state0
        sub     eax, 2
        je      short L_mps_state2
        sub     eax, 0x43
        jne     L_mps_drawTail
        mov     dword ptr [g_data_00ab4388], 0
        jmp     L_mps_drawTail
    L_mps_state2:
        push    1
        call    MenuInputPoll_004b7020
        mov     ebx, eax
        add     esp, 4
        mov     esi, ebx
        and     esi, 0x8000
        jne     short L_mps_skipAsc
        test    bl, 1
        je      short L_mps_skipAsc
        mov     eax, dword ptr [g_data_00ab42d0]
        push    offset g_gsmVar4_004f4fd0
        push    eax
        call    TableSearchDesc_004b62c0
        add     esp, 8
        mov     dword ptr [g_data_00ab42d0], eax
    L_mps_skipAsc:
        test    esi, esi
        jne     short L_mps_skipDesc
        test    bl, 2
        je      short L_mps_skipDescCall
        mov     ecx, dword ptr [g_data_00ab42d0]
        push    offset g_gsmVar4_004f4fd0
        push    ecx
        call    TableSearchAsc_004b6300
        add     esp, 8
        mov     dword ptr [g_data_00ab42d0], eax
    L_mps_skipDescCall:
        test    esi, esi
        jne     short L_mps_skipDesc
        test    bl, 0x20
        je      short L_mps_skipDesc
        mov     dword ptr [g_data_00ab4388], 0x45
    L_mps_skipDesc:
        mov     edx, dword ptr [g_data_00ab42d0]
        movsx   eax, word ptr [edx*8 + g_dispatchSave866_004f4fd4]
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
        call    Thunk_004c48b0
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
        mov     dword ptr [g_data_00ab4388], 0x45
        jmp     short L_mps_drawTail
    L_mps_state0:
        mov     dword ptr [g_data_00ab4388], 2
    L_mps_drawTail:
        mov     eax, dword ptr [g_data_00ab42d0]
        push    eax
        push    offset g_gsmVar4_004f4fd0
        call    DrawMenu
        mov     eax, dword ptr [g_data_00ab4388]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}

