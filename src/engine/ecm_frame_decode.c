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
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
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
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
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

extern int Helper_ECM_PostCleanup(int);
extern void ECM_Cleanup(void);
extern void EcmFrameDecode(void);
/* extern void DoubleToInt64(void); -- defined elsewhere with diff sig */
extern unsigned int g_const_004d2998;
extern unsigned int g_const_004d29a0;
extern unsigned int g_const_004d29a8;
extern unsigned int g_const_004d29b0;
extern u32 g_ecmFrameIdx;
extern u32 g_ecmFrameTotal;
extern u8 g_ecmAudioSlots[];
extern unsigned int g_dispatchSave1602;
extern unsigned int g_dispatchSave1603;
extern unsigned int g_dispatchSave1604;
extern unsigned int g_dispatchSave1605;
extern void  * g_ecmFile;
extern u32 g_ecmFrameSizeDiv8;
extern unsigned int g_ecmDSBuffer;
extern u32 g_ecmRunFlag;
extern u32 g_ecmReserved;
extern HANDLE g_ecmThread;
extern u32 g_ecmVolumeFromFtol;
extern u32 g_ecmPlayState;

extern unsigned int g_iat_Sleep;
extern unsigned int g_iat_ResumeThread;
extern unsigned int g_iat_timeGetTime;
extern void DoubleToInt64(void);

__declspec(naked) void EcmStreamTickAdvance(void)
{
    __asm {
        mov      eax, dword ptr [g_ecmFile]
        sub      esp, 8
        push     ebx
        xor      ebx, ebx
        push     ebp
        push     esi
        cmp      eax, ebx
        push     edi
        je       L_1077
        mov      eax, dword ptr [g_ecmFrameSizeDiv8]
        mov      ecx, dword ptr [g_dispatchSave1604]
        cmp      eax, ecx
        jae      L_1077
        cmp      dword ptr [esp + 0x1c], ebx
        je       L_1077
        mov      ebp, dword ptr [esp + 0x20]
        cmp      ebp, ebx
        je       L_1077
        push     1
        call     Helper_ECM_PostCleanup
        mov      eax, dword ptr [g_ecmReserved]
        add      esp, 4
        cmp      eax, ebx
        je       L_0e4d
        mov      dword ptr [g_ecmReserved], ebx
        call     dword ptr [g_iat_timeGetTime]
        mov      ecx, dword ptr [g_ecmFrameSizeDiv8]
        mov      dword ptr [esp + 0x14], ebx
        mov      dword ptr [esp + 0x10], ecx
        mov      esi, eax
        fild     qword ptr [esp + 0x10]
        fmul     qword ptr [g_const_004d2998]
        fmul     qword ptr [g_const_004d29a0]
        fadd     qword ptr [g_const_004d29a8]
        call     DoubleToInt64
        sub      esi, eax
        mov      dword ptr [g_dispatchSave1605], ebx
        mov      dword ptr [g_dispatchSave1602], esi
        mov      dword ptr [g_dispatchSave1603], ebx
    L_0e4d:
        mov      eax, dword ptr [g_ecmFrameSizeDiv8]
        xor      edx, edx
        mov      ecx, 0xf
        div      ecx
        test     edx, edx
        jne      L_0e6f
        mov      eax, dword ptr [g_ecmThread]
        cmp      eax, ebx
        je       L_0e6f
        push     eax
        call     dword ptr [g_iat_ResumeThread]
    L_0e6f:
        mov      edx, dword ptr [g_ecmFrameTotal]
        mov      eax, dword ptr [g_ecmFrameIdx]
        mov      edi, dword ptr [g_iat_Sleep]
        cmp      edx, eax
        jle      L_0ee6
        mov      edx, dword ptr [g_ecmReserved]
        mov      eax, dword ptr [g_ecmDSBuffer]
        inc      edx
        cmp      eax, ebx
        mov      dword ptr [g_ecmReserved], edx
        je       L_0ea0
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x48]
    L_0ea0:
        mov      edx, dword ptr [g_ecmFrameTotal]
        mov      eax, dword ptr [g_ecmFrameIdx]
        xor      esi, esi
        cmp      edx, eax
        jle      L_0ecf
    L_0eb1:
        cmp      esi, 0xbb8
        jge      L_0eee
        push     0xa
        call     edi
        mov      eax, dword ptr [g_ecmFrameTotal]
        mov      ecx, dword ptr [g_ecmFrameIdx]
        add      esi, 0xa
        cmp      eax, ecx
        jg       L_0eb1
    L_0ecf:
        cmp      esi, 0xbb8
        jl       L_0ee6
        call     ECM_Cleanup
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_0ee6:
        cmp      dword ptr [g_ecmPlayState], ebx
        je       L_0efd
    L_0eee:
        call     ECM_Cleanup
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_0efd:
        mov      ecx, dword ptr [esp + 0x1c]
        mov      eax, dword ptr [g_ecmFrameSizeDiv8]
        push     ecx
        xor      edx, edx
        mov      ecx, 0xf
        push     ebp
        div      ecx
        mov      eax, dword ptr [g_ecmFrameTotal]
        push     edx
        cdq
        xor      eax, edx
        sub      eax, edx
        and      eax, 3
        xor      eax, edx
        sub      eax, edx
        imul     eax, eax, 0x5ab5c
        add      eax, OFFSET g_ecmAudioSlots
        push     eax
        call     EcmFrameDecode
        add      esp, 0x10
        test     eax, eax
        jne      L_1077
        call     dword ptr [g_iat_timeGetTime]
        mov      edx, eax
        mov      eax, dword ptr [g_dispatchSave1605]
        sub      eax, edx
        dec      eax
        cmp      eax, ebx
        jle      L_0f56
        push     eax
        call     edi
    L_0f56:
        mov      eax, dword ptr [g_ecmDSBuffer]
        cmp      eax, ebx
        je       L_0fbf
        mov      ecx, dword ptr [eax]
        lea      edx, [esp + 0x1c]
        push     edx
        push     eax
        call     dword ptr [ecx + 0x24]
        test     byte ptr [esp + 0x1c], 1
        jne      L_0fbf
        mov      eax, dword ptr [g_ecmDSBuffer]
        mov      edx, dword ptr [g_ecmVolumeFromFtol]
        push     edx
        push     eax
        mov      ecx, dword ptr [eax]
        call     dword ptr [ecx + 0x3c]
        mov      ecx, dword ptr [g_ecmFrameSizeDiv8]
        xor      edx, edx
        mov      esi, dword ptr [g_ecmDSBuffer]
        lea      eax, [ecx + ecx*2]
        shl      eax, 4
        add      eax, ecx
        mov      ecx, 0x2b110
        mov      edi, dword ptr [esi]
        lea      eax, [eax + eax*2]
        lea      eax, [eax + eax*4]
        shl      eax, 2
        div      ecx
        push     edx
        push     esi
        call     dword ptr [edi + 0x34]
        mov      eax, dword ptr [g_ecmDSBuffer]
        push     1
        push     ebx
        push     ebx
        mov      edx, dword ptr [eax]
        push     eax
        call     dword ptr [edx + 0x30]
    L_0fbf:
        cmp      dword ptr [g_ecmRunFlag], ebx
        je       L_0fdd
        call     dword ptr [g_iat_timeGetTime]
        mov      edi, eax
        mov      dword ptr [g_ecmRunFlag], ebx
        mov      dword ptr [g_dispatchSave1602], edi
        jmp      L_0fe3
    L_0fdd:
        mov      edi, dword ptr [g_dispatchSave1602]
    L_0fe3:
        mov      esi, dword ptr [g_ecmFrameSizeDiv8]
        mov      dword ptr [esp + 0x14], ebx
        mov      dword ptr [esp + 0x10], esi
        fild     qword ptr [esp + 0x10]
        fmul     qword ptr [g_const_004d2998]
        fmul     qword ptr [g_const_004d29a0]
        fsubr    qword ptr [g_const_004d29b0]
        call     DoubleToInt64
        sub      edi, eax
        mov      eax, dword ptr [g_dispatchSave1603]
        cmp      eax, ebx
        mov      dword ptr [g_dispatchSave1605], edi
        jne      L_1048
        call     dword ptr [g_iat_timeGetTime]
        mov      ecx, dword ptr [g_dispatchSave1605]
        mov      esi, dword ptr [g_ecmFrameSizeDiv8]
        cmp      eax, ecx
        jb       L_1048
        cmp      esi, ebx
        je       L_1048
        mov      eax, dword ptr [g_dispatchSave1604]
        dec      eax
        cmp      esi, eax
        je       L_1048
        mov      ecx, 1
        jmp      L_104a
    L_1048:
        xor      ecx, ecx
    L_104a:
        inc      esi
        mov      eax, 0x88888889
        mul      esi
        shr      edx, 3
        cmp      ecx, ebx
        mov      dword ptr [g_dispatchSave1603], ecx
        mov      dword ptr [g_ecmFrameSizeDiv8], esi
        mov      dword ptr [g_ecmFrameTotal], edx
        je       L_106d
        neg      esi
    L_106d:
        mov      eax, esi
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_1077:
        pop      edi
        pop      esi
        pop      ebp
        xor      eax, eax
        pop      ebx
        add      esp, 8
        ret
    }
}
