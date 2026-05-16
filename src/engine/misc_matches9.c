/**
 * Ninth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00439b80 (30b)
 *   mov     eax, [g_state]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .skip1
 *   jmp     +0x0d
 * .skip1:
 *   cmp     eax, 1
 *   jne     .skip2
 *   jmp     +3
 * .skip2:
 *   ret
 */
extern unsigned int g_state_0053a51c;
extern void func_00439ba1(void);
extern void func_00439ba6(void);
void TwoConditionalJmp_00439b80(void) {
    unsigned int v = g_state_0053a51c;
    g_walkCallback = (void (*)(void))v;
    if (v == 0) {
        func_00439ba1();
        return;
    }
    if (v == 1) {
        func_00439ba6();
    }
}

/* @addr 0x0043bd30 (27b)
 *   mov     eax, [g_X]
 *   cmp     eax, 0x200
 *   mov     [g_walkCallback], eax
 *   jge     +5
 *   jmp     T1
 *   jmp     +5
 */
extern unsigned int g_state_00535ddc;
extern void func_00408f80(void);
extern void func_0043bd5b(void);
void Cmp200Jmp_0043bd30(void) {
    unsigned int v = g_state_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if ((int)v < 0x20000) {
        func_00408f80();
    } else {
        func_0043bd5b();
    }
}

/* @addr 0x00486510 (25b)
 *   mov     [g_walkCallback], 0x20c
 *   mov     [g_eventQueueCurrent], -1   ; sort of, the imm = "ff ff ff ff" via loop?
 *   actually:
 *   c7 05 6c 20 54 00 0c 02 00 00       mov [g_walkCallback], 0x20c
 *   c7 05 70 20 54 00 e2 fa ff ff       mov [g_eventQueueCurrent], 0xfffffae2
 *   e9 27 a8 ff ff                       jmp T
 *
 * Wait the actual bytes: c7 05 70 20 54 00 e2 fa ff ff has imm=0xfffffae2,
 * which is -0x51e in signed.
 */
extern void func_00480d3c(void);
void Const20cFae2Jmp_00486510(void) {
    g_walkCallback = (void(*)(void))0x20c;
    g_eventQueueCurrent = 0xfffffae2;
    func_00480d3c();
}

/* @addr 0x004933b0 (30b)
 *   mov     eax, [g_X]
 *   test    eax, eax
 *   mov     [g_eventQueueCurrent], eax
 *   jne     +0x0f
 *   mov     [g_walkCallback], 0x0e
 *   jmp     T
 *   ret
 */
extern unsigned int g_state_0053a430;
extern void func_0049b619(void);
void TestStoreConstJmp_004933b0(void) {
    unsigned int s = g_state_0053a430;
    g_eventQueueCurrent = s;
    if (s) return;
    g_walkCallback = (void(*)(void))0x0e;
    func_0049b619();
}

/* @addr 0x00493ed0 (29b)
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, 0x004f1e20
 *   sar     eax, 2
 *   cmp     eax, ecx
 *   mov     [g_state_00541dc4], eax
 *   jne     +4
 *   jmp     +4
 *   ret
 */
extern unsigned int g_state_00541dc4;
extern void func_00493edd(void);
extern unsigned int g_table_004f1e20;
void LoadCmpAddrJmp_00493ed0(void) {
    unsigned int packed = (unsigned int)((int)&g_table_004f1e20 >> 2);
    g_state_00541dc4 = packed;
    if ((unsigned int)g_walkCallback == packed) {
        func_00493edd();
    }
}

/* @addr 0x004a1d00 (27b)
 *   call    F
 *   test    eax, eax
 *   je      .return0
 *   mov     eax, 1
 *   ret
 * .return0:
 *   call    F2
 *   neg     eax
 *   sbb     eax, eax
 *   neg     eax
 *   ret
 */
extern int MovsxAnd4Shr_004a1ce0(void);
extern int MovsxAnd20Shr5_004a1cf0(void);
int IsNonzeroBoolFlagged_004a1d00(void) {
    if (MovsxAnd4Shr_004a1ce0() != 0) {
        return 1;
    }
    return MovsxAnd20Shr5_004a1cf0() != 0 ? 1 : 0;
}

/* @addr 0x004a5680 (28b)
 *   push    esi
 *   mov     esi, [esp+0x10]
 *   test    esi, esi
 *   jle     .ret
 *   mov     ecx, [esp+0x0c]
 *   mov     eax, [esp+8]
 * .loop:
 *   mov     dl, [ecx]
 *   mov     [eax], dl
 *   inc     eax
 *   inc     ecx
 *   dec     esi
 *   jne     .loop
 * .ret:
 *   pop     esi
 *   ret
 */
void MemcpyByteN_004a5680(unsigned char *dst, unsigned char *src, int n) {
    if (n <= 0) return;
    do {
        *dst++ = *src++;
    } while (--n);
}

/* @addr 0x004a56a0 (25b)
 *   mov     ecx, [g_count]
 *   test    ecx, ecx
 *   jle     .ret
 *   mov     eax, OFFSET g_target
 * .loop:
 *   mov     [eax], 1
 *   add     eax, 0x18
 *   dec     ecx
 *   jne     .loop
 * .ret:
 *   ret
 */
extern unsigned int g_count_005433b8;
extern unsigned char g_target_005435a2;
void Memset18Step_004a56a0(void) {
    int n = (int)g_count_005433b8;
    unsigned char *p;
    if (n <= 0) return;
    p = &g_target_005435a2;
    do {
        *p = 1;
        p += 0x18;
    } while (--n);
}

/* @addr 0x004be610 (18b)
 *   call    F
 *   xor     eax, eax
 *   mov     [g_X1], eax
 *   mov     [g_X2], eax
 *   ret
 */
extern void func_004be370(void);
extern unsigned int g_zero_00541fa8;
extern unsigned int g_zero_00541fa4;
void CallZero2_004be610(void) {
    func_004be370();
    g_zero_00541fa8 = 0;
    g_zero_00541fa4 = 0;
}

/* @addr 0x004be790 (16b)
 *   mov     eax, [esp+4]
 *   push    eax
 *   push    -1
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int __cdecl func_004c1ac8(int, int);
int PushArgPushNeg1Call_004be790(int x) {
    return func_004c1ac8(-1, x);
}

/* @addr 0x004bea30 (16b)
 *   call    F
 *   mov     [g_target], 0
 *   ret
 */
extern void func_004bdcb0(void);
extern unsigned int g_state_00ab5748;
void CallZero_004bea30(void) {
    func_004bdcb0();
    g_state_00ab5748 = 0;
}

/* @addr 0x004c44f0 (18b)
 *   mov     eax, [g_state_00f9f008]
 *   test    eax, eax
 *   je      .ret
 *   push    1
 *   call    [iat]
 * .ret:
 *   ret
 */
extern unsigned int g_state_00f9f008;
extern void *g_iat_004d2220;
__declspec(naked) void TestCallIat_004c44f0(void) {
    __asm {
        mov     eax, dword ptr [g_state_00f9f008]
        test    eax, eax
        _emit   74h
        _emit   08h
        push    1
        call    dword ptr [g_iat_004d2220]
        ret
    }
}
