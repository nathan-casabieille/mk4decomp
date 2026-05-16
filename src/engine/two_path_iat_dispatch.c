/**
 * 2 "two-path arg dispatch with IAT call" helpers (40 bytes each).
 *
 * Pattern:
 *   push    ebp
 *   mov     ebp, esp
 *   mov     eax, [ebp+8]              ; first arg
 *   cmp     eax, 0x14
 *   jge     .iat_path
 *   add     eax, 0x1c
 *   push    eax
 *   call    LocalFunc
 *   add     esp, 4
 *   pop     ebp
 *   ret
 * .iat_path:
 *   mov     eax, [ebp+0x0c]           ; second arg
 *   add     eax, 0x20
 *   push    eax
 *   call    [iat_slot]                ; ff 15 absolute indirect
 *   pop     ebp
 *   ret
 */

extern int Lock_004c6f50(int);
extern void *g_iat_004d2140;
extern void *g_iat_004d213c;

/* @addr 0x004c7030 */
__declspec(naked) void TwoPathIATDispatch_004c7030(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        mov     eax, dword ptr [ebp + 8]
        cmp     eax, 0x14
        _emit   7dh
        _emit   0eh
        add     eax, 0x1c
        push    eax
        call    Lock_004c6f50
        add     esp, 4
        pop     ebp
        ret
        mov     eax, dword ptr [ebp + 0x0c]
        add     eax, 0x20
        push    eax
        call    dword ptr [g_iat_004d2140]
        pop     ebp
        ret
    }
}

/* @addr 0x004c70a0 */
__declspec(naked) void TwoPathIATDispatch_004c70a0(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        mov     eax, dword ptr [ebp + 8]
        cmp     eax, 0x14
        _emit   7dh
        _emit   0eh
        add     eax, 0x1c
        push    eax
        call    Lock_004c6f50
        add     esp, 4
        pop     ebp
        ret
        mov     eax, dword ptr [ebp + 0x0c]
        add     eax, 0x20
        push    eax
        call    dword ptr [g_iat_004d213c]
        pop     ebp
        ret
    }
}
