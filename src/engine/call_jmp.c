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

extern void Wrapper_OrListLoop_004de3f8(void);
extern void PendingMatch_CallPauseScaledStoreCopyJmp(void);
extern void TestCallPush4Zero(void);
extern void Helper_GeoLoadPost(void);

/* @addr 0x00467d30 */
void CallJmp(void) {
    Wrapper_OrListLoop_004de3f8();
    PendingMatch_CallPauseScaledStoreCopyJmp();
}

/* @addr 0x004bd990 */
void XformChainAdvance(void) {
    TestCallPush4Zero();
    Helper_GeoLoadPost();
}
