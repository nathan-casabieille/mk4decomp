/**
 * Auto-split from misc_matchesDD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b5a80 (52b)
 *   rep stos zero-fill 0xc0000 dwords starting at 0x007b41a0;
 *   then mask + or bits, set [0x007b41a8] = 0x007b41a0 (self-link list head).
 */
extern unsigned int g_state_007b41a0;
extern unsigned int g_state_007b41a8;
__declspec(naked) void AppInit_Misc2(void) {
    __asm {
        push    edi
        mov     ecx, 0xc0000
        xor     eax, eax
        mov     edi, OFFSET g_state_007b41a0
        rep stosd
        mov     eax, dword ptr [g_state_007b41a0]
        mov     dword ptr [g_state_007b41a8], OFFSET g_state_007b41a0
        and     eax, 0xff2ffff4
        pop     edi
        or      eax, 0x002ffff4
        or      eax, 0x80000000
        mov     dword ptr [g_state_007b41a0], eax
        ret
    }
}

/* @addr 0x004c5790 (56b): set 5 vtable slots at 0x00522160..0x00522174 */
extern void *g_iat_00522160;
extern void *g_iat_00522164;
extern void *g_iat_00522168;
extern void *g_iat_0052216c;
extern void *g_iat_00522170;
extern void *g_iat_00522174;
extern void func_004c8940(void);
extern void func_004c84e0(void);
extern void func_004c8570(void);
extern void func_004c8480(void);
extern void func_004c8550(void);
void SetVtable5Slots_004c5790(void) {
    void *fn = (void *)func_004c8940;
    g_iat_00522164 = (void *)func_004c84e0;
    g_iat_00522160 = fn;
    g_iat_00522168 = (void *)func_004c8570;
    g_iat_0052216c = (void *)func_004c8480;
    g_iat_00522170 = (void *)func_004c8550;
    g_iat_00522174 = fn;
}
