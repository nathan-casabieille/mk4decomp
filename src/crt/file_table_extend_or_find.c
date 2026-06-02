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
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
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
extern void DispatcherComplex260_00407030(void);
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
extern void PendingMatch_0042b930(void);
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

/* @addr 0x004ccfa0 (360b crt) - _ioinit-style file-table extend / find.
 *   Enters crit-sec lock 0x12 (Lock(0x12)), then walks the
 *   array of 0x480-byte file-table blocks at g_arr_00fa0de0. For each
 *   block, scans 0x24-byte entries looking for one with bit-0 of [+4]
 *   set or count [+8] zero - lazy-initializes the InitializeCriticalSection
 *   slot at [esi+0xc] via IAT [0x4d215c] on first use, then locks via
 *   IAT [0x4d2140] and reads bit-0 of [+4] to decide whether to release
 *   via IAT [0x4d213c]. Computes the file-table index from the byte
 *   offset using 0x38e38e39 reciprocal-multiply (= /0x24). If no
 *   existing block has room, allocates a new 0x480-byte block via
 *   LoadArgPushCall(0x480), seeds entries with type=0xa, then
 *   calls CritSecLazyEnter(idx*0x20). Exits crit-sec 0x12.
 */
extern unsigned int g_iat_LeaveCriticalSection;
extern unsigned int g_iat_EnterCriticalSection;
extern unsigned int g_iat_InitializeCriticalSection;
extern unsigned int g_arr_00fa0de0;
extern unsigned int g_dispatchSave1469;
extern void CritSecLazyEnter(void);
extern void LoadArgPushCall(void);
extern void Lock(void);
extern void TableLookupIatCall(void);

__declspec(naked) void FileTableExtendOrFind(void) {
    __asm {
        sub     esp, 8
        push    ebx
        push    ebp
        push    esi
        push    edi
        push    0x12
        mov     dword ptr [esp + 0x14], 0xffffffff
        call    Lock
        xor     edi, edi
        add     esp, 4
        mov     dword ptr [esp + 0x14], edi
        xor     ebx, ebx
        mov     ebp, offset g_arr_00fa0de0
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
        call    Lock
        mov     eax, dword ptr [esi + 8]
        add     esp, 4
        test    eax, eax
        jne     short L_fte_relCrit
        lea     ecx, [esi + 0xc]
        push    ecx
        call    dword ptr [g_iat_InitializeCriticalSection]
        inc     dword ptr [esi + 8]
    L_fte_relCrit:
        push    0x11
        call    TableLookupIatCall
        add     esp, 4
    L_fte_initDone:
        lea     edi, [esi + 0xc]
        push    edi
        call    dword ptr [g_iat_EnterCriticalSection]
        test    byte ptr [esi + 4], 1
        je      short L_fte_foundFree
        push    edi
        call    dword ptr [g_iat_LeaveCriticalSection]
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
        call    LoadArgPushCall
        xor     edx, edx
        add     esp, 4
        cmp     eax, edx
        je      short L_fte_doneFound
        mov     ebx, dword ptr [g_dispatchSave1469]
        lea     ecx, [eax + 0x480]
        add     ebx, 0x20
        cmp     eax, ecx
        mov     dword ptr [edi*4 + g_arr_00fa0de0], eax
        mov     dword ptr [g_dispatchSave1469], ebx
        jae     short L_fte_postSeed
        mov     cl, 0xa
    L_fte_seedLoop:
        mov     byte ptr [eax + 4], 0
        mov     dword ptr [eax], 0xffffffff
        mov     byte ptr [eax + 5], cl
        mov     dword ptr [eax + 8], edx
        mov     esi, dword ptr [edi*4 + g_arr_00fa0de0]
        add     eax, 0x24
        add     esi, 0x480
        cmp     eax, esi
        jb      short L_fte_seedLoop
    L_fte_postSeed:
        shl     edi, 5
        mov     eax, edi
        push    eax
        mov     dword ptr [esp + 0x14], eax
        call    CritSecLazyEnter
        add     esp, 4
    L_fte_doneFound:
        push    0x12
        call    TableLookupIatCall
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
