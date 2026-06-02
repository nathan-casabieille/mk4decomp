/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
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

/* @addr 0x004d0140 (303b other) - bundled string-digit-strip + slot-replace pair.
 *   sub-1 (~48b at 0x4d0140): in-place string translation. For each char:
 *     if digit '0'..'9': subtract '0'; if ';': skip (shift rest down).
 *   sub-2 (~239b at 0x4d0180): slot replace - allocate 0x30 bytes via Calloc_004c6110,
 *     copy from g_crtTimeFmtPrefs_005236e8 into new slot, free old, swap pointers.
 *     Path differs based on flag g_dispatchSave1445_00f9fc14.
 */
extern unsigned int g_dispatchPair_005236b8;
extern unsigned int g_crtTimeFmtPrefs_005236e8;
extern unsigned int g_dispatchSave1445_00f9fc14;
extern unsigned int g_dispatchSave1459_00f9fc74;
extern void Calloc_004c6110(void);
extern void CrtFreeLocaleInfo_004d0400(void);
extern void FreeImpl_004c55f0(void);
extern void LocaleInfoFill_004d0270(void);

__declspec(naked) void StringStripSlotReplace_004d0140(void) {
    __asm {
        /* sub-1 (in-place string strip) */
        mov     ecx, [esp + 4]
        mov     al, [ecx]
        test    al, al
        jz      short L_strs_endA
    L_strs_scan:
        cmp     al, 0x30
        jl      short L_strs_notDigit
        cmp     al, 0x39
        jg      short L_strs_notDigit
        sub     al, 0x30
        mov     [ecx], al
    L_strs_advance:
        inc     ecx
    L_strs_load:
        mov     al, [ecx]
        test    al, al
        jne     short L_strs_scan
    L_strs_endA:
        ret
    L_strs_notDigit:
        cmp     al, 0x3b
        jne     short L_strs_advance
        mov     eax, ecx
    L_strs_shift:
        mov     dl, [eax + 1]
        mov     [eax], dl
        mov     dl, [eax + 1]
        inc     eax
        test    dl, dl
        jne     short L_strs_shift
        jmp     short L_strs_load
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        /* sub-2 (slot replace) */
        mov     eax, dword ptr [g_dispatchSave1445_00f9fc14]
        push    esi
        test    eax, eax
        jz      L_srr_directPath
        push    0x30
        push    1
        call    Calloc_004c6110
        mov     esi, eax
        add     esp, 8
        test    esi, esi
        jne     short L_srr_haveBuf
        mov     eax, 1
        pop     esi
        ret
    L_srr_haveBuf:
        push    esi
        call    LocaleInfoFill_004d0270
        add     esp, 4
        test    eax, eax
        jz      short L_srr_install
        push    esi
        call    CrtFreeLocaleInfo_004d0400
        add     esp, 4
        push    esi
        call    FreeImpl_004c55f0
        add     esp, 4
        mov     eax, 1
        pop     esi
        ret
    L_srr_install:
        mov     eax, dword ptr [g_crtTimeFmtPrefs_005236e8]
        mov     ecx, [eax]
        mov     [esi], ecx
        mov     edx, dword ptr [g_crtTimeFmtPrefs_005236e8]
        mov     eax, [edx + 4]
        mov     [esi + 4], eax
        mov     ecx, dword ptr [g_crtTimeFmtPrefs_005236e8]
        mov     edx, [ecx + 8]
        mov     [esi + 8], edx
        mov     eax, dword ptr [g_dispatchSave1459_00f9fc74]
        push    eax
        mov     dword ptr [g_crtTimeFmtPrefs_005236e8], esi
        call    CrtFreeLocaleInfo_004d0400
        mov     ecx, dword ptr [g_dispatchSave1459_00f9fc74]
        add     esp, 4
        push    ecx
        call    FreeImpl_004c55f0
        add     esp, 4
        mov     dword ptr [g_dispatchSave1459_00f9fc74], esi
        xor     eax, eax
        pop     esi
        ret
    L_srr_directPath:
        mov     eax, dword ptr [g_crtTimeFmtPrefs_005236e8]
        mov     edx, [eax]
        mov     dword ptr [g_dispatchPair_005236b8], edx
        mov     ecx, [eax + 4]
        mov     dword ptr [g_dispatchPair_005236b8 + 4], ecx
        mov     edx, [eax + 8]
        mov     eax, dword ptr [g_dispatchSave1459_00f9fc74]
        mov     dword ptr [g_dispatchPair_005236b8 + 8], edx
        push    eax
        mov     dword ptr [g_crtTimeFmtPrefs_005236e8], offset g_dispatchPair_005236b8
        call    CrtFreeLocaleInfo_004d0400
        mov     ecx, dword ptr [g_dispatchSave1459_00f9fc74]
        add     esp, 4
        push    ecx
        call    FreeImpl_004c55f0
        add     esp, 4
        mov     dword ptr [g_dispatchSave1459_00f9fc74], 0
        xor     eax, eax
        pop     esi
        ret
    }
}
