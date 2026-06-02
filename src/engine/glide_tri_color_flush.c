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

extern unsigned int g_byte_004f4b4c;
extern f32 g_glideTable2[];
extern f32 g_glideTable1[];
extern f32 g_glideTable3[];
extern u32 g_glideD0;
extern int g_renderer1_active;
extern u8 g_glideE8;
extern int g_renderer1_busy;
extern int g_renderer1_surface;
extern unsigned int g_dispatchSave1632_007b0004;
extern unsigned int g_dispatchSave1652_007b0074;
extern unsigned int g_dispatchSave1653_007b0078;

__declspec(naked) void GlideTriColorFlush_004b46f0(void)
{
    __asm {
        mov      eax, dword ptr [g_renderer1_active]
        sub      esp, 0xb4
        test     eax, eax
        je       L_4992
        mov      eax, dword ptr [g_renderer1_surface]
        test     eax, eax
        je       L_4992
        mov      eax, dword ptr [g_renderer1_busy]
        test     eax, eax
        jne      L_4992
        push     ebx
        mov      bl, byte ptr [esp + 0xbc]
        cmp      bl, 0x10
        jbe      L_4733
        xor      bl, bl
        mov      byte ptr [esp + 0xbc], bl
    L_4733:
        cmp      byte ptr [g_byte_004f4b4c], bl
        je       L_4764
        mov      eax, dword ptr [esp + 0xbc]
        push     OFFSET g_glideD0
        and      eax, 0xff
        push     3
        mov      ecx, dword ptr [eax*4 + g_glideTable2]
        push     ecx
        push     0
        call     dword ptr [g_dispatchSave1652_007b0074]
        mov      byte ptr [g_byte_004f4b4c], bl
    L_4764:
        mov      ebx, dword ptr [esp + 0xc0]
        mov      al, byte ptr [g_glideE8]
        cmp      bl, al
        je       L_47ad
        test     bl, bl
        jne      L_4782
        push     0
        push     4
        push     0
        push     4
        jmp      L_47a1
    L_4782:
        cmp      bl, 0xff
        jne      L_4791
        push     0
        push     4
        push     4
        push     4
        jmp      L_47a1
    L_4791:
        test     al, al
        je       L_4799
        cmp      al, 0xff
        jne      L_47a7
    L_4799:
        push     0
        push     0
        push     1
        push     5
    L_47a1:
        call     dword ptr [g_dispatchSave1632_007b0004]
    L_47a7:
        mov      byte ptr [g_glideE8], bl
    L_47ad:
        mov      eax, dword ptr [esp + 0xc8]
        mov      edx, dword ptr [esp + 0xc4]
        mov      dword ptr [esp + 0x80], eax
        and      ebx, 0xff
        movsx    eax, word ptr [esp + 0xd4]
        fld      dword ptr [ebx*4 + g_glideTable1]
        fst      dword ptr [esp + 0x5c]
        fst      dword ptr [esp + 0x20]
        fstp     dword ptr [esp + 0x98]
        mov      ecx, eax
        mov      dword ptr [esp + 0x7c], edx
        sar      ecx, 0xa
        and      ecx, 0x1f
        mov      edx, eax
        sar      edx, 5
        fld      dword ptr [ecx*4 + g_glideTable3]
        and      edx, 0x1f
        and      eax, 0x1f
        fstp     dword ptr [esp + 0x88]
        fld      dword ptr [edx*4 + g_glideTable3]
        mov      ecx, dword ptr [esp + 0xd0]
        mov      edx, dword ptr [esp + 0xd8]
        fstp     dword ptr [esp + 0x8c]
        fld      dword ptr [eax*4 + g_glideTable3]
        mov      eax, dword ptr [esp + 0xcc]
        and      ecx, 0xff
        fstp     dword ptr [esp + 0x90]
        and      eax, 0xff
        mov      dword ptr [esp + 4], edx
        mov      dword ptr [esp + 0x60], 0x3f800000
        mov      dword ptr [esp + 0x24], 0x3f800000
        fld      dword ptr [eax*4 + g_glideTable1]
        mov      eax, dword ptr [esp + 0xdc]
        mov      dword ptr [esp + 0x9c], 0x3f800000
        fstp     dword ptr [esp + 0xa0]
        fld      dword ptr [ecx*4 + g_glideTable1]
        mov      dword ptr [esp + 8], eax
        movsx    eax, word ptr [esp + 0xe8]
        fstp     dword ptr [esp + 0xa4]
        mov      ecx, eax
        mov      edx, eax
        sar      ecx, 0xa
        and      ecx, 0x1f
        and      eax, 0x1f
        sar      edx, 5
        fld      dword ptr [ecx*4 + g_glideTable3]
        and      edx, 0x1f
        mov      ecx, dword ptr [esp + 0xe4]
        fstp     dword ptr [esp + 0x10]
        fld      dword ptr [edx*4 + g_glideTable3]
        mov      edx, dword ptr [esp + 0xec]
        and      ecx, 0xff
        fstp     dword ptr [esp + 0x14]
        fld      dword ptr [eax*4 + g_glideTable3]
        mov      eax, dword ptr [esp + 0xe0]
        mov      dword ptr [esp + 0x40], edx
        fstp     dword ptr [esp + 0x18]
        and      eax, 0xff
        fld      dword ptr [eax*4 + g_glideTable1]
        mov      eax, dword ptr [esp + 0xf0]
        fstp     dword ptr [esp + 0x28]
        fld      dword ptr [ecx*4 + g_glideTable1]
        mov      dword ptr [esp + 0x44], eax
        movsx    eax, word ptr [esp + 0xfc]
        fstp     dword ptr [esp + 0x2c]
        mov      ecx, eax
        mov      edx, eax
        sar      ecx, 0xa
        and      ecx, 0x1f
        and      eax, 0x1f
        sar      edx, 5
        fld      dword ptr [ecx*4 + g_glideTable3]
        and      edx, 0x1f
        fstp     dword ptr [esp + 0x4c]
        fld      dword ptr [edx*4 + g_glideTable3]
        fstp     dword ptr [esp + 0x50]
        fld      dword ptr [eax*4 + g_glideTable3]
        mov      eax, dword ptr [esp + 0xf4]
        fstp     dword ptr [esp + 0x54]
        and      eax, 0xff
        fld      dword ptr [eax*4 + g_glideTable1]
        mov      ecx, dword ptr [esp + 0xf8]
        lea      edx, [esp + 0x40]
        fstp     dword ptr [esp + 0x64]
        and      ecx, 0xff
        lea      eax, [esp + 4]
        push     edx
        push     eax
        fld      dword ptr [ecx*4 + g_glideTable1]
        lea      ecx, [esp + 0x84]
        fstp     dword ptr [esp + 0x70]
        push     ecx
        call     dword ptr [g_dispatchSave1653_007b0078]
        pop      ebx
    L_4992:
        add      esp, 0xb4
        ret
    }
}
