/**
 * Fifth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004314d0 (29b)
 *   mov     eax, [0x0052ab10]
 *   mov     ecx, 0xfffe8000
 *   mov     [g_fightGroupHead], eax
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x58], ecx
 *   ret
 */
extern unsigned int g_load_0052ab10;
void LoadStoreScaled58_004314d0(void) {
    unsigned int idx = g_load_0052ab10;
    g_fightGroupHead = idx;
    g_walkCallback   = (void(*)(void))0xfffe8000;
    *(unsigned int *)(idx * 4 + 0x58) = 0xfffe8000;
}

/* @addr 0x0042f4d0 (28b)
 *   mov     edx, [g_scaledInit_00542044]
 *   mov     ecx, [g_currentNodeFlags]
 *   mov     [edx*4 + 0x5c], ecx
 *   call    F
 *   pop     edi, esi, ebp
 *   ret
 */
extern void func_0042f539(void);
__declspec(naked) void ScaledStoreCallEpilogue_0042f4d0(void) {
    __asm {
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [edx*4 + 0x5c], ecx
        call    func_0042f539
        pop     edi
        pop     esi
        pop     ebp
        ret
    }
}

/* @addr 0x0041f270 (27b): zero a large memory block
 *   push    edi
 *   mov     ecx, 0x0e80
 *   xor     eax, eax
 *   mov     edi, 0x0053e368
 *   rep     stosd
 *   mov     [0x0052ab3c], 0
 *   pop     edi
 *   ret
 */
extern unsigned int g_extra_0052ab3c;
__declspec(naked) void ZeroLargeBlock_0041f270(void) {
    __asm {
        push    edi
        mov     ecx, 0x0e80
        xor     eax, eax
        mov     edi, 0x0053e368
        rep     stosd
        mov     dword ptr [g_extra_0052ab3c], 0
        pop     edi
        ret
    }
}

/* @addr 0x004578e0 (21b): strlen-style counter
 *   mov     ecx, [esp+4]
 *   xor     eax, eax
 *   cmp     byte ptr [ecx], 0
 *   je      .ret
 * .loop:
 *   mov     dl, [ecx+1]
 *   inc     eax
 *   inc     ecx
 *   test    dl, dl
 *   jne     .loop
 * .ret:
 *   ret
 */
__declspec(naked) void StrLen_004578e0(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        xor     eax, eax
        cmp     byte ptr [ecx], 0
        _emit   74h
        _emit   09h
        mov     dl, byte ptr [ecx + 1]
        inc     eax
        inc     ecx
        test    dl, dl
        _emit   75h
        _emit   0f7h
        ret
    }
}

/* @addr 0x0048cc20 (25b)
 *   mov     [g_walkCallback], 0x71
 *   mov     [g_eventQueueCurrent], -1
 *   jmp     T
 */
extern void func_0048cbef(void);
__declspec(naked) void DualConstJmpNeg1_0048cc20(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x71
        mov     dword ptr [g_eventQueueCurrent], 0xffffffff
        jmp     func_0048cbef
    }
}

/* @addr 0x0048fbd0 (25b)
 *   mov     [g_walkCallback], 0x00010000
 *   mov     [g_eventQueueCurrent], 0x28
 *   jmp     T
 */
extern void func_0048fb2c(void);
__declspec(naked) void DualConstJmpBig_0048fbd0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00010000
        mov     dword ptr [g_eventQueueCurrent], 0x28
        jmp     func_0048fb2c
    }
}

/* @addr 0x00490110 (28b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      al, 4
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   ret
 */
__declspec(naked) void ScaledOr4Store_00490110(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x34]
        or      al, 4
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        ret
    }
}

/* @addr 0x004902d0 (29b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x40]
 *   and     ah, 0xfd
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [ecx*4 + 0x40], eax
 *   ret
 */
__declspec(naked) void ScaledAndAh_004902d0(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x40]
        and     ah, 0xfd
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x40], eax
        ret
    }
}

/* @addr 0x004902f0 (28b): same shape, and al, 0x7f */
__declspec(naked) void ScaledAndAl7f_004902f0(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x40]
        and     al, 0x7f
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x40], eax
        ret
    }
}

/* @addr 0x00490310 (28b): same shape, and al, 0xf7 */
__declspec(naked) void ScaledAndAlf7_00490310(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x40]
        and     al, 0xf7
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x40], eax
        ret
    }
}

/* @addr 0x00490330 (28b): same shape, and al, 0xdf */
__declspec(naked) void ScaledAndAldf_00490330(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x40]
        and     al, 0xdf
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x40], eax
        ret
    }
}

/* @addr 0x00490350 (28b): same shape, and al, 0xbf */
__declspec(naked) void ScaledAndAlbf_00490350(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x40]
        and     al, 0xbf
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x40], eax
        ret
    }
}

/* @addr 0x00490370 (28b): same shape, and al, 0xfb */
__declspec(naked) void ScaledAndAlfb_00490370(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x40]
        and     al, 0xfb
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x40], eax
        ret
    }
}

/* @addr 0x00490390 (28b): same shape, and al, 0xfe */
__declspec(naked) void ScaledAndAlfe_00490390(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x40]
        and     al, 0xfe
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [ecx*4 + 0x40], eax
        ret
    }
}

/* @addr 0x0045e0b0 (30b)
 *   mov     eax, [g_xformScratch2088]
 *   mov     [g_acc_00542078], 4
 *   test    eax, eax
 *   je      ret
 *   mov     [g_acc_00542078], 3
 *   ret
 */
extern unsigned int g_acc_00542078;
__declspec(naked) void ConditionalAcc4or3_0045e0b0(void) {
    __asm {
        mov     eax, dword ptr [g_xformScratch2088]
        mov     dword ptr [g_acc_00542078], 4
        test    eax, eax
        _emit   74h
        _emit   0ah
        mov     dword ptr [g_acc_00542078], 3
        ret
    }
}

/* @addr 0x0045e0d0 (30b): same shape, default=3, override=4 */
__declspec(naked) void ConditionalAcc3or4_0045e0d0(void) {
    __asm {
        mov     eax, dword ptr [g_xformScratch2088]
        mov     dword ptr [g_acc_00542078], 3
        test    eax, eax
        _emit   74h
        _emit   0ah
        mov     dword ptr [g_acc_00542078], 4
        ret
    }
}
