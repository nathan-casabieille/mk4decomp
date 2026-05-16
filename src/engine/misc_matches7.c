/**
 * Seventh batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404af0 (18b)
 *   mov     eax, [esp+4]
 *   mov     ecx, 0x10
 *   imul    dword ptr [esp+8]
 *   jmp     +0x0c0b5e
 */
extern void func_0040c656(void);
__declspec(naked) void Mul10Tail_00404af0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, 0x10
        imul    dword ptr [esp + 8]
        jmp     func_0040c656
    }
}

/* @addr 0x0041f550 (18b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, [esp+4]
 *   mov     [ecx*4 + 0xe0], eax
 *   ret
 */
void ScaledStoreE0_0041f550(int x) {
    *(int *)(g_baseSel_00542060 * 4 + 0xe0) = x;
}

/* @addr 0x0041f810 (28b)
 *   mov     eax, [g_pendingNodeType]
 *   shl     eax, 2
 *   mov     ecx, [eax + 0xd8]
 *   test    ecx, ecx
 *   je      .ret
 *   push    eax
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern void func_0041f700(unsigned int);
void LoadShlDerefCallSkip_0041f810(void) {
    unsigned int p = g_pendingNodeType * 4;
    if (*(unsigned int*)(p + 0xd8)) {
        func_0041f700(p);
    }
}

/* @addr 0x004a1ce0 (14b)
 *   movsx   eax, byte ptr [0x004d50c0]
 *   and     eax, 4
 *   shr     eax, 2
 *   ret
 */
extern char g_byte_004d50c0;
__declspec(naked) void MovsxAnd4Shr_004a1ce0(void) {
    __asm {
        movsx   eax, byte ptr [g_byte_004d50c0]
        and     eax, 4
        shr     eax, 2
        ret
    }
}

/* @addr 0x004a1cf0 (14b)
 *   movsx   eax, byte ptr [0x004d50c0]
 *   and     eax, 0x20
 *   shr     eax, 5
 *   ret
 */
__declspec(naked) void MovsxAnd20Shr5_004a1cf0(void) {
    __asm {
        movsx   eax, byte ptr [g_byte_004d50c0]
        and     eax, 0x20
        shr     eax, 5
        ret
    }
}

/* @addr 0x00404af0 already covered above? Check addr - yes the first entry */

/* @addr 0x004a5660 (19b): rep stosd zero-init from arg
 *   mov     ecx, [esp+8]
 *   test    ecx, ecx
 *   jle     .ret
 *   push    edi
 *   mov     edi, [esp+8]
 *   xor     eax, eax
 *   rep     stosd
 *   pop     edi
 * .ret:
 *   ret
 */
__declspec(naked) void ZeroNDwords_004a5660(void) {
    __asm {
        mov     ecx, dword ptr [esp + 8]
        test    ecx, ecx
        _emit   7eh
        _emit   0ah
        push    edi
        mov     edi, dword ptr [esp + 8]
        xor     eax, eax
        rep     stosd
        pop     edi
        ret
    }
}

/* @addr 0x0049cc10 (24b)
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, [g_walkCallback]
 *   and     ecx, eax
 *   mov     [g_walkCallback], ecx
 *   jmp     T
 */
extern void func_0049fa30(void);
__declspec(naked) void AndStoreJmp_0049cc10(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_walkCallback]
        and     ecx, eax
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_0049fa30
    }
}

/* @addr 0x0049d080 (25b)
 *   mov     eax, [g_walkCallback]
 *   cmp     eax, 2
 *   jle     .keep
 *   cdq
 *   sub     eax, edx
 *   sar     eax, 1
 *   mov     [g_walkCallback], eax
 *   jmp     T
 */
extern void func_0049cf60(void);
__declspec(naked) void CmpDivJmp_0049d080(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 2
        _emit   7eh
        _emit   0ah
        cdq
        sub     eax, edx
        sar     eax, 1
        mov     dword ptr [g_walkCallback], eax
        jmp     func_0049cf60
    }
}

/* @addr 0x0049d430 (30b)
 *   mov     eax, [g_scaledInit_00542044]
 *   xor     ecx, ecx
 *   cmp     eax, ecx
 *   mov     [g_walkCallback], eax
 *   je      .ret
 *   mov     [eax*4 + 8], ecx
 *   mov     [g_scaledInit_00542044], ecx
 * .ret:
 *   ret
 */
__declspec(naked) void ScaledZeroIfNonzero_0049d430(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        xor     ecx, ecx
        cmp     eax, ecx
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   0dh
        mov     dword ptr [eax*4 + 8], ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        ret
    }
}

/* @addr 0x0049fa00 (29b)
 *   mov     eax, [g_state_005380e4]
 *   cmp     eax, 8
 *   mov     [g_walkCallback], eax
 *   ja      .reset
 *   add     eax, 5
 *   mov     [g_walkCallback], eax
 *   mov     [g_state_005380e4], eax
 *   ret
 */
extern unsigned int g_state_005380e4;
__declspec(naked) void StateAdd5Capped_0049fa00(void) {
    __asm {
        mov     eax, dword ptr [g_state_005380e4]
        cmp     eax, 8
        mov     dword ptr [g_walkCallback], eax
        _emit   77h
        _emit   0dh
        add     eax, 5
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_005380e4], eax
        ret
    }
}

/* @addr 0x004a4180 (19b)
 *   cmp     byte ptr [0x00543590], 1
 *   jne     +5
 *   jmp     T1
 *   jmp     T2
 */
extern unsigned char g_byte_00543590;
extern void func_004a4159(void);
extern void func_004a4136(void);
__declspec(naked) void CmpByteJmp_004a4180(void) {
    __asm {
        cmp     byte ptr [g_byte_00543590], 1
        _emit   75h
        _emit   05h
        jmp     func_004a4159
        jmp     func_004a4136
    }
}

/* @addr 0x004a42b0 (25b)
 *   mov     eax, [g_X]
 *   test    eax, eax
 *   je      .ret
 *   mov     [g_X], 0
 *   jmp     T
 *   ret
 */
extern unsigned int g_state_00543824;
extern void func_0048a1ad(void);
__declspec(naked) void TestZeroJmp_004a42b0(void) {
    __asm {
        mov     eax, dword ptr [g_state_00543824]
        test    eax, eax
        _emit   74h
        _emit   0fh
        mov     dword ptr [g_state_00543824], 0
        jmp     func_0048a1ad
        ret
    }
}

/* @addr 0x0049c6d0 (27b)
 *   mov     eax, [esp+4]
 *   mov     [g_eventQueueChild], 1
 *   sar     eax, 2
 *   mov     [g_eventQueueEnd], eax
 *   jmp     +0x25
 */
extern void func_0049c6fa(void);
__declspec(naked) void ArgSar_Set1_Jmp_0049c6d0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     dword ptr [g_eventQueueChild], 1
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        jmp     func_0049c6fa
    }
}

/* @addr 0x0049c6f0 (27b)
 *   mov     eax, [esp+4]
 *   mov     [g_eventQueueChild], 0
 *   sar     eax, 2
 *   mov     [g_eventQueueEnd], eax
 *   jmp     +5
 */
extern void func_0049c6fa_b(void);
__declspec(naked) void ArgSar_Set0_Jmp_0049c6f0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     dword ptr [g_eventQueueChild], 0
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        jmp     func_0049c6fa_b
    }
}
