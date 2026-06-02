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

extern unsigned int g_arr_00fa0de0;
extern unsigned int g_iat_GetLastError;
extern unsigned int g_iat_ReadFile;
extern void Crt_doserrno(void);
extern void Crt_errno(void);
extern void DosMapErr(void);
extern void LseekImpl(void);

__declspec(naked) void CrtReadCrlfDecode(void)
{
    __asm {
        mov      eax, dword ptr [esp + 0xc]
        sub      esp, 0xc
        push     ebx
        push     ebp
        push     esi
        push     edi
        mov      edi, dword ptr [esp + 0x24]
        xor      ebp, ebp
        test     eax, eax
        mov      edx, edi
        je       L_925b
        mov      eax, dword ptr [esp + 0x20]
        mov      ecx, eax
        and      eax, 0x1f
        sar      ecx, 5
        lea      ebx, [eax + eax*8]
        mov      eax, dword ptr [ecx*4 + g_arr_00fa0de0]
        lea      esi, [ecx*4 + g_arr_00fa0de0]
        shl      ebx, 2
        mov      dword ptr [esp + 0x18], esi
        lea      ecx, [ebx + eax]
        mov      al, byte ptr [ebx + eax + 4]
        test     al, 2
        jne      L_925b
        test     al, 0x48
        je       short L_90b3
        mov      al, byte ptr [ecx + 5]
        cmp      al, 0xa
        je       short L_90b3
        mov      byte ptr [edi], al
        mov      eax, dword ptr [esp + 0x28]
        mov      ecx, dword ptr [esi]
        dec      eax
        lea      edx, [edi + 1]
        mov      ebp, 1
        mov      dword ptr [esp + 0x28], eax
        mov      byte ptr [ebx + ecx + 5], 0xa
    L_90b3:
        mov      ecx, dword ptr [esp + 0x28]
        lea      eax, [esp + 0x14]
        push     0
        push     eax
        push     ecx
        push     edx
        mov      edx, dword ptr [esi]
        mov      eax, dword ptr [ebx + edx]
        push     eax
        call     dword ptr [g_iat_ReadFile]
        test     eax, eax
        jne      short L_9119
        call     dword ptr [g_iat_GetLastError]
        cmp      eax, 5
        jne      short L_90fc
        call     Crt_errno
        mov      dword ptr [eax], 9
        call     Crt_doserrno
        mov      dword ptr [eax], 5
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    L_90fc:
        cmp      eax, 0x6d
        je       L_925b
        push     eax
        call     DosMapErr
        add      esp, 4
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    L_9119:
        mov      ecx, dword ptr [esi]
        mov      edx, dword ptr [esp + 0x14]
        add      ebp, edx
        mov      al, byte ptr [ebx + ecx + 4]
        lea      ecx, [ebx + ecx + 4]
        test     al, 0x80
        je       L_9251
        test     edx, edx
        je       short L_913e
        cmp      byte ptr [edi], 0xa
        jne      short L_913e
        or       al, 4
        jmp      short L_9140
    L_913e:
        and      al, 0xfb
    L_9140:
        mov      byte ptr [ecx], al
        mov      eax, dword ptr [esp + 0x24]
        add      ebp, eax
        mov      esi, edi
        cmp      eax, ebp
        mov      dword ptr [esp + 0x28], ebp
        jae      L_924b
    L_9156:
        mov      al, byte ptr [edi]
        cmp      al, 0x1a
        je       L_9235
        cmp      al, 0xd
        je       short L_916d
        mov      byte ptr [esi], al
        inc      esi
        inc      edi
        jmp      short L_9219
    L_916d:
        dec      ebp
        cmp      edi, ebp
        jae      short L_918d
        cmp      byte ptr [edi + 1], 0xa
        jne      short L_9183
        add      edi, 2
        mov      byte ptr [esi], 0xa
        jmp      short L_9218
    L_9183:
        mov      byte ptr [esi], 0xd
        inc      esi
        inc      edi
        jmp      short L_9219
    L_918d:
        mov      ecx, dword ptr [esp + 0x18]
        xor      ebp, ebp
        lea      edx, [esp + 0x14]
        push     ebp
        push     edx
        mov      edx, dword ptr [ecx]
        lea      eax, [esp + 0x1b]
        push     1
        push     eax
        mov      eax, dword ptr [ebx + edx]
        push     eax
        inc      edi
        call     dword ptr [g_iat_ReadFile]
        test     eax, eax
        jne      short L_91b9
        call     dword ptr [g_iat_GetLastError]
        mov      ebp, eax
    L_91b9:
        test     ebp, ebp
        jne      short L_9215
        mov      eax, dword ptr [esp + 0x14]
        test     eax, eax
        je       short L_9215
        mov      ecx, dword ptr [esp + 0x18]
        mov      edx, dword ptr [ecx]
        test     byte ptr [ebx + edx + 4], 0x48
        je       short L_91ea
        mov      al, byte ptr [esp + 0x13]
        cmp      al, 0xa
        jne      short L_91de
        mov      byte ptr [esi], al
        jmp      short L_9218
    L_91de:
        mov      byte ptr [esi], 0xd
        mov      ecx, dword ptr [ecx]
        inc      esi
        mov      byte ptr [ebx + ecx + 5], al
        jmp      short L_9219
    L_91ea:
        cmp      esi, dword ptr [esp + 0x24]
        jne      short L_91fc
        cmp      byte ptr [esp + 0x13], 0xa
        jne      short L_91fc
        mov      byte ptr [esi], 0xa
        jmp      short L_9218
    L_91fc:
        mov      edx, dword ptr [esp + 0x20]
        push     1
        push     -1
        push     edx
        call     LseekImpl
        mov      al, byte ptr [esp + 0x1f]
        add      esp, 0xc
        cmp      al, 0xa
        je       short L_9219
    L_9215:
        mov      byte ptr [esi], 0xd
    L_9218:
        inc      esi
    L_9219:
        mov      ebp, dword ptr [esp + 0x28]
        cmp      edi, ebp
        jb       L_9156
        sub      esi, dword ptr [esp + 0x24]
        mov      ebp, esi
        mov      eax, ebp
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    L_9235:
        mov      eax, dword ptr [esp + 0x18]
        mov      ecx, dword ptr [eax]
        mov      al, byte ptr [ebx + ecx + 4]
        test     al, 0x40
        lea      ebx, [ebx + ecx + 4]
        jne      short L_924b
        or       al, 2
        mov      byte ptr [ebx], al
    L_924b:
        sub      esi, dword ptr [esp + 0x24]
        mov      ebp, esi
    L_9251:
        mov      eax, ebp
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    L_925b:
        pop      edi
        pop      esi
        pop      ebp
        xor      eax, eax
        pop      ebx
        add      esp, 0xc
        ret
    }
}
