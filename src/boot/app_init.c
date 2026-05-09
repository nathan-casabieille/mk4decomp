/**
 * High-level engine init (called from WinMain).
 *
 * Bring up the timer, joystick, install validator, gfx pipeline,
 * audio (Aux + DSound), various sub-systems, then run the
 * renderer auto-fallback ladder (mode 1 -> 2 -> 3 -> 5) calling
 * TryInitRenderer until one succeeds. Tail does demo-mode init
 * and a small RNG dice-roll for the random seed.
 */
#include "platform/win32.h"
#include "engine/render.h"
#include "game/statemachine.h"
#include "audio/sound.h"
#include "game/tick.h"

extern void UpdateWindowTitle(void);
extern s32  ValidateInstall(void);
extern s32  Joystick_Init(HWND hwnd);
extern u32  g_pumpFlagD8, g_pumpFlagDC, g_pumpFlagE0, g_pumpFlagE4;

/*
 * @addr 0x004b2500
 *
 * Naked + __asm: long sequence of init calls with very specific
 * stack-cleanup pacing (some `add esp, 4` interleaved with arg
 * loads for the next call) and a 4-step renderer fallback ladder
 * that clears one of the g_pumpFlag{D8,DC,E0,E4} per failed step.
 */
__declspec(naked) void AppInit(HWND hwnd)
{
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        push    edi
        mov     dword ptr [g_appInitHwnd], eax
        call    Timer_Init
        call    Joystick_Init
        call    ValidateInstall
        call    AppInit_PostJoy
        call    AppInit_PreInstall
        mov     ecx, dword ptr [g_appInitHwnd]
        push    ecx
        call    Gfx_Init
        mov     edx, dword ptr [g_appInitHwnd]
        add     esp, 4
        push    edx
        call    AuxAudio_Init
        mov     eax, dword ptr [g_audioMasterVol]
        add     esp, 4
        and     eax, 0xff
        push    eax
        call    AuxAudio_SetMasterVol
        mov     ecx, dword ptr [g_appInitHwnd]
        add     esp, 4
        push    ecx
        call    DSound_Init
        mov     dl, byte ptr [g_audioPostFlag]
        add     esp, 4
        push    edx
        call    AppInit_AudioPostInit
        add     esp, 4
        call    AppInit_PostDSound
        call    AppInit_Misc1
        call    AppInit_Misc2
        call    AppInit_Misc3
        mov     edi, 1
        push    edi
        mov     dword ptr [g_pumpFlagE4], edi
        mov     dword ptr [g_pumpFlagE0], edi
        mov     dword ptr [g_pumpFlagDC], edi
        mov     dword ptr [g_pumpFlagD8], edi
        call    SetRendererMode
        add     esp, 4
        call    TryInitRenderer
        xor     esi, esi
        test    eax, eax
        jge     after_fallback
        push    2
        mov     dword ptr [g_pumpFlagD8], esi
        call    SetRendererMode
        add     esp, 4
        call    TryInitRenderer
        test    eax, eax
        jge     after_fallback
        push    3
        mov     dword ptr [g_pumpFlagDC], esi
        call    SetRendererMode
        add     esp, 4
        call    TryInitRenderer
        test    eax, eax
        jge     after_fallback
        push    5
        mov     dword ptr [g_pumpFlagE0], esi
        call    SetRendererMode
        add     esp, 4
        call    TryInitRenderer
        test    eax, eax
        jge     after_fallback
        mov     dword ptr [g_pumpFlagE4], esi
after_fallback:
        call    UpdateWindowTitle
        call    AppInit_Misc4
        call    AppInit_Misc5
        call    AppInit_Misc6
        call    AppInit_Misc7
        call    AppInit_Misc8
        cmp     dword ptr [g_demoModeFlag], esi
        jne     skip_demo
        push    7
        call    GameStateMachine
        add     esp, 4
skip_demo:
        mov     dword ptr [g_appInitFlag1], esi
        mov     dword ptr [g_appInitFlag2], esi
        call    AppInit_Probe
        test    eax, eax
        jz      done
        call    dword ptr [timeGetTime]
        push    eax
        call    Crt_srand
        add     esp, 4
        call    Crt_rand
        test    al, 3
        jz      seed_extra
        mov     dword ptr [g_appInitFlag1], edi
        pop     edi
        pop     esi
        ret
seed_extra:
        call    Crt_rand
        or      eax, 0x1881
        mov     dword ptr [g_appInitFlag2], eax
done:
        pop     edi
        pop     esi
        ret
    }
}
