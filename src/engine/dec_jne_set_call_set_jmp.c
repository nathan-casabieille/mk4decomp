/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004389b0 (48b)
 *   mov     eax, [g_eventQueueChild]
 *   dec     eax
 *   mov     [g_eventQueueChild], eax
 *   jne     +0x22
 *   mov     [g_walkCallback], 0x18
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0a
 *   mov     [g_eventQueueChild], 0x0d
 *   ret
 */
extern void func_004385f4(void);
void DecJneSetCallSetJmp_004389b0(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        _emit   75h
        _emit   22h
        mov     dword ptr [g_walkCallback], 0x18
        call    func_004385f4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ah
        mov     dword ptr [g_eventQueueChild], 0x0d
        }
}
