/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004bf070 (16b)
 *   mov     eax, 0x00b4d00f
 *   and     eax, 0xfffe0000
 *   mov     [0x00f85b38], eax
 *   ret
 *
 * Keep naked: MSVC SP3 constant-folds `0x00b4d00f & 0xfffe0000`
 * into a single `mov [g], imm32` (10b), losing the load+and form.
 */
extern unsigned int g_dispatchSave1401;
extern void LoadStoreRetNopJmp(void);
#ifdef NON_MATCHING
/* Portable: the orig const-folds the load+and into one store; behavior
 * is just "store the masked constant". (Matching keeps the explicit
 * load+and form below so MSVC SP3 does not fold it.) */
void MovAndStoreRetJmp(void) {
    g_dispatchSave1401 = 0x00b4d00fu & 0xfffe0000u;
}
#else
__declspec(naked) void MovAndStoreRetJmp(void) {
    __asm {
        mov     eax, 0x00b4d00f
        and     eax, 0xfffe0000
        mov     dword ptr [g_dispatchSave1401], eax
        ret
    }
}
#endif
