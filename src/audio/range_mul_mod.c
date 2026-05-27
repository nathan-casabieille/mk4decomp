/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ab2a0 (89b)
 * 16.16 fixed-point divide: g_walkCallback = (g_walkCallback << 16) /
 * g_eventQueueCurrent. If the divisor is 0, returns it unchanged. The
 * fast path (numerator in [-0x8000, 0x8000)) uses a 32-bit shl+idiv;
 * larger numerators take a 64-bit path (__allshl via func_004c5740 +
 * the 64-bit signed Alldiv at 0x004c5690) to avoid overflowing the
 * <<16. Both paths compute the same quotient - the "MulMod" in the old
 * name was wrong; it is a divide. Used to normalise a delta by a range
 * (e.g. the inter-fighter facing components in helper_per_player_tick).
 */
extern unsigned int g_eventQueueCurrent_mm2;
extern void func_004c5740_mm(void);
extern int Alldiv_004c5690(int, int, int, int);

__declspec(naked) void FixedDiv16_004ab2a0(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [g_eventQueueCurrent_mm2]
        test    esi, esi
        push    edi
        _emit   75h
        _emit   09h
        mov     dword ptr [g_walkCallback], esi
        pop     edi
        pop     esi
        ret
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0xffff8000
        _emit   7ch
        _emit   15h
        cmp     eax, 0x00008000
        _emit   7dh
        _emit   0eh
        shl     eax, 0x10
        cdq
        idiv    esi
        mov     dword ptr [g_walkCallback], eax
        pop     edi
        pop     esi
        ret
        cdq
        mov     ecx, 0x10
        call    func_004c5740_mm
        mov     ecx, eax
        mov     eax, esi
        mov     edi, edx
        cdq
        push    edx
        push    eax
        push    edi
        push    ecx
        call    Alldiv_004c5690
        pop     edi
        mov     dword ptr [g_walkCallback], eax
        pop     esi
        ret
    }
}
