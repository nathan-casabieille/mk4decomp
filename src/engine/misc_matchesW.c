/**
 * Thirty-second batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x00438650 (58b)
 *   mov     eax, [g_eventQueueChild]
 *   test    eax, eax
 *   jl      +7
 *   cmp     eax, 0xf0
 *   jle     +0x17
 *   mov     eax, [g_xformDirtyFlags]
 *   mov     [g_eventQueueChild], 0
 *   or      al, 4
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   dec     eax
 *   mov     [g_eventQueueChild], eax
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfb
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
__declspec(naked) void DecOrZeroDirty4_00438650(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueChild]
        test    eax, eax
        _emit   7ch
        _emit   07h
        cmp     eax, 0xf0
        _emit   7eh
        _emit   17h
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_eventQueueChild], 0
        or      al, 4
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfb
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x00446600 (58b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, 1
 *   mov     eax, [eax*4 + 0x60]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   shl     eax, 2
 *   mov     [eax + 0x1c], ecx
 *   mov     ecx, [eax + 0x20]
 *   or      ch, 1
 *   mov     [eax + 0x20], ecx
 *   mov     ecx, 0x13b6
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x38], ecx
 *   ret
 */
__declspec(naked) void ScaledInitOrSet13b6_00446600(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, 1
        mov     eax, dword ptr [eax*4 + 0x60]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        shl     eax, 2
        mov     dword ptr [eax + 0x1c], ecx
        mov     ecx, dword ptr [eax + 0x20]
        or      ch, 1
        mov     dword ptr [eax + 0x20], ecx
        mov     ecx, 0x13b6
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x38], ecx
        ret
    }
}

/* @addr 0x0045bfe0 (60b)
 *   mov     ecx, [g_framePauseFlag]
 *   xor     eax, eax
 *   mov     al, byte ptr [g_state_00542071]
 *   test    ecx, ecx
 *   mov     [g_walkCallback], eax
 *   jne     +0x25
 *   cmp     eax, 2
 *   jne     +0x20
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x12
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [g_walkCallback]
 *   mov     [ecx*4 + 0x24], eax
 *   ret
 */
extern unsigned char g_byte_00542071;
extern void func_0045c005(void);
__declspec(naked) void PauseTestCmp2CallStore_0045bfe0(void) {
    __asm {
        mov     ecx, dword ptr [g_framePauseFlag]
        xor     eax, eax
        mov     al, byte ptr [g_byte_00542071]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   25h
        cmp     eax, 2
        _emit   75h
        _emit   20h
        call    func_0045c005
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x24], eax
        ret
    }
}

/* @addr 0x0045e590 (55b)
 *   mov     eax, [g_state_00535ddc]
 *   cmp     eax, 0x1cccc
 *   mov     [g_walkCallback], eax
 *   jge     +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   cmp     eax, 0x30000
 *   jle     +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   jmp     +0x79
 */
extern unsigned int g_state_00535ddc_w;
extern void func_0045e60c(void);
__declspec(naked) void RangeCheckJmp_0045e590(void) {
    __asm {
        mov     eax, dword ptr [g_state_00535ddc_w]
        cmp     eax, 0x1cccc
        mov     dword ptr [g_walkCallback], eax
        _emit   7dh
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        cmp     eax, 0x30000
        _emit   7eh
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        jmp     func_0045e60c
    }
}

/* @addr 0x0047e600 (51b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, 0x1017
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x74], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0d
 *   push    0x004ed5e0
 *   call    F2
 *   add     esp, 4
 *   ret
 */
extern void func_004fa320(void);
extern int func_0046d4d8(void *p);
extern void *g_data_004ed5e0;
__declspec(naked) void Set1017CallPausePush_0047e600(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x1017
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    func_004fa320
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    OFFSET g_data_004ed5e0
        call    func_0046d4d8
        add     esp, 4
        ret
    }
}

/* @addr 0x00482eb0 (53b)
 *   push    0x004ee340
 *   call    F1
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     +0x0d
 *   push    0x004ee348
 *   call    F2
 *   add     esp, 4
 *   ret
 *   nop * 12
 *   jmp     +0xb
 */
extern int func_004907bc(void *);
extern int func_00459500(void *);
extern void *g_data_004ee340;
extern void *g_data_004ee348;
extern void func_00482eec(void);
__declspec(naked) void DualPushCallPause_00482eb0(void) {
    __asm {
        push    OFFSET g_data_004ee340
        call    func_004907bc
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    OFFSET g_data_004ee348
        call    func_00459500
        add     esp, 4
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        jmp     func_00482eec
    }
}

/* @addr 0x00484b00 (56b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x29
 *   test    byte [g_xformDirtyFlags], 4
 *   je      +0x1b
 *   mov     eax, [g_matrixStackTop]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], 0x00484b40
 *   jmp     T
 *   jmp     +9
 *   ret
 */
extern void func_00484f50(void);
extern void GuardedDispatch4_00484b40(void);
extern void func_0042b594(void);
extern void func_00484b13(void);
__declspec(naked) void CallPauseDirtyMStackPush484b40_00484b00(void) {
    __asm {
        call    func_00484f50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   1bh
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET GuardedDispatch4_00484b40
        jmp     func_0042b594
        jmp     func_00484b13
        ret
    }
}

/* @addr 0x00488e90 (56b)
 *   mov     eax, [g_walkCallback]
 *   mov     ecx, 1
 *   cmp     eax, ecx
 *   jne     +7
 *   or      [g_xformDirtyFlags], ecx
 *   ret
 *   mov     eax, [g_state_00537f98]
 *   mov     [g_walkCallback], eax
 *   test    eax, eax
 *   mov     eax, [g_xformDirtyFlags]
 *   je      +8
 *   or      eax, ecx
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_state_00537f98;
__declspec(naked) void CmpEax1OrSetDirty_00488e90(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, 1
        cmp     eax, ecx
        _emit   75h
        _emit   07h
        or      dword ptr [g_xformDirtyFlags], ecx
        ret
        mov     eax, dword ptr [g_state_00537f98]
        mov     dword ptr [g_walkCallback], eax
        test    eax, eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        _emit   74h
        _emit   08h
        or      eax, ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x0048e550 (54b)
 *   mov     eax, [esp+4]
 *   mov     edx, [g_fightGroupHead]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     ecx, [eax*4 + 0]
 *   mov     [g_walkCallback], ecx
 *   mov     ecx, [g_player1NodeIdx]
 *   cmp     edx, ecx
 *   je      +0x0c
 *   mov     eax, [eax*4 + 4]
 *   mov     [g_scaledInit_00542044], eax
 *   ret
 */
extern packed_ptr g_player1NodeIdx;
extern packed_ptr g_fightGroupHead;
__declspec(naked) void ArgScaledLoadCmpP1_0048e550(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     edx, dword ptr [g_fightGroupHead]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_walkCallback], ecx
        mov     ecx, dword ptr [g_player1NodeIdx]
        cmp     edx, ecx
        _emit   74h
        _emit   0ch
        mov     eax, dword ptr [eax*4 + 4]
        mov     dword ptr [g_scaledInit_00542044], eax
        ret
    }
}

/* @addr 0x00490030 (54b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     edx, [ecx*4 + 0x38]
 *   mov     [g_fightGroupHead], edx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0a
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     [g_fightGroupHead], eax
 *   ret
 */
extern void func_00490074(void);
__declspec(naked) void SwapCallRestore_00490030(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [ecx*4 + 0x38]
        mov     dword ptr [g_fightGroupHead], edx
        call    func_00490074
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ah
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_fightGroupHead], eax
        ret
    }
}
