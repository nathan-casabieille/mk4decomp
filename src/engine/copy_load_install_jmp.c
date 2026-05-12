/**
 * 2 "copy + scaled-load + install + tail-jmp" helpers (34 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     [g_fightGroupHead], eax
 *   mov     edx, [ecx*4 + 0x30]
 *   mov     [g_scaledInit_00542044], edx
 *   jmp     Tail
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

extern void func_00405e70(void);
extern void func_00405ca0(void);

/* @addr 0x00445ed0 */
void CopyLoadInstallJmp_00445ed0(void) {
    g_fightGroupHead = g_eventQueueIdx;
    g_scaledInit_00542044 = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x30);
    func_00405e70();
}

/* @addr 0x00446210 */
void CopyLoadInstallJmp_00446210(void) {
    g_fightGroupHead = g_eventQueueEnd;
    g_scaledInit_00542044 = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x30);
    func_00405ca0();
}
