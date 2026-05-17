/**
 * Twenty-fifth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0045fa90 (46b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_walkCallback], 0
 *   mov     [eax*4 + 0x28], 0
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     +3
 *   ret
 */
extern void func_004611c0(void);
extern void func_0045faec(void);
void ZeroScaledZeroCallPauseJmp_0045fa90(void) {
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0;
    func_004611c0();
    if (g_framePauseFlag != 0) return;
    func_0045faec();
}

/* @addr 0x0046a520 (50b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_state_00535ddc]
 *   cmp     eax, 0x00030000
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     +0x1c
 *   push    0x004eabb0
 *   call    F2
 *   add     esp, 4
 *   ret
 */
extern unsigned int g_state_00535ddc;
extern void func_0046c740(void);
extern void func_004594c8(void *p);
extern void *g_data_004eabb0;
extern void func_0046a542(void);
void CallPauseCmpStateJmp_0046a520(void) {
    unsigned int v;
    func_0046c740();
    if (g_framePauseFlag != 0) return;
    v = g_state_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if ((int)v > 0x30000) {
        func_0046a542();
        return;
    }
    func_004594c8(&g_data_004eabb0);
}

/* @addr 0x0046fbe0 (49b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     al, byte ptr [g_xformDirtyFlags]
 *   mov     [g_walkCallback], 0x0e14
 *   test    al, 1
 *   jne     +0x0a
 *   mov     [g_walkCallback], 0xfffff1ec
 *   jmp     +0x50
 *   ret
 */
extern void func_0048eff0(void);
extern void func_0046fc35(void);
__declspec(naked) void CallPauseDirtyTwoSetsJmp_0046fbe0(void) {
    __asm {
        call    func_0048eff0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   22h
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     dword ptr [g_walkCallback], 0x0e14
        test    al, 1
        _emit   75h
        _emit   0ah
        mov     dword ptr [g_walkCallback], 0xfffff1ec
        jmp     func_0046fc35
        ret
    }
}

/* @addr 0x0046fc20 (49b): same as 0x0046fbe0 with constants swapped */
extern void func_0048eff0_b(void);
extern void func_0046fc75(void);
__declspec(naked) void CallPauseDirtyTwoSetsJmp_0046fc20(void) {
    __asm {
        call    func_0048eff0_b
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   22h
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     dword ptr [g_walkCallback], 0xfffff1ec
        test    al, 1
        _emit   75h
        _emit   0ah
        mov     dword ptr [g_walkCallback], 0x0e14
        jmp     func_0046fc75
        ret
    }
}

/* @addr 0x00486fc0 (48b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   je      +5
 *   jmp     T1
 *   jmp     T2
 *   ret
 */
extern void func_00487640(void);
extern void func_00487358(void);
extern void func_0046f660(void);
extern void func_0046025e(void);
void DualCallPauseDirtyDoubleJmp_00486fc0(void) {
    func_00487640();
    if (g_framePauseFlag != 0) return;
    func_00487358();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) {
        func_0046f660();
        return;
    }
    func_0046025e();
}

/* @addr 0x00487150 (46b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x30]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   jmp     T1
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T2
 *   ret
 */
extern void func_00486848(void);
extern void func_004ba31a(void);
extern void func_004871a3(void);
__declspec(naked) void ScaledTestCallPauseJmpFar_00487150(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x30]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_004871a3
        call    func_00486848
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004ba31a
        ret
    }
}

/* @addr 0x0048a220 (46b)
 *   mov     eax, [0x0053a7b0]
 *   and     al, 0xfd
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [0x0053a7b0], eax
 *   mov     eax, [0x00541fa8]
 *   test    eax, eax
 *   je      +0x13
 *   push    eax
 *   call    F
 *   add     esp, 4
 *   mov     [0x00541fa8], 0
 *   ret
 */
extern unsigned int g_state_0053a7b0;
extern unsigned int g_state_00541fa8;
extern int func_004be770(void *p);
__declspec(naked) void AndStorePushCallZero_0048a220(void) {
    __asm {
        mov     eax, dword ptr [g_state_0053a7b0]
        and     al, 0xfd
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_state_0053a7b0], eax
        mov     eax, dword ptr [g_state_00541fa8]
        test    eax, eax
        _emit   74h
        _emit   13h
        push    eax
        call    func_004be770
        add     esp, 4
        mov     dword ptr [g_state_00541fa8], 0
        ret
    }
}

/* @addr 0x0048d0c0 (48b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      ah, 8
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void func_00426d80(void);
extern void func_00414fa6(void);
__declspec(naked) void ScaledOrAh8CallPauseJmp_0048d0c0(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x34]
        or      ah, 8
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        call    func_00426d80
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00414fa6
        ret
    }
}

/* @addr 0x0048f8e0 (48b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x3c]
 *   mov     [g_scaledInit_00542044], ecx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0f
 *   mov     [g_scaledInit_00542044], 0x0048fa20
 *   jmp     T
 *   ret
 */
extern void Wrapper_0048fbc0(void);
extern void func_00498e3c(void);
__declspec(naked) void ScaledChainCallPauseSetJmp_0048f8e0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_scaledInit_00542044], ecx
        call    Wrapper_0048fbc0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     dword ptr [g_scaledInit_00542044], 0x0048fa20
        jmp     func_00498e3c
        ret
    }
}

/* @addr 0x00490e00 (49b)
 *   mov     eax, [g_eventQueueIdx]
 *   xor     edx, edx
 *   mov     ecx, [eax*4 + 0x4c]
 *   cmp     ecx, edx
 *   mov     [g_pendingNodeType], ecx
 *   je      +0x18
 *   mov     [g_walkCallback], edx
 *   mov     [eax*4 + 0x4c], edx
 *   mov     eax, [g_pendingNodeType]
 *   cmp     eax, edx
 *   je      +2
 *   jmp     eax
 *   ret
 */
extern u32 g_pendingNodeType;
__declspec(naked) void ScaledLoadJmpIfNonzero_00490e00(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueIdx]
        xor     edx, edx
        mov     ecx, dword ptr [eax*4 + 0x4c]
        cmp     ecx, edx
        mov     dword ptr [g_pendingNodeType], ecx
        _emit   74h
        _emit   18h
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax*4 + 0x4c], edx
        mov     eax, dword ptr [g_pendingNodeType]
        cmp     eax, edx
        _emit   74h
        _emit   02h
        jmp     eax
        ret
    }
}

/* @addr 0x004a1cb0 (45b)
 *   call    F
 *   test    eax, eax
 *   je      +0x0b
 *   mov     eax, 1
 *   mov     byte ptr [0x00543590], al
 *   ret
 *   call    F2
 *   test    eax, eax
 *   je      +0x0d
 *   mov     byte ptr [0x00543590], 2
 *   mov     eax, 1
 *   ret
 *   xor     eax, eax
 *   ret
 */
extern int TripleByteCheck_004a1c50(void);
extern int func_004a1c70(void);
extern unsigned char g_byte_00543590;
__declspec(naked) void DualCallSetByte_004a1cb0(void) {
    __asm {
        call    TripleByteCheck_004a1c50
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     eax, 1
        mov     byte ptr [g_byte_00543590], al
        ret
        call    func_004a1c70
        test    eax, eax
        _emit   74h
        _emit   0dh
        mov     byte ptr [g_byte_00543590], 2
        mov     eax, 1
        ret
        xor     eax, eax
        ret
    }
}
