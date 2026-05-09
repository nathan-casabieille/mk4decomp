/**
 * Win32 message pump driver.
 *
 * Pumps up to 20 messages per call, then dispatches state machine
 * actions based on TryInitRenderer's return code (a 5-way switch
 * over rc + 5 in the range [0, 4]). Each switch arm clears one of
 * the 4 per-renderer-mode flags and conditionally invokes
 * GameStateMachine with a mode argument.
 *
 * After UpdateWindowTitle, blocks on WaitMessage if either of two
 * "needs more work" globals is clear; loops back if so.
 */
#include "platform/win32.h"
#include "engine/render.h"
#include "game/statemachine.h"

extern int  TryInitRenderer(void);                       /* 0x004b3ed0 */
extern void UpdateWindowTitle(void);                     /* 0x004b22e0 */

extern u32  g_pumpFlagD8;        /* 0x00f9f7d8 */
extern u32  g_pumpFlagDC;        /* 0x00f9f7dc */
extern u32  g_pumpFlagE0;        /* 0x00f9f7e0 */
extern u32  g_pumpFlagE4;        /* 0x00f9f7e4 */
extern u32  g_pumpFlagE8;        /* 0x00f9f7e8 */
extern u32  g_pumpFlagEC;        /* 0x00f9f7ec */
extern u32  g_pumpFlagF0;        /* 0x00f9f7f0 */
extern u32  g_rendererCheckVal;  /* 0x00ab5748 */

/* Jump table for the rc-switch. The linker places this in .rdata;
 * the diff masks the DIR32 reloc on the function's `jmp [eax*4 +
 * PumpMsg_JumpTable]` so the function body matches even though the
 * table content here is zero-init'd. */
const u32 PumpMsg_JumpTable[5] = {0, 0, 0, 0, 0};

/*
 * @addr 0x004c52a0
 *
 * Naked + __asm: switch with a 5-entry jump table indexed by
 * (TryInitRenderer() + 5). Each arm clears a different per-mode
 * flag and pushes a mode-specific arg to GameStateMachine. The
 * tail does WaitMessage and a "two-flag" loop-back check that
 * doubles as the do-while condition.
 */
__declspec(naked) void PumpMessages(void)
{
    __asm {
        sub     esp, 0x1c
        push    ebx
        mov     ebx, dword ptr [TranslateMessage]
        push    ebp
        mov     ebp, dword ptr [DispatchMessageA]
        push    esi
        push    edi
        xor     edi, edi
        mov     dword ptr [g_pumpFlagEC], edi
loop_top:
        xor     esi, esi
peek_loop:
        push    edi
        push    edi
        push    edi
        lea     eax, [esp + 0x1c]
        push    edi
        push    eax
        call    dword ptr [PeekMessageA]
        test    eax, eax
        jz      after_peek
        push    edi
        push    edi
        lea     ecx, [esp + 0x18]
        push    edi
        push    ecx
        call    dword ptr [GetMessageA]
        test    eax, eax
        jne     have_msg
        call    ExitGame
have_msg:
        lea     edx, [esp + 0x10]
        push    edx
        call    ebx                                       ; TranslateMessage
        lea     eax, [esp + 0x10]
        push    eax
        call    ebp                                       ; DispatchMessageA
        inc     esi
        cmp     esi, 0x14                                 ; 20
        jl      peek_loop
after_peek:
        cmp     dword ptr [g_pumpFlagF0], 1
        jne     skip_clear_F0
        mov     dword ptr [g_pumpFlagF0], edi
skip_clear_F0:
        call    TryInitRenderer
        add     eax, 5
        cmp     eax, 4
        ja      after_switch
        jmp     dword ptr [eax*4 + PumpMsg_JumpTable]
case_neg1:
        mov     eax, dword ptr [g_rendererCheckVal]
        mov     dword ptr [g_pumpFlagD8], edi
        cmp     eax, edi
        jne     after_switch
        push    6
        jmp     do_gsm
case_neg2:
        mov     eax, dword ptr [g_rendererCheckVal]
        mov     dword ptr [g_pumpFlagDC], edi
        cmp     eax, edi
        jne     after_switch
        push    4
        jmp     do_gsm
case_neg3:
        mov     eax, dword ptr [g_rendererCheckVal]
        mov     dword ptr [g_pumpFlagE0], edi
        cmp     eax, edi
        jne     after_switch
        jmp     do_gsm_5
case_neg5:
        mov     eax, dword ptr [g_rendererCheckVal]
        mov     dword ptr [g_pumpFlagE4], edi
        cmp     eax, edi
        jne     after_switch
do_gsm_5:
        push    5
do_gsm:
        call    GameStateMachine
        add     esp, 4
after_switch:
        call    UpdateWindowTitle
        cmp     dword ptr [g_pumpFlagF0], edi
        jz      do_wait
        cmp     dword ptr [g_pumpFlagE8], edi
        jz      after_wait
do_wait:
        call    dword ptr [WaitMessage]
after_wait:
        cmp     dword ptr [g_pumpFlagF0], edi
        je      loop_top                                   ; long form
        cmp     dword ptr [g_pumpFlagE8], edi
        jne     loop_top                                   ; long form
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x1c
        ret
    }
}
