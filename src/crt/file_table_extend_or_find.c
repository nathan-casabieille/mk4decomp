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

/* @addr 0x004ccfa0 (360b crt) - _ioinit-style file-table extend / find.
 *   Enters crit-sec lock 0x12 (Lock_004c6f50(0x12)), then walks the
 *   array of 0x480-byte file-table blocks at g_data_00fa0de0. For each
 *   block, scans 0x24-byte entries looking for one with bit-0 of [+4]
 *   set or count [+8] zero - lazy-initializes the InitializeCriticalSection
 *   slot at [esi+0xc] via IAT [0x4d215c] on first use, then locks via
 *   IAT [0x4d2140] and reads bit-0 of [+4] to decide whether to release
 *   via IAT [0x4d213c]. Computes the file-table index from the byte
 *   offset using 0x38e38e39 reciprocal-multiply (= /0x24). If no
 *   existing block has room, allocates a new 0x480-byte block via
 *   LoadArgPushCall_004c54b0(0x480), seeds entries with type=0xa, then
 *   calls CritSecLazyEnter_004cd2b0(idx*0x20). Exits crit-sec 0x12.
 */
extern unsigned int g_data_004d213c;
extern unsigned int g_data_004d2140;
extern unsigned int g_data_004d215c;
extern unsigned int g_data_00fa0de0;
extern unsigned int g_data_00fa0ee0;
extern void CritSecLazyEnter_004cd2b0(void);
extern void LoadArgPushCall_004c54b0(void);
extern void Lock_004c6f50(void);
extern void TableLookupIatCall_004c6fd0(void);

__declspec(naked) void FileTableExtendOrFind_004ccfa0(void) {
    __asm {
        sub     esp, 8
        push    ebx
        push    ebp
        push    esi
        push    edi
        push    0x12
        mov     dword ptr [esp + 0x14], 0xffffffff
        call    Lock_004c6f50
        xor     edi, edi
        add     esp, 4
        mov     dword ptr [esp + 0x14], edi
        xor     ebx, ebx
        mov     ebp, offset g_data_00fa0de0
    L_fte_outer:
        mov     esi, dword ptr [ebp]
        test    esi, esi
        je      L_fte_allocNew
        lea     eax, [esi + 0x480]
        cmp     esi, eax
        jae     L_fte_advancePtr
    L_fte_innerHead:
        test    byte ptr [esi + 4], 1
        jne     short L_fte_advanceEntry
        mov     eax, dword ptr [esi + 8]
        test    eax, eax
        jne     short L_fte_initDone
        push    0x11
        call    Lock_004c6f50
        mov     eax, dword ptr [esi + 8]
        add     esp, 4
        test    eax, eax
        jne     short L_fte_relCrit
        lea     ecx, [esi + 0xc]
        push    ecx
        call    dword ptr [g_data_004d215c]
        inc     dword ptr [esi + 8]
    L_fte_relCrit:
        push    0x11
        call    TableLookupIatCall_004c6fd0
        add     esp, 4
    L_fte_initDone:
        lea     edi, [esi + 0xc]
        push    edi
        call    dword ptr [g_data_004d2140]
        test    byte ptr [esi + 4], 1
        je      short L_fte_foundFree
        push    edi
        call    dword ptr [g_data_004d213c]
    L_fte_advanceEntry:
        mov     edx, dword ptr [ebp]
        add     esi, 0x24
        add     edx, 0x480
        cmp     esi, edx
        jb      L_fte_innerHead
        jmp     short L_fte_advancePtr
    L_fte_foundFree:
        mov     dword ptr [esi], 0xffffffff
        mov     eax, dword ptr [ebp]
        sub     esi, eax
        mov     eax, 0x38e38e39
        imul    esi
        sar     edx, 3
        mov     eax, edx
        shr     eax, 0x1f
        add     edx, eax
        add     edx, ebx
        mov     dword ptr [esp + 0x10], edx
    L_fte_advancePtr:
        cmp     dword ptr [esp + 0x10], -1
        jne     L_fte_doneFound
        mov     edi, dword ptr [esp + 0x14]
        add     ebp, 4
        inc     edi
        add     ebx, 0x20
        cmp     ebp, 0xfa0ee0
        mov     dword ptr [esp + 0x14], edi
        jl      L_fte_outer
        jmp     short L_fte_doneFound
    L_fte_allocNew:
        push    0x480
        call    LoadArgPushCall_004c54b0
        xor     edx, edx
        add     esp, 4
        cmp     eax, edx
        je      short L_fte_doneFound
        mov     ebx, dword ptr [g_data_00fa0ee0]
        lea     ecx, [eax + 0x480]
        add     ebx, 0x20
        cmp     eax, ecx
        mov     dword ptr [edi*4 + g_data_00fa0de0], eax
        mov     dword ptr [g_data_00fa0ee0], ebx
        jae     short L_fte_postSeed
        mov     cl, 0xa
    L_fte_seedLoop:
        mov     byte ptr [eax + 4], 0
        mov     dword ptr [eax], 0xffffffff
        mov     byte ptr [eax + 5], cl
        mov     dword ptr [eax + 8], edx
        mov     esi, dword ptr [edi*4 + g_data_00fa0de0]
        add     eax, 0x24
        add     esi, 0x480
        cmp     eax, esi
        jb      short L_fte_seedLoop
    L_fte_postSeed:
        shl     edi, 5
        mov     eax, edi
        push    eax
        mov     dword ptr [esp + 0x14], eax
        call    CritSecLazyEnter_004cd2b0
        add     esp, 4
    L_fte_doneFound:
        push    0x12
        call    TableLookupIatCall_004c6fd0
        mov     eax, dword ptr [esp + 0x14]
        add     esp, 4
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 8
        ret
    }
}
