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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

extern unsigned int g_dispatchSave820_004f42d8;
extern unsigned int g_dispatchSave821_004f42dc;
extern unsigned int g_menuPageVar_004f5328;
extern unsigned int g_dispatchSave872_004f6164;
extern unsigned int g_dispatchSave873_004f6190;
extern unsigned int g_dispatchSave874_004f61a0;
extern unsigned int g_dispatchSave875_004f61b0;
extern unsigned int g_dispatchSave876_004f61bc;
extern unsigned int g_dispatchSave877_004f61c8;
extern unsigned int g_dispatchSave878_004f61d0;
extern unsigned int g_dispatchSave879_004f61d8;
extern unsigned int g_dispatchSave721_004f61e0;
extern unsigned int g_menuPageDispatch_00543a98;
extern unsigned int g_menuRestoreD_00543a9c;
extern unsigned int g_menuRestoreA_00543aa0;
extern unsigned int g_menuRestoreB_00543aac;
extern unsigned int g_menuRestoreC_00543ab0;
extern unsigned int g_byte_00543ab4;
extern unsigned int g_dispatchSave1479_00ab41c8;
extern unsigned int g_dispatchSave1490_00ab4328;
extern unsigned int g_dispatchSave1492_00ab4358;
extern void DrawMenu(void);
extern void Helper_Sprintf(void);
extern void Menu_FillColonField(void);

__declspec(naked) void Menu_FillOptionValues(void)
{
    __asm {
        mov      eax, dword ptr [g_menuPageVar_004f5328]
        mov      dword ptr [esp + 8], OFFSET g_dispatchSave721_004f61e0
        test     eax, eax
        mov      dword ptr [esp + 0xc], OFFSET g_dispatchSave879_004f61d8
        mov      dword ptr [esp + 0x10], OFFSET g_dispatchSave878_004f61d0
        mov      dword ptr [esp + 0x14], OFFSET g_dispatchSave877_004f61c8
        mov      dword ptr [esp + 0x18], OFFSET g_dispatchSave876_004f61bc
        mov      dword ptr [esp + 0x1c], OFFSET g_dispatchSave875_004f61b0
        je       L_8152
        mov      esi, OFFSET g_menuPageVar_004f5328
    L_80c2:
        movsx    eax, word ptr [esi + 4]
        add      eax, -0x3c
        cmp      eax, 5
        ja       short L_8144
        jmp      dword ptr [eax*4 + L_080_jmptbl]
    L_80d5:
        mov      edx, dword ptr [g_menuRestoreC_00543ab0]
        push     edx
        jmp      short L_8117
    L_80de:
        mov      eax, dword ptr [g_menuRestoreB_00543aac]
        jmp      short L_80ea
    L_80e5:
        mov      eax, dword ptr [g_byte_00543ab4]
    L_80ea:
        test     eax, eax
        mov      eax, OFFSET g_dispatchSave820_004f42d8
        jne      short L_810e
        mov      eax, OFFSET g_dispatchSave821_004f42dc
        push     eax
        jmp      short L_813b
    L_80fb:
        mov      eax, dword ptr [g_menuPageDispatch_00543a98]
        test     eax, eax
        mov      eax, OFFSET g_dispatchSave874_004f61a0
        jne      short L_810e
        mov      eax, OFFSET g_dispatchSave873_004f6190
    L_810e:
        push     eax
        jmp      short L_813b
    L_8111:
        mov      eax, dword ptr [g_menuRestoreA_00543aa0]
        push     eax
    L_8117:
        push     OFFSET g_dispatchSave872_004f6164
        push     OFFSET g_dispatchSave1479_00ab41c8
        call     Helper_Sprintf
        add      esp, 0xc
        push     OFFSET g_dispatchSave1479_00ab41c8
        jmp      short L_813b
    L_8130:
        mov      ecx, dword ptr [g_menuRestoreD_00543a9c]
        mov      edx, dword ptr [esp + ecx*4 + 8]
        push     edx
    L_813b:
        push     esi
        call     Menu_FillColonField
        add      esp, 8
    L_8144:
        mov      eax, dword ptr [esi + 8]
        add      esi, 8
        test     eax, eax
        jne      L_80c2
    L_8152:
        mov      eax, dword ptr [g_dispatchSave1490_00ab4328]
        push     eax
        push     OFFSET g_menuPageVar_004f5328
        call     DrawMenu
        mov      eax, dword ptr [g_dispatchSave1492_00ab4358]
        add      esp, 8
        pop      esi
        pop      ebx
        add      esp, 0x18
        ret
    L_080_tail:
        /* 8-entry jump table at 0x4b8170 (belongs to Helper_GSM_Options's outer switch). */
        _emit 0x65
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0xd8
        _emit 0x7e
        _emit 0x4b
        _emit 0x00
        _emit 0x3b
        _emit 0x7f
        _emit 0x4b
        _emit 0x00
        _emit 0xa1
        _emit 0x7f
        _emit 0x4b
        _emit 0x00
        _emit 0x0e
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0x2b
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0x48
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0x80
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        /* 64-byte index array at 0x4b8190 (also Helper_GSM_Options). */
        _emit 0x00
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x07
        _emit 0x01
        _emit 0x02
        _emit 0x03
        _emit 0x04
        _emit 0x05
        _emit 0x06
        _emit 0x90
    L_080_jmptbl:
        /* Our 6-entry jump table (case0..case5). */
        _emit 0x11
        _emit 0x81
        _emit 0x4b
        _emit 0x00
        _emit 0x30
        _emit 0x81
        _emit 0x4b
        _emit 0x00
        _emit 0xd5
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0xde
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0xe5
        _emit 0x80
        _emit 0x4b
        _emit 0x00
        _emit 0xfb
        _emit 0x80
        _emit 0x4b
        _emit 0x00
    }
}
