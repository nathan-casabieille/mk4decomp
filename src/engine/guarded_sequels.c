/**
 * 38 "guarded sequel" wrappers.
 *
 * Each compiles to:
 *   call PreFunc                  ; e8 + reloc
 *   mov eax, [g_framePauseFlag]   ; a1 6c 1e 54 00
 *   test eax, eax                  ; 85 c0
 *   jne short skip                 ; 75 05
 *   jmp PostFunc                   ; e9 + reloc  (tail-call)
 *   ret                            ; c3
 *
 * 20 bytes total. Generated as a per-tick chain helper that
 * runs PostFunc only if the frame pause flag is clear.
 */
#include "game/tick.h"   /* g_framePauseFlag */

/* Externs for guarded-sequel targets. */
extern void func_00401b70(void);   /* 0x00401b70 */
extern void func_004058c0(void);   /* 0x004058c0 */
extern void func_00406740(void);   /* 0x00406740 */
extern void func_00406ba0(void);   /* 0x00406ba0 */
extern void func_00408c10(void);   /* 0x00408c10 */
extern void func_00408cb0(void);   /* 0x00408cb0 */
extern void func_0041ab90(void);   /* 0x0041ab90 */
extern void func_0041f780(void);   /* 0x0041f780 */
extern void func_0041f830(void);   /* 0x0041f830 */
extern void func_00421c20(void);   /* 0x00421c20 */
extern void func_00428370(void);   /* 0x00428370 */
extern void func_004284a0(void);   /* 0x004284a0 */
extern void func_004297d0(void);   /* 0x004297d0 */
extern void func_004299a0(void);   /* 0x004299a0 */
extern void func_0042f8a0(void);   /* 0x0042f8a0 */
extern void func_0042ffa0(void);   /* 0x0042ffa0 */
extern void func_00433bd0(void);   /* 0x00433bd0 */
extern void func_00433bf0(void);   /* 0x00433bf0 */
extern void func_00433c60(void);   /* 0x00433c60 */
extern void func_00433d30(void);   /* 0x00433d30 */
extern void func_0044ba30(void);   /* 0x0044ba30 */
extern void func_0044baa0(void);   /* 0x0044baa0 */
extern void func_004537a0(void);   /* 0x004537a0 */
extern void func_004592f0(void);   /* 0x004592f0 */
extern void func_00467c30(void);   /* 0x00467c30 */
extern void func_00467ca0(void);   /* 0x00467ca0 */
extern void func_00473f50(void);   /* 0x00473f50 */
extern void func_00473f90(void);   /* 0x00473f90 */
extern void func_00474010(void);   /* 0x00474010 */
extern void func_00474050(void);   /* 0x00474050 */
extern void func_00474090(void);   /* 0x00474090 */
extern void func_00474170(void);   /* 0x00474170 */
extern void func_00474290(void);   /* 0x00474290 */
extern void func_00474d40(void);   /* 0x00474d40 */
extern void func_00474de0(void);   /* 0x00474de0 */
extern void func_00475790(void);   /* 0x00475790 */
extern void func_00476e00(void);   /* 0x00476e00 */
extern void func_00476f30(void);   /* 0x00476f30 */
extern void func_00476fe0(void);   /* 0x00476fe0 */
extern void func_004774f0(void);   /* 0x004774f0 */
extern void func_0047d9a0(void);   /* 0x0047d9a0 */
extern void func_004871d0(void);   /* 0x004871d0 */
extern void func_004888b0(void);   /* 0x004888b0 */
extern void func_00488be0(void);   /* 0x00488be0 */
extern void func_00488c00(void);   /* 0x00488c00 */
extern void func_00488f00(void);   /* 0x00488f00 */
extern void func_0048a050(void);   /* 0x0048a050 */
extern void Wrapper_0048a3a0(void);   /* 0x0048a3a0 */
extern void func_00490230(void);   /* 0x00490230 */
extern void func_004903b0(void);   /* 0x004903b0 */
extern void func_00490740(void);   /* 0x00490740 */
extern void func_00490c30(void);   /* 0x00490c30 */
extern void func_004910b0(void);   /* 0x004910b0 */
extern void func_004917e0(void);   /* 0x004917e0 */

/* The wrappers - naked __asm to force the exact `call/test/jne/jmp/ret` sequence. */
/* @addr 0x0041aad0 */
__declspec(naked) void GuardedSeq_0041aad0(void) {
    __asm {
        call    func_0041ab90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0041f780
        ret
    }
}

/* @addr 0x004200b0 */
__declspec(naked) void GuardedSeq_004200b0(void) {
    __asm {
        call    func_00421c20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00401b70
        ret
    }
}

/* @addr 0x00428350 */
__declspec(naked) void GuardedSeq_00428350(void) {
    __asm {
        call    func_00406ba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00428370
        ret
    }
}

/* @addr 0x00428480 */
__declspec(naked) void GuardedSeq_00428480(void) {
    __asm {
        call    func_00406ba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004284a0
        ret
    }
}

/* @addr 0x004297b0 */
__declspec(naked) void GuardedSeq_004297b0(void) {
    __asm {
        call    func_004299a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004297d0
        ret
    }
}

/* @addr 0x0042fb80 */
__declspec(naked) void GuardedSeq_0042fb80(void) {
    __asm {
        call    func_0042ffa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0042f8a0
        ret
    }
}

/* @addr 0x0042fba0 */
__declspec(naked) void GuardedSeq_0042fba0(void) {
    __asm {
        call    func_0042ffa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0042f8a0
        ret
    }
}

/* @addr 0x004335d0 */
__declspec(naked) void GuardedSeq_004335d0(void) {
    __asm {
        call    func_004592f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004774f0
        ret
    }
}

/* @addr 0x00433bb0 */
__declspec(naked) void GuardedSeq_00433bb0(void) {
    __asm {
        call    func_00433c60
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00433bd0
        ret
    }
}

/* @addr 0x00433bd0 */
__declspec(naked) void GuardedSeq_00433bd0(void) {
    __asm {
        call    func_00433d30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00433bf0
        ret
    }
}

/* @addr 0x00438630 */
__declspec(naked) void GuardedSeq_00438630(void) {
    __asm {
        call    func_00490740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0041f780
        ret
    }
}

/* @addr 0x0044ba10 */
__declspec(naked) void GuardedSeq_0044ba10(void) {
    __asm {
        call    func_0044ba30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00473f50
        ret
    }
}

/* @addr 0x0044ba80 */
__declspec(naked) void GuardedSeq_0044ba80(void) {
    __asm {
        call    func_0044baa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00473f50
        ret
    }
}

/* @addr 0x004515a0 */
__declspec(naked) void GuardedSeq_004515a0(void) {
    __asm {
        call    func_00408c10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00475790
        ret
    }
}

/* @addr 0x00453780 */
__declspec(naked) void GuardedSeq_00453780(void) {
    __asm {
        call    func_004058c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004537a0
        ret
    }
}

/* @addr 0x004605b0 */
__declspec(naked) void GuardedSeq_004605b0(void) {
    __asm {
        call    func_004910b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004917e0
        ret
    }
}

/* @addr 0x00467c10 */
__declspec(naked) void GuardedSeq_00467c10(void) {
    __asm {
        call    func_00467c30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00473f50
        ret
    }
}

/* @addr 0x00467c80 */
__declspec(naked) void GuardedSeq_00467c80(void) {
    __asm {
        call    func_00467ca0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00473f50
        ret
    }
}

/* @addr 0x00471670 */
__declspec(naked) void GuardedSeq_00471670(void) {
    __asm {
        call    func_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0041f830
        ret
    }
}

/* @addr 0x00472820 */
__declspec(naked) void GuardedSeq_00472820(void) {
    __asm {
        call    func_00474de0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0048a050
        ret
    }
}

/* @addr 0x00472840 */
__declspec(naked) void GuardedSeq_00472840(void) {
    __asm {
        call    func_00474d40
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0048a050
        ret
    }
}

/* @addr 0x00473ef0 */
__declspec(naked) void GuardedSeq_00473ef0(void) {
    __asm {
        call    func_00473f90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00474090
        ret
    }
}

/* @addr 0x00473f10 */
__declspec(naked) void GuardedSeq_00473f10(void) {
    __asm {
        call    func_00473f90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00474050
        ret
    }
}

/* @addr 0x00473f30 */
__declspec(naked) void GuardedSeq_00473f30(void) {
    __asm {
        call    func_00473f90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00474010
        ret
    }
}

/* @addr 0x00473f50 */
__declspec(naked) void GuardedSeq_00473f50(void) {
    __asm {
        call    func_00473f90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00474290
        ret
    }
}

/* @addr 0x00473f70 */
__declspec(naked) void GuardedSeq_00473f70(void) {
    __asm {
        call    func_00473f90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00474170
        ret
    }
}

/* @addr 0x00476de0 */
__declspec(naked) void GuardedSeq_00476de0(void) {
    __asm {
        call    func_00408cb0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00476e00
        ret
    }
}

/* @addr 0x00476f10 */
__declspec(naked) void GuardedSeq_00476f10(void) {
    __asm {
        call    func_00408cb0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00476f30
        ret
    }
}

/* @addr 0x00476fc0 */
__declspec(naked) void GuardedSeq_00476fc0(void) {
    __asm {
        call    func_00408cb0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00476fe0
        ret
    }
}

/* @addr 0x0047d980 */
__declspec(naked) void GuardedSeq_0047d980(void) {
    __asm {
        call    func_00490230
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0047d9a0
        ret
    }
}

/* @addr 0x00485ca0 */
__declspec(naked) void GuardedSeq_00485ca0(void) {
    __asm {
        call    func_00490740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00488be0
        ret
    }
}

/* @addr 0x004871b0 */
__declspec(naked) void GuardedSeq_004871b0(void) {
    __asm {
        call    func_004871d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     Wrapper_0048a3a0
        ret
    }
}

/* @addr 0x00488890 */
__declspec(naked) void GuardedSeq_00488890(void) {
    __asm {
        call    func_00488f00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004888b0
        ret
    }
}

/* @addr 0x00488be0 */
__declspec(naked) void GuardedSeq_00488be0(void) {
    __asm {
        call    func_004903b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00488c00
        ret
    }
}

/* @addr 0x00490c60 */
__declspec(naked) void GuardedSeq_00490c60(void) {
    __asm {
        call    func_00490c30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004903b0
        ret
    }
}

/* @addr 0x00497450 */
__declspec(naked) void GuardedSeq_00497450(void) {
    __asm {
        call    func_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0041f830
        ret
    }
}

/* @addr 0x0049a650 */
__declspec(naked) void GuardedSeq_0049a650(void) {
    __asm {
        call    func_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0041f830
        ret
    }
}

/* @addr 0x0049c340 */
__declspec(naked) void GuardedSeq_0049c340(void) {
    __asm {
        call    func_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0041f830
        ret
    }
}

