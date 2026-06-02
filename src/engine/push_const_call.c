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

extern int __cdecl MStackAngleWrapDispatch(int);
extern int __cdecl LockIterTwoPath(int);
extern int __cdecl Lock(int);
extern int __cdecl TableLookupIatCall(int);

/* @addr 0x0048bac0 */
void PushConstCall_MStackAngleWrapDispatch_1(void) {
    MStackAngleWrapDispatch(1);
}

/* @addr 0x004c6a10 */
void PushConstCall_LockIterTwoPath_1(void) {
    LockIterTwoPath(1);
}

/* @addr 0x004c6920 */
void PushConstCall_Lock_0xd(void) {
    Lock(0xd);
}

/* @addr 0x004c6930 */
void PushConstCall_TableLookupIatCall_0xd(void) {
    TableLookupIatCall(0xd);
}
