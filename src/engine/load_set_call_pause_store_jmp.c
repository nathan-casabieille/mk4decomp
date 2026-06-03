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
extern unsigned int g_player1NodeIdx;
extern void MStackSignedMod(void);

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

/* @addr 0x0042fea0 (64b)
 *   load g_player2NodeIdx; set g_eventQueueWorkType = 0x4ccc;
 *   store eax → g_scaledInit; call F; pause → ret;
 *   load g_walkCallback, g_player1NodeIdx;
 *   store both into g_eventQueueCurrent and g_scaledInit; jmp T.
 */
void LoadSetCallPauseStoreJmp(void) {
    g_eventQueueWorkType = 0x4ccc;
    g_currentNodeIdx = g_player2NodeIdx;
    MStackSignedMod();
    if (g_framePauseFlag) return;
    g_eventQueueCurrent = (unsigned int)g_walkCallback;
    g_currentNodeIdx = g_player1NodeIdx;
    MStackSignedMod();
}
