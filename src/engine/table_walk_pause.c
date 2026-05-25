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
extern unsigned int g_dispatchSave1579_00ab5034;
extern unsigned int g_table_004ab4e78;
extern void LoadGeoAsset_Default(void);

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

/* @addr 0x004bd850 (57b)
 *   walk table 0x00ab4e78..0x00ab5034 step 4;
 *   each entry's high bit triggers a call after clearing it
 *   into g_scaledInit_00542044; pause-test breaks the loop.
 */
void TableWalkPause_004bd850(void) {
    unsigned int *p = &g_table_004ab4e78;
    do {
        unsigned int v = *p;
        g_scaledInit_00542044 = v;
        if ((v & 0x80000000) != 0) {
            v &= 0x7fffffff;
            g_scaledInit_00542044 = v;
            LoadGeoAsset_Default();
            if (g_framePauseFlag != 0) return;
        }
        p++;
    } while ((int)p < (int)&g_dispatchSave1579_00ab5034);
}
