/**
 * 3D vertex projection.
 *
 * Applies the camera matrix g_vtxMat (row-major) + translation to
 * the input local coords, stores the world-space result, then
 * does a perspective divide (0x02000000 / world_z) and viewport
 * scaling to produce the 16-bit screen coords. The viewport
 * constants here are 320 (half of width=640) and 240 (half of
 * height=480) - low-res hardcoded.
 */
#include "engine/render.h"
#include "portable/ghidra_types.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#endif


/*
 * @addr 0x004b2e80
 *
 * Naked + __asm: the body is 7 movsx + 9 imul + a chain of sar 12
 * fixed-point reductions, threaded through eax/ecx/edx/edi/esi/ebx
 * with a very specific order. Pure C wouldn't reproduce the dual
 * idiv result-reuse (eax: ratio for X, ecx: ratio for Y).
 */
extern void Helper_EmitLine(int slot);

#ifdef NON_MATCHING
/* Co-exec verified (tools/decomp/verify_project.py, pos/neg/mixed seeds).
 *
 * ProjectVertex IS Helper_EmitLine(2). Confirmed by the write set: the original
 * stores to 0x7af974 / 0x7af980 / 0x7af98c and the screen pair 0x7af9bc/be,
 * which are exactly slot 2 of the out-x (0x7af96c), out-y (0x7af978), out-z
 * (0x7af984) and screen (0x7af9b4) arrays Helper_EmitLine indexes - and it
 * reads g_triStripX0/1/2, slot 2 of the three s16 input vectors.
 *
 * Expressing it this way retires a Ghidra lift that carried two sign bugs the
 * old all-positive seeds could never catch: logical shifts where the original
 * uses sar, and a (short) truncation applied BEFORE adding the 32-bit
 * translation instead of after (orig: sar / add / movsx).
 */
void ProjectVertex(void)
{
    Helper_EmitLine(2);
}
#else
__declspec(naked) void ProjectVertex(void)
{
    __asm {
        movsx   eax, word ptr [g_vtxIn_x]
        movsx   ecx, word ptr [g_vtxIn_y]
        push    ebx
        push    esi
        movsx   esi, word ptr [g_vtxMat + 2]               ; mat[0][1]?
        push    edi
        imul    esi, ecx
        movsx   edi, word ptr [g_vtxMat]                    ; mat[0][0]
        imul    edi, eax
        movsx   edx, word ptr [g_vtxIn_z]
        add     esi, edi
        mov     dword ptr [g_vtxValid], 1
        movsx   edi, word ptr [g_vtxMat + 4]               ; mat[0][2]
        imul    edi, edx
        movsx   ebx, word ptr [g_vtxMat + 6]               ; mat[1][0]
        add     esi, edi
        mov     edi, dword ptr [g_vtxTransX]
        sar     esi, 12
        imul    ebx, eax
        add     esi, edi
        movsx   edi, word ptr [g_vtxMat + 8]               ; mat[1][1]
        imul    edi, ecx
        add     edi, ebx
        movsx   ebx, word ptr [g_vtxMat + 10]              ; mat[1][2]
        imul    ebx, edx
        add     edi, ebx
        mov     ebx, dword ptr [g_vtxTransY]
        sar     edi, 12
        add     edi, ebx
        movsx   ebx, word ptr [g_vtxMat + 14]              ; mat[2][1]
        imul    ebx, ecx
        movsx   ecx, word ptr [g_vtxMat + 12]              ; mat[2][0]
        imul    ecx, eax
        movsx   eax, word ptr [g_vtxMat + 16]              ; mat[2][2]
        imul    eax, edx
        add     ebx, ecx
        add     ebx, eax
        mov     eax, dword ptr [g_vtxTransZ]
        sar     ebx, 12
        add     ebx, eax
        mov     eax, 0x02000000
        movsx   ecx, bx
        movsx   esi, si
        movsx   edi, di
        cmp     ecx, 1
        mov     dword ptr [g_vtxOut_x], esi
        mov     dword ptr [g_vtxOut_y], edi
        mov     dword ptr [g_vtxOut_z], ecx
        jle     skip_div
        cdq
        idiv    ecx
skip_div:
        mov     ecx, eax
        imul    eax, edi
        imul    ecx, esi
        sar     ecx, 16
        imul    ecx, 0x1999a                                ; 320/3 in 16.16
        sar     eax, 16
        sar     ecx, 16
        lea     eax, [eax + eax*2]                          ; eax * 3
        add     ecx, 0x140                                   ; +320
        pop     edi
        pop     esi
        lea     edx, [eax + eax*4]                          ; eax * 5
        mov     word ptr [g_vtxScreenX], cx
        shl     edx, 13
        sar     edx, 16
        add     edx, 0xf0                                    ; +240
        pop     ebx
        mov     word ptr [g_vtxScreenY], dx
        ret
    }
}
#endif
