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
extern unsigned int g_dispatchSave1654_007b41a8;
extern unsigned int g_crtCleanupFlag_00f9f84c;
extern void DualCondCleanupCall_004cc030(void);
extern void RaiseAbortLocalized_004cc070(void);

__declspec(naked) void AppInit_Misc2(void) {
    __asm {
        push    edi
        mov     ecx, 0xc0000
        xor     eax, eax
        mov     edi, OFFSET g_memHeapStart
        rep stosd
        mov     eax, dword ptr [g_memHeapStart]
        mov     dword ptr [g_dispatchSave1654_007b41a8], OFFSET g_memHeapStart
        and     eax, 0xff2ffff4
        pop     edi
        or      eax, 0x002ffff4
        or      eax, 0x80000000
        mov     dword ptr [g_memHeapStart], eax
        ret
    }
}

/* @addr 0x004c6e60 (42b)
 *   if g_crtCleanupFlag_00f9f84c == 1, call F; then call F2(arg);
 *   call IAT [g_iat_00520060](0xff); ret.
 */
extern void (*g_iat_00520060)(int);
void CmpCallPushIATCall_004c6e60(int arg) {
    if (g_crtCleanupFlag_00f9f84c == 1) {
        DualCondCleanupCall_004cc030();
    }
    RaiseAbortLocalized_004cc070(arg);
    g_iat_00520060(0xff);
}
