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

/* @addr 0x004a1b00 (74b)
 *   Input poll: if (byte_4d50b8 & 0x02) → 1;
 *               if (byte_4d50b4 & 0x40) → 1;
 *               if (byte_4d50b8 & 0x01) → 1;
 *               if (byte_4d50b4 & 0x10) → 1;
 *               if (byte_4d50b4 & 0x20) → 1;
 *               else (byte_4d50b8 & 0x04) >> 2 (0 or 1).
 */
extern unsigned char g_byte_004d50b8;
extern unsigned char g_byte_004d50b4;
void InputPollFlagBits_004a1b00(void) {
    __asm {
        mov     al, byte ptr [g_byte_004d50b8]
        test    al, 2
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        mov     cl, byte ptr [g_byte_004d50b4]
        test    cl, 0x40
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    al, 1
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    cl, 0x10
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    cl, 0x20
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        movsx   eax, al
        and     eax, 4
        shr     eax, 2
        }
}
