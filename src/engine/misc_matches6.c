/**
 * Sixth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490330 (28b): scaled and ah, 0xdf */
void ScaledAndAhdf_00490330(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFDFu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490350 (28b): scaled and ah, 0xbf */
void ScaledAndAhbf_00490350(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFBFu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490370 (28b): scaled and ah, 0xfb */
void ScaledAndAhfb_00490370(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFFBu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490390 (28b): scaled and ah, 0xfe */
void ScaledAndAhfe_00490390(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFFEu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00491500 (21b)
 *   mov     ecx, [g_fightGroupHead]
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x44], eax
 *   ret
 */
void ScaledZero44_00491500(void) {
    int *p = (int *)(g_fightGroupHead * 4 + 0x44);
    g_walkCallback = 0;
    *p = 0;
}

/* @addr 0x00491e50 (22b)
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [g_X], eax
 *   mov     [g_Y], eax
 *   jmp     +0xffa
 */
extern unsigned int g_zero_0053a470;
extern unsigned int g_zero_0053a104;
extern void func_00492e50(void);
void ZeroTripleJmp_00491e50(void) {
    g_walkCallback = 0;
    g_zero_0053a470 = 0;
    g_zero_0053a104 = 0;
    func_00492e50();
}

/* @addr 0x004930e0 (28b)
 *   mov     eax, [g_baseSel]
 *   mov     eax, [eax*4 + 0x34]
 *   cmp     eax, 0x0f
 *   mov     [g_walkCallback], eax
 *   je      ret_label
 *   jmp     +5
 */
extern void func_004930ed(void);
__declspec(naked) void ScaledLoadCmp0fJmp_004930e0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x34]
        cmp     eax, 0x0f
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   05h
        jmp     func_004930ed
        ret
    }
}

/* @addr 0x00495da0 (28b)
 *   mov     ecx, [g_baseSel]
 *   mov     eax, 0x0111
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x74], eax
 *   jmp     +4
 */
extern void func_00495dc8(void);
void Const111ScaledStoreJmp_00495da0(void) {
    g_walkCallback = (void(*)(void))0x111;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x74) = 0x111;
    func_00495dc8();
}

/* @addr 0x004594f0 (30b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [g_baseSel]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     [ecx*4 + 0x48], eax
 *   jmp     +2
 */
extern void func_0045950e(void);
__declspec(naked) void ArgSarStoreJmp_004594f0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [g_baseSel_00542060]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        jmp     func_0045950e
    }
}

/* @addr 0x00490720 (30b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x48]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x58], ecx
 *   jmp     +2
 */
extern void ScaledZeroFour_00490740(void);
__declspec(naked) void ScaledMove48to58_00490720(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x48]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x58], ecx
        jmp     ScaledZeroFour_00490740
    }
}

/* @addr 0x0048c190 (25b)
 *   mov     eax, [g_eventQueueEnd]
 *   test    eax, eax
 *   je      after_set
 *   mov     [eax*4 + 0], 1
 * after_set:
 *   jmp     +0x031407
 */
extern void func_004bd5a2(void);
__declspec(naked) void ScaledSet1OnNonZero_0048c190(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueEnd]
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     dword ptr [eax*4 + 0], 1
        jmp     func_004bd5a2
    }
}

/* @addr 0x0048de00 (25b)
 *   mov     eax, [g_xformDirtyFlags]
 *   mov     [g_xformScratch2088], 0
 *   and     al, 0xfe
 *   or      al, 4
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void DirtyFlagsManip_0048de00(void) {
    u32 v = g_xformDirtyFlags;
    g_xformScratch2088 = 0;
    g_xformDirtyFlags = (v & 0xfffffffe) | 4;
}

/* @addr 0x0049afe0 (30b)
 *   mov     [g_walkCallback], 0x7c
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret
 *   jmp     +3
 *   ret
 */
extern void func_00490fd8(void);
extern void func_0049b00f(void);
void Const7cCallJmp_0049afe0(void) {
    g_walkCallback = (void(*)(void))0x7c;
    func_00490fd8();
    if (g_framePauseFlag) return;
    func_0049b00f();
}
