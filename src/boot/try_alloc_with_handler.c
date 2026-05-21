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

/* @addr 0x004c54d0 (68b)
 *   CRT _new_handler-style malloc retry: takes (size, retry_flag).
 *   Calls SmallMalloc_004c5520(size); if NULL and retry_flag, invokes
 *   IndirectCall_004c6ec0(size) and loops back. Returns NULL if size > -32
 *   (overflow guard).
 */
extern void *SmallMalloc_004c5520(unsigned int n);
extern int IndirectCall_004c6ec0(unsigned int n);
__declspec(naked) void TryAllocWithHandler_004c54d0(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        cmp     esi, -32
        push    edi
        _emit   77h
        _emit   34h
        test    esi, esi
        _emit   75h
        _emit   05h
        mov     esi, 1
        mov     edi, dword ptr [esp + 0x10]
loop_top:
        cmp     esi, -32
        _emit   77h
        _emit   0bh
        push    esi
        call    SmallMalloc_004c5520
        add     esp, 4
        jmp     short skip_zero
        xor     eax, eax
skip_zero:
        test    eax, eax
        _emit   75h
        _emit   13h
        test    edi, edi
        _emit   74h
        _emit   0fh
        push    esi
        call    IndirectCall_004c6ec0
        add     esp, 4
        test    eax, eax
        jne     loop_top
        xor     eax, eax
        pop     edi
        pop     esi
        ret
    }
}
