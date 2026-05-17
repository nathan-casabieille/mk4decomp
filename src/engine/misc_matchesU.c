/**
 * Thirtieth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;

/* @addr 0x0045f5d0 (50b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     edx, [g_player1NodeIdx]
 *   mov     eax, [g_gtPlayerProbe2]
 *   cmp     ecx, edx
 *   mov     [g_scaledInit_00542044], eax
 *   je      +0x0a
 *   mov     eax, [g_gtPlayerProbe1]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     edx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], edx
 *   ret
 */
void CmpP1ScaledLoad74_0045f5d0(void) {
    unsigned int v = g_gtPlayerProbe2;
    g_scaledInit_00542044 = v;
    if (g_fightGroupHead != g_player1NodeIdx) {
        v = g_gtPlayerProbe1;
        g_scaledInit_00542044 = v;
    }
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x74);
}

/* @addr 0x0045f610 (50b): same shape with offset 0x7c */
void CmpP1ScaledLoad7c_0045f610(void) {
    unsigned int v = g_gtPlayerProbe2;
    g_scaledInit_00542044 = v;
    if (g_fightGroupHead != g_player1NodeIdx) {
        v = g_gtPlayerProbe1;
        g_scaledInit_00542044 = v;
    }
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x7c);
}

/* @addr 0x004202c0 (57b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x84]
 *   mov     [eax*4 + 0x84], 0
 *   test    ecx, ecx
 *   jne     +5
 *   call    F1
 *   call    F2
 *   call    F3
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     +8
 *   ret
 */
extern void OrDualStore_0048a190(void);
extern void func_00404e10(void);
extern void func_004222c0(void);
extern void func_004202f5(void);
__declspec(naked) void ScaledClearTripleCallJmp_004202c0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x84]
        mov     dword ptr [eax*4 + 0x84], 0
        test    ecx, ecx
        _emit   75h
        _emit   05h
        call    OrDualStore_0048a190
        call    func_00404e10
        call    func_004222c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004202f5
        ret
    }
}

/* @addr 0x00429750 (56b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x29
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x28]
 *   dec     ecx
 *   mov     [g_eventQueueCurrent], ecx
 *   js      +5
 *   jmp     -0x88
 *   mov     [g_eventQueueCurrent], 0
 *   jmp     -0x57
 *   ret
 */
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void func_004296d8(void);
extern void func_004296fb(void);
__declspec(naked) void CallPauseScaledDecJmp_00429750(void) {
    __asm {
        call    GuardedChainCmpDualBitXor_004299a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x28]
        dec     ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   78h
        _emit   05h
        jmp     func_004296d8
        mov     dword ptr [g_eventQueueCurrent], 0
        jmp     func_004296fb
        ret
    }
}

/* @addr 0x00446580 (56b)
 *   mov     eax, 0x004ec8f8
 *   shr     eax, 2
 *   mov     [g_xformEntityIdx], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     +0x13
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     edx, [g_scaledInit_00542044]
 *   mov     [ecx*4 + 0x60], edx
 *   ret
 */
extern packed_ptr g_xformEntityIdx;
extern void FramePauseScaledStore_00406c10(void);
extern int g_data_004ec8f8;
void Const4ec8f8DirtyScaledStore_00446580(void) {
    g_xformEntityIdx = ((unsigned int)&g_data_004ec8f8) >> 2;
    FramePauseScaledStore_00406c10();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x60) = g_scaledInit_00542044;
}

/* @addr 0x004465c0 (56b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x60]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     eax, [eax*4 + 0x4c]
 *   mov     [g_xformEntityIdx], eax
 *   mov     [ecx*4 + 0x18], eax
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_xformEntityIdx]
 *   mov     [eax*4 + 0x18], ecx
 *   ret
 */
__declspec(naked) void ScaledChainTripleStore_004465c0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x60]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     eax, dword ptr [eax*4 + 0x4c]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [eax*4 + 0x18], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [eax*4 + 0x18], ecx
        ret
    }
}

/* @addr 0x00446940 (53b): same as 0x0041f1b0 but with diff IMM and value */
__declspec(naked) void ScaledInitWithCounterAndType_00446940(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, 1
        shl     eax, 2
        mov     dword ptr [eax + 0x84], 0
        mov     dword ptr [eax + 8], 0x00446940
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], 0x28
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x004535e0 (53b)
 *   mov     [g_walkCallback], 2
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     +0x13
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void func_00455746(void);
extern void func_00455760(void);
extern void func_0042038f(void);
void Set2CallDirtyCallPauseJmp_004535e0(void) {
    g_walkCallback = (void (*)(void))2;
    func_00455746();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    func_00455760();
    if (g_framePauseFlag != 0) return;
    func_0042038f();
}

/* @addr 0x00456180 (54b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x19
 *   mov     [g_acc_00542078], 2
 *   mov     [g_walkCallback], 3
 *   jmp     T
 *   ret
 */
extern void func_00408990(void);
extern void func_00478f90(void);
extern void func_00407f40(void);
void TwoCallPauseSetJmp2_00456180(void) {
    func_00408990();
    if (g_framePauseFlag != 0) return;
    func_00478f90();
    if (g_framePauseFlag != 0) return;
    g_acc_00542078 = 2;
    g_walkCallback = (void (*)(void))3;
    func_00407f40();
}

/* @addr 0x0045f5a0 (48b) - wait, that's done already. Skip. */

/* @addr 0x00450680 (53b)
 *   mov     ecx, [g_eventQueueCurrent]
 *   mov     edx, [g_eventQueueChild]
 *   mov     eax, [g_eventQueueWorkType]
 *   push    0x93
 *   push    0x00450790
 *   mov     [g_state_0052d750], eax
 *   mov     [g_state_0052d754], ecx
 *   mov     [g_state_0052d758], edx
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int func_004acabc(void *p, int n);
extern void *g_data_00450790;
extern unsigned int g_state_0052d750;
extern unsigned int g_state_0052d754;
extern unsigned int g_state_0052d758;
__declspec(naked) void StoreThreeStatesPushCall_00450680(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     edx, dword ptr [g_eventQueueWorkType]
        push    0x93
        push    OFFSET g_data_00450790
        mov     dword ptr [g_state_0052d750], eax
        mov     dword ptr [g_state_0052d754], ecx
        mov     dword ptr [g_state_0052d758], edx
        call    func_004acabc
        add     esp, 8
        ret
    }
}
