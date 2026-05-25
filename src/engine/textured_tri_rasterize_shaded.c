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
extern unsigned int g_data_00f4d014;
extern unsigned int g_data_00f4d018;
extern unsigned int g_data_00f4d01c;
extern unsigned int g_data_00f4d020;
extern unsigned int g_data_00f4d024;
extern unsigned int g_data_00f4d028;
extern unsigned int g_data_00f4d02c;
extern unsigned int g_data_00f4d030;
extern unsigned int g_data_00f4d034;
extern unsigned int g_data_00f4d040;
extern unsigned int g_data_00f4d044;
extern unsigned int g_data_00f70f54;
extern unsigned int g_data_00f70f58;
extern unsigned int g_data_00f70f5c;
extern unsigned int g_data_00f70f60;
extern unsigned int g_data_00f70f64;
extern unsigned int g_data_00f70f68;
extern unsigned int g_data_00f70f6c;
extern unsigned int g_data_00f70f70;
extern unsigned int g_data_00f70f74;
extern unsigned int g_data_00f70f78;
extern unsigned int g_data_00f70f7c;
extern unsigned int g_data_00f70f7d;
extern unsigned int g_data_00f70f7e;
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
extern unsigned int g_data_00f70fd4;
extern unsigned int g_data_00f70fd8;
extern unsigned int g_data_00f70fdc;
extern unsigned int g_data_00f70fe0;
extern unsigned int g_data_00f712f8;
extern unsigned int g_data_00f712fc;
extern unsigned int g_data_00f85b34;
extern unsigned int g_data_00f85b4c;
extern unsigned int g_data_00f85b50;
extern unsigned int g_data_00f85b54;
extern unsigned int g_data_00f85b58;

__declspec(naked) void TexturedTriRasterizeShaded_004c2cb0(void)
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
        je       L_334f
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
        jle      L_334f
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
        jge      L_2d3e
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_2d47
    L_2d3e:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_2d47:
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
        jge      L_2d84
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_2d8d
    L_2d84:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_2d8d:
        mov      dword ptr [g_data_00f4d034], eax
        mov      eax, dword ptr [g_data_00f70f7c]
        xor      edx, edx
        and      eax, 0xff
        mov      dl, byte ptr [g_data_00f70f7e]
        sub      edx, eax
        imul     edx, ebx
        xor      ebx, ebx
        mov      bl, byte ptr [g_data_00f70f7d]
        mov      esi, ebx
        sub      esi, eax
        imul     esi, edi
        sub      esi, edx
        mov      eax, esi
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 0x80000
        mov      eax, esi
        jge      L_2dd5
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_2dde
    L_2dd5:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_2dde:
        mov      ecx, dword ptr [g_data_00f70fbc]
        mov      dword ptr [g_data_00f4d02c], eax
        mov      eax, dword ptr [g_data_00f70fb8]
        xor      edx, edx
        xor      edi, edi
        cmp      ecx, eax
        mov      dword ptr [g_data_00f70f54], edi
        mov      dword ptr [g_data_00f70f6c], eax
        mov      dword ptr [g_data_00f712fc], eax
        jge      L_2e1b
        mov      edi, 1
        mov      dword ptr [g_data_00f70f6c], ecx
        mov      dword ptr [g_data_00f70f54], edi
        mov      eax, ecx
        jmp      L_2e21
    L_2e1b:
        mov      dword ptr [g_data_00f712fc], ecx
    L_2e21:
        mov      ecx, dword ptr [g_data_00f70fc0]
        cmp      ecx, eax
        jge      L_2e3e
        mov      edi, 2
        mov      dword ptr [g_data_00f70f6c], ecx
        mov      dword ptr [g_data_00f70f54], edi
        mov      eax, ecx
    L_2e3e:
        cmp      ecx, dword ptr [g_data_00f712fc]
        jle      L_2e4c
        mov      dword ptr [g_data_00f712fc], ecx
    L_2e4c:
        cmp      eax, edx
        jge      L_2e58
        mov      dword ptr [g_data_00f70f6c], edx
        mov      eax, edx
    L_2e58:
        mov      ecx, dword ptr [g_data_004ffd48]
        mov      esi, dword ptr [g_data_00f712fc]
        cmp      esi, ecx
        jle      L_2e6e
        mov      dword ptr [g_data_00f712fc], ecx
    L_2e6e:
        mov      ecx, dword ptr [g_data_00f85b4c]
        mov      ebx, dword ptr [g_data_00f85b34]
        and      ecx, 0xf
        mov      esi, dword ptr [g_data_00f85b50]
        shl      ecx, 0x11
        add      ecx, ebx
        mov      dword ptr [g_data_00f70f74], edi
        mov      dword ptr [g_data_00f85b58], ecx
        mov      ecx, dword ptr [g_data_00f85b54]
        imul     ecx, eax
        add      ecx, esi
        mov      dword ptr [g_data_00f70fcc], edx
        mov      dword ptr [g_data_00f4d044], ecx
        mov      ecx, dword ptr [g_data_00f712fc]
        cmp      eax, ecx
        mov      dword ptr [g_data_00f70f68], edx
        jge      L_334f
        mov      ebx, dword ptr [g_data_00f70f5c]
        jmp      L_2ecc
    L_2ec7:
        mov      eax, dword ptr [g_data_00f70f6c]
    L_2ecc:
        cmp      dword ptr [g_data_00f70f68], eax
        jg       L_3023
    L_2ed8:
        lea      esi, [edi - 1]
        test     esi, esi
        jge      L_2ee4
        mov      esi, 2
    L_2ee4:
        mov      ecx, dword ptr [esi*4 + g_data_00f70fb8]
        mov      eax, dword ptr [edi*4 + g_data_00f70fb8]
        mov      dword ptr [ebp - 4], ecx
        sub      ecx, eax
        mov      dword ptr [ebp - 8], eax
        je       L_2f6a
        mov      eax, dword ptr [esi*4 + g_data_00f70fa8]
        mov      ebx, dword ptr [edi*4 + g_data_00f70fa8]
        sub      eax, ebx
        mov      ebx, dword ptr [edi*4 + g_data_00f70f88]
        shl      eax, 0x10
        cdq
        idiv     ecx
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
        xor      edx, edx
        mov      dl, byte ptr [edi + g_data_00f70f7c]
        mov      dword ptr [g_data_00f4d01c], eax
        xor      eax, eax
        mov      al, byte ptr [esi + g_data_00f70f7c]
        sub      eax, edx
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      dword ptr [g_data_00f4d014], eax
    L_2f6a:
        mov      edx, dword ptr [edi*4 + g_data_00f70fa8]
        mov      ebx, dword ptr [edi*4 + g_data_00f70f88]
        mov      ecx, dword ptr [edi*4 + g_data_00f70f98]
        xor      eax, eax
        mov      al, byte ptr [edi + g_data_00f70f7c]
        mov      edi, dword ptr [ebp - 8]
        shl      eax, 0x10
        mov      dword ptr [g_data_00f70f58], eax
        mov      eax, dword ptr [g_data_00f70f6c]
        shl      edx, 0x10
        shl      ebx, 0x10
        shl      ecx, 0x10
        sub      eax, edi
        mov      dword ptr [g_data_00f70f64], edx
        mov      dword ptr [g_data_00f70f5c], ebx
        mov      dword ptr [g_data_00f70f60], ecx
        mov      dword ptr [g_data_00f70f78], eax
        je       L_3003
        mov      edi, eax
        imul     edi, dword ptr [g_data_00f4d020]
        add      edx, edi
        mov      dword ptr [g_data_00f70f64], edx
        mov      edx, eax
        imul     edx, dword ptr [g_data_00f4d018]
        add      ebx, edx
        mov      edx, eax
        imul     edx, dword ptr [g_data_00f4d01c]
        imul     eax, dword ptr [g_data_00f4d014]
        add      ecx, edx
        mov      dword ptr [g_data_00f70f5c], ebx
        mov      dword ptr [g_data_00f70f60], ecx
        mov      ecx, dword ptr [g_data_00f70f58]
        add      ecx, eax
        mov      dword ptr [g_data_00f70f58], ecx
    L_3003:
        mov      eax, dword ptr [ebp - 4]
        mov      ecx, dword ptr [g_data_00f70f6c]
        cmp      eax, ecx
        mov      edi, esi
        mov      dword ptr [g_data_00f70f68], eax
        jle      L_2ed8
        mov      dword ptr [g_data_00f70f54], edi
        mov      eax, ecx
    L_3023:
        cmp      dword ptr [g_data_00f70fcc], eax
        jg       L_30ca
    L_302f:
        mov      edx, dword ptr [g_data_00f70f74]
        lea      ecx, [edx + 1]
        cmp      ecx, 2
        jle      L_303f
        xor      ecx, ecx
    L_303f:
        mov      esi, dword ptr [ecx*4 + g_data_00f70fb8]
        mov      edx, dword ptr [edx*4 + g_data_00f70fb8]
        mov      dword ptr [ebp - 4], esi
        sub      esi, edx
        mov      dword ptr [ebp - 8], edx
        je       L_307e
        mov      edx, dword ptr [g_data_00f70f74]
        mov      eax, dword ptr [ecx*4 + g_data_00f70fa8]
        sub      eax, dword ptr [edx*4 + g_data_00f70fa8]
        shl      eax, 0x10
        cdq
        idiv     esi
        mov      edx, dword ptr [ebp - 8]
        mov      dword ptr [g_data_00f4d024], eax
        mov      eax, dword ptr [g_data_00f70f6c]
    L_307e:
        mov      esi, dword ptr [g_data_00f70f74]
        mov      esi, dword ptr [esi*4 + g_data_00f70fa8]
        shl      esi, 0x10
        sub      eax, edx
        mov      dword ptr [g_data_00f70fc8], esi
        mov      dword ptr [g_data_00f70f78], eax
        je       L_30ac
        imul     eax, dword ptr [g_data_00f4d024]
        add      esi, eax
        mov      dword ptr [g_data_00f70fc8], esi
    L_30ac:
        mov      eax, dword ptr [g_data_00f70f6c]
        mov      dword ptr [g_data_00f70f74], ecx
        mov      ecx, dword ptr [ebp - 4]
        cmp      ecx, eax
        mov      dword ptr [g_data_00f70fcc], ecx
        jle      L_302f
        jmp      L_30d0
    L_30ca:
        mov      esi, dword ptr [g_data_00f70fc8]
    L_30d0:
        mov      ecx, dword ptr [g_data_00f70f68]
        mov      edx, dword ptr [g_data_00f70fcc]
        cmp      ecx, edx
        jge      L_30e2
        mov      edx, ecx
    L_30e2:
        mov      ecx, edx
        mov      dword ptr [g_data_00f70f70], edx
        sub      ecx, eax
        mov      eax, dword ptr [g_data_00f712fc]
        cmp      edx, eax
        mov      dword ptr [g_data_00f712f8], ecx
        mov      dword ptr [g_data_00f70f6c], edx
        jle      L_310b
        sub      eax, edx
        add      ecx, eax
        mov      dword ptr [g_data_00f712f8], ecx
    L_310b:
        test     ecx, ecx
        jle      L_333c
    L_3113:
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
        jle      L_32bd
        test     edx, edx
        jl       L_32bd
        cmp      eax, dword ptr [g_data_004ffd44]
        jge      L_32bd
        mov      edx, dword ptr [g_data_00f70f60]
        add      ecx, eax
        mov      dword ptr [g_data_00f70fdc], edx
        mov      edx, dword ptr [g_data_00f70f58]
        test     eax, eax
        mov      dword ptr [g_data_00f70fd8], ebx
        mov      dword ptr [g_data_00f70fd4], edx
        mov      dword ptr [g_data_00f70f78], ecx
        jge      L_31c2
        mov      edx, eax
        mov      esi, ebx
        imul     edx, dword ptr [g_data_00f4d030]
        sub      esi, edx
        mov      edx, eax
        imul     edx, dword ptr [g_data_00f4d034]
        imul     eax, dword ptr [g_data_00f4d02c]
        mov      dword ptr [g_data_00f70fd8], esi
        mov      esi, dword ptr [g_data_00f70f60]
        sub      esi, edx
        mov      edx, dword ptr [g_data_00f70f58]
        sub      edx, eax
        mov      dword ptr [g_data_00f70fdc], esi
        mov      esi, dword ptr [g_data_00f70fc8]
        mov      dword ptr [g_data_00f70fd4], edx
        xor      eax, eax
    L_31c2:
        mov      edx, dword ptr [g_data_00f4d044]
        lea      edx, [edx + eax*2]
        mov      dword ptr [g_data_00f4d040], edx
        mov      edx, dword ptr [g_data_004ffd44]
        cmp      ecx, edx
        jle      L_31e3
        mov      ecx, edx
        mov      dword ptr [g_data_00f70f78], ecx
    L_31e3:
        sub      ecx, eax
        test     ecx, ecx
        mov      dword ptr [g_data_00f70f70], ecx
        jle      L_32bd
        push     ebp
        mov      ebx, dword ptr [g_data_00f4d030]
        shl      ebx, 0x10
        mov      ecx, dword ptr [g_data_00f70fd8]
        shl      ecx, 0x10
        mov      eax, dword ptr [g_data_00f4d034]
        shr      eax, 0x10
        mov      ch, al
        mov      eax, dword ptr [g_data_00f4d030]
        shr      eax, 0x10
        mov      cl, al
        mov      edx, dword ptr [g_data_00f85b58]
        shr      edx, 1
        mov      eax, dword ptr [g_data_00f70fdc]
        shr      eax, 0x10
        mov      dh, al
        mov      eax, dword ptr [g_data_00f70fd8]
        shr      eax, 0x10
        mov      dl, al
        mov      ebp, dword ptr [g_data_00f4d034]
        shl      ebp, 0x10
        mov      edi, dword ptr [g_data_00f4d040]
        mov      esi, dword ptr [g_data_00f70fdc]
        shl      esi, 0x10
        mov      eax, dword ptr [g_data_00f70f70]
        mov      si, ax
        mov      eax, dword ptr [g_data_00f4d02c]
        sar      eax, 4
        mov      dword ptr [g_data_00f70fe0], eax
        mov      eax, dword ptr [g_data_00f70fd4]
        shr      eax, 3
        add      eax, dword ptr [g_data_00f4d028]
        shr      eax, 1
    L_3273:
        mov      bx, ax
        mov      ax, word ptr [edx*2]
        test     ax, ax
        je       L_328e
        mov      ax, word ptr [eax*2]
        mov      word ptr [edi], ax
    L_328e:
        mov      ax, bx
        mov      bx, 0
        add      esi, ebp
        adc      dh, ch
        add      ecx, ebx
        adc      dl, cl
        add      eax, dword ptr [g_data_00f70fe0]
        add      edi, 2
        dec      si
        jg       L_3273
        pop      ebp
        mov      edi, dword ptr [g_data_00f70f54]
        mov      ebx, dword ptr [g_data_00f70f5c]
        mov      esi, dword ptr [g_data_00f70fc8]
    L_32bd:
        mov      ecx, dword ptr [g_data_00f85b54]
        mov      edx, dword ptr [g_data_00f4d044]
        add      edx, ecx
        mov      ecx, dword ptr [g_data_00f70f64]
        mov      dword ptr [g_data_00f4d044], edx
        mov      edx, dword ptr [g_data_00f4d020]
        add      ecx, edx
        mov      edx, dword ptr [g_data_00f4d024]
        mov      eax, dword ptr [g_data_00f712f8]
        mov      dword ptr [g_data_00f70f64], ecx
        mov      ecx, dword ptr [g_data_00f4d018]
        add      esi, edx
        mov      edx, dword ptr [g_data_00f70f60]
        add      ebx, ecx
        mov      ecx, dword ptr [g_data_00f4d01c]
        dec      eax
        add      edx, ecx
        mov      ecx, dword ptr [g_data_00f70f58]
        mov      dword ptr [g_data_00f70f60], edx
        mov      edx, dword ptr [g_data_00f4d014]
        add      ecx, edx
        mov      dword ptr [g_data_00f712f8], eax
        test     eax, eax
        mov      dword ptr [g_data_00f70fc8], esi
        mov      dword ptr [g_data_00f70f5c], ebx
        mov      dword ptr [g_data_00f70f58], ecx
        jg       L_3113
    L_333c:
        mov      eax, dword ptr [g_data_00f712fc]
        mov      ecx, dword ptr [g_data_00f70f6c]
        cmp      ecx, eax
        jl       L_2ec7
    L_334f:
        pop      edi
        pop      esi
        pop      ebx
        mov      esp, ebp
        pop      ebp
        ret
    }
}
