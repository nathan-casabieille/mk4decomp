/**
 * 2 "forwarding stub with prepended literal pointer" helpers (24b).
 *
 * Pattern:
 *   mov     eax, [esp+8]            ; arg2
 *   mov     ecx, [esp+4]            ; arg1
 *   push    LITERAL                 ; per-helper data ptr
 *   push    eax
 *   push    ecx
 *   call    SharedImpl
 *   add     esp, 12
 *   ret
 *
 * Two-arg trampolines that prepend a per-helper data pointer
 * (different table addresses) and forward to a shared 3-arg
 * implementation at 0x004ccb10.
 */

extern int func_004ccb10(void *table, int a, int b);
extern void *g_table_00522bc0;
extern void *g_table_00522bd8;

/* @addr 0x004ccce0 */
__declspec(naked) void ForwardWithLiteral_004ccce0(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        mov     ecx, dword ptr [esp + 4]
        push    OFFSET g_table_00522bc0
        push    eax
        push    ecx
        call    func_004ccb10
        add     esp, 12
        ret
    }
}

/* @addr 0x004ccd00 */
__declspec(naked) void ForwardWithLiteral_004ccd00(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        mov     ecx, dword ptr [esp + 4]
        push    OFFSET g_table_00522bd8
        push    eax
        push    ecx
        call    func_004ccb10
        add     esp, 12
        ret
    }
}
