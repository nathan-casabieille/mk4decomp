/**
 * Fourth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004089c0 (29b)
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     ret_label
 *   jmp     Tail
 *   ret
 */
extern void func_004085f8(void);
extern void func_004088a0(void);
__declspec(naked) void GDispatch4_004089c0(void) {
    __asm {
        call    func_004085f8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0eh
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     func_004088a0
        ret
    }
}

/* @addr 0x00439c40 (29b): same as above but mask=1, jne */
extern void func_00439c60(void);
extern void func_004068e0(void);
__declspec(naked) void GDispatch1_00439c40(void) {
    __asm {
        call    func_00439c60
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0eh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   75h
        _emit   05h
        jmp     func_004068e0
        ret
    }
}

/* @addr 0x00488da0 (29b): mask=1, je (skip-then-jmp) */
extern void func_00488dc0(void);
extern void func_004814e0(void);
__declspec(naked) void GDispatch1_00488da0(void) {
    __asm {
        call    func_00488dc0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0eh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_004814e0
        ret
    }
}

/* @addr 0x004350f0 (30b)
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   mov     [g_eventQueueChild], 0x1e
 *   jmp     +3
 *   ret
 */
extern void func_00460470(void);
extern void func_00435112(void);
__declspec(naked) void CallPauseConstStoreJmp_004350f0(void) {
    __asm {
        call    func_00460470
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     dword ptr [g_eventQueueChild], 0x1e
        jmp     func_00435112
        ret
    }
}

/* @addr 0x00438170 (30b): same shape, value=0x78 */
extern void func_004393b0(void);
extern void func_00438192(void);
__declspec(naked) void CallPauseConstStoreJmp_00438170(void) {
    __asm {
        call    func_004393b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     dword ptr [g_eventQueueChild], 0x78
        jmp     func_00438192
        ret
    }
}

/* @addr 0x00481360 (30b): same shape, store walkCallback=0xb5 */
extern void func_00416cb0(void);
extern void func_0049cc35(void);
__declspec(naked) void CallPauseConstStoreJmp_00481360(void) {
    __asm {
        call    func_00416cb0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     dword ptr [g_walkCallback], 0xb5
        jmp     func_0049cc35
        ret
    }
}

/* @addr 0x00448fa0 (30b)
 *   mov     [g_walkCallback], 3
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   jmp     Tail
 *   ret
 */
extern void func_00408c0a(void);
extern void func_00475778(void);
__declspec(naked) void ConstStoreCallJmp_00448fa0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 3
        call    func_00408c0a
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00475778
        ret
    }
}

/* @addr 0x0046ff60 (30b): same shape, value=4 */
extern void func_0048a046(void);
extern void func_0046ff8e(void);
__declspec(naked) void ConstStoreCallJmp_0046ff60(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 4
        call    func_0048a046
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0046ff8e
        ret
    }
}

/* @addr 0x0041f830 (16b)
 *   call    F
 *   mov     [g_framePauseFlag], 1
 *   ret
 */
extern void func_0041f840(void);
void CallSetPause_0041f830(void) {
    func_0041f840();
    g_framePauseFlag = 1;
}
