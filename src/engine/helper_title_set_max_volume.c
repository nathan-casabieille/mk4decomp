/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"

/* @addr 0x004c3eb0 (60b)
 *   if g_dsoundPrimary != 0:
 *     bl = clamp(arg, 0..0x64); ecx = sbyte(bl); eax = (ecx*16 + ecx)*3 = 51*ecx;
 *     ecx = (short)g_audioFrameTbl[eax*8]; call vtable[edx, +0x3c](edx, ecx);
 *     g_dispatchSave1416 = bl.
 */
extern void * g_dsoundPrimary;
extern unsigned char g_audioChannelCount;
extern short g_audioFrameTbl[];

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Helper_TitleSetMaxVolume(byte param_1)

{
  if (g_dsoundPrimary != (int *)0x0) {
    if (100 < param_1) {
      param_1 = 100;
    }
    (*(MK4ComMethod *)(*g_dsoundPrimary + 0x3c))
              (g_dsoundPrimary,(int)(short)(&g_audioFrameTbl)[(char)param_1 * 0xcc]);
    g_audioChannelCount = param_1;
  }
  return;
}
#else
__declspec(naked) void Helper_TitleSetMaxVolume(void) {
    __asm {
        mov     edx, dword ptr [g_dsoundPrimary]
        test    edx, edx
        _emit   74h
        _emit   31h
        push    esi
        push    ebx
        mov     bl,  byte  ptr [esp + 0x0c]
        cmp     bl, 0x64
        _emit   76h
        _emit   02h
        mov     bl, 0x64
        movsx   ecx, bl
        mov     eax, ecx
        mov     esi, dword ptr [edx]
        shl     eax, 4
        add     eax, ecx
        lea     eax, [eax + eax*2]
        movsx   ecx, word ptr [eax*8 + g_audioFrameTbl]
        push    ecx
        push    edx
        call    dword ptr [esi + 0x3c]
        mov     byte  ptr [g_audioChannelCount], bl
        pop     ebx
        pop     esi
        ret
    }
}
#endif

