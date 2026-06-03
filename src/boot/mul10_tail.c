/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00404af0 (18b)
 *   mov     eax, [esp+4]
 *   mov     ecx, 0x10
 *   imul    dword ptr [esp+8]
 *   jmp     +0x0c0b5e
 */
extern void Sar64(void);
__declspec(naked) void Mul10Tail(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, 0x10
        imul    dword ptr [esp + 8]
        jmp     Sar64
    }
}
