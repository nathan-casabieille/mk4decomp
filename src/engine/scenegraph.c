/**
 * Scene-graph allocator wrappers.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"   /* g_framePauseFlag */

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
 * Walk the scene-graph siblings of g_currentNodeIdx, invoking the
 * caller-supplied g_walkCallback on each. Each sibling entry has
 * three packed fields at byte offsets +0, +4, +8 (interpreted by
 * the table base relocations).
 *
 * The function pauses if g_framePauseFlag becomes non-zero mid
 * walk, and ORs 4 into g_xformDirtyFlags / clears it via XOR
 * depending on whether the walk completed.
 *
 * @addr 0x004ba130
 */
__declspec(naked) void WalkSceneGraphSiblings(void)
{
    __asm {
        mov     ecx, [g_currentNodeIdx]
        push    ebx
        mov     ebx, [g_walkCallback]
        push    ebp
        mov     eax, dword ptr [ecx*4 + g_siblingTable+4]
        push    esi
        push    edi
        mov     [g_walkCallback], eax
        mov     edi, dword ptr [ecx*4 + g_siblingTable+8]
        mov     ebp, eax
        add     edi, 2
        test    eax, eax
        jz      post_walk
walk_loop:
        lea     ecx, [edi+eax]
        mov     [g_currentNodeIdx], ecx
        mov     esi, dword ptr [ecx*4 + g_siblingTable]
        mov     [g_currentNodeIdx], eax
        call    ebx
        mov     eax, [g_framePauseFlag]
        test    eax, eax
        jne     done
        test    byte ptr [g_xformDirtyFlags], 1
        jne     post_walk
        mov     eax, esi
        mov     ebp, esi
        test    esi, esi
        mov     [g_walkCallback], eax
        jne     walk_loop
post_walk:
        mov     edx, [g_xformDirtyFlags]
        mov     eax, 4
        or      edx, eax
        mov     [g_currentNodeIdx], ebp
        test    ebp, ebp
        mov     [g_xformDirtyFlags], edx
        jz      done
        mov     ecx, edx
        xor     ecx, eax
        mov     [g_xformDirtyFlags], ecx
done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
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
