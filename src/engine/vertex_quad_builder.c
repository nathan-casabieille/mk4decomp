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

/* @addr 0x004bc470 (294b engine.render) - per-tri vertex/UV building from indexed source.
 *   arg0 (esp+8): poly index. Reads [0x542048]+4 (base table); fetches 16-byte
 *   entry; reads bp = count (entry+0xe), ebx = entry+0xc. If ebp == 0, free slot
 *   in [edx*4 + 0x48] table and return.
 *   Allocates a vertex block via LeaScaledCall_004bd510 + Mem_Malloc; iterates
 *   `ebp` times copying UV (3 u16) + reading color index (byte) -> palette
 *   byte, masking into output.
 */
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542048;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00ab4e34;
extern void LeaScaledCall_004bd510(void);
extern void Mem_Malloc(void);

__declspec(naked) void VertexQuadBuilder_004bc470(void) {
    __asm {
        push    ecx
        mov     ecx, dword ptr [g_data_00542048]
        mov     eax, [esp + 8]
        shl     eax, 4
        mov     edx, [ecx + 4]
        push    ebx
        push    ebp
        xor     ebp, ebp
        mov     bp, word ptr [eax + edx + 0xe]
        lea     ebx, [eax + edx + 0xc]
        push    esi
        push    edi
        test    ebp, ebp
        mov     [esp + 0x10], ecx
        jz      L_vqb_freeRet
        mov     esi, dword ptr [g_data_0054205c]
        mov     edx, dword ptr [g_data_00ab4e34]
        mov     eax, dword ptr [g_data_00542044]
        mov     edi, ebp
        sar     esi, 0x10
        and     esi, 8
        lea     eax, [eax*4 + 0x48]
        shl     edi, 3
        or      esi, edx
        mov     edx, [esp + 0x1c]
        sub     edi, ebp
        mov     [esp + 0x18], eax
        shl     edi, 2
        test    edx, edx
        jz      short L_vqb_directAlloc
        mov     eax, [eax]
        mov     edx, [eax]
        and     edx, 9
        cmp     edx, esi
        jne     short L_vqb_allocFallback
        cmp     edi, [eax + 4]
        jle     short L_vqb_useExisting
    L_vqb_allocFallback:
        push    2
        call    LeaScaledCall_004bd510
        mov     eax, [esp + 0x1c]
        add     esp, 4
    L_vqb_directAlloc:
        lea     ecx, [edi + 0xc]
        push    2
        push    ecx
        push    eax
        call    Mem_Malloc
        add     esp, 0xc
        test    eax, eax
        jne     short L_vqb_store
    L_vqb_freeRet:
        mov     edx, dword ptr [g_data_00542044]
        xor     eax, eax
        mov     dword ptr [g_data_0054204c], eax
        mov     [edx*4 + 0x48], eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    L_vqb_store:
        mov     ecx, [esp + 0x10]
        mov     [eax + 4], edi
    L_vqb_useExisting:
        mov     edx, ebx
        mov     dword ptr [g_data_0054204c], eax
        shl     edx, 5
        or      edx, esi
        mov     [eax], edx
        lea     edx, [eax + 8]
        mov     eax, [ebx + 0xc]
        test    ebp, ebp
        lea     esi, [eax + ebx + 0xc]
        mov     eax, [ecx + 4]
        mov     ecx, [eax + 4]
        lea     ebx, [ecx + eax + 8]
        jle     short L_vqb_done
    L_vqb_loop:
        mov     ecx, 7
        xor     eax, eax
        mov     edi, edx
        add     edx, 0x1c
        rep     stosd
        mov     ax, word ptr [esi + 2]
        add     esi, 8
        mov     word ptr [edx - 0x10], ax
        mov     cx, word ptr [esi - 4]
        mov     word ptr [edx - 0x0e], cx
        mov     ax, word ptr [esi - 2]
        mov     word ptr [edx - 0x0c], ax
        movsx   ecx, byte ptr [esi - 8]
        mov     al, byte ptr [ebx + ecx*4 + 2]
        xor     cx, cx
        and     al, 0x0f
        mov     cl, al
        mov     ax, word ptr [edx - 2]
        and     eax, 0xfff0
        or      ecx, eax
        dec     ebp
        mov     word ptr [edx - 2], cx
        jne     short L_vqb_loop
    L_vqb_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
