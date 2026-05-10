/**
 * Miscellaneous one-off matches for small unmatched stubs.
 *
 * Each function here represents a unique pattern not shared with any
 * other stub in the binary. Grouped together for organizational
 * convenience.
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004049c0 (14b)
 * "Init g_matrixStackTop with packed-ptr (0x53 8168 / 4)".
 *   mov     eax, 0x00538168
 *   shr     eax, 2
 *   mov     [g_matrixStackTop], eax
 *   ret
 */
__declspec(naked) void MStackPackedInit_004049c0(void) {
    __asm {
        mov     eax, 0x00538168
        shr     eax, 2
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}

/* @addr 0x00406ce0 (19b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax*4 + 0x24], ecx
 *   ret
 */
__declspec(naked) void ScaledStoreIdx24_00406ce0(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x24], ecx
        ret
    }
}

/* @addr 0x004296c0 (17b)
 *   mov     eax, [g_xformDirtyFlags]
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   jmp     +0xf
 */
extern void func_004296d4(void);
__declspec(naked) void DirtyOrJmp_004296c0(void) {
    __asm {
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        jmp     func_004296d4
    }
}

/* @addr 0x00421c20 (18b)
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [g_X1], eax
 *   mov     [g_X2], eax
 *   ret
 */
extern unsigned int g_zerotriple_00541de8;
extern unsigned int g_zerotriple_00541dec;
__declspec(naked) void ZeroTriple_00421c20(void) {
    __asm {
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_zerotriple_00541de8], eax
        mov     dword ptr [g_zerotriple_00541dec], eax
        ret
    }
}

/* @addr 0x0044ccd0 (18b)
 *   mov     eax, [g_baseSel_00542060]
 *   add     eax, 0x0f
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     +0xe
 */
extern void func_0044cce2(void);
__declspec(naked) void Add0fJmp_0044ccd0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        add     eax, 0x0f
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     func_0044cce2
    }
}

/* @addr 0x00489f50 (16b)
 *   mov     ax, word ptr [g_lit16_00542074]
 *   push    eax
 *   call    Func
 *   add     esp, 4
 *   ret
 */
extern unsigned int g_lit16_00542074;   /* alias of g_eventQueueWorkType (16-bit read) */
extern int func_004be690(int);
__declspec(naked) void Push16Call_00489f50(void) {
    __asm {
        mov     ax, word ptr [g_lit16_00542074]
        push    eax
        call    func_004be690
        add     esp, 4
        ret
    }
}

/* @addr 0x00490130 (14b)
 *   mov     eax, [g_fightGroupHead]
 *   and     dword ptr [eax*4 + 0x34], -5     ; clear bit 2
 *   ret
 */
__declspec(naked) void ClearBit2x34_00490130(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        and     dword ptr [eax*4 + 0x34], -5
        ret
    }
}
