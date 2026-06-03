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

extern void Renderer2_FlushBatch_D3D(void);
extern void GlidePolyClip(void);
extern unsigned int g_const_004d2964;
extern unsigned int g_const_004d2968;
extern unsigned int g_const_004d296c;
extern unsigned int g_renderer2_d3dInitByte;
extern unsigned int g_renderer2_d3dByte;
extern int g_renderer2_active;
extern int g_renderer2_surface;
extern int g_renderer2_paused;
extern s32 g_renderer2_batchCount;
extern unsigned int g_glideTriBatch;
extern unsigned int g_glideTriBatchB;
extern unsigned int g_glideTriBatchC;
extern unsigned int g_glideTriBatchD;
extern unsigned int g_glideTriSave;
extern unsigned int g_glideDataArr_00543f8c;
extern unsigned int g_glideDataArr_00543f90;
extern unsigned int g_glideDataArr_00543f94;
extern unsigned int g_glideDataArr_00543f98;
extern unsigned int g_glideDataArr_00543f9c;
extern unsigned int g_glideDataArr_00543fa0;
extern unsigned int g_glideDataArr_00543fa4;
extern unsigned int g_glideDataArr_00543fa8;
extern unsigned int g_glideDataArr_00543fac;
extern unsigned int g_glideDataArr_00543fb0;
extern unsigned int g_glideDataArr_00543fb4;
extern unsigned int g_glideDataArr_00543fb8;
extern unsigned int g_glideDataArr_00543fbc;
extern unsigned int g_glideDataArr_00543fc0;
extern unsigned int g_glideDataArr_00543fc4;
extern unsigned int g_glideDataArr_00543fc8;
extern unsigned int g_glideDataArr_00543fcc;
extern unsigned int g_glideDataArr_00543fd0;
extern unsigned int g_glideDataArr_00543fd4;
extern unsigned int g_glideDataArr_00543fd8;
extern unsigned int g_palette;
extern f32 g_renderer2_lutTable[];
extern unsigned int g_glideTriVar;
extern u8 g_renderer2_vertexBatch[];
extern unsigned int g_glideTriArrayBase;
extern unsigned int g_glideVertArr_00544720;
extern unsigned int g_glideVertArr_00544724;
extern unsigned int g_glideVertArr_00544728;
extern unsigned int g_glideVertArr_00544730;
extern unsigned int g_glideVertArr_00544734;
extern unsigned int g_glideVertArr_00544738;
extern unsigned int g_glideVertArr_0054473c;
extern unsigned int g_glideVertArr_00544740;
extern unsigned int g_glideVertArr_00544744;
extern unsigned int g_glideVertArr_00544748;
extern unsigned int g_glideVertArr_00544750;
extern unsigned int g_glideVertArr_00544754;
extern unsigned int g_glideVertArr_00544758;
extern unsigned int g_glideVertArr6;
extern unsigned int g_glideVertArr5;
extern unsigned int g_glideVertArr4;
extern unsigned int g_glideVertArr3;
extern unsigned int g_glideVertArr2;
extern unsigned int g_glideVertArr_00544774;

extern u8 g_renderer2_buf1[];
extern unsigned int g_renderer2_obj;
extern int g_renderer2_present_rc;
extern void DoubleToInt64(void);

__declspec(naked) void GlideTriBatchEmit(void)
{
    __asm {
        mov      eax, dword ptr [g_renderer2_active]
        push     ebx
        push     ebp
        push     esi
        test     eax, eax
        push     edi
        je       L_e55b
        mov      eax, dword ptr [g_renderer2_surface]
        test     eax, eax
        je       L_e55b
        mov      eax, dword ptr [g_renderer2_paused]
        test     eax, eax
        jne      L_e55b
        cmp      byte ptr [esp + 0x14], 0x10
        jb       L_dcd7
        mov      byte ptr [esp + 0x14], 0
    L_dcd7:
        mov      eax, dword ptr [g_renderer2_batchCount]
        mov      ebx, dword ptr [esp + 0x18]
        add      eax, 7
        cmp      eax, 0xc00
        jge      L_dd03
        cmp      bl, byte ptr [g_renderer2_d3dByte]
        jne      L_dd03
        mov      cl, byte ptr [esp + 0x14]
        mov      al, byte ptr [g_renderer2_d3dInitByte]
        cmp      cl, al
        je       L_de14
    L_dd03:
        call     Renderer2_FlushBatch_D3D
        mov      dl, byte ptr [esp + 0x14]
        mov      al, byte ptr [g_renderer2_d3dInitByte]
        cmp      dl, al
        mov      eax, dword ptr [g_renderer2_obj]
        je       L_dd4c
        test     eax, eax
        je       L_dd42
        mov      edx, dword ptr [esp + 0x14]
        mov      ecx, dword ptr [eax]
        and      edx, 0xff
        mov      edx, dword ptr [edx*4 + g_renderer2_buf1]
        push     edx
        push     1
        push     eax
        call     dword ptr [ecx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
    L_dd42:
        mov      cl, byte ptr [esp + 0x14]
        mov      byte ptr [g_renderer2_d3dInitByte], cl
    L_dd4c:
        mov      cl, byte ptr [g_renderer2_d3dByte]
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
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
    L_dd96:
        test     eax, eax
        je       L_de0e
        mov      edx, dword ptr [eax]
        push     2
        push     0x13
        push     eax
        call     dword ptr [edx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
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
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
    L_dde3:
        test     eax, eax
        je       L_de0e
        mov      ecx, dword ptr [eax]
        push     6
        push     0x13
        push     eax
        call     dword ptr [ecx + 0x5c]
        mov      dword ptr [g_renderer2_present_rc], eax
        mov      eax, dword ptr [g_renderer2_obj]
        test     eax, eax
        je       L_de0e
        mov      edx, dword ptr [eax]
        push     5
        push     0x14
    L_de05:
        push     eax
        call     dword ptr [edx + 0x5c]
    L_de09:
        mov      dword ptr [g_renderer2_present_rc], eax
    L_de0e:
        mov      byte ptr [g_renderer2_d3dByte], bl
    L_de14:
        fld      dword ptr [esp + 0x1c]
        fcomp    dword ptr [g_const_004d2964]
        xor      di, di
        xor      si, si
        xor      dx, dx
        xor      cx, cx
        mov      word ptr [g_glideTriBatchD], di
        mov      word ptr [g_glideTriBatchC], si
        fnstsw   ax
        mov      word ptr [g_glideTriBatchB], dx
        mov      word ptr [g_glideTriBatch], cx
        test     ah, 1
        je       L_de5a
        mov      di, 1
        mov      word ptr [g_glideTriBatchD], di
        jmp      L_de76
    L_de5a:
        fld      dword ptr [esp + 0x1c]
        fcomp    dword ptr [g_const_004d2968]
        fnstsw   ax
        test     ah, 0x41
        jne      L_de76
        mov      dx, 1
        mov      word ptr [g_glideTriBatchB], dx
    L_de76:
        fld      dword ptr [esp + 0x20]
        fcomp    dword ptr [g_const_004d2964]
        fnstsw   ax
        test     ah, 1
        je       L_de94
        mov      cx, 1
        mov      word ptr [g_glideTriBatch], cx
        jmp      L_deb0
    L_de94:
        fld      dword ptr [esp + 0x20]
        fcomp    dword ptr [g_const_004d296c]
        fnstsw   ax
        test     ah, 0x41
        jne      L_deb0
        mov      si, 1
        mov      word ptr [g_glideTriBatchC], si
    L_deb0:
        fld      dword ptr [esp + 0x30]
        fcomp    dword ptr [g_const_004d2964]
        fnstsw   ax
        test     ah, 1
        je       L_decc
        inc      di
        mov      word ptr [g_glideTriBatchD], di
        jmp      L_dee6
    L_decc:
        fld      dword ptr [esp + 0x30]
        fcomp    dword ptr [g_const_004d2968]
        fnstsw   ax
        test     ah, 0x41
        jne      L_dee6
        inc      dx
        mov      word ptr [g_glideTriBatchB], dx
    L_dee6:
        fld      dword ptr [esp + 0x34]
        fcomp    dword ptr [g_const_004d2964]
        fnstsw   ax
        test     ah, 1
        je       L_df02
        inc      cx
        mov      word ptr [g_glideTriBatch], cx
        jmp      L_df1c
    L_df02:
        fld      dword ptr [esp + 0x34]
        fcomp    dword ptr [g_const_004d296c]
        fnstsw   ax
        test     ah, 0x41
        jne      L_df1c
        inc      si
        mov      word ptr [g_glideTriBatchC], si
    L_df1c:
        fld      dword ptr [esp + 0x44]
        fcomp    dword ptr [g_const_004d2964]
        fnstsw   ax
        test     ah, 1
        je       L_df38
        inc      di
        mov      word ptr [g_glideTriBatchD], di
        jmp      L_df52
    L_df38:
        fld      dword ptr [esp + 0x44]
        fcomp    dword ptr [g_const_004d2968]
        fnstsw   ax
        test     ah, 0x41
        jne      L_df52
        inc      dx
        mov      word ptr [g_glideTriBatchB], dx
    L_df52:
        fld      dword ptr [esp + 0x48]
        fcomp    dword ptr [g_const_004d2964]
        fnstsw   ax
        test     ah, 1
        je       L_df6e
        inc      cx
        mov      word ptr [g_glideTriBatch], cx
        jmp      L_df88
    L_df6e:
        fld      dword ptr [esp + 0x48]
        fcomp    dword ptr [g_const_004d296c]
        fnstsw   ax
        test     ah, 0x41
        jne      L_df88
        inc      si
        mov      word ptr [g_glideTriBatchC], si
    L_df88:
        cmp      cx, 3
        je       L_e55b
        cmp      dx, 3
        je       L_e55b
        cmp      si, 3
        je       L_e55b
        cmp      di, 3
        je       L_e55b
        mov      eax, dword ptr [g_glideTriBatchC]
        mov      ecx, dword ptr [g_glideTriBatchD]
        mov      edx, dword ptr [g_glideTriBatch]
        and      eax, 0xffff
        and      ecx, 0xffff
        and      edx, 0xffff
        add      eax, ecx
        mov      ecx, dword ptr [g_glideTriBatchB]
        add      eax, edx
        and      ecx, 0xffff
        add      eax, ecx
        jne      L_e1da
        mov      eax, dword ptr [g_renderer2_batchCount]
        mov      edx, dword ptr [esp + 0x1c]
        mov      ecx, dword ptr [esp + 0x20]
        and      ebx, 0xff
        lea      eax, [eax + eax*2]
        mov      esi, ebx
        shl      eax, 5
        xor      ebx, ebx
        mov      edi, 0x3f800000
        mov      dword ptr [eax + g_renderer2_vertexBatch], edx
        mov      dword ptr [eax + g_glideTriArrayBase], ecx
        movsx    ecx, word ptr [esp + 0x2c]
        mov      edx, ecx
        mov      ebp, ecx
        sar      edx, 7
        and      edx, 0xf8
        and      ecx, 0x1f
        sar      ebp, 2
        mov      bl, byte ptr [edx + g_palette]
        and      ebp, 0xf8
        shl      esi, 8
        or       ebx, esi
        xor      edx, edx
        mov      dl, byte ptr [ebp + g_palette]
        mov      dword ptr [eax + g_glideVertArr_00544724], edi
        shl      ebx, 8
        or       ebx, edx
        xor      edx, edx
        mov      dl, byte ptr [ecx*8 + g_palette]
        mov      ecx, dword ptr [esp + 0x24]
        shl      ebx, 8
        and      ecx, 0xff
        or       ebx, edx
        mov      dword ptr [eax + g_glideVertArr_00544720], edi
        mov      dword ptr [eax + g_glideVertArr_00544728], ebx
        mov      edx, dword ptr [ecx*4 + g_renderer2_lutTable]
        mov      ecx, dword ptr [esp + 0x28]
        and      ecx, 0xff
        mov      dword ptr [eax + g_glideVertArr_00544730], edx
        xor      ebx, ebx
        mov      edx, dword ptr [ecx*4 + g_renderer2_lutTable]
        mov      ecx, dword ptr [esp + 0x30]
        mov      dword ptr [eax + g_glideVertArr_00544734], edx
        mov      edx, dword ptr [esp + 0x34]
        mov      dword ptr [eax + g_glideVertArr_00544738], ecx
        mov      dword ptr [eax + g_glideVertArr_0054473c], edx
        movsx    ecx, word ptr [esp + 0x40]
        mov      edx, ecx
        mov      ebp, ecx
        sar      edx, 7
        and      edx, 0xf8
        and      ecx, 0x1f
        sar      ebp, 2
        mov      bl, byte ptr [edx + g_palette]
        and      ebp, 0xf8
        or       ebx, esi
        xor      edx, edx
        mov      dl, byte ptr [ebp + g_palette]
        mov      dword ptr [eax + g_glideVertArr_00544744], edi
        shl      ebx, 8
        or       ebx, edx
        xor      edx, edx
        mov      dl, byte ptr [ecx*8 + g_palette]
        mov      ecx, dword ptr [esp + 0x38]
        shl      ebx, 8
        and      ecx, 0xff
        or       ebx, edx
        mov      dword ptr [eax + g_glideVertArr_00544740], edi
        mov      dword ptr [eax + g_glideVertArr_00544748], ebx
        mov      edx, dword ptr [ecx*4 + g_renderer2_lutTable]
        mov      ecx, dword ptr [esp + 0x3c]
        and      ecx, 0xff
        mov      dword ptr [eax + g_glideVertArr_00544750], edx
        mov      edx, dword ptr [ecx*4 + g_renderer2_lutTable]
        mov      ecx, dword ptr [esp + 0x44]
        mov      dword ptr [eax + g_glideVertArr_00544754], edx
        mov      edx, dword ptr [esp + 0x48]
        mov      dword ptr [eax + g_glideVertArr_00544758], ecx
        mov      dword ptr [eax + g_glideVertArr6], edx
        mov      dword ptr [eax + g_glideVertArr4], edi
        mov      dword ptr [eax + g_glideVertArr5], edi
        movsx    ecx, word ptr [esp + 0x54]
        mov      edx, ecx
        xor      ebx, ebx
        sar      edx, 7
        and      edx, 0xf8
        mov      bl, byte ptr [edx + g_palette]
        xor      edx, edx
        or       ebx, esi
        mov      esi, ecx
        sar      esi, 2
        and      esi, 0xf8
        and      ecx, 0x1f
        shl      ebx, 8
        mov      dl, byte ptr [esi + g_palette]
        or       ebx, edx
        xor      edx, edx
        mov      dl, byte ptr [ecx*8 + g_palette]
        mov      ecx, dword ptr [esp + 0x4c]
        shl      ebx, 8
        and      ecx, 0xff
        or       ebx, edx
        mov      dword ptr [eax + g_glideVertArr3], ebx
        mov      edx, dword ptr [ecx*4 + g_renderer2_lutTable]
        mov      ecx, dword ptr [esp + 0x50]
        and      ecx, 0xff
        mov      dword ptr [eax + g_glideVertArr2], edx
        mov      edx, dword ptr [ecx*4 + g_renderer2_lutTable]
        mov      dword ptr [eax + g_glideVertArr_00544774], edx
        mov      eax, dword ptr [g_renderer2_batchCount]
        inc      eax
        mov      dword ptr [g_renderer2_batchCount], eax
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
        mov      dword ptr [g_glideTriSave], eax
        mov      eax, dword ptr [esp + 0x28]
        fld      dword ptr [edx*4 + g_renderer2_lutTable]
        and      eax, 0xff
        mov      dword ptr [g_glideDataArr_00543f8c], ecx
        fstp     dword ptr [g_glideDataArr_00543f90]
        fld      dword ptr [eax*4 + g_renderer2_lutTable]
        mov      eax, dword ptr [esp + 0x38]
        mov      ecx, dword ptr [esp + 0x30]
        fstp     dword ptr [g_glideDataArr_00543f94]
        mov      edx, dword ptr [esp + 0x34]
        and      eax, 0xff
        mov      dword ptr [g_glideDataArr_00543fa4], ecx
        mov      ecx, dword ptr [esp + 0x3c]
        fld      dword ptr [eax*4 + g_renderer2_lutTable]
        mov      eax, dword ptr [esp + 0x48]
        and      ecx, 0xff
        fstp     dword ptr [g_glideDataArr_00543fac]
        fld      dword ptr [ecx*4 + g_renderer2_lutTable]
        mov      ecx, dword ptr [esp + 0x4c]
        mov      dword ptr [g_glideDataArr_00543fa8], edx
        mov      edx, dword ptr [esp + 0x44]
        mov      dword ptr [g_glideDataArr_00543fc4], eax
        movsx    eax, word ptr [esp + 0x2c]
        fstp     dword ptr [g_glideDataArr_00543fb0]
        and      ecx, 0xff
        mov      dword ptr [g_glideDataArr_00543fc0], edx
        mov      edx, dword ptr [esp + 0x50]
        fld      dword ptr [ecx*4 + g_renderer2_lutTable]
        mov      ecx, eax
        and      edx, 0xff
        fstp     dword ptr [g_glideDataArr_00543fc8]
        fld      dword ptr [edx*4 + g_renderer2_lutTable]
        sar      ecx, 7
        and      ecx, 0xf8
        xor      edx, edx
        fstp     dword ptr [g_glideDataArr_00543fcc]
        mov      dl, byte ptr [ecx + g_palette]
        mov      ecx, eax
        sar      ecx, 2
        mov      dword ptr [esp + 0x2c], edx
        and      ecx, 0xf8
        fild     dword ptr [esp + 0x2c]
        xor      edx, edx
        and      eax, 0x1f
        mov      dl, byte ptr [ecx + g_palette]
        xor      ecx, ecx
        mov      cl, byte ptr [eax*8 + g_palette]
        mov      dword ptr [esp + 0x2c], edx
        movsx    eax, word ptr [esp + 0x40]
        fstp     dword ptr [g_glideDataArr_00543f98]
        fild     dword ptr [esp + 0x2c]
        mov      edx, eax
        mov      dword ptr [esp + 0x2c], ecx
        sar      edx, 7
        fstp     dword ptr [g_glideDataArr_00543f9c]
        fild     dword ptr [esp + 0x2c]
        and      edx, 0xf8
        xor      ecx, ecx
        mov      cl, byte ptr [edx + g_palette]
        mov      edx, eax
        fstp     dword ptr [g_glideDataArr_00543fa0]
        sar      edx, 2
        mov      dword ptr [esp + 0x2c], ecx
        and      edx, 0xf8
        fild     dword ptr [esp + 0x2c]
        xor      ecx, ecx
        and      eax, 0x1f
        mov      cl, byte ptr [edx + g_palette]
        xor      edx, edx
        fstp     dword ptr [g_glideDataArr_00543fb4]
        mov      dl, byte ptr [eax*8 + g_palette]
        mov      dword ptr [esp + 0x2c], ecx
        fild     dword ptr [esp + 0x2c]
        mov      dword ptr [esp + 0x2c], edx
        fstp     dword ptr [g_glideDataArr_00543fb8]
        fild     dword ptr [esp + 0x2c]
        movsx    eax, word ptr [esp + 0x54]
        fstp     dword ptr [g_glideDataArr_00543fbc]
        mov      ecx, eax
        xor      edx, edx
        sar      ecx, 7
        and      ecx, 0xf8
        mov      dl, byte ptr [ecx + g_palette]
        mov      ecx, eax
        sar      ecx, 2
        mov      dword ptr [esp + 0x2c], edx
        and      ecx, 0xf8
        fild     dword ptr [esp + 0x2c]
        xor      edx, edx
        and      eax, 0x1f
        mov      dl, byte ptr [ecx + g_palette]
        xor      ecx, ecx
        fstp     dword ptr [g_glideDataArr_00543fd0]
        mov      cl, byte ptr [eax*8 + g_palette]
        mov      dword ptr [esp + 0x2c], edx
        fild     dword ptr [esp + 0x2c]
        mov      dword ptr [esp + 0x2c], ecx
        fstp     dword ptr [g_glideDataArr_00543fd4]
        fild     dword ptr [esp + 0x2c]
        fstp     dword ptr [g_glideDataArr_00543fd8]
        call     GlidePolyClip
        cmp      eax, 3
        jl       L_e55b
        cmp      eax, 7
        jg       L_e55b
        mov      ecx, dword ptr [g_renderer2_batchCount]
        lea      edx, [ecx + eax - 2]
        sub      eax, 3
        lea      esi, [ecx + ecx*2]
        mov      dword ptr [g_renderer2_batchCount], edx
        js       L_e55b
        mov      ebp, dword ptr [g_glideTriVar]
        mov      ecx, eax
        and      ebx, 0xff
        shl      esi, 5
        shl      ecx, 3
        shl      ebx, 8
        add      esi, OFFSET g_glideTriArrayBase
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
        call     DoubleToInt64
        fld      dword ptr [ebp + 0x14]
        mov      dl, al
        and      edx, 0xff
        or       edx, ebx
        shl      edx, 8
        mov      dword ptr [esp + 0x54], edx
        call     DoubleToInt64
        mov      ebx, dword ptr [esp + 0x54]
        and      eax, 0xff
        fld      dword ptr [ebp + 0x18]
        or       ebx, eax
        shl      ebx, 8
        call     DoubleToInt64
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
        call     DoubleToInt64
        mov      ecx, dword ptr [esp + 0x2c]
        mov      bl, al
        fld      dword ptr [edi + 0x10]
        and      ebx, 0xff
        or       ebx, ecx
        shl      ebx, 8
        call     DoubleToInt64
        fld      dword ptr [edi + 0x14]
        and      eax, 0xff
        or       ebx, eax
        shl      ebx, 8
        call     DoubleToInt64
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
        call     DoubleToInt64
        mov      ecx, dword ptr [esp + 0x2c]
        mov      bl, al
        fld      dword ptr [edi + 0x2c]
        and      ebx, 0xff
        or       ebx, ecx
        shl      ebx, 8
        call     DoubleToInt64
        fld      dword ptr [edi + 0x30]
        and      eax, 0xff
        or       ebx, eax
        shl      ebx, 8
        call     DoubleToInt64
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
