/**
 * Boot-phase miscellaneous helpers.
 *
 * Three unrelated boot-phase functions that don't fit the scaled-pushpop or
 * scaled-init categories:
 *   - StackPushAdd15CallPop: mstack-save g_eventQueueEnd, add 0x15, call, restore
 *   - PushCallScaledClearJmp: chain init w/ dirty-bit dispatch
 *   - ExtractBitsToVec3: extract three bit-fields from g_walkCallback into a vec3
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0040a7e0 (69b)
 *   push g_eventQueueEnd, add 0x15, restore at end after call.
 */
extern void Copy3Fields38_0040a870(void);
void StackPushAdd15CallPop_0040a7e0(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueEnd;
    g_eventQueueEnd = g_eventQueueEnd + 0x15;
    Copy3Fields38_0040a870();
    g_eventQueueEnd = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}

/* @addr 0x0040bf20 (66b)
 *   push 0x408040; call F; load g_fightGroupHead; push it; call F2;
 *   clear g_scaledInit; call F3; pause-test → ret;
 *   testb 4,[dirty]; if cleared then jmp T; ret.
 */
extern void *g_data_00408040;
extern void ThreeChanPackClamp_00404cc0(void *);
extern void CopyThreeFields_00404df0(int);
extern void func_00405420_ii(void);
extern void BootMStackBracketedScaledStores_0040bf70(void);
void PushCallScaledClearJmp_0040bf20(void) {
    ThreeChanPackClamp_00404cc0(&g_data_00408040);
    CopyThreeFields_00404df0(g_fightGroupHead);
    g_scaledInit_00542044 = 0;
    func_00405420_ii();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) {
        BootMStackBracketedScaledStores_0040bf70();
        return;
    }
}

/* @addr 0x00407c00 (88b)
 *   triple bit-extract from g_walkCallback: low 11 bits, mid 11 bits, high 10 bits;
 *   store each into a 3-vec at g_pendingNodeType*4 with stride 4.
 */

void ExtractBitsToVec3_00407c00(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_pendingNodeType]
        and     eax, 0x7ff
        shl     eax, 1
        mov     dword ptr [ecx*4 + 0], eax
        mov     eax, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_pendingNodeType]
        shr     eax, 0x0b
        and     eax, 0x7ff
        shl     eax, 1
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [edx*4 + 4], eax
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_pendingNodeType]
        shr     eax, 0x16
        shl     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 8], eax
        }
}

