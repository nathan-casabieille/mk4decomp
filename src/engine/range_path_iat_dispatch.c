/**
 * 2 "range-checked path with IAT call" helpers (54 bytes each).
 *
 * Pattern:
 *   push    ebp
 *   mov     ebp, esp
 *   mov     eax, [ebp+8]
 *   cmp     eax, 0x00522600
 *   jb      .iat_path
 *   cmp     eax, 0x00522860
 *   ja      .iat_path
 *   sub     eax, 0x00522600
 *   sar     eax, 5
 *   add     eax, 0x1c
 *   push    eax
 *   call    LocalFunc
 *   add     esp, 4
 *   pop     ebp
 *   ret
 * .iat_path:
 *   add     eax, 0x20
 *   push    eax
 *   call    [iat_slot]                ; ff 15 absolute indirect
 *   pop     ebp
 *   ret
 *
 * Stays naked: MSVC SP3 picks `add eax, -0x522600` (05 form) over
 * `sub eax, 0x522600` (2d form) for the imm32 subtraction. Both forms
 * are 5 bytes but different opcodes; not coaxable from C source (see
 * memory: sub-vs-add-neg).
 */

extern int Lock_004c6f50(int);
extern int TableLookupIatCall_004c6fd0(int);
extern void *g_iat_004d2140;
extern void *g_iat_004d213c;

/* @addr 0x004c6ff0 */
__declspec(naked) void RangePathIATDispatch_004c6ff0(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        mov     eax, dword ptr [ebp + 8]
        cmp     eax, 0x00522600
        _emit   72h
        _emit   1dh
        cmp     eax, 0x00522860
        _emit   77h
        _emit   16h
        sub     eax, 0x00522600
        sar     eax, 5
        add     eax, 0x1c
        push    eax
        call    Lock_004c6f50
        add     esp, 4
        pop     ebp
        ret
        add     eax, 0x20
        push    eax
        call    dword ptr [g_iat_004d2140]
        pop     ebp
        ret
    }
}

/* @addr 0x004c7060 */
__declspec(naked) void RangePathIATDispatch_004c7060(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        mov     eax, dword ptr [ebp + 8]
        cmp     eax, 0x00522600
        _emit   72h
        _emit   1dh
        cmp     eax, 0x00522860
        _emit   77h
        _emit   16h
        sub     eax, 0x00522600
        sar     eax, 5
        add     eax, 0x1c
        push    eax
        call    TableLookupIatCall_004c6fd0
        add     esp, 4
        pop     ebp
        ret
        add     eax, 0x20
        push    eax
        call    dword ptr [g_iat_004d213c]
        pop     ebp
        ret
    }
}
