/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ab700 (73b)
 *   Audio mixer step: load d0/d4/walk, sum=d0+d4, sign=sar 31,
 *   store sum, adj=sign+sum, low16=sum&0xffff, d4new=d4+adj,
 *   push low16/walk, store walk/d4new/low16, call helper, store ret.
 */
/*
 * NON-COAXABLE: push esi comes at byte 19, after 3 loads + add eax,edx
 * (Eurocom late-push style). MSVC /O2 places callee-saves right before
 * first register use; with esi used for sign/adj, the earliest MSVC
 * can defer push esi is after 2 loads (byte 11) - not past an add.
 */
extern unsigned int g_dispatchSave1163_004d5100;
extern unsigned int g_dispatchSave1164_004d5104;
extern unsigned int g_dispatchSave404_0053814c;
extern void Mul10Tail_00404af0(int, int);

__declspec(naked) void AudioMixerStep_004ab700(void) {
    __asm {
        mov     eax, dword ptr [g_dispatchSave1163_004d5100]
        mov     edx, dword ptr [g_dispatchSave1164_004d5104]
        mov     ecx, dword ptr [g_walkCallback]
        add     eax, edx
        push    esi
        mov     esi, eax
        sar     esi, 0x1f
        mov     dword ptr [g_dispatchSave1163_004d5100], eax
        add     esi, eax
        and     eax, 0x0000ffff
        add     edx, esi
        push    eax
        push    ecx
        mov     dword ptr [g_dispatchSave404_0053814c], ecx
        mov     dword ptr [g_dispatchSave1164_004d5104], edx
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        pop     esi
        ret
    }
}
