/**
 * 2 "complex three-state dispatcher" helpers (115 bytes each).
 *
 * Pattern:
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte ptr [g_xformDirtyFlags], 1
 *   je      .skip_states
 *   mov     eax, [g_state1]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .skip_states
 *   mov     eax, [g_state2]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .skip_states
 *   mov     [g_state1], 2                  ; reset state1 to 2
 *   mov     [g_walkCallback], eax           ; eax is still 0 here
 *   mov     [g_state4], eax
 * .skip_states:
 *   call    Worker
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    Finalize
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     ax, word ptr [g_lit16]
 *   push    eax
 *   call    Sink
 *   add     esp, 4
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_active_0053a408;
extern unsigned int g_active_00537e88;
extern unsigned int g_state2_00541d88;
extern unsigned int g_state2_00537ea8;
extern unsigned int g_player1State;
extern unsigned int g_player2State;
extern unsigned int g_lit16_004e286c;

extern void Cmp3DirtyToggle(void);
extern void RoundWinTransition(void);
extern void StateAdd5Capped(void);
extern int  TaggedSceneDispatch(int);

/* @addr 0x0049f900 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DispatcherComplex115_Cmp3DirtyToggle_0049f900(void)

{
  Cmp3DirtyToggle();
  if (((g_framePauseFlag == 0) && (((byte)g_xformDirtyFlags & 1) != 0)) &&
     (g_walkCallback = g_active_0053a408, g_active_0053a408 == 0)) {
    g_walkCallback = g_state2_00541d88;
    if (g_state2_00541d88 == 0) {
      g_active_0053a408 = 2;
      g_player1State = g_state2_00541d88;
      RoundWinTransition();
      if (g_framePauseFlag == 0) {
        StateAdd5Capped();
        if (g_framePauseFlag == 0) {
          TaggedSceneDispatch(g_lit16_004e286c);
        }
      }
    }
  }
  return;
}
#else
__declspec(naked) void DispatcherComplex115_Cmp3DirtyToggle_0049f900(void) {
    __asm {
        call    Cmp3DirtyToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   64h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   5bh
        mov     eax, dword ptr [g_active_0053a408]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   4dh
        mov     eax, dword ptr [g_state2_00541d88]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   3fh
        mov     dword ptr [g_active_0053a408], 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_player1State], eax
        call    RoundWinTransition
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        call    StateAdd5Capped
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     ax, word ptr [g_lit16_004e286c]
        push    eax
        call    TaggedSceneDispatch
        add     esp, 4
        ret
    }
}
#endif

/* @addr 0x0049f980 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DispatcherComplex115_Cmp3DirtyToggle_0049f980(void)

{
  Cmp3DirtyToggle();
  if (((g_framePauseFlag == 0) && (((byte)g_xformDirtyFlags & 1) != 0)) &&
     (g_walkCallback = g_active_00537e88, g_active_00537e88 == 0)) {
    g_walkCallback = g_state2_00537ea8;
    if (g_state2_00537ea8 == 0) {
      g_active_00537e88 = 2;
      g_player2State = g_state2_00537ea8;
      RoundWinTransition();
      if (g_framePauseFlag == 0) {
        StateAdd5Capped();
        if (g_framePauseFlag == 0) {
          TaggedSceneDispatch(g_lit16_004e286c);
        }
      }
    }
  }
  return;
}
#else
__declspec(naked) void DispatcherComplex115_Cmp3DirtyToggle_0049f980(void) {
    __asm {
        call    Cmp3DirtyToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   64h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   5bh
        mov     eax, dword ptr [g_active_00537e88]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   4dh
        mov     eax, dword ptr [g_state2_00537ea8]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   3fh
        mov     dword ptr [g_active_00537e88], 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_player2State], eax
        call    RoundWinTransition
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        call    StateAdd5Capped
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     ax, word ptr [g_lit16_004e286c]
        push    eax
        call    TaggedSceneDispatch
        add     esp, 4
        ret
    }
}
#endif
