/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bf070 (16b)
 *   mov     eax, 0x00b4d00f
 *   and     eax, 0xfffe0000
 *   mov     [0x00f85b38], eax
 *   ret
 *
 * Keep naked: MSVC SP3 constant-folds `0x00b4d00f & 0xfffe0000`
 * into a single `mov [g], imm32` (10b), losing the load+and form.
 */
extern unsigned int g_dispatchSave1401_00f85b38;
extern void LoadStoreRetNopJmp_004bf090(void);
__declspec(naked) void MovAndStoreRetJmp_004bf070(void) {
    __asm {
        mov     eax, 0x00b4d00f
        and     eax, 0xfffe0000
        mov     dword ptr [g_dispatchSave1401_00f85b38], eax
        ret
    }
}
