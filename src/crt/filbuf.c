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
extern unsigned int g_data_0053a180;
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

/* @addr 0x004c8ed0 (239b crt) - CRT _filbuf: fill stream buffer on read.
 *   FILE* arg (esi); reads flags from [esi+0xc]. If !0x83 → error tail.
 *   If 0x40 (error) → error tail. If 0x02 → mark EOF (or 0x20), ret -1.
 *   Otherwise: ensure buffer allocated (StreamAllocInit) or reset to [esi+8].
 *   Read via IOWrapper(buf=[esi+0x10], size=[esi+8], fd=[esi+0x18]) → eax.
 *   If 0 or -1: set EOF/error flag, ret -1.
 *   Otherwise: check device flags via fd lookup table (g_data_00fa0de0 or default 0x5222e0):
 *     if 0x82 device flags set, OR 0x2000 into flags.
 *   If buf-size == 0x200 and flag-bit 8 set and flag-bit 0x400 clear: bump size to 0x1000.
 *   Decrement count, return first byte.
 */
extern unsigned int g_data_005222e0;
extern unsigned int g_data_00fa0de0;
extern void IOWrapper_004c8fc0(void);
extern void StreamAllocInit_004cc250(void);

__declspec(naked) void Filbuf_004c8ed0(void) {
    __asm {
        push    esi
        mov     esi, [esp + 8]
        push    edi
        mov     eax, [esi + 0xc]
        test    al, 0x83
        jz      L_fb_err
        test    al, 0x40
        jne     L_fb_err
        test    al, 2
        jz      short L_fb_setRead
        or      al, 0x20
        mov     [esi + 0xc], eax
        or      eax, -1
        pop     edi
        pop     esi
        ret
    L_fb_setRead:
        or      al, 1
        test    eax, 0x10c
        mov     [esi + 0xc], eax
        jne     short L_fb_haveBuf
        push    esi
        call    StreamAllocInit_004cc250
        add     esp, 4
        jmp     short L_fb_doRead
    L_fb_haveBuf:
        mov     eax, [esi + 8]
        mov     [esi], eax
    L_fb_doRead:
        mov     ecx, [esi + 0x18]
        mov     edx, [esi + 8]
        mov     eax, [esi + 0x10]
        push    ecx
        push    edx
        push    eax
        call    IOWrapper_004c8fc0
        add     esp, 0xc
        mov     [esi + 4], eax
        test    eax, eax
        jz      short L_fb_eof
        cmp     eax, -1
        jz      short L_fb_eof
        mov     edx, [esi + 0xc]
        test    dl, 0x82
        jne     short L_fb_sizeCk
        mov     ecx, [esi + 0x10]
        cmp     ecx, -1
        jz      short L_fb_useDefault
        mov     edi, ecx
        sar     edi, 5
        and     ecx, 0x1f
        mov     edi, dword ptr [edi*4 + g_data_00fa0de0]
        lea     ecx, [ecx + ecx*8]
        lea     ecx, [edi + ecx*4]
        jmp     short L_fb_checkFlags
    L_fb_useDefault:
        mov     ecx, offset g_data_005222e0
    L_fb_checkFlags:
        mov     cl, byte ptr [ecx + 4]
        and     cl, 0x82
        cmp     cl, 0x82
        jne     short L_fb_sizeCk
        or      dh, 0x20
        mov     [esi + 0xc], edx
    L_fb_sizeCk:
        cmp     dword ptr [esi + 0x18], 0x200
        jne     short L_fb_advance
        mov     ecx, [esi + 0xc]
        test    cl, 8
        jz      short L_fb_advance
        test    ch, 4
        jne     short L_fb_advance
        mov     dword ptr [esi + 0x18], 0x1000
    L_fb_advance:
        dec     eax
        xor     edx, edx
        mov     [esi + 4], eax
        mov     eax, [esi]
        mov     dl, [eax]
        inc     eax
        mov     [esi], eax
        mov     eax, edx
        pop     edi
        pop     esi
        ret
    L_fb_eof:
        mov     ecx, [esi + 0xc]
        mov     dword ptr [esi + 4], 0
        neg     eax
        sbb     eax, eax
        and     eax, 0x10
        add     eax, 0x10
        or      ecx, eax
        mov     [esi + 0xc], ecx
    L_fb_err:
        pop     edi
        or      eax, -1
        pop     esi
        ret
    }
}
