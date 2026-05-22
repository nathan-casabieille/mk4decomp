/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004c5580 (104b boot) - vfprintf-style char-writer with
 *   buffered length and overflow handler: sets up a 32-byte scratch,
 *   calls printf-formatter (PendingMatch_004c7920) with cap=INT_MAX, tag=0x42;
 *   on negative residual length calls overflow helper, else writes
 *   trailing NUL.
 */
extern void Flsbuf_004c77f0(void);
extern void PendingMatch_004c7920(void);

__declspec(naked) void Helper_Sprintf(void) {
    __asm {
        sub     esp, 0x20
        mov     eax, dword ptr [esp + 0x24]
        mov     ecx, dword ptr [esp + 0x28]
        mov     dword ptr [esp + 8], eax
        _emit   89h
        _emit   44h
        _emit   24h
        _emit   00h
        lea     eax, [esp + 0x2c]
        push    esi
        push    eax
        lea     edx, [esp + 8]
        push    ecx
        push    edx
        mov     dword ptr [esp + 0x1c], 0x42
        mov     dword ptr [esp + 0x14], 0x7fffffff
        call    PendingMatch_004c7920
        mov     esi, eax
        mov     eax, dword ptr [esp + 0x14]
        add     esp, 0xc
        dec     eax
        mov     dword ptr [esp + 8], eax
        js      overflow
        mov     eax, dword ptr [esp + 4]
        mov     byte ptr [eax], 0
        mov     eax, esi
        pop     esi
        add     esp, 0x20
        ret
overflow:
        lea     ecx, [esp + 4]
        push    ecx
        push    0
        call    Flsbuf_004c77f0
        add     esp, 8
        mov     eax, esi
        pop     esi
        add     esp, 0x20
        ret
    }
}

