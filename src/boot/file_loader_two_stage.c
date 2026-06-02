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

extern unsigned int g_dispatchSave891_004d5040;
extern unsigned int g_dispatchSave892_004d504c;
extern unsigned int g_dispatchVar40_004d505c;
extern unsigned int g_dispatchSave893_004d5060;
extern unsigned int g_dispatchSave565_004d506c;
extern unsigned int g_fileLoaderArr_00524158;
extern unsigned int g_fileLoaderState_00524358;
extern void FSYS_fclose(void);
extern void FSYS_fopen(void);
extern void FSYS_fread(void);
extern void FSYS_fseek(void);
extern void FSYS_ftell(void);
extern void Helper_Sprintf(void);
extern void ListInitLoop(void);
extern void LoadArgPushCall(void);
extern void MemcpyByteN(void);
extern void ShowErrorMessage(void);

__declspec(naked) void Anim_LoadPackFile(void)
{
    __asm {
        sub     esp, 0x100
        _emit   0x8D
        _emit   0x44
        _emit   0x24
        _emit   0x00
        push    ebx
        push    ebp
        push    esi
        mov     esi, dword ptr [esp + 0x110]
        push    edi
        push    esi
        push    offset g_dispatchSave565_004d506c
        push    offset g_dispatchSave893_004d5060
        push    eax
        call    Helper_Sprintf
        add     esp, 0x10
        lea     ecx, [esp + 0x10]
        push    offset g_dispatchVar40_004d505c
        push    ecx
        call    FSYS_fopen
        mov     ebx, eax
        add     esp, 8
        test    ebx, ebx
        jne     L_fl_have_f1
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x100
        ret
    L_fl_have_f1:
        push    2
        push    0
        push    ebx
        call    FSYS_fseek
        add     esp, 0xC
        push    ebx
        call    FSYS_ftell
        add     esp, 4
        mov     ebp, eax
        push    0
        push    0
        push    ebx
        call    FSYS_fseek
        add     esp, 0xC
        push    ebp
        call    LoadArgPushCall
        add     esp, 4
        mov     dword ptr [g_fileLoaderState_00524358], eax
        test    eax, eax
        jne     L_fl_have_buf
        push    offset g_dispatchSave892_004d504c
        call    ShowErrorMessage
        mov     eax, dword ptr [g_fileLoaderState_00524358]
        add     esp, 4
        test    eax, eax
        jne     L_fl_have_buf
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x100
        ret
    L_fl_have_buf:
        push    esi
        push    offset g_dispatchSave565_004d506c
        lea     edx, [esp + 0x98]
        push    offset g_dispatchSave891_004d5040
        push    edx
        call    Helper_Sprintf
        add     esp, 0x10
        lea     eax, [esp + 0x90]
        push    offset g_dispatchVar40_004d505c
        push    eax
        call    FSYS_fopen
        mov     esi, eax
        add     esp, 8
        test    esi, esi
        jne     L_fl_have_f2
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x100
        ret
    L_fl_have_f2:
        push    2
        push    0
        push    esi
        call    FSYS_fseek
        add     esp, 0xC
        push    esi
        call    FSYS_ftell
        mov     edi, eax
        add     esp, 4
        cmp     edi, ebp
        jle     L_fl_size_ok
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x100
        ret
    L_fl_size_ok:
        push    0
        push    0
        push    esi
        call    FSYS_fseek
        mov     ecx, dword ptr [g_fileLoaderState_00524358]
        add     esp, 0xC
        push    esi
        push    edi
        push    1
        push    ecx
        call    FSYS_fread
        add     esp, 0x10
        push    esi
        call    FSYS_fclose
        mov     edx, dword ptr [g_fileLoaderState_00524358]
        add     esp, 4
        push    0x200
        push    edx
        push    offset g_fileLoaderArr_00524158
        call    MemcpyByteN
        add     esp, 0xC
        call    ListInitLoop
        mov     esi, dword ptr [g_fileLoaderState_00524358]
        xor     eax, eax
        mov     ax, word ptr [esi + 0x200]
        lea     ecx, [esi + 0x200]
        mov     edx, eax
        add     ecx, 2
        and     edx, 0x8000
        cmp     eax, 0xFFFF
        je      L_fl_terminator
    L_fl_loop:
        and     eax, 0x7FFF
        add     ecx, 2
        add     ecx, 2
        lea     eax, [eax + eax*2]
        mov     dword ptr [eax*4 + 0x004FFDEC], esi
        mov     edi, dword ptr [eax*4 + 0x004FFDF4]
        and     edi, 0xFFFF7FFF
        add     edi, edx
        mov     dword ptr [eax*4 + 0x004FFDF4], edi
        xor     eax, eax
        mov     ax, word ptr [ecx - 4]
        add     esi, eax
        xor     eax, eax
        mov     ax, word ptr [ecx - 2]
        mov     edx, eax
        and     edx, 0x8000
        cmp     eax, 0xFFFF
        jne     L_fl_loop
        mov     esi, dword ptr [g_fileLoaderState_00524358]
    L_fl_terminator:
        push    ebx
        push    ebp
        push    1
        push    esi
        call    FSYS_fread
        add     esp, 0x10
        push    ebx
        call    FSYS_fclose
        mov     eax, dword ptr [g_fileLoaderState_00524358]
        add     esp, 4
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x100
        ret
    }
}
