/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004b8f50 (70b)
 *   ecx = [0xab4e2c]; edx = [0xab4e30]; eax = [0x52aac4];
 *   if ecx != edx: store ecx → [0xab4e30].
 *   if eax == 2: eax = [0x53a50c]; eax *= 3; ecx = eax*2 + 0x4f6240;
 *     store ecx → [0xab4e2c]; ret.
 *   else: edx = eax*3; eax = edx*2 + 0x4f62a8; store → [0xab4e2c]; ret.
 */
extern unsigned int g_dispatchSave1571;
extern unsigned int g_phaseIdx;
extern unsigned int g_tickFlagF;

void DispatchScaledLEA(void) {
    __asm {
        mov     ecx, dword ptr [g_tickCurConfig]
        mov     edx, dword ptr [g_dispatchSave1571]
        mov     eax, dword ptr [g_tickFlagF]
        cmp     ecx, edx
        _emit   74h
        _emit   06h
        mov     dword ptr [g_dispatchSave1571], ecx
        cmp     eax, 2
        _emit   75h
        _emit   16h
        mov     eax, dword ptr [g_phaseIdx]
        lea     eax, [eax + eax*2]
        lea     ecx, [eax*2 + 0x004f6240]
        mov     dword ptr [g_tickCurConfig], ecx
        ret
        lea     edx, [eax + eax*2]
        lea     eax, [edx*2 + 0x004f62a8]
        mov     dword ptr [g_tickCurConfig], eax
        }
}

