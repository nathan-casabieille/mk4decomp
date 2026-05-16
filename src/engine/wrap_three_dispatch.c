/**
 * 2 "wrap-3-call dispatch" helpers (55 bytes each).
 *
 * Pattern:
 *   push    esi
 *   mov     esi, [esp+0x14]
 *   push    edi
 *   push    esi
 *   call    RangePathIATDispatch_004c6ff0    ; single-arg lookup
 *   mov     eax, [esp+0x18]
 *   mov     ecx, [esp+0x14]
 *   mov     edx, [esp+0x10]
 *   add     esp, 4
 *   push    esi
 *   push    eax
 *   push    ecx
 *   push    edx
 *   call    LocalImpl                         ; 4-arg local
 *   add     esp, 0x10
 *   mov     edi, eax
 *   push    esi
 *   call    RangePathIATDispatch_004c7060    ; cleanup
 *   add     esp, 4
 *   mov     eax, edi
 *   pop     edi
 *   pop     esi
 *   ret
 */

extern void RangePathIATDispatch_004c6ff0(int);
extern void RangePathIATDispatch_004c7060(int);
extern int  Fread_004c5bb0(int a, int b, int c, int d);
extern int  FWriteNoLock_004c5fc0(int a, int b, int c, int d);

/* @addr 0x004c5b70 */
__declspec(naked) void WrapThreeDispatch_004c5b70(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 0x14]
        push    edi
        push    esi
        call    RangePathIATDispatch_004c6ff0
        mov     eax, dword ptr [esp + 0x18]
        mov     ecx, dword ptr [esp + 0x14]
        mov     edx, dword ptr [esp + 0x10]
        add     esp, 4
        push    esi
        push    eax
        push    ecx
        push    edx
        call    Fread_004c5bb0
        add     esp, 0x10
        mov     edi, eax
        push    esi
        call    RangePathIATDispatch_004c7060
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        ret
    }
}

/* @addr 0x004c5f80 */
__declspec(naked) void WrapThreeDispatch_004c5f80(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 0x14]
        push    edi
        push    esi
        call    RangePathIATDispatch_004c6ff0
        mov     eax, dword ptr [esp + 0x18]
        mov     ecx, dword ptr [esp + 0x14]
        mov     edx, dword ptr [esp + 0x10]
        add     esp, 4
        push    esi
        push    eax
        push    ecx
        push    edx
        call    FWriteNoLock_004c5fc0
        add     esp, 0x10
        mov     edi, eax
        push    esi
        call    RangePathIATDispatch_004c7060
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        ret
    }
}
