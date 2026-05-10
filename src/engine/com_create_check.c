/**
 * 2 "COM-style create + null-check + bool return" helpers (28 bytes).
 *
 * Pattern:
 *   push    0
 *   push    OFFSET g_ifaceSlot      ; out param
 *   push    0
 *   call    Creator
 *   mov     ecx, [g_ifaceSlot]
 *   xor     eax, eax
 *   test    ecx, ecx
 *   setne   al
 *   ret
 *
 * Calls a creator that fills g_ifaceSlot, then returns
 * (slot != NULL) as a bool.
 */

extern void *g_comptr_0058c860;
extern void *g_comptr_0058c8e0;
extern int  func_004d12cc(int a, void **out, int b);

/* @addr 0x004afb30 */
__declspec(naked) void ComCreateCheck_004afb30(void) {
    __asm {
        push    0
        push    OFFSET g_comptr_0058c860
        push    0
        call    func_004d12cc
        mov     ecx, dword ptr [g_comptr_0058c860]
        xor     eax, eax
        test    ecx, ecx
        setne   al
        ret
    }
}

/* @addr 0x004b0360 */
__declspec(naked) void ComCreateCheck_004b0360(void) {
    __asm {
        push    0
        push    OFFSET g_comptr_0058c8e0
        push    0
        call    func_004d12cc
        mov     ecx, dword ptr [g_comptr_0058c8e0]
        xor     eax, eax
        test    ecx, ecx
        setne   al
        ret
    }
}
