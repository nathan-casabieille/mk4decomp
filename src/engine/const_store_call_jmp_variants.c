/**
 * Auto-split from misc_matches4.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
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
extern void ChainDirtyBitWalker(void);
extern void DualScaledLoadStoreJmp(void);
void ConstStoreCallJmp_ChainDirtyBitWalker_then_DualScaledLoadStoreJmp(void) {
    g_walkCallback = (void(*)(void))3;
    ChainDirtyBitWalker();
    if (g_framePauseFlag) return;
    DualScaledLoadStoreJmp();
}

/* @addr 0x0046ff60 (30b): same shape, value=4 */
extern void ByteWordTableTaggedDispatch(void);
extern void Phase3PackedInstallSelf(void);
void ConstStoreCallJmp_ByteWordTableTaggedDispatch_then_Phase3PackedInstallSelf(void) {
    g_walkCallback = (void(*)(void))4;
    ByteWordTableTaggedDispatch();
    if (g_framePauseFlag) return;
    Phase3PackedInstallSelf();
}
