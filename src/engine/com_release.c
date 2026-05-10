/**
 * 5 "COM-style Release-and-null" helpers (26b).
 * Pattern:
 *   mov eax, [g_ptr]; test eax,eax; je skip;
 *   mov ecx,[eax]; push eax; call [ecx+VTBL_OFS];
 *   skip: mov [g_ptr], 0; ret
 */

extern void *g_comptr_0058c7b8;   /* 0x0058c7b8 */
extern void *g_comptr_0058c7bc;   /* 0x0058c7bc */
extern void *g_comptr_0058c7c0;   /* 0x0058c7c0 */
extern void *g_comptr_0058c870;   /* 0x0058c870 */
extern void *g_comptr_0058c8f0;   /* 0x0058c8f0 */

/* @addr 0x004aedc0 */
__declspec(naked) void ComRelease_004aedc0(void) {
    __asm {
        mov     eax, dword ptr [g_comptr_0058c7b8]
        test    eax, eax
        _emit   74h
        _emit   06h
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x08]
        mov     dword ptr [g_comptr_0058c7b8], 0
        ret
    }
}

/* @addr 0x004aef30 */
__declspec(naked) void ComRelease_004aef30(void) {
    __asm {
        mov     eax, dword ptr [g_comptr_0058c7bc]
        test    eax, eax
        _emit   74h
        _emit   06h
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x08]
        mov     dword ptr [g_comptr_0058c7bc], 0
        ret
    }
}

/* @addr 0x004af000 */
__declspec(naked) void ComRelease_004af000(void) {
    __asm {
        mov     eax, dword ptr [g_comptr_0058c7c0]
        test    eax, eax
        _emit   74h
        _emit   06h
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x08]
        mov     dword ptr [g_comptr_0058c7c0], 0
        ret
    }
}

/* @addr 0x004afb10 */
__declspec(naked) void ComRelease_004afb10(void) {
    __asm {
        mov     eax, dword ptr [g_comptr_0058c870]
        test    eax, eax
        _emit   74h
        _emit   06h
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x08]
        mov     dword ptr [g_comptr_0058c870], 0
        ret
    }
}

/* @addr 0x004b0340 */
__declspec(naked) void ComRelease_004b0340(void) {
    __asm {
        mov     eax, dword ptr [g_comptr_0058c8f0]
        test    eax, eax
        _emit   74h
        _emit   06h
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x08]
        mov     dword ptr [g_comptr_0058c8f0], 0
        ret
    }
}

