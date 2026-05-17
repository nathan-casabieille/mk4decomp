/**
 * Fifteenth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00422880 (44b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, [g_xformEntityIdx]
 *   inc     eax
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [ecx*4 + 0], eax
 *   jmp     T
 */
extern packed_ptr g_xformEntityIdx;
extern void SwapOrPassSet_0048fbf0(void);
extern void func_00478328(void);
void CallPauseEvtPushJmp_00422880(void) {
    unsigned int v;
    SwapOrPassSet_0048fbf0();
    if (g_framePauseFlag != 0) return;
    v = g_eventQueueCurrent + 1;
    g_eventQueueCurrent = v;
    *(unsigned int *)(g_xformEntityIdx * 4) = v;
    func_00478328();
}

/* @addr 0x004297d0 (45b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     eax, [eax*4 + 0x28]
 *   inc     eax
 *   mov     [g_eventQueueCurrent], eax
 *   mov     edx, [ecx*4 + 4]
 *   cmp     eax, edx
 *   jge     +5
 *   jmp     T1
 *   jmp     T2
 */
extern void func_004296d8(void);
extern void func_004296e8(void);
void ScaledIncCmpJmp_004297d0(void) {
    unsigned int idx;
    unsigned int scaled;
    unsigned int v;
    int cmp_val;
    idx = g_fightGroupHead;
    scaled = g_scaledInit_00542044;
    v = *(unsigned int *)(idx * 4 + 0x28) + 1;
    g_eventQueueCurrent = v;
    cmp_val = *(int *)(scaled * 4 + 4);
    if ((int)v < cmp_val) {
        func_004296d8();
        return;
    }
    func_004296e8();
}

/* @addr 0x0042c9c0 (35b)
 *   push    0x004e3540
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern int ArgSarStoreJmp_004594f0(void *);
extern void *g_data_004e3540;
void PushCallPauseDirtyClear_0042c9c0(void) {
    ArgSarStoreJmp_004594f0(&g_data_004e3540);
    if (g_framePauseFlag != 0) return;
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}

/* @addr 0x0042ee10 (36b)
 *   mov     eax, [0x0052aac4]
 *   mov     [g_walkCallback], eax
 *   cmp     eax, 7
 *   mov     eax, [g_xformDirtyFlags]
 *   je      +8
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_state_0052aac4;
void Cmp7DirtyToggle_0042ee10(void) {
    unsigned int state = g_state_0052aac4;
    g_walkCallback = (void (*)(void))state;
    if (state != 7) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}

/* @addr 0x004338e0 (34b)
 *   mov     eax, [g_state_0053a3c0]
 *   cmp     eax, 3
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     T1
 *   push    0x004e44c0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern unsigned int g_state_0053a3c0;
extern void func_00433901(void);
extern int func_004392a0(void *);
extern void *g_data_004e44c0;
void Cmp3JmpOrPushCall_004338e0(void) {
    int v = (int)g_state_0053a3c0;
    g_walkCallback = (void (*)(void))v;
    if (v > 3) {
        func_00433901();
        return;
    }
    func_004392a0(&g_data_004e44c0);
}

/* @addr 0x00433e50 (32b)
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, 0x004e4cf8
 *   shr     eax, 8
 *   shr     ecx, 2
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [g_eventQueueChild], ecx
 *   jmp     T
 */
extern void func_00433e80(void);
__declspec(naked) void ShrShrStoreJmp_00433e50(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, 0x004e4cf8
        shr     eax, 8
        shr     ecx, 2
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_eventQueueChild], ecx
        jmp     func_00433e80
    }
}

/* @addr 0x00433e70 (32b)
 *   mov     eax, [g_eventQueueChild]
 *   mov     ecx, [g_eventQueueCurrent]
 *   add     eax, ecx
 *   mov     [g_eventQueueChild], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_eventQueueChild], eax
 *   jmp     eax
 */
__declspec(naked) void AddDerefJmp_00433e70(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueChild]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        add     eax, ecx
        mov     dword ptr [g_eventQueueChild], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_eventQueueChild], eax
        jmp     eax
    }
}

/* @addr 0x00438e70 (37b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 3
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET func_004391b0
 *   jmp     T
 */
extern void func_0043928c(void);
extern void func_004391b0(void);
void MStackPushPtr1Jmp_00438e70(void) {
    unsigned int v = g_matrixStackTop;
    g_walkCallback = (void (*)(void))3;
    v++;
    g_matrixStackTop = v;
    *(unsigned int *)(v * 4) = (unsigned int)&func_004391b0;
    func_0043928c();
}

/* @addr 0x00438ef0 (37b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 1
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET func_004391b0
 *   jmp     T
 */
extern void func_0043930c(void);
void MStackPushPtr1Jmp_00438ef0(void) {
    unsigned int v = g_matrixStackTop;
    g_walkCallback = (void (*)(void))1;
    v++;
    g_matrixStackTop = v;
    *(unsigned int *)(v * 4) = (unsigned int)&func_004391b0;
    func_0043930c();
}

/* @addr 0x00438f20 (38b)
 *   push    0x004e4a1c
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], 1
 *   jmp     T
 */
extern int func_00440950(void *p);
extern void *g_data_004e4a1c;
extern void func_0046f370(void);
void PushCallPauseSet1Jmp_00438f20(void) {
    func_00440950(&g_data_004e4a1c);
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))1;
    func_0046f370();
}
