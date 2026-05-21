/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004cbaf0 (58b)
 *   indexed-bit test: returns true if a bit is set in g_byte_00f9f8c1[eax]
 *   masked by cl, OR if (g_word_005229a2[eax*2] & arg2) != 0; else false.
 */
extern unsigned char g_byte_00f9f8c1[];
extern unsigned short g_word_005229a2[];
void IndexedBitTest_004cbaf0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     cl,  byte  ptr [esp + 0x0c]
        and     eax, 0xff
        test    byte ptr [eax + g_byte_00f9f8c1], cl
        _emit   75h
        _emit   1fh
        mov     ecx, dword ptr [esp + 8]
        test    ecx, ecx
        _emit   74h
        _emit   10h
        xor     edx, edx
        mov     dx,  word  ptr [eax*2 + g_word_005229a2]
        mov     eax, edx
        and     eax, ecx
        _emit   0ebh
        _emit   02h
        xor     eax, eax
        test    eax, eax
        _emit   75h
        _emit   01h
        ret
        mov     eax, 1
        }
}
