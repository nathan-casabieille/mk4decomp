/**
 * Twenty-eighth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404e50 (52b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x18]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0x28]
 *   mov     [g_eventQueueIdx], ecx
 *   mov     eax, [ecx*4 + 0]
 *   or      al, 8
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0], eax
 *   ret
 */
__declspec(naked) void ScaledChainOr8_00404e50(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     eax, dword ptr [ecx*4 + 0]
        or      al, 8
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0], eax
        ret
    }
}

/* @addr 0x00404e90 (54b)
 *   mov     ecx, [g_pendingNodeType]
 *   mov     eax, [g_fightGroupHead]
 *   shl     ecx, 2
 *   shl     eax, 2
 *   mov     edx, [ecx + 0x3c]
 *   mov     [g_walkCallback], edx
 *   mov     [eax + 0x54], edx
 *   mov     edx, [ecx + 0x40]
 *   mov     [g_walkCallback], edx
 *   mov     [eax + 0x58], edx
 *   mov     ecx, [ecx + 0x44]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x5c], ecx
 *   ret
 */
extern unsigned int g_pendingNodeType;
__declspec(naked) void Copy3Fields3c4044_00404e90(void) {
    __asm {
        mov     ecx, dword ptr [g_pendingNodeType]
        mov     eax, dword ptr [g_fightGroupHead]
        shl     ecx, 2
        shl     eax, 2
        mov     edx, dword ptr [ecx + 0x3c]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x54], edx
        mov     edx, dword ptr [ecx + 0x40]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x58], edx
        mov     ecx, dword ptr [ecx + 0x44]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x5c], ecx
        ret
    }
}

/* @addr 0x0040a870 (52b)
 *   mov     eax, [g_eventQueueEnd]
 *   mov     ecx, [g_scaledInit_00542044]
 *   shl     eax, 2
 *   shl     ecx, 2
 *   mov     edx, [eax]
 *   mov     [g_walkCallback], edx
 *   mov     [ecx + 0x38], edx
 *   mov     edx, [eax + 4]
 *   mov     [g_walkCallback], edx
 *   mov     [ecx + 0x3c], edx
 *   mov     eax, [eax + 8]
 *   mov     [g_walkCallback], eax
 *   mov     [ecx + 0x40], eax
 *   ret
 */
__declspec(naked) void Copy3Fields38_0040a870(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        shl     eax, 2
        shl     ecx, 2
        mov     edx, dword ptr [eax]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x38], edx
        mov     edx, dword ptr [eax + 4]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x3c], edx
        mov     eax, dword ptr [eax + 8]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx + 0x40], eax
        ret
    }
}

/* @addr 0x0041aa40 (60b)
 *   mov     ecx, [g_xformEntityIdx]
 *   mov     eax, [g_scaledInit_00542044]
 *   shl     ecx, 2
 *   shl     eax, 2
 *   mov     edx, [ecx + 0x30]
 *   neg     edx
 *   mov     [g_walkCallback], edx
 *   mov     [eax + 0x30], edx
 *   mov     edx, [ecx + 0x34]
 *   neg     edx
 *   mov     [g_walkCallback], edx
 *   mov     [eax + 0x34], edx
 *   mov     ecx, [ecx + 0x38]
 *   neg     ecx
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x38], ecx
 *   ret
 */
extern unsigned int g_xformEntityIdx;
__declspec(naked) void Copy3FieldsNeg_0041aa40(void) {
    __asm {
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [g_scaledInit_00542044]
        shl     ecx, 2
        shl     eax, 2
        mov     edx, dword ptr [ecx + 0x30]
        neg     edx
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x30], edx
        mov     edx, dword ptr [ecx + 0x34]
        neg     edx
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x34], edx
        mov     ecx, dword ptr [ecx + 0x38]
        neg     ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x38], ecx
        ret
    }
}

/* @addr 0x0040a830 (54b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_eventQueueEnd]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   call    F
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_eventQueueEnd], edx
 *   mov     [g_matrixStackTop], eax
 *   ret
 */
extern void func_0040a888(void);
__declspec(naked) void MStackPushCallPop_0040a830(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueEnd]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    func_0040a888
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], edx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x00427ea0 (54b)
 *   mov     eax, [0x0053a408]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0x0e
 *   mov     eax, [0x00537e88]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_state_0053a408_s;
extern unsigned int g_state_00537e88_s;
__declspec(naked) void DualTestDirtyToggle_00427ea0(void) {
    __asm {
        mov     eax, dword ptr [g_state_0053a408_s]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0eh
        mov     eax, dword ptr [g_state_00537e88_s]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
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

/* @addr 0x004282c0 (54b): same as 0x00427ea0 with je/jne swapped at first jcc */
__declspec(naked) void DualTestDirtyToggle_004282c0(void) {
    __asm {
        mov     eax, dword ptr [g_state_0053a408_s]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   0eh
        mov     eax, dword ptr [g_state_00537e88_s]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x00423870 (55b)
 *   mov     eax, [0x0052aac4]
 *   cmp     eax, 2
 *   mov     [g_walkCallback], eax
 *   je      +0x0e
 *   mov     eax, [0x00542004]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   mov     eax, [g_xformDirtyFlags]
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_state_0052aac4_s;
extern unsigned int g_dlMode;
__declspec(naked) void Cmp2DirtyToggle_00423870(void) {
    __asm {
        mov     eax, dword ptr [g_state_0052aac4_s]
        cmp     eax, 2
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   0eh
        mov     eax, dword ptr [g_dlMode]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x004231b0 (53b)
 *   push    3
 *   push    0x004234f0
 *   call    F
 *   mov     eax, [g_scaledInit_00542044]
 *   add     esp, 8
 *   mov     [0x00538040], eax
 *   push    4
 *   push    0x00423570
 *   call    F
 *   mov     ecx, [g_scaledInit_00542044]
 *   add     esp, 8
 *   mov     [0x00538044], ecx
 *   ret
 */
extern int func_0049cb34(void *p, int n);
extern void *g_data_004234f0;
extern void *g_data_00423570;
extern unsigned int g_state_00538040;
extern unsigned int g_state_00538044;
__declspec(naked) void DualPushCallStore_004231b0(void) {
    __asm {
        push    3
        push    OFFSET g_data_004234f0
        call    func_0049cb34
        mov     eax, dword ptr [g_scaledInit_00542044]
        add     esp, 8
        mov     dword ptr [g_state_00538040], eax
        push    4
        push    OFFSET g_data_00423570
        call    func_0049cb34
        mov     ecx, dword ptr [g_scaledInit_00542044]
        add     esp, 8
        mov     dword ptr [g_state_00538044], ecx
        ret
    }
}

/* @addr 0x00429800 (52b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x24]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     eax, [eax*4 + 0x28]
 *   inc     eax
 *   mov     [g_walkCallback], eax
 *   mov     edx, [ecx*4 + 4]
 *   cmp     eax, edx
 *   jl      +5
 *   jmp     +0xb1
 *   jmp     +0x12c
 */
extern void func_0042985c(void);
extern void func_004298d7(void);
__declspec(naked) void ScaledIncCmpDualJmp_00429800(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     eax, dword ptr [eax*4 + 0x28]
        inc     eax
        mov     dword ptr [g_walkCallback], eax
        mov     edx, dword ptr [ecx*4 + 4]
        cmp     eax, edx
        _emit   7ch
        _emit   05h
        jmp     func_0042985c
        jmp     func_004298d7
    }
}

/* @addr 0x00437930 (52b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 2
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET func_00437970
 *   jmp     T
 *   ret
 */
extern void func_0049e4d0(void);
extern void func_00437970(void);
extern void func_0048121c(void);
__declspec(naked) void CallPauseMStackPushSet2Jmp_00437930(void) {
    __asm {
        call    func_0049e4d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   25h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], 2
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET func_00437970
        jmp     func_0048121c
        ret
    }
}
