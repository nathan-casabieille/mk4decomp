/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004d03c0 (51b)
 *   string convert: each digit '0'..'9' becomes 0..9 in place;
 *   semicolon (';') triggers a memmove-left tail to remove that char and continue.
 */
__declspec(naked) void StringDigitConvert_004d03c0(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
loop_a:
        mov     al,  byte  ptr [ecx]
        test    al, al
        _emit   74h
        _emit   13h
        cmp     al, 0x30
        _emit   7ch
        _emit   10h
        cmp     al, 0x39
        _emit   7fh
        _emit   0ch
        sub     al, 0x30
        mov     byte ptr [ecx], al
loop_inc:
        inc     ecx
        mov     al,  byte  ptr [ecx]
        test    al, al
        _emit   75h
        _emit   0edh
        ret
        cmp     al, 0x3b
        _emit   75h
        _emit   0f4h
        mov     eax, ecx
shift_loop:
        mov     dl,  byte  ptr [eax + 1]
        mov     byte ptr [eax], dl
        mov     dl,  byte  ptr [eax + 1]
        inc     eax
        test    dl, dl
        _emit   75h
        _emit   0f3h
        _emit   0ebh
        _emit   0e4h
    }
}
