/**
 * Two-vertex projection (line drawer).
 *
 * Same machinery as ProjectVertex applied to two vertices in
 * sequence (g_vtxIn1_* and g_vtxIn2_*), storing world coords to
 * (g_vtxOut1_*, g_vtxOut2_*) and screen coords to
 * (g_vtxScreenP1{X,Y}, g_vtxScreenP2{X,Y}). Tail-calls
 * Helper_EmitLine(2) at the end.
 */
#include "engine/render.h"

/*
 * @addr 0x004b2af0
 *
 * Naked + __asm: register-level scheduling threads the matrix
 * loads through edi/esi/ebx across the two vertex transforms,
 * with a single shared idiv per vertex for the perspective
 * divide. Pure C wouldn't reproduce the cross-vertex register
 * carry-over.
 */
__declspec(naked) void ProjectTwoVertices(void)
{
    __asm {
        movsx   edx, word ptr [g_vtxIn2_y]
        movsx   ecx, word ptr [g_vtxIn1_y]
        push    ebx
        push    ebp
        movsx   ebx, word ptr [g_vtxMat + 4]
        push    esi
        push    edi
        movsx   edi, word ptr [g_vtxMat + 2]
        mov     ebp, edx
        imul    ebp, ebx
        mov     ebx, ecx
        movsx   eax, word ptr [g_vtxIn_x]
        imul    ebx, edi
        movsx   esi, word ptr [g_vtxMat]
        add     ebp, ebx
        mov     ebx, eax
        imul    ebx, esi
        add     ebp, ebx
        mov     ebx, dword ptr [g_vtxTransX]
        sar     ebp, 12
        add     ebp, ebx
        movsx   ebx, bp
        movsx   ebp, word ptr [g_vtxMat + 10]
        mov     dword ptr [g_vtxOut1_x], ebx
        imul    ebp, edx
        movsx   ebx, word ptr [g_vtxMat + 8]
        imul    ebx, ecx
        add     ebp, ebx
        movsx   ebx, word ptr [g_vtxMat + 6]
        imul    ebx, eax
        add     ebp, ebx
        mov     ebx, dword ptr [g_vtxTransY]
        sar     ebp, 12
        add     ebp, ebx
        movsx   ebx, bp
        movsx   ebp, word ptr [g_vtxMat + 14]
        mov     dword ptr [g_vtxOut1_y], ebx
        imul    ebp, ecx
        movsx   ebx, word ptr [g_vtxMat + 12]
        mov     ecx, ebx
        imul    ecx, eax
        movsx   eax, word ptr [g_vtxMat + 16]
        imul    eax, edx
        add     ebp, ecx
        add     ebp, eax
        mov     eax, dword ptr [g_vtxTransZ]
        sar     ebp, 12
        add     ebp, eax
        mov     eax, 0x02000000
        movsx   ecx, bp
        cmp     ecx, 1
        mov     dword ptr [g_vtxOut1_z], ecx
        jle     skip_div1
        cdq
        idiv    ecx
skip_div1:
        mov     edx, eax
        imul    eax, dword ptr [g_vtxOut1_y]
        imul    edx, dword ptr [g_vtxOut1_x]
        sar     eax, 16
        movsx   ecx, word ptr [g_vtxIn1_z]
        lea     eax, [eax + eax*2]
        mov     dword ptr [g_vtxValid], 1
        sar     edx, 16
        lea     eax, [eax + eax*4]
        imul    edx, 0x1999a
        shl     eax, 13
        sar     eax, 16
        add     eax, 0xf0
        mov     word ptr [g_vtxScreenP1Y], ax
        movsx   eax, word ptr [g_vtxIn2_x]
        mov     ebp, eax
        imul    ebp, esi
        mov     esi, ecx
        imul    esi, edi
        sar     edx, 16
        add     edx, 0x140
        add     ebp, esi
        movsx   esi, word ptr [g_vtxMat + 4]
        mov     word ptr [g_vtxScreenP1X], dx
        movsx   edx, word ptr [g_vtxIn2_z]
        mov     edi, edx
        imul    edi, esi
        add     ebp, edi
        mov     edi, dword ptr [g_vtxTransX]
        sar     ebp, 12
        add     ebp, edi
        mov     edi, eax
        movsx   esi, bp
        imul    eax, ebx
        mov     dword ptr [g_vtxOut2_x], esi
        mov     ebp, edx
        movsx   esi, word ptr [g_vtxMat + 6]
        imul    edi, esi
        movsx   esi, word ptr [g_vtxMat + 10]
        imul    ebp, esi
        movsx   esi, word ptr [g_vtxMat + 8]
        add     edi, ebp
        mov     ebp, ecx
        imul    ebp, esi
        movsx   esi, word ptr [g_vtxMat + 14]
        imul    ecx, esi
        add     eax, ecx
        mov     esi, dword ptr [g_vtxTransZ]
        movsx   ecx, word ptr [g_vtxMat + 16]
        imul    edx, ecx
        add     eax, edx
        add     edi, ebp
        mov     ebp, dword ptr [g_vtxTransY]
        sar     eax, 12
        sar     edi, 12
        add     eax, esi
        add     edi, ebp
        movsx   ecx, ax
        movsx   edi, di
        cmp     ecx, 1
        mov     dword ptr [g_vtxOut2_y], edi
        mov     dword ptr [g_vtxOut2_z], ecx
        mov     eax, 0x02000000
        jle     skip_div2
        cdq
        idiv    ecx
skip_div2:
        mov     ecx, eax
        imul    eax, edi
        imul    ecx, dword ptr [g_vtxOut2_x]
        sar     ecx, 16
        imul    ecx, 0x1999a
        sar     eax, 16
        sar     ecx, 16
        lea     eax, [eax + eax*2]
        add     ecx, 0x140
        push    2
        mov     word ptr [g_vtxScreenP2X], cx
        lea     edx, [eax + eax*4]
        shl     edx, 13
        sar     edx, 16
        add     edx, 0xf0
        mov     word ptr [g_vtxScreenP2Y], dx
        call    Helper_EmitLine
        add     esp, 4
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
