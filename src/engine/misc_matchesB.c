/**
 * Eleventh batch of one-off matches.
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0042f840 (12b)
 *   mov     byte ptr [g_byte_00538148], 0
 *   jmp     T
 */
extern unsigned char g_byte_00538148;
extern void func_0041a608(void);
__declspec(naked) void StoreByteJmp_0042f840(void) {
    __asm {
        mov     byte ptr [g_byte_00538148], 0
        jmp     func_0041a608
    }
}

/* @addr 0x0045e1d0 (11b)
 *   inc     dword ptr [g_scaledInit_00542044]
 *   jmp     +5
 */
extern void func_0045e1e0(void);
__declspec(naked) void IncJmp_0045e1d0(void) {
    __asm {
        inc     dword ptr [g_scaledInit_00542044]
        jmp     func_0045e1e0
    }
}

/* @addr 0x0048a1b0 (11b)
 *   mov     [g_state], 0
 *   ret
 */
extern unsigned int g_state_00541fa4;
__declspec(naked) void ZeroState_0048a1b0(void) {
    __asm {
        mov     dword ptr [g_state_00541fa4], 0
        ret
    }
}

/* @addr 0x0048bad0 (11b)
 *   push    0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int func_004887ff(int);
__declspec(naked) void PushZeroCallRet_0048bad0(void) {
    __asm {
        push    0
        call    func_004887ff
        add     esp, 4
        ret
    }
}

/* @addr 0x004ac1f0 (11b)
 *   mov     eax, [g_walkCallback]
 *   mov     [g_target_0053a6fc], eax
 *   ret
 */
extern unsigned int g_target_0053a6fc;
__declspec(naked) void CopyGlobal_004ac1f0(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_target_0053a6fc], eax
        ret
    }
}

/* @addr 0x004b21b0 (8b)
 *   mov     byte ptr [g_byte_007af508], 0
 *   ret
 */
extern unsigned char g_byte_007af508;
__declspec(naked) void ZeroByte_004b21b0(void) {
    __asm {
        mov     byte ptr [g_byte_007af508], 0
        ret
    }
}

/* @addr 0x004b5840 (11b)
 *   mov     [g_state_004f4e98], 1
 *   ret
 */
extern unsigned int g_state_004f4e98;
__declspec(naked) void SetState1_004b5840(void) {
    __asm {
        mov     dword ptr [g_state_004f4e98], 1
        ret
    }
}

/* @addr 0x004b5ae0 (29b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [esp+8]
 *   and     ecx, 0x3f
 *   mov     edx, [eax-0xc]
 *   shl     ecx, 0x18
 *   and     edx, 0xc0ffffff
 *   or      ecx, edx
 *   mov     [eax-0xc], ecx
 *   ret
 */
__declspec(naked) void SetHi6_004b5ae0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [esp + 8]
        and     ecx, 0x3f
        mov     edx, dword ptr [eax - 0x0c]
        shl     ecx, 0x18
        and     edx, 0xc0ffffff
        or      ecx, edx
        mov     dword ptr [eax - 0x0c], ecx
        ret
    }
}

/* @addr 0x004b5b00 (12b)
 *   mov     ecx, [esp+4]
 *   mov     eax, [esp+8]
 *   mov     [ecx-8], eax
 *   ret
 */
__declspec(naked) void StoreAtMinus8_004b5b00(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        mov     eax, dword ptr [esp + 8]
        mov     dword ptr [ecx - 8], eax
        ret
    }
}

/* @addr 0x004c4360 (13b)
 *   call    F
 *   mov     byte ptr [g_byte_00f9efd4], 1
 *   ret
 */
extern void func_004c42f0(void);
extern unsigned char g_byte_00f9efd4;
__declspec(naked) void CallSetByte1_004c4360(void) {
    __asm {
        call    func_004c42f0
        mov     byte ptr [g_byte_00f9efd4], 1
        ret
    }
}

/* @addr 0x004c4450 (24b)
 *   mov     eax, 0x00f8fade
 * .loop:
 *   mov     cl, [eax]
 *   add     eax, 0x1c
 *   and     cl, 0xfb
 *   cmp     eax, 0x00f8eb7e
 *   jl      .loop
 *   mov     [eax-0x1c], cl
 *   ret
 *
 * Wait, the cmp+jl should be at the end. Let me re-decode:
 * b8 de fa f8 00     mov eax, 0x00f8fade
 * 8a 08              mov cl, [eax]
 * 83 c0 1c           add eax, 0x1c
 * 80 e1 fb           and cl, 0xfb
 * 3d 7e eb f9 00     cmp eax, 0x00f9eb7e
 * 88 48 e4           mov [eax-0x1c], cl
 * 7c ee              jl .loop
 * c3                 ret
 */
__declspec(naked) void Loop1cBitMask_004c4450(void) {
    __asm {
        mov     eax, 0x00f8fade
        mov     cl, byte ptr [eax]
        add     eax, 0x1c
        and     cl, 0xfb
        cmp     eax, 0x00f9eb7e
        mov     byte ptr [eax - 0x1c], cl
        _emit   7ch
        _emit   0eeh
        ret
    }
}

/* @addr 0x004c6500 (13b)
 *   call    F
 *   mov     ecx, [esp+4]
 *   mov     [eax+0x14], ecx
 *   ret
 */
extern void *func_004c9df0(void);
__declspec(naked) void CallStoreField14_004c6500(void) {
    __asm {
        call    func_004c9df0
        mov     ecx, dword ptr [esp + 4]
        mov     dword ptr [eax + 0x14], ecx
        ret
    }
}

/* @addr 0x004c8ba0 (9b)
 *   call    F
 *   add     eax, 8
 *   ret
 */
extern int *func_004c9df0_b(void);
__declspec(naked) void CallAdd8_004c8ba0(void) {
    __asm {
        call    func_004c9df0_b
        add     eax, 8
        ret
    }
}

/* @addr 0x004c8bb0 (9b)
 *   call    F
 *   add     eax, 0xc
 *   ret
 */
__declspec(naked) void CallAddC_004c8bb0(void) {
    __asm {
        call    func_004c9df0_b
        add     eax, 0x0c
        ret
    }
}

/* @addr 0x004c9a20 (11b)
 *   push    -3
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int func_004c951e(int);
__declspec(naked) void PushNeg3CallRet_004c9a20(void) {
    __asm {
        push    -3
        call    func_004c951e
        add     esp, 4
        ret
    }
}

/* @addr 0x004cca30 (29b): linear search a 4-stride array
 *   mov     ecx, [esp+4]
 *   xor     eax, eax
 * .loop:
 *   cmp     dword ptr [ecx], 0
 *   jne     .found
 *   inc     eax
 *   add     ecx, 4
 *   cmp     eax, 3
 *   jl      .loop
 *   mov     eax, 1
 *   ret
 * .found:
 *   xor     eax, eax
 *   ret
 */
__declspec(naked) void LinearSearchArray_004cca30(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        xor     eax, eax
        cmp     dword ptr [ecx], 0
        _emit   75h
        _emit   0fh
        inc     eax
        add     ecx, 4
        cmp     eax, 3
        _emit   7ch
        _emit   0f2h
        mov     eax, 1
        ret
        xor     eax, eax
        ret
    }
}

/* @addr 0x004cdff0 (21b)
 *   push    ebp
 *   mov     ebp, esp
 *   sub     esp, 8
 *   fld     qword ptr [ebp+8]
 *   frndint
 *   fstp    qword ptr [ebp-8]
 *   fld     qword ptr [ebp-8]
 *   mov     esp, ebp
 *   pop     ebp
 *   ret
 */
__declspec(naked) void RoundDouble_004cdff0(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        sub     esp, 8
        fld     qword ptr [ebp + 8]
        frndint
        fstp    qword ptr [ebp - 8]
        fld     qword ptr [ebp - 8]
        mov     esp, ebp
        pop     ebp
        ret
    }
}

/* @addr 0x004cf710 (16b)
 *   push    ebp
 *   mov     ebp, esp
 *   push    ecx
 *   wait
 *   fnstcw  word ptr [ebp-2]
 *   movsx   eax, word ptr [ebp-2]
 *   mov     esp, ebp
 *   pop     ebp
 *   ret
 */
__declspec(naked) void GetFpuSw_004cf710(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        push    ecx
        fstsw   word ptr [ebp - 2]
        movsx   eax, word ptr [ebp - 2]
        mov     esp, ebp
        pop     ebp
        ret
    }
}

/* @addr 0x004cf720 (17b)
 *   push    ebp
 *   mov     ebp, esp
 *   push    ecx
 *   fld     qword ptr [ebp+8]
 *   fstp    qword ptr [ebp-2]      ; actually fistp via dbe2 ?
 *   ; Actually 0xdb 0xe2 is fnclex... no wait
 *   ; 0xdb /2 with mod=11 reg=100 rm=010 = ... actually let me just use _emit
 *   movsx   eax, word ptr [ebp-2]
 *   mov     esp, ebp
 *   pop     ebp
 *   ret
 *
 * Bytes: 558bec51dd7dfedbe20fbf45fe8be55dc3
 *   55              push ebp
 *   8b ec           mov ebp, esp
 *   51              push ecx
 *   dd 7d fe        fnstsw [ebp-2]? wait dd /7 mod=01 = fnstsw
 *   actually dd 7d fe = fnstsw word ptr [ebp-2]?
 *   dd is x87 group; 7d means /7 with disp8. 7d = mod=01 reg=111 rm=101 (ebp+disp8)
 *   /7 of dd is fnstsw m16 — yes, fnstsw [ebp-2]
 *   db e2           fnclex (if e2)? Actually db is x87, e2 = no /r form...
 *   db e2 = FNCLEX is db e2. Yes.
 *   Wait actually fnclex = db e2, fclex = 9b db e2. So this is fnclex.
 *   Hmm but the earlier instruction was fld qword and now fnclex? Let me re-decode.
 *
 * Actually re-read:
 *   55 8b ec 51 dd 7d fe db e2 0f bf 45 fe 8b e5 5d c3
 * - 55       push ebp
 * - 8b ec    mov ebp, esp
 * - 51       push ecx
 * - dd 7d fe fstp qword ptr [ebp-2]  ?? no, dd /7 = fstp — but fstp needs specific size
 *   Actually dd = x87, /7 in modr/m means group; let me look up:
 *   dd /0 = fld m64
 *   dd /1 = fisttp m64
 *   dd /2 = fst m64
 *   dd /3 = fstp m64
 *   dd /7 = fnstsw m16
 *   So dd 7d fe = fnstsw [ebp-2]
 * - db e2    fnclex (if e2 means /4 with no operand) actually fnclex = db e2 yes
 * - 0f bf 45 fe   movsx eax, word ptr [ebp-2]
 * - 8b e5    mov esp, ebp
 * - 5d       pop ebp
 * - c3       ret
 *
 * So this is "get fpu status word + clear exceptions, return as int".
 * However, that's only 17 bytes, matching.
 */
__declspec(naked) void GetFpuSwClex_004cf720(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        push    ecx
        fnstsw  word ptr [ebp - 2]
        fnclex
        movsx   eax, word ptr [ebp - 2]
        mov     esp, ebp
        pop     ebp
        ret
    }
}
