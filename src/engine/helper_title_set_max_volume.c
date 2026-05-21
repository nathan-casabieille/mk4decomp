/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004c3eb0 (60b)
 *   if g_state_00f9efcc != 0:
 *     bl = clamp(arg, 0..0x64); ecx = sbyte(bl); eax = (ecx*16 + ecx)*3 = 51*ecx;
 *     ecx = (short)g_table_00f85b60[eax*8]; call vtable[edx, +0x3c](edx, ecx);
 *     g_state_00f9efec = bl.
 */
extern unsigned int *g_state_00f9efcc;
extern unsigned char g_byte_00f9efec;
extern short g_table_00f85b60[];
__declspec(naked) void Helper_TitleSetMaxVolume(void) {
    __asm {
        mov     edx, dword ptr [g_state_00f9efcc]
        test    edx, edx
        _emit   74h
        _emit   31h
        push    esi
        push    ebx
        mov     bl,  byte  ptr [esp + 0x0c]
        cmp     bl, 0x64
        _emit   76h
        _emit   02h
        mov     bl, 0x64
        movsx   ecx, bl
        mov     eax, ecx
        mov     esi, dword ptr [edx]
        shl     eax, 4
        add     eax, ecx
        lea     eax, [eax + eax*2]
        movsx   ecx, word ptr [eax*8 + g_table_00f85b60]
        push    ecx
        push    edx
        call    dword ptr [esi + 0x3c]
        mov     byte  ptr [g_byte_00f9efec], bl
        pop     ebx
        pop     esi
        ret
    }
}

