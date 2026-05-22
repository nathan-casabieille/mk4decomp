/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004c5520 (85b boot) - small-block malloc with lock fallback.
 *   esi = (size+0xf) & ~0xf; if (esi > g_x_00522154): HeapAlloc(g_x_00fa0ee4,0,size).
 *   Else: Lock(9); ptr = func_004c7430(esi >> 4); Unlock(9); return ptr (or 0).
 */
extern unsigned int g_iat_004d20b4;
extern unsigned int g_x_00522154;
extern unsigned int g_x_00fa0ee4;
extern void Lock_004c6f50(void);
extern void TableLookupIatCall_004c6fd0(void);
extern void func_004c7430(void);

__declspec(naked) void* SmallMalloc_004c5520(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        push    edi
        lea     esi, [eax + 0xf]
        mov     eax, dword ptr [g_x_00522154]
        and     esi, 0xfffffff0
        cmp     esi, eax
        _emit   77h
        _emit   2dh
        push    9
        call    Lock_004c6f50
        mov     ecx, esi
        add     esp, 4
        shr     ecx, 4
        push    ecx
        call    func_004c7430
        add     esp, 4
        mov     edi, eax
        push    9
        call    TableLookupIatCall_004c6fd0
        add     esp, 4
        test    edi, edi
        _emit   74h
        _emit   05h
        mov     eax, edi
        pop     edi
        pop     esi
        ret
        mov     edx, dword ptr [g_x_00fa0ee4]
        push    esi
        push    0
        push    edx
        call    dword ptr [g_iat_004d20b4]
        pop     edi
        pop     esi
        ret
    }
}

