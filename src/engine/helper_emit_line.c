/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b2d20 (338b engine.app) - 3D vertex transform + perspective project.
 *   Reads vertex idx ecx; applies 3x3 matrix at g_data_007af990..0x7af9a0 to
 *   (x,y,z) at g_data_007af958/95e/964[ecx]; adds translation 0x7af9a4/a8/ac.
 *   Stores transformed XYZ at [0x7af96c/78/84][ecx*4].
 *   Perspective divide: if Z > 1, scale = 0x02000000/Z; project X via
 *   scale*0x19999a (offset 0x140 = 320 center); Y via scale * 15 * 8192/65536
 *   (offset 0xf0 = 240 center). Stores screen XY (word) at 0x7af9b4/b6.
 */
extern unsigned int g_data_007af958;
extern unsigned int g_data_007af95e;
extern unsigned int g_data_007af964;
extern unsigned int g_data_007af96c;
extern unsigned int g_data_007af978;
extern unsigned int g_data_007af984;
extern unsigned int g_data_007af990;
extern unsigned int g_data_007af992;
extern unsigned int g_data_007af994;
extern unsigned int g_data_007af996;
extern unsigned int g_data_007af998;
extern unsigned int g_data_007af99a;
extern unsigned int g_data_007af99c;
extern unsigned int g_data_007af99e;
extern unsigned int g_data_007af9a0;
extern unsigned int g_data_007af9a4;
extern unsigned int g_data_007af9a8;
extern unsigned int g_data_007af9ac;
extern unsigned int g_data_007af9b0;
extern unsigned int g_data_007af9b4;
extern unsigned int g_data_007af9b6;

__declspec(naked) void Helper_EmitLine(void) {
    __asm {
        mov     ecx, [esp + 4]
        mov     dword ptr [g_data_007af9b0], 1
        movsx   eax, word ptr [g_data_007af990]
        movsx   edx, word ptr [ecx*2 + g_data_007af958]
        imul    eax, edx
        movsx   edx, word ptr [g_data_007af992]
        push    esi
        movsx   esi, word ptr [ecx*2 + g_data_007af95e]
        imul    edx, esi
        movsx   esi, word ptr [ecx*2 + g_data_007af964]
        add     eax, edx
        movsx   edx, word ptr [g_data_007af994]
        imul    edx, esi
        add     eax, edx
        mov     edx, dword ptr [g_data_007af9a4]
        sar     eax, 0x0c
        add     eax, edx
        movsx   eax, ax
        mov     dword ptr [ecx*4 + g_data_007af96c], eax
        movsx   edx, word ptr [g_data_007af996]
        movsx   eax, word ptr [ecx*2 + g_data_007af958]
        movsx   esi, word ptr [ecx*2 + g_data_007af95e]
        imul    edx, eax
        movsx   eax, word ptr [g_data_007af998]
        imul    eax, esi
        movsx   esi, word ptr [ecx*2 + g_data_007af964]
        add     edx, eax
        movsx   eax, word ptr [g_data_007af99a]
        imul    eax, esi
        add     edx, eax
        mov     eax, dword ptr [g_data_007af9a8]
        sar     edx, 0x0c
        add     edx, eax
        movsx   edx, dx
        mov     dword ptr [ecx*4 + g_data_007af978], edx
        movsx   eax, word ptr [g_data_007af99c]
        movsx   edx, word ptr [ecx*2 + g_data_007af958]
        movsx   esi, word ptr [ecx*2 + g_data_007af95e]
        imul    eax, edx
        movsx   edx, word ptr [g_data_007af99e]
        imul    edx, esi
        movsx   esi, word ptr [ecx*2 + g_data_007af964]
        add     eax, edx
        movsx   edx, word ptr [g_data_007af9a0]
        imul    edx, esi
        mov     esi, dword ptr [g_data_007af9ac]
        add     eax, edx
        sar     eax, 0x0c
        add     eax, esi
        movsx   esi, ax
        cmp     esi, 1
        mov     dword ptr [ecx*4 + g_data_007af984], esi
        mov     eax, 0x02000000
        jle     short L_vp3_skipDiv
        cdq
        idiv    esi
    L_vp3_skipDiv:
        mov     edx, eax
        pop     esi
        imul    edx, dword ptr [ecx*4 + g_data_007af96c]
        sar     edx, 0x10
        imul    edx, 0x0001999a
        sar     edx, 0x10
        add     edx, 0x140
        mov     word ptr [ecx*4 + g_data_007af9b4], dx
        imul    eax, dword ptr [ecx*4 + g_data_007af978]
        sar     eax, 0x10
        lea     eax, [eax + eax*2]
        lea     eax, [eax + eax*4]
        shl     eax, 0x0d
        sar     eax, 0x10
        add     eax, 0xf0
        mov     word ptr [ecx*4 + g_data_007af9b6], ax
        ret
    }
}

