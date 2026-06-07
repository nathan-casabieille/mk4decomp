/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004c3710 (206b engine.render) - COM object slot release/dealloc by index.
 *   arg ax = obj idx. if (idx >= 0x898) ret.
 *   edi = idx * 28 (object slot stride).
 *   if (chain[idx+0xc8 base] == 0): ret.
 *   if ([0xf9eff0] == 0): scan 4 entries; if marked, bit-2 of flag byte; jmp end-set-flag.
 *   esi = &chain[idx + 0x4f8fad4]; for i in 4..1: if (slot != 0) {
 *     call slot->vtable[0x48](slot); call slot->vtable[8](slot); slot = 0;
 *   } esi -= 4.
 *   Update [0xf9efe4] -= chain[+0xd8]; [0xf9efe8]--; [0xf9efd8]++.
 *   pop edi/esi/ebx; ret.
 *   Alt path: g_flags |= 2; pop and ret.
 */
extern unsigned int g_flags_00f8fade;
extern unsigned int g_flags_00f8fadf;
extern unsigned int g_dispatchSave1415;
extern u32 g_dsoundFieldE4;
extern u32 g_dsoundFieldE8;
extern unsigned int g_dispatchSave1417;

extern unsigned int g_obj_size;
extern unsigned int g_obj_table;
extern unsigned int g_obj_used;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Helper_AudioStop(ushort param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 < 0x898) {
    iVar2 = (int)(short)param_1;
    iVar4 = iVar2 * 0x1c;
    piVar3 = &g_audioChannelTable + iVar2 * 7;
    if ((&g_audioChannelTable)[iVar2 * 7] != 0) {
      if (g_dispatchSave1417 == 0) {
        iVar2 = 0;
        do {
          if (((*piVar3 != 0) && ((&g_flags_00f8fadf)[iVar4 + iVar2] != '\0')) &&
             (((&g_flags_00f8fade)[iVar4] & 1) == 0)) {
            (&g_flags_00f8fade)[iVar4] = (&g_flags_00f8fade)[iVar4] | 2;
            return;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar2 < 4);
      }
      piVar3 = (int *)(&g_obj_used + iVar4);
      iVar2 = 4;
      do {
        piVar1 = (int *)*piVar3;
        if (piVar1 != (int *)0x0) {
          (*(MK4ComMethod *)(*piVar1 + 0x48))(piVar1);
          (*(MK4ComMethod *)(*(int *)*piVar3 + 8))((int *)*piVar3);
          *piVar3 = 0;
        }
        piVar3 = piVar3 + -1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      g_dsoundFieldE4 = g_dsoundFieldE4 - *(int *)(&g_obj_size + iVar4);
      g_dsoundFieldE8 = g_dsoundFieldE8 + -1;
      g_dispatchSave1415 = g_dispatchSave1415 + 1;
    }
  }
  return;
}
#else
__declspec(naked) void Helper_AudioStop(void) {
    __asm {
        mov     ax, word ptr [esp + 4]
        push    ebx
        push    esi
        cmp     ax, 0x0898
        push    edi
        _emit   0fh
        _emit   83h
        _emit   0a6h
        _emit   00h
        _emit   00h
        _emit   00h
        movsx   eax, ax
        mov     edi, eax
        shl     edi, 3
        sub     edi, eax
        shl     edi, 2
        mov     eax, [edi + g_obj_table]
        lea     ecx, [edi + g_obj_table]
        test    eax, eax
        _emit   0fh
        _emit   84h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_dispatchSave1417]
        test    eax, eax
        _emit   75h
        _emit   25h
        xor     eax, eax
        mov     dl, 1
        cmp     dword ptr [ecx], 0
        _emit   74h
        _emit   13h
        mov     bl, byte ptr [eax + edi + g_flags_00f8fadf]
        test    bl, bl
        _emit   74h
        _emit   08h
        test    byte ptr [edi + g_flags_00f8fade], dl
        _emit   74h
        _emit   64h
        inc     eax
        add     ecx, 4
        cmp     eax, 4
        _emit   7ch
        _emit   0dfh
        lea     esi, [edi + g_obj_used]
        mov     ebx, 4
        mov     eax, [esi]
        test    eax, eax
        _emit   74h
        _emit   14h
        mov     ecx, [eax]
        push    eax
        call    dword ptr [ecx + 0x48]
        mov     eax, [esi]
        push    eax
        mov     edx, [eax]
        call    dword ptr [edx + 8]
        mov     dword ptr [esi], 0
        sub     esi, 4
        dec     ebx
        _emit   75h
        _emit   0e0h
        mov     eax, [edi + g_obj_size]
        mov     edx, dword ptr [g_dsoundFieldE4]
        mov     ecx, dword ptr [g_dsoundFieldE8]
        sub     edx, eax
        mov     eax, dword ptr [g_dispatchSave1415]
        dec     ecx
        inc     eax
        mov     dword ptr [g_dsoundFieldE4], edx
        mov     dword ptr [g_dsoundFieldE8], ecx
        mov     dword ptr [g_dispatchSave1415], eax
        pop     edi
        pop     esi
        pop     ebx
        ret
        mov     al, byte ptr [edi + g_flags_00f8fade]
        or      al, 2
        mov     byte ptr [edi + g_flags_00f8fade], al
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
#endif

