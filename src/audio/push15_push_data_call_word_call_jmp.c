/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1080 (35b)
 *   push    0x15
 *   push    0x004a6068        ; was 0x004a6060? actually let me decode
 *   call    F
 *   mov     ax, word ptr [0x004e2860]
 *   add     esp, 8
 *   push    eax
 *   call    F2
 *   add     esp, 4
 *   jmp     T
 */
extern int StoreTwoCall(void *p, int n);
extern int TaggedSceneDispatch(unsigned short v);
extern void *g_const_004a0060;
extern unsigned short g_word_004e2860;
extern void CallSetPause(void);
int Push15PushDataCallWordCallJmp_004a1080(void) {
    StoreTwoCall(&g_const_004a0060, 0x15);
    TaggedSceneDispatch(g_word_004e2860);
    return ((int (*)(void))CallSetPause)();
}
