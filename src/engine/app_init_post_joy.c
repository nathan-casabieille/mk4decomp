/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004b5a10 (84b engine.geo) - fill 0x7b01a0..0x7b41a0 (16KB) with
 *   DoubleToInt64(cos(i*const3)*const2 - const4) per slot. Two FP consts
 *   loaded once before loop; one call to CrtPowCluster in prologue.
 */
extern unsigned int g_buf_007b01a0;
extern unsigned int g_fpSinTableBaseTwo;
extern unsigned int g_fpSinTableExp28;
extern unsigned int g_fpRadianPerBam;
extern unsigned int g_fpRoundBiasNegHalf;
extern void CrtPowCluster(void);
extern void DoubleToInt64(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void AppInit_PostJoy(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int local_4;
  
  local_4 = 0;
  CrtPowCluster();
  puVar2 = &g_buf_007b01a0;
  do {
    fcos((float10)local_4 * (float10)g_fpRadianPerBam);
    uVar1 = __ftol();
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
    local_4 = local_4 + 1;
  } while ((int)puVar2 < 0x7b41a0);
  return;
}
#else
__declspec(naked) void AppInit_PostJoy(void) {
    __asm {
        push    ecx
        fld     qword ptr [g_fpSinTableBaseTwo]
        fld     qword ptr [g_fpSinTableExp28]
        push    esi
        mov     dword ptr [esp + 4], 0
        call    CrtPowCluster
        mov     esi, offset g_buf_007b01a0
loop4b5a10:
        fild    dword ptr [esp + 4]
        fmul    qword ptr [g_fpRadianPerBam]
        fcos
        fmul    st(0), st(1)
        fsub    qword ptr [g_fpRoundBiasNegHalf]
        call    DoubleToInt64
        mov     ecx, dword ptr [esp + 4]
        mov     dword ptr [esi], eax
        add     esi, 4
        inc     ecx
        cmp     esi, 0x007b41a0
        mov     dword ptr [esp + 4], ecx
        _emit   7ch
        _emit   0d1h
        fstp    st(0)
        pop     esi
        pop     ecx
        ret
    }
}
#endif

