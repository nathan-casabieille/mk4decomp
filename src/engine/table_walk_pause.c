/**
 * Auto-split from misc_matchesDD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004b5a80 (52b)
 *   rep stos zero-fill 0xc0000 dwords starting at 0x007b41a0;
 *   then mask + or bits, set [0x007b41a8] = 0x007b41a0 (self-link list head).
 */
extern u8 g_memHeapStart[];
extern unsigned int g_dispatchSave1654;
extern unsigned int g_dispatchSave1579;
extern unsigned int g_texAssetIds;
extern void LoadGeoAsset_Default(void);

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

/* @addr 0x004bd850 (57b)
 *   walk table 0x00ab4e78..0x00ab5034 step 4;
 *   each entry's high bit triggers a call after clearing it
 *   into g_currentNodeIdx; pause-test breaks the loop.
 */
void TableWalkPause(void) {
    unsigned int *p = &g_texAssetIds;
    do {
        unsigned int v = *p;
        g_currentNodeIdx = v;
        if ((v & 0x80000000) != 0) {
            v &= 0x7fffffff;
            g_currentNodeIdx = v;
            LoadGeoAsset_Default();
            if (g_framePauseFlag != 0) return;
        }
        p++;
    } while ((int)p < (int)&g_dispatchSave1579);
}
