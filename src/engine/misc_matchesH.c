/**
 * Seventeenth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00401340 (39b)
 *   mov     al, byte ptr [g_byte_0052435c]
 *   test    al, al
 *   jne     .skip
 *   push    0
 *   push    0
 *   push    0x004d5084
 *   mov     byte ptr [g_byte_0052435c], 1
 *   call    F
 *   add     esp, 0xc
 *   jmp     +0x0a
 * .skip:
 *   ret
 */
extern unsigned char g_byte_0052435c;
extern void *g_data_004d5084;
extern int func_00401118(void *p, int a, int b);
extern void func_0040136d(void);
__declspec(naked) void OnceCall_00401340(void) {
    __asm {
        mov     al, byte ptr [g_byte_0052435c]
        test    al, al
        _emit   75h
        _emit   1dh
        push    0
        push    0
        push    OFFSET g_data_004d5084
        mov     byte ptr [g_byte_0052435c], 1
        call    func_00401118
        add     esp, 0x0c
        jmp     func_0040136d
        ret
    }
}

/* @addr 0x00435230 (37b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   cmp     [g_walkCallback], 0x00013333
 *   jle     +5
 *   jmp     +0x11
 *   jmp     T
 *   ret
 */
extern void func_00485e50(void);
extern void func_0043524c(void);
extern void func_00437a91(void);
__declspec(naked) void CallPauseCmpDoubleJmp_00435230(void) {
    __asm {
        call    func_00485e50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   16h
        cmp     dword ptr [g_walkCallback], 0x00013333
        _emit   7eh
        _emit   05h
        jmp     func_0043524c
        jmp     func_00437a91
        ret
    }
}

/* @addr 0x00435f20 (43b)
 *   call    F
 *   test    eax, eax
 *   jne     .skip2
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      .ret
 *   jmp     T1
 * .skip2:
 *   jmp     +6
 *   ret
 */
extern int func_004395b0(void);
extern void func_00439600(void);
extern void func_0043625b(void);
extern void func_00435f4d(void);
__declspec(naked) void DualCallPauseDirtyJmp_00435f20(void) {
    __asm {
        call    func_004395b0
        test    eax, eax
        _emit   75h
        _emit   21h
        call    func_00439600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_0043625b
        jmp     func_00435f4d
        ret
    }
}

/* @addr 0x004389e0 (44b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   cmp     [g_eventQueueChild], 0x64
 *   jge     +5
 *   jmp     +0x14
 *   mov     [g_eventQueueChild], 0x1e
 *   jmp     +5
 *   ret
 */
extern void func_00438b90(void);
extern void func_00438a04(void);
extern void func_00438a09(void);
__declspec(naked) void CmpJmpConstStoreJmp_004389e0(void) {
    __asm {
        call    func_00438b90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        cmp     dword ptr [g_eventQueueChild], 0x64
        _emit   7dh
        _emit   05h
        jmp     func_00438a04
        mov     dword ptr [g_eventQueueChild], 0x1e
        jmp     func_00438a09
        ret
    }
}

/* @addr 0x00438ca0 (44b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      +5
 *   jmp     +0x2a4
 *   mov     [g_walkCallback], 0x0c
 *   jmp     +0x384c5
 *   ret
 */
extern void func_00482ec0(void);
extern void func_0049f4ad(void);
extern void func_0046f170(void);
__declspec(naked) void CallPauseDirtyConstJmp_00438ca0(void) {
    __asm {
        call    func_00482ec0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_0049f4ad
        mov     dword ptr [g_walkCallback], 0x0c
        jmp     func_0046f170
        ret
    }
}

/* @addr 0x0043aa80 (37b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 5
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET func_0043aab0
 *   jmp     T
 */
extern void func_0043aab0(void);
extern void func_00440230(void);
__declspec(naked) void MStackPush5Func_0043aa80(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], 5
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET func_0043aab0
        jmp     func_00440230
    }
}

/* @addr 0x004462f0 (41b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x5c]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     eax, [ecx*4 + 0x20]
 *   or      ah, 1                           ; set bit 8
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x20], eax
 *   ret
 */
__declspec(naked) void ScaledChainOrAh1_004462f0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x5c]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     eax, dword ptr [ecx*4 + 0x20]
        or      ah, 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        ret
    }
}

/* @addr 0x004464f0 (33b)
 *   mov     eax, [g_baseSel_00542060]
 *   xor     ecx, ecx
 *   mov     eax, [eax*4 + 0x30]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [eax*4 + 0x28], ecx
 *   ret
 */
__declspec(naked) void ScaledLoadZeroStore_004464f0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        xor     ecx, ecx
        mov     eax, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0x28], ecx
        ret
    }
}

/* @addr 0x00452740 (37b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [g_eventQueueEnd]
 *   mov     [eax*4 + 0x64], ecx
 *   mov     edx, [g_baseSel_00542060]
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [edx*4 + 0x68], eax
 *   ret
 */
void DualScaledStore_00452740(void) {
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x64) = g_eventQueueEnd;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x68) = g_eventQueueIdx;
}

/* @addr 0x004534e0 (39b)
 *   mov     [g_walkCallback], 5
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     .ret
 *   jmp     T
 *   ret
 */
extern void func_00453746(void);
extern void func_00455761(void);
__declspec(naked) void Const5Call_PauseDirty4_Jmp_004534e0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 5
        call    func_00453746
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0eh
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     func_00455761
        ret
    }
}

/* @addr 0x00453510 (39b): same shape, value=6 */
extern void func_00453746_b(void);
extern void func_00455761_b(void);
__declspec(naked) void Const6Call_PauseDirty4_Jmp_00453510(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 6
        call    func_00453746_b
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0eh
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     func_00455761_b
        ret
    }
}

/* @addr 0x00461340 (31b)
 *   mov     [g_walkCallback], 1
 *   jmp     T
 *   nop
 *   mov     [g_walkCallback], 2
 *   jmp     T2
 */
extern void func_0048e4ab(void);
extern void func_0048e4af(void);
__declspec(naked) void Set1JmpSet2Jmp_00461340(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 1
        jmp     func_0048e4ab
        nop
        mov     dword ptr [g_walkCallback], 2
        jmp     func_0048e4af
    }
}

/* @addr 0x00464320 (36b): same shape as 0x0042ee10 (Cmp7DirtyToggle) but cmp=9 */
extern unsigned int g_state_0052aac4_h;
__declspec(naked) void Cmp9DirtyToggle_00464320(void) {
    __asm {
        mov     eax, dword ptr [g_state_0052aac4_h]
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 9
        mov     eax, dword ptr [g_xformDirtyFlags]
        _emit   74h
        _emit   08h
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x004709c0 (31b)
 *   mov     ecx, [g_player1NodeIdx]
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [g_player1NodeIdx]
 *   cmp     ecx, eax
 *   je      .skip
 *   mov     [g_scaledInit_00542044], eax
 * .skip:
 *   ret
 */
__declspec(naked) void CmpP1ScaledInit_004709c0(void) {
    __asm {
        mov     eax, dword ptr [g_player2NodeIdx]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [g_player1NodeIdx]
        cmp     ecx, eax
        _emit   74h
        _emit   05h
        mov     dword ptr [g_scaledInit_00542044], eax
        ret
    }
}

/* @addr 0x00470f30 (34b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   je      .doit
 *   jmp     +0x44
 * .doit:
 *   jmp     +0x0f
 *   ret
 */
extern void func_0048f350(void);
extern void func_00470f78(void);
extern void func_00470f4d(void);
__declspec(naked) void CallDirty4DualJmp_00470f30(void) {
    __asm {
        call    func_0048f350
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   05h
        jmp     func_00470f78
        jmp     func_00470f4d
        ret
    }
}
