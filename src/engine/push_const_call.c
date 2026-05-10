/**
 * 4 "push imm + call + cleanup + ret" wrappers (11 bytes each).
 *
 * Variants:
 *   push 1; call X; add esp,4; ret   (2 stubs)
 *   push 0xd; call X; add esp,4; ret (2 stubs)
 *
 * Single-arg trampolines that pin the argument as a constant and
 * forward to a shared callee.
 */

extern int func_0048b800(int);
extern int func_004c6a20(int);
extern int func_004c6f50(int);
extern int func_004c6fd0(int);

/* @addr 0x0048bac0 */
__declspec(naked) void PushConstCall_0048bac0(void) {
    __asm {
        push    1
        call    func_0048b800
        add     esp, 4
        ret
    }
}

/* @addr 0x004c6a10 */
__declspec(naked) void PushConstCall_004c6a10(void) {
    __asm {
        push    1
        call    func_004c6a20
        add     esp, 4
        ret
    }
}

/* @addr 0x004c6920 */
__declspec(naked) void PushConstCall_004c6920(void) {
    __asm {
        push    0xd
        call    func_004c6f50
        add     esp, 4
        ret
    }
}

/* @addr 0x004c6930 */
__declspec(naked) void PushConstCall_004c6930(void) {
    __asm {
        push    0xd
        call    func_004c6fd0
        add     esp, 4
        ret
    }
}
