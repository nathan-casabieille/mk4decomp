/**
 * Third batch of miscellaneous one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404ed0 (26b): zero 3 fields at offsets 0x60/0x64/0x68 plus walkCallback */
__declspec(naked) void ZeroThreeFields_00404ed0(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        xor     ecx, ecx
        shl     eax, 2
        mov     dword ptr [eax + 0x60], ecx
        mov     dword ptr [eax + 0x64], ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x68], ecx
        ret
    }
}

/* @addr 0x0040a8b0 (26b): zero 3 fields at offsets 0x44/0x48/0x4c plus walkCallback */
__declspec(naked) void ZeroThreeFields_0040a8b0(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        xor     ecx, ecx
        shl     eax, 2
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x44], ecx
        mov     dword ptr [eax + 0x48], ecx
        mov     dword ptr [eax + 0x4c], ecx
        ret
    }
}

/* @addr 0x004066d0 (27b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     eax, [eax*4 + 4]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      ret_label
 *   jmp     +6
 *   ret
 */
extern void func_004066df(void);
__declspec(naked) void ScaledLoadGuardedJmp_004066d0(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [eax*4 + 4]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   05h
        jmp     func_004066df
        ret
    }
}

/* @addr 0x00429710 (24b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 4]
 *   dec     ecx
 *   mov     [g_eventQueueCurrent], ecx
 *   jmp     +8
 */
extern void func_00429721(void);
__declspec(naked) void ScaledLoadDecJmp_00429710(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 4]
        dec     ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        jmp     func_00429721
    }
}

/* @addr 0x00429790 (23b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x24]
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     +0x29
 */
extern void func_004297c0(void);
__declspec(naked) void ScaledLoadJmp_24_00429790(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_scaledInit_00542044], ecx
        jmp     func_004297c0
    }
}

/* @addr 0x004774d0 (25b)
 *   mov     eax, [g_pendingNodeType]
 *   mov     ecx, [eax*4 + 0]
 *   and     ecx, 0xff
 *   mov     [g_walkCallback], ecx
 *   ret
 */
__declspec(naked) void ScaledMaskByte_004774d0(void) {
    __asm {
        mov     eax, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [eax*4 + 0]
        and     ecx, 0x000000ff
        mov     dword ptr [g_walkCallback], ecx
        ret
    }
}

/* @addr 0x0048bb40 (25b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x40]
 *   shr     ecx, 0xc
 *   and     ecx, 3
 *   mov     [g_walkCallback], ecx
 *   ret
 */
__declspec(naked) void ScaledShrAnd_0048bb40(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x40]
        shr     ecx, 0x0c
        and     ecx, 3
        mov     dword ptr [g_walkCallback], ecx
        ret
    }
}

/* @addr 0x0046eaa0 (26b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x70], ecx
 *   ret
 */
extern unsigned int g_baseSel_00542060;
__declspec(naked) void ScaledMove74to70_0046eaa0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x74]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x70], ecx
        ret
    }
}

/* @addr 0x00490070 (23b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x38]
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     +9
 */
extern void func_0049008b(void);
__declspec(naked) void ScaledLoadJmp_38_00490070(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_scaledInit_00542044], ecx
        jmp     func_0049008b
    }
}

/* @addr 0x0048e7b0 (23b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   jmp     +9
 */
extern void func_0048e7cb(void);
__declspec(naked) void ScaledLoadJmp_74_0048e7b0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x74]
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_0048e7cb
    }
}

/* @addr 0x00485d70 (27b)
 *   mov     eax, [g_X1]
 *   mov     ecx, [g_X2]
 *   mov     [g_walkCallback], eax
 *   mov     [g_eventQueueCurrent], ecx
 *   jmp     +5
 */
extern unsigned int g_dual_0053a1a8;
extern unsigned int g_dual_0053a1a4;
extern void func_00485d8c(void);
__declspec(naked) void DualLoadDualStoreJmp_00485d70(void) {
    __asm {
        mov     eax, dword ptr [g_dual_0053a1a8]
        mov     ecx, dword ptr [g_dual_0053a1a4]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        jmp     func_00485d8c
    }
}

/* @addr 0x00405430 already in misc_matches2 (different file no — wait,
 * this was already added). Skip. */

/* @addr 0x00422080 (29b)
 *   mov     eax, [g_X]
 *   inc     eax
 *   cmp     eax, 9
 *   mov     [g_walkCallback], eax
 *   jle     +7
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [g_X], eax
 *   ret
 */
extern unsigned int g_counter_0053a51c;
__declspec(naked) void IncOrZero9_00422080(void) {
    __asm {
        mov     eax, dword ptr [g_counter_0053a51c]
        inc     eax
        cmp     eax, 9
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   07h
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_counter_0053a51c], eax
        ret
    }
}

/* @addr 0x00409280 (22b)
 *   mov     eax, [g_walkCallback]
 *   and     eax, 0xf
 *   shl     eax, 0x14
 *   mov     [g_walkCallback], eax
 *   mov     [g_X], eax
 *   ret
 */
extern unsigned int g_dest_0053a6e4;
__declspec(naked) void AndShlStore_00409280(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        and     eax, 0x0f
        shl     eax, 0x14
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_dest_0053a6e4], eax
        ret
    }
}

/* @addr 0x0048e4d0 (22b)
 *   mov     eax, [g_baseSel_00542060]
 *   lea     ecx, [eax + 0x22]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 4], ecx
 *   ret
 */
__declspec(naked) void LeaPlus22StoreSelf_0048e4d0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        lea     ecx, [eax + 0x22]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 4], ecx
        ret
    }
}
