/**
 * Auto-split from misc_matchesEE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c6510 (45b)
 *   call F; mul-by-N pattern via lea/shl on [eax + 0x14];
 *   ((x * 13 << 4) + x) << 8 - x → effectively x * (13<<12 - 1) etc.
 *   adds 0x269ec3, stores back, returns shr 0x10 & 0x7fff.
 */
extern void *PendingMatch_004c9df0(void);
int Crt_rand(void) {
    unsigned char *p = (unsigned char *)PendingMatch_004c9df0();
    unsigned int v = *(unsigned int *)(p + 0x14) * 214013u + 0x269ec3u;
    *(unsigned int *)(p + 0x14) = v;
    return (int)((v >> 16) & 0x7fff);
}

/* @addr 0x004c67f0 (48b)
 *   if (g_fnptr_0051ffd8) (*g_fnptr_0051ffd8)();
 *   call 0x4c6940(0x4d501c, 0x4d5024); add esp 8;
 *   call 0x4c6940(0x4d5000, 0x4d5018); add esp 8; ret.
 */
extern void (*g_fnptr_0051ffd8)(void);
extern int IterFnPtrs(void *, void *);
extern void *g_dispatchSave550;
extern void *g_dispatchSave549;
extern void *g_dispatchSave548;
extern void *g_dispatchSave547;
void _init_premain(void) {
    if (g_fnptr_0051ffd8) g_fnptr_0051ffd8();
    IterFnPtrs(&g_dispatchSave548, &g_dispatchSave547);
    IterFnPtrs(&g_dispatchSave550, &g_dispatchSave549);
}

/* @addr 0x004c6960 (53b)
 *   call F1(arg); if (eax != 0) return -1;
 *   if (arg.flags & 0x4000) return arg.field10 ? -1 : 0;
 *   else return 0.
 */
extern int FFlushImpl(int);
extern int FileTableClose(int);
void CallTestPushSubCall(void) {
    __asm {
        mov     esi, dword ptr [esp + 8]
        push    esi
        call    FFlushImpl
        add     esp, 4
        test    eax, eax
        _emit   74h
        _emit   05h
        or      eax, 0xffffffff
        pop     esi
        ret
        mov     eax, dword ptr [esi + 0x0c]
        test    ah, 0x40
        _emit   74h
        _emit   12h
        mov     eax, dword ptr [esi + 0x10]
        push    eax
        call    FileTableClose
        add     esp, 4
        neg     eax
        sbb     eax, eax
        pop     esi
        ret
        xor     eax, eax
        }
}
