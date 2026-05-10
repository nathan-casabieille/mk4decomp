/**
 * 47 "set-global-and-tail-jmp" wrappers.
 *
 * Each compiles to:
 *   mov dword ptr [g_X], CONST     ; c7 05 + reloc + imm32  (10 bytes)
 *   jmp Target                      ; e9 + reloc            (5 bytes)
 *
 * 15 bytes total - per-state setup helpers in the menu/scene-
 * graph code.
 */
#include "engine/scenegraph.h"

/* New globals referenced by these wrappers. */
extern unsigned int g_setjmp_00542078;   /* 0x00542078 */
extern unsigned int g_setjmp_00ab5750;   /* 0x00ab5750 */

/* Externs for jump targets. */
extern void func_00405430(void);   /* 0x00405430 */
extern void func_004078f0(void);   /* 0x004078f0 */
extern void func_00408d30(void);   /* 0x00408d30 */
extern void func_004294a0(void);   /* 0x004294a0 */
extern void func_004295a0(void);   /* 0x004295a0 */
extern void func_00429960(void);   /* 0x00429960 */
extern void func_0042d090(void);   /* 0x0042d090 */
extern void func_00440730(void);   /* 0x00440730 */
extern void func_00451ad0(void);   /* 0x00451ad0 */
extern void func_00451b10(void);   /* 0x00451b10 */
extern void func_00451b50(void);   /* 0x00451b50 */
extern void func_00451b90(void);   /* 0x00451b90 */
extern void func_004561f0(void);   /* 0x004561f0 */
extern void func_0045ec10(void);   /* 0x0045ec10 */
extern void func_0045f650(void);   /* 0x0045f650 */
extern void func_004609e0(void);   /* 0x004609e0 */
extern void func_00471190(void);   /* 0x00471190 */
extern void GuardedSeq_00473f10(void);   /* 0x00473f10 */
extern void func_004753b0(void);   /* 0x004753b0 */
extern void func_00481020(void);   /* 0x00481020 */
extern void func_00483f30(void);   /* 0x00483f30 */
extern void func_00485d70(void);   /* 0x00485d70 */
extern void func_00487920(void);   /* 0x00487920 */
extern void func_00489f50(void);   /* 0x00489f50 */
extern void func_0048acd0(void);   /* 0x0048acd0 */
extern void func_0048fd60(void);   /* 0x0048fd60 */
extern void Thunk_0049cba0(void);   /* 0x0049cba0 */
extern void func_004b0d80(void);   /* 0x004b0d80 */

/* The wrappers - naked __asm to lock the encoding. */
/* @addr 0x00405420 */
__declspec(naked) void SetJmp_00405420(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x0000f333
        jmp     func_00405430
    }
}

/* @addr 0x004078e0 */
__declspec(naked) void SetJmp_004078e0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000001
        jmp     func_004078f0
    }
}

/* @addr 0x00408d20 */
__declspec(naked) void SetJmp_00408d20(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000001
        jmp     func_00408d30
    }
}

/* @addr 0x00428cf0 */
__declspec(naked) void SetJmp_00428cf0(void) {
    __asm {
        mov     dword ptr [g_eventQueueChild], 0x00000003
        jmp     func_004294a0
    }
}

/* @addr 0x00429230 */
__declspec(naked) void SetJmp_00429230(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000000
        jmp     func_004295a0
    }
}

/* @addr 0x00429950 */
__declspec(naked) void SetJmp_00429950(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000000
        jmp     func_00429960
    }
}

/* @addr 0x0042d070 */
__declspec(naked) void SetJmp_0042d070(void) {
    __asm {
        mov     dword ptr [g_currentNodeFlags], 0x00010000
        jmp     func_0042d090
    }
}

/* @addr 0x0042d080 */
__declspec(naked) void SetJmp_0042d080(void) {
    __asm {
        mov     dword ptr [g_currentNodeFlags], 0xffff0000
        jmp     func_0042d090
    }
}

/* @addr 0x00438f50 */
__declspec(naked) void SetJmp_00438f50(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000004
        jmp     func_00471190
    }
}

/* @addr 0x00438f60 */
__declspec(naked) void SetJmp_00438f60(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000005
        jmp     func_00471190
    }
}

/* @addr 0x00438f70 */
__declspec(naked) void SetJmp_00438f70(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000006
        jmp     func_00471190
    }
}

/* @addr 0x00439c30 */
__declspec(naked) void SetJmp_00439c30(void) {
    __asm {
        mov     dword ptr [g_eventQueueNotMask], 0x00010029
        jmp     func_0045f650
    }
}

/* @addr 0x00440710 */
__declspec(naked) void SetJmp_00440710(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x000001f4
        jmp     func_00440730
    }
}

/* @addr 0x00440720 */
__declspec(naked) void SetJmp_00440720(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x0000002d
        jmp     func_00440730
    }
}

/* @addr 0x00451aa0 */
__declspec(naked) void SetJmp_00451aa0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000005
        jmp     func_00451ad0
    }
}

/* @addr 0x00451ab0 */
__declspec(naked) void SetJmp_00451ab0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000002
        jmp     func_00451ad0
    }
}

/* @addr 0x00451ac0 */
__declspec(naked) void SetJmp_00451ac0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000003
        jmp     func_00451ad0
    }
}

/* @addr 0x00451ad0 */
__declspec(naked) void SetJmp_00451ad0(void) {
    __asm {
        mov     dword ptr [g_setjmp_00542078], 0x00000006
        jmp     GuardedSeq_00473f10
    }
}

/* @addr 0x00451ae0 */
__declspec(naked) void SetJmp_00451ae0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000006
        jmp     func_00451b10
    }
}

/* @addr 0x00451af0 */
__declspec(naked) void SetJmp_00451af0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000002
        jmp     func_00451b10
    }
}

/* @addr 0x00451b00 */
__declspec(naked) void SetJmp_00451b00(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000003
        jmp     func_00451b10
    }
}

/* @addr 0x00451b10 */
__declspec(naked) void SetJmp_00451b10(void) {
    __asm {
        mov     dword ptr [g_setjmp_00542078], 0x00000005
        jmp     GuardedSeq_00473f10
    }
}

/* @addr 0x00451b20 */
__declspec(naked) void SetJmp_00451b20(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000005
        jmp     func_00451b50
    }
}

/* @addr 0x00451b30 */
__declspec(naked) void SetJmp_00451b30(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000002
        jmp     func_00451b50
    }
}

/* @addr 0x00451b40 */
__declspec(naked) void SetJmp_00451b40(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000003
        jmp     func_00451b50
    }
}

/* @addr 0x00451b50 */
__declspec(naked) void SetJmp_00451b50(void) {
    __asm {
        mov     dword ptr [g_setjmp_00542078], 0x0000000c
        jmp     GuardedSeq_00473f10
    }
}

/* @addr 0x00451b60 */
__declspec(naked) void SetJmp_00451b60(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000006
        jmp     func_00451b90
    }
}

/* @addr 0x00451b70 */
__declspec(naked) void SetJmp_00451b70(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000002
        jmp     func_00451b90
    }
}

/* @addr 0x00451b80 */
__declspec(naked) void SetJmp_00451b80(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000003
        jmp     func_00451b90
    }
}

/* @addr 0x004561c0 */
__declspec(naked) void SetJmp_004561c0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000003
        jmp     func_004561f0
    }
}

/* @addr 0x004561d0 */
__declspec(naked) void SetJmp_004561d0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000009
        jmp     func_004561f0
    }
}

/* @addr 0x004561e0 */
__declspec(naked) void SetJmp_004561e0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x0000000a
        jmp     func_004561f0
    }
}

/* @addr 0x0045ebf0 */
__declspec(naked) void SetJmp_0045ebf0(void) {
    __asm {
        mov     dword ptr [g_eventQueueCurrent], 0x00000002
        jmp     func_0045ec10
    }
}

/* @addr 0x0045ec00 */
__declspec(naked) void SetJmp_0045ec00(void) {
    __asm {
        mov     dword ptr [g_eventQueueCurrent], 0x00000001
        jmp     func_0045ec10
    }
}

/* @addr 0x004609c0 */
__declspec(naked) void SetJmp_004609c0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000000
        jmp     func_004609e0
    }
}

/* @addr 0x004609d0 */
__declspec(naked) void SetJmp_004609d0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000001
        jmp     func_004609e0
    }
}

/* @addr 0x004753a0 */
__declspec(naked) void SetJmp_004753a0(void) {
    __asm {
        mov     dword ptr [g_eventQueueIdx], 0x00475570
        jmp     func_004753b0
    }
}

/* @addr 0x00483b40 */
__declspec(naked) void SetJmp_00483b40(void) {
    __asm {
        mov     dword ptr [g_currentNodeIdx], 0x00494580
        jmp     func_0048fd60
    }
}

/* @addr 0x00483f20 */
__declspec(naked) void SetJmp_00483f20(void) {
    __asm {
        mov     dword ptr [g_eventQueueNotMask], 0x0000000a
        jmp     func_00483f30
    }
}

/* @addr 0x00485d60 */
__declspec(naked) void SetJmp_00485d60(void) {
    __asm {
        mov     dword ptr [g_setjmp_00542078], 0x00010000
        jmp     func_00485d70
    }
}

/* @addr 0x00487910 */
__declspec(naked) void SetJmp_00487910(void) {
    __asm {
        mov     dword ptr [g_eventQueueEnd], 0x00000000
        jmp     func_00487920
    }
}

/* @addr 0x00489020 */
__declspec(naked) void SetJmp_00489020(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x00000002
        jmp     func_00481020
    }
}

/* @addr 0x0048acc0 */
__declspec(naked) void SetJmp_0048acc0(void) {
    __asm {
        mov     dword ptr [g_currentNodeFlags], 0x00010000
        jmp     func_0048acd0
    }
}

/* @addr 0x0049cb90 */
__declspec(naked) void SetJmp_0049cb90(void) {
    __asm {
        mov     dword ptr [g_eventQueueCurrent], 0xffffffff
        jmp     Thunk_0049cba0
    }
}

/* @addr 0x004a1ac0 */
__declspec(naked) void SetJmp_004a1ac0(void) {
    __asm {
        mov     dword ptr [g_eventQueueWorkType], 0x00000325
        jmp     func_00489f50
    }
}

/* @addr 0x004a1ad0 */
__declspec(naked) void SetJmp_004a1ad0(void) {
    __asm {
        mov     dword ptr [g_eventQueueWorkType], 0x00000320
        jmp     func_00489f50
    }
}

/* @addr 0x004bea40 */
__declspec(naked) void SetJmp_004bea40(void) {
    __asm {
        mov     dword ptr [g_setjmp_00ab5750], 0x00000000
        jmp     func_004b0d80
    }
}

