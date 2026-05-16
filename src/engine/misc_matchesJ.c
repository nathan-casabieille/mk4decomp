/**
 * Nineteenth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004751c0 (43b)
 *   mov     eax, [g_state_00537f48]
 *   mov     ecx, [g_eventQueueEnd]
 *   mov     [g_eventQueueCurrent], eax
 *   mov     eax, [g_player1NodeIdx]
 *   cmp     ecx, eax
 *   mov     [g_walkCallback], eax
 *   je      +0x0c
 *   mov     ecx, [g_state_005380e0]
 *   mov     [g_eventQueueCurrent], ecx
 *   ret
 */
extern s32 g_dlNalt1;       /* 0x00537f48 */
extern unsigned int g_state_005380e0;
__declspec(naked) void TestP1ReplaceCurrent_004751c0(void) {
    __asm {
        mov     eax, dword ptr [g_dlNalt1]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     eax, dword ptr [g_player1NodeIdx]
        cmp     ecx, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   0ch
        mov     ecx, dword ptr [g_state_005380e0]
        mov     dword ptr [g_eventQueueCurrent], ecx
        ret
    }
}

/* @addr 0x00480fb0 (38b)
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, 0x004ef4d0
 *   shr     eax, 2
 *   add     eax, ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_xformEntityIdx], eax
 *   jmp     T
 */
extern void func_0048f8be(void);
__declspec(naked) void ScaledLitAddJmp_00480fb0(void) {
    __asm {
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, 0x004ef4d0
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_xformEntityIdx], eax
        jmp     func_0048f8be
    }
}

/* @addr 0x00488ba0 (42b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret              ; jne +0x1b
 *   test    byte [g_xformDirtyFlags], 1
 *   jne     +5                ; if dirty, skip jmp
 *   jmp     T                 ; not dirty, jump out
 *   push    0x004ef1d0
 *   call    F2
 *   add     esp, 4
 *   ret
 */
extern void DualCondMatchSet_00488dc0(void);
extern int func_00459500(void *);
extern void *g_data_004ef1d0;
extern void func_00488bd9(void);
void CallPauseDirtyPushCall_00488ba0(void) {
    DualCondMatchSet_00488dc0();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) == 0) {
        func_00488bd9();
        return;
    }
    func_00459500(&g_data_004ef1d0);
}

/* @addr 0x00488c00 (37b)
 *   mov     eax, 0x00500d4c
 *   push    0x004ef1f8
 *   shr     eax, 2
 *   mov     [g_xformEntityIdx], eax
 *   mov     [g_walkCallback], 0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern void *g_data_004ef1f8;
extern int func_00491508(void *);
extern int g_data_00500d4c;
void LiteralPushCallEntZero_00488c00(void) {
    g_xformEntityIdx = ((unsigned int)&g_data_00500d4c) >> 2;
    g_walkCallback = (void (*)(void))0;
    func_00491508(&g_data_004ef1f8);
}

/* @addr 0x00488c30 (43b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, 0x005006e0
 *   mov     [g_walkCallback], 0
 *   shr     eax, 2
 *   mov     [g_xformEntityIdx], eax
 *   jmp     +6
 *   ret
 */
extern void SaveSwapCallRestore_00489030(void);
extern void func_00488c61(void);
__declspec(naked) void CallPauseLitInitJmp_00488c30(void) {
    __asm {
        call    SaveSwapCallRestore_00489030
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ch
        mov     eax, 0x005006e0
        mov     dword ptr [g_walkCallback], 0
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        jmp     func_00488c61
        ret
    }
}

/* @addr 0x00488ed0 (33b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, [eax*4 + 0x7c]
 *   cmp     eax, ecx
 *   mov     [g_eventQueueCurrent], eax
 *   jl      +0x10
 *   ret
 */
extern void func_00488f04(void);
__declspec(naked) void ScaledCmpJlJmp_00488ed0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, dword ptr [eax*4 + 0x7c]
        cmp     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   7ch
        _emit   05h
        jmp     func_00488f04
        ret
    }
}

/* @addr 0x00489f60 (33b)
 *   mov     eax, [g_walkCallback]
 *   cmp     eax, 0x32
 *   ja      .skip
 *   mov     ax, word ptr [eax*2 + 0x004ef998]
 *   test    ax, ax
 *   je      .skip
 *   push    eax
 *   call    F
 *   add     esp, 4
 * .skip:
 *   ret
 */
extern unsigned short g_table_004ef998[];
extern int TaggedSceneDispatch_004be690(int);
__declspec(naked) void TableLookupCall_00489f60(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0x32
        _emit   77h
        _emit   16h
        mov     ax, word ptr [eax*2 + g_table_004ef998]
        test    ax, ax
        _emit   74h
        _emit   09h
        push    eax
        call    TaggedSceneDispatch_004be690
        add     esp, 4
        ret
    }
}

/* @addr 0x00489ff0 (33b): same shape with cmp=0x70, table=0x004efa00 */
extern unsigned short g_table_004efa00[];
__declspec(naked) void TableLookupCall_00489ff0(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0x70
        _emit   77h
        _emit   16h
        mov     ax, word ptr [eax*2 + g_table_004efa00]
        test    ax, ax
        _emit   74h
        _emit   09h
        push    eax
        call    TaggedSceneDispatch_004be690
        add     esp, 4
        ret
    }
}

/* @addr 0x0048a130 (33b): same shape with cmp=0x41, table=0x004efd18 */
extern unsigned short g_table_004efd18[];
__declspec(naked) void TableLookupCall_0048a130(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0x41
        _emit   77h
        _emit   16h
        mov     ax, word ptr [eax*2 + g_table_004efd18]
        test    ax, ax
        _emit   74h
        _emit   09h
        push    eax
        call    TaggedSceneDispatch_004be690
        add     esp, 4
        ret
    }
}

/* @addr 0x0048a160 (33b): same shape with cmp=0x13, table=0x004efae0 */
extern unsigned short g_table_004efae0[];
__declspec(naked) void TableLookupCall_0048a160(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0x13
        _emit   77h
        _emit   16h
        mov     ax, word ptr [eax*2 + g_table_004efae0]
        test    ax, ax
        _emit   74h
        _emit   09h
        push    eax
        call    TaggedSceneDispatch_004be690
        add     esp, 4
        ret
    }
}

/* @addr 0x0048a020 (45b)
 *   mov     eax, [g_state_00541dc0]
 *   test    eax, eax
 *   jl      +0x23
 *   mov     eax, [g_walkCallback]
 *   test    eax, eax
 *   jl      +0x1a
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0]
 *   push    eax
 *   mov     [g_walkCallback], eax
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern unsigned int g_state_00541dc0;
extern int func_004be690_b(int);
__declspec(naked) void GuardedScaledCall_0048a020(void) {
    __asm {
        mov     eax, dword ptr [g_state_00541dc0]
        test    eax, eax
        _emit   7ch
        _emit   23h
        mov     eax, dword ptr [g_walkCallback]
        test    eax, eax
        _emit   7ch
        _emit   1ah
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0]
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    func_004be690_b
        add     esp, 4
        ret
    }
}

/* @addr 0x0048b450 (37b)
 *   mov     eax, [g_eventQueueChild]
 *   mov     [g_eventQueueWorkType], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     ecx, [g_acc_00542078]
 *   mov     [g_currentNodeFlags], ecx
 *   ret
 */
extern unsigned int g_acc_00542078;
extern void func_0048b606(void);
__declspec(naked) void StoreCallPauseStore_0048b450(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueChild]
        mov     dword ptr [g_eventQueueWorkType], eax
        call    func_0048b606
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ch
        mov     ecx, dword ptr [g_acc_00542078]
        mov     dword ptr [g_currentNodeFlags], ecx
        ret
    }
}

/* @addr 0x0048e3e0 (31b)
 *   mov     eax, [0x0052aac4]
 *   cmp     eax, 2
 *   mov     [g_walkCallback], eax
 *   je      +0x0f
 *   mov     eax, 0x0b
 *   mov     [g_walkCallback], eax
 *   mov     [0x0052aac4], eax
 *   ret
 */
extern unsigned int g_state_0052aac4_j;
__declspec(naked) void Cmp2OrSet0b_0048e3e0(void) {
    __asm {
        mov     eax, dword ptr [g_state_0052aac4_j]
        cmp     eax, 2
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   0fh
        mov     eax, 0x0b
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_0052aac4_j], eax
        ret
    }
}

/* @addr 0x0048e5e0 (32b)
 *   mov     eax, [esp+4]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     ecx, [eax*4 + 0]
 *   inc     eax
 *   mov     [g_walkCallback], ecx
 *   mov     [g_eventQueueTotal], eax
 *   ret
 */
__declspec(naked) void IterStepNoSecond_0048e5e0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        ret
    }
}

/* @addr 0x0048e600 (44b)
 *   mov     eax, [esp+4]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     ecx, [eax*4 + 0]
 *   inc     eax
 *   mov     [g_eventQueueTotal], eax
 *   mov     eax, [g_baseSel_00542060]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x4c], ecx
 *   ret
 */
__declspec(naked) void IterStepScaledStore_0048e600(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_eventQueueTotal], eax
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x4c], ecx
        ret
    }
}

/* @addr 0x0048e780 (35b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x3c]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   jmp     +0x2d
 */
extern void ScaledLoadJmp_74_0048e7b0(void);
__declspec(naked) void ScaledChain3c74Jmp_0048e780(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0x74]
        mov     dword ptr [g_walkCallback], ecx
        jmp     ScaledLoadJmp_74_0048e7b0
    }
}

/* @addr 0x0048ee50 (35b)
 *   mov     eax, [g_player2NodeIdx]
 *   mov     ecx, [g_fightGroupHead]
 *   cmp     ecx, eax
 *   mov     [g_scaledInit_00542044], eax
 *   jne     +0x0a
 *   mov     eax, [g_player1NodeIdx]
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     +0x1d
 */
extern void func_0048ee77(void);
__declspec(naked) void CmpP2P1ScaledJmp_0048ee50(void) {
    __asm {
        mov     eax, dword ptr [g_player2NodeIdx]
        mov     ecx, dword ptr [g_fightGroupHead]
        cmp     ecx, eax
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   75h
        _emit   0ah
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     func_0048ee77
    }
}

/* @addr 0x0048ee90 (39b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0x48]
 *   mov     [g_walkCallback], ecx
 *   mov     eax, [eax*4 + 0x58]
 *   sub     ecx, eax
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [g_walkCallback], ecx
 *   ret
 */
__declspec(naked) void ScaledSubStore_0048ee90(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 0x48]
        mov     dword ptr [g_walkCallback], ecx
        mov     eax, dword ptr [eax*4 + 0x58]
        sub     ecx, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], ecx
        ret
    }
}

/* @addr 0x0048f3c0 (43b)
 *   mov     edx, [g_xformDirtyFlags]
 *   mov     eax, [g_state_0053a408]
 *   mov     ecx, 4
 *   mov     [g_walkCallback], eax
 *   or      edx, ecx
 *   test    eax, eax
 *   mov     [g_xformDirtyFlags], edx
 *   je      +9
 *   mov     eax, edx
 *   xor     eax, ecx
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_state_0053a408;
__declspec(naked) void DirtyFlagsManipB_0048f3c0(void) {
    __asm {
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [g_state_0053a408]
        mov     ecx, 4
        mov     dword ptr [g_walkCallback], eax
        or      edx, ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   09h
        mov     eax, edx
        xor     eax, ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x0048e710 (40b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [0x0052aac4]
 *   sar     eax, 2
 *   add     eax, ecx
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     eax
 */
extern unsigned int g_state_0052aac4_k;
__declspec(naked) void ArgSarAddDerefJmp_0048e710(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [g_state_0052aac4_k]
        sar     eax, 2
        add     eax, ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     eax
    }
}
