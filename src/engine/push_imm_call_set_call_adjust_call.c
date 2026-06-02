/**
 * Auto-split from misc_matchesNN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00446bf0 (85b)
 *   push g_eventQueueCurrent, push 0x6666; call F; add esp 8; store eax → eventQueueCurrent;
 *   set walk = 0xf5c; call F2; pause → ret;
 *   load walk, current; walk += 0x10000; push current, push walk; store walk;
 *   call F3; add esp 8; store eax → eventQueueCurrent.
 */
extern int Mul10Tail(int, int);
extern int Mul10Tail(int, int);
extern void StoreDoubleNegPauseSubStore(void);

void PushImmCallSetCallAdjustCall(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    eax
        push    0x6666
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], 0xf5c
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   24h
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        }
}

