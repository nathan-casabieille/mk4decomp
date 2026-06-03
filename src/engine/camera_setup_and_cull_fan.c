/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
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

extern unsigned int g_const_004d2a20;
extern unsigned int g_fpBam2PiScale;
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af9a0;
extern unsigned int g_dispatchSave1504;
extern unsigned int g_dispatchSave1505;
extern unsigned int g_dispatchSave1506;
extern unsigned int g_dispatchSave1507;
extern unsigned int g_dispatchSave1508;
extern unsigned int g_dispatchSave1509;
extern unsigned int g_dispatchSave1510;
extern unsigned int g_dispatchSave1511;
extern unsigned int g_dispatchSave1512;
extern unsigned int g_word_00ab47f8;
extern unsigned int g_word_00ab47fa;
extern unsigned int g_word_00ab47fc;
extern unsigned int g_dispatchSave1519;
extern unsigned int g_dispatchSave1520;
extern unsigned int g_dispatchSave1521;
extern unsigned int g_dispatchSave1522;
extern unsigned int g_dispatchSave1523;
extern unsigned int g_dispatchSave1524;
extern unsigned int g_dispatchSave1525;
extern unsigned int g_dispatchSave1526;
extern unsigned int g_dispatchSave1527;
extern unsigned int g_dispatchSave1550;
extern unsigned int g_dispatchSave1554;
extern unsigned int g_dispatchSave1555;
extern unsigned int g_dispatchSave1556;
extern unsigned int g_dispatchSave1557;
extern unsigned int g_dispatchSave1558;
extern unsigned int g_dispatchSave1567;
extern unsigned int g_dispatchSave1574;
extern unsigned int g_pointPosX;
extern unsigned int g_pointPosY;
extern unsigned int g_pointPosZ;
extern unsigned int g_dispatchSave1575;
extern unsigned int g_dispatchSave1576;
extern unsigned int g_dispatchSave1577;
extern void AltCamMatrixProject(void);
extern void Color15BitPacker(void);
extern void DoubleToInt64(void);
extern void Mat3x3VecMul6Bit(void);
extern void PackColor(void);
extern void Vec3NormalizeScaleStore(void);

__declspec(naked) void CameraSetupAndCullFan(void)
{
    __asm {
        sub      esp, 0x18
        mov      eax, dword ptr [g_pendingNodeType]
        push     ebx
        mov      dword ptr [esp + 0x18], eax
        mov      eax, dword ptr [g_tickX3]
        push     ebp
        push     esi
        lea      eax, [eax + eax*2]
        mov      edx, dword ptr [g_currentNodeIdx]
        shl      eax, 5
        shr      eax, 8
        push     edi
        mov      edi, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_dispatchSave1575], eax
        mov      eax, dword ptr [g_tickW1]
        mov      dword ptr [esp + 0x20], edx
        mov      dword ptr [g_dispatchSave1576], eax
        mov      ecx, dword ptr [edi*4 + 0x3c]
        sar      ecx, 8
        cmp      ecx, 0x60
        mov      dword ptr [g_walkCallback], ecx
        jge      L_9a0e
        mov      ecx, 0x60
        jmp      L_9a1b
    L_9a0e:
        cmp      ecx, 0xa0
        jle      L_9a21
        mov      ecx, 0xa0
    L_9a1b:
        mov      dword ptr [g_walkCallback], ecx
    L_9a21:
        mov      esi, eax
        imul     esi, ecx
        shl      esi, 3
        sar      esi, 8
        cmp      ecx, 0x100
        jle      L_9a3f
        mov      ecx, 0x100
        mov      dword ptr [g_walkCallback], ecx
    L_9a3f:
        imul     eax, ecx
        sar      eax, 8
        mov      word ptr [g_dispatchSave1504], si
        mov      word ptr [g_dispatchSave1507], si
        mov      word ptr [g_dispatchSave1510], si
        mov      dword ptr [g_dispatchSave1577], eax
        sar      esi, 1
        mov      eax, esi
        lea      ecx, [edx + 0x15]
        neg      eax
        mov      word ptr [g_dispatchSave1505], ax
        mov      word ptr [g_dispatchSave1508], ax
        mov      word ptr [g_dispatchSave1511], ax
        lea      eax, [edi + 0x15]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      edx, dword ptr [ecx*4]
        mov      edi, dword ptr [eax*4]
        sub      edx, edi
        push     OFFSET g_dispatchSave1525
        sar      edx, 8
        mov      dword ptr [g_dispatchSave1525], edx
        mov      edx, dword ptr [ecx*4 + 4]
        mov      ebx, dword ptr [eax*4 + 4]
        push     OFFSET g_dispatchSave1525
        sub      edx, ebx
        sar      edx, 8
        mov      dword ptr [g_dispatchSave1526], edx
        mov      ecx, dword ptr [ecx*4 + 8]
        mov      edx, dword ptr [eax*4 + 8]
        mov      eax, dword ptr [g_dispatchSave1555]
        sub      ecx, edx
        mov      edx, dword ptr [g_dispatchSave1554]
        sar      ecx, 8
        mov      dword ptr [g_dispatchSave1527], ecx
        mov      ecx, dword ptr [g_dispatchSave1556]
        mov      dword ptr [g_vtxMat], edx
        mov      edx, dword ptr [g_dispatchSave1557]
        mov      dword ptr [g_mat3x3_007af994], eax
        mov      ax, word ptr [g_dispatchSave1558]
        mov      dword ptr [g_mat3x3_007af998], ecx
        mov      dword ptr [g_mat3x3_007af99c], edx
        mov      word ptr [g_mat3x3_007af9a0], ax
        call     Mat3x3VecMul6Bit
        mov      edi, dword ptr [g_dispatchSave1525]
        mov      ecx, dword ptr [g_dispatchSave1526]
        mov      ebx, dword ptr [g_dispatchSave1527]
        mov      word ptr [g_dispatchSave1520], cx
        movsx    eax, di
        movsx    ecx, cx
        mov      ebp, eax
        mov      dword ptr [esp + 0x18], eax
        movsx    edx, bx
        imul     ebp, eax
        mov      eax, ecx
        mov      dword ptr [esp + 0x1c], ecx
        imul     eax, ecx
        mov      ecx, edx
        add      ebp, eax
        imul     ecx, edx
        add      ebp, ecx
        add      esp, 8
        mov      dword ptr [esp + 0x1c], ebp
        mov      word ptr [g_dispatchSave1519], di
        fild     dword ptr [esp + 0x1c]
        mov      word ptr [g_dispatchSave1521], bx
        mov      dword ptr [esp + 0x18], edx
        fsqrt
        fcom     qword ptr [g_const_004d2a20]
        fnstsw   ax
        test     ah, 0x40
        jne      L_9bca
        fdivr    qword ptr [g_fpBam2PiScale]
        fild     dword ptr [esp + 0x10]
        fmul     st, st(1)
        call     DoubleToInt64
        fild     dword ptr [esp + 0x14]
        mov      di, ax
        mov      word ptr [g_dispatchSave1519], di
        fmul     st, st(1)
        call     DoubleToInt64
        fild     dword ptr [esp + 0x18]
        mov      word ptr [g_dispatchSave1520], ax
        fmul     st, st(1)
        call     DoubleToInt64
        mov      bx, ax
        fstp     st(0)
        mov      word ptr [g_dispatchSave1521], bx
        jmp      L_9bcc
    L_9bca:
        fstp     st(0)
    L_9bcc:
        mov      eax, dword ptr [g_dispatchSave1520]
        mov      dx, di
        neg      dx
        mov      word ptr [g_word_00ab47f8], dx
        mov      cx, bx
        neg      eax
        movsx    edx, bx
        neg      cx
        mov      word ptr [g_word_00ab47fa], ax
        mov      word ptr [g_word_00ab47fc], cx
        movsx    eax, word ptr [g_dispatchSave1520]
        neg      edx
        movsx    ecx, di
        push     edx
        push     eax
        push     ecx
        push     0
        call     Vec3NormalizeScaleStore
        add      esp, 0x10
        push     0x50
        push     0x50
        push     0x50
        call     Color15BitPacker
        add      esp, 0xc
        push     esi
        push     esi
        push     esi
        push     0
        call     PackColor
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_pointPosX]
        mov      esi, dword ptr [g_pointPosY]
        add      esp, 0x10
        mov      edi, dword ptr [eax*4]
        sub      ecx, edi
        mov      edi, dword ptr [g_pointPosZ]
        sar      ecx, 8
        mov      dword ptr [g_dispatchSave1525], ecx
        mov      edx, dword ptr [eax*4 + 4]
        sub      esi, edx
        sar      esi, 8
        mov      dword ptr [g_dispatchSave1526], esi
        mov      ebx, dword ptr [eax*4 + 8]
        sub      edi, ebx
        mov      edx, esi
        sar      edi, 8
        imul     edx, esi
        mov      ebx, edi
        mov      eax, ecx
        imul     ebx, edi
        imul     eax, ecx
        sar      ebx, 0xc
        sar      edx, 0xc
        add      ebx, edx
        mov      dword ptr [g_dispatchSave1527], edi
        sar      eax, 0xc
        add      ebx, eax
        je       L_9df0
        mov      eax, 0x180000
        mov      bp, cx
        cdq
        idiv     ebx
        mov      word ptr [g_dispatchSave1524], di
        mov      word ptr [g_dispatchSave1522], bp
        movsx    edx, di
        mov      word ptr [g_dispatchSave1523], si
        mov      dword ptr [esp + 0x18], edx
        mov      ebx, eax
        movsx    eax, cx
        movsx    ecx, si
        mov      edi, eax
        mov      dword ptr [esp + 0x10], eax
        imul     edi, eax
        mov      eax, ecx
        mov      dword ptr [esp + 0x14], ecx
        imul     eax, ecx
        mov      ecx, edx
        add      edi, eax
        imul     ecx, edx
        add      edi, ecx
        mov      dword ptr [esp + 0x1c], edi
        fild     dword ptr [esp + 0x1c]
        sar      ebx, 8
        fsqrt
        fcom     qword ptr [g_const_004d2a20]
        fnstsw   ax
        test     ah, 0x40
        jne      L_9d42
        fdivr    qword ptr [g_fpBam2PiScale]
        fild     dword ptr [esp + 0x10]
        fmul     st, st(1)
        call     DoubleToInt64
        fild     dword ptr [esp + 0x14]
        mov      bp, ax
        mov      word ptr [g_dispatchSave1522], bp
        fmul     st, st(1)
        call     DoubleToInt64
        fild     dword ptr [esp + 0x18]
        mov      si, ax
        mov      word ptr [g_dispatchSave1523], si
        fmul     st, st(1)
        call     DoubleToInt64
        fstp     st(0)
        mov      word ptr [g_dispatchSave1524], ax
        jmp      L_9d44
    L_9d42:
        fstp     st(0)
    L_9d44:
        cmp      ebx, 0x100
        jle      L_9d51
        mov      ebx, 0x100
    L_9d51:
        imul     ebx, dword ptr [g_tickX3]
        mov      edx, dword ptr [g_gtAxisX]
        mov      eax, dword ptr [g_gtAxisY]
        mov      ecx, dword ptr [g_gtAxisZ]
        and      edx, 0xffff
        and      eax, 0xffff
        sub      edx, 0x8000
        and      ecx, 0xffff
        sub      eax, 0x8000
        shr      ebx, 8
        sar      edx, 8
        sub      ecx, 0x8000
        imul     edx, ebx
        sar      eax, 8
        sar      ecx, 8
        imul     eax, ebx
        imul     ecx, ebx
        mov      word ptr [g_dispatchSave1506], dx
        mov      word ptr [g_dispatchSave1509], ax
        movsx    edx, word ptr [g_dispatchSave1524]
        mov      word ptr [g_dispatchSave1512], cx
        push     edx
        movsx    eax, si
        movsx    ecx, bp
        push     eax
        push     ecx
        push     1
        call     Vec3NormalizeScaleStore
        movsx    edx, word ptr [g_dispatchSave1512]
        movsx    eax, word ptr [g_dispatchSave1509]
        movsx    ecx, word ptr [g_dispatchSave1506]
        add      esp, 0x10
        push     edx
        push     eax
        push     ecx
        push     1
        call     PackColor
        add      esp, 0x10
    L_9df0:
        mov      eax, dword ptr [g_fightGroupHead]
        test     eax, 0x180000
        je       L_9e10
        mov      ecx, dword ptr [g_tickFlagZ]
        test     ecx, ecx
        je       L_9e10
        add      dword ptr [g_dispatchSave1567], 0x2b85
    L_9e10:
        test     ah, 0x10
        je       L_9e2d
        mov      eax, dword ptr [g_dispatchSave1574]
        test     eax, eax
        jl       L_9e2d
        push     0
        push     OFFSET g_dispatchSave1550
        call     AltCamMatrixProject
        add      esp, 8
    L_9e2d:
        mov      edx, dword ptr [esp + 0x20]
        mov      eax, dword ptr [esp + 0x24]
        pop      edi
        pop      esi
        pop      ebp
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_pendingNodeType], eax
        pop      ebx
        add      esp, 0x18
        ret
    }
}
