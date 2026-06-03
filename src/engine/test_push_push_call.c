/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004bea50 (42b)
 *   mov     ecx, [0x00ab5754]
 *   xor     eax, eax
 *   cmp     ecx, eax
 *   jne     +1
 *   ret
 *   push    0x00ab5760
 *   push    0x00ab575c
 *   mov     [0x00ab575c], eax
 *   mov     [0x00ab5760], eax
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern unsigned int g_dispatchSave1592;
extern unsigned int g_dispatchSave1594;
extern unsigned int g_dispatchSave1595;
extern int EcmStreamTickAdvance(unsigned int *, unsigned int *);
void TestPushPushCall(void) {
    __asm {
        mov     ecx, dword ptr [g_dispatchSave1592]
        xor     eax, eax
        cmp     ecx, eax
        _emit   75h
        _emit   01h
        ret
        push    OFFSET g_dispatchSave1595
        push    OFFSET g_dispatchSave1594
        mov     dword ptr [g_dispatchSave1594], eax
        mov     dword ptr [g_dispatchSave1595], eax
        call    EcmStreamTickAdvance
        add     esp, 8
        }
}
