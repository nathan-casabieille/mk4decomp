/**
 * Auto-split from misc_matchesDD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b5a80 (52b)
 *   rep stos zero-fill 0xc0000 dwords starting at 0x007b41a0;
 *   then mask + or bits, set [0x007b41a8] = 0x007b41a0 (self-link list head).
 */
extern u8 g_memHeapStart[];
extern unsigned int g_state_007b41a8;
__declspec(naked) void AppInit_Misc2(void) {
    __asm {
        push    edi
        mov     ecx, 0xc0000
        xor     eax, eax
        mov     edi, OFFSET g_memHeapStart
        rep stosd
        mov     eax, dword ptr [g_memHeapStart]
        mov     dword ptr [g_state_007b41a8], OFFSET g_memHeapStart
        and     eax, 0xff2ffff4
        pop     edi
        or      eax, 0x002ffff4
        or      eax, 0x80000000
        mov     dword ptr [g_memHeapStart], eax
        ret
    }
}

/* @addr 0x004be210 (52b)
 *   scaled load; 16-bit neg of 3 word fields at offsets 0,2,4;
 *   set g_xformDirtyFlags |= 0x30.
 */
void ScaledNegThreeWords_004be210(void) {
    unsigned int idx;
    short a;
    short b;
    short c;
    idx = g_scaledInit_00542044 * 4;
    a = *(short *)(idx);
    b = *(short *)(idx + 2);
    a = (short)-(int)a;
    *(short *)(idx) = a;
    c = *(short *)(idx + 4);
    b = (short)-(int)b;
    c = (short)-(int)c;
    *(short *)(idx + 2) = b;
    *(short *)(idx + 4) = c;
    g_xformDirtyFlags |= 0x30;
}
