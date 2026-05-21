/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern u32 g_eventQueueEnd;
extern u32 g_eventQueueIdx;
extern u32 g_pendingNodeType;

/* @addr 0x004923f0 (91b)
 *   inc g_state_004d57ac; push g_eventQueueCurrent; load walk;
 *   dec walk; if walk<0 jmp shift-amount path; else fall through.
 *   Computes shifted-mod via [g_state_0053a470 + ecx*4] table.
 */
extern unsigned int g_eventQueueCurrent_mm;
extern unsigned int g_state_0053a470;
__declspec(naked) void PushPopWalkDecMod_004923f0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_eventQueueCurrent_mm]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_walkCallback]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        _emit   78h
        _emit   1dh
        mov     edx, eax
        mov     eax, dword ptr [g_state_0053a470]
        lea     ecx, [edx*4 + 0]
        shr     eax, cl
        and     eax, 0x0f
        mov     dword ptr [g_eventQueueCurrent_mm], eax
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_eventQueueCurrent_mm], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}
