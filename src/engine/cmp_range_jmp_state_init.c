/**
 * Auto-split from misc_matchesNN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00436250 (85b)
 *   load g_fightStateProgress; if <= 0x30000 jmp T1 else jmp T2;
 *   nop * 5; call F; if zero: inc g_matrixStackTop; set walk=2;
 *     push 0x004335f0 onto stack[idx*4]; jmp T3;
 *   else: ret; nop; jmp T4.
 */
extern unsigned int g_fightStateProgress;
extern void GuardedSeq_PackedSelectLoad6_then_GuardedSeq(void);
extern void PrefixThunkInstallSelf3State(void);
extern int Cmp2CallDirtyCall(void);
extern void HitReactionStateCluster(void);
extern void MstackPopScaledChainPlusThunks(void);
extern void Cmp30000And18000(void);
/* @addr 0x00436250 (27b): if state_ddc > 0x30000 tail-jmp GuardedSeq_PackedSelectLoad6_then_GuardedSeq,
 * else tail-jmp PrefixThunkInstallSelf3State. Entry A of the original 85-byte packed
 * block; entries B (call + mstack-push) and C (single tail-jmp) live in
 * func_Cmp2CallDirtyCall_then_MstackPopScaledChainPlusThunks / func_Cmp30000And18000. The 5-byte nop gap is filled by 0x90-fill. */
void CmpRangeJmpStateInit(void) {
    int v = (int)g_fightStateProgress;
    g_walkCallback = (void (*)(void))v;
    if (v > 0x30000) {
        GuardedSeq_PackedSelectLoad6_then_GuardedSeq();
        return;
    }
    PrefixThunkInstallSelf3State();
}
