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
extern void ScaledAndMaskInitJmp_00405a00(void);
void ScaledAndMaskInitJmp_00405a00(void) {
    unsigned int v;
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x20) &= 0xffffff7fu;
    g_walkCallback = (void (*)(void))&ScaledAndMaskInitJmp_00405a00;
    v = *(unsigned int *)(g_scaledInit_00542044 * 4);
    g_eventQueueCurrent = v;
    if (v == 0) return;
    func_004bae62();
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
void ScaledInitWithCounterAndType_0041f1b0(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    *(unsigned int *)(base + 0x84) = 0;
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitWithCounterAndType_0041f1b0;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 0x3c;
    g_framePauseFlag = 1;
}

/* @addr 0x004314f0 (53b): same shape as 0x0041f1b0 with different ptr/value */
void ScaledInitWithCounterAndType_004314f0(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    *(unsigned int *)(base + 0x84) = 0;
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitWithCounterAndType_004314f0;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 0x28;
    g_framePauseFlag = 1;
}

/* @addr 0x00428370 (51b): packed multi-entry helper - keep naked.
 *
 * This 51-byte symbol covers TWO independent code blocks under one
 * function name. Block A converted to pure C; Block B kept naked
 * (it uses raw _emit jne and has no entry from Block A - reached
 * only via external jmp landing at 0x00428390).
 *
 *   Block A (offsets 0x00..0x1a, 27b): mstack push + tail-jmp.
 *   Block B (offsets 0x20..0x32, 19b at 0x00428390): test/jne/jmp/jmp.
 *   5-byte nop pad between, filled by synth 0x90.
 */
extern void TripleBranchInstall_004283b0(void);
extern void func_0042867d(void);
extern void func_004283b3(void);
extern void func_0042976e(void);

void MStackPushDualJmp_00428370(void) {
    int top = g_matrixStackTop;
    top++;
    g_matrixStackTop = top;
    *(void(**)(void))((unsigned int)top * 4) = TripleBranchInstall_004283b0;
    func_0042867d();
}

/* @addr 0x00428390 (19b naked): Block B - reached only via external
 * jmp from a different call site. Uses _emit jne for the back-jump
 * into Block A and a forward tail-jmp. */
__declspec(naked) void func_00428390(void) {
    __asm {
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     func_004283b3
        jmp     func_0042976e
    }
}

/* @addr 0x00438470 (37b main + 11 nop pad + 5b sub-entry at +0x30):
 *   set walk=6, mstack-push func_004384a0, tail-jmp func_0046f230.
 *   Sub-entry MStackCleanupFrom_004384a0 (below) is a 5b tail-jmp
 *   wrapper into func_0042b1c0; the 11-byte gap is synth 0x90 fill.
 */
extern void func_004384a0(void);
extern void func_0046f230(void);
extern void func_0042b1c0(void);
void MStackPushSet6Jmp_00438470(void) {
    int top = g_matrixStackTop;
    g_walkCallback = (void(*)(void))6;
    top++;
    g_matrixStackTop = top;
    *(void(**)(void))((unsigned int)top * 4) = func_004384a0;
    func_0046f230();
}

/* @addr 0x004384a0 (5b) packed mstack-pop-callback tail-jmp wrapper. */
void MStackCleanupFrom_004384a0(void) {
    func_0042b1c0();
}

/* @addr 0x004384b0 (37b): same shape value=0 + diff target */
extern void func_004384e0(void);
extern void StageTransitionCluster_0046f250(void);
extern void func_0042b200(void);
void MStackPushSet0Jmp_004384b0(void) {
    int top = g_matrixStackTop;
    g_walkCallback = (void(*)(void))0;
    top++;
    g_matrixStackTop = top;
    *(void(**)(void))((unsigned int)top * 4) = func_004384e0;
    StageTransitionCluster_0046f250();
}

/* @addr 0x004384e0 (5b) packed mstack-pop-callback tail-jmp wrapper. */
void MStackCleanupFrom_004384e0(void) {
    func_0042b200();
}

/* @addr 0x004384f0 (37b): same shape value=4 */
extern void func_00438520(void);
extern void func_0046f230_c(void);
extern void func_0042b240(void);
void MStackPushSet4Jmp_004384f0(void) {
    int top = g_matrixStackTop;
    g_walkCallback = (void(*)(void))4;
    top++;
    g_matrixStackTop = top;
    *(void(**)(void))((unsigned int)top * 4) = func_00438520;
    func_0046f230_c();
}

/* @addr 0x00438520 (5b) packed mstack-pop-callback tail-jmp wrapper. */
void MStackCleanupFrom_00438520(void) {
    func_0042b240();
}

/* @addr 0x00439190 (20b): call F1; if pause, ret; else tail-jmp T1.
 *   Originally a 52-byte slot covering this 20-byte entry plus a 12-byte
 *   nop gap and a twin 20-byte entry at +0x20 (func_004391b0). Split into
 *   two pure-C functions; the gap is filled by the synth via 0x90-fill. */
extern void func_00423c10(void);
extern void func_00423bf0(void);
extern void func_00477670(void);
extern void func_0046f680(void);
void DualCallPauseJmpDual_00439190(void) {
    func_00423c10();
    if (g_framePauseFlag != 0) return;
    func_00477670();
}

/* @addr 0x004391b0 (20b): twin of DualCallPauseJmpDual_00439190 at +0x20 in
 * the original packed slot. Reached via OFFSET func_004391b0 references
 * (e.g. from misc_matchesF.c). */
void func_004391b0(void) {
    func_00423bf0();
    if (g_framePauseFlag != 0) return;
    func_0046f680();
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
void ScaledChainSignDirtyToggle_00439680(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x38);
    g_scaledInit_00542044 = v;
    v = *(unsigned int *)(v * 4 + 0x70);
    g_walkCallback = (void (*)(void))v;
    if ((int)v < 0) {
        g_xformDirtyFlags = g_xformDirtyFlags | 1;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
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
void ScaledChainCopyTriple_00446280(void) {
    unsigned char *src;
    unsigned char *dst;
    unsigned int v;
    src = (unsigned char *)(g_baseSel_00542060 * 4);
    g_scaledInit_00542044 = *(unsigned int *)(src + 0x5c);
    dst = (unsigned char *)(g_scaledInit_00542044 * 4);
    v = *(unsigned int *)(src + 0x3c);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x30) = v;
    v = *(unsigned int *)(src + 0x40);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x34) = v;
    v = *(unsigned int *)(src + 0x44);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x38) = v;
}
