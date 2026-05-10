/**
 * Thirty-eighth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b2690 (60b): pure call chain — 11 calls + 1 jmp */
extern void func_004c44f0(void);
extern void func_004b4410(void);
extern void func_004b2ae0(void);
extern void func_004b5ac0(void);
extern void func_004ad410(void);
extern void func_004b62b0(void);
extern void func_004b21c0(void);
extern void func_004c4240(void);
extern void func_004ac9b0(void);
extern void func_004b5370(void);
extern void func_004b1de0(void);
extern void func_004b5a70(void);
__declspec(naked) void ElevenCallsJmp_004b2690(void) {
    __asm {
        call    func_004c44f0
        call    func_004b4410
        call    func_004b2ae0
        call    func_004b5ac0
        call    func_004ad410
        call    func_004b62b0
        call    func_004b21c0
        call    func_004c4240
        call    func_004ac9b0
        call    func_004b5370
        call    func_004b1de0
        jmp     func_004b5a70
    }
}

/* @addr 0x004b2ff0 (58b)
 *   load two dword globals, then move 16-bit args at [esp+4],[esp+8],[esp+0xc]
 *   into 16-bit globals; flush the dwords back too.
 */
extern unsigned int g_state_007af9bc;
extern unsigned int g_state_007af98c;
extern unsigned int g_state_007af9b8;
extern unsigned int g_state_007af988;
extern unsigned short g_word_007af95c;
extern unsigned short g_word_007af962;
extern unsigned short g_word_007af968;
__declspec(naked) void CopyArgs16ToGlobals_004b2ff0(void) {
    __asm {
        mov     eax, dword ptr [g_state_007af9bc]
        mov     ecx, dword ptr [g_state_007af98c]
        mov     dx,  word  ptr [esp + 4]
        mov     dword ptr [g_state_007af9b8], eax
        mov     ax,  word  ptr [esp + 8]
        mov     dword ptr [g_state_007af988], ecx
        mov     cx,  word  ptr [esp + 0x0c]
        mov     word  ptr [g_word_007af95c], dx
        mov     word  ptr [g_word_007af962], ax
        mov     word  ptr [g_word_007af968], cx
        ret
    }
}

/* @addr 0x004b41c0 (64b): 5-way jump-table dispatcher.
 *   call F; eax=arg-1; if (eax > 4) ret; jmp [tab + eax*4]
 *   table swaps entries 4<->5 (table[3]=case5, table[4]=case4).
 */
extern void func_004b3db0(void);
extern void func_004b4600_cc(void);
extern void func_004ad590(void);
extern void func_004af880(void);
extern void func_004b00b0(void);
extern void func_004b2930(void);
__declspec(naked) void JumpTable5Way_004b41c0(void) {
    __asm {
        call    func_004b3db0
        dec     eax
        cmp     eax, 4
        _emit   77h
        _emit   20h
        _emit   0ffh
        _emit   24h
        _emit   85h
        _emit   0ech
        _emit   41h
        _emit   4bh
        _emit   00h
        jmp     func_004b4600_cc
        jmp     func_004ad590
        jmp     func_004af880
        jmp     func_004b00b0
        jmp     func_004b2930
        ret
        _emit   0d2h
        _emit   41h
        _emit   4bh
        _emit   00h
        _emit   0d7h
        _emit   41h
        _emit   4bh
        _emit   00h
        _emit   0dch
        _emit   41h
        _emit   4bh
        _emit   00h
        _emit   0e6h
        _emit   41h
        _emit   4bh
        _emit   00h
        _emit   0e1h
        _emit   41h
        _emit   4bh
        _emit   00h
    }
}

/* @addr 0x004b4410 (51b): push 4; 7 calls; clear [g_state_004f4b3c] */
extern void func_004b40a0(int);
extern void func_004b3ed0(void);
extern void func_004bf320(void);
extern void func_004ad7c0(void);
extern void func_004afa10(void);
extern void func_004b0240(void);
extern void func_004b2a40(void);
extern unsigned int g_state_004f4b3c;
__declspec(naked) void Push4MultiCall_004b4410(void) {
    __asm {
        push    4
        call    func_004b40a0
        add     esp, 4
        call    func_004b3ed0
        call    func_004bf320
        call    func_004ad7c0
        call    func_004afa10
        call    func_004b0240
        call    func_004b2a40
        mov     dword ptr [g_state_004f4b3c], 0
        ret
    }
}

/* @addr 0x004b44f0 (52b)
 *   if g_state_007affe4 != 0:
 *     eax = abs([esp+4]); clamp to <= 100; convert to float; *= g_data_004d29c8
 *     call IAT [g_iat_007b0030] with float arg.
 */
extern unsigned int g_state_007affe4;
extern float g_data_004d29c8;
extern void (*g_iat_007b0030)(float);
__declspec(naked) void AbsClampIATCall_004b44f0(void) {
    __asm {
        mov     eax, dword ptr [g_state_007affe4]
        test    eax, eax
        _emit   74h
        _emit   2ah
        mov     eax, dword ptr [esp + 4]
        cdq
        xor     eax, edx
        sub     eax, edx
        cmp     eax, 0x64
        _emit   7eh
        _emit   08h
        mov     dword ptr [esp + 4], 0x64
        fild    dword ptr [esp + 4]
        push    ecx
        fmul    dword ptr [g_data_004d29c8]
        fstp    dword ptr [esp]
        call    dword ptr [g_iat_007b0030]
        ret
    }
}

/* @addr 0x004b4600 (65b)
 *   if (g_state_007affe4 != 0 && g_state_007afff0 != 0):
 *     if eax == 2: push 1, push 1, call IAT, clear g_state_007afff0;
 *     else:        push 0, push 0, call IAT, clear g_state_007afff0;
 *   ret.
 */
extern unsigned int g_state_007afff0;
extern void (*g_iat_007b0040)(int, int);
__declspec(naked) void EarlyOutDualPushIATStore_004b4600(void) {
    __asm {
        mov     eax, dword ptr [g_state_007affe4]
        test    eax, eax
        _emit   74h
        _emit   37h
        mov     eax, dword ptr [g_state_007afff0]
        test    eax, eax
        _emit   74h
        _emit   2eh
        cmp     eax, 2
        _emit   75h
        _emit   15h
        push    1
        push    1
        call    dword ptr [g_iat_007b0040]
        mov     dword ptr [g_state_007afff0], 0
        ret
        push    0
        push    0
        call    dword ptr [g_iat_007b0040]
        mov     dword ptr [g_state_007afff0], 0
        ret
    }
}

/* @addr 0x004a9230 (64b): call F + load 1, 0; set 5 globals; jmp T. */
extern void func_004a1ec0(void);
extern unsigned int g_state_0052aac4_cc;
extern unsigned int g_state_0053a50c;
extern unsigned int g_state_0054355c;
extern unsigned int g_state_00543710;
extern unsigned int g_state_0054359c;
extern unsigned int g_state_005433c8;
extern unsigned char g_byte_00543834;
extern void func_004a93c0(void);
__declspec(naked) void CallSetMultiGlobalsJmp_004a9230(void) {
    __asm {
        call    func_004a1ec0
        mov     eax, 1
        xor     ecx, ecx
        mov     dword ptr [g_state_0052aac4_cc], 2
        mov     dword ptr [g_state_0053a50c], 0x0e
        mov     dword ptr [g_state_0054355c], eax
        mov     dword ptr [g_state_00543710], eax
        mov     dword ptr [g_state_0054359c], ecx
        mov     dword ptr [g_state_005433c8], ecx
        mov     byte  ptr [g_byte_00543834], al
        jmp     func_004a93c0
    }
}

/* @addr 0x004a1bf0 (65b): 3-stage call chain with byte/byte/byte stores */
extern int func_004a1ba0(void);
extern int func_004a1b00(void);
extern int func_004a1b50(void);
extern unsigned char g_byte_00543590;
__declspec(naked) void TripleCallByteCheck_004a1bf0(void) {
    __asm {
        call    func_004a1ba0
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     eax, 1
        mov     byte  ptr [g_byte_00543590], al
        ret
        call    func_004a1b00
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     eax, 1
        mov     byte  ptr [g_byte_00543590], al
        ret
        call    func_004a1b50
        test    eax, eax
        _emit   74h
        _emit   0dh
        mov     byte  ptr [g_byte_00543590], 2
        mov     eax, 1
        ret
        xor     eax, eax
        ret
    }
}

/* @addr 0x004a1d80 (61b): 6 push/call/add-esp sequences */
extern void func_004bd890(int);
__declspec(naked) void SixCallSeqPushImm_004a1d80(void) {
    __asm {
        push    9
        call    func_004bd890
        add     esp, 4
        push    2
        call    func_004bd890
        add     esp, 4
        push    3
        call    func_004bd890
        add     esp, 4
        push    4
        call    func_004bd890
        add     esp, 4
        push    5
        call    func_004bd890
        add     esp, 4
        push    7
        call    func_004bd890
        add     esp, 4
        ret
    }
}

/* @addr 0x004235f0 (64b)
 *   call F; pause → ret;
 *   load g_state_0052ab40 → walk; and 4 → g_state_00542094;
 *   jz → call F2; pause → ret;
 *   set [g_eventQueueNotMask] = 0x1002f; jmp T.
 */
extern void func_00423720(void);
extern unsigned int g_state_0052ab40;
extern unsigned int g_state_00542094;
extern void func_004930e0(void);
extern void func_0045f650(void);
__declspec(naked) void CallPauseLoadAndDispatch_004235f0(void) {
    __asm {
        call    func_00423720
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   31h
        mov     eax, dword ptr [g_state_0052ab40]
        mov     dword ptr [g_walkCallback], eax
        and     eax, 4
        mov     dword ptr [g_state_00542094], eax
        _emit   74h
        _emit   0eh
        call    func_004930e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     dword ptr [g_eventQueueNotMask], 0x1002f
        jmp     func_0045f650
        ret
    }
}
