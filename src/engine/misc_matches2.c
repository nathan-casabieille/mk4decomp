/**
 * Second batch of miscellaneous one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x00433bf0 (19b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x6c]
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     eax
 */
__declspec(naked) void ScaledIndirectJmp_00433bf0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x6c]
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     eax
    }
}

/* @addr 0x0049c850 (19b)
 *   mov     eax, [g_eventQueueEnd]
 *   mov     eax, [eax*4 + 0x0c]
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     eax
 */
__declspec(naked) void ScaledIndirectJmp_0049c850(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [eax*4 + 0x0c]
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     eax
    }
}

/* @addr 0x00473ed0 (19b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x68]
 *   mov     [g_fightGroupHead], ecx
 *   ret
 */
__declspec(naked) void ScaledLoadStore_00473ed0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x68]
        mov     dword ptr [g_fightGroupHead], ecx
        ret
    }
}

/* @addr 0x004774b0 (19b)
 *   mov     eax, [g_pendingNodeType]
 *   mov     ecx, [g_eventQueueWorkType]
 *   mov     [eax*4 + 0], ecx          ; SIB+0 store
 *   ret
 */
__declspec(naked) void ScaledDerefStore_004774b0(void) {
    __asm {
        mov     eax, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [eax*4 + 0], ecx
        ret
    }
}

/* @addr 0x00461840 (23b)
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, [g_walkCallback]
 *   mov     [g_X], eax
 *   mov     [g_Y], ecx
 *   ret
 */
extern unsigned int g_save_0053a7d8;
extern unsigned int g_save_0053a748;
__declspec(naked) void DualSave_00461840(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [g_save_0053a7d8], eax
        mov     dword ptr [g_save_0053a748], ecx
        ret
    }
}

/* @addr 0x00487120 (24b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, 0x2005
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x74], eax
 *   ret
 */
__declspec(naked) void Const0x2005Store_00487120(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x2005
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        ret
    }
}

/* @addr 0x004871d0 (19b)
 *   cmp     [g_eventQueueChild], 5
 *   jge     +5
 *   jmp     T1
 *   jmp     T2
 */
extern void func_004ba317(void);
extern void func_00489202(void);
__declspec(naked) void CmpJmpTwoBranch_004871d0(void) {
    __asm {
        cmp     dword ptr [g_eventQueueChild], 5
        _emit   7dh
        _emit   05h
        jmp     func_004ba317
        jmp     func_00489202
    }
}

/* @addr 0x00405430 (23b)
 *   mov     eax, [g_xformDirtyFlags]
 *   mov     [g_walkCallback], 0
 *   or      al, 4
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
__declspec(naked) void ZeroAndDirty4_00405430(void) {
    __asm {
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_walkCallback], 0
        or      al, 4
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}
