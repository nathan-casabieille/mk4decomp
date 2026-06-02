/**
 * Auto-split from misc_matchesDD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b5a80 (52b)
 *   rep stos zero-fill 0xc0000 dwords starting at 0x007b41a0;
 *   then mask + or bits, set [0x007b41a8] = 0x007b41a0 (self-link list head).
 */
extern u8 g_memHeapStart[];
extern unsigned int g_dispatchSave1654;
extern unsigned int g_dispatchSave1583;
extern unsigned int g_dispatchSave1582;
extern void SetHi6(void);
extern void StoreAtMinus8(void);

__declspec(naked) void AppInit_Misc2(void) {
    __asm {
        push    edi
        mov     ecx, 0xc0000
        xor     eax, eax
        mov     edi, OFFSET g_memHeapStart
        rep stosd
        mov     eax, dword ptr [g_memHeapStart]
        mov     dword ptr [g_dispatchSave1654], OFFSET g_memHeapStart
        and     eax, 0xff2ffff4
        pop     edi
        or      eax, 0x002ffff4
        or      eax, 0x80000000
        mov     dword ptr [g_memHeapStart], eax
        ret
    }
}

/* @addr 0x004bd530 (56b)
 *   if (arg && *arg) {
 *     call free([*arg], 4); call free([*arg], &g_dispatchSave1583);
 *     g_dispatchSave1582 = 1; *arg = 0;
 *   }
 */
void CleanupCallTwice(int *arg) {
    if (*arg != 0) {
        SetHi6(*arg, 4);
        StoreAtMinus8(*arg, (int)&g_dispatchSave1583);
        g_dispatchSave1582 = 1;
        *arg = 0;
    }
}
