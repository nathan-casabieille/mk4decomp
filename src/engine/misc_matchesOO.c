/**
 * Fiftieth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_state_00537e94;
extern u32 g_eventQueueCurrent;
extern u32 g_eventQueueWorkType;

/* @addr 0x00428850 (84b)
 *   call F1; pause → ret; testb 1,[dirty]; je +5 → jmp T1;
 *   call F2; pause → ret; testb 4,[dirty]; je +0x1b →ret-tail;
 *   inc g_state_004d57ac; push 0x00428950 onto stack[idx*4]; jmp T2.
 */
extern void ScaledLoadJmp_24_00429790(void);
extern void func_00436670(void);
extern void func_0048f330(void);
extern void func_00428950_oo(void);
extern void func_004939a0(void);
__declspec(naked) void CallPauseDirty1JmpDirty4StackPush_00428850(void) {
    __asm {
        call    ScaledLoadJmp_24_00429790
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   45h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_00436670
        call    func_0048f330
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   1bh
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], OFFSET func_00428950_oo
        jmp     func_004939a0
        _emit   0e9h
        _emit   0adh
        _emit   00h
        _emit   00h
        _emit   00h
        ret
    }
}

/* @addr 0x00483a80 (84b): same shape, push 0x00483ae0 instead of 0x00428950 */
extern void func_0047d860(void);
extern void func_00488bf0(void);
extern void func_0048f330_oo(void);
extern void InstallSelfCallBitGate_00483ae0(void);
extern void func_0042b988_oo(void);
__declspec(naked) void CallPauseDirty1JmpDirty4StackPush_00483a80(void) {
    __asm {
        call    func_0047d860
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   45h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_00488bf0
        call    func_0048f330_oo
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   1bh
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], OFFSET InstallSelfCallBitGate_00483ae0
        jmp     func_0042b988_oo
        _emit   0e9h
        _emit   0dh
        _emit   00h
        _emit   00h
        _emit   00h
        ret
    }
}

/* @addr 0x004370e0 (20b): call LeaPlus22StoreSelf; if !pause tail-jmp
 * func_0046ca80. Entry A of the original 84-byte packed block; entry B
 * (at +0x20) lives in func_00437100. The 12-byte nop gap is filled
 * by 0x90-fill. */
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void func_0046ca80(void);
extern void DualCallPauseJmpDual_00439190(void);
extern void func_00471270(void);
void CallPauseJmpStateInit_004370e0(void) {
    LeaPlus22StoreSelf_0048e4d0();
    if (g_framePauseFlag != 0) return;
    func_0046ca80();
}

/* @addr 0x00437100 (52b): call LeaPlus22StoreSelf; if !pause set walk=3,
 * mstack-push OFFSET DualCallPauseJmpDual_00439190, tail-jmp func_00471270.
 * Orphan sub-entry of the original packed block. */
void func_00437100(void) {
    LeaPlus22StoreSelf_0048e4d0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))3;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) =
        (unsigned int)&DualCallPauseJmpDual_00439190;
    func_00471270();
}

/* @addr 0x00490650 (84b)
 *   PushPopWrapper saving g_eventQueueCurrent;
 *   does (state_004d50a8 << 16) | (state_004d50a4 & 0xffff);
 *   stores to current and ~that to walk; restores current.
 */
extern unsigned int g_state_004d50a8;
extern unsigned int g_state_004d50a4;
void PushPopState70Mask_00490650(void) {
    unsigned int hi;
    unsigned int packed;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_eventQueueCurrent;
    hi = g_state_004d50a8 << 0x10;
    packed = (g_state_004d50a4 & 0xffff) | hi;
    g_eventQueueCurrent = hi;
    g_walkCallback = (void (*)(void))~packed;
    g_eventQueueCurrent = *(unsigned int *)(g_state_004d57ac * 4);
    g_state_004d57ac--;
}

/* @addr 0x0048e380 (84b)
 *   push lit; call F; pause → ret;
 *   set workType = 0x3c; call F2; pause → ret;
 *   set walk = 0xfff and g_state_00537e94; ret;
 *   nop nop; call F3; pause → ret; jmp T.
 */
extern void *g_data_004f12f8;
extern int PackedAdvanceCallContinue_0048e630(void *);
extern void func_00489fd0(void);
extern void func_004312e0(void);
extern void func_00431470(void);
__declspec(naked) void PushCallPauseSetMaxThenCallPauseJmp_0048e380(void) {
    __asm {
        push    OFFSET g_data_004f12f8
        call    PackedAdvanceCallContinue_0048e630
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   27h
        mov     dword ptr [g_eventQueueWorkType], 0x3c
        call    func_00489fd0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     eax, 0xfff
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_00537e94], eax
        ret
        nop
        nop
        call    func_004312e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00431470
        ret
    }
}

/* @addr 0x0048e4f0 (84b)
 *   arg sar 2 → g_scaledInit; load baseSel*4+0x34 → walk; cmp 0x10;
 *   if !=, set walk=2 (always); cmp 0x11; if !=, set walk=4 (always);
 *   add eax, walk → g_scaledInit; load *4+0 → g_scaledInit; jmp eax.
 */
void ScaledChainCmpDispatch_0048e4f0(int arg) {
    unsigned int idx = (unsigned int)(arg >> 2);
    unsigned int walk;
    unsigned int target;
    g_scaledInit_00542044 = idx;
    walk = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x34);
    g_walkCallback = (void (*)(void))walk;
    if (walk == 0x10) {
        walk = 2;
        g_walkCallback = (void (*)(void))walk;
    }
    if (walk == 0x11) {
        walk = 4;
        g_walkCallback = (void (*)(void))walk;
    }
    idx += walk;
    g_scaledInit_00542044 = idx;
    target = *(unsigned int *)(idx * 4);
    g_scaledInit_00542044 = target;
    ((void (*)(void))target)();
}
