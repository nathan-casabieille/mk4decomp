/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004c5740 (65b): __aullshl 64-bit shift-left + fnclex init helper
 *   joined with int3 + nop padding. Whole stub is 65b.
 *
 *   Layout:
 *     [0x00..0x1e] __aullshl: 64-bit shl by cl, 3 fall-through paths
 *                              (cl<0x20, 0x20<=cl<0x40, cl>=0x40).
 *     [0x1f]       int3 (filler).
 *     [0x20..0x36] init helper: call 4c5790, call 4c8450 → store result,
 *                                call 4c83e0, fnclex, ret.
 *     [0x37..0x3f] nop * 9 + ret.
 */
extern void func_004c5790_hh(void);
extern int LocaleNumericHelpers(void);
extern void Push3000010000Call(void);
extern unsigned int g_dispatchSave1423;
void UllShlAndInit(void) {
    __asm {
        cmp     cl, 0x40
        _emit   73h
        _emit   15h
        cmp     cl, 0x20
        _emit   73h
        _emit   06h
        shld    edx, eax, cl
        shl     eax, cl
        ret
        mov     edx, eax
        xor     eax, eax
        and     cl,  0x1f
        shl     edx, cl
        ret
        xor     eax, eax
        xor     edx, edx
        ret
        _emit   0cch
        call    func_004c5790_hh
        call    LocaleNumericHelpers
        mov     dword ptr [g_dispatchSave1423], eax
        call    Push3000010000Call
        fnclex
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        }
}
