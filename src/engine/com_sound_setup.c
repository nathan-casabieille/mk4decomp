/**
 * 2 "COM-style sound init with abs/clamp + zero-stack + vtable call" (102b).
 *
 * Pattern (decoded):
 *   mov     eax, [g_state]
 *   sub     esp, 0x28
 *   test    eax, eax
 *   push    esi
 *   push    edi
 *   je      .done              ; if no state, skip (still adjust stack)
 *   mov     esi, [esp+0x34]
 *   mov     eax, esi
 *   cdq
 *   xor     eax, edx
 *   sub     eax, edx           ; abs(esi)
 *   cmp     eax, 0x64
 *   jle     .nopush
 *   mov     esi, 0x64          ; clamp
 * .nopush:
 *   mov     ecx, 10
 *   xor     eax, eax
 *   lea     edi, [esp+8]
 *   rep     stosd              ; zero 40 bytes
 *   lea     eax, [esi + esi*4] ; 5 * clamped
 *   mov     [esp+8], 0x28
 *   mov     [esp+0x24], eax
 *   mov     eax, [g_iface]
 *   test    eax, eax
 *   mov     [esp+0x0c], 0x20
 *   je      .done
 *   mov     ecx, [eax]
 *   lea     edx, [esp+8]
 *   push    edx
 *   push    eax
 *   call    [ecx + 0x10]       ; vtable[4]
 *   mov     [g_retSlot], eax
 * .done:
 *   pop     edi
 *   pop     esi
 *   add     esp, 0x28
 *   ret
 */

extern unsigned int g_state_0058c874;
extern unsigned int g_iface_0058c870;
extern unsigned int g_retSlot_0058c878;

extern unsigned int g_state_0058c8f4;
extern unsigned int g_iface_0058c8f0;
extern unsigned int g_retSlot_0058c8f8;

/* @addr 0x004af6c0 */

__declspec(naked) void ComSoundSetup_004af6c0(void) {
    __asm {
        mov     eax, dword ptr [g_state_0058c874]
        sub     esp, 0x28
        test    eax, eax
        push    esi
        push    edi
        _emit   74h
        _emit   52h
        mov     esi, dword ptr [esp + 0x34]
        mov     eax, esi
        cdq
        xor     eax, edx
        sub     eax, edx
        cmp     eax, 0x64
        _emit   7eh
        _emit   05h
        mov     esi, 0x64
        mov     ecx, 10
        xor     eax, eax
        lea     edi, dword ptr [esp + 8]
        rep     stosd
        lea     eax, dword ptr [esi + esi*4]
        mov     dword ptr [esp + 8], 0x28
        mov     dword ptr [esp + 0x24], eax
        mov     eax, dword ptr [g_iface_0058c870]
        test    eax, eax
        mov     dword ptr [esp + 0x0c], 0x20
        _emit   74h
        _emit   10h
        mov     ecx, dword ptr [eax]
        lea     edx, dword ptr [esp + 8]
        push    edx
        push    eax
        call    dword ptr [ecx + 0x10]
        mov     dword ptr [g_retSlot_0058c878], eax
        pop     edi
        pop     esi
        add     esp, 0x28
        ret
    }
}

/* @addr 0x004afef0 */
__declspec(naked) void ComSoundSetup_004afef0(void) {
    __asm {
        mov     eax, dword ptr [g_state_0058c8f4]
        sub     esp, 0x28
        test    eax, eax
        push    esi
        push    edi
        _emit   74h
        _emit   52h
        mov     esi, dword ptr [esp + 0x34]
        mov     eax, esi
        cdq
        xor     eax, edx
        sub     eax, edx
        cmp     eax, 0x64
        _emit   7eh
        _emit   05h
        mov     esi, 0x64
        mov     ecx, 10
        xor     eax, eax
        lea     edi, dword ptr [esp + 8]
        rep     stosd
        lea     eax, dword ptr [esi + esi*4]
        mov     dword ptr [esp + 8], 0x28
        mov     dword ptr [esp + 0x24], eax
        mov     eax, dword ptr [g_iface_0058c8f0]
        test    eax, eax
        mov     dword ptr [esp + 0x0c], 0x20
        _emit   74h
        _emit   10h
        mov     ecx, dword ptr [eax]
        lea     edx, dword ptr [esp + 8]
        push    edx
        push    eax
        call    dword ptr [ecx + 0x10]
        mov     dword ptr [g_retSlot_0058c8f8], eax
        pop     edi
        pop     esi
        add     esp, 0x28
        ret
    }
}
