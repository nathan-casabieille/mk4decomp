/**
 * Scene-graph allocator wrappers.
 */
#include "engine/scenegraph.h"

/*
 * Convenience: allocate a node using the type cached in
 * g_pendingNodeType. Lets a hot path skip re-passing the type.
 *
 * @addr 0x0049cb60
 */
void *AllocNode(void)
{
    return AllocateNode(g_pendingNodeType);
}

/*
 * Build the per-axis rotation matrix using the "Direct" entry
 * point - load three 16-bit angles from g_nodeAngleTable[idx*2+i]
 * (i=0,2,4), negate each into the scratch buffer, then call
 * BuildRotMatrix_Order{A,B,C} with that buffer + a slot in the
 * per-node matrix table. Marks g_xformDirtyFlags |= 0x30.
 *
 * The three *_Direct functions are identical except for which
 * BuildRotMatrix_Order* they tail-call. Inline asm pins the
 * specific load/store interleave the original compiler emitted.
 *
 * @addr 0x004bdc00 / 0x004bdd50 / 0x004bdf40
 */
__declspec(naked) void NodeApplyTransform_A_Direct(void)
{
    __asm {
        mov     eax, [g_xformEntityIdx]
        mov     cx, word ptr [eax*4 + g_nodeAngleTable]
        neg     cx
        mov     word ptr [g_xformTempAngles], cx
        mov     dx, word ptr [eax*4 + g_nodeAngleTable+4]
        mov     ecx, [g_currentNodeIdx]
        neg     dx
        mov     word ptr [g_xformTempAngles+2], dx
        mov     ax, word ptr [eax*4 + g_nodeAngleTable+8]
        lea     edx, [ecx*4 + g_nodeMatrixTable]
        neg     ax
        push    edx
        push    offset g_xformTempAngles
        mov     word ptr [g_xformTempAngles+4], ax
        call    BuildRotMatrix_OrderA
        mov     eax, [g_xformDirtyFlags]
        add     esp, 8
        or      al, 30h
        mov     [g_xformDirtyFlags], eax
        ret
    }
}

__declspec(naked) void NodeApplyTransform_B_Direct(void)
{
    __asm {
        mov     eax, [g_xformEntityIdx]
        mov     cx, word ptr [eax*4 + g_nodeAngleTable]
        neg     cx
        mov     word ptr [g_xformTempAngles], cx
        mov     dx, word ptr [eax*4 + g_nodeAngleTable+4]
        mov     ecx, [g_currentNodeIdx]
        neg     dx
        mov     word ptr [g_xformTempAngles+2], dx
        mov     ax, word ptr [eax*4 + g_nodeAngleTable+8]
        lea     edx, [ecx*4 + g_nodeMatrixTable]
        neg     ax
        push    edx
        push    offset g_xformTempAngles
        mov     word ptr [g_xformTempAngles+4], ax
        call    BuildRotMatrix_OrderB
        mov     eax, [g_xformDirtyFlags]
        add     esp, 8
        or      al, 30h
        mov     [g_xformDirtyFlags], eax
        ret
    }
}

__declspec(naked) void NodeApplyTransform_C_Direct(void)
{
    __asm {
        mov     eax, [g_xformEntityIdx]
        mov     cx, word ptr [eax*4 + g_nodeAngleTable]
        neg     cx
        mov     word ptr [g_xformTempAngles], cx
        mov     dx, word ptr [eax*4 + g_nodeAngleTable+4]
        mov     ecx, [g_currentNodeIdx]
        neg     dx
        mov     word ptr [g_xformTempAngles+2], dx
        mov     ax, word ptr [eax*4 + g_nodeAngleTable+8]
        lea     edx, [ecx*4 + g_nodeMatrixTable]
        neg     ax
        push    edx
        push    offset g_xformTempAngles
        mov     word ptr [g_xformTempAngles+4], ax
        call    BuildRotMatrix_OrderC
        mov     eax, [g_xformDirtyFlags]
        add     esp, 8
        or      al, 30h
        mov     [g_xformDirtyFlags], eax
        ret
    }
}
