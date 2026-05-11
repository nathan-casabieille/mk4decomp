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
