/**
 * Thirteenth batch of one-off matches (size 31-45 bytes).
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404ef0 (33b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     [g_pendingNodeType], eax
 *   mov     edx, [ecx*4 + 0x0c]
 *   mov     [g_eventQueueWorkType], edx
 *   jmp     T
 */
extern void func_0049cb44(void);
__declspec(naked) void StoreLoadJmp_00404ef0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [g_pendingNodeType], eax
        mov     edx, dword ptr [ecx*4 + 0x0c]
        mov     dword ptr [g_eventQueueWorkType], edx
        jmp     func_0049cb44
    }
}

/* @addr 0x00406b20 (34b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x10]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0xb
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     +0xf
 *   ret
 */
extern void func_00406b3a(void);
__declspec(naked) void ScaledLoadOrSetJmp_00406b20(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x10]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0bh
        mov     dword ptr [g_scaledInit_00542044], ecx
        jmp     func_00406b3a
        ret
    }
}

/* @addr 0x00409260 (32b)
 *   mov     eax, [g_xformEntityIdx]
 *   mov     ecx, [g_walkCallback]
 *   shl     eax, 2
 *   mov     [eax + 4], ecx
 *   xor     ecx, ecx
 *   mov     [eax + 8], ecx
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x0c], ecx
 *   ret
 */
extern unsigned int g_xformEntityIdx;
void ScaledStoreThree_00409260(void) {
    unsigned int *base = (unsigned int *)(g_xformEntityIdx * 4);
    base[1] = (unsigned int)g_walkCallback;
    base[2] = 0;
    g_walkCallback = (void (*)(void))0;
    base[3] = 0;
}

/* @addr 0x00409320 (40b)
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      al, 4
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void ScaledOr4DirtyClear_00409320(void) {
    unsigned int idx = g_scaledInit_00542044;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x34) | 4;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(idx * 4 + 0x34) = v;
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}

/* @addr 0x00409350 (35b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0x34]
 *   and     ecx, 0xfffffffb
 *   mov     [eax*4 + 0x34], ecx
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void ScaledAnd4InvDirtyClear_00409350(void) {
    unsigned int idx = g_scaledInit_00542044;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x34) & 0xFFFFFFFBu;
    *(unsigned int *)(idx * 4 + 0x34) = v;
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}

/* @addr 0x00413040 (39b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_fightGroupHead]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   mov     [g_walkCallback], 9
 *   jmp     T
 */
extern void func_0041309e(void);
__declspec(naked) void MStackPushSet9Jmp_00413040(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     dword ptr [g_walkCallback], 9
        jmp     func_0041309e
    }
}

/* @addr 0x004296f0 (31b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_eventQueueCurrent]
 *   mov     [eax*4 + 0x28], ecx
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void ScaledStoreCurDirtyClear_004296f0(void) {
    unsigned int idx = g_fightGroupHead;
    *(unsigned int *)(idx * 4 + 0x28) = g_eventQueueCurrent;
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}

/* @addr 0x00429730 (31b): same shape, or al,1 instead of and al,0xfe */
void ScaledStoreCurDirtyOr1_00429730(void) {
    unsigned int idx = g_fightGroupHead;
    *(unsigned int *)(idx * 4 + 0x28) = g_eventQueueCurrent;
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}

/* @addr 0x00428300 (33b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_eventQueueIdx]
 *   mov     [eax*4 + 0x24], ecx
 *   mov     [g_walkCallback], 0
 *   jmp     +0xf
 */
extern void func_00428328(void);
__declspec(naked) void ScaledStoreIdxZeroJmp_00428300(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [eax*4 + 0x24], ecx
        mov     dword ptr [g_walkCallback], 0
        jmp     func_00428328
    }
}

/* @addr 0x00428e40 (33b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_xformEntityIdx]
 *   mov     [g_eventQueueCurrent], 0
 *   mov     [eax*4 + 0x24], ecx
 *   jmp     +0xf
 */
extern void func_00428e68(void);
__declspec(naked) void ScaledStoreEntZeroJmp_00428e40(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_eventQueueCurrent], 0
        mov     dword ptr [eax*4 + 0x24], ecx
        jmp     func_00428e68
    }
}

/* @addr 0x00422050 (43b)
 *   push    0x29
 *   push    0x004573e0
 *   call    F1
 *   add     esp, 8
 *   push    0x2c
 *   push    0x00422200
 *   call    F1
 *   mov     eax, [g_xformDirtyFlags]
 *   add     esp, 8
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern int func_0049cb40_t(int, void *);
extern void *g_data_004573e0;
extern void *g_data_00422200;
__declspec(naked) void TwoPushCallSetDirty_00422050(void) {
    __asm {
        push    0x29
        push    OFFSET g_data_004573e0
        call    func_0049cb40_t
        add     esp, 8
        push    0x2c
        push    OFFSET g_data_00422200
        call    func_0049cb40_t
        mov     eax, dword ptr [g_xformDirtyFlags]
        add     esp, 8
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x00428650 (41b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x28]
 *   dec     eax
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x28], eax
 *   ret
 */
extern void func_0040592c(void);
__declspec(naked) void CallPauseDecScaled_00428650(void) {
    __asm {
        call    func_0040592c
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ah
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x28]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x28], eax
        ret
    }
}

/* @addr 0x0042c390 (31b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     [eax*4 + 0x74], 0x501
 *   mov     [g_walkCallback], 8
 *   jmp     T
 */
extern void func_00471006(void);
__declspec(naked) void ScaledStore501Set8Jmp_0042c390(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x74], 0x501
        mov     dword ptr [g_walkCallback], 8
        jmp     func_00471006
    }
}
