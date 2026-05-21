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

/* @addr 0x004b8f50 (70b)
 *   ecx = [0xab4e2c]; edx = [0xab4e30]; eax = [0x52aac4];
 *   if ecx != edx: store ecx → [0xab4e30].
 *   if eax == 2: eax = [0x53a50c]; eax *= 3; ecx = eax*2 + 0x4f6240;
 *     store ecx → [0xab4e2c]; ret.
 *   else: edx = eax*3; eax = edx*2 + 0x4f62a8; store → [0xab4e2c]; ret.
 */
extern unsigned int g_data_00ab4e2c;
extern unsigned int g_data_00ab4e30;
extern unsigned int g_data_0053a50c;
void DispatchScaledLEA_004b8f50(void) {
    __asm {
        mov     ecx, dword ptr [g_data_00ab4e2c]
        mov     edx, dword ptr [g_data_00ab4e30]
        mov     eax, dword ptr [g_data_0052aac4]
        cmp     ecx, edx
        _emit   74h
        _emit   06h
        mov     dword ptr [g_data_00ab4e30], ecx
        cmp     eax, 2
        _emit   75h
        _emit   16h
        mov     eax, dword ptr [g_data_0053a50c]
        lea     eax, [eax + eax*2]
        lea     ecx, [eax*2 + 0x004f6240]
        mov     dword ptr [g_data_00ab4e2c], ecx
        ret
        lea     edx, [eax + eax*2]
        lea     eax, [edx*2 + 0x004f62a8]
        mov     dword ptr [g_data_00ab4e2c], eax
        }
}
