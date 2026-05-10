/**
 * Thirty-fifth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_fightGroupHead;
extern unsigned int g_eventQueueNotMask;

/* @addr 0x00474b10 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x474b50 */
extern void func_00474b50(void);
__declspec(naked) void ScaledInitOrSelfPtr_00474b10(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   05h
        jmp     func_00474b50
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00474b10
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x00489130 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x41f780 */
extern void func_0041f780_z(void);
__declspec(naked) void ScaledInitOrSelfPtr_00489130(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   05h
        jmp     func_0041f780_z
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00489130
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x00474050 (63b): DoubleStackPushAndJmp variant, value=0x7d */
extern void func_004740d0_z(void);
__declspec(naked) void DoubleStackPushAndJmp7d_00474050(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     dword ptr [g_scaledInit_00542044], 0x7d
        jmp     func_004740d0_z
    }
}

/* @addr 0x00474090 (63b): DoubleStackPushAndJmp variant, value=0x7b */
extern void func_004740d0_zz(void);
__declspec(naked) void DoubleStackPushAndJmp7b_00474090(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     dword ptr [g_scaledInit_00542044], 0x7b
        jmp     func_004740d0_zz
    }
}

/* @addr 0x00475750 (62b)
 *   load g_eventQueueIdx, g_eventQueueEnd; cross-copy [+0x54] then [+0x5c].
 */
__declspec(naked) void DoubleScaledCrossStore_00475750(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [eax*4 + 0x54]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [edx*4 + 0x5c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x5c], eax
        ret
    }
}

/* @addr 0x00482740 (62b)
 *   3-level scaled chain (0x3c, 0x30, 0); cmp 0x61 → jmp T1; cmp 0x69 → jmp T2.
 */
extern void func_00482780(void);
extern void func_0048a360(void);
__declspec(naked) void ScaledChainCmp61_00482740(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0]
        cmp     eax, 0x61
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_00482780
        cmp     eax, 0x69
        _emit   74h
        _emit   05h
        jmp     func_0048a360
        ret
    }
}

/* @addr 0x0048e2f0 (60b)
 *   push lit; call F; pause-test → ret;
 *   load g_baseSel; copy [eax*4+0x7c]→g_walkCallback, [eax*4+0x80]→g_currentNodeFlags;
 *   jmp [g_scaledInit_00542044]; ret.
 */
extern void *g_data_004f1290;
extern int func_0048e550(void *);
__declspec(naked) void PushCallPauseScaledJmpInd_0048e2f0(void) {
    __asm {
        push    OFFSET g_data_004f1290
        call    func_0048e550
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   25h
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x7c]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0x80]
        mov     dword ptr [g_currentNodeFlags], edx
        jmp     dword ptr [g_scaledInit_00542044]
        ret
    }
}

/* @addr 0x0048e740 (62b)
 *   scaled chain 0x3c → 0x74; and 0xf000; cmp 0x4000;
 *   if eq: or al,1 → store dirty;  else and al,0xfe → store dirty.
 */
__declspec(naked) void ScaledChainAndF000DirtyToggle_0048e740(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0x74]
        and     eax, 0xf000
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 0x4000
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

/* @addr 0x00490290 (55b)
 *   load g_fightGroupHead, g_eventQueueNotMask; or eax with [ecx*4+0x40];
 *   store both eventQueueCurrent and back to [ecx*4+0x40];
 *   load g_state_004d57ac; pop top into eventQueueNotMask; dec ; store.
 */
__declspec(naked) void OrStoreDecStackPop_00490290(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_eventQueueNotMask]
        or      eax, dword ptr [ecx*4 + 0x40]
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x40], eax
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x0048ac70 (65b)
 *   init g_fightGroupHead from g_state_0052ab10, set g_eventQueueChild = 0x48acb0
 *   (callback ptr to inline ret stub at end), set g_eventQueueTotal = head+0x15;
 *   call F1; pause → ret;
 *   call F2; pause → ret; jmp T;
 *   ret; nop nop; ret  (the inline 0x48acb0 stub fits in the tail)
 */
extern unsigned int g_state_0052ab10;
extern void func_0048acb0(void);
extern void func_0048ae50(void);
extern void func_0048abe0(void);
extern void func_0041f780_zz(void);
__declspec(naked) void InitStateDualCall48ac70_0048ac70(void) {
    __asm {
        mov     eax, dword ptr [g_state_0052ab10]
        mov     dword ptr [g_eventQueueChild], OFFSET func_0048acb0
        mov     dword ptr [g_fightGroupHead], eax
        add     eax, 0x15
        mov     dword ptr [g_eventQueueTotal], eax
        call    func_0048ae50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    func_0048abe0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0041f780_zz
        ret
        nop
        nop
        ret
    }
}
