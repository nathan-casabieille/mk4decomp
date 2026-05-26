/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x0042f4d0 (28b)
 *   mov     edx, [g_scaledInit_00542044]
 *   mov     ecx, [g_currentNodeFlags]
 *   mov     [edx*4 + 0x5c], ecx
 *   call    F
 *   pop     edi, esi, ebp
 *   ret
 */
extern void Event23bMusicCluster_0042f540(void);
__declspec(naked) void ScaledStoreCallEpilogue_0042f4d0(void) {
    __asm {
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [edx*4 + 0x5c], ecx
        call    Event23bMusicCluster_0042f540
        pop     edi
        pop     esi
        pop     ebp
        ret
    }
}
