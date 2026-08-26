/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004b21d0 (272b engine.app) - per-char glyph emitter for HUD text.
 *   args: (esp+8)=screen_x, (esp+0xc)=string ptr, (esp+0x10)=screen_y, (esp+0x14) bp=z, (esp+0x18) sign_flag.
 *   For each printable char (0x21..0x7e): index = c - 0x21; sprite cell pos = (idx % 28, idx / 28).
 *   Builds quad descriptor at g_dispatchSave1609..g_callocInitFlag, calls Helper_DrawCursor.
 *   Advances screen_x by 9 per char; clears g_callocInitFlag at end.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1609;
extern unsigned int g_dispatchSave1610;
extern unsigned int g_dispatchSave1611;
extern unsigned int g_dispatchSave1612;
extern unsigned int g_dispatchSave1613;
extern unsigned int g_dispatchSave1614;
extern unsigned int g_dispatchSave1615;
extern unsigned int g_dispatchSave1616;
extern unsigned int g_dispatchSave1617;
extern unsigned int g_dispatchSave1618;
extern unsigned int g_dispatchSave1619;
extern unsigned int g_callocInitFlag;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
/* g_dispatchSave1609..1619 carry their REAL widths from
 * config/global_widths.yaml: 1613..1616 are four consecutive BYTES, so a
 * 32-bit alias makes every store wipe the fields after it. */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_callocInitFlag (*(unsigned int *)MK4_VA(unsigned int, 0x7af508u))
#define g_dispatchSave1609 (*(unsigned short *)MK4_VA(unsigned short, 0x7af4e8u))
#define g_dispatchSave1610 (*(unsigned short *)MK4_VA(unsigned short, 0x7af4eau))
#define g_dispatchSave1611 (*(unsigned short *)MK4_VA(unsigned short, 0x7af4f0u))
#define g_dispatchSave1612 (*(unsigned short *)MK4_VA(unsigned short, 0x7af4f2u))
#define g_dispatchSave1613 (*(unsigned char *)MK4_VA(unsigned char, 0x7af4f4u))
#define g_dispatchSave1614 (*(unsigned char *)MK4_VA(unsigned char, 0x7af4f5u))
#define g_dispatchSave1615 (*(unsigned char *)MK4_VA(unsigned char, 0x7af4f8u))
#define g_dispatchSave1616 (*(unsigned char *)MK4_VA(unsigned char, 0x7af4f9u))
#define g_dispatchSave1617 (*(unsigned short *)MK4_VA(unsigned short, 0x7af4fau))
#define g_dispatchSave1618 (*(unsigned short *)MK4_VA(unsigned short, 0x7af4fcu))
#define g_dispatchSave1619 (*(unsigned short *)MK4_VA(unsigned short, 0x7af502u))
#endif

extern void Helper_DrawCursor(void *quad);   /* placeholder said (void) */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int Helper_DrawMenuText(int param_1,short param_2,char *param_3,char param_4,undefined2 param_5)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = *param_3;
  if (cVar1 == '\0') {
    g_callocInitFlag = 0;
    return param_1;
  }
  do {
    if ((cVar1 < '!') || (cVar1 == '\x7f')) {
      uVar2 = 0;
    }
    else {
      uVar2 = (uint)(byte)(cVar1 - 0x21);
    }
    if (uVar2 != 0) {
      g_dispatchSave1609 = (short)param_1;
      g_dispatchSave1611 = g_dispatchSave1609 + 9;
      g_dispatchSave1610 = param_2;
      g_dispatchSave1612 = param_2 + 10;
      g_dispatchSave1617 = 0;
      g_dispatchSave1618 = param_5;
      g_dispatchSave1613 = (char)((ulonglong)uVar2 % 0x1c) * '\t';
      g_dispatchSave1615 = g_dispatchSave1613 + '\t';
      g_dispatchSave1614 = (char)(uVar2 / 0x1c) * '\n';
      g_dispatchSave1616 = g_dispatchSave1614 + '\n';
      g_dispatchSave1619 = (-(ushort)(param_4 != '\0') & 3) << 7 | 0x22f;
      Helper_DrawCursor(&g_dispatchSave1609);
    }
    param_1 = param_1 + 9;
    param_3 = param_3 + 1;
    cVar1 = *param_3;
  } while (cVar1 != '\0');
  g_callocInitFlag = cVar1;
  return param_1;
}
#else
__declspec(naked) void Helper_DrawMenuText(void) {
    __asm {
        mov     eax, [esp + 0xc]
        push    esi
        mov     cl, [eax]
        test    cl, cl
        jz      L_hpc_emptyTail
        mov     esi, [esp + 8]
        push    edi
        mov     edi, [esp + 0x10]
        push    ebp
        mov     bp, word ptr [esp + 0x20]
        push    ebx
    L_hpc_loop:
        cmp     cl, 0x21
        jl      short L_hpc_zero
        cmp     cl, 0x7e
        jg      short L_hpc_zero
        sub     ecx, 0x21
        and     ecx, 0xff
        jmp     short L_hpc_check
    L_hpc_zero:
        xor     ecx, ecx
    L_hpc_check:
        test    ecx, ecx
        jz      L_hpc_advance
        lea     edx, [esi + 9]
        lea     eax, [edi + 0xa]
        mov     word ptr [g_dispatchSave1611], dx
        mov     word ptr [g_dispatchSave1612], ax
        mov     eax, ecx
        xor     edx, edx
        mov     ebx, 0x1c
        push    offset g_dispatchSave1609
        div     ebx
        mov     word ptr [g_dispatchSave1609], si
        mov     word ptr [g_dispatchSave1610], di
        mov     word ptr [g_dispatchSave1617], 0
        mov     word ptr [g_dispatchSave1618], bp
        mov     al, dl
        mov     dl, 9
        imul    dl
        mov     bl, al
        mov     eax, 0x24924925
        mul     ecx
        mov     eax, ecx
        mov     cl, 0x0a
        sub     eax, edx
        mov     byte ptr [g_dispatchSave1613], bl
        shr     eax, 1
        add     eax, edx
        add     bl, 9
        shr     eax, 4
        imul    cl
        mov     byte ptr [g_dispatchSave1614], al
        add     al, cl
        mov     byte ptr [g_dispatchSave1616], al
        mov     al, [esp + 0x24]
        neg     al
        sbb     eax, eax
        mov     byte ptr [g_dispatchSave1615], bl
        and     eax, 3
        and     eax, 3
        shl     eax, 7
        or      al, 0x0f
        or      ah, 2
        or      al, 0x20
        mov     word ptr [g_dispatchSave1619], ax
        call    Helper_DrawCursor
        add     esp, 4
    L_hpc_advance:
        mov     eax, [esp + 0x1c]
        add     esi, 9
        inc     eax
        mov     [esp + 0x1c], eax
        mov     cl, [eax]
        test    cl, cl
        jne     L_hpc_loop
        pop     ebx
        pop     ebp
        pop     edi
        mov     byte ptr [g_callocInitFlag], cl
        mov     eax, esi
        pop     esi
        ret
    L_hpc_emptyTail:
        mov     esi, [esp + 8]
        mov     byte ptr [g_callocInitFlag], 0
        mov     eax, esi
        pop     esi
        ret
    }
}
#endif

