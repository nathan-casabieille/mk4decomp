/**
 * 2 "two-gate COM call with refcount capture" helpers (39 bytes).
 *
 * Pattern:
 *   mov     eax, [g_X]
 *   test    eax, eax
 *   je      .ret
 *   call    Setup
 *   mov     eax, [g_Y]                ; iface
 *   test    eax, eax
 *   je      .ret
 *   mov     ecx, [eax]
 *   push    1
 *   push    0
 *   push    eax
 *   call    [ecx + 0x2c]              ; vtable[11]
 *   mov     [g_Z], eax                ; capture refcount
 * .ret:
 *   ret
 */

extern unsigned int g_state_0058c874;
extern unsigned int g_state_0058c8f4;
extern void *g_comptr_0058c864;
extern void *g_comptr_0058c8e4;
extern unsigned int g_comret_0058c878;
extern unsigned int g_comret_0058c8f8;

extern void Renderer3_EndScene_SW_FS(void);
extern void Renderer5_EndScene_SW_FS_Hi(void);

/* @addr 0x004af690 */
__declspec(naked) void ComTwoGateCall_004af690(void) {
    __asm {
        mov     eax, dword ptr [g_state_0058c874]
        test    eax, eax
        _emit   74h
        _emit   1dh
        call    Renderer3_EndScene_SW_FS
        mov     eax, dword ptr [g_comptr_0058c864]
        test    eax, eax
        _emit   74h
        _emit   0fh
        mov     ecx, dword ptr [eax]
        push    1
        push    0
        push    eax
        call    dword ptr [ecx + 0x2c]
        mov     dword ptr [g_comret_0058c878], eax
        ret
    }
}

/* @addr 0x004afec0 */
__declspec(naked) void ComTwoGateCall_004afec0(void) {
    __asm {
        mov     eax, dword ptr [g_state_0058c8f4]
        test    eax, eax
        _emit   74h
        _emit   1dh
        call    Renderer5_EndScene_SW_FS_Hi
        mov     eax, dword ptr [g_comptr_0058c8e4]
        test    eax, eax
        _emit   74h
        _emit   0fh
        mov     ecx, dword ptr [eax]
        push    1
        push    0
        push    eax
        call    dword ptr [ecx + 0x2c]
        mov     dword ptr [g_comret_0058c8f8], eax
        ret
    }
}
