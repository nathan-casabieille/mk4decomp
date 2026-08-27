/**
 * 3 "scaled-base SAR + tail-jmp" wrappers.
 *
 * Distinct from src/engine/scaled_init.c which uses SHR. These three
 * use SAR (arithmetic shift), so the encoded byte differs:
 *   c1 e8 02  shr eax, 2
 *   c1 f8 02  sar eax, 2
 *
 * Pattern (18 bytes total):
 *   mov eax, ADDR_OF_TABLE
 *   sar eax, 2
 *   mov [g_scaledBase], eax
 *   jmp Target
 */
#include "engine/scenegraph.h"

extern void InstallSelfMStackPushDispatch(void);
extern void IntroComboFsmCluster(void);

/* Table-base externs - referenced only by `&` so the linker emits a
 * DIR32 reloc into the imm32 slot; that keeps `addr >> 2` from being
 * constant-folded and lets MSVC SP3 /O2 emit the runtime shift. */
extern unsigned int g_orphanTbl_004e4780;   /* 0x004e4780 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_sceneInitBlob_004e56d8;   /* 0x004e56d8 */
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_eventQueueEnd (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_sceneInitBlob_004e56d8 (*(unsigned int *)MK4_VA(unsigned int, 0x4e56d8u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x004368f0 */
void ScaledAddrInit_InstallSelfMStackPushDispatch(void) {
    g_eventQueueEnd = (unsigned int)((int)MK4_UNPTR(&g_orphanTbl_004e4780) >> 2);
    InstallSelfMStackPushDispatch();
}

/* @addr 0x004677c0 */
void ScaledAddrInit_IntroComboFsmCluster_004677c0(void) {
    g_walkCallback = (void (*)(void))((int)MK4_UNPTR(&g_sceneInitBlob_004e56d8) >> 2);
    IntroComboFsmCluster();
}

/* @addr 0x004677e0 */
void ScaledAddrInit_IntroComboFsmCluster_004677e0(void) {
    g_walkCallback = (void (*)(void))((int)MK4_UNPTR(&g_sceneInitBlob_004e56d8) >> 2);
    IntroComboFsmCluster();
}
