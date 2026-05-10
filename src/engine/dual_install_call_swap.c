/**
 * 2 "dual install + call + pause-guarded swap + tail-jmp" helpers (64b).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [g_B]
 *   mov     [g_C], eax
 *   mov     [g_D], ecx
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     edx, [g_E]
 *   mov     eax, [g_F]
 *   mov     [g_C], edx                       ; replace with E/F
 *   mov     [g_D], eax
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_xformEntityIdx;     /* 0x00542048 */
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

extern unsigned int g_dualA_00542044;     /* alias of g_scaledInit_00542044 */
extern unsigned int g_dualB_00542020;
extern unsigned int g_dualC_0054204c;     /* alias of g_pendingNodeType */
extern unsigned int g_dualD_00542050;     /* alias of g_eventQueueTotal */
extern unsigned int g_dualF_00542024;

extern unsigned int g_dualB_00538038;     /* g_gtPlayerProbe2 */
extern unsigned int g_dualB_0053803c;     /* g_gtPlayerProbe1 */
extern unsigned int g_dualA_00538158;     /* g_player1NodeIdx */
extern unsigned int g_dualA_0053815c;     /* g_player2NodeIdx */

extern void func_00489d10(void);
extern void func_00490cc0(void);

/* @addr 0x00489cd0 */
__declspec(naked) void DualInstallCallSwap_00489cd0(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_dualB_00542020]
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_eventQueueTotal], ecx
        call    func_00489d10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [g_dualF_00542024]
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_eventQueueTotal], eax
        jmp     func_00489d10
        ret
    }
}

/* @addr 0x00490c80 */
__declspec(naked) void DualInstallCallSwap_00490c80(void) {
    __asm {
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     ecx, dword ptr [g_gtPlayerProbe2]
        mov     dword ptr [g_fightGroupHead], eax
        mov     dword ptr [g_baseSel_00542060], ecx
        call    func_00490cc0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        mov     edx, dword ptr [g_player2NodeIdx]
        mov     eax, dword ptr [g_gtPlayerProbe1]
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_baseSel_00542060], eax
        jmp     func_00490cc0
        ret
    }
}
