/**
 * Eighth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00413360 (19b): push 0x8d; push DATA_PTR; call F; add esp,8; ret */
extern int __cdecl func_0049cb38(void *, int);
extern void *g_data_00413490;
void Push8d_Push413490_00413360(void) {
    func_0049cb38(&g_data_00413490, 0x8d);
}

/* @addr 0x00413560 (19b): push 0x8e; push DATA_PTR; call F; add esp,8; ret */
extern void *g_data_00413690;
void Push8e_Push413690_00413560(void) {
    func_0049cb38(&g_data_00413690, 0x8e);
}

/* @addr 0x0041d550 (16b): push 0; push DATA_PTR; call F; add esp,8; ret */
extern int __cdecl func_0049eb40(void *, int);
extern void *g_data_0041d7d0;
void Push0_Push41d7d0_0041d550(void) {
    func_0049eb40(&g_data_0041d7d0, 0);
}

/* @addr 0x00421c40 (16b): push 0x71; push DATA_PTR; call F; add esp,8; ret */
extern void StoreTwoCall_0049cb40(int, int);
extern void *g_data_0048caa0;
void Push71_Push48caa0_00421c40(void) {
    StoreTwoCall_0049cb40(&g_data_0048caa0, 0x71);
}

/* @addr 0x00463070 (20b): push 0; push 0x00463220; call F; add esp,8; jmp +0x0c */
extern int func_0049cb40_b(int, void *);
extern void *g_data_00463220;
extern void func_0046308c(void);
void Push0_Push463220_Jmp_00463070(void) {
    func_0049cb40_b((int)&g_data_00463220, 0);
    func_0046308c();
}

/* @addr 0x00489220 (23b): push 0x267; push DATA; call F; add esp,8; jmp -0xc7 */
extern int func_0049cb40_c(int, void *);
extern void *g_data_0044eb60;
extern void func_0048915f(void);
void Push267_Push44eb60_Jmp_00489220(void) {
    func_0049cb40_c((int)&g_data_0044eb60, 0x267);
    func_0048915f();
}

/* @addr 0x00478120 (25b): two arg+call pairs then jmp
 *   push    0x2b
 *   call    F
 *   add     esp, 4
 *   push    0x2c
 *   call    F
 *   add     esp, 4
 *   jmp     +7
 */
extern int SaveCallRestore_004049d0(int);
extern void func_00478131(void);
void TwoCallJmp_00478120(void) {
    SaveCallRestore_004049d0(0x2b);
    SaveCallRestore_004049d0(0x2c);
    func_00478131();
}

/* @addr 0x0043d580 (14b)
 *   push    0x004e5120
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int func_00459500(void *);
extern void *g_data_004e5120;
extern void func_0043d590(void);
void PushCallRetNopJmp_0043d580(void) {
    func_00459500(&g_data_004e5120);
}

/* @addr 0x0043d590 (5b) tail-jmp wrapper to CountdownStoreCallChain_0043d5a0
 * (resolved via the func_0043d590 alias in extras_map -> 0x43d5a0). */
void TailJmpTo_0043d5a0(void) {
    func_0043d590();
}

/* @addr 0x004ab670 (21b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +6
 *   inc     dword ptr [g_walkCallback]
 *   ret
 */
extern void StorePauseImulShr16_004ab630(void);
void CallPauseInc_004ab670(void) {
    StorePauseImulShr16_004ab630();
    if (g_framePauseFlag == 0) {
        g_walkCallback = (void (*)(void))((unsigned int)g_walkCallback + 1);
    }
}

/* @addr 0x0049cb40 (28b)
 *   mov     eax, [esp+8]
 *   mov     [g_eventQueueWorkType], eax
 *   mov     eax, [esp+4]
 *   push    eax
 *   mov     [g_pendingNodeType], eax
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int func_0049f280(int);
void StoreTwoCall_0049cb40(int arg1, int arg2) {
    g_eventQueueWorkType = arg2;
    g_pendingNodeType = arg1;
    func_0049f280(arg1);
}

/* @addr 0x004abfc0 (27b)
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, eax
 *   and     eax, 0x00ffffff
 *   shr     ecx, 0x18
 *   mov     [g_eventQueueCurrent], ecx
 *   mov     [g_xformEntityIdx], eax
 *   ret
 */
extern packed_ptr g_xformEntityIdx;
void SplitHi8Lo24_004abfc0(void) {
    unsigned int v = g_eventQueueCurrent;
    g_eventQueueCurrent = v >> 24;
    g_xformEntityIdx = v & 0x00ffffff;
}

/* @addr 0x004b5450 (18b)
 *   mov     eax, [esp+4]
 *   push    eax
 *   call    [iat]
 *   shr     eax, 0xf
 *   and     eax, 1
 *   ret
 */
extern unsigned int (__stdcall *g_iat_004d21c0)(int);
int Helper_JoyButtonInit(int arg) {
    return (g_iat_004d21c0(arg) >> 15) & 1;
}

/* @addr 0x004bd510 (22b)
 *   mov     eax, [g_scaledInit_00542044]
 *   lea     ecx, [eax*4 + 0x48]
 *   push    ecx
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int func_004bd524(void *);
void LeaScaledCall_004bd510(void) {
    func_004bd524((void *)(g_scaledInit_00542044 * 4 + 0x48));
}

/* @addr 0x004bd570 (21b)
 *   push    4
 *   call    F1
 *   add     esp, 4
 *   push    2
 *   call    F1
 *   add     esp, 4
 *   ret
 */
extern int __cdecl func_00444c98(int);
void Helper_GeoLoadPre(void) {
    func_00444c98(4);
    func_00444c98(2);
}
