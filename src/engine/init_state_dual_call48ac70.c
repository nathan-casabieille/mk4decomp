/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;

/* @addr 0x0048ac70 (65b)
 *   init g_fightGroupHead from g_state_0052ab10, set g_eventQueueChild = 0x48acb0
 *   (callback ptr to inline ret stub at end), set g_eventQueueTotal = head+0x15;
 *   call F1; pause → ret;
 *   call F2; pause → ret; jmp T;
 *   ret; nop nop; ret  (the inline 0x48acb0 stub fits in the tail)
 */
extern unsigned int g_state_0052ab10;
extern void func_0048acb0(void);
extern void IndirectDispatchCjStore_0048ae50(void);
extern void LazyAllocOrPush_0048abe0(void);
extern void func_0041f780_zz(void);
/* @addr 0x0048ac70 (62b): state init + dual call/pause-gate chain;
 * sets g_eventQueueChild to OFFSET func_0048acb0 (the trailing inline
 * `ret` stub at offset 0x40), then primes fightGroupHead/total from
 * g_state_0052ab10. The 2-byte nop gap + 1-byte `ret` stub at the
 * function tail are filled by 0x90-fill + the existing stub in stubs.c. */
void InitStateDualCall48ac70_0048ac70(void) {
    unsigned int v = g_state_0052ab10;
    g_eventQueueChild = (unsigned int)&func_0048acb0;
    g_fightGroupHead = v;
    g_eventQueueTotal = v + 0x15;
    IndirectDispatchCjStore_0048ae50();
    if (g_framePauseFlag != 0) return;
    LazyAllocOrPush_0048abe0();
    if (g_framePauseFlag != 0) return;
    func_0041f780_zz();
}
