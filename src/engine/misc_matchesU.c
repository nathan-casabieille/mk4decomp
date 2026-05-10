/**
 * Thirtieth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_eventQueueWorkType;
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
__declspec(naked) void CmpP1ScaledLoad74_0045f5d0(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_player1NodeIdx]
        mov     eax, dword ptr [g_gtPlayerProbe2]
        cmp     ecx, edx
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   74h
        _emit   0ah
        mov     eax, dword ptr [g_gtPlayerProbe1]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [eax*4 + 0x74]
        mov     dword ptr [g_walkCallback], edx
        ret
    }
}

/* @addr 0x0045f610 (50b): same shape with offset 0x7c */
__declspec(naked) void CmpP1ScaledLoad7c_0045f610(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_player1NodeIdx]
        mov     eax, dword ptr [g_gtPlayerProbe2]
        cmp     ecx, edx
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   74h
        _emit   0ah
        mov     eax, dword ptr [g_gtPlayerProbe1]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [eax*4 + 0x7c]
        mov     dword ptr [g_walkCallback], edx
        ret
    }
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
extern void func_0048a190(void);
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
        call    func_0048a190
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
extern void func_004299a0(void);
extern void func_004296d8(void);
extern void func_004296fb(void);
__declspec(naked) void CallPauseScaledDecJmp_00429750(void) {
    __asm {
        call    func_004299a0
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
extern unsigned int g_xformEntityIdx;
extern void func_00406c10(void);
__declspec(naked) void Const4ec8f8DirtyScaledStore_00446580(void) {
    __asm {
        mov     eax, 0x004ec8f8
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    func_00406c10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ch
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   13h
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [ecx*4 + 0x60], edx
        ret
    }
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
__declspec(naked) void Set2CallDirtyCallPauseJmp_004535e0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 2
        call    func_00455746
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ch
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   13h
        call    func_00455760
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0042038f
        ret
    }
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
__declspec(naked) void TwoCallPauseSetJmp2_00456180(void) {
    __asm {
        call    func_00408990
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   27h
        call    func_00478f90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   19h
        mov     dword ptr [g_acc_00542078], 2
        mov     dword ptr [g_walkCallback], 3
        jmp     func_00407f40
        ret
    }
}

/* @addr 0x0045f5a0 (48b) — wait, that's done already. Skip. */

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
