/**
 * Post-create-window IAT-driven driver query.
 */
#include "engine/scenegraph.h"

/* @addr 0x004c4950 (75b)
 *   IAT-driven driver query: call IAT[0x4d21b8](0); if 0 -> ret.
 *   Else: load IAT[0x4d203c]; query (handle, 0xc) >= 0xf?
 *   if so query (handle, 0xe) == 1; if so call IAT[0x4d21a8](0,handle).
 *   Returns either 1 or 0 in eax.
 */
extern unsigned int g_iat_004d203c;
extern unsigned int g_iat_004d21a8;
extern unsigned int g_iat_004d21b8;

__declspec(naked) void Helper_PostCreateWindow(void) {
    __asm {
        push    esi
        push    0
        call    dword ptr [g_iat_004d21b8]
        mov     esi, eax
        test    esi, esi
        _emit   75h
        _emit   02h
        pop     esi
        ret
        push    edi
        mov     edi, dword ptr [g_iat_004d203c]
        push    0x0c
        push    esi
        call    edi
        cmp     eax, 0x0f
        _emit   7ch
        _emit   1ah
        push    0x0e
        push    esi
        call    edi
        cmp     eax, 1
        _emit   75h
        _emit   10h
        push    esi
        push    0
        mov     edi, eax
        call    dword ptr [g_iat_004d21a8]
        mov     eax, edi
        pop     edi
        pop     esi
        ret
        xor     edi, edi
        push    esi
        push    edi
        call    dword ptr [g_iat_004d21a8]
        mov     eax, edi
        pop     edi
        pop     esi
        ret
    }
}
