/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004111d0 (28b): byte-gate + set g_eventQueueIdx = (0x004d5c38>>2);
 * tail-jmp func_004111fa (= PendingMatch_00411210 via extras_map). Entry A
 * of the original 50-byte packed block; sub-entry at +0x20 (func_004111f0)
 * referenced from data table at g_dispatchSave904_004d5818 in data.c. */
extern unsigned char g_byte_004f360c;
extern unsigned int g_data_004d5c20;
extern unsigned int g_data_004d5c38;
extern void func_004111fa(void);
extern void func_00411202(void);
void TestByteSelectInit_004111d0(void) {
    if (g_byte_004f360c == 0) return;
    g_eventQueueIdx = (unsigned int)&g_data_004d5c38 >> 2;
    func_004111fa();
}
