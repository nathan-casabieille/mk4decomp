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

/* @addr 0x004cd260 (73b)
 *   CRT _osfile / _osfhnd handle lookup. Returns a pointer or
 *   sets errno/EBADF on out-of-range / closed handle. The byte
 *   table at +4 records FOPEN bit (0x01).
 */
extern unsigned int g_data_00fa0ee0;
extern unsigned int g_data_00fa0de0;
extern void Crt_doserrno_004c8bb0(void);
extern void Crt_errno_004c8ba0(void);

void CRTHandleLookup_004cd260(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [g_data_00fa0ee0]
        cmp     eax, ecx
        _emit   73h
        _emit   21h
        mov     ecx, eax
        and     eax, 0x1f
        sar     ecx, 5
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [ecx*4 + g_data_00fa0de0]
        mov     cl, byte ptr [eax + edx*4 + 4]
        lea     eax, [eax + edx*4]
        test    cl, 1
        _emit   74h
        _emit   03h
        mov     eax, dword ptr [eax]
        ret
        call    Crt_errno_004c8ba0
        mov     dword ptr [eax], 9
        call    Crt_doserrno_004c8bb0
        mov     dword ptr [eax], 0
        or      eax, 0xffffffff
        }
}

