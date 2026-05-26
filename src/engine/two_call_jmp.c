/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00478120 (25b): two arg+call pairs then jmp
 *   push    0x2b
 *   call    F
 *   add     esp, 4
 *   push    0x2c
 *   call    F
 *   add     esp, 4
 *   jmp     +7
 */
extern int SaveCallRestore_004049d0(int);
extern void SpawnLeftRightProps_00478140(void);
void TwoCallJmp_00478120(void) {
    SaveCallRestore_004049d0(0x2b);
    SaveCallRestore_004049d0(0x2c);
    SpawnLeftRightProps_00478140();
}
