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
void OnceCall_00401340(void) {
    if (g_byte_0052435c != 0) {
        return;
    }
    g_byte_0052435c = 1;
    func_00401118(&g_data_004d5084, 0, 0);
    func_0040136d();
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
void CallPauseCmpDoubleJmp_00435230(void) {
    func_00485e50();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((int)g_walkCallback > 0x13333) {
        func_0043524c();
    } else {
        func_00437a91();
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
void DualCallPauseDirtyJmp_00435f20(void) {
    if (func_004395b0() != 0) {
        return;
    }
    func_00439600();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((g_xformDirtyFlags & 1) != 0) {
        func_0043625b();
    } else {
        func_00435f4d();
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
extern void PushPop84TripleCall_00438b90(void);
extern void func_00438a04(void);
extern void func_00438a09(void);
void CmpJmpConstStoreJmp_004389e0(void) {
    PushPop84TripleCall_00438b90();
    if (g_framePauseFlag) return;
    if ((int)g_eventQueueChild < 0x64) {
        func_00438a04();
        return;
    }
    g_eventQueueChild = 0x1e;
    func_00438a09();
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
void CallPauseDirtyConstJmp_00438ca0(void) {
    func_00482ec0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        func_0049f4ad();
        return;
    }
    g_walkCallback = (void(*)(void))0x0c;
    func_0046f170();
}

/* @addr 0x0043aa80 (37b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 5
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET StateMachine4ArmCascade_0043aab0
 *   jmp     T
 */
extern void StateMachine4ArmCascade_0043aab0(void);
extern void func_00440230(void);
void MStackPush5Func_0043aa80(void) {
    unsigned int top = g_matrixStackTop;
    g_walkCallback = (void(*)(void))5;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)StateMachine4ArmCascade_0043aab0;
    func_00440230();
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
void ScaledChainOrAh1_004462f0(void) {
    unsigned int scaled = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x5c);
    unsigned int v;
    g_scaledInit_00542044 = scaled;
    v = *(unsigned int *)(scaled * 4 + 0x20) | 0x100;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(scaled * 4 + 0x20) = v;
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
void ScaledLoadZeroStore_004464f0(void) {
    unsigned int scaled = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x30);
    g_walkCallback = 0;
    g_scaledInit_00542044 = scaled;
    *(unsigned int *)(scaled * 4 + 0x28) = 0;
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
void Const5Call_PauseDirty4_Jmp_004534e0(void) {
    g_walkCallback = (void(*)(void))5;
    func_00453746();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    func_00455761();
}

/* @addr 0x00453510 (39b): same shape, value=6 */
extern void func_00453746_b(void);
extern void func_00455761_b(void);
void Const6Call_PauseDirty4_Jmp_00453510(void) {
    g_walkCallback = (void(*)(void))6;
    func_00453746_b();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    func_00455761_b();
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
void Cmp9DirtyToggle_00464320(void) {
    unsigned int state = g_state_0052aac4_h;
    g_walkCallback = (void(*)(void))state;
    if (state != 9) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
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
void CmpP1ScaledInit_004709c0(void) {
    g_scaledInit_00542044 = g_player2NodeIdx;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_scaledInit_00542044 = g_player1NodeIdx;
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
extern void DirtyToggleByGate_0048f350(void);
extern void func_00470f78(void);
extern void func_00470f4d(void);
void CallDirty4DualJmp_00470f30(void) {
    DirtyToggleByGate_0048f350();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) {
        func_00470f78();
        return;
    }
    func_00470f4d();
}
