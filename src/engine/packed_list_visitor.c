/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x004b5c90 (80b)
 *   Walks a packed list at 0x7b41a0 (entries 12+ bytes each):
 *   each entry's first dword has top-2-bit flag (0xc0000000 →
 *   skip) and a 24-bit "next-offset". When passing target arg,
 *   match if 0xff (any) or if (entry.tag6bit) == arg.
 *   Calls helper(entry+0xc) on match. Loops until offset
 *   exceeds 0xab4194.
 */
extern unsigned int g_data_007b41a0;
extern void Mem_Free_004b5b10(void *);
__declspec(naked) void PackedListVisitor_004b5c90(void) {
    __asm {
        push    esi
        push    edi
        mov     edi, dword ptr [esp + 0x0c]
        mov     esi, OFFSET g_data_007b41a0
loop_top:
        mov     eax, dword ptr [esi]
        test    eax, 0xc0000000
        _emit   75h
        _emit   28h
        cmp     edi, -1
        _emit   74h
        _emit   0ah
        shr     eax, 0x18
        and     eax, 0x3f
        cmp     edi, eax
        _emit   75h
        _emit   19h
        mov     eax, dword ptr [esi + 4]
        test    eax, eax
        _emit   74h
        _emit   06h
        mov     eax, dword ptr [eax]
        test    eax, eax
        _emit   75h
        _emit   03h
        lea     eax, [esi + 0x0c]
        push    eax
        call    Mem_Free_004b5b10
        add     esp, 4
        mov     eax, dword ptr [esi]
        and     eax, 0xffffff
        add     esi, eax
        cmp     esi, 0x00ab4194
        jb      loop_top
        pop     edi
        pop     esi
        ret
    }
}
