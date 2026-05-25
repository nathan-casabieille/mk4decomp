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
extern unsigned int g_audioBankSel_00537f94;
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
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern void Renderer2_FlushBatch_D3D(void);
extern void GlidePolyClip_004ae560(void);
extern unsigned int g_const_004d2964;
extern unsigned int g_const_004d2968;
extern unsigned int g_const_004d296c;
extern unsigned int g_data_004f4790;
extern unsigned int g_data_0058c7d0;
extern unsigned int g_data_0058c7e0;
extern unsigned int g_data_0058c7e4;
extern unsigned int g_data_0058c7ec;
extern unsigned int g_data_0058c7f0;
extern unsigned int g_data_0058c7f4;
extern unsigned int g_data_0058c7f8;
extern unsigned int g_data_0058c7fc;
extern unsigned int g_data_0058c800;
extern unsigned int g_data_00543f88;
extern unsigned int g_data_00543f8c;
extern unsigned int g_data_00543f90;
extern unsigned int g_data_00543f94;
extern unsigned int g_data_00543f98;
extern unsigned int g_data_00543f9c;
extern unsigned int g_data_00543fa0;
extern unsigned int g_data_00543fa4;
extern unsigned int g_data_00543fa8;
extern unsigned int g_data_00543fac;
extern unsigned int g_data_00543fb0;
extern unsigned int g_data_00543fb4;
extern unsigned int g_data_00543fb8;
extern unsigned int g_data_00543fbc;
extern unsigned int g_data_00543fc0;
extern unsigned int g_data_00543fc4;
extern unsigned int g_data_00543fc8;
extern unsigned int g_data_00543fcc;
extern unsigned int g_data_00543fd0;
extern unsigned int g_data_00543fd4;
extern unsigned int g_data_00543fd8;
extern unsigned int g_data_00544158;
extern unsigned int g_data_00544308;
extern unsigned int g_data_00544708;
extern unsigned int g_data_00544718;
extern unsigned int g_data_0054471c;
extern unsigned int g_data_00544720;
extern unsigned int g_data_00544724;
extern unsigned int g_data_00544728;
extern unsigned int g_data_00544730;
extern unsigned int g_data_00544734;
extern unsigned int g_data_00544738;
extern unsigned int g_data_0054473c;
extern unsigned int g_data_00544740;
extern unsigned int g_data_00544744;
extern unsigned int g_data_00544748;
extern unsigned int g_data_00544750;
extern unsigned int g_data_00544754;
extern unsigned int g_data_00544758;
extern unsigned int g_data_0054475c;
extern unsigned int g_data_00544760;
extern unsigned int g_data_00544764;
extern unsigned int g_data_00544768;
extern unsigned int g_data_00544770;
extern unsigned int g_data_00544774;

extern unsigned int g_data_0058c768;
extern unsigned int g_data_0058c7c0;
extern unsigned int g_data_0058c7dc;
extern void DoubleToInt64_004c57d0(void);

__declspec(naked) void GlideTriBatchEmit_004adca0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_0058c7e0]
        push     ebx
        push     ebp
        push     esi
        test     eax, eax
        push     edi
        je       L_e55b
        mov      eax, dword ptr [g_data_0058c7e4]
        test     eax, eax
        je       L_e55b
        mov      eax, dword ptr [g_data_0058c7ec]
        test     eax, eax
        jne      L_e55b
        cmp      byte ptr [esp + 0x14], 0x10
        jb       L_dcd7
        mov      byte ptr [esp + 0x14], 0
    L_dcd7:
        mov      eax, dword ptr [g_data_0058c7f0]
        mov      ebx, dword ptr [esp + 0x18]
        add      eax, 7
        cmp      eax, 0xc00
        jge      L_dd03
        cmp      bl, byte ptr [g_data_0058c7d0]
        jne      L_dd03
        mov      cl, byte ptr [esp + 0x14]
        mov      al, byte ptr [g_data_004f4790]
        cmp      cl, al
        je       L_de14
    L_dd03:
        call     Renderer2_FlushBatch_D3D
        mov      dl, byte ptr [esp + 0x14]
        mov      al, byte ptr [g_data_004f4790]
        cmp      dl, al
        mov      eax, dword ptr [g_data_0058c7c0]
        je       L_dd4c
        test     eax, eax
        je       L_dd42
        mov      edx, dword ptr [esp + 0x14]
        mov      ecx, dword ptr [eax]
        and      edx, 0xff
        mov      edx, dword ptr [edx*4 + g_data_0058c768]
        push     edx
        push     1
        push     eax
        call     dword ptr [ecx + 0x5c]
        mov      dword ptr [g_data_0058c7dc], eax
        mov      eax, dword ptr [g_data_0058c7c0]
    L_dd42:
        mov      cl, byte ptr [esp + 0x14]
        mov      byte ptr [g_data_004f4790], cl
    L_dd4c:
        mov      cl, byte ptr [g_data_0058c7d0]
        cmp      bl, cl
        je       L_de14
        test     bl, bl
        jne      L_dd71
        test     eax, eax
        je       L_de0e
        mov      edx, dword ptr [eax]
        push     0
        push     0x1b
        jmp      L_de05
    L_dd71:
        cmp      bl, 0xff
        jne      L_ddbe
        test     cl, cl
        jne      L_dd96
        test     eax, eax
        je       L_de0e
        mov      ecx, dword ptr [eax]
        push     1
        push     0x1b
        push     eax
        call     dword ptr [ecx + 0x5c]
        mov      dword ptr [g_data_0058c7dc], eax
        mov      eax, dword ptr [g_data_0058c7c0]
    L_dd96:
        test     eax, eax
        je       L_de0e
        mov      edx, dword ptr [eax]
        push     2
        push     0x13
        push     eax
        call     dword ptr [edx + 0x5c]
        mov      dword ptr [g_data_0058c7dc], eax
        mov      eax, dword ptr [g_data_0058c7c0]
        test     eax, eax
        je       L_de0e
        mov      ecx, dword ptr [eax]
        push     2
        push     0x14
        push     eax
        call     dword ptr [ecx + 0x5c]
        jmp      L_de09
    L_ddbe:
        test     cl, cl
        je       L_ddcb
        cmp      cl, 0xff
        jne      L_de0e
        test     cl, cl
        jne      L_dde3
    L_ddcb:
        test     eax, eax
        je       L_de0e
        mov      edx, dword ptr [eax]
        push     1
        push     0x1b
        push     eax
        call     dword ptr [edx + 0x5c]
        mov      dword ptr [g_data_0058c7dc], eax
        mov      eax, dword ptr [g_data_0058c7c0]
    L_dde3:
        test     eax, eax
        je       L_de0e
        mov      ecx, dword ptr [eax]
        push     6
        push     0x13
        push     eax
        call     dword ptr [ecx + 0x5c]
        mov      dword ptr [g_data_0058c7dc], eax
        mov      eax, dword ptr [g_data_0058c7c0]
        test     eax, eax
        je       L_de0e
        mov      edx, dword ptr [eax]
        push     5
        push     0x14
    L_de05:
        push     eax
        call     dword ptr [edx + 0x5c]
    L_de09:
        mov      dword ptr [g_data_0058c7dc], eax
    L_de0e:
        mov      byte ptr [g_data_0058c7d0], bl
    L_de14:
        fld      dword ptr [esp + 0x1c]
        fcomp    dword ptr [g_const_004d2964]
        xor      di, di
        xor      si, si
        xor      dx, dx
        xor      cx, cx
        mov      word ptr [g_data_0058c800], di
        mov      word ptr [g_data_0058c7fc], si
        fnstsw   ax
        mov      word ptr [g_data_0058c7f8], dx
        mov      word ptr [g_data_0058c7f4], cx
        test     ah, 1
        je       L_de5a
        mov      di, 1
        mov      word ptr [g_data_0058c800], di
        jmp      L_de76
    L_de5a:
        fld      dword ptr [esp + 0x1c]
        fcomp    dword ptr [g_const_004d2968]
        fnstsw   ax
        test     ah, 0x41
        jne      L_de76
        mov      dx, 1
        mov      word ptr [g_data_0058c7f8], dx
    L_de76:
        fld      dword ptr [esp + 0x20]
        fcomp    dword ptr [g_const_004d2964]
        fnstsw   ax
        test     ah, 1
        je       L_de94
        mov      cx, 1
        mov      word ptr [g_data_0058c7f4], cx
        jmp      L_deb0
    L_de94:
        fld      dword ptr [esp + 0x20]
        fcomp    dword ptr [g_const_004d296c]
        fnstsw   ax
        test     ah, 0x41
        jne      L_deb0
        mov      si, 1
        mov      word ptr [g_data_0058c7fc], si
    L_deb0:
        fld      dword ptr [esp + 0x30]
        fcomp    dword ptr [g_const_004d2964]
        fnstsw   ax
        test     ah, 1
        je       L_decc
        inc      di
        mov      word ptr [g_data_0058c800], di
        jmp      L_dee6
    L_decc:
        fld      dword ptr [esp + 0x30]
        fcomp    dword ptr [g_const_004d2968]
        fnstsw   ax
        test     ah, 0x41
        jne      L_dee6
        inc      dx
        mov      word ptr [g_data_0058c7f8], dx
    L_dee6:
        fld      dword ptr [esp + 0x34]
        fcomp    dword ptr [g_const_004d2964]
        fnstsw   ax
        test     ah, 1
        je       L_df02
        inc      cx
        mov      word ptr [g_data_0058c7f4], cx
        jmp      L_df1c
    L_df02:
        fld      dword ptr [esp + 0x34]
        fcomp    dword ptr [g_const_004d296c]
        fnstsw   ax
        test     ah, 0x41
        jne      L_df1c
        inc      si
        mov      word ptr [g_data_0058c7fc], si
    L_df1c:
        fld      dword ptr [esp + 0x44]
        fcomp    dword ptr [g_const_004d2964]
        fnstsw   ax
        test     ah, 1
        je       L_df38
        inc      di
        mov      word ptr [g_data_0058c800], di
        jmp      L_df52
    L_df38:
        fld      dword ptr [esp + 0x44]
        fcomp    dword ptr [g_const_004d2968]
        fnstsw   ax
        test     ah, 0x41
        jne      L_df52
        inc      dx
        mov      word ptr [g_data_0058c7f8], dx
    L_df52:
        fld      dword ptr [esp + 0x48]
        fcomp    dword ptr [g_const_004d2964]
        fnstsw   ax
        test     ah, 1
        je       L_df6e
        inc      cx
        mov      word ptr [g_data_0058c7f4], cx
        jmp      L_df88
    L_df6e:
        fld      dword ptr [esp + 0x48]
        fcomp    dword ptr [g_const_004d296c]
        fnstsw   ax
        test     ah, 0x41
        jne      L_df88
        inc      si
        mov      word ptr [g_data_0058c7fc], si
    L_df88:
        cmp      cx, 3
        je       L_e55b
        cmp      dx, 3
        je       L_e55b
        cmp      si, 3
        je       L_e55b
        cmp      di, 3
        je       L_e55b
        mov      eax, dword ptr [g_data_0058c7fc]
        mov      ecx, dword ptr [g_data_0058c800]
        mov      edx, dword ptr [g_data_0058c7f4]
        and      eax, 0xffff
        and      ecx, 0xffff
        and      edx, 0xffff
        add      eax, ecx
        mov      ecx, dword ptr [g_data_0058c7f8]
        add      eax, edx
        and      ecx, 0xffff
        add      eax, ecx
        jne      L_e1da
        mov      eax, dword ptr [g_data_0058c7f0]
        mov      edx, dword ptr [esp + 0x1c]
        mov      ecx, dword ptr [esp + 0x20]
        and      ebx, 0xff
        lea      eax, [eax + eax*2]
        mov      esi, ebx
        shl      eax, 5
        xor      ebx, ebx
        mov      edi, 0x3f800000
        mov      dword ptr [eax + g_data_00544718], edx
        mov      dword ptr [eax + g_data_0054471c], ecx
        movsx    ecx, word ptr [esp + 0x2c]
        mov      edx, ecx
        mov      ebp, ecx
        sar      edx, 7
        and      edx, 0xf8
        and      ecx, 0x1f
        sar      ebp, 2
        mov      bl, byte ptr [edx + g_data_00544158]
        and      ebp, 0xf8
        shl      esi, 8
        or       ebx, esi
        xor      edx, edx
        mov      dl, byte ptr [ebp + g_data_00544158]
        mov      dword ptr [eax + g_data_00544724], edi
        shl      ebx, 8
        or       ebx, edx
        xor      edx, edx
        mov      dl, byte ptr [ecx*8 + g_data_00544158]
        mov      ecx, dword ptr [esp + 0x24]
        shl      ebx, 8
        and      ecx, 0xff
        or       ebx, edx
        mov      dword ptr [eax + g_data_00544720], edi
        mov      dword ptr [eax + g_data_00544728], ebx
        mov      edx, dword ptr [ecx*4 + g_data_00544308]
        mov      ecx, dword ptr [esp + 0x28]
        and      ecx, 0xff
        mov      dword ptr [eax + g_data_00544730], edx
        xor      ebx, ebx
        mov      edx, dword ptr [ecx*4 + g_data_00544308]
        mov      ecx, dword ptr [esp + 0x30]
        mov      dword ptr [eax + g_data_00544734], edx
        mov      edx, dword ptr [esp + 0x34]
        mov      dword ptr [eax + g_data_00544738], ecx
        mov      dword ptr [eax + g_data_0054473c], edx
        movsx    ecx, word ptr [esp + 0x40]
        mov      edx, ecx
        mov      ebp, ecx
        sar      edx, 7
        and      edx, 0xf8
        and      ecx, 0x1f
        sar      ebp, 2
        mov      bl, byte ptr [edx + g_data_00544158]
        and      ebp, 0xf8
        or       ebx, esi
        xor      edx, edx
        mov      dl, byte ptr [ebp + g_data_00544158]
        mov      dword ptr [eax + g_data_00544744], edi
        shl      ebx, 8
        or       ebx, edx
        xor      edx, edx
        mov      dl, byte ptr [ecx*8 + g_data_00544158]
        mov      ecx, dword ptr [esp + 0x38]
        shl      ebx, 8
        and      ecx, 0xff
        or       ebx, edx
        mov      dword ptr [eax + g_data_00544740], edi
        mov      dword ptr [eax + g_data_00544748], ebx
        mov      edx, dword ptr [ecx*4 + g_data_00544308]
        mov      ecx, dword ptr [esp + 0x3c]
        and      ecx, 0xff
        mov      dword ptr [eax + g_data_00544750], edx
        mov      edx, dword ptr [ecx*4 + g_data_00544308]
        mov      ecx, dword ptr [esp + 0x44]
        mov      dword ptr [eax + g_data_00544754], edx
        mov      edx, dword ptr [esp + 0x48]
        mov      dword ptr [eax + g_data_00544758], ecx
        mov      dword ptr [eax + g_data_0054475c], edx
        mov      dword ptr [eax + g_data_00544764], edi
        mov      dword ptr [eax + g_data_00544760], edi
        movsx    ecx, word ptr [esp + 0x54]
        mov      edx, ecx
        xor      ebx, ebx
        sar      edx, 7
        and      edx, 0xf8
        mov      bl, byte ptr [edx + g_data_00544158]
        xor      edx, edx
        or       ebx, esi
        mov      esi, ecx
        sar      esi, 2
        and      esi, 0xf8
        and      ecx, 0x1f
        shl      ebx, 8
        mov      dl, byte ptr [esi + g_data_00544158]
        or       ebx, edx
        xor      edx, edx
        mov      dl, byte ptr [ecx*8 + g_data_00544158]
        mov      ecx, dword ptr [esp + 0x4c]
        shl      ebx, 8
        and      ecx, 0xff
        or       ebx, edx
        mov      dword ptr [eax + g_data_00544768], ebx
        mov      edx, dword ptr [ecx*4 + g_data_00544308]
        mov      ecx, dword ptr [esp + 0x50]
        and      ecx, 0xff
        mov      dword ptr [eax + g_data_00544770], edx
        mov      edx, dword ptr [ecx*4 + g_data_00544308]
        mov      dword ptr [eax + g_data_00544774], edx
        mov      eax, dword ptr [g_data_0058c7f0]
        inc      eax
        mov      dword ptr [g_data_0058c7f0], eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_e1da:
        mov      edx, dword ptr [esp + 0x24]
        mov      eax, dword ptr [esp + 0x1c]
        mov      ecx, dword ptr [esp + 0x20]
        and      edx, 0xff
        mov      dword ptr [g_data_00543f88], eax
        mov      eax, dword ptr [esp + 0x28]
        fld      dword ptr [edx*4 + g_data_00544308]
        and      eax, 0xff
        mov      dword ptr [g_data_00543f8c], ecx
        fstp     dword ptr [g_data_00543f90]
        fld      dword ptr [eax*4 + g_data_00544308]
        mov      eax, dword ptr [esp + 0x38]
        mov      ecx, dword ptr [esp + 0x30]
        fstp     dword ptr [g_data_00543f94]
        mov      edx, dword ptr [esp + 0x34]
        and      eax, 0xff
        mov      dword ptr [g_data_00543fa4], ecx
        mov      ecx, dword ptr [esp + 0x3c]
        fld      dword ptr [eax*4 + g_data_00544308]
        mov      eax, dword ptr [esp + 0x48]
        and      ecx, 0xff
        fstp     dword ptr [g_data_00543fac]
        fld      dword ptr [ecx*4 + g_data_00544308]
        mov      ecx, dword ptr [esp + 0x4c]
        mov      dword ptr [g_data_00543fa8], edx
        mov      edx, dword ptr [esp + 0x44]
        mov      dword ptr [g_data_00543fc4], eax
        movsx    eax, word ptr [esp + 0x2c]
        fstp     dword ptr [g_data_00543fb0]
        and      ecx, 0xff
        mov      dword ptr [g_data_00543fc0], edx
        mov      edx, dword ptr [esp + 0x50]
        fld      dword ptr [ecx*4 + g_data_00544308]
        mov      ecx, eax
        and      edx, 0xff
        fstp     dword ptr [g_data_00543fc8]
        fld      dword ptr [edx*4 + g_data_00544308]
        sar      ecx, 7
        and      ecx, 0xf8
        xor      edx, edx
        fstp     dword ptr [g_data_00543fcc]
        mov      dl, byte ptr [ecx + g_data_00544158]
        mov      ecx, eax
        sar      ecx, 2
        mov      dword ptr [esp + 0x2c], edx
        and      ecx, 0xf8
        fild     dword ptr [esp + 0x2c]
        xor      edx, edx
        and      eax, 0x1f
        mov      dl, byte ptr [ecx + g_data_00544158]
        xor      ecx, ecx
        mov      cl, byte ptr [eax*8 + g_data_00544158]
        mov      dword ptr [esp + 0x2c], edx
        movsx    eax, word ptr [esp + 0x40]
        fstp     dword ptr [g_data_00543f98]
        fild     dword ptr [esp + 0x2c]
        mov      edx, eax
        mov      dword ptr [esp + 0x2c], ecx
        sar      edx, 7
        fstp     dword ptr [g_data_00543f9c]
        fild     dword ptr [esp + 0x2c]
        and      edx, 0xf8
        xor      ecx, ecx
        mov      cl, byte ptr [edx + g_data_00544158]
        mov      edx, eax
        fstp     dword ptr [g_data_00543fa0]
        sar      edx, 2
        mov      dword ptr [esp + 0x2c], ecx
        and      edx, 0xf8
        fild     dword ptr [esp + 0x2c]
        xor      ecx, ecx
        and      eax, 0x1f
        mov      cl, byte ptr [edx + g_data_00544158]
        xor      edx, edx
        fstp     dword ptr [g_data_00543fb4]
        mov      dl, byte ptr [eax*8 + g_data_00544158]
        mov      dword ptr [esp + 0x2c], ecx
        fild     dword ptr [esp + 0x2c]
        mov      dword ptr [esp + 0x2c], edx
        fstp     dword ptr [g_data_00543fb8]
        fild     dword ptr [esp + 0x2c]
        movsx    eax, word ptr [esp + 0x54]
        fstp     dword ptr [g_data_00543fbc]
        mov      ecx, eax
        xor      edx, edx
        sar      ecx, 7
        and      ecx, 0xf8
        mov      dl, byte ptr [ecx + g_data_00544158]
        mov      ecx, eax
        sar      ecx, 2
        mov      dword ptr [esp + 0x2c], edx
        and      ecx, 0xf8
        fild     dword ptr [esp + 0x2c]
        xor      edx, edx
        and      eax, 0x1f
        mov      dl, byte ptr [ecx + g_data_00544158]
        xor      ecx, ecx
        fstp     dword ptr [g_data_00543fd0]
        mov      cl, byte ptr [eax*8 + g_data_00544158]
        mov      dword ptr [esp + 0x2c], edx
        fild     dword ptr [esp + 0x2c]
        mov      dword ptr [esp + 0x2c], ecx
        fstp     dword ptr [g_data_00543fd4]
        fild     dword ptr [esp + 0x2c]
        fstp     dword ptr [g_data_00543fd8]
        call     GlidePolyClip_004ae560
        cmp      eax, 3
        jl       L_e55b
        cmp      eax, 7
        jg       L_e55b
        mov      ecx, dword ptr [g_data_0058c7f0]
        lea      edx, [ecx + eax - 2]
        sub      eax, 3
        lea      esi, [ecx + ecx*2]
        mov      dword ptr [g_data_0058c7f0], edx
        js       L_e55b
        mov      ebp, dword ptr [g_data_00544708]
        mov      ecx, eax
        and      ebx, 0xff
        shl      esi, 5
        shl      ecx, 3
        shl      ebx, 8
        add      esi, OFFSET g_data_0054471c
        sub      ecx, eax
        inc      eax
        mov      dword ptr [esp + 0x2c], ebx
        lea      edi, [ebp + ecx*4 + 0x20]
        mov      dword ptr [esp + 0x40], eax
        jmp      L_e424
    L_e420:
        mov      ebx, dword ptr [esp + 0x2c]
    L_e424:
        mov      edx, dword ptr [ebp]
        mov      dword ptr [esi - 4], edx
        mov      eax, dword ptr [ebp + 4]
        mov      dword ptr [esi], eax
        mov      eax, 0x3f800000
        mov      dword ptr [esi + 8], eax
        mov      dword ptr [esi + 4], eax
        fld      dword ptr [ebp + 0x10]
        call     DoubleToInt64_004c57d0
        fld      dword ptr [ebp + 0x14]
        mov      dl, al
        and      edx, 0xff
        or       edx, ebx
        shl      edx, 8
        mov      dword ptr [esp + 0x54], edx
        call     DoubleToInt64_004c57d0
        mov      ebx, dword ptr [esp + 0x54]
        and      eax, 0xff
        fld      dword ptr [ebp + 0x18]
        or       ebx, eax
        shl      ebx, 8
        call     DoubleToInt64_004c57d0
        and      eax, 0xff
        or       ebx, eax
        mov      dword ptr [esi + 0xc], ebx
        mov      ecx, dword ptr [ebp + 8]
        mov      dword ptr [esi + 0x14], ecx
        mov      edx, dword ptr [ebp + 0xc]
        mov      dword ptr [esi + 0x18], edx
        mov      eax, dword ptr [edi - 4]
        mov      dword ptr [esi + 0x1c], eax
        mov      ecx, dword ptr [edi]
        mov      eax, 0x3f800000
        mov      dword ptr [esi + 0x20], ecx
        mov      dword ptr [esi + 0x28], eax
        mov      dword ptr [esi + 0x24], eax
        fld      dword ptr [edi + 0xc]
        call     DoubleToInt64_004c57d0
        mov      ecx, dword ptr [esp + 0x2c]
        mov      bl, al
        fld      dword ptr [edi + 0x10]
        and      ebx, 0xff
        or       ebx, ecx
        shl      ebx, 8
        call     DoubleToInt64_004c57d0
        fld      dword ptr [edi + 0x14]
        and      eax, 0xff
        or       ebx, eax
        shl      ebx, 8
        call     DoubleToInt64_004c57d0
        and      eax, 0xff
        or       ebx, eax
        mov      dword ptr [esi + 0x2c], ebx
        mov      edx, dword ptr [edi + 4]
        mov      dword ptr [esi + 0x34], edx
        mov      eax, dword ptr [edi + 8]
        mov      dword ptr [esi + 0x38], eax
        mov      ecx, dword ptr [edi + 0x18]
        mov      dword ptr [esi + 0x3c], ecx
        mov      edx, dword ptr [edi + 0x1c]
        mov      eax, 0x3f800000
        mov      dword ptr [esi + 0x40], edx
        mov      dword ptr [esi + 0x48], eax
        mov      dword ptr [esi + 0x44], eax
        fld      dword ptr [edi + 0x28]
        call     DoubleToInt64_004c57d0
        mov      ecx, dword ptr [esp + 0x2c]
        mov      bl, al
        fld      dword ptr [edi + 0x2c]
        and      ebx, 0xff
        or       ebx, ecx
        shl      ebx, 8
        call     DoubleToInt64_004c57d0
        fld      dword ptr [edi + 0x30]
        and      eax, 0xff
        or       ebx, eax
        shl      ebx, 8
        call     DoubleToInt64_004c57d0
        and      eax, 0xff
        or       ebx, eax
        mov      dword ptr [esi + 0x4c], ebx
        mov      eax, dword ptr [edi + 0x20]
        sub      edi, 0x1c
        mov      dword ptr [esi + 0x54], eax
        mov      ecx, dword ptr [edi + 0x40]
        mov      eax, dword ptr [esp + 0x40]
        mov      dword ptr [esi + 0x58], ecx
        add      esi, 0x60
        dec      eax
        mov      dword ptr [esp + 0x40], eax
        jne      L_e420
    L_e55b:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
