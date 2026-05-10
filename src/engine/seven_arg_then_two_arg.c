/**
 * 2 "7-arg call + 2-arg cleanup" wrappers (56 bytes each).
 *
 * Pattern:
 *   mov     eax, [esp+8]
 *   sub     esp, 0xc                   ; reserve 12 bytes scratch
 *   lea     ecx, [esp+0x14]            ; addr of 2nd arg slot
 *   lea     edx, [esp]                 ; addr of scratch
 *   push    0
 *   push    0
 *   push    0
 *   push    0
 *   push    eax
 *   push    ecx
 *   push    edx
 *   call    SharedSetup                ; 7-arg
 *   mov     eax, [esp+0x2c]            ; result
 *   add     esp, 0x1c                  ; remove 7 pushes
 *   lea     ecx, [esp]
 *   push    eax
 *   push    ecx
 *   call    Forwarder                  ; per-helper 2-arg
 *   add     esp, 8
 *   add     esp, 0xc                   ; release scratch
 *   ret
 */

extern int func_004ce3f0(int a, int b, int c, int d, int e, int f, int g);
extern int ForwardWithLiteral_004ccce0(int a, int b);
extern int ForwardWithLiteral_004ccd00(int a, int b);

/* @addr 0x004ccd20 */
__declspec(naked) void SevenArgThenTwoArg_004ccd20(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        sub     esp, 0x0c
        lea     ecx, dword ptr [esp + 0x14]
        _emit   8dh
        _emit   54h
        _emit   24h
        _emit   00h
        push    0
        push    0
        push    0
        push    0
        push    eax
        push    ecx
        push    edx
        call    func_004ce3f0
        mov     eax, dword ptr [esp + 0x2c]
        add     esp, 0x1c
        _emit   8dh
        _emit   4ch
        _emit   24h
        _emit   00h
        push    eax
        push    ecx
        call    ForwardWithLiteral_004ccce0
        add     esp, 8
        add     esp, 0x0c
        ret
    }
}

/* @addr 0x004ccd60 */
__declspec(naked) void SevenArgThenTwoArg_004ccd60(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        sub     esp, 0x0c
        lea     ecx, dword ptr [esp + 0x14]
        _emit   8dh
        _emit   54h
        _emit   24h
        _emit   00h
        push    0
        push    0
        push    0
        push    0
        push    eax
        push    ecx
        push    edx
        call    func_004ce3f0
        mov     eax, dword ptr [esp + 0x2c]
        add     esp, 0x1c
        _emit   8dh
        _emit   4ch
        _emit   24h
        _emit   00h
        push    eax
        push    ecx
        call    ForwardWithLiteral_004ccd00
        add     esp, 8
        add     esp, 0x0c
        ret
    }
}
