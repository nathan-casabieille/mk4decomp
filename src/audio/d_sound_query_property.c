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

/* @addr 0x004ac3a0 (68b)
 *   sub esp,0x10; call init helper. If non-zero result, run
 *   DirectInput-style IAT call(0x814, 0x100, &local) on
 *   g_dsoundDevice to query/test some property. Returns
 *   (~(neg eax==0))&local - i.e., result if call succeeded
 *   (eax=0) else 0.
 */
extern void Helper_AuxAudio_PostInit(void);
extern unsigned int g_dsoundDevice_005438e8;
extern unsigned int g_iat_004d2244;

void DSoundQueryProperty_004ac3a0(void) {
    __asm {
        sub     esp, 0x10
        call    Helper_AuxAudio_PostInit
        test    eax, eax
        _emit   75h
        _emit   04h
        add     esp, 0x10
        ret
        mov     ecx, dword ptr [g_dsoundDevice_005438e8]
        _emit   8dh
        _emit   44h
        _emit   24h
        _emit   00h
        push    eax
        push    0x100
        push    0x814
        push    ecx
        mov     dword ptr [esp + 0x18], 3
        call    dword ptr [g_iat_004d2244]
        mov     ecx, dword ptr [esp + 4]
        neg     eax
        sbb     eax, eax
        not     eax
        and     eax, ecx
        add     esp, 0x10
        }
}

