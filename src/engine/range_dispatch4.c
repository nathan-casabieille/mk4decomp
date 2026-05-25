/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x00434ec0 (74b)
 *   push lit; call F; if pause → ret;
 *   eax = [0x535ddc]; mov walk = eax; 4-way range dispatch:
 *   if eax > 0x20000 → jmp T1, > 0x18000 → T2, > 0x10000 → T3,
 *   else → T4.
 */
extern unsigned int g_data_004e4a04;
extern unsigned int g_table_00535ddc;
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80Call_00434f90(void);
extern void InstallSelfStdChain_00435030(void);
extern void InstallSelfChainExtendCall_00434f10(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
void RangeDispatch4_00434ec0(void) {
    int v;
    QuadBlockArgInstallChain_0043a950((void *)&g_data_004e4a04);
    if (g_framePauseFlag != 0) {
        return;
    }
    v = (int)g_table_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if (v > 0x20000) {
        InstallSelfChainSet84_80Call_00434f90();
        return;
    }
    if (v > 0x18000) {
        InstallSelfStdChain_00435030();
        return;
    }
    if (v > 0x10000) {
        InstallSelfChainExtendCall_00434f10();
        return;
    }
    CallPauseTestByteJmpCalls_004390f0();
}
