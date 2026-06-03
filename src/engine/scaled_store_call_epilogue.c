/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

/* @addr 0x0042f4d0 (28b)
 *   mov     edx, [g_currentNodeIdx]
 *   mov     ecx, [g_currentNodeFlags]
 *   mov     [edx*4 + 0x5c], ecx
 *   call    F
 *   pop     edi, esi, ebp
 *   ret
 */
extern void Event23bMusicCluster(void);
__declspec(naked) void ScaledStoreCallEpilogue(void) {
    __asm {
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [edx*4 + 0x5c], ecx
        call    Event23bMusicCluster
        pop     edi
        pop     esi
        pop     ebp
        ret
    }
}
