/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004c5cf0 (117b boot) - lazy stream init+open:
 *   calls helpers to lock and reset, then either points eax at the
 *   per-handle entry in g_x_00fa0de0 (if fd valid) or at the global
 *   stdfile slot 0x005222e0. Clears bit 1 of the flag byte, calls
 *   IOWrapper(fd,0,0), then RangePathIATDispatch_004c7060 on the FILE.
 */
extern unsigned int g_x_00fa0de0;
extern void FFlushImpl_004c69a0(void);
extern void IOWrapper_004c8dd0(void);
extern void RangePathIATDispatch_004c6ff0(void);
extern void RangePathIATDispatch_004c7060(void);

__declspec(naked) void Helper_FOpenPostInit(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        push    edi
        push    esi
        mov     edi, dword ptr [esi + 0x10]
        call    RangePathIATDispatch_004c6ff0
        add     esp, 4
        push    esi
        call    FFlushImpl_004c69a0
        mov     ecx, dword ptr [esi + 0xc]
        add     esp, 4
        and     ecx, 0xffffffcf
        cmp     edi, -1
        mov     dword ptr [esi + 0xc], ecx
        je      useStd
        mov     ecx, edi
        mov     eax, edi
        sar     ecx, 5
        and     eax, 0x1f
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [ecx*4 + g_x_00fa0de0]
        lea     eax, [eax + edx*4]
        jmp     gotEntry
useStd:
        mov     eax, 0x005222e0
gotEntry:
        mov     dl, byte ptr [eax + 4]
        and     dl, 0xfd
        mov     byte ptr [eax + 4], dl
        mov     eax, dword ptr [esi + 0xc]
        test    al, 0x80
        je      callIO
        and     al, 0xfc
        mov     dword ptr [esi + 0xc], eax
callIO:
        push    0
        push    0
        push    edi
        call    IOWrapper_004c8dd0
        add     esp, 0xc
        push    esi
        call    RangePathIATDispatch_004c7060
        add     esp, 4
        pop     edi
        pop     esi
        ret
    }
}

