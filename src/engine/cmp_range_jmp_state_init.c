/**
 * Auto-split from misc_matchesNN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_pendingNodeType;

/* @addr 0x00436250 (85b)
 *   load g_table_00535ddc; if <= 0x30000 jmp T1 else jmp T2;
 *   nop * 5; call F; if zero: inc g_state_004d57ac; set walk=2;
 *     push 0x004335f0 onto stack[idx*4]; jmp T3;
 *   else: ret; nop; jmp T4.
 */
extern unsigned int g_state_00535ddc_nn;
extern void func_00433b60(void);
extern void func_00438f30(void);
extern int func_00439890(void);
extern void HitReactionStateCluster_004335f0(void);
extern void func_00471200(void);
extern void func_00436290(void);
/* @addr 0x00436250 (27b): if state_ddc > 0x30000 tail-jmp func_00433b60,
 * else tail-jmp func_00438f30. Entry A of the original 85-byte packed
 * block; entries B (call + mstack-push) and C (single tail-jmp) live in
 * func_00436270 / func_004362a0. The 5-byte nop gap is filled by 0x90-fill. */
void CmpRangeJmpStateInit_00436250(void) {
    int v = (int)g_state_00535ddc_nn;
    g_walkCallback = (void (*)(void))v;
    if (v > 0x30000) {
        func_00433b60();
        return;
    }
    func_00438f30();
}
