/**
 * Twenty-ninth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00405a00 (59b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     edx, [eax*4 + 0x20]
 *   and     dl, 0x7f
 *   mov     [eax*4 + 0x20], edx
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     [g_walkCallback], 0x00405a00
 *   mov     eax, [eax*4 + 0]
 *   test    eax, eax
 *   mov     [g_eventQueueCurrent], eax
 *   je      +5
 *   jmp     +0xb5456
 *   ret
 */
extern void func_004bae62(void);
__declspec(naked) void ScaledAndMaskInitJmp_00405a00(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [eax*4 + 0x20]
        and     dl, 0x7f
        mov     dword ptr [eax*4 + 0x20], edx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_walkCallback], 0x00405a00
        mov     eax, dword ptr [eax*4 + 0]
        test    eax, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   74h
        _emit   05h
        jmp     func_004bae62
        ret
    }
}

/* @addr 0x0041f1b0 (53b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, 1
 *   shl     eax, 2
 *   mov     [eax + 0x84], 0
 *   mov     [eax + 8], 0x0041f1b0
 *   mov     [eax + 0x84], ecx
 *   mov     [g_pendingNodeType], 0x3c
 *   mov     [g_walkCallback], 0    (g_framePauseFlag area)
 *   ret
 */
extern u32 g_pendingNodeType;
__declspec(naked) void ScaledInitWithCounterAndType_0041f1b0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, 1
        shl     eax, 2
        mov     dword ptr [eax + 0x84], 0
        mov     dword ptr [eax + 8], 0x0041f1b0
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], 0x3c
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x004314f0 (53b): same shape as 0x0041f1b0 with different ptr/value */
__declspec(naked) void ScaledInitWithCounterAndType_004314f0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, 1
        shl     eax, 2
        mov     dword ptr [eax + 0x84], 0
        mov     dword ptr [eax + 8], 0x004314f0
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], 0x28
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x00428370 (51b): mstack push then jmp/dispatch
 *   mov     eax, [g_matrixStackTop]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], 0x004283b0
 *   jmp     +0x2f5
 *   nop * 5
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     +5
 *   jmp     -0x2e
 *   jmp     -0x18bc23
 */
extern void TripleBranchInstall_004283b0(void);
extern void func_0042867d(void);
extern void func_004283b3(void);
extern void func_0042976e(void);
__declspec(naked) void MStackPushDualJmp_00428370(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET TripleBranchInstall_004283b0
        jmp     func_0042867d
        nop
        nop
        nop
        nop
        nop
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     func_004283b3
        jmp     func_0042976e
    }
}

/* @addr 0x00438470 (53b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 6
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET func_004384a0
 *   jmp     +0x38dbb
 *   nop * 11
 *   jmp     -0x18d25
 */
extern void func_004384a0(void);
extern void func_0046f230(void);
extern void func_0042b1c0(void);
__declspec(naked) void MStackPushSet6Jmp_00438470(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], 6
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET func_004384a0
        jmp     func_0046f230
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        jmp     func_0042b1c0
    }
}

/* @addr 0x004384b0 (53b): same shape value=0 + diff target */
extern void func_004384e0(void);
extern void StageTransitionCluster_0046f250(void);
extern void func_0042b200(void);
__declspec(naked) void MStackPushSet0Jmp_004384b0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], 0
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET func_004384e0
        jmp     StageTransitionCluster_0046f250
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        jmp     func_0042b200
    }
}

/* @addr 0x004384f0 (53b): same shape value=4 */
extern void func_00438520(void);
extern void func_0046f230_c(void);
extern void func_0042b240(void);
__declspec(naked) void MStackPushSet4Jmp_004384f0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], 4
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET func_00438520
        jmp     func_0046f230_c
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        jmp     func_0042b240
    }
}

/* @addr 0x00439190 (52b)
 *   call    F1
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T1
 *   ret
 *   nop * 11
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T2
 *   ret
 */
extern void func_00423c10(void);
extern void func_00423bf0(void);
extern void func_00477670(void);
extern void func_0046f680(void);
__declspec(naked) void DualCallPauseJmpDual_00439190(void) {
    __asm {
        call    func_00423c10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00477670
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        call    func_00423bf0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0046f680
        ret
    }
}

/* @addr 0x00439680 (54b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x38]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0x70]
 *   mov     [g_walkCallback], eax
 *   test    eax, eax
 *   mov     eax, [g_xformDirtyFlags]
 *   jge     +8
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
__declspec(naked) void ScaledChainSignDirtyToggle_00439680(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0x70]
        mov     dword ptr [g_walkCallback], eax
        test    eax, eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        _emit   7dh
        _emit   08h
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x00445e80 (54b)
 *   call    F1
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x19
 *   mov     [g_walkCallback], 3
 *   mov     [g_acc_00542078], 2
 *   jmp     T
 *   ret
 */
extern unsigned int g_acc_00542078;
extern void func_00408ce0(void);
extern void func_00478f90(void);
extern void func_00408a20(void);
void TwoCallPauseSetJmp_00445e80(void) {
    func_00408ce0();
    if (g_framePauseFlag != 0) return;
    func_00478f90();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))3;
    g_acc_00542078 = 2;
    func_00408a20();
}

/* @addr 0x00446280 (56b)
 *   mov     eax, [g_baseSel_00542060]
 *   shl     eax, 2
 *   mov     ecx, [eax + 0x5c]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     edx, [eax + 0x3c]
 *   shl     ecx, 2
 *   mov     [g_walkCallback], edx
 *   mov     [ecx + 0x30], edx
 *   mov     edx, [eax + 0x40]
 *   mov     [g_walkCallback], edx
 *   mov     [ecx + 0x34], edx
 *   mov     eax, [eax + 0x44]
 *   mov     [g_walkCallback], eax
 *   mov     [ecx + 0x38], eax
 *   ret
 */
__declspec(naked) void ScaledChainCopyTriple_00446280(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x5c]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     edx, dword ptr [eax + 0x3c]
        shl     ecx, 2
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x30], edx
        mov     edx, dword ptr [eax + 0x40]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x34], edx
        mov     eax, dword ptr [eax + 0x44]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx + 0x38], eax
        ret
    }
}
