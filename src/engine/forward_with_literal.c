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

extern int __cdecl FpExtendedToFloat_004ccb10(int a, int b, void *table);
extern void *g_table_00522bc0;
extern void *g_table_00522bd8;

/* @addr 0x004ccce0 */
int ForwardWithLiteral_004ccce0(int a, int b) {
    return FpExtendedToFloat_004ccb10(a, b, &g_table_00522bc0);
}

/* @addr 0x004ccd00 */
int ForwardWithLiteral_004ccd00(int a, int b) {
    return FpExtendedToFloat_004ccb10(a, b, &g_table_00522bd8);
}
