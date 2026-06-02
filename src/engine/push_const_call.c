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

extern int __cdecl MStackAngleWrapDispatch_0048b800(int);
extern int __cdecl LockIterTwoPath_004c6a20(int);
extern int __cdecl Lock(int);
extern int __cdecl TableLookupIatCall(int);

/* @addr 0x0048bac0 */
void PushConstCall_0048bac0(void) {
    MStackAngleWrapDispatch_0048b800(1);
}

/* @addr 0x004c6a10 */
void PushConstCall_004c6a10(void) {
    LockIterTwoPath_004c6a20(1);
}

/* @addr 0x004c6920 */
void PushConstCall_004c6920(void) {
    Lock(0xd);
}

/* @addr 0x004c6930 */
void PushConstCall_004c6930(void) {
    TableLookupIatCall(0xd);
}
