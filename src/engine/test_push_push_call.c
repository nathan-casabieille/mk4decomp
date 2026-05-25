/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

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
extern unsigned int g_dispatchSave1592_00ab5754;
extern unsigned int g_dispatchSave1594_00ab575c;
extern unsigned int g_dispatchSave1595_00ab5760;
extern int func_004bedd0(unsigned int *, unsigned int *);
void TestPushPushCall_004bea50(void) {
    __asm {
        mov     ecx, dword ptr [g_dispatchSave1592_00ab5754]
        xor     eax, eax
        cmp     ecx, eax
        _emit   75h
        _emit   01h
        ret
        push    OFFSET g_dispatchSave1595_00ab5760
        push    OFFSET g_dispatchSave1594_00ab575c
        mov     dword ptr [g_dispatchSave1594_00ab575c], eax
        mov     dword ptr [g_dispatchSave1595_00ab5760], eax
        call    func_004bedd0
        add     esp, 8
        }
}
