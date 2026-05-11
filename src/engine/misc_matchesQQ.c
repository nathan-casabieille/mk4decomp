/**
 * Fifty-second batch of one-off matches.
 *
 * Seven 81-byte + four 82-byte + four 83-byte stubs - all unique
 * signatures, no clusters. Mostly guarded-call chains, scaled
 * load/store dispatchers, double-push state wrappers, and
 * bit-test branchers on g_state_0054208c.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_framePauseFlag;
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
extern unsigned int g_pendingNodeType;

extern void StoreTwoCall_0049cb40(void);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void TimeBudgetSubCallChain_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void func_00407510(void);
extern void func_00477710(void);
extern void func_00426230(void);
extern void func_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void func_00492450(void);
extern void func_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void func_00492280(void);
extern void func_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void func_0043a950(void);
extern void func_004363f0(void);
extern void Wrapper_00436490(void);
extern void func_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void func_0047a840(void);
extern void func_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void func_00476880(void);
extern void Thunk_004bd5c0(void);
extern void func_00427470(void);
extern void func_004274f0(void);
extern void func_00457ad0(void);
extern void func_00457900(void);
extern void func_004903f0(void);
extern void func_004917e0(void);
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
extern void IterStepDualStore_00490b40(void);
extern void ScaledXorStore_004900f0(void);
extern void func_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void func_0042b930(void);
extern void func_004089e0(void);
extern void func_004b8fa0(void);
extern void func_00475990(void);
extern void func_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void func_0048bc40(void);
extern void func_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void func_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void func_0048f350(void);
extern void func_004339c0(void);
extern void func_0046f7a0(void);
extern void func_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void func_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void func_00406530(void);
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

/* @addr 0x00426d30 (81b)
 *   Push g_eventQueueEnd on mstack; replace it with 0x4e2670>>2;
 *   push 0x23c and 0x00426da0 as args; call StoreTwoCall_0049cb40;
 *   pop g_eventQueueEnd; pop mstack; ret.
 *   The 0x426da0 imm is the in-body label of func_00426d90.
 */
__declspec(naked) void PushSetEventQueueCallStore_00426d30(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_eventQueueEnd]
        inc     eax
        mov     edx, 0x004e2670
        mov     dword ptr [g_state_004d57ac], eax
        push    0x23c
        shr     edx, 2
        mov     dword ptr [eax*4 + 0], ecx
        push    0x00426da0
        mov     dword ptr [g_eventQueueEnd], edx
        call    StoreTwoCall_0049cb40
        mov     eax, dword ptr [g_state_004d57ac]
        add     esp, 8
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x00431cf0 (81b)
 *   call func_00407510; if pause: ret;
 *   call TimeBudgetSubCallChain; if pause: ret;
 *   push g_eventQueueWorkType, g_data_00542084;
 *   call Mul10Tail_00404af0; store to g_eventQueueWorkType;
 *   push g_acc_00542078, g_data_00542084;
 *   call Mul10Tail_00404af0; store to g_acc_00542078; ret.
 */
__declspec(naked) void GuardedTimeBudgetDualMul10_00431cf0(void) {
    __asm {
        call    func_00407510
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   42h
        call    TimeBudgetSubCallChain_00431d50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   34h
        mov     eax, dword ptr [g_eventQueueWorkType]
        mov     ecx, dword ptr [g_data_00542084]
        push    eax
        push    ecx
        call    Mul10Tail_00404af0
        mov     edx, dword ptr [g_acc_00542078]
        add     esp, 8
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     eax, dword ptr [g_data_00542084]
        push    edx
        push    eax
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_acc_00542078], eax
        ret
    }
}

/* @addr 0x00472db0 (81b)
 *   eax = g_baseSel_00542060[4*idx + 0x68] → g_data_00542050;
 *   ecx = eax[4*idx + 0x30] → g_walkCallback;
 *   call SetJmp_0049cb90; if pause: ret;
 *   eax = arg0[esp+4] >> 2 → g_data_00542050;
 *   edx = [eax*4]; ++eax → g_xformEntityIdx, g_data_00542050;
 *   jmp Thunk_0049cbd0.
 */
__declspec(naked) void ScaledIdxLoadCallTailThunk_00472db0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x68]
        mov     dword ptr [g_data_00542050], eax
        mov     ecx, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_walkCallback], ecx
        call    SetJmp_0049cb90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   24h
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_data_00542050], eax
        mov     edx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_data_00542050], eax
        jmp     Thunk_0049cbd0
        ret
    }
}

/* @addr 0x004776b0 (81b)
 *   Push g_scaledInit and g_cj_0054205c onto mstack;
 *   set g_walkCallback=0x63, g_state_0053a718=0x63;
 *   set g_scaledInit_00542044 = 0x4ece68>>2; jmp func_00477710.
 */
__declspec(naked) void DoublePushWalkInitJmp_004776b0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [g_cj_0054205c]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     eax, 0x63
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_0053a718], eax
        mov     eax, 0x004ece68
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     func_00477710
    }
}

/* @addr 0x004907b0 (81b)
 *   Push g_cj_0054205c on mstack; set it to
 *   g_baseSel_00542060[edx*4 + 0x38]; call ScaledZeroFour;
 *   if pause: ret; pop g_cj_0054205c; pop mstack; ret.
 */
__declspec(naked) void PushSetCallPopCj_004907b0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_cj_0054205c]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [edx*4 + 0x38]
        mov     dword ptr [g_cj_0054205c], eax
        call    ScaledZeroFour_00490740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_cj_0054205c], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x00490890 (81b)
 *   eax = arg0[esp+4]>>2 → g_scaledInit; ecx=[eax*4]; ++eax →
 *   g_scaledInit; mov eax,g_cj_0054205c; g_walkCallback=ecx;
 *   [eax*4+0x70]=ecx. Then eax=g_scaledInit, edx=g_cj_0054205c,
 *   ecx=[eax*4]; ++eax → g_scaledInit; g_walkCallback=ecx;
 *   [edx*4+0x4c]=ecx; ret.
 */
__declspec(naked) void ScaledFromArgDualSibStore_00490890(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x70], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [edx*4 + 0x4c], ecx
        ret
    }
}

/* @addr 0x00491230 (81b)
 *   ecx = g_scaledInit; eax = [ecx*4+0x54] → g_walkCallback;
 *   ecx = [ecx*4+0x5c]; push eax, eax; g_data_00542070 = ecx;
 *   call Mul10Tail_00404af0; pop esp; g_walkCallback = ret;
 *   eax = g_data_00542070; push eax, eax;
 *   call Mul10Tail_00404af0; pop esp; add return to walkCallback;
 *   g_data_00542070 = old (eax); g_walkCallback = sum; ret.
 */
__declspec(naked) void DualMul10AccCj_00491230(void) {
    __asm {
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [ecx*4 + 0x54]
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [ecx*4 + 0x5c]
        push    eax
        push    eax
        mov     dword ptr [g_data_00542070], ecx
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_data_00542070]
        push    eax
        push    eax
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_walkCallback]
        add     esp, 8
        add     ecx, eax
        mov     dword ptr [g_data_00542070], eax
        mov     dword ptr [g_walkCallback], ecx
        ret
    }
}

/* @addr 0x004261d0 (82b)
 *   call func_00426230; if pause: ret;
 *   g_walkCallback &= 0x7070; g_eventQueueWorkType = 0xffff;
 *   if walkCallback != 0: set bit0 of g_state_0054208c, ret;
 *   else g_data_00542070 &= 0x77;
 *   if zero: clear bit0 of g_state_0054208c, ret;
 *   else: set bit0 of g_state_0054208c, ret.
 */
__declspec(naked) void GuardedDualMaskFlagToggle_004261d0(void) {
    __asm {
        call    func_00426230
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   43h
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_eventQueueWorkType], 0xffff
        and     eax, 0x7070
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0fh
        mov     eax, dword ptr [g_data_00542070]
        and     eax, 0x77
        mov     dword ptr [g_data_00542070], eax
        _emit   74h
        _emit   0dh
        mov     eax, dword ptr [g_state_0054208c]
        or      al, 1
        mov     dword ptr [g_state_0054208c], eax
        ret
        mov     eax, dword ptr [g_state_0054208c]
        and     al, 0xfe
        mov     dword ptr [g_state_0054208c], eax
        ret
    }
}

/* @addr 0x00429860 (82b)
 *   call func_004299a0; if pause: ret;
 *   eax = g_cj_0054205c[idx*4 + 0x28]; ecx = g_scaledInit;
 *   ++eax → g_data_00542070;
 *   edx = [ecx*4 + 4]; if eax<edx: jmp ScaledLoadDecJmp_00429710;
 *   else: ++eax → g_data_00542070;
 *   if eax<edx: jmp ScaledLoadDecJmp_00429710;
 *   else: jmp ScaledStoreCurDirtyClear_004296f0.
 */
__declspec(naked) void GuardedDoubleIncCmpJmp_00429860(void) {
    __asm {
        call    func_004299a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   43h
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [eax*4 + 0x28]
        inc     eax
        mov     dword ptr [g_data_00542070], eax
        mov     edx, dword ptr [ecx*4 + 4]
        cmp     eax, edx
        _emit   7ch
        _emit   05h
        jmp     ScaledLoadDecJmp_00429710
        inc     eax
        mov     dword ptr [g_data_00542070], eax
        mov     edx, dword ptr [ecx*4 + 4]
        cmp     eax, edx
        _emit   7ch
        _emit   05h
        jmp     ScaledLoadDecJmp_00429710
        jmp     ScaledStoreCurDirtyClear_004296f0
        ret
    }
}

/* @addr 0x004928c0 (82b)
 *   if g_data_00542070 != 0: skip to call_chain;
 *   call func_00492450; if !pause: skip-ret; ret;
 *   call_chain: call func_00492510; if pause: jmp end;
 *   call Push1eCallTestDirtyLoop; if pause: jmp end;
 *   call func_00492280; if pause: jmp end;
 *   movzx ax, [0x4e28b8]; push eax; call func_004be690; pop arg;
 *   end: ret.
 */
__declspec(naked) void GuardedFourCallChain_004928c0(void) {
    __asm {
        mov     eax, dword ptr [g_data_00542070]
        test    eax, eax
        _emit   75h
        _emit   0fh
        call    func_00492450
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   74h
        _emit   0fh
        ret
        call    func_00492510
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2bh
        call    Push1eCallTestDirtyLoop_004923b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        call    func_00492280
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        _emit   66h
        _emit   0a1h
        _emit   0b8h
        _emit   28h
        _emit   4eh
        _emit   00h
        push    eax
        call    func_004be690
        add     esp, 4
        ret
    }
}

/* @addr 0x00483a20 (82b)
 *   eax = g_baseSel<<2; ecx = [eax+0x84]; clear [eax+0x84];
 *   if ecx != 0: dec g_state_00542080;
 *     if zero: jmp CallPauseDirty1JmpDirty4StackPush_00483a80;
 *     else:    jmp CallPauseDirty4StackPushFn_004839d0;
 *   else: store 0x483a20 at [eax+8], store 1 at [eax+0x84],
 *         g_pendingNodeType = 1, g_framePauseFlag = 1, ret.
 */
__declspec(naked) void InstallSelfOrChainJmp_00483a20(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   17h
        mov     eax, dword ptr [g_state_00542080]
        dec     eax
        mov     dword ptr [g_state_00542080], eax
        _emit   74h
        _emit   05h
        jmp     CallPauseDirty4StackPushFn_004839d0
        jmp     CallPauseDirty1JmpDirty4StackPush_00483a80
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00483a20
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x00436390 (83b)
 *   call Cmp2CallDirtyCall_004398b0; if eax: ret;
 *   push 0x4e4a10; call func_0043a950; pop;
 *   if pause: ret;
 *   eax = g_state_00535ddc; g_walkCallback = eax;
 *   cmp eax,0x20000; if >: jmp func_004363f0;
 *   cmp eax,0x17333; if >: jmp Wrapper_00436490;
 *   cmp eax,0x10000; if >: jmp func_004364a0;
 *   else: jmp CallPauseTestByteJmpCalls_004390f0.
 */
__declspec(naked) void ThresholdedTailJmps_00436390(void) {
    __asm {
        call    Cmp2CallDirtyCall_004398b0
        test    eax, eax
        _emit   75h
        _emit   49h
        push    0x004e4a10
        call    func_0043a950
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   33h
        mov     eax, dword ptr [g_state_00535ddc]
        cmp     eax, 0x20000
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   05h
        jmp     func_004363f0
        cmp     eax, 0x17333
        _emit   7eh
        _emit   05h
        jmp     Wrapper_00436490
        cmp     eax, 0x10000
        _emit   7eh
        _emit   05h
        jmp     func_004364a0
        jmp     CallPauseTestByteJmpCalls_004390f0
        ret
    }
}

/* @addr 0x0047a8f0 (83b)
 *   eax = g_baseSel<<2; ecx = [eax+0x84]; clear [eax+0x84];
 *   if ecx != 0: jmp func_0047a840;
 *   edx = g_state_00542088; ecx = 1; if edx==1: jmp func_0047a950;
 *   else store 0x47a8f0 at [eax+8], [eax+0x84]=1, g_pendingNodeType=8,
 *        g_framePauseFlag = 1, ret.
 */
__declspec(naked) void InstallSelfOrChainCmpJmp_0047a8f0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   05h
        jmp     func_0047a840
        mov     edx, dword ptr [g_state_00542088]
        mov     ecx, 1
        cmp     edx, ecx
        _emit   75h
        _emit   05h
        jmp     func_0047a950
        mov     dword ptr [eax + 8], 0x0047a8f0
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], 8
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x0048c510 (83b)
 *   eax = g_state_00537f94 → g_walkCallback;
 *   if eax: jmp clear_and_ret;
 *   call CopyJmp_0048ef90; if pause: ret;
 *   cl = byte [g_state_0054208c]; eax = 1;
 *   if (al & cl): jmp clear_and_ret;
 *   ecx = g_cj_0054205c; edx = [ecx*4 + 0x40] & 1; g_state_00542094 = edx;
 *   if zero: g_walkCallback = 1, ret;
 *   clear_and_ret: g_walkCallback = 0, ret.
 */
__declspec(naked) void GuardedBitMaskFlagOrClear_0048c510(void) {
    __asm {
        mov     eax, dword ptr [g_state_00537f94]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   34h
        call    CopyJmp_0048ef90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   36h
        mov     cl, byte ptr [g_state_0054208c]
        mov     eax, 1
        test    cl, al
        _emit   75h
        _emit   17h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [ecx*4 + 0x40]
        and     edx, eax
        mov     dword ptr [g_state_00542094], edx
        _emit   74h
        _emit   0bh
        mov     dword ptr [g_walkCallback], 0
        ret
        mov     dword ptr [g_walkCallback], eax
        ret
    }
}

/* @addr 0x0049e360 (83b)
 *   call DualTestDirtyToggle_004282c0; if pause: ret;
 *   test [g_state_0054208c]&1; if zero: ret;
 *   eax = g_state_0053a408; ecx = 2; cmp eax,1;
 *   g_walkCallback = eax; if !=: skip;
 *     g_walkCallback = 2; g_state_0053a408 = 2;
 *   eax = g_state_00537e88; cmp eax,1; g_data_00542070 = eax;
 *   if !=: ret;
 *   g_walkCallback = 2; g_state_00537e88 = 2; ret.
 */
__declspec(naked) void GuardedCmpDualToggle_0049e360(void) {
    __asm {
        call    DualTestDirtyToggle_004282c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   44h
        test    byte ptr [g_state_0054208c], 1
        _emit   74h
        _emit   3bh
        mov     eax, dword ptr [g_state_0053a408]
        mov     ecx, 2
        cmp     eax, 1
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0ch
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_state_0053a408], ecx
        mov     eax, dword ptr [g_state_00537e88]
        cmp     eax, 1
        mov     dword ptr [g_data_00542070], eax
        _emit   75h
        _emit   0ch
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_state_00537e88], ecx
        ret
    }
}

/* @addr 0x0043e270 (86b)
 *   [g_scaledInit*4 + 0x74] = 0xffffcccd;
 *   g_walkCallback = 0xffffd70b; [g_scaledInit*4 + 0x70] = 0xffffd70b;
 *   g_eventQueueWorkType = 0x3333;
 *   g_scaledInit += 0x1b; call func_00476880;
 *   if no pause: g_scaledInit -= 0x1b; ret.
 */
__declspec(naked) void DualPackedStoreCallSubBack_0043e270(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [eax*4 + 0x74], 0xffffcccd
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, 0xffffd70b
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x70], eax
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_eventQueueWorkType], 0x3333
        add     ecx, 0x1b
        mov     dword ptr [g_scaledInit_00542044], ecx
        call    func_00476880
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   07h
        sub     dword ptr [g_scaledInit_00542044], 0x1b
        ret
    }
}

/* @addr 0x0048c1b0 (86b)
 *   Push g_data_00542070 on mstack; compute
 *   g_xformEntityIdx = (g_data_00542070 * 5) << 0x14 + 0x4c00000;
 *   call Thunk_004bd5c0; if no pause: pop g_data_00542070; ret.
 */
__declspec(naked) void PushScaledIdxStoreCallPop_0048c1b0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_data_00542070]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_data_00542070]
        lea     edx, [eax + eax*4]
        shl     edx, 0x14
        add     edx, 0x4c00000
        mov     dword ptr [g_xformEntityIdx], edx
        call    Thunk_004bd5c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_data_00542070], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x004a1fa0 (86b)
 *   call func_00427470; if pause: ret;
 *   eax = arg0 >> 2 → g_xformEntityIdx; ecx = arg1;
 *   g_walkCallback = 0xa000; g_data_00542070 = 4;
 *   g_acc_00542078 = 0; g_state_0054207c = ecx;
 *   call func_00457ad0; if no pause: jmp func_004274f0; else ret.
 */
__declspec(naked) void GuardedSetupCallTailJmp_004a1fa0(void) {
    __asm {
        call    func_00427470
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   47h
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [esp + 8]
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [g_walkCallback], 0xa000
        mov     dword ptr [g_data_00542070], 4
        mov     dword ptr [g_acc_00542078], 0
        mov     dword ptr [g_state_0054207c], ecx
        call    func_00457ad0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004274f0
        ret
    }
}

/* @addr 0x004a2000 (86b)
 *   call func_00427470; if pause: ret;
 *   eax=arg0, ecx=arg1, edx=arg2;
 *   g_walkCallback=0xa000; g_xformEntityIdx=arg0>>2;
 *   g_data_00542070=4; g_acc_00542078=ecx; g_state_0054207c=edx;
 *   call func_00457900; if no pause: jmp func_004274f0; else ret.
 */
__declspec(naked) void GuardedSetupCallTailJmp3_004a2000(void) {
    __asm {
        call    func_00427470
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   47h
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [esp + 8]
        mov     edx, dword ptr [esp + 0x0c]
        mov     dword ptr [g_walkCallback], 0xa000
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [g_data_00542070], 4
        mov     dword ptr [g_acc_00542078], ecx
        mov     dword ptr [g_state_0054207c], edx
        call    func_00457900
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004274f0
        ret
    }
}

/* @addr 0x00424020 (87b)
 *   Push g_walkCallback on mstack; eax=g_cj_00542058; edx=[eax*4];
 *   ++eax; g_eventQueueWorkType=edx; g_cj_00542058=eax;
 *   call Push16Call_00489f50; if no pause: pop g_walkCallback; ret.
 */
__declspec(naked) void PushSetCj58CallPopWalk_00424020(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_walkCallback]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_cj_00542058]
        mov     edx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_eventQueueWorkType], edx
        mov     dword ptr [g_cj_00542058], eax
        call    Push16Call_00489f50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x00439350 (87b)
 *   Push g_state_00542080 on mstack; g_walkCallback = 0xf5c;
 *   call func_004903f0; if pause: ret;
 *   call func_004917e0; if pause: ret;
 *   pop g_state_00542080; ret.
 */
__declspec(naked) void Push80SetWalkDualCallPop_00439350(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_state_00542080]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     dword ptr [g_walkCallback], 0xf5c
        call    func_004903f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   26h
        call    func_004917e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_state_00542080], edx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x004393b0 (87b)
 *   Same as 0x00439350 but g_walkCallback = 0xfffff0a4.
 */
__declspec(naked) void Push80SetWalkNegDualCallPop_004393b0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_state_00542080]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     dword ptr [g_walkCallback], 0xfffff0a4
        call    func_004903f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   26h
        call    func_004917e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_state_00542080], edx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x00439700 (87b)
 *   eax = g_cj_00542058; if zero: jmp clear;
 *   ecx = [eax*4+0x30]; g_walkCallback=ecx; cmp ecx,0x43;
 *   if eq: jmp set;
 *   loop: eax = [eax*4]; g_cj_00542058 = eax; if zero: jmp clear;
 *         ecx = [eax*4+0x30]; g_walkCallback=ecx; cmp ecx,0x43;
 *         if ne: jmp loop;
 *   set: g_state_0054208c |= 1; ret.
 *   clear: g_state_0054208c &= 0xfe; ret.
 */
__declspec(naked) void WalkCj58Loop43Toggle_00439700(void) {
    __asm {
        mov     eax, dword ptr [g_cj_00542058]
        test    eax, eax
        _emit   74h
        _emit   41h
        mov     ecx, dword ptr [eax*4 + 0x30]
        cmp     ecx, 0x43
        mov     dword ptr [g_walkCallback], ecx
        _emit   74h
        _emit   22h
        mov     eax, dword ptr [eax*4 + 0]
        test    eax, eax
        mov     dword ptr [g_cj_00542058], eax
        _emit   74h
        _emit   1fh
        mov     ecx, dword ptr [eax*4 + 0x30]
        cmp     ecx, 0x43
        mov     dword ptr [g_walkCallback], ecx
        _emit   75h
        _emit   0deh
        mov     eax, dword ptr [g_state_0054208c]
        or      al, 1
        mov     dword ptr [g_state_0054208c], eax
        ret
        mov     eax, dword ptr [g_state_0054208c]
        and     al, 0xfe
        mov     dword ptr [g_state_0054208c], eax
        ret
    }
}

/* @addr 0x0044d060 (87b)
 *   Push g_scaledInit on mstack; set g_xformEntityIdx = 0x4ec8f8>>2;
 *   call DispatcherComplex260_00407030; if pause: ret;
 *   g_data_00542050 = g_scaledInit; pop g_scaledInit; ret.
 */
__declspec(naked) void PushSetXfmCallStoreCopy_0044d060(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     edx, 0x004ec8f8
        mov     dword ptr [g_state_004d57ac], eax
        shr     edx, 2
        mov     dword ptr [eax*4 + 0], ecx
        mov     dword ptr [g_xformEntityIdx], edx
        call    DispatcherComplex260_00407030
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   22h
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_data_00542050], eax
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x0048f210 (87b)
 *   call ScaledLoadCmpStoreXfm_0048f2a0; if pause: ret;
 *   eax = g_walkCallback; ecx = g_data_00542070;
 *   cmp ecx,eax; if gt: jmp clear;
 *   ecx = g_data_0053a180; edx = ecx;
 *   ecx += 0xfff60000; edx -= eax; cmp eax,ecx;
 *   g_eventQueueWorkType = edx; g_data_00542070 = ecx;
 *   if le: jmp clear;
 *   set: g_state_0054208c |= 1; ret.
 *   clear: g_state_0054208c &= 0xfe; ret.
 */
__declspec(naked) void GuardedRangeCmpToggle_0048f210(void) {
    __asm {
        call    ScaledLoadCmpStoreXfm_0048f2a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   48h
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_data_00542070]
        cmp     ecx, eax
        _emit   7fh
        _emit   2dh
        mov     ecx, dword ptr [g_data_0053a180]
        mov     edx, ecx
        add     ecx, 0xfff60000
        sub     edx, eax
        cmp     eax, ecx
        mov     dword ptr [g_eventQueueWorkType], edx
        mov     dword ptr [g_data_00542070], ecx
        _emit   7eh
        _emit   0dh
        mov     eax, dword ptr [g_state_0054208c]
        or      al, 1
        mov     dword ptr [g_state_0054208c], eax
        ret
        mov     eax, dword ptr [g_state_0054208c]
        and     al, 0xfe
        mov     dword ptr [g_state_0054208c], eax
        ret
    }
}

/* @addr 0x0048f570 (87b)
 *   eax = g_baseSel<<2; ecx = [eax+0x84]; clear [eax+0x84];
 *   if ecx != 0:
 *     ecx = g_cj_0054205c; ecx = [ecx*4+0x70];
 *     g_walkCallback = ecx; if !neg: skip;
 *     jmp StackPopDispatchTagged_0041f780;
 *   else: ecx=1; [eax+8]=0x48f570; [eax+0x84]=1;
 *         g_pendingNodeType=1; g_framePauseFlag=1; ret.
 */
__declspec(naked) void InstallSelfOrCmpJmp_0048f570(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   1ch
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [ecx*4 + 0x70]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        _emit   7dh
        _emit   05h
        jmp     StackPopDispatchTagged_0041f780
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x0048f570
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x0047dbc0 (88b)
 *   g_xformEntityIdx = 0x500c08>>2; call ScaledArrStore_004298c0;
 *   if pause: ret; ecx = g_cj_0054205c; eax = 0xffffb334;
 *   g_state_00542088 = eax; [ecx*4+0x78] = eax;
 *   g_eventQueueWorkType = 0x3333; call DualFieldAddSubStore;
 *   if pause: ret; push 0x4ed4b8; call IterStepDualStore; ret.
 */
__declspec(naked) void DualSetCallPair_0047dbc0(void) {
    __asm {
        mov     eax, 0x00500c08
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    ScaledArrStore_004298c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3ch
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, 0xffffb334
        mov     dword ptr [g_state_00542088], eax
        mov     dword ptr [ecx*4 + 0x78], eax
        mov     dword ptr [g_eventQueueWorkType], 0x3333
        call    DualFieldAddSubStore_00470340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004ed4b8
        call    IterStepDualStore_00490b40
        add     esp, 4
        ret
    }
}

/* @addr 0x00490090 (88b)
 *   eax = g_cj_0054205c[*4 + 0x64]; ecx = g_scaledInit;
 *   g_walkCallback = eax; [ecx*4 + 0x64] = eax;
 *   edx = g_cj_0054205c; ecx = g_scaledInit;
 *   eax = [edx*4 + 0x34]; g_walkCallback = eax;
 *   ecx = [ecx*4 + 0x34]; eax &= 1; ecx &= 1;
 *   cmp ecx,eax; g_walkCallback = eax; g_data_00542070 = ecx;
 *   if eq: ret;
 *   else: jmp ScaledXorStore_004900f0.
 */
__declspec(naked) void DualMaskCmpJmp_00490090(void) {
    __asm {
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [eax*4 + 0x64]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x64], eax
        mov     edx, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [edx*4 + 0x34]
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [ecx*4 + 0x34]
        and     eax, 1
        and     ecx, 1
        cmp     ecx, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_data_00542070], ecx
        _emit   74h
        _emit   05h
        jmp     ScaledXorStore_004900f0
        ret
    }
}

/* @addr 0x0049b850 (88b)
 *   eax = [g_scaledInit*4]; g_walkCallback = eax;
 *   if zero: ret;
 *   ecx = 0xffffb334; g_scaledInit = eax;
 *   g_walkCallback = ecx; edx = [eax*4 + 0x38];
 *   g_data_00542070 = edx; [eax*4 + 0x38] = ecx;
 *   eax = g_walkCallback; edx = g_data_00542070;
 *   eax -= edx; cmp eax, 0x1999;
 *   g_walkCallback = eax; if le: ret;
 *   else: jmp func_0049b7c0.
 */
__declspec(naked) void ChainStoreCmpJmp_0049b850(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [eax*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   42h
        mov     ecx, 0xffffb334
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_data_00542070], edx
        mov     dword ptr [eax*4 + 0x38], ecx
        mov     eax, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_data_00542070]
        sub     eax, edx
        cmp     eax, 0x1999
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   05h
        jmp     func_0049b7c0
        ret
    }
}

/* @addr 0x00446520 (89b)
 *   eax = g_baseSel*4; ecx=0; g_walkCallback=ecx;
 *   eax = [eax*4 + 0x30] (loaded earlier?); g_scaledInit=eax;
 *   actually: eax = g_baseSel; eax = [eax*4+0x30]; g_scaledInit=eax;
 *   eax <<= 2; [eax+0x30]=0; [eax+0x34]=0; [eax+0x38]=0;
 *   [eax+0x40]=0; ecx=0x2b43; [eax+0x44]=0; [eax+0x3c]=0x1eb8;
 *   g_walkCallback=ecx; [eax+0x34]=ecx; ret.
 */
__declspec(naked) void InitSlotsWithTag_00446520(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        xor     ecx, ecx
        mov     eax, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        shl     eax, 2
        mov     dword ptr [eax + 0x30], ecx
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x34], ecx
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x38], edx
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x40], ecx
        mov     edx, dword ptr [g_walkCallback]
        mov     ecx, 0x2b43
        mov     dword ptr [eax + 0x44], edx
        mov     dword ptr [eax + 0x3c], 0x1eb8
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x34], ecx
        ret
    }
}

/* @addr 0x00453170 (89b)
 *   call func_004089e0; if pause: ret;
 *   call func_004b8fa0; if pause: ret;
 *   eax = g_cj_0054205c; eax = [eax*4 + 0x18];
 *   g_scaledInit = eax; eax = [eax*4 + 0x28];
 *   g_scaledInit = eax; ecx = [eax*4 + 0x3c];
 *   g_walkCallback = ecx; edx = [eax*4 + 0x44];
 *   g_data_00542070 = edx; jmp func_00475990.
 */
__declspec(naked) void DualGuardedChainJmp_00453170(void) {
    __asm {
        call    func_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   4ah
        call    func_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3ch
        mov     eax, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0x44]
        mov     dword ptr [g_data_00542070], edx
        jmp     func_00475990
        ret
    }
}

/* @addr 0x00453420 (89b)
 *   call func_004089e0; if pause: ret;
 *   g_walkCallback = 2; call func_00408c10; if pause: ret;
 *   eax = g_xformEntityIdx; ecx = [eax*4] | 4; [eax*4] = ecx;
 *   ecx = g_xformEntityIdx; eax = 0xa0000;
 *   g_walkCallback = eax; [ecx*4+0x34] = eax; jmp func_004b8fa0.
 */
__declspec(naked) void GuardedSetCallOrJmp_00453420(void) {
    __asm {
        call    func_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   4ah
        mov     dword ptr [g_walkCallback], 2
        call    func_00408c10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   32h
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0]
        or      ecx, 4
        mov     dword ptr [eax*4 + 0], ecx
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0xa0000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        jmp     func_004b8fa0
        ret
    }
}

/* @addr 0x0048a1c0 (89b)
 *   if g_state_00541fa4==0 and (g_state_0053a7b0&1)!=0:
 *     g_eventQueueWorkType=0x1f9; call Push16Call_00489f50;
 *     g_state_00541fa4 = g_data_0053a770;
 *   if g_state_00541fa8==0 and (g_state_0053a7b0&2)!=0:
 *     g_eventQueueWorkType=0x1fe; call Push16Call_00489f50;
 *     g_state_00541fa8 = g_data_0053a770;
 *   ret.
 */
__declspec(naked) void DualBitGateInitCall_0048a1c0(void) {
    __asm {
        mov     eax, dword ptr [g_state_00541fa4]
        test    eax, eax
        _emit   75h
        _emit   22h
        test    byte ptr [g_state_0053a7b0], 1
        _emit   74h
        _emit   19h
        mov     dword ptr [g_eventQueueWorkType], 0x1f9
        call    Push16Call_00489f50
        mov     eax, dword ptr [g_data_0053a770]
        mov     dword ptr [g_state_00541fa4], eax
        mov     eax, dword ptr [g_state_00541fa8]
        test    eax, eax
        _emit   75h
        _emit   24h
        test    byte ptr [g_state_0053a7b0], 2
        _emit   74h
        _emit   1bh
        mov     dword ptr [g_eventQueueWorkType], 0x1fe
        call    Push16Call_00489f50
        mov     ecx, dword ptr [g_data_0053a770]
        mov     dword ptr [g_state_00541fa8], ecx
        ret
    }
}

/* @addr 0x0048ce00 (89b)
 *   Push g_scaledInit on mstack; call func_0048bc40;
 *   if pause: ret; eax = g_scaledInit; ecx = g_state_004d57ac;
 *   g_xformEntityIdx = eax; edx = [ecx*4]; --ecx;
 *   g_scaledInit = edx; g_state_004d57ac = ecx;
 *   eax = [eax*4 + 8]; g_walkCallback = eax; jmp eax.
 */
__declspec(naked) void PushCallPopScaledJmpIndirect_0048ce00(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    func_0048bc40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   32h
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_state_004d57ac]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [ecx*4 + 0]
        dec     ecx
        mov     dword ptr [g_scaledInit_00542044], edx
        mov     dword ptr [g_state_004d57ac], ecx
        mov     eax, dword ptr [eax*4 + 8]
        mov     dword ptr [g_walkCallback], eax
        jmp     eax
        ret
    }
}

/* @addr 0x00439130 (90b)
 *   4-call cascade: call func_0048eec0; if pause: ret;
 *   if (bit0 of g_state_0054208c)!=0: jmp SetJmp_00438f60;
 *   call Wrapper_0048ec20; if pause: ret;
 *   if bit0 set: jmp SetJmp_00438f50;
 *   call func_0045f8d0; if pause: ret;
 *   call ScaledZeroFour_00490740; if pause: ret;
 *   jmp GuardedDispatch_0042b6c0.
 */
__declspec(naked) void QuadGuardBitGateJmp_00439130(void) {
    __asm {
        call    func_0048eec0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   4bh
        test    byte ptr [g_state_0054208c], 1
        _emit   74h
        _emit   05h
        jmp     SetJmp_00438f60
        call    Wrapper_0048ec20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2fh
        test    byte ptr [g_state_0054208c], 1
        _emit   74h
        _emit   05h
        jmp     SetJmp_00438f50
        call    func_0045f8d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    ScaledZeroFour_00490740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     GuardedDispatch_0042b6c0
        ret
    }
}

/* @addr 0x0046f740 (90b)
 *   eax = g_state_00542088; g_data_00542070 = 0;
 *   g_walkCallback = eax; call MStackPushZeroCallPop_00407d00;
 *   if pause: ret; call func_0048f350; if pause: ret;
 *   if (bit2 of g_state_0054208c) != 0:
 *     ++g_state_004d57ac; [mstack[*4]] = 0x46f7a0;
 *     jmp func_004339c0;
 *   else: jmp func_0046f7a0.
 */
__declspec(naked) void BitGateInstallChainJmp_0046f740(void) {
    __asm {
        mov     eax, dword ptr [g_state_00542088]
        mov     dword ptr [g_data_00542070], 0
        mov     dword ptr [g_walkCallback], eax
        call    MStackPushZeroCallPop_00407d00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   37h
        call    func_0048f350
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_state_0054208c], 4
        _emit   74h
        _emit   1bh
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], 0x0046f7a0
        jmp     func_004339c0
        jmp     func_0046f7a0
        ret
    }
}

/* @addr 0x00484650 (90b)
 *   eax = g_baseSel; esi = &[eax*4]; eax = [eax*4 + 0x84];
 *   [esi + 0x84] = 0; if eax != 0: call LiteralPushCallEntZero;
 *   pop esi; ret;
 *   else: call LeaPlus22StoreSelf_0048e4d0; if pause: ret;
 *     [esi+8] = 0x484650; [esi+0x84] = 1;
 *     g_pendingNodeType = 0x14; g_framePauseFlag = 1; ret.
 */
__declspec(naked) void EsiAliasInstallSelf_00484650(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   07h
        call    LiteralPushCallEntZero_00488c00
        pop     esi
        ret
        call    LeaPlus22StoreSelf_0048e4d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   21h
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00484650
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 0x14
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}

/* @addr 0x0043d040 (91b)
 *   eax = g_baseSel*4; edx=0; ecx = [eax+0x84]; [eax+0x84]=0;
 *   if ecx==0: jmp install;
 *   loop: ecx = g_baseSel*4; eax = [ecx*4]; ecx = [ecx*4+0x84];
 *         [eax+0x84] = 0; if ecx!=0: jmp loop;
 *   install: ecx = 1; [eax+8] = 0x43d040; [eax+0x84] = 1;
 *            g_pendingNodeType = 0x64; g_framePauseFlag = 1; ret.
 */
__declspec(naked) void UnlinkChainInstall_0043d040(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        xor     edx, edx
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   74h
        _emit   1eh
        mov     ecx, dword ptr [g_baseSel_00542060]
        lea     eax, [ecx*4 + 0]
        mov     ecx, dword ptr [ecx*4 + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   75h
        _emit   0e2h
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x0043d040
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], 0x64
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x0044ccf0 (91b)
 *   call func_004767e0; if pause: ret;
 *   eax = g_data_00535cf8; ecx = g_cj_00542058; edx = g_baseSel;
 *   g_scaledInit = eax; eax = [ecx*4 + 0x54]; push esi;
 *   g_data_00542070 = eax; esi = [edx*4 + 0x3c]; eax += esi;
 *   pop esi; g_data_00542070 = eax;
 *   eax = [ecx*4 + 0x5c]; g_eventQueueWorkType = eax;
 *   ecx = [edx*4 + 0x44]; eax += ecx; g_eventQueueWorkType = eax;
 *   ret.
 */
__declspec(naked) void GuardedChainDualAdd_0044ccf0(void) {
    __asm {
        call    func_004767e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   4ch
        mov     eax, dword ptr [g_data_00535cf8]
        mov     ecx, dword ptr [g_cj_00542058]
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [ecx*4 + 0x54]
        push    esi
        mov     dword ptr [g_data_00542070], eax
        mov     esi, dword ptr [edx*4 + 0x3c]
        add     eax, esi
        pop     esi
        mov     dword ptr [g_data_00542070], eax
        mov     eax, dword ptr [ecx*4 + 0x5c]
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     ecx, dword ptr [edx*4 + 0x44]
        add     eax, ecx
        mov     dword ptr [g_eventQueueWorkType], eax
        ret
    }
}

/* @addr 0x004756f0 (91b)
 *   eax = g_cj_00542054<<2; ecx = g_cj_00542058<<2;
 *   edx = [eax+0x34]; push esi; g_walkCallback = edx;
 *   esi = [ecx+0x34]; esi &= 1; edx &= 0xfffffffe; edx |= esi;
 *   g_data_00542070 = esi; g_walkCallback = edx;
 *   [eax+0x34] = edx;
 *   edx = [ecx+0x60]; pop esi; g_walkCallback = edx; [eax+0x60]=edx;
 *   edx = [ecx+0x64]; g_walkCallback=edx; [eax+0x64]=edx;
 *   ecx = [ecx+0x68]; g_walkCallback=ecx; [eax+0x68]=ecx; ret.
 */
__declspec(naked) void DualSlotCopyChain_004756f0(void) {
    __asm {
        mov     eax, dword ptr [g_cj_00542054]
        mov     ecx, dword ptr [g_cj_00542058]
        shl     eax, 2
        shl     ecx, 2
        mov     edx, dword ptr [eax + 0x34]
        push    esi
        mov     dword ptr [g_walkCallback], edx
        mov     esi, dword ptr [ecx + 0x34]
        and     esi, 1
        and     edx, 0xfffffffe
        or      edx, esi
        mov     dword ptr [g_data_00542070], esi
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x34], edx
        mov     edx, dword ptr [ecx + 0x60]
        pop     esi
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x60], edx
        mov     edx, dword ptr [ecx + 0x64]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x64], edx
        mov     ecx, dword ptr [ecx + 0x68]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x68], ecx
        ret
    }
}

/* @addr 0x0049c670 (91b)
 *   edx = g_data_00535e7c; eax = g_baseSel;
 *   ecx = g_data_00535e78; push esi; esi = g_state_00538158;
 *   g_data_00542070 = edx; edx = g_cj_0054205c;
 *   g_walkCallback = ecx; eax <<= 2; cmp edx,esi;
 *   if eq: jmp store; ecx = g_data_00535e70; cmp edx,esi;
 *   g_walkCallback = ecx; if eq: jmp store;
 *   edx = g_data_00535e74; g_data_00542070 = edx;
 *   store: [eax+0x68] = ecx; ecx = g_data_00542070;
 *          [eax+0x6c] = ecx; pop esi; ret.
 */
__declspec(naked) void CondPickDualStore_0049c670(void) {
    __asm {
        mov     edx, dword ptr [g_data_00535e7c]
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_data_00535e78]
        push    esi
        mov     esi, dword ptr [g_state_00538158]
        mov     dword ptr [g_data_00542070], edx
        mov     edx, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_walkCallback], ecx
        shl     eax, 2
        cmp     edx, esi
        _emit   74h
        _emit   1ch
        mov     ecx, dword ptr [g_data_00535e70]
        cmp     edx, esi
        mov     dword ptr [g_walkCallback], ecx
        _emit   74h
        _emit   0ch
        mov     edx, dword ptr [g_data_00535e74]
        mov     dword ptr [g_data_00542070], edx
        mov     dword ptr [eax + 0x68], ecx
        mov     ecx, dword ptr [g_data_00542070]
        mov     dword ptr [eax + 0x6c], ecx
        pop     esi
        ret
    }
}

/* @addr 0x004a3260 (91b)
 *   ecx = g_baseSel; edx = arg0;
 *   eax = [ecx*4 + 0x30]; eax = eax + eax*8; eax <<= 0 (lea);
 *   eax = (signed char)[edx + eax*4 + 0x10];
 *   edx = g_data_005437f0; eax += ecx;
 *   eax = [eax*4]; g_scaledInit = eax;
 *   ecx = [eax*4 + 0x58]; ecx -= 0x50000;
 *   [edx*4 + 0x58] = ecx; eax = g_scaledInit;
 *   edx = g_data_005437f0; ecx = [eax*4 + 0x5c]; [edx*4+0x5c]=ecx;
 *   ret.
 */
__declspec(naked) void ScaledByteIdxDualCopy_004a3260(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     edx, dword ptr [esp + 4]
        mov     eax, dword ptr [ecx*4 + 0x30]
        lea     eax, [eax + eax*8]
        movsx   eax, byte ptr [edx + eax*4 + 0x10]
        mov     edx, dword ptr [g_data_005437f0]
        add     eax, ecx
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0x58]
        sub     ecx, 0x50000
        mov     dword ptr [edx*4 + 0x58], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_data_005437f0]
        mov     ecx, dword ptr [eax*4 + 0x5c]
        mov     dword ptr [edx*4 + 0x5c], ecx
        ret
    }
}

/* @addr 0x0047c620 (92b)
 *   ecx = g_baseSel; eax = 1; g_walkCallback = 1;
 *   [ecx*4 + 0x68] = 1; edx = g_cj_0054205c;
 *   eax = 0x4ffe1c >> 2; g_xformEntityIdx = eax;
 *   ecx = [edx*4 + 0x24]; cmp eax, ecx;
 *   g_scaledInit = ecx; if eq: jmp end;
 *   push 0x542b90; call IterLoad_00491050; pop esp;
 *   if pause: ret; jmp end. (end is a ret).
 */
__declspec(naked) void OneSetCmpJmpLoadCall_0047c620(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x68], eax
        mov     edx, dword ptr [g_cj_0054205c]
        mov     eax, 0x004ffe1c
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [edx*4 + 0x24]
        cmp     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        _emit   75h
        _emit   05h
        _emit   0e9h
        _emit   20h
        _emit   00h
        _emit   00h
        _emit   00h
        push    0x00542b90
        call    IterLoad_00491050
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   05h
        _emit   0e9h
        _emit   05h
        _emit   00h
        _emit   00h
        _emit   00h
        ret
    }
}

/* @addr 0x00483ae0 (92b)
 *   eax = g_baseSel<<2; ecx = [eax+0x84]; [eax+0x84] = 0;
 *   if ecx != 0: call func_0048eba0; if pause: ret;
 *     if (bit0 of g_state_0054208c) == 0: jmp CallPauseDirty1JmpDirty4StackPush;
 *     else: jmp CallPauseScaledStorePushCall_0045fca0;
 *   else: ecx=1; [eax+8]=0x483ae0; [eax+0x84]=1;
 *         g_pendingNodeType=1; g_framePauseFlag=1; ret.
 */
__declspec(naked) void InstallSelfCallBitGate_00483ae0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   21h
        call    func_0048eba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   31h
        test    byte ptr [g_state_0054208c], 1
        _emit   74h
        _emit   05h
        jmp     CallPauseScaledStorePushCall_0045fca0
        jmp     CallPauseDirty1JmpDirty4StackPush_00483a80
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00483ae0
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x004a4880 (92b)
 *   g_scaledInit = 0x503308>>2; call LoadGeoAsset_Default;
 *   if pause: ret; g_xformEntityIdx = 0x506414>>2;
 *   call DispatcherComplex260_00407400; if pause: ret;
 *   call func_00406530; if pause: ret;
 *   g_cj_00542058 = 0; g_eventQueueEnd = g_scaledInit; ret.
 */
__declspec(naked) void TripleCallSetCopy_004a4880(void) {
    __asm {
        mov     eax, 0x00503308
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        call    LoadGeoAsset_Default
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   40h
        mov     ecx, 0x00506414
        shr     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    DispatcherComplex260_00407400
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   24h
        call    func_00406530
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   16h
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_cj_00542058], 0
        mov     dword ptr [g_eventQueueEnd], edx
        ret
    }
}

/* @addr 0x004b8ec0 (92b)
 *   eax = arg0; g_data_00ab4d9c = eax;
 *   ecx = eax + 0x200; edx = eax + 0x400;
 *   g_data_00ab4da0 = ecx; g_data_00ab4da4 = edx;
 *   ecx = eax + 0x580; edx = eax + 0x680;
 *   g_data_00ab4da8 = ecx; g_data_00ab4dac = edx;
 *   ecx = eax + 0x720; edx = eax + 0x780;
 *   eax += 0x7c0; g_data_00ab4db0=ecx; g_data_00ab4db4=edx;
 *   g_data_00ab4db8=eax; ret.
 */
extern unsigned int g_state_00ab4d9c;
extern unsigned int g_state_00ab4da0;
extern unsigned int g_state_00ab4da4;
extern unsigned int g_state_00ab4da8;
extern unsigned int g_state_00ab4dac;
extern unsigned int g_state_00ab4db0;
extern unsigned int g_state_00ab4db4;
extern unsigned int g_state_00ab4db8;
extern void func_00409aa0(void);
extern void func_00422810(void);
extern void DownloadPlayerChar(void);
extern void func_00468440(void);
extern void func_004071a0(void);
extern void func_00470480(void);
extern void func_0048f8e0(void);
extern void func_00405e70(void);
extern unsigned int g_state_00537f48;
extern unsigned int g_state_005380e0;
extern unsigned int g_state_00535cfc;
extern unsigned int g_state_0053a1d0;
__declspec(naked) void SetupBufferOffsets_004b8ec0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     dword ptr [g_state_00ab4d9c], eax
        lea     ecx, [eax + 0x200]
        lea     edx, [eax + 0x400]
        mov     dword ptr [g_state_00ab4da0], ecx
        mov     dword ptr [g_state_00ab4da4], edx
        lea     ecx, [eax + 0x580]
        lea     edx, [eax + 0x680]
        mov     dword ptr [g_state_00ab4da8], ecx
        mov     dword ptr [g_state_00ab4dac], edx
        lea     ecx, [eax + 0x720]
        lea     edx, [eax + 0x780]
        add     eax, 0x7c0
        mov     dword ptr [g_state_00ab4db0], ecx
        mov     dword ptr [g_state_00ab4db4], edx
        mov     dword ptr [g_state_00ab4db8], eax
        ret
    }
}

/* @addr 0x00438530 (93b)
 *   eax = g_state_00535ddc; ecx = g_data_00542084;
 *   cmp eax,ecx; g_walkCallback = eax;
 *   if lt: jmp StackPopDispatchTagged_0041f780;
 *   else: push g_state_00542080 on mstack;
 *         call Push80SetWalkDualCallPop_00439350;
 *         if pause: ret; pop g_state_00542080; jmp 0x438590.
 *   At 0x438587 we jmp 0x438590 (4 bytes past local end which is itself outside).
 */
__declspec(naked) void CmpDispatchPushCallPop_00438530(void) {
    __asm {
        mov     eax, dword ptr [g_state_00535ddc]
        mov     ecx, dword ptr [g_data_00542084]
        cmp     eax, ecx
        mov     dword ptr [g_walkCallback], eax
        _emit   7dh
        _emit   05h
        jmp     StackPopDispatchTagged_0041f780
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_state_00542080]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    Push80SetWalkDualCallPop_00439350
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_state_00542080], edx
        mov     dword ptr [g_state_004d57ac], eax
        _emit   0e9h
        _emit   04h
        _emit   00h
        _emit   00h
        _emit   00h
        ret
    }
}

/* @addr 0x00480ac0 (93b)
 *   eax = g_baseSel<<2; ecx = [eax+0x84]; [eax+0x84] = 0;
 *   if ecx != 0:
 *     ecx = g_cj_0054205c; edx = g_state_0054207c;
 *     ecx = [ecx*4 + 0x58]; cmp ecx,edx; g_walkCallback = ecx;
 *     if gt: jmp install;
 *     jmp StackPopDispatchTagged_0041f780;
 *   install: ecx=1; [eax+8]=0x480ac0; [eax+0x84]=1;
 *            g_pendingNodeType=1; g_framePauseFlag=1; ret.
 */
__declspec(naked) void InstallSelfCmpJgJmp_00480ac0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   22h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [g_state_0054207c]
        mov     ecx, dword ptr [ecx*4 + 0x58]
        cmp     ecx, edx
        mov     dword ptr [g_walkCallback], ecx
        _emit   7fh
        _emit   05h
        jmp     StackPopDispatchTagged_0041f780
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00480ac0
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x00480b20 (93b) - twin of 0x00480ac0 with `jl` instead of `jg`. */
__declspec(naked) void InstallSelfCmpJlJmp_00480b20(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   22h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [g_state_0054207c]
        mov     ecx, dword ptr [ecx*4 + 0x58]
        cmp     ecx, edx
        mov     dword ptr [g_walkCallback], ecx
        _emit   7ch
        _emit   05h
        jmp     StackPopDispatchTagged_0041f780
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00480b20
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x0048f7b0 (93b)
 *   3-field copy: g_baseSel[*4+0x5c/0x60/0x64] →
 *                 g_cj_0054205c[*4+0x6c/0x70/0x74] (via walkCallback).
 */
__declspec(naked) void TripleFieldCopyHi_0048f7b0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [eax*4 + 0x5c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x6c], eax
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [edx*4 + 0x60]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x70], eax
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [edx*4 + 0x64]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        ret
    }
}

/* @addr 0x0048f880 (93b) - twin of 0x0048f7b0 mapping to 0x54/0x58/0x5c. */
__declspec(naked) void TripleFieldCopyLo_0048f880(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [eax*4 + 0x5c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [edx*4 + 0x60]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [edx*4 + 0x64]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x5c], eax
        ret
    }
}

/* @addr 0x00489c70 (93b)
 *   eax = g_pendingNodeType; ecx = [eax*4 + 0x54];
 *   g_walkCallback = ecx; edx = [eax*4 + 0x6c]; ecx -= edx;
 *   g_data_00542070 = edx; g_walkCallback = ecx;
 *   [eax*4 + 0x54] = ecx; eax = g_pendingNodeType;
 *   ecx = [eax*4 + 0x5c]; g_walkCallback = ecx;
 *   edx = [eax*4 + 0x74]; ecx -= edx; g_data_00542070 = edx;
 *   g_walkCallback = ecx; [eax*4 + 0x5c] = ecx; ret.
 */
__declspec(naked) void DualSubFromField_00489c70(void) {
    __asm {
        mov     eax, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [eax*4 + 0x54]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0x6c]
        sub     ecx, edx
        mov     dword ptr [g_data_00542070], edx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x54], ecx
        mov     eax, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [eax*4 + 0x5c]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0x74]
        sub     ecx, edx
        mov     dword ptr [g_data_00542070], edx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x5c], ecx
        ret
    }
}

/* @addr 0x00406bb0 (94b)
 *   eax = [g_scaledInit*4 + 0x10]; test+store g_walkCallback;
 *   if zero: ret;
 *   push g_xformEntityIdx on mstack; g_xformEntityIdx = 3;
 *   call func_00409aa0; if pause: ret;
 *   pop g_xformEntityIdx; ret.
 */
__declspec(naked) void GuardedChainPushSetCallPop_00406bb0(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [eax*4 + 0x10]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   48h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     dword ptr [g_xformEntityIdx], 3
        call    func_00409aa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x004227b0 (94b)
 *   g_data_00542070=4; g_scaledInit=0x53a328>>2; g_xformEntityIdx=0x53a788>>2;
 *   call func_00422810; if pause: ret;
 *   g_data_00542070=0x40; g_scaledInit=0x53e348>>2; g_xformEntityIdx=0x53e34c>>2;
 *   jmp func_00422810.
 */
__declspec(naked) void DualSetupSameCall_004227b0(void) {
    __asm {
        mov     eax, 0x0053a328
        mov     ecx, 0x0053a788
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_data_00542070], 4
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        call    func_00422810
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2ah
        mov     edx, 0x0053e348
        mov     eax, 0x0053e34c
        shr     edx, 2
        shr     eax, 2
        mov     dword ptr [g_data_00542070], 0x40
        mov     dword ptr [g_scaledInit_00542044], edx
        mov     dword ptr [g_xformEntityIdx], eax
        jmp     func_00422810
        ret
    }
}

/* @addr 0x00463810 (94b)
 *   if g_state_0053a408 != 0:
 *     g_walkCallback = g_state_00537f48; g_eventQueueEnd = 0x535cfc>>2;
 *     g_data_00542070 = 0; call DownloadPlayerChar;
 *     g_framePauseFlag = g_framePauseFlag (load); ret;
 *   else:
 *     g_walkCallback = g_state_005380e0; g_eventQueueEnd = 0x53a1d0>>2;
 *     g_data_00542070 = 1; jmp DownloadPlayerChar.
 */
__declspec(naked) void DualPathDownloadChar_00463810(void) {
    __asm {
        mov     eax, dword ptr [g_state_0053a408]
        test    eax, eax
        _emit   74h
        _emit   2dh
        mov     eax, dword ptr [g_state_00537f48]
        mov     ecx, 0x00535cfc
        shr     ecx, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_data_00542070], 0
        call    DownloadPlayerChar
        mov     eax, dword ptr [g_framePauseFlag]
        ret
        mov     edx, dword ptr [g_state_005380e0]
        mov     eax, 0x0053a1d0
        shr     eax, 2
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [g_data_00542070], 1
        jmp     DownloadPlayerChar
    }
}

/* @addr 0x004683e0 (94b)
 *   eax = g_baseSel; push esi;
 *   ecx = [eax*4+0x38]; g_data_00542084 = ecx;
 *   edx = [eax*4+0x3c]; g_state_00542088 = edx;
 *   esi = [eax*4+0x30]; ecx += esi; g_data_00542084 = ecx;
 *   esi = [eax*4+0x34]; edx += esi; g_state_00542088 = edx;
 *   [eax*4+0x38] = ecx; eax = g_baseSel; ecx = g_state_00542088;
 *   [eax*4+0x3c] = ecx; call func_00468440; pop esi; ret.
 */
__declspec(naked) void DualSlotPropagateCall_004683e0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        mov     ecx, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_data_00542084], ecx
        mov     edx, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_state_00542088], edx
        mov     esi, dword ptr [eax*4 + 0x30]
        add     ecx, esi
        mov     dword ptr [g_data_00542084], ecx
        mov     esi, dword ptr [eax*4 + 0x34]
        add     edx, esi
        mov     dword ptr [g_state_00542088], edx
        mov     dword ptr [eax*4 + 0x38], ecx
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_state_00542088]
        mov     dword ptr [eax*4 + 0x3c], ecx
        call    func_00468440
        pop     esi
        ret
    }
}

/* @addr 0x00407140 (95b)
 *   Push g_xformEntityIdx on mstack; eax = g_walkCallback;
 *   g_xformEntityIdx = eax; edx = [eax*4]; edx >>= 2; edx &= 0x3fffff;
 *   g_xformEntityIdx = edx; call func_004071a0;
 *   if pause: ret; pop g_xformEntityIdx; ret.
 */
__declspec(naked) void PushSetXfmMaskCallPop_00407140(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [eax*4 + 0]
        sar     edx, 2
        and     edx, 0x3fffff
        mov     dword ptr [g_xformEntityIdx], edx
        call    func_004071a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x0042c490 (95b)
 *   eax = g_baseSel; push esi; esi = &[eax*4];
 *   eax = [eax*4+0x84]; [esi+0x84] = 0;
 *   if eax != 0: call func_00470480; pop esi; ret;
 *   else: g_xformEntityIdx = 0x42c550;
 *     call func_0048f8e0; if pause: ret;
 *     [esi+8] = 0x42c490; [esi+0x84]=1;
 *     g_pendingNodeType = 1; g_framePauseFlag = 1; pop esi; ret.
 */
__declspec(naked) void EsiAliasInstallChainCall_0042c490(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   07h
        call    func_00470480
        pop     esi
        ret
        mov     dword ptr [g_xformEntityIdx], 0x0042c550
        call    func_0048f8e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ch
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0042c490
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}

/* @addr 0x0049b6d0 (95b)
 *   eax = g_baseSel; eax = [eax*4 + 0x60]; g_scaledInit = eax;
 *   eax = [eax*4]; test+store g_walkCallback;
 *   if zero: jmp call;
 *   loop: g_scaledInit = eax; eax = [eax*4];
 *         test+store g_walkCallback; if nonzero: jmp loop;
 *   call: call func_00405e70; if pause: ret;
 *         edx = g_baseSel; ecx = g_scaledInit;
 *         cmp ecx, [edx*4+0x60]; if ne: ret;
 *         else: jmp 0x49b730.
 */
__declspec(naked) void ChainWalkCallCmp_0049b6d0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x60]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   15h
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0ebh
        call    func_00405e70
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ah
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        cmp     ecx, dword ptr [edx*4 + 0x60]
        _emit   75h
        _emit   05h
        _emit   0e9h
        _emit   02h
        _emit   00h
        _emit   00h
        _emit   00h
        ret
    }
}
