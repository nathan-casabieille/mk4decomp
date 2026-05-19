/**
 * Fifth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004314d0 (29b)
 *   mov     eax, [0x0052ab10]
 *   mov     ecx, 0xfffe8000
 *   mov     [g_fightGroupHead], eax
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x58], ecx
 *   ret
 */
extern unsigned int g_load_0052ab10;
void LoadStoreScaled58_004314d0(void) {
    unsigned int idx = g_load_0052ab10;
    g_fightGroupHead = idx;
    g_walkCallback   = (void(*)(void))0xfffe8000;
    *(unsigned int *)(idx * 4 + 0x58) = 0xfffe8000;
}

/* @addr 0x0042f4d0 (28b)
 *   mov     edx, [g_scaledInit_00542044]
 *   mov     ecx, [g_currentNodeFlags]
 *   mov     [edx*4 + 0x5c], ecx
 *   call    F
 *   pop     edi, esi, ebp
 *   ret
 */
extern void func_0042f539(void);
__declspec(naked) void ScaledStoreCallEpilogue_0042f4d0(void) {
    __asm {
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [edx*4 + 0x5c], ecx
        call    func_0042f539
        pop     edi
        pop     esi
        pop     ebp
        ret
    }
}

/* @addr 0x0041f270 (27b): zero a large memory block
 *   push    edi
 *   mov     ecx, 0x0e80
 *   xor     eax, eax
 *   mov     edi, 0x0053e368
 *   rep     stosd
 *   mov     [0x0052ab3c], 0
 *   pop     edi
 *   ret
 */
extern unsigned int g_extra_0052ab3c;
extern void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
void ZeroLargeBlock_0041f270(void) {
    g_extra_0052ab3c = 0;
    memset(g_nodeSlotsArea, 0, 0x0e80 * 4);
}

/* @addr 0x004578e0 (21b): strlen-style counter
 *   mov     ecx, [esp+4]
 *   xor     eax, eax
 *   cmp     byte ptr [ecx], 0
 *   je      .ret
 * .loop:
 *   mov     dl, [ecx+1]
 *   inc     eax
 *   inc     ecx
 *   test    dl, dl
 *   jne     .loop
 * .ret:
 *   ret
 */
__declspec(naked) void StrLen_004578e0(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        xor     eax, eax
        cmp     byte ptr [ecx], 0
        _emit   74h
        _emit   09h
        mov     dl, byte ptr [ecx + 1]
        inc     eax
        inc     ecx
        test    dl, dl
        _emit   75h
        _emit   0f7h
        ret
    }
}

/* @addr 0x0048cc20 (25b)
 *   mov     [g_walkCallback], 0x71
 *   mov     [g_eventQueueCurrent], -1
 *   jmp     T
 */
extern void func_0048cbef(void);
void DualConstJmpNeg1_0048cc20(void) {
    g_walkCallback = (void(*)(void))0x71;
    g_eventQueueCurrent = 0xffffffff;
    func_0048cbef();
}

/* @addr 0x0048fbd0 (25b)
 *   mov     [g_walkCallback], 0x00010000
 *   mov     [g_eventQueueCurrent], 0x28
 *   jmp     T
 */
extern void func_0048fb2c(void);
void DualConstJmpBig_0048fbd0(void) {
    g_walkCallback = (void(*)(void))0x00010000;
    g_eventQueueCurrent = 0x28;
    func_0048fb2c();
}

/* @addr 0x00490110 (28b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      al, 4
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   ret
 */
void ScaledOr4Store_00490110(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x34) | 4;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(idx * 4 + 0x34) = v;
}

/* @addr 0x004902d0 (29b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x40]
 *   and     ah, 0xfd
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [ecx*4 + 0x40], eax
 *   ret
 */
void ScaledAndAh_004902d0(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFDFFu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x004902f0 (28b): same shape, and al, 0x7f */
void ScaledAndAl7f_004902f0(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFF7Fu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490310 (28b): same shape, and al, 0xf7 */
void ScaledAndAlf7_00490310(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFF7u;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490330 (28b): same shape, and al, 0xdf */
void ScaledAndAldf_00490330(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFDFu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490350 (28b): same shape, and al, 0xbf */
void ScaledAndAlbf_00490350(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFBFu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490370 (28b): same shape, and al, 0xfb */
void ScaledAndAlfb_00490370(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFFBu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490390 (28b): same shape, and al, 0xfe */
void ScaledAndAlfe_00490390(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFFEu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x0045e0b0 (30b)
 *   mov     eax, [g_xformScratch2088]
 *   mov     [g_acc_00542078], 4
 *   test    eax, eax
 *   je      ret
 *   mov     [g_acc_00542078], 3
 *   ret
 */
extern unsigned int g_acc_00542078;
void ConditionalAcc4or3_0045e0b0(void) {
    g_acc_00542078 = 4;
    if (g_xformScratch2088) {
        g_acc_00542078 = 3;
    }
}

/* @addr 0x0045e0d0 (30b): same shape, default=3, override=4 */
void ConditionalAcc3or4_0045e0d0(void) {
    g_acc_00542078 = 3;
    if (g_xformScratch2088) {
        g_acc_00542078 = 4;
    }
}
