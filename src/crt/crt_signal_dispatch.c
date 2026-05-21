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

/* @addr 0x004c9750 (77b)
 *   CRT signal/setjmp dispatch: arg = -2 → IAT[0x4d2118],
 *   -3 → IAT[0x4d2110], -4 → fetch [0xf9fc20] (no IAT call);
 *   each path sets the [0xf9fadc] flag to 1 first.
 */
extern unsigned int g_data_00f9fadc;
extern unsigned int g_data_00f9fc20;
extern void *g_iat_004d2118;
extern void *g_iat_004d2110;
__declspec(naked) void CRTSignalDispatch_004c9750(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     dword ptr [g_data_00f9fadc], 0
        cmp     eax, -2
        _emit   75h
        _emit   10h
        mov     dword ptr [g_data_00f9fadc], 1
        jmp     dword ptr [g_iat_004d2118]
        cmp     eax, -3
        _emit   75h
        _emit   10h
        mov     dword ptr [g_data_00f9fadc], 1
        jmp     dword ptr [g_iat_004d2110]
        cmp     eax, -4
        _emit   75h
        _emit   0fh
        mov     eax, dword ptr [g_data_00f9fc20]
        mov     dword ptr [g_data_00f9fadc], 1
        ret
    }
}
