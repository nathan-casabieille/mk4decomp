/**
 * Fourth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004089c0 (29b)
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     ret_label
 *   jmp     Tail
 *   ret
 */
extern void func_004085f8(void);
extern void func_004088a0(void);
void GDispatch4_004089c0(void) {
    func_004085f8();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    func_004088a0();
}

/* @addr 0x00439c40 (29b): same as above but mask=1, jne */
extern void CmpEqWalkSetCallToggleDirty_00439c60(void);
extern void func_004068e0(void);
void GDispatch1_00439c40(void) {
    CmpEqWalkSetCallToggleDirty_00439c60();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) return;
    func_004068e0();
}

/* @addr 0x00488da0 (29b): mask=1, je (skip-then-jmp) */
extern void DualCondMatchSet_00488dc0(void);
extern void func_004814e0(void);
void GDispatch1_00488da0(void) {
    DualCondMatchSet_00488dc0();
    if (g_framePauseFlag) return;
    if (!(g_xformDirtyFlags & 1)) return;
    func_004814e0();
}

/* @addr 0x004350f0 (30b)
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   mov     [g_eventQueueChild], 0x1e
 *   jmp     +3
 *   ret
 */
extern void MultiThunkDispatcher_00460470(void);
extern void func_00435112(void);
void CallPauseConstStoreJmp_004350f0(void) {
    MultiThunkDispatcher_00460470();
    if (g_framePauseFlag) return;
    g_eventQueueChild = 0x1e;
    func_00435112();
}

/* @addr 0x00438170 (30b): same shape, value=0x78 */
extern void Push80SetWalkNegDualCallPop_004393b0(void);
extern void func_00438192(void);
void CallPauseConstStoreJmp_00438170(void) {
    Push80SetWalkNegDualCallPop_004393b0();
    if (g_framePauseFlag) return;
    g_eventQueueChild = 0x78;
    func_00438192();
}

/* @addr 0x00481360 (30b): same shape, store walkCallback=0xb5 */
extern void BootChainMaskAndDispatch_00416cb0(void);
extern void func_0049cc35(void);
void CallPauseConstStoreJmp_00481360(void) {
    BootChainMaskAndDispatch_00416cb0();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))0xb5;
    func_0049cc35();
}

/* @addr 0x00448fa0 (30b)
 *   mov     [g_walkCallback], 3
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   jmp     Tail
 *   ret
 */
extern void func_00408c0a(void);
extern void func_00475778(void);
void ConstStoreCallJmp_00448fa0(void) {
    g_walkCallback = (void(*)(void))3;
    func_00408c0a();
    if (g_framePauseFlag) return;
    func_00475778();
}

/* @addr 0x0046ff60 (30b): same shape, value=4 */
extern void func_0048a046(void);
extern void func_0046ff8e(void);
void ConstStoreCallJmp_0046ff60(void) {
    g_walkCallback = (void(*)(void))4;
    func_0048a046();
    if (g_framePauseFlag) return;
    func_0046ff8e();
}

/* @addr 0x0041f830 (16b)
 *   call    F
 *   mov     [g_framePauseFlag], 1
 *   ret
 */
extern void ScaledNeg1SetPause_0041f840(void);
void CallSetPause_0041f830(void) {
    ScaledNeg1SetPause_0041f840();
    g_framePauseFlag = 1;
}
