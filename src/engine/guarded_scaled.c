/**
 * 7 "guarded scaled-base init + tail-jmp" wrappers.
 *
 * Pattern (33 bytes):
 *   call PreFunc                              ; e8 + reloc
 *   mov eax, [g_framePauseFlag]                ; a1 ...
 *   test eax, eax
 *   jne SHORT skip                             ; 75 12
 *   mov eax, IMM                              ; b8 ...
 *   shr eax, 2
 *   mov [g_scaledBase], eax                   ; a3 ...
 *   jmp Target                                 ; e9 + reloc
 *   ret
 *
 * Pure-C equivalent: a leading void call, an if-zero guard around the
 * tail-call body that does `g_scaledBase = (unsigned)&table >> 2;
 * Target();`. The `&extern_table` reloc keeps MSVC from constant-folding
 * the shift; MSVC SP3 /O2 tail-call-optimizes the trailing void call.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"   /* g_framePauseFlag */

/* New globals. */
extern unsigned int g_gs_00542048;   /* 0x00542048 */

/* Table-base externs - &-references defeat constant-folding of `>> 2`. */
extern unsigned int g_table_004d7238;   /* 0x004d7238 */
extern unsigned int g_table_004ecaf0;   /* 0x004ecaf0 */
extern unsigned int g_table_004ecb10;   /* 0x004ecb10 */
extern unsigned int g_table_004ecb20;   /* 0x004ecb20 */
extern unsigned int g_table_004ecb28;   /* 0x004ecb28 */
extern unsigned int g_table_004ecb40;   /* 0x004ecb40 */
extern unsigned int g_table_004ecb48;   /* 0x004ecb48 */

/* Externs for call/jump targets. */
extern void PendingMatch_0040cd50(void);   /* 0x0040cd50 */
extern void LinkedListSearch_004750f0(void);   /* 0x004750f0 */
extern void TestP1ReplaceCurrent_004751c0(void);   /* 0x004751c0 */
extern void MStackPush8_004ab790(void);   /* 0x004ab790 */

/* The wrappers. */
/* @addr 0x0040cd20 */
void GuardedScaled_0040cd20(void) {
    MStackPush8_004ab790();
    if (g_framePauseFlag == 0) {
        g_eventQueueTotal = (unsigned int)&g_table_004d7238 >> 2;
        PendingMatch_0040cd50();
    }
}

/* @addr 0x00474fd0 */
void GuardedScaled_00474fd0(void) {
    TestP1ReplaceCurrent_004751c0();
    if (g_framePauseFlag == 0) {
        g_gs_00542048 = (unsigned int)&g_table_004ecaf0 >> 2;
        LinkedListSearch_004750f0();
    }
}

/* @addr 0x00475000 */
void GuardedScaled_00475000(void) {
    TestP1ReplaceCurrent_004751c0();
    if (g_framePauseFlag == 0) {
        g_gs_00542048 = (unsigned int)&g_table_004ecb10 >> 2;
        LinkedListSearch_004750f0();
    }
}

/* @addr 0x00475030 */
void GuardedScaled_00475030(void) {
    TestP1ReplaceCurrent_004751c0();
    if (g_framePauseFlag == 0) {
        g_gs_00542048 = (unsigned int)&g_table_004ecb20 >> 2;
        LinkedListSearch_004750f0();
    }
}

/* @addr 0x00475060 */
void GuardedScaled_00475060(void) {
    TestP1ReplaceCurrent_004751c0();
    if (g_framePauseFlag == 0) {
        g_gs_00542048 = (unsigned int)&g_table_004ecb28 >> 2;
        LinkedListSearch_004750f0();
    }
}

/* @addr 0x00475090 */
void GuardedScaled_00475090(void) {
    TestP1ReplaceCurrent_004751c0();
    if (g_framePauseFlag == 0) {
        g_gs_00542048 = (unsigned int)&g_table_004ecb40 >> 2;
        LinkedListSearch_004750f0();
    }
}

/* @addr 0x004750c0 */
void GuardedScaled_004750c0(void) {
    TestP1ReplaceCurrent_004751c0();
    if (g_framePauseFlag == 0) {
        g_gs_00542048 = (unsigned int)&g_table_004ecb48 >> 2;
        LinkedListSearch_004750f0();
    }
}
