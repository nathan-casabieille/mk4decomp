/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1163;
extern unsigned int g_dispatchSave1164;
extern unsigned int g_dispatchSave404;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1163 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5100u))
#define g_dispatchSave1164 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5104u))
#define g_dispatchSave404 (*(unsigned int *)MK4_VA(unsigned int, 0x53814cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

extern void Mul10Tail(int, int);

#ifdef NON_MATCHING
/* Portable twin - VERIFIED via verify_coexec (2 writes match the original). */
void AudioMixerStep(void)

{
  undefined4 uVar1;
  
  uVar1 = g_walkCallback;
  g_dispatchSave1163 = g_dispatchSave1163 + (int)g_dispatchSave1164;
  g_dispatchSave1164 = g_dispatchSave1164 + (int)(g_dispatchSave1163 + ((int)g_dispatchSave1163 >> 0x1f));
  g_dispatchSave404 = g_walkCallback;
  g_walkCallback = (uint)g_dispatchSave1163 & 0xffff;
  /* Mul10Tail is declared void (matching side ignores eax) but returns a value
   * here; cast to a returning fn-ptr to capture it. See feedback_cast_to_int_fnptr. */
  g_walkCallback = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)
                       (uVar1, (uint)g_dispatchSave1163 & 0xffff);
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
