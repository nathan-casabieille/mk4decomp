/**
 * Small game-state one-off helpers.
 *
 * Five tiny utilities that don't belong elsewhere: dirty-flag toggle,
 * zero-init wrappers, packed-ptr add+jmp, 16-bit-arg event call, and
 * a single bit-clear on the fight-group entry's flag-field.
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004296c0 (17b)
 *   mov     eax, [g_xformDirtyFlags]
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   jmp     +0xf
 */
extern void func_004296d4(void);
void DirtyOrJmp_004296c0(void) {
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
    func_004296d4();
}

/* @addr 0x00421c20 (18b)
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [g_X1], eax
 *   mov     [g_X2], eax
 *   ret
 */
extern unsigned int g_zerotriple_00541de8;
extern unsigned int g_zerotriple_00541dec;
void ZeroTriple_00421c20(void) {
    g_walkCallback        = 0;
    g_zerotriple_00541de8 = 0;
    g_zerotriple_00541dec = 0;
}

/* @addr 0x0044ccd0 (18b)
 *   mov     eax, [g_baseSel_00542060]
 *   add     eax, 0x0f
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     +0xe
 */
extern void func_0044cce2(void);
void Add0fJmp_0044ccd0(void) {
    g_scaledInit_00542044 = g_baseSel_00542060 + 0x0f;
    func_0044cce2();
}

/* @addr 0x00489f50 (16b)
 *   mov     ax, word ptr [g_lit16_00542074]
 *   push    eax
 *   call    Func
 *   add     esp, 4
 *   ret
 */
extern unsigned short g_lit16_00542074;
extern int TaggedSceneDispatch_004be690(unsigned short);
void Push16Call_00489f50(void) {
    TaggedSceneDispatch_004be690(g_lit16_00542074);
}

/* @addr 0x00490130 (14b)
 *   mov     eax, [g_fightGroupHead]
 *   and     dword ptr [eax*4 + 0x34], -5     ; clear bit 2
 *   ret
 */
void ClearBit2x34_00490130(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->state_mask &= ~4u;
}
