/**
 * Auto-split from misc_matchesEE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
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
 *   if (g_iat_0051ffd8) (*g_iat_0051ffd8)();
 *   call 0x4c6940(0x4d501c, 0x4d5024); add esp 8;
 *   call 0x4c6940(0x4d5000, 0x4d5018); add esp 8; ret.
 */
extern void (*g_iat_0051ffd8)(void);
extern int IterFnPtrs_004c6940(void *, void *);
extern void *g_dispatchSave550_004d5000;
extern void *g_dispatchSave549_004d5018;
extern void *g_dispatchSave548_004d501c;
extern void *g_dispatchSave547_004d5024;
void _init_premain(void) {
    if (g_iat_0051ffd8) g_iat_0051ffd8();
    IterFnPtrs_004c6940(&g_dispatchSave548_004d501c, &g_dispatchSave547_004d5024);
    IterFnPtrs_004c6940(&g_dispatchSave550_004d5000, &g_dispatchSave549_004d5018);
}

/* @addr 0x004c8300 (57b)
 *   loop: call 0x4c82b0(arg1, arg2, arg3); decrement count;
 *   break if [arg3] == -1 or count == 0. Calls with raw 3 args.
 */
extern void WriteCharBuffered_004c82b0(int, int, int);
__declspec(naked) void PaddedLoopFunc_004c8300(void) {
    __asm {
        push    ebx
        push    ebp
        mov     ebp, dword ptr [esp + 0x10]
        push    esi
        mov     eax, ebp
        dec     ebp
        test    eax, eax
        push    edi
        _emit   7eh
        _emit   25h
        mov     esi, dword ptr [esp + 0x20]
        mov     edi, dword ptr [esp + 0x1c]
        mov     ebx, dword ptr [esp + 0x14]
loop_top:
        push    esi
        push    edi
        push    ebx
        call    WriteCharBuffered_004c82b0
        mov     eax, dword ptr [esi]
        add     esp, 0x0c
        cmp     eax, 0xffffffff
        _emit   74h
        _emit   07h
        mov     ecx, ebp
        dec     ebp
        test    ecx, ecx
        _emit   7fh
        _emit   0e7h
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
