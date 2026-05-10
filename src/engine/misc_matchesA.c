/**
 * Tenth batch of one-off matches.
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b3d70 (30b)
 *   mov     eax, [g_X1]
 *   mov     ecx, [g_X2]
 *   cmp     ecx, eax
 *   jge     +2
 *   mov     eax, ecx
 *   mov     ecx, [g_X3]
 *   cmp     ecx, eax
 *   jge     +2
 *   mov     eax, ecx
 *   ret
 */
extern int g_min_007af984;
extern int g_min_007af988;
extern int g_min_007af98c;
__declspec(naked) void MinOfThree_004b3d70(void) {
    __asm {
        mov     eax, dword ptr [g_min_007af984]
        mov     ecx, dword ptr [g_min_007af988]
        cmp     ecx, eax
        _emit   7dh
        _emit   02h
        mov     eax, ecx
        mov     ecx, dword ptr [g_min_007af98c]
        cmp     ecx, eax
        _emit   7dh
        _emit   02h
        mov     eax, ecx
        ret
    }
}

/* @addr 0x004b3d90 (30b): max-of-three (jle instead of jge) */
__declspec(naked) void MaxOfThree_004b3d90(void) {
    __asm {
        mov     eax, dword ptr [g_min_007af984]
        mov     ecx, dword ptr [g_min_007af988]
        cmp     ecx, eax
        _emit   7eh
        _emit   02h
        mov     eax, ecx
        mov     ecx, dword ptr [g_min_007af98c]
        cmp     ecx, eax
        _emit   7eh
        _emit   02h
        mov     eax, ecx
        ret
    }
}

/* @addr 0x004b46d0 (27b)
 *   mov     eax, [g_X1]
 *   test    eax, eax
 *   je      .doit
 *   mov     eax, [g_X2]
 *   test    eax, eax
 *   jne     .ret
 * .doit:
 *   push    1
 *   call    [iat]
 * .ret:
 *   ret
 */
extern unsigned int g_state_007affe4;
extern unsigned int g_state_007afff0;
extern void *g_iat_007b0010;
__declspec(naked) void DualTestCallIat_004b46d0(void) {
    __asm {
        mov     eax, dword ptr [g_state_007affe4]
        test    eax, eax
        _emit   74h
        _emit   11h
        mov     eax, dword ptr [g_state_007afff0]
        test    eax, eax
        _emit   75h
        _emit   08h
        push    1
        call    dword ptr [g_iat_007b0010]
        ret
    }
}

/* @addr 0x004bcc50 (24b)
 *   xor     eax, eax
 *   mov     word ptr [0x00ab47fc], 0x1000
 *   mov     word ptr [0x00ab47f8], ax
 *   mov     word ptr [0x00ab47fa], ax
 *   ret
 */
extern unsigned short g_word_00ab47fc;
extern unsigned short g_word_00ab47f8;
extern unsigned short g_word_00ab47fa;
__declspec(naked) void Init16BitFields_004bcc50(void) {
    __asm {
        xor     eax, eax
        mov     word ptr [g_word_00ab47fc], 0x1000
        mov     word ptr [g_word_00ab47f8], ax
        mov     word ptr [g_word_00ab47fa], ax
        ret
    }
}

/* @addr 0x004bf070 (21b)
 *   mov     eax, 0x00b4d00f
 *   and     eax, 0xfffe0000
 *   mov     [0x00f85b38], eax
 *   ret
 *   jmp     +0x0b
 */
extern unsigned int g_state_00f85b38;
extern void func_004bf088(void);
__declspec(naked) void MovAndStoreRetJmp_004bf070(void) {
    __asm {
        mov     eax, 0x00b4d00f
        and     eax, 0xfffe0000
        mov     dword ptr [g_state_00f85b38], eax
        ret
        jmp     func_004bf088
    }
}

/* @addr 0x004bf090 (21b)
 *   mov     eax, [g_state_00f85b38]
 *   mov     [0x00f85b34], eax
 *   ret
 *   nop * 5
 *   jmp     +0x0b
 */
extern unsigned int g_state_00f85b34;
extern void func_004bf0a8(void);
__declspec(naked) void LoadStoreRetNopJmp_004bf090(void) {
    __asm {
        mov     eax, dword ptr [g_state_00f85b38]
        mov     dword ptr [g_state_00f85b34], eax
        ret
        nop
        nop
        nop
        nop
        nop
        jmp     func_004bf0a8
    }
}

/* @addr 0x004bf0b0 (16b)
 *   mov     eax, [g_state_00f85b38]
 *   add     eax, 0x00200000
 *   mov     [0x00f4d028], eax
 *   ret
 */
extern unsigned int g_state_00f4d028;
void AddStore_004bf0b0(void) {
    g_state_00f4d028 = g_state_00f85b38 + 0x00200000;
}

/* @addr 0x004c4370 (22b)
 *   push    esi
 *   xor     esi, esi
 * .loop:
 *   push    esi
 *   push    -1
 *   call    F
 *   add     esp, 8
 *   inc     esi
 *   cmp     esi, 0x10
 *   jl      .loop
 *   pop     esi
 *   ret
 */
extern int func_004c3be0(int, int);
__declspec(naked) void Loop16Init_004c4370(void) {
    __asm {
        push    esi
        xor     esi, esi
        push    esi
        push    -1
        call    func_004c3be0
        add     esp, 8
        inc     esi
        cmp     esi, 0x10
        _emit   7ch
        _emit   0efh
        pop     esi
        ret
    }
}

/* @addr 0x004c54b0 (20b)
 *   mov     eax, [0x00f9f850]
 *   mov     ecx, [esp+4]
 *   push    eax
 *   push    ecx
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern unsigned int g_state_00f9f850;
extern int func_004c54c2(int, int);
__declspec(naked) void LoadArgPushCall_004c54b0(void) {
    __asm {
        mov     eax, dword ptr [g_state_00f9f850]
        mov     ecx, dword ptr [esp + 4]
        push    eax
        push    ecx
        call    func_004c54c2
        add     esp, 8
        ret
    }
}

/* @addr 0x004c5db0 (21b)
 *   mov     eax, [esp+8]
 *   mov     ecx, [esp+4]
 *   push    0x40
 *   push    eax
 *   push    ecx
 *   call    F
 *   add     esp, 0xc
 *   ret
 */
extern int func_004c5d68(int, int, int);
__declspec(naked) void Push3ArgsCall_004c5db0(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        mov     ecx, dword ptr [esp + 4]
        push    0x40
        push    eax
        push    ecx
        call    func_004c5d68
        add     esp, 0x0c
        ret
    }
}

/* @addr 0x004c6820 (18b): forwarding wrapper push 0+0+arg+call */
extern int func_004c6857(int, int, int);
__declspec(naked) void PushZ2ArgCall_004c6820(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    0
        push    0
        push    eax
        call    func_004c6857
        add     esp, 0x0c
        ret
    }
}

/* @addr 0x004c6840 (18b): same shape, push 0+1+arg+call */
__declspec(naked) void PushZ1ArgCall_004c6840(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    0
        push    1
        push    eax
        call    func_004c6857
        add     esp, 0x0c
        ret
    }
}

/* @addr 0x004cbad0 (18b): same shape, push 4+0+arg+call */
extern int func_004cbae7(int, int, int);
__declspec(naked) void Push40ArgCall_004cbad0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    4
        push    0
        push    eax
        call    func_004cbae7
        add     esp, 0x0c
        ret
    }
}

/* @addr 0x004c8380 (17b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [eax]
 *   add     ecx, 4
 *   mov     [eax], ecx
 *   mov     eax, ecx
 *   mov     eax, [eax-4]
 *   ret
 */
__declspec(naked) void StreamReadDword_004c8380(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [eax]
        add     ecx, 4
        mov     dword ptr [eax], ecx
        mov     eax, ecx
        mov     eax, dword ptr [eax - 4]
        ret
    }
}

/* @addr 0x004c83a0 (18b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [eax]
 *   add     ecx, 8
 *   mov     [eax], ecx
 *   mov     eax, [ecx-8]
 *   mov     edx, [ecx-4]
 *   ret
 */
__declspec(naked) void StreamReadQword_004c83a0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [eax]
        add     ecx, 8
        mov     dword ptr [eax], ecx
        mov     eax, dword ptr [ecx - 8]
        mov     edx, dword ptr [ecx - 4]
        ret
    }
}

/* @addr 0x004c83c0 (18b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [eax]
 *   add     ecx, 4
 *   mov     [eax], ecx
 *   mov     eax, ecx
 *   mov     ax, [eax-4]                  ; word read with 66 prefix
 *   ret
 */
__declspec(naked) void StreamReadWord_004c83c0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [eax]
        add     ecx, 4
        mov     dword ptr [eax], ecx
        mov     eax, ecx
        mov     ax, word ptr [eax - 4]
        ret
    }
}

/* @addr 0x004c83e0 (19b)
 *   push    0x00030000
 *   push    0x00010000
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int func_004ccdf6(int, int);
__declspec(naked) void Push3000010000Call_004c83e0(void) {
    __asm {
        push    0x00030000
        push    0x00010000
        call    func_004ccdf6
        add     esp, 8
        ret
    }
}

/* @addr 0x004c9dd0 (19b)
 *   mov     eax, [esp+4]
 *   mov     [eax + 0x50], 0x00522880
 *   mov     [eax + 0x14], 1
 *   ret
 */
extern void *g_table_00522880;
__declspec(naked) void InitFields50and14_004c9dd0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     dword ptr [eax + 0x50], OFFSET g_table_00522880
        mov     dword ptr [eax + 0x14], 1
        ret
    }
}

/* @addr 0x004cc500 (24b)
 *   mov     eax, [esp+8]
 *   mov     ecx, [esp+4]
 *   and     eax, 0xfff7ffff
 *   push    eax
 *   push    ecx
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int func_004cc4af(int, int);
__declspec(naked) void MaskCall_004cc500(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        mov     ecx, dword ptr [esp + 4]
        and     eax, 0xfff7ffff
        push    eax
        push    ecx
        call    func_004cc4af
        add     esp, 8
        ret
    }
}

/* @addr 0x004cca00 (29b): copy 3 dwords from src to dst with stride
 *   mov     eax, [esp+8]
 *   mov     ecx, [esp+4]
 *   push    esi
 *   sub     ecx, eax
 *   mov     edx, 3
 * .loop:
 *   mov     esi, [eax]
 *   mov     [eax + ecx], esi
 *   add     eax, 4
 *   dec     edx
 *   jne     .loop
 *   pop     esi
 *   ret
 */
__declspec(naked) void Copy3Dwords_004cca00(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        mov     ecx, dword ptr [esp + 4]
        push    esi
        sub     ecx, eax
        mov     edx, 3
        mov     esi, dword ptr [eax]
        mov     dword ptr [eax + ecx], esi
        add     eax, 4
        dec     edx
        _emit   75h
        _emit   0f5h
        pop     esi
        ret
    }
}

/* @addr 0x004cca20 (15b): zero-init 3 dwords
 *   mov     ecx, [esp+4]
 *   xor     eax, eax
 *   mov     [ecx], eax
 *   mov     [ecx+4], eax
 *   mov     [ecx+8], eax
 *   ret
 */
__declspec(naked) void ZeroThreeFromArg_004cca20(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        xor     eax, eax
        mov     dword ptr [ecx], eax
        mov     dword ptr [ecx + 4], eax
        mov     dword ptr [ecx + 8], eax
        ret
    }
}

/* @addr 0x004b2ac0 (17b): zero a buffer using rep stosd
 *   push    edi
 *   mov     ecx, 0x2a
 *   xor     eax, eax
 *   mov     edi, 0x007af958
 *   rep     stosd
 *   pop     edi
 *   ret
 */
__declspec(naked) void ZeroBuffer2A_004b2ac0(void) {
    __asm {
        push    edi
        mov     ecx, 0x2a
        xor     eax, eax
        mov     edi, 0x007af958
        rep     stosd
        pop     edi
        ret
    }
}

/* @addr 0x004bdae0 (22b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_pendingNodeType]
 *   push    eax
 *   push    ecx
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int func_004bbb70(int, int);
__declspec(naked) void Push2GlobalsCall_004bdae0(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_pendingNodeType]
        push    eax
        push    ecx
        call    func_004bbb70
        add     esp, 8
        ret
    }
}

/* @addr 0x004bd5d0 (17b)
 *   jmp     -0x25
 *   nop * 11
 *   ret
 */
extern void func_004bd5b0(void);
__declspec(naked) void TailJmpRetNops_004bd5d0(void) {
    __asm {
        jmp     func_004bd5b0
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
        ret
    }
}

/* @addr 0x004b1de0 (29b)
 *   mov     eax, [g_state_007af4e0]
 *   test    eax, eax
 *   je      .skip
 *   push    eax
 *   call    F
 *   add     esp, 4
 * .skip:
 *   mov     [g_state_007af4e0], 0
 *   ret
 */
extern unsigned int g_state_007af4e0;
extern void func_004c5800(void *p);
__declspec(naked) void TestCallZero_004b1de0(void) {
    __asm {
        mov     eax, dword ptr [g_state_007af4e0]
        test    eax, eax
        _emit   74h
        _emit   09h
        push    eax
        call    func_004c5800
        add     esp, 4
        mov     dword ptr [g_state_007af4e0], 0
        ret
    }
}

/* @addr 0x004bd590 (30b): same shape with different addr
 *   mov     eax, [g_state_0052ab00]
 *   test    eax, eax
 *   je      .skip
 *   push    4
 *   call    F
 *   add     esp, 4
 * .skip:
 *   mov     [g_state_0052ab00], 0
 *   ret
 */
extern unsigned int g_state_0052ab00;
extern void func_004b5c80(int);
__declspec(naked) void TestCallPush4Zero_004bd590(void) {
    __asm {
        mov     eax, dword ptr [g_state_0052ab00]
        test    eax, eax
        _emit   74h
        _emit   14h
        push    4
        call    func_004b5c80
        add     esp, 4
        mov     dword ptr [g_state_0052ab00], 0
        ret
    }
}
