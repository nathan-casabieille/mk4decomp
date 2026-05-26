/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004b3e20 (108b): 5-way switch on g_currentRendererMode - 1.
 *   Each case is a single-arg forward to a different per-mode helper.
 *   Jump table at +0x58 swaps entries 4/5 (the mode-3 slot routes to
 *   the last code block).
 */
extern int g_currentRendererMode;
extern void Helper_AppStub_2890(void);
extern void PaletteRampInit_004ad5f0(void);
extern void ComSoundSetup_004af6c0(void);
extern void ComSoundSetup_004afef0(void);
extern void func_004b44d0(void);

__declspec(naked) void Helper_RendererPostInit(void) {
    __asm {
        mov     eax, dword ptr [g_currentRendererMode]
        dec     eax
        cmp     eax, 4
        _emit   77h
        _emit   4ch
        _emit   0ffh
        _emit   24h
        _emit   85h
        _emit   78h
        _emit   3eh
        _emit   4bh
        _emit   00h
        mov     ecx, dword ptr [esp + 4]
        push    ecx
        call    func_004b44d0
        add     esp, 4
        ret
        mov     edx, dword ptr [esp + 4]
        push    edx
        call    PaletteRampInit_004ad5f0
        add     esp, 4
        ret
        mov     eax, dword ptr [esp + 4]
        push    eax
        call    ComSoundSetup_004af6c0
        add     esp, 4
        ret
        mov     ecx, dword ptr [esp + 4]
        push    ecx
        call    ComSoundSetup_004afef0
        add     esp, 4
        ret
        mov     edx, dword ptr [esp + 4]
        push    edx
        call    Helper_AppStub_2890
        add     esp, 4
        ret
        _emit   32h
        _emit   3eh
        _emit   4bh
        _emit   00h
        _emit   40h
        _emit   3eh
        _emit   4bh
        _emit   00h
        _emit   4eh
        _emit   3eh
        _emit   4bh
        _emit   00h
        _emit   6ah
        _emit   3eh
        _emit   4bh
        _emit   00h
        _emit   5ch
        _emit   3eh
        _emit   4bh
        _emit   00h
    }
}

