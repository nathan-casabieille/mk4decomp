/**
 * Call + pause-check + scaled decrement dispatcher.
 *
 * Naked because of dec-flag preservation across store
 * (`dec ecx; mov [g], ecx; js`).
 */
#include "engine/scenegraph.h"

/* @addr 0x00429750 (56b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x29
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x28]
 *   dec     ecx
 *   mov     [g_eventQueueCurrent], ecx
 *   js      +5
 *   jmp     -0x88
 *   mov     [g_eventQueueCurrent], 0
 *   jmp     -0x57
 *   ret
 */
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void func_004296d8(void);
extern void func_004296fb(void);
extern u32 g_framePauseFlag;

__declspec(naked) void CallPauseScaledDecJmp_00429750(void) {
    __asm {
        call    GuardedChainCmpDualBitXor_004299a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_cpsdj_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x28]
        dec     ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        js      short L_cpsdj_neg
        jmp     func_004296d8
L_cpsdj_neg:
        mov     dword ptr [g_eventQueueCurrent], 0
        jmp     func_004296fb
L_cpsdj_ret:
        ret
    }
}
