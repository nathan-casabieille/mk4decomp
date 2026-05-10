/**
 * 3 "iterate scaled-ptr + load + tail-jmp" helpers (36 bytes each).
 *
 * Pattern:
 *   mov     eax, [esp+4]              ; packed_ptr arg
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax  ; save packed
 *   mov     ecx, [eax*4 + 0]          ; deref via SIB+0 trick
 *   inc     eax                       ; step packed by 1 (= +4 bytes)
 *   mov     [g_scaledInit_*], ecx     ; install loaded value
 *   mov     [g_eventQueueTotal], eax  ; save advanced packed
 *   jmp     Target
 *
 * Iterator step that loads one dword off the packed pointer, advances
 * the packed counter, and tail-jumps into the dispatch handler.
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_scaledInit_00542048;
extern void func_0049cbb0(void);
extern void func_0048fd60(void);
extern void func_00491080(void);

/* @addr 0x0048e680 */
__declspec(naked) void IterLoad_0048e680(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_scaledInit_00542048], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        jmp     func_0049cbb0
    }
}

/* @addr 0x0048fd30 */
__declspec(naked) void IterLoad_0048fd30(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        jmp     func_0048fd60
    }
}

/* @addr 0x00491050 */
__declspec(naked) void IterLoad_00491050(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_scaledInit_00542048], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        jmp     func_00491080
    }
}
