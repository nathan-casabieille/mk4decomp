/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b5a10 (84b engine.geo) - fill 0x7b01a0..0x7b41a0 (16KB) with
 *   DoubleToInt64(cos(i*const3)*const2 - const4) per slot. Two FP consts
 *   loaded once before loop; one call to CrtPowCluster_004c6540 in prologue.
 */
extern unsigned int g_buf_007b01a0;
extern unsigned int g_fp_004d29d0;
extern unsigned int g_fp_004d29d8;
extern unsigned int g_fp_004d29e0;
extern unsigned int g_fp_004d29e8;
extern void CrtPowCluster_004c6540(void);
extern void DoubleToInt64_004c57d0(void);

__declspec(naked) void AppInit_PostJoy(void) {
    __asm {
        push    ecx
        fld     qword ptr [g_fp_004d29d0]
        fld     qword ptr [g_fp_004d29d8]
        push    esi
        mov     dword ptr [esp + 4], 0
        call    CrtPowCluster_004c6540
        mov     esi, offset g_buf_007b01a0
loop4b5a10:
        fild    dword ptr [esp + 4]
        fmul    qword ptr [g_fp_004d29e0]
        fcos
        fmul    st(0), st(1)
        fsub    qword ptr [g_fp_004d29e8]
        call    DoubleToInt64_004c57d0
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

