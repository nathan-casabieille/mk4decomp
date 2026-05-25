/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b2d20 (338b engine.app) - 3D vertex transform + perspective project.
 *   Reads vertex idx ecx; applies 3x3 matrix at g_vtxMat..0x7af9a0 to
 *   (x,y,z) at g_vtxIn_x/95e/964[ecx]; adds translation 0x7af9a4/a8/ac.
 *   Stores transformed XYZ at [0x7af96c/78/84][ecx*4].
 *   Perspective divide: if Z > 1, scale = 0x02000000/Z; project X via
 *   scale*0x19999a (offset 0x140 = 320 center); Y via scale * 15 * 8192/65536
 *   (offset 0xf0 = 240 center). Stores screen XY (word) at 0x7af9b4/b6.
 */
extern s16 g_vtxIn_x;
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn2_y;
extern s32 g_vtxOut1_x;
extern s32 g_vtxOut1_y;
extern unsigned int g_triStripRingB;
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af992;
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af996;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99a;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af99e;
extern unsigned int g_mat3x3_007af9a0;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP1Y;

__declspec(naked) void Helper_EmitLine(void) {
    __asm {
        mov     ecx, [esp + 4]
        mov     dword ptr [g_vtxValid], 1
        movsx   eax, word ptr [g_vtxMat]
        movsx   edx, word ptr [ecx*2 + g_vtxIn_x]
        imul    eax, edx
        movsx   edx, word ptr [g_mat3x3_007af992]
        push    esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn1_y]
        imul    edx, esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn2_y]
        add     eax, edx
        movsx   edx, word ptr [g_mat3x3_007af994]
        imul    edx, esi
        add     eax, edx
        mov     edx, dword ptr [g_vtxTransX]
        sar     eax, 0x0c
        add     eax, edx
        movsx   eax, ax
        mov     dword ptr [ecx*4 + g_vtxOut1_x], eax
        movsx   edx, word ptr [g_mat3x3_007af996]
        movsx   eax, word ptr [ecx*2 + g_vtxIn_x]
        movsx   esi, word ptr [ecx*2 + g_vtxIn1_y]
        imul    edx, eax
        movsx   eax, word ptr [g_mat3x3_007af998]
        imul    eax, esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn2_y]
        add     edx, eax
        movsx   eax, word ptr [g_mat3x3_007af99a]
        imul    eax, esi
        add     edx, eax
        mov     eax, dword ptr [g_vtxTransY]
        sar     edx, 0x0c
        add     edx, eax
        movsx   edx, dx
        mov     dword ptr [ecx*4 + g_vtxOut1_y], edx
        movsx   eax, word ptr [g_mat3x3_007af99c]
        movsx   edx, word ptr [ecx*2 + g_vtxIn_x]
        movsx   esi, word ptr [ecx*2 + g_vtxIn1_y]
        imul    eax, edx
        movsx   edx, word ptr [g_mat3x3_007af99e]
        imul    edx, esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn2_y]
        add     eax, edx
        movsx   edx, word ptr [g_mat3x3_007af9a0]
        imul    edx, esi
        mov     esi, dword ptr [g_vtxTransZ]
        add     eax, edx
        sar     eax, 0x0c
        add     eax, esi
        movsx   esi, ax
        cmp     esi, 1
        mov     dword ptr [ecx*4 + g_triStripRingB], esi
        mov     eax, 0x02000000
        jle     short L_vp3_skipDiv
        cdq
        idiv    esi
    L_vp3_skipDiv:
        mov     edx, eax
        pop     esi
        imul    edx, dword ptr [ecx*4 + g_vtxOut1_x]
        sar     edx, 0x10
        imul    edx, 0x0001999a
        sar     edx, 0x10
        add     edx, 0x140
        mov     word ptr [ecx*4 + g_triStripRingA], dx
        imul    eax, dword ptr [ecx*4 + g_vtxOut1_y]
        sar     eax, 0x10
        lea     eax, [eax + eax*2]
        lea     eax, [eax + eax*4]
        shl     eax, 0x0d
        sar     eax, 0x10
        add     eax, 0xf0
        mov     word ptr [ecx*4 + g_vtxScreenP1Y], ax
        ret
    }
}

