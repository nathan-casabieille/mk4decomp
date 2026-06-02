/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0046a1e0 (65b)
 *   set 0xa → walk; call F; pause → ret;
 *   load g_fightGroupHead, g_player1NodeIdx; cmp; set 0x26 (or 0x27 if !eq); jmp T.
 */
extern void SpecialAnimBuilder(void);
extern void TableLookupCall_g_table_004efa00(void);
void Set0xaCmpEqSet0x26Jmp(void) {
    g_walkCallback = (void(*)(void))0x0a;
    SpecialAnimBuilder();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))0x26;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_walkCallback = (void(*)(void))0x27;
    }
    TableLookupCall_g_table_004efa00();
}
