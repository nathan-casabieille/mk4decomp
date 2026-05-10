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
