/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_data_00542050;
extern unsigned int g_data_00542070;
extern unsigned int g_data_00542084;
extern unsigned int g_state_0054208c;
extern unsigned int g_state_00542088;
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_state_00542080;
extern u32 g_pendingNodeType;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_state_0054207c;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_state_00541fa4;
extern unsigned int g_state_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_state_0053a3c0;
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

__declspec(naked) void TexturedTriRasterize_004c13f0(void)
{
    __asm {
        push     ebp
        mov      ebp, esp
        sub      esp, 8
        mov      eax, dword ptr [g_data_00f85b50]
        push     ebx
        push     esi
        push     edi
        test     eax, eax
        je       L_19ab
        mov      edi, dword ptr [g_data_00f70fc0]
        mov      eax, dword ptr [g_data_00f70fb8]
        mov      ebx, dword ptr [g_data_00f70fbc]
        mov      edx, dword ptr [g_data_00f70fb0]
        mov      ecx, dword ptr [g_data_00f70fac]
        sub      edi, eax
        sub      ebx, eax
        mov      eax, dword ptr [g_data_00f70fa8]
        sub      edx, eax
        sub      ecx, eax
        imul     edx, ebx
        imul     ecx, edi
        sub      ecx, edx
        test     ecx, ecx
        mov      dword ptr [g_data_00f70f70], ecx
        jle      L_19ab
        mov      edx, dword ptr [g_data_00f70f90]
        mov      eax, dword ptr [g_data_00f70f88]
        mov      esi, dword ptr [g_data_00f70f8c]
        sub      edx, eax
        sub      esi, eax
        imul     edx, ebx
        imul     esi, edi
        sub      esi, edx
        mov      eax, esi
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 0x80000
        mov      eax, esi
        jge      L_147e
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_1487
    L_147e:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_1487:
        mov      edx, dword ptr [g_data_00f70fa0]
        mov      esi, dword ptr [g_data_00f70f9c]
        mov      dword ptr [g_data_00f4d030], eax
        mov      eax, dword ptr [g_data_00f70f98]
        sub      edx, eax
        sub      esi, eax
        imul     edx, ebx
        imul     esi, edi
        sub      esi, edx
        mov      eax, esi
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 0x80000
        mov      eax, esi
        jge      L_14c4
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_14cd
    L_14c4:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_14cd:
        mov      ecx, dword ptr [g_data_00f70fb8]
        mov      dword ptr [g_data_00f4d034], eax
        mov      eax, dword ptr [g_data_00f70fbc]
        xor      esi, esi
        xor      edx, edx
        cmp      eax, ecx
        mov      dword ptr [g_data_00f70f54], edx
        mov      dword ptr [g_data_00f70f6c], ecx
        mov      dword ptr [g_data_00f712fc], ecx
        jge      L_1510
        mov      dword ptr [g_data_00f70f54], 1
        mov      edx, dword ptr [g_data_00f70f54]
        mov      dword ptr [g_data_00f70f6c], eax
        mov      ecx, eax
        jmp      L_1515
    L_1510:
        mov      dword ptr [g_data_00f712fc], eax
    L_1515:
        mov      eax, dword ptr [g_data_00f70fc0]
        cmp      eax, ecx
        jge      L_1535
        mov      dword ptr [g_data_00f70f54], 2
        mov      edx, dword ptr [g_data_00f70f54]
        mov      dword ptr [g_data_00f70f6c], eax
        mov      ecx, eax
    L_1535:
        cmp      eax, dword ptr [g_data_00f712fc]
        jle      L_1542
        mov      dword ptr [g_data_00f712fc], eax
    L_1542:
        cmp      ecx, esi
        jge      L_154e
        mov      dword ptr [g_data_00f70f6c], esi
        mov      ecx, esi
    L_154e:
        mov      eax, dword ptr [g_data_004ffd48]
        mov      edi, dword ptr [g_data_00f712fc]
        cmp      edi, eax
        jle      L_1562
        mov      dword ptr [g_data_00f712fc], eax
    L_1562:
        mov      eax, dword ptr [g_data_00f85b4c]
        mov      ebx, dword ptr [g_data_00f85b34]
        and      eax, 0xf
        mov      edi, dword ptr [g_data_00f85b50]
        shl      eax, 0x11
        add      eax, ebx
        mov      dword ptr [g_data_00f70f74], edx
        mov      dword ptr [g_data_00f85b58], eax
        mov      eax, dword ptr [g_data_00f85b54]
        imul     eax, ecx
        add      eax, edi
        mov      dword ptr [g_data_00f70fcc], esi
        mov      dword ptr [g_data_00f4d044], eax
        mov      eax, dword ptr [g_data_00f712fc]
        cmp      ecx, eax
        mov      dword ptr [g_data_00f70f68], esi
        jge      L_19ab
        mov      edi, dword ptr [g_data_00f70f5c]
        mov      ebx, dword ptr [g_data_00f70f60]
        jmp      L_15c2
    L_15bc:
        mov      ecx, dword ptr [g_data_00f70f6c]
    L_15c2:
        cmp      dword ptr [g_data_00f70f68], ecx
        jg       L_16e0
    L_15ce:
        lea      esi, [edx - 1]
        test     esi, esi
        jge      L_15da
        mov      esi, 2
    L_15da:
        mov      ecx, dword ptr [esi*4 + g_data_00f70fb8]
        mov      eax, dword ptr [edx*4 + g_data_00f70fb8]
        mov      dword ptr [ebp - 4], ecx
        sub      ecx, eax
        mov      dword ptr [ebp - 8], eax
        je       L_164b
        mov      eax, dword ptr [esi*4 + g_data_00f70fa8]
        mov      edi, dword ptr [edx*4 + g_data_00f70fa8]
        sub      eax, edi
        mov      edi, dword ptr [g_data_00f70f54]
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      ebx, dword ptr [edi*4 + g_data_00f70f88]
        mov      dword ptr [g_data_00f4d020], eax
        mov      eax, dword ptr [esi*4 + g_data_00f70f88]
        sub      eax, ebx
        mov      ebx, dword ptr [edi*4 + g_data_00f70f98]
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      dword ptr [g_data_00f4d018], eax
        mov      eax, dword ptr [esi*4 + g_data_00f70f98]
        sub      eax, ebx
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      edx, edi
        mov      dword ptr [g_data_00f4d01c], eax
    L_164b:
        mov      eax, dword ptr [edx*4 + g_data_00f70fa8]
        mov      edi, dword ptr [edx*4 + g_data_00f70f88]
        mov      ebx, dword ptr [edx*4 + g_data_00f70f98]
        mov      ecx, dword ptr [ebp - 8]
        shl      eax, 0x10
        mov      dword ptr [g_data_00f70f64], eax
        mov      eax, dword ptr [g_data_00f70f6c]
        shl      edi, 0x10
        shl      ebx, 0x10
        sub      eax, ecx
        mov      dword ptr [g_data_00f70f5c], edi
        mov      dword ptr [g_data_00f70f60], ebx
        mov      dword ptr [g_data_00f70f78], eax
        je       L_16c2
        mov      ecx, eax
        mov      edx, dword ptr [g_data_00f70f64]
        imul     ecx, dword ptr [g_data_00f4d020]
        add      edx, ecx
        mov      dword ptr [g_data_00f70f64], edx
        mov      edx, eax
        imul     edx, dword ptr [g_data_00f4d018]
        imul     eax, dword ptr [g_data_00f4d01c]
        add      edi, edx
        add      ebx, eax
        mov      dword ptr [g_data_00f70f5c], edi
        mov      dword ptr [g_data_00f70f60], ebx
    L_16c2:
        mov      eax, dword ptr [ebp - 4]
        mov      ecx, dword ptr [g_data_00f70f6c]
        cmp      eax, ecx
        mov      dword ptr [g_data_00f70f54], esi
        mov      dword ptr [g_data_00f70f68], eax
        mov      edx, esi
        jle      L_15ce
    L_16e0:
        cmp      dword ptr [g_data_00f70fcc], ecx
        jg       L_1799
    L_16ec:
        mov      eax, dword ptr [g_data_00f70f74]
        inc      eax
        cmp      eax, 2
        mov      dword ptr [g_data_00f70f70], eax
        jle      L_1703
        xor      eax, eax
        mov      dword ptr [g_data_00f70f70], eax
    L_1703:
        mov      ecx, dword ptr [g_data_00f70f74]
        mov      esi, dword ptr [eax*4 + g_data_00f70fb8]
        mov      dword ptr [ebp - 4], esi
        mov      ecx, dword ptr [ecx*4 + g_data_00f70fb8]
        sub      esi, ecx
        je       L_1743
        mov      edx, dword ptr [g_data_00f70f74]
        mov      eax, dword ptr [eax*4 + g_data_00f70fa8]
        sub      eax, dword ptr [edx*4 + g_data_00f70fa8]
        shl      eax, 0x10
        cdq
        idiv     esi
        mov      edx, dword ptr [g_data_00f70f54]
        mov      dword ptr [g_data_00f4d024], eax
    L_1743:
        mov      eax, dword ptr [g_data_00f70f74]
        mov      esi, dword ptr [eax*4 + g_data_00f70fa8]
        mov      eax, dword ptr [g_data_00f70f6c]
        shl      esi, 0x10
        sub      eax, ecx
        mov      dword ptr [g_data_00f70fc8], esi
        mov      dword ptr [g_data_00f70f78], eax
        je       L_1775
        imul     eax, dword ptr [g_data_00f4d024]
        add      esi, eax
        mov      dword ptr [g_data_00f70fc8], esi
    L_1775:
        mov      ecx, dword ptr [g_data_00f70f70]
        mov      eax, dword ptr [ebp - 4]
        mov      dword ptr [g_data_00f70f74], ecx
        mov      ecx, dword ptr [g_data_00f70f6c]
        cmp      eax, ecx
        mov      dword ptr [g_data_00f70fcc], eax
        jle      L_16ec
        jmp      L_179f
    L_1799:
        mov      esi, dword ptr [g_data_00f70fc8]
    L_179f:
        mov      eax, dword ptr [g_data_00f70f68]
        mov      ecx, dword ptr [g_data_00f70fcc]
        cmp      eax, ecx
        jl       L_17b0
        mov      eax, ecx
    L_17b0:
        mov      ecx, dword ptr [g_data_00f70f6c]
        mov      dword ptr [g_data_00f70f70], eax
        sub      eax, ecx
        mov      ecx, dword ptr [g_data_00f712fc]
        mov      dword ptr [g_data_00f712f8], eax
        mov      eax, dword ptr [g_data_00f70f70]
        cmp      eax, ecx
        mov      dword ptr [g_data_00f70f6c], eax
        jle      L_17e4
        sub      ecx, eax
        mov      eax, dword ptr [g_data_00f712f8]
        add      eax, ecx
        mov      dword ptr [g_data_00f712f8], eax
    L_17e4:
        mov      eax, dword ptr [g_data_00f712f8]
        test     eax, eax
        jle      L_1998
    L_17f1:
        mov      eax, dword ptr [g_data_00f70f64]
        mov      edx, esi
        sar      edx, 0x10
        sar      eax, 0x10
        mov      ecx, edx
        mov      dword ptr [g_data_00f70f84], edx
        sub      ecx, eax
        mov      dword ptr [g_data_00f70f70], eax
        test     ecx, ecx
        mov      dword ptr [g_data_00f70f78], ecx
        jle      L_192d
        test     edx, edx
        jl       L_192d
        cmp      eax, dword ptr [g_data_004ffd44]
        jge      L_192d
        add      ecx, eax
        mov      dword ptr [g_data_00f70fd8], edi
        test     eax, eax
        mov      dword ptr [g_data_00f70fdc], ebx
        mov      dword ptr [g_data_00f70f78], ecx
        jge      L_1873
        mov      edx, eax
        imul     eax, dword ptr [g_data_00f4d034]
        imul     edx, dword ptr [g_data_00f4d030]
        mov      esi, edi
        sub      esi, edx
        mov      edx, ebx
        sub      edx, eax
        mov      dword ptr [g_data_00f70fd8], esi
        mov      esi, dword ptr [g_data_00f70fc8]
        mov      dword ptr [g_data_00f70fdc], edx
        xor      eax, eax
    L_1873:
        mov      edx, dword ptr [g_data_00f4d044]
        lea      edx, [edx + eax*2]
        mov      dword ptr [g_data_00f4d040], edx
        mov      edx, dword ptr [g_data_004ffd44]
        cmp      ecx, edx
        jle      L_1894
        mov      ecx, edx
        mov      dword ptr [g_data_00f70f78], ecx
    L_1894:
        sub      ecx, eax
        test     ecx, ecx
        mov      dword ptr [g_data_00f70f70], ecx
        jle      L_192d
        push     ebp
        mov      ebx, dword ptr [g_data_00f4d030]
        rol      ebx, 0x10
        mov      eax, dword ptr [g_data_00f4d034]
        shr      eax, 8
        mov      bh, ah
        mov      ecx, dword ptr [g_data_00f70fdc]
        shl      ecx, 0x10
        mov      edx, dword ptr [g_data_00f70fdc]
        shr      edx, 8
        mov      eax, dword ptr [g_data_00f70fd8]
        shr      eax, 8
        mov      dl, ah
        and      edx, 0xffff
        mov      edi, dword ptr [g_data_00f4d040]
        mov      esi, dword ptr [g_data_00f85b58]
        mov      ebp, dword ptr [g_data_00f4d034]
        shl      ebp, 0x10
        mov      eax, dword ptr [g_data_00f70f70]
        mov      bp, ax
        mov      eax, dword ptr [g_data_00f70fd8]
        shl      eax, 0x10
    L_18ff:
        mov      ax, word ptr [esi + edx*2]
        test     ax, ax
        je       L_190b
        mov      word ptr [edi], ax
    L_190b:
        add      ecx, ebp
        adc      dh, bh
        add      eax, ebx
        adc      dl, bl
        add      edi, 2
        dec      bp
        jg       L_18ff
        pop      ebp
        mov      edi, dword ptr [g_data_00f70f5c]
        mov      ebx, dword ptr [g_data_00f70f60]
        mov      esi, dword ptr [g_data_00f70fc8]
    L_192d:
        mov      ecx, dword ptr [g_data_00f85b54]
        mov      edx, dword ptr [g_data_00f4d044]
        mov      eax, dword ptr [g_data_00f712f8]
        add      edx, ecx
        mov      ecx, dword ptr [g_data_00f70f64]
        mov      dword ptr [g_data_00f4d044], edx
        mov      edx, dword ptr [g_data_00f4d020]
        dec      eax
        add      ecx, edx
        mov      edx, dword ptr [g_data_00f4d024]
        mov      dword ptr [g_data_00f70f64], ecx
        mov      ecx, dword ptr [g_data_00f4d018]
        add      esi, edx
        mov      edx, dword ptr [g_data_00f4d01c]
        add      edi, ecx
        add      ebx, edx
        test     eax, eax
        mov      dword ptr [g_data_00f712f8], eax
        mov      dword ptr [g_data_00f70fc8], esi
        mov      dword ptr [g_data_00f70f5c], edi
        mov      dword ptr [g_data_00f70f60], ebx
        jg       L_17f1
        mov      edx, dword ptr [g_data_00f70f54]
    L_1998:
        mov      eax, dword ptr [g_data_00f712fc]
        mov      ecx, dword ptr [g_data_00f70f6c]
        cmp      ecx, eax
        jl       L_15bc
    L_19ab:
        pop      edi
        pop      esi
        pop      ebx
        mov      esp, ebp
        pop      ebp
        ret
    }
}
