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
void ScaledChainOr8_00404e50(void) {
    unsigned int s;
    unsigned int e;
    unsigned int v;
    s = *(unsigned int *)(g_fightGroupHead * 4 + 0x18);
    g_scaledInit_00542044 = s;
    e = *(unsigned int *)(s * 4 + 0x28);
    g_eventQueueIdx = e;
    v = *(unsigned int *)(e * 4) | 8;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(e * 4) = v;
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
extern u32 g_pendingNodeType;
void Copy3Fields3c4044_00404e90(void) {
    unsigned char *dst = (unsigned char *)(g_fightGroupHead * 4);
    unsigned char *src = (unsigned char *)(g_pendingNodeType * 4);
    unsigned int v;
    v = *(unsigned int *)(src + 0x3c);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x54) = v;
    v = *(unsigned int *)(src + 0x40);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x58) = v;
    v = *(unsigned int *)(src + 0x44);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x5c) = v;
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
void Copy3Fields38_0040a870(void) {
    unsigned char *src = (unsigned char *)(g_eventQueueEnd * 4);
    unsigned char *dst = (unsigned char *)(g_scaledInit_00542044 * 4);
    unsigned int v;
    v = *(unsigned int *)(src);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x38) = v;
    v = *(unsigned int *)(src + 4);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x3c) = v;
    v = *(unsigned int *)(src + 8);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x40) = v;
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
extern packed_ptr g_xformEntityIdx;
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
void MStackPushCallPop_0040a830(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueEnd;
    func_0040a888();
    g_eventQueueEnd = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
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
extern u32 g_dlMode;
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
void DualPushCallStore_004231b0(void) {
    func_0049cb34(&g_data_004234f0, 3);
    g_state_00538040 = g_scaledInit_00542044;
    func_0049cb34(&g_data_00423570, 4);
    g_state_00538044 = g_scaledInit_00542044;
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
void ScaledIncCmpDualJmp_00429800(void) {
    unsigned int idx;
    unsigned int scaled;
    unsigned int v;
    int cmp_val;
    idx = g_fightGroupHead;
    scaled = *(unsigned int *)(idx * 4 + 0x24);
    g_scaledInit_00542044 = scaled;
    v = *(unsigned int *)(idx * 4 + 0x28) + 1;
    g_walkCallback = (void (*)(void))v;
    cmp_val = *(int *)(scaled * 4 + 4);
    if ((int)v >= cmp_val) {
        func_0042985c();
        return;
    }
    func_004298d7();
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
 *   mov     [eax*4 + 0], OFFSET InstallSelfThreeStateLeaPlus22_00437970
 *   jmp     T
 *   ret
 */
extern void func_0049e4d0(void);
extern void InstallSelfThreeStateLeaPlus22_00437970(void);
extern void func_0048121c(void);
void CallPauseMStackPushSet2Jmp_00437930(void) {
    unsigned int top;
    func_0049e4d0();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))2;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&InstallSelfThreeStateLeaPlus22_00437970;
    func_0048121c();
}
