/**
 * Fifty-first batch of one-off matches.
 *
 * Fourteen 66-68 byte stubs covering: double-push state-stack,
 * save/restore wrappers, guarded multi-call chains, walk-callback
 * dispatch, clamped scaled multiply, fight-group field stores,
 * IAT-style helpers, sound-disable gate, malloc-with-handler,
 * and a CRT buffered-write.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_tickW1;
extern unsigned int g_fightGroupHead;

/* @addr 0x00444db0 (66b)
 *   Pushes g_currentNodeIdx (0x542044) and g_eventQueueWorkType
 *   (0x542074) onto the matrix-stack at g_matrixStackTop (0x4d57ac),
 *   sets g_walkCallback (0x54206c) = 0x4e5e28 >> 2, then jmp T.
 */
extern void func_00444ef0(void);
__declspec(naked) void DoublePushScaledInitJmp_00444db0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [g_eventQueueWorkType]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     eax, 0x004e5e28
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        jmp     func_00444ef0
    }
}

/* @addr 0x0044d1e0 (66b)
 *   Save g_xformEntityIdx (0x542048) on matrix stack, replace it
 *   with g_eventQueueEnd (0x542054), call helper, restore.
 *   Standard "scoped global swap" wrapper.
 */
extern void func_0044aa40(void);
__declspec(naked) void PushPopXformEntityCall_0044d1e0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_xformEntityIdx], edx
        call    func_0044aa40
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x00460260 (66b)
 *   call F1; pause → ret; call F2; pause → ret;
 *   set walk = 0xc; inc g_state_004d57ac;
 *   push 0x004602b0 onto stack[idx*4]; jmp T.
 */
extern void func_00490740(void);
extern void func_0048f720(void);
extern void func_004602b0_pp(void);
extern void func_00471250(void);
__declspec(naked) void GuardedDoubleCallSetJmp_00460260(void) {
    __asm {
        call    func_00490740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   33h
        call    func_0048f720
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   25h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     dword ptr [g_walkCallback], 0x0c
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], OFFSET func_004602b0_pp
        jmp     func_00471250
        ret
    }
}

/* @addr 0x0048e7d0 (66b)
 *   Switch on g_walkCallback: if it equals one of {0x2001, 0x2010,
 *   0x2002, 0x106, 0x107}, set bit 0 of g_xformDirtyFlags; else
 *   clear bit 0. Two distinct return paths.
 */
__declspec(naked) void WalkCallbackSetClearDirty_0048e7d0(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0x2001
        _emit   74h
        _emit   1ch
        cmp     eax, 0x2010
        _emit   74h
        _emit   15h
        cmp     eax, 0x2002
        _emit   74h
        _emit   0eh
        cmp     eax, 0x106
        _emit   74h
        _emit   07h
        cmp     eax, 0x107
        _emit   75h
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x004ba0e0 (66b)
 *   eax = g_xformEntityIdx[+0x14] * [0xab4e6c]; sar 8;
 *   clamp to [0, 0x100]; store at 0xab4e5c;
 *   then mov [0xab4e60] = g_tickW1; ret.
 */
extern int g_data_00ab4e6c;
extern int g_data_00ab4e5c;
extern int g_data_00ab4e60;
__declspec(naked) void ClampMulShiftStore_004ba0e0(void) {
    __asm {
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [eax*4 + 0x14]
        imul    eax, dword ptr [g_data_00ab4e6c]
        sar     eax, 8
        mov     dword ptr [g_data_00ab4e5c], eax
        _emit   79h
        _emit   07h
        xor     eax, eax
        mov     dword ptr [g_data_00ab4e5c], eax
        cmp     eax, 0x100
        _emit   7eh
        _emit   0ah
        mov     dword ptr [g_data_00ab4e5c], 0x100
        mov     ecx, dword ptr [g_tickW1]
        mov     dword ptr [g_data_00ab4e60], ecx
        ret
    }
}

/* @addr 0x0047dee0 (67b)
 *   if g_xformScratch2088 == 1, jmp T0; else set walk=2; call F1;
 *   pause → ret; load lit 0xf; push OFFSET g_data_004ed4e0;
 *   set walk and g_state_00537e94 = 0xf; call F2; add esp, 4; ret.
 */
extern unsigned int g_state_00537e94;
extern unsigned int g_data_004ed4e0;
extern void func_0047df30(void);
extern void func_0048e400(void);
extern int func_004594f0(unsigned int *p);
__declspec(naked) void GuardedSetCallSetCall_0047dee0(void) {
    __asm {
        cmp     dword ptr [g_xformScratch2088], 1
        _emit   75h
        _emit   05h
        jmp     func_0047df30
        mov     dword ptr [g_walkCallback], 2
        call    func_0048e400
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ch
        mov     eax, 0x0f
        push    OFFSET g_data_004ed4e0
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_00537e94], eax
        call    func_004594f0
        add     esp, 4
        ret
    }
}

/* @addr 0x0048ea40 (67b)
 *   call F1; pause → ret;
 *   eax = g_walkCallback; if == 0x2005, set dirty bit 0 → ret;
 *   if == 0x2002, set dirty bit 0 → ret; else clear bit 0 → ret.
 *   The second arm loads g_xformDirtyFlags BEFORE the conditional
 *   branch (codegen quirk: cmp flags preserved across load).
 */
extern void func_0048f910(void);
__declspec(naked) void GuardedWalkSwitchDirty_0048ea40(void) {
    __asm {
        call    func_0048f910
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   34h
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0x2005
        _emit   75h
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        cmp     eax, 0x2002
        mov     eax, dword ptr [g_xformDirtyFlags]
        _emit   75h
        _emit   08h
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x00460420 (68b)
 *   push OFFSET g_data_00542978; call helper; if pause → ret;
 *   else store g_xformEntityIdx into g_fightGroupHead[+0x24],
 *   clear walk and g_fightGroupHead[+0x28], jmp T.
 */
extern unsigned int g_data_00542978;
extern void func_00494140(void);
extern void func_00406b20(void);
__declspec(naked) void PushCallStoreClearJmp_00460420(void) {
    __asm {
        push    OFFSET g_data_00542978
        call    func_00494140
        mov     ecx, dword ptr [g_framePauseFlag]
        xor     eax, eax
        add     esp, 4
        cmp     ecx, eax
        _emit   75h
        _emit   2ah
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [ecx*4 + 0x24], edx
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x28], eax
        jmp     func_00406b20
        ret
    }
}

/* @addr 0x0048fee0 (68b)
 *   call F1; pause → ret; swap g_walkCallback ↔ g_xformEntityIdx;
 *   call F2; pause → ret; call F3; pause → ret; jmp T.
 */
extern void func_00490fc0(void);
extern void func_00408190(void);
extern void func_004299a0(void);
extern void func_00490720(void);
__declspec(naked) void GuardedTripleCallSwapJmp_0048fee0(void) {
    __asm {
        call    func_00490fc0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   35h
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_xformEntityIdx], eax
        call    func_00408190
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    func_004299a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00490720
        ret
    }
}

/* @addr 0x004a1740 (68b)
 *   if g_eventQueueEnd != 0 jmp T0; else
 *   load g_fightGroupHead, set g_eventQueueWorkType = 0xfef20000,
 *   set fightGroup[+0x30] = 0x25a, set walk = 0x50000, set
 *   fightGroup[+0x6c] = walk, jmp T1.
 */
extern void func_004a1790(void);
extern void func_004a17d0(void);
__declspec(naked) void TestEqJmpInitFightGroup_004a1740(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueEnd]
        test    eax, eax
        _emit   74h
        _emit   05h
        jmp     func_004a1790
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_eventQueueWorkType], 0xfef20000
        mov     dword ptr [eax*4 + 0x30], 0x25a
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0x00050000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x6c], eax
        jmp     func_004a17d0
    }
}

/* @addr 0x004ac3a0 (68b)
 *   sub esp,0x10; call init helper. If non-zero result, run
 *   DirectInput-style IAT call(0x814, 0x100, &local) on
 *   g_dsoundDevice to query/test some property. Returns
 *   (~(neg eax==0))&local — i.e., result if call succeeded
 *   (eax=0) else 0.
 */
extern int func_004ac320(void);
extern void *g_dsoundDevice_005438e8;
extern void *g_iat_004d2244;
__declspec(naked) void DSoundQueryProperty_004ac3a0(void) {
    __asm {
        sub     esp, 0x10
        call    func_004ac320
        test    eax, eax
        _emit   75h
        _emit   04h
        add     esp, 0x10
        ret
        mov     ecx, dword ptr [g_dsoundDevice_005438e8]
        _emit   8dh
        _emit   44h
        _emit   24h
        _emit   00h
        push    eax
        push    0x100
        push    0x814
        push    ecx
        mov     dword ptr [esp + 0x18], 3
        call    dword ptr [g_iat_004d2244]
        mov     ecx, dword ptr [esp + 4]
        neg     eax
        sbb     eax, eax
        not     eax
        and     eax, ecx
        add     esp, 0x10
        ret
    }
}

/* @addr 0x004b4650 (68b)
 *   Sound channel disable gate.
 *   if g_soundEnabled (0x7affe4) == 0: ret;
 *   if g_soundDisabled1 (0x7afff4) != 0: ret;
 *   if g_soundDisabled2 (0x7afff0) != 0: ret;
 *   if arg0 != 0: call IAT[0x7b000c](0, 0, 0xffff)
 *   set byte [0x4f4b4c] = 0xff; set [0x7afff4] = 1; ret.
 */
extern unsigned int g_data_007affe4;
extern unsigned int g_data_007afff4;
extern unsigned int g_data_007afff0;
extern unsigned char g_byte_004f4b4c;
extern void *g_iat_007b000c;
__declspec(naked) void SoundDisableIfActive_004b4650(void) {
    __asm {
        mov     eax, dword ptr [g_data_007affe4]
        test    eax, eax
        _emit   74h
        _emit   3ah
        mov     eax, dword ptr [g_data_007afff4]
        test    eax, eax
        _emit   75h
        _emit   31h
        mov     eax, dword ptr [g_data_007afff0]
        test    eax, eax
        _emit   75h
        _emit   28h
        mov     eax, dword ptr [esp + 4]
        test    eax, eax
        _emit   74h
        _emit   0fh
        push    0xffff
        push    0
        push    0
        call    dword ptr [g_iat_007b000c]
        mov     byte ptr [g_byte_004f4b4c], 0xff
        mov     dword ptr [g_data_007afff4], 1
        ret
    }
}

/* @addr 0x004c54d0 (68b)
 *   CRT _new_handler-style malloc retry: takes (size, retry_flag).
 *   Calls func_004c5520(size); if NULL and retry_flag, invokes
 *   func_004c6ec0(size) and loops back. Returns NULL if size > -32
 *   (overflow guard).
 */
extern void *func_004c5520(unsigned int n);
extern int func_004c6ec0(unsigned int n);
__declspec(naked) void TryAllocWithHandler_004c54d0(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        cmp     esi, -32
        push    edi
        _emit   77h
        _emit   34h
        test    esi, esi
        _emit   75h
        _emit   05h
        mov     esi, 1
        mov     edi, dword ptr [esp + 0x10]
loop_top:
        cmp     esi, -32
        _emit   77h
        _emit   0bh
        push    esi
        call    func_004c5520
        add     esp, 4
        jmp     short skip_zero
        xor     eax, eax
skip_zero:
        test    eax, eax
        _emit   75h
        _emit   13h
        test    edi, edi
        _emit   74h
        _emit   0fh
        push    esi
        call    func_004c6ec0
        add     esp, 4
        test    eax, eax
        jne     loop_top
        xor     eax, eax
        pop     edi
        pop     esi
        ret
    }
}

/* @addr 0x004284a0 (69b)
 *   inc g_state_004d57ac, push 0x004284c0 onto stack[idx*4],
 *   jmp T1, 5 nops align;
 *   tail (at 0x4284c0): test dirty&4; if set, jmp T2;
 *   else dec g_eventQueueChild, if zero jmp T2, else jmp 0x4284a0
 *   (loop back to entry).
 */
extern void func_00428680(void);
extern void func_0041f780_pp(void);
__declspec(naked) void GuardedLoopWithCallback_004284a0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], 0x004284c0
        jmp     func_00428680
        nop
        nop
        nop
        nop
        nop
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   05h
        jmp     func_0041f780_pp
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        _emit   74h
        _emit   05h
        _emit   0e9h
        _emit   0c0h
        _emit   0ffh
        _emit   0ffh
        _emit   0ffh
        jmp     func_0041f780_pp
    }
}

/* @addr 0x0042f850 (69b)
 *   eax = [0x52aac4]; cmp eax, 2; mov [walk] = eax; jne +5; jmp T1.
 *   else: mov fightGroupHead = [0x52ab10]; call F1; pause → ret;
 *   mov [g_baseSel*4 + 0x64] = walk; jmp T2.
 */
extern unsigned int g_data_0052aac4;
extern unsigned int g_data_0052ab10;
extern unsigned int g_baseSel_00542060;
extern void func_0042f840(void);
extern void func_00430e60(void);
extern void func_0042f8a0(void);
__declspec(naked) void DispatchOrInitFightGroup_0042f850(void) {
    __asm {
        mov     eax, dword ptr [g_data_0052aac4]
        cmp     eax, 2
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_0042f840
        mov     eax, dword ptr [g_data_0052ab10]
        mov     dword ptr [g_fightGroupHead], eax
        call    func_00430e60
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x64], ecx
        jmp     func_0042f8a0
        ret
    }
}

/* @addr 0x004667a0 (69b)
 *   load g_fightGroupHead, g_eventQueueEnd; push 0x4eaa58;
 *   eax = [fightGroup*4+0x64] - 0x4ccc; mov walk=eax;
 *   mov [eventQueueEnd*4+0x64]=eax; call F; add esp,4; ret.
 *   Then 15 NOPs and a tail-jmp (entry at +0x40).
 */
extern unsigned int g_data_004eaa58;
extern void func_0041f830(void);
__declspec(naked) void StoreFightFieldCallTailJmp_004667a0(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueEnd]
        push    OFFSET g_data_004eaa58
        mov     eax, dword ptr [eax*4 + 0x64]
        sub     eax, 0x4ccc
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x64], eax
        call    func_004594f0
        add     esp, 4
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
        nop
        nop
        nop
        jmp     func_0041f830
    }
}

/* @addr 0x0048e400 (69b)
 *   ecx = walk; edx = fightGroupHead; eax = 0x541ee8 >> 2;
 *   eax = eax + ecx*2; if fightGroupHead == [0x538158], ecx=0
 *   else ecx=1; eax += ecx; store eax→g_scaledInit;
 *   load ecx=[0x53a498]; store ecx→walk; store ecx→[eax*4+0]; ret.
 */
extern unsigned int g_data_00538158;
extern unsigned int g_data_0053a498;
__declspec(naked) void ScaledIndexConditionalAdd_0048e400(void) {
    __asm {
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0x00541ee8
        push    esi
        mov     esi, dword ptr [g_data_00538158]
        shr     eax, 2
        lea     eax, [eax + ecx*2]
        xor     ecx, ecx
        cmp     edx, esi
        _emit   74h
        _emit   05h
        mov     ecx, 1
        add     eax, ecx
        mov     ecx, dword ptr [g_data_0053a498]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0], ecx
        pop     esi
        ret
    }
}

/* @addr 0x0048e590 (69b)
 *   eax = arg0 >> 2 → g_eventQueueTotal; ecx = [eax*4+0] → scaled;
 *   if g_fightGroupHead != [0x538158]: ecx = [eax*4+4] → scaled;
 *   eax = [ecx*4+0]; store → walk; ret.
 */
extern unsigned int g_eventQueueTotal;
__declspec(naked) void ScaledIndexCondCopy_0048e590(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     edx, dword ptr [g_fightGroupHead]
        sar     eax, 2
        push    esi
        mov     esi, dword ptr [g_data_00538158]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        cmp     edx, esi
        mov     dword ptr [g_scaledInit_00542044], ecx
        _emit   74h
        _emit   0dh
        mov     ecx, dword ptr [eax*4 + 4]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     eax, dword ptr [ecx*4 + 0]
        pop     esi
        mov     dword ptr [g_walkCallback], eax
        ret
    }
}

/* @addr 0x004a1ba0 (69b)
 *   push 0xd; call helper; if eax == 0 jmp set-zero-tail.
 *   else: if [0xab4334] != 0: jmp store-1-tail.
 *   if [0x4f2fc8] != 0: jmp store-1-tail.
 *   else: store 1 → [0x4f2fc8] (using mov reg form); ret eax=1.
 *   set-zero-tail: store 0 → [0x4f2fc8]; xor eax,eax; ret.
 *   store-1-tail: store 1 → [0x4f2fc8] (mov imm32 form); xor eax,eax; ret.
 */
extern unsigned int g_data_00ab4334;
extern unsigned int g_data_004f2fc8;
extern int func_004b5450(int);
__declspec(naked) void TestQueueGateState_004a1ba0(void) {
    __asm {
        push    0x0d
        call    func_004b5450
        add     esp, 4
        test    eax, eax
        _emit   74h
        _emit   2ah
        mov     eax, dword ptr [g_data_00ab4334]
        test    eax, eax
        _emit   75h
        _emit   14h
        mov     eax, dword ptr [g_data_004f2fc8]
        test    eax, eax
        _emit   75h
        _emit   0bh
        mov     eax, 1
        mov     dword ptr [g_data_004f2fc8], eax
        ret
        mov     dword ptr [g_data_004f2fc8], 1
        xor     eax, eax
        ret
        mov     dword ptr [g_data_004f2fc8], 0
        xor     eax, eax
        ret
    }
}

/* @addr 0x004ac150 (69b)
 *   ecx = g_fightGroupHead; edx = [0x538158]; eax = [0x53a510];
 *   walk = eax; if ecx == edx, skip override; else
 *     eax = [0x52aafc]; walk = eax;
 *   edx = dirty; ecx = 4; edx |= 4; flag if eax == 0; store edx;
 *   if eax == 0: ret; else clear bit 4 (xor): store edx ^ 4.
 */
extern unsigned int g_data_0052aafc;
extern unsigned int g_data_0053a510;
__declspec(naked) void DispatchSetDirtyToggle_004ac150(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_data_00538158]
        mov     eax, dword ptr [g_data_0053a510]
        cmp     ecx, edx
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   0ah
        mov     eax, dword ptr [g_data_0052aafc]
        mov     dword ptr [g_walkCallback], eax
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     ecx, 4
        or      edx, ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   09h
        mov     eax, edx
        xor     eax, ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x004b8f50 (70b)
 *   ecx = [0xab4e2c]; edx = [0xab4e30]; eax = [0x52aac4];
 *   if ecx != edx: store ecx → [0xab4e30].
 *   if eax == 2: eax = [0x53a50c]; eax *= 3; ecx = eax*2 + 0x4f6240;
 *     store ecx → [0xab4e2c]; ret.
 *   else: edx = eax*3; eax = edx*2 + 0x4f62a8; store → [0xab4e2c]; ret.
 */
extern unsigned int g_data_00ab4e2c;
extern unsigned int g_data_00ab4e30;
extern unsigned int g_data_0053a50c;
__declspec(naked) void DispatchScaledLEA_004b8f50(void) {
    __asm {
        mov     ecx, dword ptr [g_data_00ab4e2c]
        mov     edx, dword ptr [g_data_00ab4e30]
        mov     eax, dword ptr [g_data_0052aac4]
        cmp     ecx, edx
        _emit   74h
        _emit   06h
        mov     dword ptr [g_data_00ab4e30], ecx
        cmp     eax, 2
        _emit   75h
        _emit   16h
        mov     eax, dword ptr [g_data_0053a50c]
        lea     eax, [eax + eax*2]
        lea     ecx, [eax*2 + 0x004f6240]
        mov     dword ptr [g_data_00ab4e2c], ecx
        ret
        lea     edx, [eax + eax*2]
        lea     eax, [edx*2 + 0x004f62a8]
        mov     dword ptr [g_data_00ab4e2c], eax
        ret
    }
}

/* @addr 0x00440990 (71b)
 *   call F1; if !pause: load g_scaledInit; copy [+0x24]→g_xformEntityIdx,
 *   [+0x28]→g_eventQueueIdx; eax = g_walkCallback;
 *   if eax == 2: jmp T (0x407030); else call F2; load pause; ret.
 */
extern void func_00408cb0(void);
extern void func_00407400(void);
extern void func_00407030(void);
__declspec(naked) void GuardedCallStoreSlotsCmp_00440990(void) {
    __asm {
        call    func_00408cb0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   33h
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     edx, dword ptr [eax*4 + 0x28]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_eventQueueIdx], edx
        cmp     eax, 2
        _emit   74h
        _emit   0bh
        call    func_00407400
        mov     eax, dword ptr [g_framePauseFlag]
        ret
        jmp     func_00407030
    }
}

/* @addr 0x00470cc0 (71b)
 *   eax = arg0 >> 2 → g_eventQueueEnd; clears g_currentNodeFlags;
 *   walks 3 entries through [eax*4+0]: stores them into
 *   g_eventQueueNotMask, g_xformEntityIdx, and g_walkCallback (1st);
 *   each step inc eax + restore to g_eventQueueEnd; jmp T.
 */
extern void func_00470d10(void);
__declspec(naked) void PackedLoadAdvanceJmp_00470cc0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     dword ptr [g_currentNodeFlags], 0
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     edx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_00470d10
    }
}

/* @addr 0x00438bf0 (72b)
 *   eax = baseSel*4+0x34; walk = eax;
 *   if eax == 0x10: walk = 2; if eax == 0x11: walk = 7;
 *   if eax == 5 or 6: jmp T1; else jmp T2.
 *   The `if==X then walk=N` arms keep eax intact for next cmp.
 */
extern void func_00438c40(void);
extern void func_00438ee0(void);
__declspec(naked) void DispatchSwitchWalkCmp_00438bf0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x34]
        cmp     eax, 0x10
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0ah
        mov     eax, 2
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 0x11
        _emit   75h
        _emit   0ah
        mov     eax, 7
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 5
        _emit   75h
        _emit   05h
        jmp     func_00438c40
        cmp     eax, 6
        _emit   75h
        _emit   05h
        jmp     func_00438c40
        jmp     func_00438ee0
    }
}

/* @addr 0x00438c50 (72b)
 *   call F1; pause → ret;
 *   if (dirty & 1): jmp T1.
 *   call F2; pause → ret;
 *   if (dirty & 1): jmp T2;
 *   else: walk = 9; jmp T3.
 */
extern void func_0048eec0(void);
extern void func_00438f60(void);
extern void func_0048e780(void);
extern void func_00438ca0(void);
extern void func_00471190(void);
__declspec(naked) void GuardedDirtyDispatch_00438c50(void) {
    __asm {
        call    func_0048eec0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   39h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_00438f60
        call    func_0048e780
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_00438ca0
        mov     dword ptr [g_walkCallback], 9
        jmp     func_00471190
        ret
    }
}

/* @addr 0x00448fc0 (72b)
 *   ecx = [baseSel*4+0x4c]; mov fightGroupHead = ecx;
 *   call F1; pause → ret; call F2; pause → ret;
 *   walk = 2; g_acc_00542078 = 4; jmp T.
 */
extern unsigned int g_acc_00542078;
extern void func_004089e0(void);
extern void func_004b8fa0(void);
extern void func_00473f50(void);
__declspec(naked) void LoadStoreDoubleCallSet_00448fc0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x4c]
        mov     dword ptr [g_fightGroupHead], ecx
        call    func_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   27h
        call    func_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   19h
        mov     dword ptr [g_walkCallback], 2
        mov     dword ptr [g_acc_00542078], 4
        jmp     func_00473f50
        ret
    }
}

/* @addr 0x00470ee0 (72b)
 *   PushPopWalk save/restore around setting walk = 0x1006 and
 *   storing it into g_baseSel[+0x74]. Symmetric stack frame.
 */
__declspec(naked) void PushPopWalkSet1006_00470ee0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_walkCallback]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x1006
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x74], eax
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x004826f0 (72b)
 *   Two-entry block: 9-byte mini-wrapper at 0x4826f0
 *   (push lit; call F; add esp, 4; ret) + 2 NOPs +
 *   the main 56-byte body at 0x482700: call F1, pause→ret,
 *   call F2, pause→ret, push lit, call F3, pause→jmp T.
 */
extern unsigned int g_data_004edf38;
extern unsigned int g_data_004edf68;
extern void func_00494580(void);
extern void func_00482740(void);
extern void func_00488c00(void);
__declspec(naked) void TwoEntryWrapperGuarded_004826f0(void) {
    __asm {
        push    OFFSET g_data_004edf38
        call    func_004594f0
        add     esp, 4
        ret
        nop
        nop
        call    func_00494580
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        call    func_00482740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        push    OFFSET g_data_004edf68
        call    func_004594f0
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00488c00
        ret
    }
}

/* @addr 0x004a2270 (72b)
 *   walk = 0; [0x541dc0] = 0; call F1; pause → ret;
 *   call F2; pause → ret; walk = 0x1000;
 *   store walk → [baseSel*4 + 0xc]; ret.
 */
extern unsigned int g_data_00541dc0;
extern void func_004265d0(void);
extern void func_00404680(void);
__declspec(naked) void ClearTwoCallSetStore_004a2270(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [g_data_00541dc0], 0
        call    func_004265d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   25h
        call    func_00404680
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   17h
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x1000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x0c], eax
        ret
    }
}

/* @addr 0x00459fc0 (73b)
 *   Inc g_state_004d57ac, push 0x459fe0 onto stack[idx*4], jmp T;
 *   5 nops align; tail at 0x459fe0:
 *   double "dec g_eventQueueChild; if zero jmp T1" with same target,
 *   else jmp 0x459fc0 (loop back to entry).
 */
extern void func_0045a010(void);
extern void func_00459510(void);
__declspec(naked) void GuardedTwiceLoopback_00459fc0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], 0x00459fe0
        jmp     func_0045a010
        nop
        nop
        nop
        nop
        nop
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        _emit   75h
        _emit   05h
        jmp     func_00459510
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        _emit   75h
        _emit   05h
        jmp     func_00459510
        _emit   0e9h
        _emit   0b7h
        _emit   0ffh
        _emit   0ffh
        _emit   0ffh
    }
}

/* @addr 0x0048bbf0 (73b)
 *   eax = 0x8a9dcbef; [0x53e35c] = 0xfedcba98; walk = eax;
 *   [0x541dbc] = eax. Then 3 chained calls with pause-test → ret;
 *   final call → jmp T.
 */
extern unsigned int g_data_0053e35c;
extern unsigned int g_data_00541dbc;
extern void func_00425b20(void);
extern void func_0049cbf0(void);
extern void func_004051b0(void);
extern void func_0045c8e0(void);
__declspec(naked) void SentinelInitTripleCall_0048bbf0(void) {
    __asm {
        mov     eax, 0x8a9dcbef
        mov     dword ptr [g_data_0053e35c], 0xfedcba98
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_data_00541dbc], eax
        call    func_00425b20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   21h
        call    func_0049cbf0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    func_004051b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0045c8e0
        ret
    }
}

/* @addr 0x0048f6d0 (73b)
 *   call F; pause → ret; if (dirty & 4) → ret;
 *   ecx = fightGroupHead; edx = [0x538158]; eax = [0x542038];
 *   xformEntityIdx = eax; cmp ecx,edx; if !=, eax = [0x54203c],
 *   xformEntityIdx = eax; edx = g_scaledInit_00542044;
 *   [eax*4+0] = edx; ret.
 */
extern unsigned int g_data_00542038;
extern unsigned int g_data_0054203c;
extern void func_0048f350(void);
__declspec(naked) void GuardedDirtyXformFromTable_0048f6d0(void) {
    __asm {
        call    func_0048f350
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3ah
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   31h
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_data_00538158]
        mov     eax, dword ptr [g_data_00542038]
        cmp     ecx, edx
        mov     dword ptr [g_xformEntityIdx], eax
        _emit   74h
        _emit   0ah
        mov     eax, dword ptr [g_data_0054203c]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [eax*4 + 0], edx
        ret
    }
}

/* @addr 0x00492870 (73b)
 *   if [0x54356c] != 0 → ret;
 *   eax = [0x53a404]; mov walk = eax; if eax != 0 → ret;
 *   mov g_eventQueueCurrent = eax (=0); call F; pause → ret;
 *   cl = byte dirty; eax = 1; if (al & cl) == 0, jmp store-tail;
 *   eventQueueCurrent = 1; walk = 1; jmp T.
 */
extern unsigned int g_data_0054356c;
extern unsigned int g_data_0053a404;
extern void func_004929e0(void);
extern void func_004928c0(void);
__declspec(naked) void DispatchGuardedDirtyTest_00492870(void) {
    __asm {
        mov     eax, dword ptr [g_data_0054356c]
        test    eax, eax
        _emit   75h
        _emit   3fh
        mov     eax, dword ptr [g_data_0053a404]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   31h
        mov     dword ptr [g_eventQueueCurrent], eax
        call    func_004929e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1eh
        mov     cl, byte ptr [g_xformDirtyFlags]
        mov     eax, 1
        test    cl, al
        _emit   74h
        _emit   05h
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], eax
        jmp     func_004928c0
        ret
    }
}

/* @addr 0x004ab700 (73b)
 *   Audio mixer step: eax = [0x4d5100] + [0x4d5104]; sar 31 (sign);
 *   eax % 0x10000; pushes ecx, eax; calls helper. Stores running
 *   sum back, low-16 to walk.
 */
extern unsigned int g_data_004d5100;
extern unsigned int g_data_004d5104;
extern unsigned int g_data_0053814c;
extern void func_00404af0(int, int);
__declspec(naked) void AudioMixerStep_004ab700(void) {
    __asm {
        mov     eax, dword ptr [g_data_004d5100]
        mov     edx, dword ptr [g_data_004d5104]
        mov     ecx, dword ptr [g_walkCallback]
        add     eax, edx
        push    esi
        mov     esi, eax
        sar     esi, 0x1f
        mov     dword ptr [g_data_004d5100], eax
        add     esi, eax
        and     eax, 0xffff
        add     edx, esi
        push    eax
        push    ecx
        mov     dword ptr [g_data_0053814c], ecx
        mov     dword ptr [g_data_004d5104], edx
        mov     dword ptr [g_walkCallback], eax
        call    func_00404af0
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        pop     esi
        ret
    }
}

/* @addr 0x004b7160 (73b)
 *   Tokenizer: walks string at *arg0, finds first ':' (sets flag),
 *   then for each char after the ':', writes the next char from
 *   arg1 (or ' ' if arg1 is empty). Effectively a one-shot
 *   substitute-after-delim helper.
 */
__declspec(naked) void StringSubstituteAfterColon_004b7160(void) {
    __asm {
        push    ebp
        mov     ebp, dword ptr [esp + 8]
        push    esi
        xor     esi, esi
        mov     ecx, dword ptr [ebp + 0]
        xor     eax, eax
        cmp     byte ptr [ecx], 0
        _emit   74h
        _emit   34h
        push    edi
        mov     edi, dword ptr [esp + 0x14]
loop_top:
        cmp     byte ptr [eax + ecx*1], 0x3a
        _emit   75h
        _emit   0ch
        test    esi, esi
        _emit   75h
        _emit   0ch
        mov     esi, 1
        inc     eax
        _emit   0ebh
        _emit   12h
        test    esi, esi
        _emit   74h
        _emit   0eh
        mov     dl, byte ptr [edi]
        test    dl, dl
        _emit   74h
        _emit   03h
        inc     edi
        _emit   0ebh
        _emit   02h
        mov     dl, 0x20
        mov     byte ptr [eax + ecx*1], dl
        mov     ecx, dword ptr [ebp + 0]
        inc     eax
        cmp     byte ptr [eax + ecx*1], 0
        jne     loop_top
        pop     edi
        pop     esi
        pop     ebp
        ret
    }
}

/* @addr 0x004cd260 (73b)
 *   CRT _osfile / _osfhnd handle lookup. Returns a pointer or
 *   sets errno/EBADF on out-of-range / closed handle. The byte
 *   table at +4 records FOPEN bit (0x01).
 */
extern unsigned int g_data_00fa0ee0;
extern void *g_data_00fa0de0;
extern int *func_004c8ba0(void);
extern int *func_004c8bb0(void);
__declspec(naked) void CRTHandleLookup_004cd260(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [g_data_00fa0ee0]
        cmp     eax, ecx
        _emit   73h
        _emit   21h
        mov     ecx, eax
        and     eax, 0x1f
        sar     ecx, 5
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [ecx*4 + g_data_00fa0de0]
        mov     cl, byte ptr [eax + edx*4 + 4]
        lea     eax, [eax + edx*4]
        test    cl, 1
        _emit   74h
        _emit   03h
        mov     eax, dword ptr [eax]
        ret
        call    func_004c8ba0
        mov     dword ptr [eax], 9
        call    func_004c8bb0
        mov     dword ptr [eax], 0
        or      eax, 0xffffffff
        ret
    }
}

/* @addr 0x00431d50 (74b)
 *   walk = 0x1921f - walk; mov g_eventQueueWorkType = walk; call F1;
 *   pause → ret; g_acc_00542078 = walk; call F2; pause → ret;
 *   g_eventQueueWorkType = walk; ret.
 */
extern void func_00424410(void);
extern void func_00424350(void);
__declspec(naked) void TimeBudgetSubCallChain_00431d50(void) {
    __asm {
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, 0x0001921f
        sub     eax, ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_eventQueueWorkType], eax
        call    func_00424410
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   24h
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_acc_00542078], eax
        call    func_00424350
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ch
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [g_eventQueueWorkType], ecx
        ret
    }
}

/* @addr 0x00433c10 (74b)
 *   Dual scaled-init helper: stores 0x53a1a0>>2 into g_scaledInit
 *   and 0x53a518>>2 into g_xformEntityIdx; if g_fightGroupHead !=
 *   [0x538158], also overrides g_scaledInit with the second value.
 *   Then clears g_walkCallback and the indexed slot.
 */
__declspec(naked) void DualScaledInitClear_00433c10(void) {
    __asm {
        mov     edx, dword ptr [g_fightGroupHead]
        push    esi
        mov     esi, dword ptr [g_data_00538158]
        mov     eax, 0x0053a1a0
        mov     ecx, 0x0053a518
        shr     eax, 2
        shr     ecx, 2
        cmp     edx, esi
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        _emit   74h
        _emit   07h
        mov     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax*4 + 0], 0
        pop     esi
        ret
    }
}

/* @addr 0x00434ec0 (74b)
 *   push lit; call F; if pause → ret;
 *   eax = [0x535ddc]; mov walk = eax; 4-way range dispatch:
 *   if eax > 0x20000 → jmp T1, > 0x18000 → T2, > 0x10000 → T3,
 *   else → T4.
 */
extern unsigned int g_data_004e4a04;
extern unsigned int g_data_00535ddc;
extern void func_0043a950(void);
extern void func_00434f90(void);
extern void func_00435030(void);
extern void func_00434f10(void);
extern void func_004390f0(void);
__declspec(naked) void RangeDispatch4_00434ec0(void) {
    __asm {
        push    OFFSET g_data_004e4a04
        call    func_0043a950
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   33h
        mov     eax, dword ptr [g_data_00535ddc]
        cmp     eax, 0x20000
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   05h
        jmp     func_00434f90
        cmp     eax, 0x18000
        _emit   7eh
        _emit   05h
        jmp     func_00435030
        cmp     eax, 0x10000
        _emit   7eh
        _emit   05h
        jmp     func_00434f10
        jmp     func_004390f0
        ret
    }
}

/* @addr 0x00489030 (74b)
 *   Save fightGroupHead → g_pendingNodeType (used as scratch);
 *   load [baseSel*4+0x38] → fightGroupHead; walk = 0x10000;
 *   eventQueueCurrent = 0x3c; call F; if !pause: restore
 *   fightGroupHead from g_pendingNodeType; ret.
 */
extern void func_0048fb40(void);
__declspec(naked) void SaveSwapCallRestore_00489030(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [g_pendingNodeType], eax
        mov     edx, dword ptr [ecx*4 + 0x38]
        mov     dword ptr [g_walkCallback], 0x10000
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_eventQueueCurrent], 0x3c
        call    func_0048fb40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ah
        mov     eax, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_fightGroupHead], eax
        ret
    }
}

/* @addr 0x004a19c0 (74b)
 *   walk = g_eventQueueEnd; if non-zero: push 0x25b, call F1;
 *   if (dirty & 4): jmp T1; else
 *   ecx = g_scaledInit; walk = 0x50000; [ecx*4+0x6c] = 0x50000;
 *   jmp T2.  If walk was 0: jmp T3.
 */
extern void func_004a1a10(void);
extern void func_00404a00(int);
extern void func_004a1a50(void);
__declspec(naked) void GuardedCallDirtyJmpInit_004a19c0(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueEnd]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_004a1a10
        push    0x25b
        call    func_00404a00
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        test    al, 4
        _emit   74h
        _emit   05h
        jmp     func_0041f780_pp
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, 0x00050000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x6c], eax
        jmp     func_004a1a50
    }
}

/* @addr 0x004a1b00 (74b)
 *   Input poll: if (byte_4d50b8 & 0x02) → 1;
 *               if (byte_4d50b4 & 0x40) → 1;
 *               if (byte_4d50b8 & 0x01) → 1;
 *               if (byte_4d50b4 & 0x10) → 1;
 *               if (byte_4d50b4 & 0x20) → 1;
 *               else (byte_4d50b8 & 0x04) >> 2 (0 or 1).
 */
extern unsigned char g_byte_004d50b8;
extern unsigned char g_byte_004d50b4;
__declspec(naked) void InputPollFlagBits_004a1b00(void) {
    __asm {
        mov     al, byte ptr [g_byte_004d50b8]
        test    al, 2
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        mov     cl, byte ptr [g_byte_004d50b4]
        test    cl, 0x40
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    al, 1
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    cl, 0x10
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    cl, 0x20
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        movsx   eax, al
        and     eax, 4
        shr     eax, 2
        ret
    }
}

/* @addr 0x004b2840 (74b)
 *   if [0x7af940] != 0: call helper; load 3 globals as args;
 *   push 9 fixed-args + 3 globals (DirectDraw Blt-style call);
 *   IAT call; tail-jmp to second IAT slot. Else: ret.
 */
extern unsigned int g_data_007af940;
extern unsigned int g_data_007af934;
extern unsigned int g_data_007af94c;
extern unsigned int g_data_007af938;
extern void *g_iat_004d2034;
extern void *g_iat_004d2040;
extern void func_004b2930(void);
__declspec(naked) void DDrawBltJmp_004b2840(void) {
    __asm {
        mov     eax, dword ptr [g_data_007af940]
        test    eax, eax
        _emit   74h
        _emit   40h
        call    func_004b2930
        mov     eax, dword ptr [g_data_007af934]
        mov     ecx, dword ptr [g_data_007af94c]
        push    0
        push    eax
        mov     edx, dword ptr [g_data_007af938]
        push    ecx
        push    0xf0
        push    0
        push    0
        push    0
        push    0xf0
        push    0x140
        push    0
        push    0
        push    edx
        call    dword ptr [g_iat_004d2034]
        jmp     dword ptr [g_iat_004d2040]
        ret
    }
}

/* @addr 0x00426550 (75b)
 *   eax = 0x53a1c0 >> 2 → g_scaledInit; eax = g_currentNodeFlags;
 *   if eax == 2: sprintf-style 3-arg call with format 0x4d56c8
 *   else format 0x4d56d0; both use 0x53a1c0 as buffer.
 */
extern unsigned int g_data_004d56c8;
extern unsigned int g_data_004d56d0;
extern unsigned int g_data_0053a1c0;
extern void func_004c5580(void *buf, void *fmt, unsigned int arg);
__declspec(naked) void Sprintf2WaySelect_00426550(void) {
    __asm {
        mov     eax, 0x0053a1c0
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [g_currentNodeFlags]
        cmp     eax, 2
        _emit   75h
        _emit   1ah
        mov     ecx, dword ptr [g_walkCallback]
        push    ecx
        push    OFFSET g_data_004d56c8
        push    OFFSET g_data_0053a1c0
        call    func_004c5580
        add     esp, 0x0c
        ret
        mov     edx, dword ptr [g_walkCallback]
        push    edx
        push    OFFSET g_data_004d56d0
        push    OFFSET g_data_0053a1c0
        call    func_004c5580
        add     esp, 0x0c
        ret
    }
}

/* @addr 0x0042f4f0 (75b)
 *   PushPop save/restore of g_pendingNodeType across two
 *   push-arg calls (0x249, 0x24a) to func_004049d0.
 */
extern void func_004049d0(int);
__declspec(naked) void PushPopPendingTwoCalls_0042f4f0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_pendingNodeType]
        inc     eax
        push    0x249
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    func_004049d0
        add     esp, 4
        push    0x24a
        call    func_004049d0
        mov     eax, dword ptr [g_state_004d57ac]
        add     esp, 4
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x004463b0 (75b)
 *   Slot field swap: copies [g_baseSel*4+0x4c]→g_scaledInit;
 *   [g_eventQueueIdx*4+0x3c]→walk; copies into eax-slot+0x3c.
 *   Then re-reads idx slot's +0x3c → walk and back into ecx-slot.
 */
__declspec(naked) void SlotFieldSwap3c_004463b0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_eventQueueIdx]
        mov     eax, dword ptr [eax*4 + 0x4c]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [ecx*4 + 0x3c]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x3c], ecx
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [edx*4 + 0x3c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x3c], eax
        ret
    }
}

/* @addr 0x00473d50 (75b)
 *   call F1; pause → ret; if (dirty & 4) jmp T1; call F2;
 *   pause → ret; call F3; pause → ret; walk = 0x4ec9e8 >> 2;
 *   jmp T2.
 */
extern void func_00405420(void);
extern void func_00473ed0(void);
extern void func_00473da0(void);
__declspec(naked) void GuardedDirty4ScaledJmp_00473d50(void) {
    __asm {
        call    func_00405420
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3ch
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     func_00473ed0
        call    func_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   20h
        call    func_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, 0x004ec9e8
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        jmp     func_00473da0
        ret
    }
}

/* @addr 0x0048e630 (75b)
 *   eax = arg0 >> 2 → g_eventQueueTotal; ecx = [eax*4+0];
 *   walk = ecx; inc eax → g_eventQueueTotal; call F; pause → ret;
 *   load eax again, edx = [eax*4+0]; xformEntityIdx = edx;
 *   inc eax → g_eventQueueTotal; jmp T.
 */
extern void func_0049cb90(void);
extern void func_0049cbd0(void);
__declspec(naked) void PackedAdvanceCallContinue_0048e630(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        call    func_0049cb90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     edx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_eventQueueTotal], eax
        jmp     func_0049cbd0
        ret
    }
}

/* @addr 0x004a4260 (75b)
 *   pendingNodeType = 0x4200b0 (a func ptr stored as data);
 *   eventQueueWorkType = 0x1000; call F; pause → ret;
 *   eax = 2; [0x543800] = -1; walk = eax; [0x52aac4] = eax;
 *   eventQueueWorkType = 0; jmp T.
 */
extern unsigned int g_data_00543800;
extern void func_0049cb60(void);
extern void func_00489f50(void);
__declspec(naked) void InitDispatchersJmp_004a4260(void) {
    __asm {
        mov     dword ptr [g_pendingNodeType], 0x004200b0
        mov     dword ptr [g_eventQueueWorkType], 0x1000
        call    func_0049cb60
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   28h
        mov     eax, 2
        mov     dword ptr [g_data_00543800], 0xffffffff
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_data_0052aac4], eax
        mov     dword ptr [g_eventQueueWorkType], 0
        jmp     func_00489f50
        ret
    }
}

/* @addr 0x004c4950 (75b)
 *   IAT-driven driver query: call IAT[0x4d21b8](0); if 0 → ret.
 *   Else: load IAT[0x4d203c]; query (handle, 0xc) >= 0xf?
 *   if so query (handle, 0xe) == 1; if so call IAT[0x4d21a8](0,handle).
 *   Returns either 1 or 0 in eax.
 */
extern void *g_iat_004d21b8;
extern void *g_iat_004d203c;
extern void *g_iat_004d21a8;
__declspec(naked) void IATDriverQuery_004c4950(void) {
    __asm {
        push    esi
        push    0
        call    dword ptr [g_iat_004d21b8]
        mov     esi, eax
        test    esi, esi
        _emit   75h
        _emit   02h
        pop     esi
        ret
        push    edi
        mov     edi, dword ptr [g_iat_004d203c]
        push    0x0c
        push    esi
        call    edi
        cmp     eax, 0x0f
        _emit   7ch
        _emit   1ah
        push    0x0e
        push    esi
        call    edi
        cmp     eax, 1
        _emit   75h
        _emit   10h
        push    esi
        push    0
        mov     edi, eax
        call    dword ptr [g_iat_004d21a8]
        mov     eax, edi
        pop     edi
        pop     esi
        ret
        xor     edi, edi
        push    esi
        push    edi
        call    dword ptr [g_iat_004d21a8]
        mov     eax, edi
        pop     edi
        pop     esi
        ret
    }
}

/* @addr 0x00470340 (76b)
 *   ecx = [fightGroupHead*4+0x18]; eax = walk + [ecx*4+0x34];
 *   stores eax both to g_eventQueueCurrent and back to [ecx*4+0x34];
 *   then eax = [fightGroupHead*4+0x58] - walk; same dual store.
 */
__declspec(naked) void DualFieldAddSubStore_00470340(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x18]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_scaledInit_00542044], ecx
        add     eax, dword ptr [ecx*4 + 0x34]
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_walkCallback]
        mov     eax, dword ptr [ecx*4 + 0x58]
        sub     eax, edx
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        ret
    }
}

/* @addr 0x004a1b50 (76b)
 *   InputPollFlagBits sibling: same shape but probes different bits
 *   in [0x4d50b8] / [0x4d50b4]. Tests 0x20 (cl), then loads
 *   [0x4d50b4] AS a dword (uses ah for 0x40, 0x10, 0x20 high-byte
 *   tests), then cl bit 0x10. Final fallback: (cl & 0x40) >> 6.
 */
__declspec(naked) void InputPollFlagBitsHalf_004a1b50(void) {
    __asm {
        mov     cl, byte ptr [g_byte_004d50b8]
        test    cl, 0x20
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        mov     eax, dword ptr [g_byte_004d50b4]
        test    ah, 0x40
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    cl, 0x10
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    ah, 0x10
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    ah, 0x20
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        movsx   eax, cl
        and     eax, 0x40
        shr     eax, 6
        ret
    }
}

/* @addr 0x004aa940 (76b)
 *   PushPopScaledInit save/restore wrapper around: load [0x54343c]
 *   into g_scaledInit, call helper, clear [0x54343c]. Standard
 *   "scoped global swap" pattern.
 */
extern unsigned int g_data_0054343c;
extern void func_00406790(void);
__declspec(naked) void PushPopScaledInit343c_004aa940(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_data_0054343c]
        mov     dword ptr [g_scaledInit_00542044], edx
        call    func_00406790
        mov     eax, dword ptr [g_state_004d57ac]
        mov     dword ptr [g_data_0054343c], 0
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x0041f780 (77b)
 *   eax = [g_baseSel*4+4] - 1 → g_scaledInit; edx = [eax*4+0]
 *   → g_walkCallback; [g_baseSel*4+4] = eax (decrement);
 *   eax = walk; eax >>= 24; → [g_baseSel*4+0x84];
 *   eax = walk & 0xffffff → walk; jmp eax.
 *   Hand-rolled tail-dispatch: pops a 24-bit "next" + 8-bit "tag"
 *   from a stack-of-callbacks, invokes the next.
 */
__declspec(naked) void StackPopDispatchTagged_0041f780(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 4]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx*4 + 4], eax
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_baseSel_00542060]
        sar     eax, 0x18
        mov     dword ptr [ecx*4 + 0x84], eax
        mov     eax, dword ptr [g_walkCallback]
        and     eax, 0xffffff
        mov     dword ptr [g_walkCallback], eax
        jmp     eax
    }
}

/* @addr 0x00428bd0 (77b)
 *   call F1; pause → ret;
 *   edx = g_fightGroupHead; ecx = [edx*4+0x24] → g_scaledInit;
 *   eax = [edx*4+0x28] → walk; ecx = [ecx*4+4]; cmp eax, ecx;
 *   if eax >= ecx: eax = ecx - 1 → walk; store walk → [edx*4+0x28];
 *   jmp T.
 */
extern void func_00406ba0(void);
__declspec(naked) void GuardedClampStoreJmp_00428bd0(void) {
    __asm {
        call    func_00406ba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3eh
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [edx*4 + 0x24]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [ecx*4 + 4]
        cmp     eax, ecx
        _emit   7ch
        _emit   08h
        lea     eax, [ecx - 1]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x28], eax
        jmp     func_004299a0
        ret
    }
}

/* @addr 0x00458c70 (77b)
 *   eventQueueCurrent = walk; pendingNodeType = (0x53a53c >> 2) + 0x3b;
 *   call F; if !pause: cmp g_eventQueueCurrent, walk;
 *   if jae: dirty |= 1; else: dirty &= ~1; ret.
 */
extern void func_004774d0(void);
__declspec(naked) void SetTagsCallCmpToggleDirty_00458c70(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, 0x0053a53c
        shr     ecx, 2
        add     ecx, 0x3b
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_pendingNodeType], ecx
        call    func_004774d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   23h
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     eax, dword ptr [g_walkCallback]
        cmp     edx, eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        _emit   73h
        _emit   08h
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x0047e640 (77b)
 *   walk = g_eventQueueNotMask; call F1; pause → ret;
 *   load g_fightGroupHead; eax = [head*4+0x70];
 *   push eax, push notMask; walk = eax; call F2 (mixer-like);
 *   add esp 8; restore [head*4+0x70] = eax; ret.
 */
extern void func_004906b0(void);
__declspec(naked) void NotMaskCallStore70_0047e640(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueNotMask]
        mov     dword ptr [g_walkCallback], eax
        call    func_004906b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   34h
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_eventQueueNotMask]
        mov     eax, dword ptr [ecx*4 + 0x70]
        push    eax
        push    edx
        mov     dword ptr [g_walkCallback], eax
        call    func_00404af0
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x70], eax
        ret
    }
}

/* @addr 0x004c9750 (77b)
 *   CRT signal/setjmp dispatch: arg = -2 → IAT[0x4d2118],
 *   -3 → IAT[0x4d2110], -4 → fetch [0xf9fc20] (no IAT call);
 *   each path sets the [0xf9fadc] flag to 1 first.
 */
extern unsigned int g_data_00f9fadc;
extern unsigned int g_data_00f9fc20;
extern void *g_iat_004d2118;
extern void *g_iat_004d2110;
__declspec(naked) void CRTSignalDispatch_004c9750(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     dword ptr [g_data_00f9fadc], 0
        cmp     eax, -2
        _emit   75h
        _emit   10h
        mov     dword ptr [g_data_00f9fadc], 1
        jmp     dword ptr [g_iat_004d2118]
        cmp     eax, -3
        _emit   75h
        _emit   10h
        mov     dword ptr [g_data_00f9fadc], 1
        jmp     dword ptr [g_iat_004d2110]
        cmp     eax, -4
        _emit   75h
        _emit   0fh
        mov     eax, dword ptr [g_data_00f9fc20]
        mov     dword ptr [g_data_00f9fadc], 1
        ret
    }
}

/* @addr 0x004392c0 (78b)
 *   Tail-dispatch on packed table. eax = arg0>>2 → g_scaledInit;
 *   ecx = [eax*4+0] → walk; advance idx; call F; pause → ret;
 *   eax = (g_scaledInit + walk) → g_scaledInit; eax = [g_scaledInit*4];
 *   walk = eax; jmp eax.
 */
extern void func_004ab630(void);
__declspec(naked) void PackedAdvanceCallTailJmp_004392c0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        call    func_004ab630
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   20h
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_walkCallback]
        add     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     eax
        ret
    }
}

/* @addr 0x0045d960 (78b)
 *   Dual-scaled-init helper: copies g_xformEntityIdx →
 *   g_eventQueueTotal, [0x53a498] → g_eventQueueWorkType;
 *   call F; pause → ret; copies g_scaledInit → g_eventQueueTotal,
 *   walk → g_eventQueueWorkType; call F again; pause → ret;
 *   jmp T.
 */
extern void func_0045d9b0(void);
__declspec(naked) void DualSwapTwoCallsJmp_0045d960(void) {
    __asm {
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_data_0053a498]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        call    func_0045d9b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_eventQueueTotal], edx
        mov     dword ptr [g_eventQueueWorkType], eax
        call    func_0045d9b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0041f830
        ret
    }
}

/* @addr 0x0048d4b0 (78b)
 *   if walk == 8: g_scaledInit = 0x542db8>>2; call F; pause → ret;
 *   if (dirty & 1) → ret; push 0x1392; call F2; add esp, 4; ret.
 *   else: g_scaledInit = 0x542db8>>2; jmp F.
 */
extern void func_0048d500(void);
extern void func_004be7a0(int);
__declspec(naked) void CmpEqInitCallElseJmp_0048d4b0(void) {
    __asm {
        cmp     dword ptr [g_walkCallback], 8
        _emit   75h
        _emit   32h
        mov     eax, 0x00542db8
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        call    func_0048d500
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   16h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   75h
        _emit   0dh
        push    0x1392
        call    func_004be7a0
        add     esp, 4
        ret
        mov     ecx, 0x00542db8
        shr     ecx, 2
        mov     dword ptr [g_scaledInit_00542044], ecx
        jmp     func_0048d500
    }
}

/* === Five 78b clones: dispatch at 0x004926e0 / 30 / 80 / d0 / 20 ===
 *
 * Same shape; only the final walk-value (6/5/4/3/2) and the
 * called helper (0x492920 vs 0x4929e0) differ.
 *
 *   if [0x54356c] != 0 → ret;
 *   eax = [0x53a404]; mov walk = eax; if eax != 0 → ret;
 *   mov eventQueueCurrent = eax; call F; pause → ret;
 *   cl = byte dirty; eax = 1; if (cl & al) != 0:
 *       eventQueueCurrent = 1.
 *   walk = N (literal); jmp T.
 */
extern void func_00492920(void);
__declspec(naked) void DispatchSetWalk6_004926e0(void) {
    __asm {
        mov     eax, dword ptr [g_data_0054356c]
        test    eax, eax
        _emit   75h
        _emit   44h
        mov     eax, dword ptr [g_data_0053a404]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   36h
        mov     dword ptr [g_eventQueueCurrent], eax
        call    func_00492920
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   23h
        mov     cl, byte ptr [g_xformDirtyFlags]
        mov     eax, 1
        test    cl, al
        _emit   74h
        _emit   05h
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], 6
        jmp     func_004928c0
        ret
    }
}

__declspec(naked) void DispatchSetWalk5_00492730(void) {
    __asm {
        mov     eax, dword ptr [g_data_0054356c]
        test    eax, eax
        _emit   75h
        _emit   44h
        mov     eax, dword ptr [g_data_0053a404]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   36h
        mov     dword ptr [g_eventQueueCurrent], eax
        call    func_00492920
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   23h
        mov     cl, byte ptr [g_xformDirtyFlags]
        mov     eax, 1
        test    cl, al
        _emit   74h
        _emit   05h
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], 5
        jmp     func_004928c0
        ret
    }
}

__declspec(naked) void DispatchSetWalk4_00492780(void) {
    __asm {
        mov     eax, dword ptr [g_data_0054356c]
        test    eax, eax
        _emit   75h
        _emit   44h
        mov     eax, dword ptr [g_data_0053a404]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   36h
        mov     dword ptr [g_eventQueueCurrent], eax
        call    func_00492920
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   23h
        mov     cl, byte ptr [g_xformDirtyFlags]
        mov     eax, 1
        test    cl, al
        _emit   74h
        _emit   05h
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], 4
        jmp     func_004928c0
        ret
    }
}

__declspec(naked) void DispatchSetWalk3_004927d0(void) {
    __asm {
        mov     eax, dword ptr [g_data_0054356c]
        test    eax, eax
        _emit   75h
        _emit   44h
        mov     eax, dword ptr [g_data_0053a404]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   36h
        mov     dword ptr [g_eventQueueCurrent], eax
        call    func_004929e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   23h
        mov     cl, byte ptr [g_xformDirtyFlags]
        mov     eax, 1
        test    cl, al
        _emit   74h
        _emit   05h
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], 3
        jmp     func_004928c0
        ret
    }
}

__declspec(naked) void DispatchSetWalk2_00492820(void) {
    __asm {
        mov     eax, dword ptr [g_data_0054356c]
        test    eax, eax
        _emit   75h
        _emit   44h
        mov     eax, dword ptr [g_data_0053a404]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   36h
        mov     dword ptr [g_eventQueueCurrent], eax
        call    func_004929e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   23h
        mov     cl, byte ptr [g_xformDirtyFlags]
        mov     eax, 1
        test    cl, al
        _emit   74h
        _emit   05h
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], 2
        jmp     func_004928c0
        ret
    }
}

/* @addr 0x004c82b0 (66b)
 *   CRT helper: writes a byte to a buffered FILE-like struct.
 *     arg0 (esp+4): char value
 *     arg1 (esp+8): FILE* (struct: ptr at +0, count at +4)
 *     arg2 (esp+c): int* counter to increment (or set to -1 on err)
 *   Decrement count; if went negative, fall back to flush helper.
 *   Either way, if write returned -1 store -1 at *counter, else
 *   increment *counter.
 */
extern int func_004c77f0(void);
__declspec(naked) void WriteCharBuffered_004c82b0(void) {
    __asm {
        mov     ecx, dword ptr [esp + 8]
        mov     eax, dword ptr [ecx + 4]
        dec     eax
        mov     dword ptr [ecx + 4], eax
        _emit   78h
        _emit   14h
        mov     edx, dword ptr [ecx]
        mov     eax, dword ptr [esp + 4]
        mov     byte ptr [edx], al
        mov     edx, dword ptr [ecx]
        and     eax, 0xff
        inc     edx
        mov     dword ptr [ecx], edx
        jmp     short cont
        mov     eax, dword ptr [esp + 4]
        push    ecx
        push    eax
        call    func_004c77f0
        add     esp, 8
cont:
        cmp     eax, -1
        _emit   75h
        _emit   07h
        mov     ecx, dword ptr [esp + 0x0c]
        mov     dword ptr [ecx], eax
        ret
        mov     eax, dword ptr [esp + 0x0c]
        inc     dword ptr [eax]
        ret
    }
}
