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

extern void InstallSelfMStackPushDispatch_00436910(void);
extern void func_004677f8(void);

/* Table-base externs - referenced only by `&` so the linker emits a
 * DIR32 reloc into the imm32 slot; that keeps `addr >> 2` from being
 * constant-folded and lets MSVC SP3 /O2 emit the runtime shift. */
extern unsigned int g_table_004e4780;   /* 0x004e4780 */
extern unsigned int g_table_004e56d8;   /* 0x004e56d8 */

/* @addr 0x004368f0 */
void ScaledAddrInit_004368f0(void) {
    g_eventQueueEnd = (unsigned int)((int)&g_table_004e4780 >> 2);
    InstallSelfMStackPushDispatch_00436910();
}

/* @addr 0x004677c0 */
void ScaledAddrInit_004677c0(void) {
    g_walkCallback = (void (*)(void))((int)&g_table_004e56d8 >> 2);
    func_004677f8();
}

/* @addr 0x004677e0 */
void ScaledAddrInit_004677e0(void) {
    g_walkCallback = (void (*)(void))((int)&g_table_004e56d8 >> 2);
    func_004677f8();
}
