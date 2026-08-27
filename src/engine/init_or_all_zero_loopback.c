/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#endif


/* @addr 0x004bdb00 (79b)
 *   Two-entry: [4bdb00 +30b] init g_scaledInit slot
 *   ((eax<<2) → ptr): writes [ptr]=0x1000, [+4]=0, [+8]=0x1000,
 *   [+0xc]=0, [+0x10]=word(0x1000); ret. nop align;
 *   [4bdb20 +49b] tail at 0x4bdb20: g_xformEntityIdx-indexed
 *   "all-zero" check across +0/+4/+8; if any non-zero jmp T,
 *   else loop back to entry.
 */
extern void NodeApplyTransform_A(void);
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void InitOrAllZeroLoopback(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)MK4_PTR(((g_currentNodeIdx) * 4));
  *puVar1 = 0x1000;
  puVar1[1] = 0;
  puVar1[2] = 0x1000;
  puVar1[3] = 0;
  *(undefined2 *)(puVar1 + 4) = 0x1000;
  return;
}
#else
__declspec(naked) void InitOrAllZeroLoopback(void) {
    __asm {
        mov     eax, dword ptr [g_currentNodeIdx]
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
#endif
