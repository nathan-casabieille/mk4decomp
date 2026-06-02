/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

/*
 * CharSelect_1v1 - 292b audio 5-iter byte-table loop variant.
 *   Same shape as CharSelect_Team but uses g_byteTab_004f3d80 (offsets
 *   +0/+4/+8/+0xc/+0x10 → 0x004f3d80..0x004f3d90), iterates 5 times instead of 8, and uses
 *   strings 0x004f44c4/a8/94 (case 4) and 0x004f447c/60/4c (case 3) in the printf.
 */
extern unsigned int g_byteTab_004f3d80;
extern unsigned int g_audioMixerKnob_005433c4;
extern unsigned int g_audioMixerKnob2_00543440;
extern void GuardedSetupCallTailJmp_004a1fa0(void);
extern void Helper_Sprintf(void);
extern void MStackPush2ChainLLInsert_00406790(void);

__declspec(naked) void CharSelect_1v1(void)
{
    __asm
    {
        push    esi
        push    edi
        xor     edi, edi
    L_a89_iter:
        mov     ecx, dword ptr [g_baseSel]
        lea     esi, [edi*8 + edi]
        shl     esi, 2
        movsx   eax, byte ptr [esi + g_byteTab_004f3d80]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert_00406790
        mov     eax, edi
        sub     eax, 3
        je      short L_a89_case3
        dec     eax
        jne     short L_a89_skipCase
        mov     eax, dword ptr [g_audioMixerKnob_005433c4]
        test    eax, eax
        jne     short L_a89_c4_1
        push    0x004f44c4
        jmp     short L_a89_printf
    L_a89_c4_1:
        cmp     eax, 1
        jne     short L_a89_c4_2
        push    0x004f44a8
        jmp     short L_a89_printf
    L_a89_c4_2:
        cmp     eax, 2
        jne     short L_a89_skipCase
        push    0x004f4494
        jmp     short L_a89_printf
    L_a89_case3:
        mov     eax, dword ptr [g_audioMixerKnob2_00543440]
        test    eax, eax
        jne     short L_a89_c3_1
        push    0x004f447c
        jmp     short L_a89_printf
    L_a89_c3_1:
        cmp     eax, 1
        jne     short L_a89_c3_2
        push    0x004f4460
        jmp     short L_a89_printf
    L_a89_c3_2:
        cmp     eax, 2
        jne     short L_a89_skipCase
        push    0x004f444c
    L_a89_printf:
        push    0x00543450
        call    Helper_Sprintf
        add     esp, 8
    L_a89_skipCase:
        mov     eax, dword ptr [esi + 0x004f3d8c]
        mov     ecx, dword ptr [esi + 0x004f3d84]
        push    eax
        push    ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_currentNodeIdx], ecx
        call    GuardedSetupCallTailJmp_004a1fa0
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [esi + 0x004f3d90]
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x5c], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [eax*4 + 0x54]
        mov     dword ptr [esi + 0x004f3d88], edx
        mov     edx, dword ptr [g_baseSel]
        movsx   ecx, byte ptr [esi + g_byteTab_004f3d80]
        mov     dword ptr [g_eventQueueCurrent], ecx
        add     ecx, edx
        inc     edi
        mov     dword ptr [ecx*4], eax
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [esi + 0x004f3d88]
        cmp     edi, 5
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [esi + 0x004f3d8c]
        mov     dword ptr [eax*4 + 0x58], edx
        jb      L_a89_iter
        pop     edi
        pop     esi
        ret
    }
}
