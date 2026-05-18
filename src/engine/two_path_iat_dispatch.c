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

#pragma optimize("y", off)
/* @addr 0x004c7030 */
void TwoPathIATDispatch_004c7030(int a, int b) {
    if (a < 0x14) {
        Lock_004c6f50(a + 0x1c);
        return;
    }
    ((void (__stdcall *)(int))g_iat_004d2140)(b + 0x20);
}

/* @addr 0x004c70a0 */
void TwoPathIATDispatch_004c70a0(int a, int b) {
    if (a < 0x14) {
        Lock_004c6f50(a + 0x1c);
        return;
    }
    ((void (__stdcall *)(int))g_iat_004d213c)(b + 0x20);
}
