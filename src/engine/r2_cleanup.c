/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004ad7c0 (141b engine.install) - shutdown sequence:
 *   Renderer2_EndScene_D3D, VtRelease_Modal, ReleaseVtableSlot 0..15;
 *   ComRelease 4x, DSoundBufferInit146(0), 3 more releases; if g_renderer2_initOk:
 *   SetEvent via IAT@4d2210; clear g_renderer2_initOk; ret.
 */
extern unsigned int g_iat_InvalidateRect;
extern unsigned int g_comptr_0058c7ac;
extern int g_renderer2_present_rc;
extern int g_renderer2_active;
extern int g_renderer2_initOk;
extern void ComReleaseCapture_004aeee0(void);
extern void ComReleasePair_004af440(void);
extern void ComRelease_g_comptr_0058c7b8(void);
extern void ComRelease_g_comptr_0058c7bc(void);
extern void ComRelease_g_comptr_0058c7c0(void);
extern void DSoundBufferInit146_a40(void);
extern void R2_Init4(void);
extern void DSoundDualEntryRelease(void);
extern void DualVtable8Call(void);
extern void ReleaseVtableSlots(void);
extern void Renderer2_EndScene_D3D(void);
extern void VtRelease_Modal(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void R2_Cleanup(void)

{
  int iVar1;
  
  Renderer2_EndScene_D3D();
  VtRelease_Modal();
  if (g_comptr_0058c7ac != (int *)0x0) {
    g_comret_0058c7dc = (*(MK4ComMethod *)(*g_comptr_0058c7ac + 0x28))(g_comptr_0058c7ac);
  }
  iVar1 = 0;
  do {
    ReleaseVtableSlots(iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  ComRelease_g_comptr_0058c7b8();
  DSoundDualEntryRelease();
  DualVtable8Call();
  ComRelease_g_comptr_0058c7c0();
  ComReleasePair_004af440();
  R2_Init4(0);
  ComRelease_g_comptr_0058c7bc();
  ComReleaseCapture_004aeee0();
  DSoundBufferInit146_a40();
  g_renderer2_active = 0;
  if (g_renderer2_initOk != 0) {
    InvalidateRect((HWND)0x0,(RECT *)0x0,1);
  }
  g_renderer2_initOk = 0;
  return;
}
#else
__declspec(naked) void R2_Cleanup(void) {
    __asm {
        push    esi
        call    Renderer2_EndScene_D3D
        call    VtRelease_Modal
        mov     eax, dword ptr [g_comptr_0058c7ac]
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x28]
        mov     dword ptr [g_renderer2_present_rc], eax
        xor     esi, esi
loop4ad7c0:
        push    esi
        call    ReleaseVtableSlots
        add     esp, 4
        inc     esi
        cmp     esi, 0x10
        _emit   7ch
        _emit   0f1h
        call    ComRelease_g_comptr_0058c7b8
        call    DSoundDualEntryRelease
        call    DualVtable8Call
        call    ComRelease_g_comptr_0058c7c0
        call    ComReleasePair_004af440
        push    0
        call    R2_Init4
        add     esp, 4
        call    ComRelease_g_comptr_0058c7bc
        call    ComReleaseCapture_004aeee0
        call    DSoundBufferInit146_a40
        mov     eax, dword ptr [g_renderer2_initOk]
        mov     dword ptr [g_renderer2_active], 0
        test    eax, eax
        _emit   74h
        _emit   0ch
        push    1
        push    0
        push    0
        call    dword ptr [g_iat_InvalidateRect]
        mov     dword ptr [g_renderer2_initOk], 0
        pop     esi
        ret
    }
}
#endif

