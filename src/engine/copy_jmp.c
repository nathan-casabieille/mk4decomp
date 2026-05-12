/**
 * 6 "copy global + tail-jmp" wrappers.
 *
 * Pattern (15 bytes):
 *   mov eax, [g_src]            ; a1 + reloc
 *   mov [g_dst], eax            ; a3 + reloc
 *   jmp Target                   ; e9 + reloc
 */
#include "engine/scenegraph.h"

/* New globals. */
extern unsigned int g_cj_00535df0;   /* 0x00535df0 */
extern unsigned int g_cj_00542054;   /* 0x00542054 */
extern unsigned int g_cj_00542058;   /* 0x00542058 */
extern unsigned int g_cj_0054205c;   /* 0x0054205c */

/* Externs for jump targets. */
extern void func_00406bb0(void);   /* 0x00406bb0 */
extern void func_0043a670(void);   /* 0x0043a670 */
extern void func_00446190(void);   /* 0x00446190 */
extern void func_0048ee90(void);   /* 0x0048ee90 */
extern void func_0048efa0(void);   /* 0x0048efa0 */

/* The wrappers. */
/* @addr 0x00406ba0 */
void CopyJmp_00406ba0(void) {
    g_currentNodeIdx = g_cj_0054205c;
    func_00406bb0();
}

/* @addr 0x0043a620 */
void CopyJmp_0043a620(void) {
    g_currentNodeIdx = g_cj_00535df0;
    func_0043a670();
}

/* @addr 0x00445ec0 */
void CopyJmp_00445ec0(void) {
    g_cj_0054205c = g_cj_00542058;
    func_00446190();
}

/* @addr 0x00446180 */
void CopyJmp_00446180(void) {
    g_cj_0054205c = g_cj_00542054;
    func_00446190();
}

/* @addr 0x0048ee80 */
void CopyJmp_0048ee80(void) {
    g_currentNodeIdx = g_cj_0054205c;
    func_0048ee90();
}

/* @addr 0x0048ef90 */
void CopyJmp_0048ef90(void) {
    g_currentNodeIdx = g_cj_0054205c;
    func_0048efa0();
}

