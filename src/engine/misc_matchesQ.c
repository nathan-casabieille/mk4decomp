/**
 * Twenty-sixth batch of one-off matches.
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ab350 (40b)
 *   mov     eax, [g_eventQueueWorkType]
 *   test    eax, eax
 *   jle     +0x19
 *   fild    dword ptr [g_eventQueueWorkType]
 *   fmul    qword ptr [0x004d27b0]
 *   fsqrt
 *   fmul    qword ptr [0x004d27b8]
 *   call    F
 *   mov     [g_walkCallback], eax
 *   ret
 */
extern u32 g_eventQueueWorkType;
extern double g_const_004d27b0;
extern double g_const_004d27b8;
extern int func_004cb7b0(void);
__declspec(naked) void FpuSqrtMul_004ab350(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueWorkType]
        test    eax, eax
        _emit   7eh
        _emit   19h
        fild    dword ptr [g_eventQueueWorkType]
        fmul    qword ptr [g_const_004d27b0]
        fsqrt
        fmul    qword ptr [g_const_004d27b8]
        call    func_004cb7b0
        mov     dword ptr [g_walkCallback], eax
        ret
    }
}

/* @addr 0x004aef00 (43b): COM-style call with capture
 *   mov     eax, [g_iface_0058c7ac]
 *   test    eax, eax
 *   je      +0x14
 *   mov     ecx, [eax]
 *   push    0x004d287c
 *   push    0x004d2870
 *   push    eax
 *   call    [ecx]
 *   mov     [g_state_0058c7dc], eax
 *   mov     ecx, [g_iface_0058c7bc]
 *   xor     eax, eax
 *   test    ecx, ecx
 *   setne   al
 *   ret
 */
extern void *g_iface_0058c7ac;
extern unsigned int g_state_0058c7dc;
extern void *g_iface_0058c7bc;
extern void *g_data_004d2870;
extern void *g_data_004d287c;
__declspec(naked) void ComCallSetne_004aef00(void) {
    __asm {
        mov     eax, dword ptr [g_iface_0058c7ac]
        test    eax, eax
        _emit   74h
        _emit   14h
        mov     ecx, dword ptr [eax]
        push    OFFSET g_data_004d287c
        push    OFFSET g_data_004d2870
        push    eax
        call    dword ptr [ecx]
        mov     dword ptr [g_state_0058c7dc], eax
        mov     ecx, dword ptr [g_iface_0058c7bc]
        xor     eax, eax
        test    ecx, ecx
        setne   al
        ret
    }
}

/* @addr 0x004be760 (46b)
 *   mov     ax, word ptr [esp+4]
 *   cmp     ax, 0x64
 *   jge     +0x20
 *   movsx   edx, ax
 *   xor     ecx, ecx
 *   mov     eax, 0x004f7d40
 * .loop:
 *   cmp     [eax], edx
 *   je      .found
 *   add     eax, 4
 *   inc     ecx
 *   cmp     eax, 0x004f7d80
 *   jl      .loop
 *   xor     eax, eax
 *   ret
 * .found:
 *   lea     eax, [ecx + 2]
 *   ret
 *   xor     eax, eax
 *   ret
 */
extern int g_table_004f7d40[16];
__declspec(naked) void TableSearch_004be760(void) {
    __asm {
        mov     ax, word ptr [esp + 4]
        cmp     ax, 0x64
        _emit   7dh
        _emit   20h
        movsx   edx, ax
        xor     ecx, ecx
        mov     eax, 0x004f7d40
        cmp     edx, dword ptr [eax]
        _emit   74h
        _emit   0eh
        add     eax, 4
        inc     ecx
        cmp     eax, 0x004f7d80
        _emit   7ch
        _emit   0f1h
        xor     eax, eax
        ret
        lea     eax, [ecx + 2]
        ret
        xor     eax, eax
        ret
    }
}

/* @addr 0x004c4210 (37b)
 *   push    esi
 *   push    edi
 *   xor     esi, esi
 *   mov     edi, 0x00f8fade
 * .loop:
 *   test    byte ptr [edi], 4
 *   jne     .skip
 *   push    esi
 *   call    F
 *   add     esp, 4
 * .skip:
 *   inc     esi
 *   add     edi, 0x1c
 *   cmp     si, 0x0898
 *   jl      .loop
 *   pop     edi
 *   pop     esi
 *   ret
 */
extern int func_004c3700(int);
__declspec(naked) void IterateCallSkip_004c4210(void) {
    __asm {
        push    esi
        push    edi
        xor     esi, esi
        mov     edi, 0x00f8fade
        test    byte ptr [edi], 4
        _emit   75h
        _emit   09h
        push    esi
        call    func_004c3700
        add     esp, 4
        inc     esi
        add     edi, 0x1c
        cmp     si, 0x0898
        _emit   7ch
        _emit   0e7h
        pop     edi
        pop     esi
        ret
    }
}

/* @addr 0x004c45a0 (37b)
 *   push    esi
 *   mov     esi, [iat]
 *   push    edi
 *   push    0x2d
 *   call    esi
 *   push    7
 *   mov     edi, eax
 *   call    esi
 *   add     edi, eax
 *   shl     edi, 1
 *   mov     [0x00f9f7b8], edi
 *   pop     edi
 *   pop     esi
 *   ret
 *   nop
 *   jmp     +0x0b
 */
extern void *g_iat_004d21b0;
extern unsigned int g_state_00f9f7b8;
extern void func_004c45c1(void);
__declspec(naked) void CallTwoSumShl_004c45a0(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [g_iat_004d21b0]
        push    edi
        push    0x2d
        call    esi
        push    7
        mov     edi, eax
        call    esi
        add     edi, eax
        shl     edi, 1
        mov     dword ptr [g_state_00f9f7b8], edi
        pop     edi
        pop     esi
        ret
        nop
        jmp     func_004c45c1
    }
}

/* @addr 0x004c45d0 (35b): similar pattern with different params
 *   push    esi
 *   mov     esi, [iat]
 *   push    edi
 *   push    0x2e
 *   call    esi
 *   push    8
 *   mov     edi, eax
 *   call    esi
 *   push    4
 *   add     edi, eax
 *   call    esi
 *   lea     eax, [edi + eax*2]
 *   pop     edi
 *   mov     [0x00f9f7bc], eax
 *   pop     esi
 *   ret
 */
extern unsigned int g_state_00f9f7bc;
__declspec(naked) void CallThreeSumLea_004c45d0(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [g_iat_004d21b0]
        push    edi
        push    0x2e
        call    esi
        push    8
        mov     edi, eax
        call    esi
        push    4
        add     edi, eax
        call    esi
        lea     eax, [eax + edi*2]
        pop     edi
        mov     dword ptr [g_state_00f9f7bc], eax
        pop     esi
        ret
    }
}

/* @addr 0x004c5660 (48b)
 *   cmp     cl, 0x40
 *   jae     +0x16
 *   cmp     cl, 0x20
 *   jae     +6
 *   shrd    eax, edx, cl
 *   shr     edx, cl
 *   ret
 *   mov     eax, edx
 *   sar     edx, 0x1f
 *   and     cl, 0x1f
 *   shr     eax, cl
 *   ret
 *   sar     edx, 0x1f
 *   mov     eax, edx
 *   ret
 *   nop * 12  (alignment)
 */
__declspec(naked) void Sar64_004c5660(void) {
    __asm {
        cmp     cl, 0x40
        _emit   73h
        _emit   16h
        cmp     cl, 0x20
        _emit   73h
        _emit   06h
        shrd    eax, edx, cl
        sar     edx, cl
        ret
        mov     eax, edx
        sar     edx, 0x1f
        and     cl, 0x1f
        sar     eax, cl
        ret
        sar     edx, 0x1f
        mov     eax, edx
        ret
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
    }
}

/* @addr 0x004c57d0 (48b)
 *   push    ebp
 *   mov     ebp, esp
 *   add     esp, -12
 *   wait
 *   fnstcw  word ptr [ebp-2]
 *   wait
 *   mov     ax, word ptr [ebp-2]
 *   or      ah, 0x0c
 *   mov     word ptr [ebp-4], ax
 *   fldcw   word ptr [ebp-4]
 *   fistp   qword ptr [ebp-12]
 *   fldcw   word ptr [ebp-2]
 *   mov     eax, [ebp-12]
 *   mov     edx, [ebp-8]
 *   leave
 *   ret
 *   nop * 8 (int 3 padding)
 */
__declspec(naked) void DoubleToInt64_004c57d0(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        add     esp, -12
        fstcw   word ptr [ebp - 2]
        wait
        mov     ax, word ptr [ebp - 2]
        or      ah, 0x0c
        mov     word ptr [ebp - 4], ax
        fldcw   word ptr [ebp - 4]
        fistp   qword ptr [ebp - 12]
        fldcw   word ptr [ebp - 2]
        mov     eax, dword ptr [ebp - 12]
        mov     edx, dword ptr [ebp - 8]
        leave
        ret
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
    }
}
