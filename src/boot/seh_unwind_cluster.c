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

extern unsigned int g_sehUnwindBase;
extern void func_004d12de(void);

__declspec(naked) void SehUnwindCluster(void)
{
    __asm {
    /* Helper 1: __try frame setup */
    L_6ae0:
        push     ebp
        mov      ebp, esp
        push     ebx
        push     esi
        push     edi
        push     ebp
        push     0
        push     0
        push     OFFSET L_6af8
        push     dword ptr [ebp + 8]
        call     func_004d12de
    L_6af8:
        pop      ebp
        pop      edi
        pop      esi
        pop      ebx
        mov      esp, ebp
        pop      ebp
        ret
    /* Helper 2: SEH filter check */
    L_6b00:
        mov      ecx, dword ptr [esp + 4]
        test     dword ptr [ecx + 4], 6
        mov      eax, 1
        je       short L_6b21
        mov      eax, dword ptr [esp + 8]
        mov      edx, dword ptr [esp + 0x10]
        mov      dword ptr [edx], eax
        mov      eax, 3
    L_6b21:
        ret
    /* Helper 3: __finally walker */
    L_6b22:
        push     ebx
        push     esi
        push     edi
        mov      eax, dword ptr [esp + 0x10]
        push     eax
        push     -2
        push     OFFSET L_6b00
        push     dword ptr fs:[0]
        mov      dword ptr fs:[0], esp
    L_6b3f:
        mov      eax, dword ptr [esp + 0x20]
        mov      ebx, dword ptr [eax + 8]
        mov      esi, dword ptr [eax + 0xc]
        cmp      esi, -1
        je       short L_6b7c
        cmp      esi, dword ptr [esp + 0x24]
        je       short L_6b7c
        lea      esi, [esi + esi*2]
        mov      ecx, dword ptr [ebx + esi*4]
        mov      dword ptr [esp + 8], ecx
        mov      dword ptr [eax + 0xc], ecx
        cmp      dword ptr [ebx + esi*4 + 4], 0
        jne      short L_6b7a
        push     0x101
        mov      eax, dword ptr [ebx + esi*4 + 8]
        call     L_6bb6
        call     dword ptr [ebx + esi*4 + 8]
    L_6b7a:
        jmp      short L_6b3f
    L_6b7c:
        pop      dword ptr fs:[0]
        add      esp, 0xc
        pop      edi
        pop      esi
        pop      ebx
        ret
    /* Helper 4: SEH magic-marker probe */
        xor      eax, eax
        mov      ecx, dword ptr fs:[0]
        cmp      dword ptr [ecx + 4], OFFSET L_6b00
        jne      short L_6bac
        mov      edx, dword ptr [ecx + 0xc]
        mov      edx, dword ptr [edx + 0xc]
        cmp      dword ptr [ecx + 8], edx
        jne      short L_6bac
        mov      eax, 1
    L_6bac:
        ret
    /* Helper 5: dual-entry __exhandler register */
        push     ebx
        push     ecx
        mov      ebx, OFFSET g_sehUnwindBase
        jmp      short L_6bc0
    L_6bb6:
        push     ebx
        push     ecx
        mov      ebx, OFFSET g_sehUnwindBase
        mov      ecx, dword ptr [ebp + 8]
    L_6bc0:
        mov      dword ptr [ebx + 8], ecx
        mov      dword ptr [ebx + 4], eax
        mov      dword ptr [ebx + 0xc], ebp
        pop      ecx
        pop      ebx
        ret      4
        int      3
        int      3
        /* Magic SEH marker bytes "VC20XC00" between helpers 5 and 6. */
        _emit    0x56
        _emit    0x43
        _emit    0x32
        _emit    0x30
        _emit    0x58
        _emit    0x43
        _emit    0x30
        _emit    0x30
    /* Helper 6: __CallSEHHandler */
        push     ebp
        mov      ebp, esp
        sub      esp, 8
        push     ebx
        push     esi
        push     edi
        push     ebp
        cld
        mov      ebx, dword ptr [ebp + 0xc]
        mov      eax, dword ptr [ebp + 8]
        test     dword ptr [eax + 4], 6
        jne      short L_6c78
        mov      dword ptr [ebp - 8], eax
        mov      eax, dword ptr [ebp + 0x10]
        mov      dword ptr [ebp - 4], eax
        lea      eax, [ebp - 8]
        mov      dword ptr [ebx - 4], eax
        mov      esi, dword ptr [ebx + 0xc]
        mov      edi, dword ptr [ebx + 8]
    L_6c0b:
        cmp      esi, -1
        je       short L_6c71
        lea      ecx, [esi + esi*2]
        cmp      dword ptr [edi + ecx*4 + 4], 0
        je       short L_6c5f
        push     esi
        push     ebp
        lea      ebp, [ebx + 0x10]
        call     dword ptr [edi + ecx*4 + 4]
        pop      ebp
        pop      esi
        mov      ebx, dword ptr [ebp + 0xc]
        or       eax, eax
        je       short L_6c5f
        js       short L_6c6a
        mov      edi, dword ptr [ebx + 8]
        push     ebx
        call     L_6ae0
        add      esp, 4
        lea      ebp, [ebx + 0x10]
        push     esi
        push     ebx
        call     L_6b22
        add      esp, 8
        lea      ecx, [esi + esi*2]
        push     1
        mov      eax, dword ptr [edi + ecx*4 + 8]
        call     L_6bb6
        mov      eax, dword ptr [edi + ecx*4]
        mov      dword ptr [ebx + 0xc], eax
        call     dword ptr [edi + ecx*4 + 8]
    L_6c5f:
        mov      edi, dword ptr [ebx + 8]
        lea      ecx, [esi + esi*2]
        mov      esi, dword ptr [edi + ecx*4]
        jmp      short L_6c0b
    L_6c6a:
        mov      eax, 0
        jmp      short L_6c8d
    L_6c71:
        mov      eax, 1
        jmp      short L_6c8d
    L_6c78:
        push     ebp
        lea      ebp, [ebx + 0x10]
        push     -1
        push     ebx
        call     L_6b22
        add      esp, 8
        pop      ebp
        mov      eax, 1
    L_6c8d:
        pop      ebp
        pop      edi
        pop      esi
        pop      ebx
        mov      esp, ebp
        pop      ebp
        ret
    /* Helper 7: __exhandler thin wrapper */
        push     ebp
        mov      ecx, dword ptr [esp + 8]
        mov      ebp, dword ptr [ecx]
        mov      eax, dword ptr [ecx + 0x1c]
        push     eax
        mov      eax, dword ptr [ecx + 0x18]
        push     eax
        call     L_6b22
        add      esp, 8
        pop      ebp
        ret      4
    }
}
