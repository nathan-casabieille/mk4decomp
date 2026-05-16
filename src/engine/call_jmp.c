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

extern void Wrapper_0041fcf0(void);
extern void PendingMatch_0043bdd0(void);
extern void TestCallPush4Zero_004bd590(void);
extern void Helper_GeoLoadPost(void);

/* @addr 0x00467d30 */
void CallJmp_00467d30(void) {
    Wrapper_0041fcf0();
    PendingMatch_0043bdd0();
}

/* @addr 0x004bd990 */
void CallJmp_004bd990(void) {
    TestCallPush4Zero_004bd590();
    Helper_GeoLoadPost();
}
