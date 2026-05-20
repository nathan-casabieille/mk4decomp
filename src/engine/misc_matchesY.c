/**
 * Thirty-fourth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_state_00537e94;
extern packed_ptr g_fightGroupHead;

/* @addr 0x0044ef10 (64b): same shape as ScaledInitOrSelfPtr_00421f00,
 *                         store=own, jmp=0x44ef50 */
extern void PoseChainAdvanceCluster_0044ef50(void);
void ScaledInitOrSelfPtr_0044ef10(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int ptr = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (ptr) {
        PoseChainAdvanceCluster_0044ef50();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_0044ef10;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00446640 (61b)
 *   mov     eax, [g_baseSel_00542060]
 *   xor     ecx, ecx
 *   mov     eax, [eax*4 + 0x30]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [eax*4 + 0x1c], ecx
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     eax, [ecx*4 + 0x20]
 *   and     ah, 0xfe
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x20], eax
 *   ret
 */
void ScaledLoad1cZeroAndFE_00446640(void) {
    unsigned int s;
    unsigned int v;
    s = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x30);
    g_walkCallback = 0;
    g_scaledInit_00542044 = s;
    *(unsigned int *)(s * 4 + 0x1c) = 0;
    s = g_scaledInit_00542044;
    v = *(unsigned int *)(s * 4 + 0x20) & 0xFFFFFEFFu;
    g_walkCallback = (void(*)(void))v;
    *(unsigned int *)(s * 4 + 0x20) = v;
}

/* @addr 0x00446880 (62b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x4c]
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     T
 *   nop * 9
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0f
 *   mov     eax, 0xfff
 *   mov     [g_walkCallback], eax
 *   mov     [g_state_00537e94], eax
 *   ret
 */
extern void MStackCall_00406340(void);
extern void Cmp2OrSet0b_0048e3e0(void);
/* Entry A (23b @ 0x00446880): load baseSel[+0x4c] into g_scaledInit,
 * tail-jmp MStackCall_00406340. Entry B (sub-entry at +0x20) lives in
 * func_004468a0. The 9-byte nop gap is filled by 0x90-fill. */
void ScaledLoadJmpPauseSetMax_00446880(void) {
    g_scaledInit_00542044 = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x4c);
    MStackCall_00406340();
}

/* @addr 0x004468a0 (30b): call Cmp2OrSet0b, then if !pause set both
 * g_walkCallback and g_state_00537e94 to 0xfff. Orphan sub-entry of the
 * original packed 62-byte block. */
void func_004468a0(void) {
    int v;
    Cmp2OrSet0b_0048e3e0();
    if (g_framePauseFlag != 0) return;
    v = 0xfff;
    g_walkCallback = (void (*)(void))v;
    g_state_00537e94 = v;
}

/* @addr 0x004390f0 (62b)
 *   call F1; pause-test → ret
 *   testb 1,[dirty] ; je → call F2 ; pause → jne ret
 *   call F3; pause → jne ret; jmp T
 */
extern void MStackPush3CmpCall_0048eec0(void);
extern void SetJmp_00438f60(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void ScaledZeroFour_00490740(void);
extern void GuardedDispatch_0042c570(void);
void CallPauseTestByteJmpCalls_004390f0(void) {
    MStackPush3CmpCall_0048eec0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        SetJmp_00438f60();
        return;
    }
    FiveCallScaledChainTailJmp_0045f8d0();
    if (g_framePauseFlag) return;
    ScaledZeroFour_00490740();
    if (g_framePauseFlag) return;
    GuardedDispatch_0042c570();
}

/* @addr 0x00451a60 (62b)
 *   call F1; pause → ret
 *   testb 4,[dirty]; je → ret
 *   call F2; pause → ret
 *   call F3; pause → ret
 *   mov [g_walkCallback], 0
 *   ret
 */
extern void SetJmp_00405420(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
void CallPauseTestByte4ZeroCB_00451a60(void) {
    SetJmp_00405420();
    if (g_framePauseFlag) return;
    if (!(g_xformDirtyFlags & 4)) return;
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_walkCallback = 0;
}

/* @addr 0x004353f0 (65b)
 *   call F1; test eax → jne ret
 *   call F2; pause → jne ret
 *   load g_walkCallback; test → jge skip → jmp T_inner
 *   load g_state_00535ddc; cmp 0x30000; store; jle → jmp T1; jmp T2
 *   ret
 */
extern void Cmp2CallDirtyCall_004398b0(void);
extern void Wrapper_00439310(void);
extern unsigned int g_state_00535ddc_y;
extern void TriEntryGateMain_00435440(void);
extern void GuardedSeq_00433bb0(void);
extern void PrefixThunkInstallSelf3State_00438f80(void);
void DualCallTestPauseRange_004353f0(void) {
    int state_y;
    if (((int (*)(void))Cmp2CallDirtyCall_004398b0)() != 0) return;
    Wrapper_00439310();
    if (g_framePauseFlag != 0) return;
    if ((int)g_walkCallback < 0) {
        TriEntryGateMain_00435440();
        return;
    }
    state_y = (int)g_state_00535ddc_y;
    g_walkCallback = (void (*)(void))state_y;
    if (state_y > 0x30000) {
        GuardedSeq_00433bb0();
        return;
    }
    PrefixThunkInstallSelf3State_00438f80();
}

/* @addr 0x00466090 (61b)
 *   dec g_walkCallback; store both walk and g_state_0053a238
 *   je → jmp T1; mov [g_walkCallback], 6
 *   call F; pause → ret; push lit; call F2; add esp,4; ret
 */
extern unsigned int g_state_0053a238;
extern void TripleBlockInstallSelf_00465ef0(void);
extern void AndShlStore_00409280(void);
extern int ArgSarStoreJmp_004594f0(void *);
extern void *g_data_004ea990;
__declspec(naked) void DecCallPushCall_00466090(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_0053a238], eax
        je      short L_dcpc_body
        jmp     TripleBlockInstallSelf_00465ef0
L_dcpc_body:
        mov     dword ptr [g_walkCallback], 6
        call    AndShlStore_00409280
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_dcpc_ret
        push    OFFSET g_data_004ea990
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
L_dcpc_ret:
        ret
    }
}

/* @addr 0x0045fca0 (65b)
 *   call F; pause → ret
 *   load baseSel; mov eax,0x2001; store walk and [ecx*4+0x74]
 *   push lit; call F2; pause → ret; add esp,4; jmp T
 */
extern void SlotPhaseResetInstallChain_0048e0e0(void);
extern int IterStepScaledStore24_00428730(void *);
extern void *g_data_00542958;
extern void SelfInstallPhaseDispatch_0045fd30(void);
void CallPauseScaledStorePushCall_0045fca0(void) {
    SlotPhaseResetInstallChain_0048e0e0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x2001;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x74) = 0x2001;
    IterStepScaledStore24_00428730(&g_data_00542958);
    if (g_framePauseFlag != 0) return;
    SelfInstallPhaseDispatch_0045fd30();
}

/* @addr 0x00474010 (63b)
 *   inc g_state_004d57ac twice, push g_scaledInit_00542044 and g_fightGroupHead
 *   onto stack[idx*4]; mov g_scaledInit_00542044 = 0x7c; jmp T.
 */
extern void HalveChainTriplePop2_004740d0(void);
void DoubleStackPushAndJmp_00474010(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_scaledInit_00542044;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_fightGroupHead;
    g_scaledInit_00542044 = 0x7c;
    HalveChainTriplePop2_004740d0();
}

/* @addr 0x00460d80 (65b)
 *   load g_state_00538094; if non-zero zero g_walkCallback and ret.
 *   else load g_fightTableC0, g_fightGroupHead; not eax; store walk
 *   load [ecx*4 + 0x30]; cmp 1; store g_eventQueueCurrent
 *   if equal ret, else shr eax,8; store walk; ret.
 */
extern unsigned int g_state_00538094;
extern u32 g_fightTableC0;
void NotShrCmp1Store_00460d80(void) {
    unsigned int e;
    unsigned int chain;
    if (g_state_00538094 != 0) {
        g_walkCallback = 0;
        return;
    }
    e = ~g_fightTableC0;
    g_walkCallback = (void(*)(void))e;
    chain = *(unsigned int *)(g_fightGroupHead * 4 + 0x30);
    g_eventQueueCurrent = chain;
    if (chain == 1) return;
    g_walkCallback = (void(*)(void))(e >> 8);
}
