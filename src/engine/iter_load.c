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
void IterLoad_0048e680(int arg) {
    int p = arg >> 2;
    g_eventQueueTotal = p;
    g_scaledInit_00542048 = *(unsigned int *)(p * 4);
    p++;
    g_eventQueueTotal = p;
    func_0049cbb0();
}

/* @addr 0x0048fd30 */
void IterLoad_0048fd30(int arg) {
    int p = arg >> 2;
    g_eventQueueTotal = p;
    g_scaledInit_00542044 = *(unsigned int *)(p * 4);
    p++;
    g_eventQueueTotal = p;
    func_0048fd60();
}

/* @addr 0x00491050 */
void IterLoad_00491050(int arg) {
    int p = arg >> 2;
    g_eventQueueTotal = p;
    g_scaledInit_00542048 = *(unsigned int *)(p * 4);
    p++;
    g_eventQueueTotal = p;
    func_00491080();
}
