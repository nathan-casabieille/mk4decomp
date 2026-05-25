/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bdb00 (79b)
 *   Two-entry: [4bdb00 +30b] init g_scaledInit slot
 *   ((eax<<2) → ptr): writes [ptr]=0x1000, [+4]=0, [+8]=0x1000,
 *   [+0xc]=0, [+0x10]=word(0x1000); ret. nop align;
 *   [4bdb20 +49b] tail at 0x4bdb20: g_xformEntityIdx-indexed
 *   "all-zero" check across +0/+4/+8; if any non-zero jmp T,
 *   else loop back to entry.
 */
extern void NodeApplyTransform_A(void);
__declspec(naked) void InitOrAllZeroLoopback_004bdb00(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     edx, 0x1000
        shl     eax, 2
        xor     ecx, ecx
        mov     dword ptr [eax], edx
        mov     dword ptr [eax + 4], ecx
        mov     dword ptr [eax + 8], edx
        mov     dword ptr [eax + 0x0c], ecx
        mov     word ptr [eax + 0x10], dx
        ret
        nop
        mov     eax, dword ptr [g_xformEntityIdx]
        cmp     dword ptr [eax*4 + 0], 0
        _emit   75h
        _emit   1bh
        mov     ecx, dword ptr [eax*4 + 4]
        test    ecx, ecx
        _emit   75h
        _emit   10h
        mov     ecx, dword ptr [eax*4 + 8]
        test    ecx, ecx
        _emit   75h
        _emit   05h
        _emit   0e9h
        _emit   0b6h
        _emit   0ffh
        _emit   0ffh
        _emit   0ffh
        jmp     NodeApplyTransform_A
    }
}
