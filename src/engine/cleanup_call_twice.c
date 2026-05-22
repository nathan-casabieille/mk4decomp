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
extern unsigned int g_state_007b41a0;
extern unsigned int g_state_007b41a8;
extern unsigned int g_data_00ab5204;
extern unsigned int g_state_00ab5200;
extern void SetHi6_004b5ae0(void);
extern void StoreAtMinus8_004b5b00(void);

__declspec(naked) void AppInit_Misc2(void) {
    __asm {
        push    edi
        mov     ecx, 0xc0000
        xor     eax, eax
        mov     edi, OFFSET g_state_007b41a0
        rep stosd
        mov     eax, dword ptr [g_state_007b41a0]
        mov     dword ptr [g_state_007b41a8], OFFSET g_state_007b41a0
        and     eax, 0xff2ffff4
        pop     edi
        or      eax, 0x002ffff4
        or      eax, 0x80000000
        mov     dword ptr [g_state_007b41a0], eax
        ret
    }
}

/* @addr 0x004bd530 (56b)
 *   if (arg && *arg) {
 *     call free([*arg], 4); call free([*arg], &g_state_00ab5204);
 *     g_state_00ab5200 = 1; *arg = 0;
 *   }
 */
void CleanupCallTwice_004bd530(int *arg) {
    if (*arg != 0) {
        SetHi6_004b5ae0(*arg, 4);
        StoreAtMinus8_004b5b00(*arg, (int)&g_data_00ab5204);
        g_state_00ab5200 = 1;
        *arg = 0;
    }
}
