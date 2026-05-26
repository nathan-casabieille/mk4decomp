/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b7160 (73b)
 *   Tokenizer: walks string at *arg0, finds first ':' (sets flag),
 *   then for each char after the ':', writes the next char from
 *   arg1 (or ' ' if arg1 is empty). Effectively a one-shot
 *   substitute-after-delim helper.
 */
__declspec(naked) void Menu_FillColonField(void) {
    __asm {
        push    ebp
        mov     ebp, dword ptr [esp + 8]
        push    esi
        xor     esi, esi
        mov     ecx, dword ptr [ebp + 0]
        xor     eax, eax
        cmp     byte ptr [ecx], 0
        _emit   74h
        _emit   34h
        push    edi
        mov     edi, dword ptr [esp + 0x14]
loop_top:
        cmp     byte ptr [eax + ecx*1], 0x3a
        _emit   75h
        _emit   0ch
        test    esi, esi
        _emit   75h
        _emit   0ch
        mov     esi, 1
        inc     eax
        _emit   0ebh
        _emit   12h
        test    esi, esi
        _emit   74h
        _emit   0eh
        mov     dl, byte ptr [edi]
        test    dl, dl
        _emit   74h
        _emit   03h
        inc     edi
        _emit   0ebh
        _emit   02h
        mov     dl, 0x20
        mov     byte ptr [eax + ecx*1], dl
        mov     ecx, dword ptr [ebp + 0]
        inc     eax
        cmp     byte ptr [eax + ecx*1], 0
        jne     loop_top
        pop     edi
        pop     esi
        pop     ebp
        ret
    }
}
