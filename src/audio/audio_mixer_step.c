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

/* @addr 0x004ab700 (73b)
 *   Audio mixer step: eax = [0x4d5100] + [0x4d5104]; sar 31 (sign);
 *   eax % 0x10000; pushes ecx, eax; calls helper. Stores running
 *   sum back, low-16 to walk.
 */
extern unsigned int g_data_004d5100;
extern unsigned int g_data_004d5104;
extern unsigned int g_data_0053814c;
extern void Mul10Tail_00404af0(int, int);
__declspec(naked) void AudioMixerStep_004ab700(void) {
    __asm {
        mov     eax, dword ptr [g_data_004d5100]
        mov     edx, dword ptr [g_data_004d5104]
        mov     ecx, dword ptr [g_walkCallback]
        add     eax, edx
        push    esi
        mov     esi, eax
        sar     esi, 0x1f
        mov     dword ptr [g_data_004d5100], eax
        add     esi, eax
        and     eax, 0xffff
        add     edx, esi
        push    eax
        push    ecx
        mov     dword ptr [g_data_0053814c], ecx
        mov     dword ptr [g_data_004d5104], edx
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        pop     esi
        ret
    }
}
