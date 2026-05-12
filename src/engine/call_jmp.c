/**
 * 2 "call X then tail-jmp Y" helpers (10 bytes each).
 *
 * Pattern:
 *   call    FuncA
 *   jmp     FuncB
 *
 * Wrapper that runs A for its side effect, then immediately
 * tail-jumps into B.
 */

extern void func_0041fcf0(void);
extern void func_0043bdd0(void);
extern void func_004bd590(void);
extern void func_004bd6d0(void);

/* @addr 0x00467d30 */
void CallJmp_00467d30(void) {
    func_0041fcf0();
    func_0043bdd0();
}

/* @addr 0x004bd990 */
void CallJmp_004bd990(void) {
    func_004bd590();
    func_004bd6d0();
}
