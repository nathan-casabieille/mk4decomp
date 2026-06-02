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
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
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

extern unsigned int g_const_004d2ebc;
extern unsigned int g_const_004d2ee4;
extern unsigned int g_const_004d2ee8;
extern unsigned int g_const_004d2f04;
extern unsigned int g_const_004d2f08;
extern unsigned int g_crtFdCloseSlot;
extern unsigned int g_crtAbortBase;
extern unsigned int g_crtFpuSlot1_0052290c;
extern unsigned int g_crtCType;
extern unsigned int g_crtCleanupFlag;
extern unsigned int g_arr_00fa0de0;
extern unsigned int g_iat_GetModuleFileNameA;
extern unsigned int g_iat_WriteFile;
extern unsigned int g_iat_GetStdHandle;
extern void LazyLoadInvoke(void);
extern void Strncpy(void);

__declspec(naked) void RaiseAbortLocalized(void)
{
    __asm {
        mov      ecx, dword ptr [esp + 4]
        sub      esp, 0x1a8
        mov      eax, OFFSET g_crtAbortBase
        push     ebx
        push     ebp
        push     esi
        push     edi
        xor      ebp, ebp
    L_c085:
        cmp      ecx, dword ptr [eax]
        je       short L_c094
        add      eax, 8
        inc      ebp
        cmp      eax, OFFSET g_crtCType
        jb       short L_c085
    L_c094:
        cmp      ecx, dword ptr [ebp*8 + g_crtAbortBase]
        jne      L_c23b
        mov      eax, dword ptr [g_crtCleanupFlag]
        cmp      eax, 1
        je       L_c1fd
        test     eax, eax
        jne      short L_c0c0
        cmp      dword ptr [g_crtFdCloseSlot], 1
        je       L_c1fd
    L_c0c0:
        cmp      ecx, 0xfc
        je       L_c23b
        lea      eax, [esp + 0xb4]
        push     0x104
        push     eax
        push     0
        call     dword ptr [g_iat_GetModuleFileNameA]
        test     eax, eax
        jne      short L_c0fb
        mov      ecx, 5
        mov      esi, OFFSET g_const_004d2f08
        lea      edi, [esp + 0xb4]
        rep movsd
        movsw
        movsb
    L_c0fb:
        lea      edi, [esp + 0xb4]
        or       ecx, 0xffffffff
        xor      eax, eax
        lea      ebx, [esp + 0xb4]
        repne scasb
        not      ecx
        cmp      ecx, 0x3c
        jbe      short L_c144
        lea      edi, [esp + 0xb4]
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        dec      ecx
        push     3
        mov      ebx, ecx
        lea      ecx, [esp + 0xb8]
        sub      ecx, 0x3b
        push     OFFSET g_const_004d2f04
        add      ebx, ecx
        push     ebx
        call     Strncpy
        add      esp, 0xc
    L_c144:
        mov      ecx, 6
        mov      esi, OFFSET g_const_004d2ee8
        lea      edi, [esp + 0x14]
        xor      eax, eax
        rep movsd
        movsw
        or       ecx, 0xffffffff
        mov      edi, ebx
        repne scasb
        not      ecx
        sub      edi, ecx
        lea      edx, [esp + 0x14]
        mov      ebx, ecx
        mov      esi, edi
        or       ecx, 0xffffffff
        mov      edi, edx
        repne scasb
        mov      ecx, ebx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, ebx
        lea      edx, [esp + 0x14]
        and      ecx, 3
        push     0x12010
        rep movsb
        mov      edi, OFFSET g_const_004d2ee4
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        sub      edi, ecx
        push     OFFSET g_const_004d2ebc
        mov      esi, edi
        mov      ebx, ecx
        mov      edi, edx
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, ebx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, ebx
        lea      edx, [esp + 0x1c]
        and      ecx, 3
        rep movsb
        mov      edi, dword ptr [ebp*8 + g_crtFpuSlot1_0052290c]
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      ebx, ecx
        mov      edi, edx
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, ebx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, ebx
        lea      eax, [esp + 0x1c]
        and      ecx, 3
        push     eax
        rep movsb
        call     LazyLoadInvoke
        add      esp, 0xc
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x1a8
        ret
    L_c1fd:
        mov      eax, dword ptr [g_arr_00fa0de0]
        test     eax, eax
        je       short L_c20e
        mov      esi, dword ptr [eax + 0x48]
        cmp      esi, -1
        jne      short L_c218
    L_c20e:
        push     -0xc
        call     dword ptr [g_iat_GetStdHandle]
        mov      esi, eax
    L_c218:
        mov      edx, dword ptr [ebp*8 + g_crtFpuSlot1_0052290c]
        lea      ecx, [esp + 0x10]
        push     0
        push     ecx
        mov      edi, edx
        or       ecx, 0xffffffff
        xor      eax, eax
        repne scasb
        not      ecx
        dec      ecx
        push     ecx
        push     edx
        push     esi
        call     dword ptr [g_iat_WriteFile]
    L_c23b:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x1a8
        ret
    }
}
