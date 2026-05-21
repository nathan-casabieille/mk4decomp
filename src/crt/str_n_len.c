/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004cd920 (47b)
 *   strnlen(arg, n): scan up to n bytes for NUL; return offset or n.
 */
__declspec(naked) void StrNLen_004cd920(void) {
    __asm {
        mov     edx, dword ptr [esp + 8]
        push    esi
        mov     esi, dword ptr [esp + 8]
        test    edx, edx
        push    edi
        mov     eax, esi
        lea     ecx, [edx - 1]
        _emit   74h
        _emit   0dh
loop_b:
        cmp     byte ptr [eax], 0
        _emit   74h
        _emit   08h
        inc     eax
        mov     edi, ecx
        dec     ecx
        test    edi, edi
        _emit   75h
        _emit   0f3h
done:
        cmp     byte ptr [eax], 0
        _emit   75h
        _emit   05h
        sub     eax, esi
        pop     edi
        pop     esi
        ret
        pop     edi
        pop     esi
        mov     eax, edx
        ret
    }
}
