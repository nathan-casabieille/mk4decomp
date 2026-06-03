/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004cd260 (73b)
 *   CRT _osfile / _osfhnd handle lookup. Returns a pointer or
 *   sets errno/EBADF on out-of-range / closed handle. The byte
 *   table at +4 records FOPEN bit (0x01).
 */
extern unsigned int g_dispatchSave1469;
extern unsigned int g_crtHandleTable;
extern void Crt_doserrno(void);
extern void Crt_errno(void);

void CRTHandleLookup(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [g_dispatchSave1469]
        cmp     eax, ecx
        _emit   73h
        _emit   21h
        mov     ecx, eax
        and     eax, 0x1f
        sar     ecx, 5
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [ecx*4 + g_crtHandleTable]
        mov     cl, byte ptr [eax + edx*4 + 4]
        lea     eax, [eax + edx*4]
        test    cl, 1
        _emit   74h
        _emit   03h
        mov     eax, dword ptr [eax]
        ret
        call    Crt_errno
        mov     dword ptr [eax], 9
        call    Crt_doserrno
        mov     dword ptr [eax], 0
        or      eax, 0xffffffff
        }
}

