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
int MinOfThree_004b3d70(void) {
    int a = g_min_007af984;
    int b = g_min_007af988;
    if (b < a) a = b;
    b = g_min_007af98c;
    if (b < a) a = b;
    return a;
}

/* @addr 0x004b3d90 (30b): max-of-three (jle instead of jge) */
int MaxOfThree_004b3d90(void) {
    int a = g_min_007af984;
    int b = g_min_007af988;
    if (b > a) a = b;
    b = g_min_007af98c;
    if (b > a) a = b;
    return a;
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
extern void (__stdcall *g_iat_007b0010)(int);
void Renderer1_PresentFrame(void) {
    if (g_state_007affe4 == 0) {
        return;
    }
    if (g_state_007afff0 != 0) {
        return;
    }
    g_iat_007b0010(1);
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
void Init16BitFields_004bcc50(void) {
    g_word_00ab47fc = 0x1000;
    g_word_00ab47f8 = 0;
    g_word_00ab47fa = 0;
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
extern int Snd3DSourceCleanupFiltered_004c3be0(int, int);
void Loop16Init_004c4370(void) {
    int i;
    for (i = 0; i < 16; i++) {
        Snd3DSourceCleanupFiltered_004c3be0(-1, i);
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
extern int __cdecl func_004c54c2(int, int);
int LoadArgPushCall_004c54b0(int x) {
    return func_004c54c2(x, g_state_00f9f850);
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
extern int __cdecl func_004c5d68(int, int, int);
int Helper_FOpen(int a, int b) {
    return func_004c5d68(a, b, 0x40);
}

/* @addr 0x004c6820 (18b): forwarding wrapper push 0+0+arg+call */
extern int __cdecl func_004c6857(int, int, int);
int PushZ2ArgCall_004c6820(int x) {
    return func_004c6857(x, 0, 0);
}

/* @addr 0x004c6840 (18b): same shape, push 0+1+arg+call */
int _exit_post(int x) {
    return func_004c6857(x, 1, 0);
}

/* @addr 0x004cbad0 (18b): same shape, push 4+0+arg+call */
extern int __cdecl func_004cbae7(int, int, int);
int _isspace_crt(int x) {
    return func_004cbae7(x, 0, 4);
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
int StreamReadDword_004c8380(int **stream) {
    int *p = *stream;
    *stream = p + 1;
    p = *stream;
    return p[-1];
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
u64 StreamReadQword_004c83a0(u32 *stream) {
    u32 newpos = *stream + 8;
    *stream = newpos;
    return *(u64 *)(newpos - 8);
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
void StreamReadWord_004c83c0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [eax]
        add     ecx, 4
        mov     dword ptr [eax], ecx
        mov     eax, ecx
        mov     ax, word ptr [eax - 4]
        }
}

/* @addr 0x004c83e0 (19b)
 *   push    0x00030000
 *   push    0x00010000
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int __cdecl func_004ccdf6(int, int);
void Push3000010000Call_004c83e0(void) {
    func_004ccdf6(0x10000, 0x30000);
}

/* @addr 0x004c9dd0 (19b)
 *   mov     eax, [esp+4]
 *   mov     [eax + 0x50], 0x00522880
 *   mov     [eax + 0x14], 1
 *   ret
 */
extern void *g_table_00522880;
void InitFields50and14_004c9dd0(char *p) {
    *(void **)(p + 0x50) = &g_table_00522880;
    *(int  *)(p + 0x14) = 1;
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
extern int __cdecl func_004cc4af(int, int);
int MaskCall_004cc500(int a, int b) {
    return func_004cc4af(a, b & 0xfff7ffff);
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
void ZeroThreeFromArg_004cca20(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        xor     eax, eax
        mov     dword ptr [ecx], eax
        mov     dword ptr [ecx + 4], eax
        mov     dword ptr [ecx + 8], eax
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
__declspec(naked) void AppInit_Misc3(void) {
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
extern int __cdecl func_004bbb70(unsigned int, unsigned int);
void Push2GlobalsCall_004bdae0(void) {
    func_004bbb70(g_pendingNodeType, g_scaledInit_00542044);
}

/* @addr 0x004bd5d0 (17b)
 *   jmp     -0x25
 *   nop * 11
 *   ret
 */
extern void LoadGeoAsset_Default(void);
__declspec(naked) void TailJmpRetNops_004bd5d0(void) {
    __asm {
        jmp     LoadGeoAsset_Default
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
extern void Helper_FClose(void *p);
void TestCallZero_004b1de0(void) {
    void *v = (void *)g_state_007af4e0;
    if (v != 0) {
        Helper_FClose(v);
    }
    g_state_007af4e0 = 0;
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
void TestCallPush4Zero_004bd590(void) {
    if (g_state_0052ab00 != 0) {
        func_004b5c80(4);
        g_state_0052ab00 = 0;
    }
}
