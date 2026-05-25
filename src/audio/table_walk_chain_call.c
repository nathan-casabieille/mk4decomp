/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a30f0 (48b)
 *   table-walk: esi iterates over 0x004f3260..0x004f33c8 step 0x24;
 *   reads sbyte → adds to g_baseSel_00542060 to form ecx;
 *   stores [ecx*4 + 0] into g_scaledInit; calls 0x406790; loop.
 */
extern signed char g_table_004f3260[];
extern void MStackPush2ChainLLInsert_00406790(void);

void TableWalkChainCall_004a30f0(void) {
    __asm {
        mov     esi, OFFSET g_table_004f3260
loop_start2:
        movsx   eax, byte ptr [esi]
        mov     ecx, dword ptr [g_baseSel_00542060]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4 + 0]
        mov     dword ptr [g_scaledInit_00542044], edx
        call    MStackPush2ChainLLInsert_00406790
        add     esi, 0x24
        cmp     esi, 0x004f33c8
        _emit   72h
        _emit   0d8h
        }
}

