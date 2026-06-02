/**
 * 2 "call + pause + dirty-bit + literal-call" helpers (42 bytes).
 *
 * Pattern:
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte ptr [g_xformDirtyFlags], 1
 *   je      .literal_path
 *   jmp     T1
 * .literal_path:
 *   push    LITERAL
 *   call    FuncB
 *   add     esp, 4
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void *g_lit_004e44d8;
extern void *g_lit_004ef218;

extern void ScaledChain3c74Jmp(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e44f0(void);
extern int  PackedAdvanceCallTailJmp(void *p);
extern void DualCondMatchSet(void);
extern void InstallSelfChainPlusGuardedTail(void);
extern int  Cascade5StageInit(void *p);

/* @addr 0x00433910 */
void CallPauseDirtyLit_00433910(void) {
    ScaledChain3c74Jmp();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        Wrapper_PackedAdvanceCallTailJmp_004e44f0();
        return;
    }
    PackedAdvanceCallTailJmp(&g_lit_004e44d8);
}

/* @addr 0x00488c70 */
void CallPauseDirtyLit_00488c70(void) {
    DualCondMatchSet();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        InstallSelfChainPlusGuardedTail();
        return;
    }
    Cascade5StageInit(&g_lit_004ef218);
}
