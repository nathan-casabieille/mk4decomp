/**
 * 11 "matrix-stack push + call + guarded pop" wrappers.
 *
 * Pattern (75 bytes):
 *   mov eax, [g_matrixStackTop]
 *   mov ecx, [g_currentNodeIdx]
 *   inc eax
 *   mov [g_matrixStackTop], eax
 *   mov [eax*4 + 0], ecx     ; SIB+disp32=0 - scaled-base array
 *   mov edx, [g_fightGroupHead]
 *   mov [g_currentNodeIdx], edx
 *   call Target
 *   mov eax, [g_framePauseFlag]
 *   test eax, eax
 *   jne short skip          ; bail if pause set
 *   mov eax, [g_matrixStackTop]
 *   mov ecx, [eax*4 + 0]
 *   dec eax
 *   mov [g_currentNodeIdx], ecx
 *   mov [g_matrixStackTop], eax
 * skip:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"   /* g_framePauseFlag */

/* Externs for call targets. */
extern void func_545ecf1e(void);   /* 0x545ecf1e */
extern void func_545ecf6e(void);   /* 0x545ecf6e */
extern void func_545ecfbe(void);   /* 0x545ecfbe */
extern void func_545ed00e(void);   /* 0x545ed00e */
extern void func_545ed05e(void);   /* 0x545ed05e */
extern void func_545ed0ae(void);   /* 0x545ed0ae */
extern void func_545ed27e(void);   /* 0x545ed27e */
extern void func_545ed2ce(void);   /* 0x545ed2ce */
extern void func_545ed40e(void);   /* 0x545ed40e */
extern void func_545ed81e(void);   /* 0x545ed81e */
extern void func_54633efe(void);   /* 0x54633efe */

/* The wrappers. */
/* @addr 0x00406250 */
__declspec(naked) void MStackCall_00406250(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_545ecf1e
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x004062a0 */
__declspec(naked) void MStackCall_004062a0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_545ecf6e
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x004062f0 */
__declspec(naked) void MStackCall_004062f0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_545ecfbe
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x00406340 */
__declspec(naked) void MStackCall_00406340(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_545ed00e
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x00406390 */
__declspec(naked) void MStackCall_00406390(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_545ed05e
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x004063e0 */
__declspec(naked) void MStackCall_004063e0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_545ed0ae
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x004065b0 */
__declspec(naked) void MStackCall_004065b0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_545ed27e
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x00406600 */
__declspec(naked) void MStackCall_00406600(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_545ed2ce
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x00406740 */
__declspec(naked) void MStackCall_00406740(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_545ed40e
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x00406b50 */
__declspec(naked) void MStackCall_00406b50(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_545ed81e
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x0044d230 */
__declspec(naked) void MStackCall_0044d230(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    func_54633efe
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

