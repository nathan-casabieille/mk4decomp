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
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_eventQueueChild;
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
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
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
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004ffd44;
extern unsigned int g_data_004ffd48;
extern unsigned int g_data_00f4d018;
extern unsigned int g_data_00f4d01c;
extern unsigned int g_data_00f4d020;
extern unsigned int g_data_00f4d024;
extern unsigned int g_data_00f4d030;
extern unsigned int g_data_00f4d034;
extern unsigned int g_data_00f4d038;
extern unsigned int g_data_00f4d040;
extern unsigned int g_data_00f4d044;
extern unsigned int g_data_00f4d048;
extern unsigned int g_data_00f6e054;
extern unsigned int g_data_00f70f54;
extern unsigned int g_data_00f70f5c;
extern unsigned int g_data_00f70f60;
extern unsigned int g_data_00f70f64;
extern unsigned int g_data_00f70f68;
extern unsigned int g_data_00f70f6c;
extern unsigned int g_data_00f70f70;
extern unsigned int g_data_00f70f74;
extern unsigned int g_data_00f70f78;
extern unsigned int g_data_00f70f84;
extern unsigned int g_data_00f70f88;
extern unsigned int g_data_00f70f8c;
extern unsigned int g_data_00f70f90;
extern unsigned int g_data_00f70f98;
extern unsigned int g_data_00f70f9c;
extern unsigned int g_data_00f70fa0;
extern unsigned int g_data_00f70fa8;
extern unsigned int g_data_00f70fac;
extern unsigned int g_data_00f70fb0;
extern unsigned int g_data_00f70fb8;
extern unsigned int g_data_00f70fbc;
extern unsigned int g_data_00f70fc0;
extern unsigned int g_data_00f70fc8;
extern unsigned int g_data_00f70fcc;
extern unsigned int g_data_00f70fd8;
extern unsigned int g_data_00f70fdc;
extern unsigned int g_data_00f70fec;
extern unsigned int g_data_00f70ff0;
extern unsigned int g_data_00f712f8;
extern unsigned int g_data_00f712fc;
extern unsigned int g_data_00f71308;
extern unsigned int g_data_00f85b30;
extern unsigned int g_data_00f85b34;
extern unsigned int g_data_00f85b4c;
extern unsigned int g_data_00f85b50;
extern unsigned int g_data_00f85b54;
extern unsigned int g_data_00f85b58;

__declspec(naked) void TexturedTriRasterizeDithered_004c2650(void)
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
        je       L_2c98
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
        jle      L_2c98
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
        jge      L_26de
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_26e7
    L_26de:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_26e7:
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
        jge      L_2724
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_272d
    L_2724:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_272d:
        mov      ecx, dword ptr [g_data_00f70fb8]
        mov      dword ptr [g_data_00f4d034], eax
        mov      eax, dword ptr [g_data_00f70fbc]
        xor      esi, esi
        xor      edx, edx
        cmp      eax, ecx
        mov      dword ptr [g_data_00f70f54], edx
        mov      dword ptr [g_data_00f70f6c], ecx
        mov      dword ptr [g_data_00f712fc], ecx
        jge      L_2770
        mov      dword ptr [g_data_00f70f54], 1
        mov      edx, dword ptr [g_data_00f70f54]
        mov      dword ptr [g_data_00f70f6c], eax
        mov      ecx, eax
        jmp      L_2775
    L_2770:
        mov      dword ptr [g_data_00f712fc], eax
    L_2775:
        mov      eax, dword ptr [g_data_00f70fc0]
        cmp      eax, ecx
        jge      L_2795
        mov      dword ptr [g_data_00f70f54], 2
        mov      edx, dword ptr [g_data_00f70f54]
        mov      dword ptr [g_data_00f70f6c], eax
        mov      ecx, eax
    L_2795:
        cmp      eax, dword ptr [g_data_00f712fc]
        jle      L_27a2
        mov      dword ptr [g_data_00f712fc], eax
    L_27a2:
        cmp      ecx, esi
        jge      L_27ae
        mov      dword ptr [g_data_00f70f6c], esi
        mov      ecx, esi
    L_27ae:
        mov      eax, dword ptr [g_data_004ffd48]
        mov      edi, dword ptr [g_data_00f712fc]
        cmp      edi, eax
        jle      L_27c2
        mov      dword ptr [g_data_00f712fc], eax
    L_27c2:
        mov      eax, dword ptr [g_data_00f85b4c]
        mov      ebx, dword ptr [g_data_00f85b34]
        and      eax, 0xf
        mov      edi, dword ptr [g_data_00f85b50]
        shl      eax, 0x11
        add      eax, ebx
        mov      dword ptr [g_data_00f6e054], ecx
        mov      dword ptr [g_data_00f85b58], eax
        mov      eax, dword ptr [g_data_00f85b54]
        imul     eax, ecx
        add      eax, edi
        mov      dword ptr [g_data_00f70f74], edx
        mov      dword ptr [g_data_00f4d044], eax
        mov      eax, dword ptr [g_data_00f712fc]
        cmp      ecx, eax
        mov      dword ptr [g_data_00f70fcc], esi
        mov      dword ptr [g_data_00f70f68], esi
        jge      L_2c98
        mov      ebx, dword ptr [g_data_00f70f5c]
        jmp      L_2822
    L_281c:
        mov      ecx, dword ptr [g_data_00f70f6c]
    L_2822:
        cmp      dword ptr [g_data_00f70f68], ecx
        jg       L_2c9f
        jmp      L_2836
    L_2830:
        mov      edx, dword ptr [g_data_00f70f54]
    L_2836:
        lea      esi, [edx - 1]
        test     esi, esi
        jge      L_2842
        mov      esi, 2
    L_2842:
        mov      ecx, dword ptr [esi*4 + g_data_00f70fb8]
        mov      eax, dword ptr [edx*4 + g_data_00f70fb8]
        mov      dword ptr [ebp - 4], ecx
        sub      ecx, eax
        mov      dword ptr [ebp - 8], eax
        je       L_28b3
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
    L_28b3:
        mov      ecx, dword ptr [edx*4 + g_data_00f70fa8]
        mov      ebx, dword ptr [edx*4 + g_data_00f70f88]
        mov      edi, dword ptr [edx*4 + g_data_00f70f98]
        mov      eax, dword ptr [g_data_00f70f6c]
        mov      edx, dword ptr [ebp - 8]
        shl      ecx, 0x10
        shl      ebx, 0x10
        shl      edi, 0x10
        sub      eax, edx
        mov      dword ptr [g_data_00f70f64], ecx
        mov      dword ptr [g_data_00f70f5c], ebx
        mov      dword ptr [g_data_00f70f60], edi
        mov      dword ptr [g_data_00f70f78], eax
        je       L_2925
        mov      edx, eax
        imul     edx, dword ptr [g_data_00f4d020]
        add      ecx, edx
        mov      dword ptr [g_data_00f70f64], ecx
        mov      ecx, eax
        imul     ecx, dword ptr [g_data_00f4d018]
        imul     eax, dword ptr [g_data_00f4d01c]
        add      ebx, ecx
        add      edi, eax
        mov      dword ptr [g_data_00f70f5c], ebx
        mov      dword ptr [g_data_00f70f60], edi
    L_2925:
        mov      eax, dword ptr [ebp - 4]
        mov      ecx, dword ptr [g_data_00f70f6c]
        cmp      eax, ecx
        mov      dword ptr [g_data_00f70f54], esi
        mov      dword ptr [g_data_00f70f68], eax
        jle      L_2830
        mov      edx, esi
    L_2943:
        cmp      dword ptr [g_data_00f70fcc], ecx
        jg       L_29fc
    L_294f:
        mov      eax, dword ptr [g_data_00f70f74]
        inc      eax
        cmp      eax, 2
        mov      dword ptr [g_data_00f70f70], eax
        jle      L_2966
        xor      eax, eax
        mov      dword ptr [g_data_00f70f70], eax
    L_2966:
        mov      ecx, dword ptr [g_data_00f70f74]
        mov      esi, dword ptr [eax*4 + g_data_00f70fb8]
        mov      dword ptr [ebp - 4], esi
        mov      ecx, dword ptr [ecx*4 + g_data_00f70fb8]
        sub      esi, ecx
        je       L_29a6
        mov      edx, dword ptr [g_data_00f70f74]
        mov      eax, dword ptr [eax*4 + g_data_00f70fa8]
        sub      eax, dword ptr [edx*4 + g_data_00f70fa8]
        shl      eax, 0x10
        cdq
        idiv     esi
        mov      edx, dword ptr [g_data_00f70f54]
        mov      dword ptr [g_data_00f4d024], eax
    L_29a6:
        mov      eax, dword ptr [g_data_00f70f74]
        mov      esi, dword ptr [eax*4 + g_data_00f70fa8]
        mov      eax, dword ptr [g_data_00f70f6c]
        shl      esi, 0x10
        sub      eax, ecx
        mov      dword ptr [g_data_00f70fc8], esi
        mov      dword ptr [g_data_00f70f78], eax
        je       L_29d8
        imul     eax, dword ptr [g_data_00f4d024]
        add      esi, eax
        mov      dword ptr [g_data_00f70fc8], esi
    L_29d8:
        mov      ecx, dword ptr [g_data_00f70f70]
        mov      eax, dword ptr [ebp - 4]
        mov      dword ptr [g_data_00f70f74], ecx
        mov      ecx, dword ptr [g_data_00f70f6c]
        cmp      eax, ecx
        mov      dword ptr [g_data_00f70fcc], eax
        jle      L_294f
        jmp      L_2a02
    L_29fc:
        mov      esi, dword ptr [g_data_00f70fc8]
    L_2a02:
        mov      eax, dword ptr [g_data_00f70f68]
        mov      ecx, dword ptr [g_data_00f70fcc]
        cmp      eax, ecx
        jl       L_2a13
        mov      eax, ecx
    L_2a13:
        mov      ecx, dword ptr [g_data_00f70f6c]
        mov      dword ptr [g_data_00f70f70], eax
        sub      eax, ecx
        mov      ecx, dword ptr [g_data_00f712fc]
        mov      dword ptr [g_data_00f712f8], eax
        mov      eax, dword ptr [g_data_00f70f70]
        cmp      eax, ecx
        mov      dword ptr [g_data_00f70f6c], eax
        jle      L_2a47
        sub      ecx, eax
        mov      eax, dword ptr [g_data_00f712f8]
        add      eax, ecx
        mov      dword ptr [g_data_00f712f8], eax
    L_2a47:
        mov      eax, dword ptr [g_data_00f712f8]
        test     eax, eax
        jle      L_2c85
    L_2a54:
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
        jle      L_2c0d
        test     edx, edx
        jl       L_2c0d
        cmp      eax, dword ptr [g_data_004ffd44]
        jge      L_2c0d
        mov      edx, ebx
        mov      esi, edi
        add      ecx, eax
        mov      dword ptr [g_data_00f70fd8], edx
        test     eax, eax
        mov      dword ptr [g_data_00f70fdc], esi
        mov      dword ptr [g_data_00f70f78], ecx
        jge      L_2ad2
        mov      esi, eax
        imul     eax, dword ptr [g_data_00f4d034]
        imul     esi, dword ptr [g_data_00f4d030]
        sub      edx, esi
        mov      esi, edi
        sub      esi, eax
        mov      dword ptr [g_data_00f70fd8], edx
        mov      dword ptr [g_data_00f70fdc], esi
        xor      eax, eax
    L_2ad2:
        mov      edi, dword ptr [g_data_00f4d044]
        cmp      ecx, dword ptr [g_data_004ffd44]
        lea      edi, [edi + eax*2]
        mov      dword ptr [g_data_00f4d040], edi
        jle      L_2af5
        mov      ecx, dword ptr [g_data_004ffd44]
        mov      dword ptr [g_data_00f70f78], ecx
    L_2af5:
        sub      ecx, eax
        test     ecx, ecx
        mov      dword ptr [g_data_00f70f70], ecx
        jle      L_2c01
        mov      eax, dword ptr [g_data_00f6e054]
        mov      ebx, edi
        sar      ebx, 1
        and      eax, 1
        and      ebx, 1
        xor      eax, ebx
        mov      dword ptr [g_data_00f70fec], edx
        mov      dword ptr [g_data_00f4d038], esi
        mov      dword ptr [g_data_00f85b30], ecx
        mov      dword ptr [g_data_00f70ff0], edi
        je       L_2b5c
        dec      ecx
        mov      dword ptr [g_data_00f85b30], ecx
        mov      ecx, dword ptr [g_data_00f4d030]
        add      ecx, edx
        mov      edx, dword ptr [g_data_00f4d034]
        add      edx, esi
        add      edi, 2
        mov      dword ptr [g_data_00f70fec], ecx
        mov      dword ptr [g_data_00f4d038], edx
        mov      dword ptr [g_data_00f70ff0], edi
    L_2b5c:
        mov      eax, dword ptr [g_data_00f4d030]
        mov      edx, dword ptr [g_data_00f4d034]
        lea      ecx, [eax + eax]
        lea      eax, [edx + edx]
        mov      dword ptr [g_data_00f4d048], eax
        mov      eax, dword ptr [g_data_00f85b30]
        cmp      eax, 1
        mov      dword ptr [g_data_00f71308], ecx
        jl       L_2bfb
        push     ebp
        mov      ebx, dword ptr [g_data_00f4d038]
        shl      ebx, 0x10
        mov      ecx, dword ptr [g_data_00f4d048]
        rol      ecx, 0x10
        mov      eax, dword ptr [g_data_00f71308]
        shr      eax, 8
        mov      ch, ah
        mov      edx, 0
        mov      eax, dword ptr [g_data_00f4d038]
        shr      eax, 8
        mov      dh, ah
        mov      eax, dword ptr [g_data_00f70fec]
        shr      eax, 8
        mov      dl, ah
        mov      edi, dword ptr [g_data_00f70ff0]
        mov      esi, dword ptr [g_data_00f85b58]
        mov      ebp, dword ptr [g_data_00f71308]
        shl      ebp, 0x10
        mov      eax, dword ptr [g_data_00f85b30]
        mov      bp, ax
        mov      eax, dword ptr [g_data_00f70fec]
        shl      eax, 0x10
    L_2bdd:
        mov      ax, word ptr [esi + edx*2]
        test     ax, ax
        je       L_2be9
        mov      word ptr [edi], ax
    L_2be9:
        add      ebx, ecx
        adc      dh, cl
        add      eax, ebp
        adc      dl, ch
        add      edi, 4
        sub      bp, 2
        jg       L_2bdd
        pop      ebp
    L_2bfb:
        mov      ebx, dword ptr [g_data_00f70f5c]
    L_2c01:
        mov      esi, dword ptr [g_data_00f70fc8]
        mov      edi, dword ptr [g_data_00f70f60]
    L_2c0d:
        mov      ecx, dword ptr [g_data_00f85b54]
        mov      edx, dword ptr [g_data_00f4d044]
        mov      eax, dword ptr [g_data_00f712f8]
        add      edx, ecx
        mov      ecx, dword ptr [g_data_00f70f64]
        mov      dword ptr [g_data_00f4d044], edx
        mov      edx, dword ptr [g_data_00f6e054]
        dec      eax
        inc      edx
        mov      dword ptr [g_data_00f712f8], eax
        mov      dword ptr [g_data_00f6e054], edx
        mov      edx, dword ptr [g_data_00f4d020]
        add      ecx, edx
        mov      edx, dword ptr [g_data_00f4d024]
        mov      dword ptr [g_data_00f70f64], ecx
        mov      ecx, dword ptr [g_data_00f4d018]
        add      esi, edx
        mov      edx, dword ptr [g_data_00f4d01c]
        add      ebx, ecx
        add      edi, edx
        test     eax, eax
        mov      dword ptr [g_data_00f70fc8], esi
        mov      dword ptr [g_data_00f70f5c], ebx
        mov      dword ptr [g_data_00f70f60], edi
        jg       L_2a54
        mov      edx, dword ptr [g_data_00f70f54]
    L_2c85:
        mov      eax, dword ptr [g_data_00f712fc]
        mov      ecx, dword ptr [g_data_00f70f6c]
        cmp      ecx, eax
        jl       L_281c
    L_2c98:
        pop      edi
        pop      esi
        pop      ebx
        mov      esp, ebp
        pop      ebp
        ret
    L_2c9f:
        mov      edi, dword ptr [g_data_00f70f60]
        jmp      L_2943
    }
}
