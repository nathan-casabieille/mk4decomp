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

extern unsigned int g_data_004f6238;
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542048;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_007af92c;
extern unsigned int g_data_007af958;
extern unsigned int g_data_007af95a;
extern unsigned int g_data_007af95c;
extern unsigned int g_data_007af95e;
extern unsigned int g_data_007af960;
extern unsigned int g_data_007af962;
extern unsigned int g_data_007af964;
extern unsigned int g_data_007af966;
extern unsigned int g_data_007af968;
extern unsigned int g_data_007af984;
extern unsigned int g_data_007af988;
extern unsigned int g_data_007af98c;
extern unsigned int g_data_007af9a4;
extern unsigned int g_data_007af9a8;
extern unsigned int g_data_007af9ac;
extern unsigned int g_data_007af9b0;
extern unsigned int g_data_007af9b4;
extern unsigned int g_data_007af9b6;
extern unsigned int g_data_007af9b8;
extern unsigned int g_data_007af9ba;
extern unsigned int g_data_007af9bc;
extern unsigned int g_data_007af9be;
extern unsigned int g_data_00ab4398;
extern unsigned int g_data_00ab439c;
extern unsigned int g_data_00ab43a0;
extern unsigned int g_data_00ab4d9c;
extern unsigned int g_data_00ab4e20;
extern unsigned int g_data_00ab4e60;
extern void CopyArgs16ToGlobals_004b2ff0(void);
extern void Helper_DrawCursor(void);
extern void MaxOfThree_004b3d90(void);
extern void ProjectTwoVertices(void);
extern void ProjectVertex(void);

__declspec(naked) void BillboardSheetDualEmit_004bbda0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_007af92c]
        sub      esp, 0x58
        test     eax, eax
        push     ebx
        push     ebp
        push     esi
        push     edi
        jne      L_c45f
        mov      eax, dword ptr [g_data_00ab4e60]
        cmp      eax, 0x10
        jl       L_bdca
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_bdcc
    L_bdca:
        xor      eax, eax
    L_bdcc:
        mov      ecx, eax
        shl      ecx, 5
        or       ecx, eax
        shl      ecx, 5
        or       eax, ecx
        mov      cl, byte ptr [g_data_0054205c]
        test     cl, 0x60
        je       L_be12
        mov      edx, dword ptr [g_data_00ab4398]
        mov      ecx, dword ptr [g_data_00ab439c]
        sar      edx, 0x10
        mov      dword ptr [g_data_007af9a4], edx
        mov      edx, dword ptr [g_data_00ab43a0]
        sar      ecx, 0x10
        sar      edx, 7
        mov      dword ptr [g_data_007af9a8], ecx
        mov      dword ptr [g_data_007af9ac], edx
        jmp      L_be3f
    L_be12:
        mov      ecx, dword ptr [g_data_00ab4398]
        mov      edx, dword ptr [g_data_00ab439c]
        sar      ecx, 7
        mov      dword ptr [g_data_007af9a4], ecx
        mov      ecx, dword ptr [g_data_00ab43a0]
        sar      edx, 7
        sar      ecx, 7
        mov      dword ptr [g_data_007af9a8], edx
        mov      dword ptr [g_data_007af9ac], ecx
    L_be3f:
        mov      ecx, dword ptr [g_data_00542048]
        mov      esi, dword ptr [esp + 0x6c]
        mov      ecx, dword ptr [ecx + 4]
        mov      bp, word ptr [esi + 0xa]
        mov      dword ptr [esp + 0x18], ebp
        mov      edx, dword ptr [ecx + 4]
        mov      word ptr [esp + 0x5c], ax
        mov      word ptr [esp + 0x3c], ax
        mov      al, byte ptr [esi + 1]
        and      eax, 3
        lea      edi, [edx + ecx + 8]
        xor      edx, edx
        mov      cl, byte ptr [eax + g_data_004f6238]
        mov      dl, byte ptr [esi + 2]
        and      cl, 3
        movsx    ax, cl
        shl      eax, 7
        mov      word ptr [esp + 0x62], ax
        mov      ecx, dword ptr [esp + 0x62]
        mov      bl, byte ptr [esp + 0x62]
        and      ecx, 0x180
        mov      word ptr [esp + 0x42], cx
        mov      dl, byte ptr [edi + edx*4 + 2]
        xor      dl, bl
        mov      bl, byte ptr [esp + 0x42]
        and      edx, 0xf
        mov      di, word ptr [esi + 8]
        xor      ax, dx
        mov      dl, byte ptr [esi + 0xe]
        mov      word ptr [esp + 0x62], ax
        mov      al, byte ptr [esp + 0x62]
        xor      al, bl
        mov      bl, byte ptr [esi + 0xf]
        and      eax, 0xf
        xor      cx, ax
        mov      al, byte ptr [esi + 0xc]
        mov      word ptr [esp + 0x42], cx
        mov      cl, byte ptr [esi + 0xd]
        mov      byte ptr [esp + 0x35], cl
        mov      byte ptr [esp + 0x37], cl
        add      bl, cl
        mov      byte ptr [esp + 0x55], cl
        mov      cx, di
        add      dl, al
        mov      word ptr [g_data_007af958], di
        mov      word ptr [g_data_007af95e], bp
        mov      word ptr [g_data_007af964], 0
        add      cx, word ptr [esi + 4]
        mov      byte ptr [esp + 0x36], dl
        mov      byte ptr [esp + 0x38], dl
        mov      byte ptr [esp + 0x56], dl
        mov      dx, di
        mov      word ptr [g_data_007af95a], cx
        mov      word ptr [g_data_007af960], bp
        mov      word ptr [g_data_007af966], 0
        add      dx, word ptr [esi + 4]
        mov      byte ptr [esp + 0x34], al
        mov      byte ptr [esp + 0x54], al
        mov      byte ptr [esp + 0x58], al
        mov      ax, bp
        mov      word ptr [g_data_007af95c], dx
        add      ax, word ptr [esi + 6]
        mov      byte ptr [esp + 0x39], bl
        mov      byte ptr [esp + 0x57], bl
        mov      byte ptr [esp + 0x59], bl
        mov      word ptr [g_data_007af962], ax
        mov      word ptr [g_data_007af968], 0
        call     ProjectTwoVertices
        mov      ax, word ptr [g_data_00ab4e20]
        test     ax, ax
        jne      L_bf84
        call     MaxOfThree_004b3d90
        mov      ecx, dword ptr [g_data_00ab4d9c]
        movsx    eax, ax
        cdq
        sub      eax, edx
        sar      eax, 1
        shl      ecx, 5
        add      ax, cx
    L_bf84:
        mov      word ptr [esp + 0x3a], ax
        mov      word ptr [esp + 0x5a], ax
        test     byte ptr [g_data_00542084], 0x40
        jne      L_c15a
        movsx    eax, word ptr [g_data_007af9b4]
        movsx    ecx, word ptr [g_data_007af9b6]
        movsx    edx, word ptr [g_data_007af9be]
        movsx    ebx, word ptr [g_data_007af9b8]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_data_007af9ba]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_data_007af9bc]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_data_007af9b4]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_data_007af9b8]
        mov      dword ptr [esp + 0x28], ecx
        mov      ecx, dword ptr [esp + 0x42]
        mov      dword ptr [esp + 0x2c], edx
        setle    al
        mov      dword ptr [g_data_007af9b0], eax
        mov      dl, byte ptr [g_data_007af9b0]
        mov      eax, dword ptr [g_data_007af9bc]
        and      edx, 1
        mov      dword ptr [esp + 0x30], eax
        mov      eax, dword ptr [g_data_007af984]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x42], cx
        jle      L_c15a
        mov      eax, dword ptr [g_data_007af988]
        test     eax, eax
        jle      L_c15a
        mov      eax, dword ptr [g_data_007af98c]
        test     eax, eax
        jle      L_c15a
        mov      ax, bp
        push     0
        add      ax, word ptr [esi + 6]
        push     eax
        push     edi
        call     CopyArgs16ToGlobals_004b2ff0
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_data_007af9b4]
        movsx    ecx, word ptr [g_data_007af9b6]
        movsx    edx, word ptr [g_data_007af9be]
        movsx    ebx, word ptr [g_data_007af9b8]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_data_007af9ba]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_data_007af9bc]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_data_007af9b4]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_data_007af9b8]
        mov      dword ptr [esp + 0x48], ecx
        mov      ecx, dword ptr [esp + 0x62]
        mov      dword ptr [esp + 0x4c], edx
        setle    al
        mov      dword ptr [g_data_007af9b0], eax
        mov      dl, byte ptr [g_data_007af9b0]
        mov      eax, dword ptr [g_data_007af9bc]
        and      edx, 1
        mov      dword ptr [esp + 0x50], eax
        mov      eax, dword ptr [g_data_007af984]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x62], cx
        jle      L_c15a
        mov      eax, dword ptr [g_data_007af988]
        test     eax, eax
        jle      L_c15a
        mov      eax, dword ptr [g_data_007af98c]
        test     eax, eax
        jle      L_c15a
        mov      ax, word ptr [esp + 0x2a]
        cmp      ax, word ptr [esp + 0x2e]
        jne      L_c140
        mov      cx, word ptr [esp + 0x28]
        cmp      cx, word ptr [esp + 0x50]
        jne      L_c140
        mov      dx, word ptr [esp + 0x30]
        cmp      dx, word ptr [esp + 0x2c]
        jne      L_c140
        mov      ax, word ptr [esp + 0x32]
        cmp      ax, word ptr [esp + 0x52]
        jne      L_c140
        or       byte ptr [esp + 0x42], 0x20
        lea      ecx, [esp + 0x28]
        push     ecx
        call     Helper_DrawCursor
        add      esp, 4
        /* MASM picks 6-byte 66 83 /4 sign-extended form for 0xffdf; orig uses 7-byte 66 81 /4 - force via _emit */
        _emit 0x66
        _emit 0x81
        _emit 0x64
        _emit 0x24
        _emit 0x42
        _emit 0xdf
        _emit 0xff
        jmp      L_c15a
    L_c140:
        lea      edx, [esp + 0x28]
        push     edx
        call     Helper_DrawCursor
        add      esp, 4
        lea      eax, [esp + 0x48]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_c15a:
        mov      ecx, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [ecx*4 + 0x2c]
        test     ecx, ecx
        mov      dword ptr [g_data_00542044], ecx
        je       L_c45f
        mov      edx, dword ptr [g_data_007af9a4]
        mov      eax, dword ptr [g_data_007af9a8]
        mov      dword ptr [esp + 0x1c], edx
        mov      edx, dword ptr [g_data_007af9ac]
        mov      dword ptr [esp + 0x20], eax
        mov      dword ptr [esp + 0x24], edx
    L_c192:
        mov      edx, dword ptr [ecx*4 + 4]
        mov      eax, dword ptr [ecx*4 + 8]
        mov      ecx, dword ptr [ecx*4 + 0xc]
        mov      ebx, dword ptr [g_data_00542084]
        sar      edx, 7
        sar      eax, 7
        sar      ecx, 7
        test     bh, 0x40
        jne      L_c261
        mov      ebx, dword ptr [esp + 0x70]
        mov      dword ptr [esp + 0x6c], edx
        mov      dword ptr [esp + 0x10], eax
        movsx    ebp, word ptr [ebx*4 + 2]
        movsx    ebx, word ptr [ebx*4]
        imul     ebp, eax
        imul     ebx, edx
        mov      edx, dword ptr [esp + 0x70]
        add      ebp, ebx
        movsx    ebx, word ptr [edx*4 + 4]
        imul     ebx, ecx
        add      ebp, ebx
        movsx    ebx, word ptr [edx*4 + 6]
        imul     ebx, dword ptr [esp + 0x6c]
        sar      ebp, 0xc
        mov      dword ptr [esp + 0x14], ebp
        movsx    ebp, word ptr [edx*4 + 0xa]
        imul     ebp, ecx
        add      ebx, ebp
        movsx    ebp, word ptr [edx*4 + 8]
        imul     ebp, eax
        add      ebx, ebp
        mov      ebp, dword ptr [esp + 0x18]
        sar      ebx, 0xc
        mov      eax, ebx
        movsx    ebx, word ptr [edx*4 + 0xe]
        movsx    edx, word ptr [edx*4 + 0xc]
        imul     ebx, dword ptr [esp + 0x10]
        imul     edx, dword ptr [esp + 0x6c]
        add      ebx, edx
        mov      edx, dword ptr [esp + 0x70]
        movsx    edx, word ptr [edx*4 + 0x10]
        imul     edx, ecx
        add      ebx, edx
        mov      edx, dword ptr [esp + 0x14]
        sar      ebx, 0xc
        mov      ecx, ebx
    L_c261:
        mov      ebx, dword ptr [esp + 0x1c]
        mov      word ptr [g_data_007af958], di
        add      edx, ebx
        mov      word ptr [g_data_007af95e], bp
        mov      dword ptr [g_data_007af9a4], edx
        mov      edx, dword ptr [esp + 0x20]
        add      eax, edx
        mov      dx, di
        mov      dword ptr [g_data_007af9a8], eax
        mov      eax, dword ptr [esp + 0x24]
        add      ecx, eax
        xor      eax, eax
        mov      dword ptr [g_data_007af9ac], ecx
        mov      cx, di
        mov      word ptr [g_data_007af964], ax
        add      cx, word ptr [esi + 4]
        mov      word ptr [g_data_007af960], bp
        mov      word ptr [g_data_007af966], ax
        mov      word ptr [g_data_007af95a], cx
        add      dx, word ptr [esi + 4]
        mov      cx, bp
        mov      word ptr [g_data_007af95c], dx
        add      cx, word ptr [esi + 6]
        mov      word ptr [g_data_007af968], ax
        mov      word ptr [g_data_007af962], cx
        call     ProjectTwoVertices
        movsx    eax, word ptr [g_data_007af9b4]
        movsx    ecx, word ptr [g_data_007af9b6]
        movsx    edx, word ptr [g_data_007af9be]
        movsx    ebx, word ptr [g_data_007af9b8]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_data_007af9ba]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_data_007af9bc]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_data_007af9b4]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_data_007af9b8]
        mov      dword ptr [esp + 0x28], ecx
        mov      ecx, dword ptr [esp + 0x42]
        mov      dword ptr [esp + 0x2c], edx
        setle    al
        mov      dword ptr [g_data_007af9b0], eax
        mov      dl, byte ptr [g_data_007af9b0]
        mov      eax, dword ptr [g_data_007af9bc]
        and      edx, 1
        mov      dword ptr [esp + 0x30], eax
        mov      eax, dword ptr [g_data_007af984]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x42], cx
        jle      L_c384
        mov      eax, dword ptr [g_data_007af988]
        test     eax, eax
        jle      L_c384
        mov      eax, dword ptr [g_data_007af98c]
        test     eax, eax
        jle      L_c384
        lea      eax, [esp + 0x28]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_c384:
        mov      cx, bp
        push     0
        add      cx, word ptr [esi + 6]
        push     ecx
        push     edi
        call     CopyArgs16ToGlobals_004b2ff0
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_data_007af9b4]
        movsx    ecx, word ptr [g_data_007af9b6]
        movsx    edx, word ptr [g_data_007af9be]
        movsx    ebx, word ptr [g_data_007af9b8]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_data_007af9ba]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_data_007af9bc]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_data_007af9b4]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_data_007af9b8]
        mov      dword ptr [esp + 0x48], ecx
        mov      ecx, dword ptr [esp + 0x62]
        mov      dword ptr [esp + 0x4c], edx
        setle    al
        mov      dword ptr [g_data_007af9b0], eax
        mov      dl, byte ptr [g_data_007af9b0]
        mov      eax, dword ptr [g_data_007af9bc]
        and      edx, 1
        mov      dword ptr [esp + 0x50], eax
        mov      eax, dword ptr [g_data_007af984]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x62], cx
        jle      L_c444
        mov      eax, dword ptr [g_data_007af988]
        test     eax, eax
        jle      L_c444
        mov      eax, dword ptr [g_data_007af98c]
        test     eax, eax
        jle      L_c444
        lea      eax, [esp + 0x48]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_c444:
        mov      ecx, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [ecx*4]
        test     ecx, ecx
        mov      dword ptr [g_data_00542044], ecx
        jne      L_c192
    L_c45f:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x58
        ret
    }
}
