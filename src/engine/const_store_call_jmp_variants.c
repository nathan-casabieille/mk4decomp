/**
 * Auto-split from misc_matches4.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00448fa0 (30b)
 *   mov     [g_walkCallback], 3
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   jmp     Tail
 *   ret
 */
extern void ChainDirtyBitWalker_00408c10(void);
extern void DualScaledLoadStoreJmp_00475790(void);
void ConstStoreCallJmp_00448fa0(void) {
    g_walkCallback = (void(*)(void))3;
    ChainDirtyBitWalker_00408c10();
    if (g_framePauseFlag) return;
    DualScaledLoadStoreJmp_00475790();
}

/* @addr 0x0046ff60 (30b): same shape, value=4 */
extern void ByteWordTableTaggedDispatch_0048a050(void);
extern void Phase3PackedInstallSelf_0046ff80(void);
void ConstStoreCallJmp_0046ff60(void) {
    g_walkCallback = (void(*)(void))4;
    ByteWordTableTaggedDispatch_0048a050();
    if (g_framePauseFlag) return;
    Phase3PackedInstallSelf_0046ff80();
}
