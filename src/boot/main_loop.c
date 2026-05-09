/**
 * Per-frame engine loop body.
 *
 * Captures the wall-clock time, runs one BeginFrame / GameLogicStep /
 * DrawScene / PresentFrame, then catches up to the 60 Hz baseline if
 * we fell behind (up to 3 extra GameLogicStep calls), then sleeps
 * the remaining budget (clamped to 1..16 ms).
 */
#include "platform/win32.h"
#include "engine/render.h"
#include "game/tick.h"

/*
 * @addr 0x004b2750
 *
 * Naked + __asm: lots of specific scheduling - the compiler
 * interleaves the (delta - 16667) / 1000 magic-divide with a
 * g_inLoopStep = 0 store, threads `delta` through edi across
 * three QueryMicroTimer rounds, and produces a signed-divide
 * idiom (imul 0x10624dd3 / sar 6 / round-up) that's painful to
 * match from C with the right operand order.
 */
__declspec(naked) void MainLoopStep(void)
{
    __asm {
        mov     al, byte ptr [g_appFlags]
        push    esi
        test    al, 1
        push    edi
        jne     skip_baseline
        or      al, 1
        mov     byte ptr [g_appFlags], al
        call    QueryMicroTimer
        mov     dword ptr [g_lastFrameTime], eax
skip_baseline:
        push    1
        call    BeginFrame
        add     esp, 4
        call    GameLogicStep
        call    DrawScene
        call    PresentFrame
        mov     dword ptr [g_loopCounter],  0
        mov     dword ptr [g_sleepBudgetMs], 0
        mov     dword ptr [g_inLoopStep],   1
        xor     esi, esi
catchup_loop:
        call    QueryMicroTimer
        mov     ecx, dword ptr [g_lastFrameTime]
        mov     edi, eax
        sub     edi, ecx
        cmp     edi, 0x4e20             ; 20 ms in us
        jl      compute_sleep
        call    GameLogicStep
        mov     eax, dword ptr [g_lastFrameTime]
        mov     ecx, dword ptr [g_loopCounter]
        add     eax, 0x411b             ; 16667 us per frame
        inc     esi
        inc     ecx
        cmp     esi, 3
        mov     dword ptr [g_lastFrameTime], eax
        mov     dword ptr [g_loopCounter],  ecx
        jl      catchup_loop
compute_sleep:
        lea     ecx, [edi + 0xffffbee5] ; edi - 16667
        mov     eax, 0x10624dd3         ; 1/1000 magic
        imul    ecx
        sar     edx, 6
        mov     eax, edx
        mov     dword ptr [g_inLoopStep], 0
        shr     eax, 31
        add     edx, eax
        or      eax, 0xffffffff
        sub     eax, edx
        cmp     eax, 1
        jle     no_sleep
        cmp     eax, 16
        jle     clamp_ok
        mov     eax, 16
clamp_ok:
        mov     edx, dword ptr [g_sleepBudgetMs]
        push    eax
        add     edx, eax
        mov     dword ptr [g_sleepBudgetMs], edx
        call    dword ptr [Sleep]
no_sleep:
        call    QueryMicroTimer
        pop     edi
        mov     dword ptr [g_lastFrameTime], eax
        pop     esi
        ret
    }
}
