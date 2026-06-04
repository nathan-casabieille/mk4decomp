/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

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
extern unsigned int g_dispatchSave1163;
extern unsigned int g_dispatchSave1164;
extern unsigned int g_dispatchSave404;
extern void Mul10Tail(int, int);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void AudioMixerStep(void)

{
  undefined4 uVar1;
  
  uVar1 = g_walkCallback;
  g_dispatchSave1163 = g_dispatchSave1163 + (int)g_dispatchSave1164;
  g_dispatchSave1164 = g_dispatchSave1164 + (int)(g_dispatchSave1163 + ((int)g_dispatchSave1163 >> 0x1f));
  g_dispatchSave404 = g_walkCallback;
  g_walkCallback = (uint)g_dispatchSave1163 & 0xffff;
  g_walkCallback = Mul10Tail(uVar1,(uint)g_dispatchSave1163 & 0xffff);
  return;
}
#else
__declspec(naked) void AudioMixerStep(void) {
    __asm {
        mov     eax, dword ptr [g_dispatchSave1163]
        mov     edx, dword ptr [g_dispatchSave1164]
        mov     ecx, dword ptr [g_walkCallback]
        add     eax, edx
        push    esi
        mov     esi, eax
        sar     esi, 0x1f
        mov     dword ptr [g_dispatchSave1163], eax
        add     esi, eax
        and     eax, 0x0000ffff
        add     edx, esi
        push    eax
        push    ecx
        mov     dword ptr [g_dispatchSave404], ecx
        mov     dword ptr [g_dispatchSave1164], edx
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        pop     esi
        ret
    }
}
#endif
