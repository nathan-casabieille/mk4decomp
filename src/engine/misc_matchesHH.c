/**
 * Forty-third batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueWorkType;
extern u32 g_pendingNodeType;

/* @addr 0x00424ba0 (65b)
 *   3-cell scaled-load test chain: deref [eax*4+0..8] in turn into walk;
 *   if any non-zero, jmp T1 else jmp T2.
 */
extern void IdentityMatrix_00424b70(void);
extern void Mul10HeavyTransform_00424bf0(void);
__declspec(naked) void ScaledTestChainDispatch_00424ba0(void) {
    __asm {
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        _emit   75h
        _emit   26h
        mov     ecx, dword ptr [eax*4 + 4]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        _emit   75h
        _emit   15h
        mov     eax, dword ptr [eax*4 + 8]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     IdentityMatrix_00424b70
        jmp     Mul10HeavyTransform_00424bf0
    }
}

/* @addr 0x00497b10 (63b)
 *   call F; pause-test → ret; jmp T1; nop padding (12);
 *   set g_eventQueueChild = 1; jmp T2; nop;
 *   set g_eventQueueChild = 0; jmp T2 (a 2-stub block joined together).
 */
extern void MStackCall_00406740(void);
extern void CallSetPause_0041f830(void);
extern void PunchDispatcherCluster_00497b50(void);
__declspec(naked) void CallPauseJmpThenSetChild_00497b10(void) {
    __asm {
        call    MStackCall_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     CallSetPause_0041f830
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov     dword ptr [g_eventQueueChild], 1
        jmp     PunchDispatcherCluster_00497b50
        nop
        mov     dword ptr [g_eventQueueChild], 0
        jmp     PunchDispatcherCluster_00497b50
    }
}

/* @addr 0x004c5800 (61b)
 *   if (arg[0xc] & 0x40) zero arg[0xc] and return -1;
 *   else: call 0x4c6ff0(arg); call 0x4c5840(arg) → save eax;
 *   call 0x4c7060(arg); restore eax; return.
 */
extern void func_004c6ff0_hh(void *);
extern int FCloseImpl_004c5840(void *);
extern void func_004c7060_hh(void *);
__declspec(naked) void Helper_FClose(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        push    edi
        or      edi, 0xffffffff
        test    byte ptr [esi + 0x0c], 0x40
        _emit   74h
        _emit   0ch
        mov     dword ptr [esi + 0x0c], 0
        mov     eax, edi
        pop     edi
        pop     esi
        ret
        push    esi
        call    func_004c6ff0_hh
        add     esp, 4
        push    esi
        call    FCloseImpl_004c5840
        add     esp, 4
        mov     edi, eax
        push    esi
        call    func_004c7060_hh
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        ret
    }
}

/* @addr 0x004cde40 (57b)
 *   pack a double from 3 dword args: high/low 32 bits + biased exponent.
 *   builds the 16-bit sign+exponent word at [esp+6], then fld it.
 */
__declspec(naked) void PackDoubleFromInts_004cde40(void) {
    __asm {
        sub     esp, 8
        mov     eax, dword ptr [esp + 0x0c]
        mov     ecx, dword ptr [esp + 0x10]
        mov     edx, dword ptr [esp + 0x14]
        _emit   89h     /* mov [esp + 0], eax (force disp8 form) */
        _emit   44h
        _emit   24h
        _emit   00h
        mov     dword ptr [esp + 4], ecx
        mov     ecx, dword ptr [esp + 0x12]
        lea     eax, [edx + 0x3fe]
        and     ecx, 0x800f
        shl     eax, 4
        or      ecx, eax
        mov     word  ptr [esp + 6], cx
        _emit   0ddh    /* fld qword [esp + 0] (force disp8 form) */
        _emit   44h
        _emit   24h
        _emit   00h
        add     esp, 8
        ret
    }
}

/* @addr 0x00404680 (71b)
 *   zero a bunch of state globals, with one extra-conditional zero on
 *   g_state_00535de4 if g_state_0054355c == 0 && g_state_00543710 == 0.
 */
extern unsigned int g_state_0054355c_hh;
extern unsigned int g_state_0053a3c0;
extern unsigned int g_state_00537f10;
extern unsigned int g_state_00543710_hh;
extern unsigned int g_state_00535de4;
extern unsigned int g_state_0052ab00;
extern unsigned int g_state_00537f8c;
extern unsigned int g_state_00541d90;
extern unsigned int g_state_0053a3e0;
extern unsigned int g_state_0053a700;
extern unsigned int g_state_00535e44;
__declspec(naked) void ZeroMultiGlobalsCmp_00404680(void) {
    __asm {
        mov     ecx, dword ptr [g_state_0054355c_hh]
        xor     eax, eax
        cmp     ecx, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_0053a3c0], eax
        mov     dword ptr [g_state_00537f10], eax
        _emit   75h
        _emit   0dh
        cmp     dword ptr [g_state_00543710_hh], eax
        _emit   75h
        _emit   05h
        mov     dword ptr [g_state_00535de4], eax
        mov     dword ptr [g_state_0052ab00], eax
        mov     dword ptr [g_state_00537f8c], eax
        mov     dword ptr [g_state_00541d90], eax
        mov     dword ptr [g_state_0053a3e0], eax
        mov     dword ptr [g_state_0053a700], eax
        mov     dword ptr [g_state_00535e44], eax
        ret
    }
}

/* @addr 0x00404a00 (77b)
 *   save g_walkCallback into esi, write arg → walk; call F; pause-test → ret;
 *   load dirty | 4; mov ax,4; restore walk = esi;
 *   if (g_scaledInit != 0) dirty ^= 4 (clear it again); store dirty; ret.
 */
extern void MStackPush2LLWalkCompare_004069b0(void);
__declspec(naked) void SaveCallRestoreOrXor_00404a00(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        mov     esi, dword ptr [g_walkCallback]
        mov     dword ptr [g_walkCallback], eax
        call    MStackPush2LLWalkCompare_004069b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2dh
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, 4
        mov     dword ptr [g_walkCallback], esi
        or      edx, eax
        test    ecx, ecx
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   0ah
        mov     ecx, edx
        xor     ecx, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        pop     esi
        ret
    }
}

/* @addr 0x00404c70 (66b)
 *   walk = arg2; eventQueueCurrent = 0xffff; call F; pause-test → ret;
 *   testb 1,[dirty]; jne ret; load arg1; eventQueueWorkType = arg2;
 *   pendingNodeType = arg1; call F2.
 */
extern void Thunk_0049cb70(void);
/* AllocNode declared in engine/scenegraph.h */
__declspec(naked) void SetWalkCurCallPauseDirty_00404c70(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 0x0c]
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [g_eventQueueCurrent], 0xffff
        call    Thunk_0049cb70
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   75h
        _emit   14h
        mov     eax, dword ptr [esp + 8]
        mov     dword ptr [g_eventQueueWorkType], esi
        mov     dword ptr [g_pendingNodeType], eax
        call    AllocNode
        pop     esi
        ret
    }
}

/* @addr 0x00408860 (68b)
 *   load scaled+0x28 into walk; if non-zero clear dirty bit 4 and ret;
 *   else call F; pause → ret; load g_scaledInit and g_xformEntityIdx;
 *   store xformEntityIdx into [scaledInit*4 + 0x28]; ret.
 */
extern void MStackPush2Burst6Init_00405450(void);
void ScaledTestPauseStore_00408860(void) {
    unsigned int v = *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x28);
    g_walkCallback = (void(*)(void))v;
    if (v) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFBu;
        return;
    }
    MStackPush2Burst6Init_00405450();
    if (g_framePauseFlag) return;
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x28) = g_xformEntityIdx;
}

/* @addr 0x00413070 (68b)
 *   inc g_state_004d57ac; push g_fightGroupHead onto stack[idx*4];
 *   call F1; pause-test → ret; call F2; pause-test → ret;
 *   set walk = 0xa; jmp T.
 */
extern void func_004089e0_hh(void);
extern void func_004b8fa0_hh(void);
extern void Phase4StateInit4Helpers_004130c0(void);
void PushStackCallPauseSet0xa_00413070(void) {
    unsigned int top = g_state_004d57ac;
    unsigned int v = g_fightGroupHead;
    top++;
    g_state_004d57ac = top;
    *(unsigned int *)(top * 4) = v;
    func_004089e0_hh();
    if (g_framePauseFlag) return;
    func_004b8fa0_hh();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))0xa;
    Phase4StateInit4Helpers_004130c0();
}

/* @addr 0x004c5740 (65b): __aullshl 64-bit shift-left + fnclex init helper
 *   joined with int3 + nop padding. Whole stub is 65b.
 *
 *   Layout:
 *     [0x00..0x1e] __aullshl: 64-bit shl by cl, 3 fall-through paths
 *                              (cl<0x20, 0x20<=cl<0x40, cl>=0x40).
 *     [0x1f]       int3 (filler).
 *     [0x20..0x36] init helper: call 4c5790, call 4c8450 → store result,
 *                                call 4c83e0, fnclex, ret.
 *     [0x37..0x3f] nop * 9 + ret.
 */
extern void func_004c5790_hh(void);
extern int LocaleNumericHelpers_004c8450(void);
extern void Push3000010000Call_004c83e0(void);
extern unsigned int g_state_00f9f7fc;
__declspec(naked) void UllShlAndInit_004c5740(void) {
    __asm {
        cmp     cl, 0x40
        _emit   73h
        _emit   15h
        cmp     cl, 0x20
        _emit   73h
        _emit   06h
        shld    edx, eax, cl
        shl     eax, cl
        ret
        mov     edx, eax
        xor     eax, eax
        and     cl,  0x1f
        shl     edx, cl
        ret
        xor     eax, eax
        xor     edx, edx
        ret
        _emit   0cch
        call    func_004c5790_hh
        call    LocaleNumericHelpers_004c8450
        mov     dword ptr [g_state_00f9f7fc], eax
        call    Push3000010000Call_004c83e0
        fnclex
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        ret
    }
}
