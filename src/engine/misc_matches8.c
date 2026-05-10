/**
 * Eighth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00413360 (19b): push 0x8d; push DATA_PTR; call F; add esp,8; ret */
extern int __cdecl func_0049cb38(void *, int);
extern void *g_data_00413490;
void Push8d_Push413490_00413360(void) {
    func_0049cb38(&g_data_00413490, 0x8d);
}

/* @addr 0x00413560 (19b): push 0x8e; push DATA_PTR; call F; add esp,8; ret */
extern void *g_data_00413690;
void Push8e_Push413690_00413560(void) {
    func_0049cb38(&g_data_00413690, 0x8e);
}

/* @addr 0x0041d550 (16b): push 0; push DATA_PTR; call F; add esp,8; ret */
extern int __cdecl func_0049eb40(void *, int);
extern void *g_data_0041d7d0;
void Push0_Push41d7d0_0041d550(void) {
    func_0049eb40(&g_data_0041d7d0, 0);
}

/* @addr 0x00421c40 (16b): push 0x71; push DATA_PTR; call F; add esp,8; ret */
extern int __cdecl func_0049cb40(void *, int);
extern void *g_data_0048caa0;
void Push71_Push48caa0_00421c40(void) {
    func_0049cb40(&g_data_0048caa0, 0x71);
}

/* @addr 0x00463070 (20b): push 0; push 0x00463220; call F; add esp,8; jmp +0x0c */
extern int func_0049cb40_b(int, void *);
extern void *g_data_00463220;
extern void func_0046308c(void);
__declspec(naked) void Push0_Push463220_Jmp_00463070(void) {
    __asm {
        push    0
        push    OFFSET g_data_00463220
        call    func_0049cb40_b
        add     esp, 8
        jmp     func_0046308c
    }
}

/* @addr 0x00489220 (23b): push 0x267; push DATA; call F; add esp,8; jmp -0xc7 */
extern int func_0049cb40_c(int, void *);
extern void *g_data_0044eb60;
extern void func_0048915f(void);
__declspec(naked) void Push267_Push44eb60_Jmp_00489220(void) {
    __asm {
        push    0x0267
        push    OFFSET g_data_0044eb60
        call    func_0049cb40_c
        add     esp, 8
        jmp     func_0048915f
    }
}

/* @addr 0x00478120 (25b): two arg+call pairs then jmp
 *   push    0x2b
 *   call    F
 *   add     esp, 4
 *   push    0x2c
 *   call    F
 *   add     esp, 4
 *   jmp     +7
 */
extern int func_004049d0(int);
extern void func_00478131(void);
__declspec(naked) void TwoCallJmp_00478120(void) {
    __asm {
        push    0x2b
        call    func_004049d0
        add     esp, 4
        push    0x2c
        call    func_004049d0
        add     esp, 4
        jmp     func_00478131
    }
}

/* @addr 0x0043d580 (21b)
 *   push    0x004e5120
 *   call    F
 *   add     esp, 4
 *   ret
 *   nop nop
 *   jmp     +0x0b
 */
extern int func_00459500(void *);
extern void *g_data_004e5120;
extern void func_0043d590(void);
__declspec(naked) void PushCallRetNopJmp_0043d580(void) {
    __asm {
        push    OFFSET g_data_004e5120
        call    func_00459500
        add     esp, 4
        ret
        nop
        nop
        jmp     func_0043d590
    }
}

/* @addr 0x004ab670 (21b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +6
 *   inc     dword ptr [g_walkCallback]
 *   ret
 */
extern void func_004ab630(void);
__declspec(naked) void CallPauseInc_004ab670(void) {
    __asm {
        call    func_004ab630
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   06h
        inc     dword ptr [g_walkCallback]
        ret
    }
}

/* @addr 0x0049cb40 (28b)
 *   mov     eax, [esp+8]
 *   mov     [g_eventQueueWorkType], eax
 *   mov     eax, [esp+4]
 *   push    eax
 *   mov     [g_pendingNodeType], eax
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int func_0049f280(int);
__declspec(naked) void StoreTwoCall_0049cb40(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     eax, dword ptr [esp + 4]
        push    eax
        mov     dword ptr [g_pendingNodeType], eax
        call    func_0049f280
        add     esp, 4
        ret
    }
}

/* @addr 0x004abfc0 (27b)
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, eax
 *   and     eax, 0x00ffffff
 *   shr     ecx, 0x18
 *   mov     [g_eventQueueCurrent], ecx
 *   mov     [g_xformEntityIdx], eax
 *   ret
 */
extern unsigned int g_xformEntityIdx;
__declspec(naked) void SplitHi8Lo24_004abfc0(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, eax
        and     eax, 0x00ffffff
        shr     ecx, 0x18
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_xformEntityIdx], eax
        ret
    }
}

/* @addr 0x004b5450 (18b)
 *   mov     eax, [esp+4]
 *   push    eax
 *   call    [iat]
 *   shr     eax, 0xf
 *   and     eax, 1
 *   ret
 */
extern void *g_iat_004d21c0;
__declspec(naked) void CallShrAnd_004b5450(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    eax
        call    dword ptr [g_iat_004d21c0]
        shr     eax, 0x0f
        and     eax, 1
        ret
    }
}

/* @addr 0x004bd510 (22b)
 *   mov     eax, [g_scaledInit_00542044]
 *   lea     ecx, [eax*4 + 0x48]
 *   push    ecx
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int func_004bd524(void *);
__declspec(naked) void LeaScaledCall_004bd510(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        lea     ecx, dword ptr [eax*4 + 0x48]
        push    ecx
        call    func_004bd524
        add     esp, 4
        ret
    }
}

/* @addr 0x004bd570 (21b)
 *   push    4
 *   call    F1
 *   add     esp, 4
 *   push    2
 *   call    F1
 *   add     esp, 4
 *   ret
 */
extern int func_00444c98(int);
__declspec(naked) void TwoArgCallSeq_004bd570(void) {
    __asm {
        push    4
        call    func_00444c98
        add     esp, 4
        push    2
        call    func_00444c98
        add     esp, 4
        ret
    }
}
