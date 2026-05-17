/**
 * Forty-sixth batch of one-off matches.
 * 68-byte stubs cluster (size-driven batch).
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_pendingNodeType;
extern packed_ptr g_fightGroupHead;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00434d60: jmp=0x00436120, type=8, ptr=own */
extern void ThresholdInitInstallSelfChain_00436120(void);
extern void ScaledInitOrSelfPtrSetType_00434d60(void);
void ScaledInitOrSelfPtrSetType_00434d60(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int v = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (v != 0) {
        ThresholdInitInstallSelfChain_00436120();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)&ScaledInitOrSelfPtrSetType_00434d60;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 8;
    g_framePauseFlag = 1;
}

/* @addr 0x0046a5e0: jmp=0x0046a630, type=3, ptr=own */
extern void QuadEntryGateChain_0046a630(void);
extern void ScaledInitOrSelfPtrSetType_0046a5e0(void);
void ScaledInitOrSelfPtrSetType_0046a5e0(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int v = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (v != 0) {
        QuadEntryGateChain_0046a630();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)&ScaledInitOrSelfPtrSetType_0046a5e0;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 3;
    g_framePauseFlag = 1;
}

/* @addr 0x0047a620: jmp=0x0047a670, type=0xa, ptr=own */
extern void TripleSubInstallSelfPair_0047a670(void);
extern void ScaledInitOrSelfPtrSetType_0047a620(void);
void ScaledInitOrSelfPtrSetType_0047a620(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int v = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (v != 0) {
        TripleSubInstallSelfPair_0047a670();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)&ScaledInitOrSelfPtrSetType_0047a620;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 0xa;
    g_framePauseFlag = 1;
}
/* @addr 0x0048a7c0 (68b): zero 6 dwords at offsets 0x6c..0x80 of fightGroupHead*4 */
void ZeroSixStores6c80_0048a7c0(void) {
    unsigned char *base = (unsigned char *)(g_fightGroupHead * 4);
    g_walkCallback = 0;
    *(unsigned int *)(base + 0x6c) = 0;
    *(unsigned int *)(base + 0x70) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x74) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x78) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x7c) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x80) = (unsigned int)g_walkCallback;
}

/* @addr 0x00490e40 (68b): same shape, offsets 0x60, 0x64, 0x68, 0x78, 0x7c, 0x80 */
void ZeroSixStores6080_00490e40(void) {
    unsigned char *base = (unsigned char *)(g_fightGroupHead * 4);
    g_walkCallback = 0;
    *(unsigned int *)(base + 0x60) = 0;
    *(unsigned int *)(base + 0x64) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x68) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x78) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x7c) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x80) = (unsigned int)g_walkCallback;
}

/* @addr 0x00421c50 (68b)
 *   if (g_state_0053a6dc == 0x10000) ret;
 *   if (g_state_00537f2c == 0x10000) ret;
 *   reset 3 globals to 0; call F; return 1.
 */
extern unsigned int g_state_0053a6dc;
extern unsigned int g_state_00537f2c;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537e88;
extern void func_00420060(void);
__declspec(naked) void CmpDualStateMatch_00421c50(void) {
    __asm {
        mov     eax, dword ptr [g_state_0053a6dc]
        cmp     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   03h
        xor     eax, eax
        ret
        mov     eax, dword ptr [g_state_00537f2c]
        cmp     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   03h
        xor     eax, eax
        ret
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_0053a408], eax
        mov     dword ptr [g_state_00537e88], eax
        call    func_00420060
        mov     eax, 1
        ret
    }
}

/* @addr 0x00451550 (68b): 4-call pause cleanup with set walk=5 then walk=6 */
extern void func_004089e0_kk(void);
extern void func_004b8f90(void);
extern void func_00451580(void);
extern void func_00451598(void);
void QuadCallPauseSetCallSeq_00451550(void) {
    func_004089e0_kk();
    if (g_framePauseFlag != 0) return;
    func_004b8f90();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))5;
    func_00451580();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))6;
    func_00451598();
}

/* @addr 0x00482be0 (68b): set 1, call F1, pause, set 0x9999, call F2, pause, call F3, pause, jmp T */
extern void func_0048a456(void);
extern void func_00482a8e(void);
extern void func_00489248(void);
extern void func_00482c50(void);
void CallPauseFourSet_00482be0(void) {
    g_walkCallback = (void (*)(void))1;
    func_0048a456();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x9999;
    func_00482a8e();
    if (g_framePauseFlag != 0) return;
    func_00489248();
    if (g_framePauseFlag != 0) return;
    func_00482c50();
}

/* @addr 0x00486530 (68b)
 *   load baseSel*4+0x74; cmp 0x1003; jne →skip; call F1; pause →ret;
 *   call F2; pause →ret; set walk=0x3b; jmp T.
 */
extern void func_0048cf38(void);
extern void func_0040ccf0(void);
extern void func_00489fb2(void);
void ScaledLoadCmp1003JmpDispatch_00486530(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x74);
    g_walkCallback = (void (*)(void))v;
    if (v != 0x1003) return;
    func_0048cf38();
    if (g_framePauseFlag != 0) return;
    func_0040ccf0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x3b;
    func_00489fb2();
}

/* @addr 0x00428030 (78b)
 *   call F; pause-test → ret; clear walk + state_00538158 + state_0053815c;
 *   call F2; pause → ret; call F3; pause → ret; jmp T.
 */
extern void BootInitChainHeavy_00404f20(void);
extern unsigned int g_state_00538158_kk;
extern unsigned int g_state_0053815c_kk;
extern void DualEntryInitCmp_00425b20(void);
extern void Cmp9DirtyToggle_00464320(void);
extern void func_00431230(void);
__declspec(naked) void CallPauseClear3CallTriple_00428030(void) {
    __asm {
        call    BootInitChainHeavy_00404f20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3fh
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_state_00538158_kk], 0
        mov     dword ptr [g_state_0053815c_kk], 0
        call    DualEntryInitCmp_00425b20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    Cmp9DirtyToggle_00464320
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00431230
        ret
    }
}
