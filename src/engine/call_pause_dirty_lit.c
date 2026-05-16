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

extern void ScaledChain3c74Jmp_0048e780(void);
extern void Wrapper_00433940(void);
extern int  PackedAdvanceCallTailJmp_004392c0(void *p);
extern void DualCondMatchSet_00488dc0(void);
extern void InstallSelfChainPlusGuardedTail_00488ca0(void);
extern int  Cascade5StageInit_00491520(void *p);

/* @addr 0x00433910 */
void CallPauseDirtyLit_00433910(void) {
    ScaledChain3c74Jmp_0048e780();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        Wrapper_00433940();
        return;
    }
    PackedAdvanceCallTailJmp_004392c0(&g_lit_004e44d8);
}

/* @addr 0x00488c70 */
void CallPauseDirtyLit_00488c70(void) {
    DualCondMatchSet_00488dc0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        InstallSelfChainPlusGuardedTail_00488ca0();
        return;
    }
    Cascade5StageInit_00491520(&g_lit_004ef218);
}
