/**
 * 3 "COM-style Release-and-null with captured retval" helpers (31b).
 *
 * Pattern:
 *   mov eax, [g_iface]
 *   test eax, eax
 *   je skip
 *   mov ecx, [eax]
 *   push eax
 *   call [ecx + 8]                 ; vtable[2] = Release
 *   mov [g_retSlot], eax           ; capture refcount
 * skip:
 *   mov [g_iface], 0
 *   ret
 *
 * Variant of com_release.c that stores the Release return value
 * into a separate global before clearing the interface slot. The
 * je skips both the Release call and the store, but still falls
 * through to the unconditional clear.
 */

extern void *g_comptr_0058c7ac;   /* 0x0058c7ac */
extern unsigned int g_comret_0058c7dc;   /* 0x0058c7dc */
extern void *g_comptr_0058c860;   /* 0x0058c860 */
extern unsigned int g_comret_0058c878;   /* 0x0058c878 */
extern void *g_comptr_0058c8e0;   /* 0x0058c8e0 */
extern unsigned int g_comret_0058c8f8;   /* 0x0058c8f8 */

/* @addr 0x004aeee0 */
__declspec(naked) void ComReleaseCapture_004aeee0(void) {
    __asm {
        mov     eax, dword ptr [g_comptr_0058c7ac]
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x08]
        mov     dword ptr [g_comret_0058c7dc], eax
        mov     dword ptr [g_comptr_0058c7ac], 0
        ret
    }
}

/* @addr 0x004afb50 */
__declspec(naked) void ComReleaseCapture_004afb50(void) {
    __asm {
        mov     eax, dword ptr [g_comptr_0058c860]
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x08]
        mov     dword ptr [g_comret_0058c878], eax
        mov     dword ptr [g_comptr_0058c860], 0
        ret
    }
}

/* @addr 0x004b0380 */
__declspec(naked) void ComReleaseCapture_004b0380(void) {
    __asm {
        mov     eax, dword ptr [g_comptr_0058c8e0]
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x08]
        mov     dword ptr [g_comret_0058c8f8], eax
        mov     dword ptr [g_comptr_0058c8e0], 0
        ret
    }
}
