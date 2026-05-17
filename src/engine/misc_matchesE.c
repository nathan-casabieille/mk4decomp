/**
 * Fourteenth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004049d0 (38b)
 *   mov     eax, [esp+4]
 *   push    esi
 *   mov     esi, [g_walkCallback]
 *   mov     [g_walkCallback], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], esi
 * .ret:
 *   pop     esi
 *   ret
 */
extern void TripleCallCountdown_00428080(void);
void SaveCallRestore_004049d0(unsigned int arg) {
    void (*saved)(void) = g_walkCallback;
    g_walkCallback = (void (*)(void))arg;
    TripleCallCountdown_00428080();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = saved;
}

/* @addr 0x00404e20 (41b): zero a struct of various sizes
 *   xor     eax, eax
 *   mov     [0x00ab4e50], eax
 *   mov     [0x00ab4e54], eax
 *   mov     [0x00ab4e58], eax
 *   mov     eax, 0x8000
 *   mov     [0x00ab4e44], ax
 *   mov     [0x00ab4e48], ax
 *   mov     [0x00ab4e4c], ax
 *   ret
 */
extern unsigned int g_struct_00ab4e44;
extern unsigned int g_struct_00ab4e48;
extern unsigned int g_struct_00ab4e4c;
extern unsigned int g_struct_00ab4e50;
extern unsigned int g_struct_00ab4e54;
extern unsigned int g_struct_00ab4e58;
__declspec(naked) void Init6Struct_00404e20(void) {
    __asm {
        xor     eax, eax
        mov     dword ptr [g_struct_00ab4e50], eax
        mov     dword ptr [g_struct_00ab4e54], eax
        mov     dword ptr [g_struct_00ab4e58], eax
        mov     eax, 0x00008000
        mov     word ptr [g_struct_00ab4e44], ax
        mov     word ptr [g_struct_00ab4e48], ax
        mov     word ptr [g_struct_00ab4e4c], ax
        ret
    }
}

/* @addr 0x004143c0 (37b)
 *   push    0x8f
 *   push    0x004146d0
 *   call    F
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_baseSel_00542060]
 *   add     esp, 8
 *   mov     [ecx*4 + 0x34], eax
 *   ret
 */
extern int func_0049cb38(int, void *);
extern void *g_data_004146d0;
void PushCallScaledStore_004143c0(void) {
    func_0049cb38((int)&g_data_004146d0, 0x8f);
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x34) = g_baseSel_00542060;
}

/* @addr 0x00414fe0 (40b)
 *   mov     [g_walkCallback], 0xb1
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], 0xb2
 *   jmp     T
 *   ret
 */
extern void func_0049cc28(void);
extern void func_00414e3c(void);
void SetCallSetJmp_00414fe0(void) {
    g_walkCallback = (void (*)(void))0xb1;
    func_0049cc28();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_walkCallback = (void (*)(void))0xb2;
    func_00414e3c();
}

/* @addr 0x0041f840 (38b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0xd8]
 *   test    ecx, ecx
 *   je      .skip
 *   mov     [eax*4 + 0xd8], -1
 *   mov     [g_framePauseFlag], 1
 * .skip:
 *   ret
 */
void ScaledNeg1SetPause_0041f840(void) {
    unsigned int base = g_baseSel_00542060;
    unsigned int *slot = (unsigned int *)(base * 4 + 0xd8);
    if (*slot != 0) {
        *slot = 0xffffffff;
        g_framePauseFlag = 1;
    }
}

/* @addr 0x00421d20 (37b)
 *   mov     eax, 0x28f
 *   mov     [g_X1], eax
 *   mov     [g_X2], eax
 *   mov     eax, [g_loaded_004f3608]
 *   dec     eax
 *   mov     [g_walkCallback], eax
 *   mov     [g_X3], eax
 *   mov     [g_X4], eax
 *   ret
 */
extern unsigned int g_dst_0053a6dc;
extern unsigned int g_dst_00537f2c;
extern unsigned int g_dst_0053a6e0;
extern unsigned int g_dst_00537ea4;
extern unsigned int g_loaded_004f3608;
void Init28fDecLoad_00421d20(void) {
    unsigned int v;
    g_dst_0053a6dc = 0x028f;
    g_dst_00537f2c = 0x028f;
    v = g_loaded_004f3608 - 1;
    g_walkCallback = (void(*)(void))v;
    g_dst_0053a6e0 = v;
    g_dst_00537ea4 = v;
}

/* @addr 0x00425360 (31b)
 *   mov     eax, [g_scaledInit_00542044]
 *   shl     eax, 2
 *   mov     ecx, [eax]
 *   mov     edx, [eax + 4]
 *   neg     ecx
 *   mov     [eax], ecx
 *   mov     ecx, [eax + 8]
 *   neg     edx
 *   neg     ecx
 *   mov     [eax + 4], edx
 *   mov     [eax + 8], ecx
 *   ret
 */
__declspec(naked) void NegateThree_00425360(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        shl     eax, 2
        mov     ecx, dword ptr [eax]
        mov     edx, dword ptr [eax + 4]
        neg     ecx
        mov     dword ptr [eax], ecx
        mov     ecx, dword ptr [eax + 8]
        neg     edx
        neg     ecx
        mov     dword ptr [eax + 4], edx
        mov     dword ptr [eax + 8], ecx
        ret
    }
}

/* @addr 0x00424b70 (42b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, 0x10000
 *   shl     eax, 2
 *   mov     [eax], ecx
 *   mov     [eax + 0x10], ecx
 *   mov     [eax + 0x20], ecx
 *   xor     ecx, ecx
 *   mov     [eax + 4], ecx
 *   mov     [eax + 8], ecx
 *   mov     [eax + 0x0c], ecx
 *   mov     [eax + 0x14], ecx
 *   mov     [eax + 0x18], ecx
 *   mov     [eax + 0x1c], ecx
 *   ret
 */
__declspec(naked) void IdentityMatrix_00424b70(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, 0x00010000
        shl     eax, 2
        mov     dword ptr [eax], ecx
        mov     dword ptr [eax + 0x10], ecx
        mov     dword ptr [eax + 0x20], ecx
        xor     ecx, ecx
        mov     dword ptr [eax + 4], ecx
        mov     dword ptr [eax + 8], ecx
        mov     dword ptr [eax + 0x0c], ecx
        mov     dword ptr [eax + 0x14], ecx
        mov     dword ptr [eax + 0x18], ecx
        mov     dword ptr [eax + 0x1c], ecx
        ret
    }
}

/* @addr 0x004238b0 (38b)
 *   mov     cl, byte ptr [g_byte_00542040]
 *   xor     eax, eax
 *   cmp     cl, al
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   mov     [0x0052ab40], eax
 *   mov     byte ptr [g_byte_00542040], al
 *   mov     [g_state_0053a7d8], eax
 *   mov     [g_state_0053a748], eax
 *   ret
 */
extern unsigned char g_byte_00542040;
extern unsigned int g_state_0052ab40;
extern unsigned int g_state_0053a7d8;
extern unsigned int g_state_0053a748;
__declspec(naked) void TestCmpZeroFour_004238b0(void) {
    __asm {
        mov     cl, byte ptr [g_byte_00542040]
        xor     eax, eax
        cmp     cl, al
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        mov     dword ptr [g_state_0052ab40], eax
        mov     byte ptr [g_byte_00542040], al
        mov     dword ptr [g_state_0053a7d8], eax
        mov     dword ptr [g_state_0053a748], eax
        ret
    }
}

/* @addr 0x0042ae10 (36b)
 *   mov     eax, 0x00020000
 *   mov     [0x004d5308], eax
 *   mov     [0x004d530c], eax
 *   mov     eax, 0x00010000
 *   mov     [0x004d5300], eax
 *   mov     [g_walkCallback], eax
 *   mov     [0x004d5304], eax
 *   ret
 */
extern unsigned int g_state_004d5308;
extern unsigned int g_state_004d530c;
extern unsigned int g_state_004d5300;
extern unsigned int g_state_004d5304;
void Init4Globals_0042ae10(void) {
    g_state_004d5308 = 0x00020000;
    g_state_004d530c = 0x00020000;
    g_state_004d5300 = 0x00010000;
    g_walkCallback   = (void(*)(void))0x00010000;
    g_state_004d5304 = 0x00010000;
}
