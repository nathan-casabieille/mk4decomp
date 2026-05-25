/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c82b0 (66b)
 *   CRT helper: writes a byte to a buffered FILE-like struct.
 *     arg0 (esp+4): char value
 *     arg1 (esp+8): FILE* (struct: ptr at +0, count at +4)
 *     arg2 (esp+c): int* counter to increment (or set to -1 on err)
 *   Decrement count; if went negative, fall back to flush helper.
 *   Either way, if write returned -1 store -1 at *counter, else
 *   increment *counter.
 */
extern int Flsbuf_004c77f0(void);
void WriteCharBuffered_004c82b0(void) {
    __asm {
        mov     ecx, dword ptr [esp + 8]
        mov     eax, dword ptr [ecx + 4]
        dec     eax
        mov     dword ptr [ecx + 4], eax
        _emit   78h
        _emit   14h
        mov     edx, dword ptr [ecx]
        mov     eax, dword ptr [esp + 4]
        mov     byte ptr [edx], al
        mov     edx, dword ptr [ecx]
        and     eax, 0xff
        inc     edx
        mov     dword ptr [ecx], edx
        jmp     short cont
        mov     eax, dword ptr [esp + 4]
        push    ecx
        push    eax
        call    Flsbuf_004c77f0
        add     esp, 8
cont:
        cmp     eax, -1
        _emit   75h
        _emit   07h
        mov     ecx, dword ptr [esp + 0x0c]
        mov     dword ptr [ecx], eax
        ret
        mov     eax, dword ptr [esp + 0x0c]
        inc     dword ptr [eax]
        }
}
