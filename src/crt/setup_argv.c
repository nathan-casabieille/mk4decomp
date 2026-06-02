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

/* @addr 0x004cbc20 (158b crt) - argv[] setup from GetModuleFileNameA + ParseCommandLine.
 *   Frame: sub esp, 8; push esi, edi.
 *   GetModuleFileNameA(NULL, [0xf9faf0], MAX_PATH).
 *   edi = [0xfa0ee8]; [0xf9f830] = [0xf9faf0].
 *   if (*edi == 0): edi = [0xf9faf0] (use module path).
 *   Call CrtParseCommandLine (parse, count). Get char_size + arg_count.
 *   Call malloc/realloc-like LoadArgPushCall(total_bytes). esi = result.
 *   if (esi == 0): call CmpCallPushIATCall(8) (errno).
 *   Call CrtParseCommandLine again (this time storing args). [0xf9f818] = esi (argv array).
 *   [0xf9f814] = argc - 1.
 */
extern unsigned int g_GetModuleFileNameA;
extern unsigned int g_buf_00f9faf0;
extern unsigned int g_dispatchSave1424;
extern unsigned int g_dispatchSave1425;
extern unsigned int g_dispatchSave1427;
extern char * g_cmdline;
extern void CmpCallPushIATCall(void);
extern void CrtParseCommandLine(void);
extern void LoadArgPushCall(void);

__declspec(naked) void SetupArgv(void) {
    __asm {
        sub     esp, 8
        push    esi
        push    edi
        push    0x104
        push    offset g_buf_00f9faf0
        push    0
        call    dword ptr [g_GetModuleFileNameA]
        mov     edi, dword ptr [g_cmdline]
        mov     dword ptr [g_dispatchSave1427], offset g_buf_00f9faf0
        cmp     byte ptr [edi], 0
        _emit   75h
        _emit   05h
        mov     edi, offset g_buf_00f9faf0
        lea     eax, [esp + 0x0c]
        lea     ecx, [esp + 8]
        push    eax
        push    ecx
        push    0
        push    0
        push    edi
        call    CrtParseCommandLine
        mov     edx, [esp + 0x20]
        mov     eax, [esp + 0x1c]
        add     esp, 0x14
        lea     ecx, [edx + eax*4]
        push    ecx
        call    LoadArgPushCall
        mov     esi, eax
        add     esp, 4
        test    esi, esi
        _emit   75h
        _emit   0ah
        push    8
        call    CmpCallPushIATCall
        add     esp, 4
        mov     ecx, [esp + 8]
        lea     edx, [esp + 0x0c]
        push    edx
        lea     eax, [esp + 0x0c]
        lea     edx, [esi + ecx*4]
        push    eax
        push    edx
        push    esi
        push    edi
        call    CrtParseCommandLine
        mov     eax, [esp + 0x1c]
        add     esp, 0x14
        dec     eax
        mov     dword ptr [g_dispatchSave1425], esi
        pop     edi
        mov     dword ptr [g_dispatchSave1424], eax
        pop     esi
        add     esp, 8
        ret
    }
}
