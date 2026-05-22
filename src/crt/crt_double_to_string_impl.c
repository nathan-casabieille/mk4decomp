/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004cce40 (139b crt) - tm-struct fill + string copy helper:
 *   Calls DoubleToLongDouble_004cced0(esp, esp+0x2c); reads 3 fields, calls CrtFloatConvert_004ceb80;
 *   fills output struct (offsets 0,4,8,c) with values; strcpy-style memcpy.
 */
extern void CrtFloatConvert_004ceb80(void);
extern void DoubleToLongDouble_004cced0(void);

__declspec(naked) void* CrtDoubleToStringImpl_004cce40(void) {
    __asm {
        sub     esp, 0x28
        lea     eax, [esp + 0x2c]
        _emit   8dh
        _emit   4ch
        _emit   24h
        _emit   00h
        push    ebx
        push    esi
        push    edi
        push    eax
        push    ecx
        call    DoubleToLongDouble_004cced0
        add     esp, 8
        lea     edx, [esp + 0x18]
        mov     ecx, dword ptr [esp + 0x0c]
        push    edx
        push    0
        push    0x11
        mov     edx, dword ptr [esp + 0x1c]
        sub     esp, 0xc
        mov     eax, esp
        mov     dword ptr [eax], ecx
        mov     cx, word ptr [esp + 0x2c]
        mov     dword ptr [eax + 4], edx
        mov     word ptr [eax + 8], cx
        call    CrtFloatConvert_004ceb80
        mov     edx, dword ptr [esp + 0x58]
        lea     edi, [esp + 0x34]
        movsx   ecx, word ptr [esp + 0x30]
        mov     dword ptr [edx + 8], eax
        mov     dword ptr [edx + 4], ecx
        movsx   eax, byte ptr [esp + 0x32]
        mov     dword ptr [edx], eax
        or      ecx, 0xffffffff
        xor     eax, eax
        add     esp, 0x18
        repne   scasb
        mov     eax, dword ptr [esp + 0x44]
        not     ecx
        sub     edi, ecx
        mov     ebx, ecx
        mov     esi, edi
        mov     edi, eax
        shr     ecx, 2
        rep     movsd
        mov     ecx, ebx
        and     ecx, 3
        rep     movsb
        pop     edi
        mov     dword ptr [edx + 0x0c], eax
        pop     esi
        mov     eax, edx
        pop     ebx
        add     esp, 0x28
        ret
    }
}

