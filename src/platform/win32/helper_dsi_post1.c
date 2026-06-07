/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004c4110 (252b platform.win32) - DirectSound buffer create+release dispatcher.
 *   Reads IDirectSound* from g_dsoundPrimary (return if null).
 *   If arg0 != 0 (init path): calls vtbl methods +0x14/+0x20/+0x1c/+0x18, sets
 *     four "owned" byte-flags (g_dispatchSave1421, _effc, _eff8, _eff4) on success.
 *   If arg0 == 0 (release path): for each owned flag, calls release vtbl +0x38,
 *     +0x44, +0x40, +0x3c; clear all four flags.
 */
extern unsigned int g_dispatchSave1406;
extern unsigned int g_dispatchSave1409;
extern unsigned int g_dispatchSave1413;
extern unsigned int g_dispatchSave1414;
extern void * g_dsoundPrimary;
extern unsigned int g_dispatchSave1418;
extern unsigned int g_dispatchSave1419;
extern unsigned int g_dispatchSave1420;
extern unsigned int g_dispatchSave1421;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Helper_DSI_post1(int param_1)

{
  int iVar1;
  
  if (g_dsoundPrimary != (int *)0x0) {
    if (param_1 != 0) {
      iVar1 = (*(MK4ComMethod *)(*g_dsoundPrimary + 0x14))(g_dsoundPrimary,&g_dispatchSave1414,0x400,0);
      g_dispatchSave1421 = '\x01' - (iVar1 != 0);
      iVar1 = (*(MK4ComMethod *)(*g_dsoundPrimary + 0x20))(g_dsoundPrimary,&g_dispatchSave1413);
      g_dispatchSave1420 = '\x01' - (iVar1 != 0);
      iVar1 = (*(MK4ComMethod *)(*g_dsoundPrimary + 0x1c))(g_dsoundPrimary,&g_dispatchSave1406);
      g_dispatchSave1419 = '\x01' - (iVar1 != 0);
      iVar1 = (*(MK4ComMethod *)(*g_dsoundPrimary + 0x18))(g_dsoundPrimary,&g_dispatchSave1409);
      g_dispatchSave1418 = '\x01' - (iVar1 != 0);
      return;
    }
    if (g_dispatchSave1421 != '\0') {
      (*(MK4ComMethod *)(*g_dsoundPrimary + 0x38))(g_dsoundPrimary,&g_dispatchSave1414);
    }
    if (g_dispatchSave1420 != '\0') {
      (*(MK4ComMethod *)(*g_dsoundPrimary + 0x44))(g_dsoundPrimary,g_dispatchSave1413);
    }
    if (g_dispatchSave1419 != '\0') {
      (*(MK4ComMethod *)(*g_dsoundPrimary + 0x40))(g_dsoundPrimary,g_dispatchSave1406);
    }
    if (g_dispatchSave1418 != '\0') {
      (*(MK4ComMethod *)(*g_dsoundPrimary + 0x3c))(g_dsoundPrimary,g_dispatchSave1409);
    }
    g_dispatchSave1421 = '\0';
    g_dispatchSave1420 = '\0';
    g_dispatchSave1419 = '\0';
    g_dispatchSave1418 = '\0';
  }
  return;
}
#else
__declspec(naked) void Helper_DSI_post1(void) {
    __asm {
        mov     eax, dword ptr [g_dsoundPrimary]
        push    ebx
        xor     ebx, ebx
        cmp     eax, ebx
        jz      L_dbd_done
        cmp     [esp + 8], ebx
        jz      L_dbd_release
        mov     ecx, [eax]
        push    ebx
        push    0x400
        push    offset g_dispatchSave1414
        push    eax
        call    dword ptr [ecx + 0x14]
        neg     eax
        sbb     eax, eax
        push    offset g_dispatchSave1413
        inc     eax
        mov     byte ptr [g_dispatchSave1421], al
        mov     eax, dword ptr [g_dsoundPrimary]
        push    eax
        mov     edx, [eax]
        call    dword ptr [edx + 0x20]
        neg     eax
        sbb     eax, eax
        push    offset g_dispatchSave1406
        inc     eax
        mov     byte ptr [g_dispatchSave1420], al
        mov     eax, dword ptr [g_dsoundPrimary]
        push    eax
        mov     ecx, [eax]
        call    dword ptr [ecx + 0x1c]
        neg     eax
        sbb     eax, eax
        push    offset g_dispatchSave1409
        inc     eax
        mov     byte ptr [g_dispatchSave1419], al
        mov     eax, dword ptr [g_dsoundPrimary]
        push    eax
        mov     edx, [eax]
        call    dword ptr [edx + 0x18]
        neg     eax
        sbb     eax, eax
        inc     eax
        mov     byte ptr [g_dispatchSave1418], al
        pop     ebx
        ret
    L_dbd_release:
        cmp     byte ptr [g_dispatchSave1421], bl
        jz      short L_dbd_r2
        mov     ecx, [eax]
        push    offset g_dispatchSave1414
        push    eax
        call    dword ptr [ecx + 0x38]
        mov     eax, dword ptr [g_dsoundPrimary]
    L_dbd_r2:
        cmp     byte ptr [g_dispatchSave1420], bl
        jz      short L_dbd_r3
        mov     ecx, dword ptr [g_dispatchSave1413]
        mov     edx, [eax]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x44]
        mov     eax, dword ptr [g_dsoundPrimary]
    L_dbd_r3:
        cmp     byte ptr [g_dispatchSave1419], bl
        jz      short L_dbd_r4
        mov     ecx, dword ptr [g_dispatchSave1406]
        mov     edx, [eax]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x40]
        mov     eax, dword ptr [g_dsoundPrimary]
    L_dbd_r4:
        cmp     byte ptr [g_dispatchSave1418], bl
        jz      short L_dbd_r_end
        mov     ecx, dword ptr [g_dispatchSave1409]
        mov     edx, [eax]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x3c]
    L_dbd_r_end:
        mov     byte ptr [g_dispatchSave1421], bl
        mov     byte ptr [g_dispatchSave1420], bl
        mov     byte ptr [g_dispatchSave1419], bl
        mov     byte ptr [g_dispatchSave1418], bl
    L_dbd_done:
        pop     ebx
        ret
    }
}
#endif

