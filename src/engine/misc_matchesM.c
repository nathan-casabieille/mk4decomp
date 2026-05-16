/**
 * Twenty-second batch of one-off matches.
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1080 (35b)
 *   push    0x15
 *   push    0x004a6068        ; was 0x004a6060? actually let me decode
 *   call    F
 *   mov     ax, word ptr [0x004e2860]
 *   add     esp, 8
 *   push    eax
 *   call    F2
 *   add     esp, 4
 *   jmp     T
 */
extern int func_00498b40(void *p, int n);
extern int func_004be698(int v);
extern void *g_data_004a6068;
extern unsigned short g_word_004e2860;
extern void func_00428c10(void);
__declspec(naked) void Push15PushDataCallWordCallJmp_004a1080(void) {
    __asm {
        push    0x15
        push    OFFSET g_data_004a6068
        call    func_00498b40
        mov     ax, word ptr [g_word_004e2860]
        add     esp, 8
        push    eax
        call    func_004be698
        add     esp, 4
        jmp     func_00428c10
    }
}

/* @addr 0x004a1c50 (38b)
 *   mov     cl, byte ptr [0x004d50b8]
 *   mov     eax, 1
 *   test    cl, al
 *   jne     +0x16
 *   test    byte ptr [0x004d50b4], 0x10
 *   jne     +0x0d
 *   movsx   eax, byte ptr [0x004d50c0]
 *   and     eax, 4
 *   shr     eax, 2
 *   ret
 */
extern unsigned char g_byte_004d50b8;
extern unsigned char g_byte_004d50b4;
extern char g_byte_004d50c0;
__declspec(naked) void TripleByteCheck_004a1c50(void) {
    __asm {
        mov     cl, byte ptr [g_byte_004d50b8]
        mov     eax, 1
        test    cl, al
        _emit   75h
        _emit   16h
        test    byte ptr [g_byte_004d50b4], 0x10
        _emit   75h
        _emit   0dh
        movsx   eax, byte ptr [g_byte_004d50c0]
        and     eax, 4
        shr     eax, 2
        ret
    }
}

/* @addr 0x004a1c80 (45b)
 *   test    byte ptr [g_byte_004d50b8], 0x10
 *   je      +6
 *   mov     eax, 1
 *   ret
 *   mov     eax, [0x004d50b4]
 *   test    ah, 0x10
 *   je      +6
 *   mov     eax, 1
 *   ret
 *   movsx   eax, byte ptr [0x004d50c0]
 *   and     eax, 0x20
 *   shr     eax, 5
 *   ret
 */
extern unsigned int g_state_004d50b4;
__declspec(naked) void TripleByteCheck20_004a1c80(void) {
    __asm {
        test    byte ptr [g_byte_004d50b8], 0x10
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        mov     eax, dword ptr [g_state_004d50b4]
        test    ah, 0x10
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        movsx   eax, byte ptr [g_byte_004d50c0]
        and     eax, 0x20
        shr     eax, 5
        ret
    }
}

/* @addr 0x004a1d20 (45b)
 *   mov     eax, [0x004d50b4]
 *   test    eax, eax
 *   jne     +0x1e
 *   mov     eax, [0x004d50b8]
 *   test    eax, eax
 *   jne     +0x15
 *   mov     eax, [0x004d50c0]
 *   test    eax, eax
 *   jne     +0x0c
 *   mov     eax, [0x004d50bc]
 *   test    eax, eax
 *   jne     +3
 *   xor     eax, eax
 *   ret
 *   mov     eax, 1
 *   ret
 */
extern unsigned int g_state_004d50b8;
extern unsigned int g_state_004d50c0;
extern unsigned int g_state_004d50bc;
__declspec(naked) void Test4StatesAny_004a1d20(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d50b4]
        test    eax, eax
        _emit   75h
        _emit   1eh
        mov     eax, dword ptr [g_state_004d50b8]
        test    eax, eax
        _emit   75h
        _emit   15h
        mov     eax, dword ptr [g_state_004d50c0]
        test    eax, eax
        _emit   75h
        _emit   0ch
        mov     eax, dword ptr [g_state_004d50bc]
        test    eax, eax
        _emit   75h
        _emit   03h
        xor     eax, eax
        ret
        mov     eax, 1
        ret
    }
}

/* @addr 0x004a22c0 (44b)
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [eax*4 + 0], 0
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     [g_walkCallback], 2
 *   mov     [ecx*4 + 0], 2
 *   ret
 */
__declspec(naked) void DualScaledStoreConst_004a22c0(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     dword ptr [eax*4 + 0], 0
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_walkCallback], 2
        mov     dword ptr [ecx*4 + 0], 2
        ret
    }
}

/* @addr 0x004a7db0 (38b)
 *   mov     eax, [0x004f3ae4]
 *   mov     ecx, [0x0054359c]
 *   dec     eax
 *   cmp     ecx, eax
 *   jge     +9
 *   mov     eax, ecx
 *   inc     eax
 *   mov     [0x0054359c], eax
 *   ret
 *   mov     eax, [g_xformDirtyFlags]
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern int g_state_004f3ae4;
extern int g_state_0054359c;
__declspec(naked) void IncBoundedDirty_004a7db0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004f3ae4]
        mov     ecx, dword ptr [g_state_0054359c]
        dec     eax
        cmp     ecx, eax
        _emit   7dh
        _emit   09h
        mov     eax, ecx
        inc     eax
        mov     dword ptr [g_state_0054359c], eax
        ret
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x004ac100 (31b)
 *   mov     eax, [g_player1NodeIdx]
 *   mov     ecx, [g_fightGroupHead]
 *   cmp     ecx, eax
 *   mov     [g_scaledInit_00542044], eax
 *   jne     +0x0a
 *   mov     eax, [g_player2NodeIdx]
 *   mov     [g_scaledInit_00542044], eax
 *   ret
 */
extern packed_ptr g_player1NodeIdx;
extern packed_ptr g_player2NodeIdx;
__declspec(naked) void CmpP1ScaledInitB_004ac100(void) {
    __asm {
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     ecx, dword ptr [g_fightGroupHead]
        cmp     ecx, eax
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   75h
        _emit   0ah
        mov     eax, dword ptr [g_player2NodeIdx]
        mov     dword ptr [g_scaledInit_00542044], eax
        ret
    }
}

/* @addr 0x004ab320 (33b)
 *   mov     eax, [g_walkCallback]
 *   test    eax, eax
 *   jne     +6
 *   mov     [g_walkCallback], eax
 *   ret
 *   cdq
 *   push    edx
 *   push    eax
 *   push    1
 *   push    0
 *   call    F
 *   mov     [g_walkCallback], eax
 *   ret
 */
extern int func_004cb680(int a, int b, int c, int d);
__declspec(naked) void DivLongPushCall_004ab320(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        test    eax, eax
        _emit   75h
        _emit   06h
        mov     dword ptr [g_walkCallback], eax
        ret
        cdq
        push    edx
        push    eax
        push    1
        push    0
        call    func_004cb680
        mov     dword ptr [g_walkCallback], eax
        ret
    }
}

/* @addr 0x004abfe0 (38b)
 *   mov     eax, [g_fightGroupHead]
 *   xor     ecx, ecx
 *   shl     eax, 2
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x6c], ecx
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax + 0x70], ecx
 *   mov     edx, [g_walkCallback]
 *   mov     [eax + 0x74], edx
 *   ret
 */
__declspec(naked) void ZeroThreeFields6c_004abfe0(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        xor     ecx, ecx
        shl     eax, 2
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x6c], ecx
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x70], ecx
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x74], edx
        ret
    }
}

/* @addr 0x004ab600 (39b)
 *   mov     eax, [0x004d5100]
 *   mov     ecx, [0x004d5104]
 *   add     eax, ecx
 *   mov     edx, eax
 *   mov     [0x004d5100], eax
 *   sar     edx, 0x1f
 *   add     edx, eax
 *   mov     [g_walkCallback], edx
 *   add     ecx, edx
 *   mov     [0x004d5104], ecx
 *   ret
 */
extern int g_state_004d5100;
extern int g_state_004d5104;
__declspec(naked) void DualAddSar_004ab600(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d5100]
        mov     ecx, dword ptr [g_state_004d5104]
        add     eax, ecx
        mov     edx, eax
        mov     dword ptr [g_state_004d5100], eax
        sar     edx, 0x1f
        add     edx, eax
        mov     dword ptr [g_walkCallback], eax
        add     ecx, edx
        mov     dword ptr [g_state_004d5104], ecx
        ret
    }
}

/* @addr 0x004ab270 (34b)
 *   mov     ecx, [esp+4]
 *   push    esi
 *   xor     eax, eax
 *   mov     dl, 1
 * .loop:
 *   movsx   esi, byte ptr [eax + 0x004f3ac8]
 *   cmp     esi, ecx
 *   jne     .skip
 *   mov     [eax + 0x004f3ac8], dl
 * .skip:
 *   inc     eax
 *   cmp     eax, 0x10
 *   jl      .loop
 *   pop     esi
 *   ret
 */
extern char g_table_004f3ac8[16];
__declspec(naked) void MarkSlot_004ab270(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        push    esi
        xor     eax, eax
        mov     dl, 1
        movsx   esi, byte ptr [eax + g_table_004f3ac8]
        cmp     ecx, esi
        _emit   75h
        _emit   06h
        mov     byte ptr [eax + g_table_004f3ac8], dl
        inc     eax
        cmp     eax, 0x10
        _emit   7ch
        _emit   0e9h
        pop     esi
        ret
    }
}

/* @addr 0x004b0d80 (39b)
 *   mov     edx, [0x007ab064]
 *   mov     eax, [0x007ab05c]
 *   inc     edx
 *   test    eax, eax
 *   mov     [0x007ab064], edx
 *   je      +6
 *   mov     ecx, [eax]
 *   push    eax
 *   call    [ecx + 0x48]
 *   push    0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern unsigned int g_state_007ab064;
extern void *g_iface_007ab05c;
extern int func_004b0982(int);
__declspec(naked) void IncCallVtablePushCall_004b0d80(void) {
    __asm {
        mov     edx, dword ptr [g_state_007ab064]
        mov     eax, dword ptr [g_iface_007ab05c]
        inc     edx
        test    eax, eax
        mov     dword ptr [g_state_007ab064], edx
        _emit   74h
        _emit   06h
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x48]
        push    0
        call    func_004b0982
        add     esp, 4
        ret
    }
}

/* @addr 0x004b8f20 (43b): zero 8 fields
 *   xor     eax, eax
 *   mov     [0x00ab4d9c], eax
 *   mov     [0x00ab4da0], eax
 *   mov     [0x00ab4da4], eax
 *   mov     [0x00ab4da8], eax
 *   mov     [0x00ab4dac], eax
 *   mov     [0x00ab4db0], eax
 *   mov     [0x00ab4db4], eax
 *   mov     [0x00ab4db8], eax
 *   ret
 */
extern unsigned int g_state_00ab4d9c;
extern unsigned int g_state_00ab4da0;
extern unsigned int g_state_00ab4da4;
extern unsigned int g_state_00ab4da8;
extern unsigned int g_state_00ab4dac;
extern unsigned int g_state_00ab4db0;
extern unsigned int g_state_00ab4db4;
extern unsigned int g_state_00ab4db8;
__declspec(naked) void ZeroEightFields_004b8f20(void) {
    __asm {
        xor     eax, eax
        mov     dword ptr [g_state_00ab4d9c], eax
        mov     dword ptr [g_state_00ab4da0], eax
        mov     dword ptr [g_state_00ab4da4], eax
        mov     dword ptr [g_state_00ab4da8], eax
        mov     dword ptr [g_state_00ab4dac], eax
        mov     dword ptr [g_state_00ab4db0], eax
        mov     dword ptr [g_state_00ab4db4], eax
        mov     dword ptr [g_state_00ab4db8], eax
        ret
    }
}

/* @addr 0x004bd960 (45b): rep stosd 3 blocks
 *   push    edi
 *   mov     ecx, 0x6f
 *   xor     eax, eax
 *   mov     edi, 0x00ab4e78
 *   rep     stosd
 *   mov     ecx, 7
 *   mov     edi, 0x00ab4e00
 *   rep     stosd
 *   stosw
 *   mov     ecx, 0xc0
 *   xor     eax, eax
 *   mov     edi, 0x00ab44f8
 *   rep     stosd
 *   pop     edi
 *   ret
 */
__declspec(naked) void AppInit_Misc4(void) {
    __asm {
        push    edi
        mov     ecx, 0x6f
        xor     eax, eax
        mov     edi, 0x00ab4e78
        rep     stosd
        mov     ecx, 7
        mov     edi, 0x00ab4e00
        rep     stosd
        stosw
        mov     ecx, 0xc0
        xor     eax, eax
        mov     edi, 0x00ab44f8
        rep     stosd
        pop     edi
        ret
    }
}

/* @addr 0x004bea50 (42b)
 *   mov     ecx, [0x00ab5754]
 *   xor     eax, eax
 *   cmp     ecx, eax
 *   jne     +1
 *   ret
 *   push    0x00ab5760
 *   push    0x00ab575c
 *   mov     [0x00ab575c], eax
 *   mov     [0x00ab5760], eax
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern unsigned int g_state_00ab5754;
extern unsigned int g_state_00ab575c;
extern unsigned int g_state_00ab5760;
extern int func_004bedd0(unsigned int *, unsigned int *);
__declspec(naked) void TestPushPushCall_004bea50(void) {
    __asm {
        mov     ecx, dword ptr [g_state_00ab5754]
        xor     eax, eax
        cmp     ecx, eax
        _emit   75h
        _emit   01h
        ret
        push    OFFSET g_state_00ab5760
        push    OFFSET g_state_00ab575c
        mov     dword ptr [g_state_00ab575c], eax
        mov     dword ptr [g_state_00ab5760], eax
        call    func_004bedd0
        add     esp, 8
        ret
    }
}
