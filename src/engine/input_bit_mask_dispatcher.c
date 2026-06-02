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

extern void Input_PollJoystick(void);

__declspec(naked) void Input_PollPlayerJoystick(void)
{
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        mov     eax, dword ptr [esi*4 + 0x00543B68]
        cmp     eax, -1
        je      L_ibmd_ret
        push    eax
        call    Input_PollJoystick
        add     esp, 4
        test    eax, 0x40000000
        je      L_ibmd_skip1
        mov     ecx, dword ptr [esi*8 + 0x004F4DCC]
        mov     edx, dword ptr [esi*8 + 0x004F4DC8]
        or      dword ptr [ecx], edx
    L_ibmd_skip1:
        test    eax, 0x80000000
        je      L_ibmd_skip2
        mov     ecx, dword ptr [esi*8 + 0x004F4DDC]
        mov     edx, dword ptr [esi*8 + 0x004F4DD8]
        or      dword ptr [ecx], edx
    L_ibmd_skip2:
        test    eax, 0x10000000
        je      L_ibmd_skip3
        mov     ecx, dword ptr [esi*8 + 0x004F4DEC]
        mov     edx, dword ptr [esi*8 + 0x004F4DE8]
        or      dword ptr [ecx], edx
    L_ibmd_skip3:
        test    eax, 0x20000000
        je      L_ibmd_skip4
        mov     ecx, dword ptr [esi*8 + 0x004F4DFC]
        mov     edx, dword ptr [esi*8 + 0x004F4DF8]
        or      dword ptr [ecx], edx
    L_ibmd_skip4:
        mov     ecx, dword ptr [esi*4 + 0x00543B20]
        test    ecx, ecx
        je      L_ibmd_skip_b1
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b1
        mov     ecx, dword ptr [esi*8 + 0x004F4E0C]
        mov     edx, dword ptr [esi*8 + 0x004F4E08]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b1:
        mov     ecx, dword ptr [esi*4 + 0x00543B28]
        test    ecx, ecx
        je      L_ibmd_skip_b2
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b2
        mov     ecx, dword ptr [esi*8 + 0x004F4E1C]
        mov     edx, dword ptr [esi*8 + 0x004F4E18]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b2:
        mov     ecx, dword ptr [esi*4 + 0x00543B30]
        test    ecx, ecx
        je      L_ibmd_skip_b3
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b3
        mov     ecx, dword ptr [esi*8 + 0x004F4E2C]
        mov     edx, dword ptr [esi*8 + 0x004F4E28]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b3:
        mov     ecx, dword ptr [esi*4 + 0x00543B38]
        test    ecx, ecx
        je      L_ibmd_skip_b4
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b4
        mov     ecx, dword ptr [esi*8 + 0x004F4E3C]
        mov     edx, dword ptr [esi*8 + 0x004F4E38]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b4:
        mov     ecx, dword ptr [esi*4 + 0x00543B40]
        test    ecx, ecx
        je      L_ibmd_skip_b5
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b5
        mov     ecx, dword ptr [esi*8 + 0x004F4E4C]
        mov     edx, dword ptr [esi*8 + 0x004F4E48]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b5:
        mov     ecx, dword ptr [esi*4 + 0x00543B48]
        test    ecx, ecx
        je      L_ibmd_skip_b6
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b6
        mov     ecx, dword ptr [esi*8 + 0x004F4E5C]
        mov     edx, dword ptr [esi*8 + 0x004F4E58]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b6:
        mov     ecx, dword ptr [esi*4 + 0x00543B50]
        test    ecx, ecx
        je      L_ibmd_skip_b7
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b7
        mov     ecx, dword ptr [esi*8 + 0x004F4E6C]
        mov     edx, dword ptr [esi*8 + 0x004F4E68]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b7:
        mov     ecx, dword ptr [esi*4 + 0x00543B58]
        test    ecx, ecx
        je      L_ibmd_skip_b8
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b8
        mov     ecx, dword ptr [esi*8 + 0x004F4E7C]
        mov     edx, dword ptr [esi*8 + 0x004F4E78]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b8:
        mov     ecx, dword ptr [esi*4 + 0x00543B60]
        test    ecx, ecx
        je      L_ibmd_ret
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_ret
        mov     eax, dword ptr [esi*8 + 0x004F4E8C]
        mov     ecx, dword ptr [esi*8 + 0x004F4E88]
        or      dword ptr [eax], ecx
    L_ibmd_ret:
        pop     esi
        ret
    }
}
