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
 * Apply a matrix from the per-node matrix stack to the current
 * transform chain. Pushes the current node + chain head onto two
 * parallel matrix stacks, walks down 8 children of the chain
 * starting at offset 0x28 of the entity table, then pops back.
 *
 * @addr 0x004be050
 */
__declspec(naked) void NodeApplyMatrix(void)
{
    __asm {
        mov     eax, [g_matrixStackTop]
        mov     ecx, [g_currentNodeIdx]
        inc     eax
        mov     [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_matrixStackA], ecx
        mov     eax, [g_matrixStackTop]
        mov     edx, [g_xformLoopCounter]
        inc     eax
        mov     [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_matrixStackB], edx
        mov     eax, [g_xformEntityIdx]
        sub     eax, 0Fh
        mov     [g_xformLoopCounter], 8
        mov     [g_xformEntityIdx], eax
        mov     eax, dword ptr [eax*4 + 28h]
        add     eax, 6
        mov     [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4 + g_xformChainTable]
        inc     eax
        mov     [g_walkCallback], ecx
        mov     [g_xformEntityIdx], eax
        jmp     loop_entry
loop_top:
        mov     eax, [g_xformEntityIdx]
loop_entry:
        mov     ecx, dword ptr [eax*4 + g_xformChainTable]
        mov     edx, [g_currentNodeIdx]
        inc     eax
        mov     [g_walkCallback], ecx
        mov     [g_xformEntityIdx], eax
        mov     dword ptr [edx*4 + g_xformChainTable], ecx
        mov     ecx, [g_currentNodeIdx]
        mov     eax, [g_xformLoopCounter]
        inc     ecx
        dec     eax
        mov     [g_currentNodeIdx], ecx
        mov     [g_xformLoopCounter], eax
        jns     loop_top
        mov     eax, [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + g_matrixStackB]
        dec     eax
        mov     [g_xformLoopCounter], ecx
        mov     [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4 + g_matrixStackA]
        dec     eax
        mov     [g_currentNodeIdx], edx
        mov     [g_matrixStackTop], eax
        ret
    }
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

/*
 * Non-Direct variant of NodeApplyTransform_A: same structure as the
 * _Direct family but each angle is pre-scaled (multiply-by-magic
 * for X >> 2 * 10430 >> 18, ~ X/100) and negated before being
 * stored into g_xformTempAngles. Likely converts "centi-degrees"
 * into BAM units before BuildRotMatrix.
 *
 * @addr 0x004bdb50 / 0x004bdca0 / 0x004bde90
 */
__declspec(naked) void NodeApplyTransform_A(void)
{
    __asm {
        mov     ecx, [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + g_nodeAngleTable]
        sar     eax, 2
        mov     edx, eax
        shl     edx, 6
        add     edx, eax
        lea     edx, [eax + edx*8]
        lea     eax, [eax + edx*2]
        lea     eax, [eax + eax*4]
        shl     eax, 1
        sar     eax, 12h
        neg     eax
        mov     word ptr [g_xformTempAngles], ax
        mov     eax, dword ptr [ecx*4 + g_nodeAngleTable+4]
        sar     eax, 2
        mov     edx, eax
        shl     edx, 6
        add     edx, eax
        lea     edx, [eax + edx*8]
        lea     eax, [eax + edx*2]
        lea     eax, [eax + eax*4]
        shl     eax, 1
        sar     eax, 12h
        neg     eax
        mov     word ptr [g_xformTempAngles+2], ax
        mov     eax, dword ptr [ecx*4 + g_nodeAngleTable+8]
        sar     eax, 2
        mov     ecx, eax
        shl     ecx, 6
        add     ecx, eax
        lea     edx, [eax + ecx*8]
        mov     ecx, [g_currentNodeIdx]
        lea     eax, [eax + edx*2]
        lea     edx, [ecx*4 + g_nodeMatrixTable]
        push    edx
        push    offset g_xformTempAngles
        lea     eax, [eax + eax*4]
        shl     eax, 1
        sar     eax, 12h
        neg     eax
        mov     word ptr [g_xformTempAngles+4], ax
        call    BuildRotMatrix_OrderA
        mov     eax, [g_xformDirtyFlags]
        add     esp, 8
        or      al, 30h
        mov     [g_xformDirtyFlags], eax
        ret
    }
}

__declspec(naked) void NodeApplyTransform_B(void)
{
    __asm {
        mov     ecx, [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + g_nodeAngleTable]
        sar     eax, 2
        mov     edx, eax
        shl     edx, 6
        add     edx, eax
        lea     edx, [eax + edx*8]
        lea     eax, [eax + edx*2]
        lea     eax, [eax + eax*4]
        shl     eax, 1
        sar     eax, 12h
        neg     eax
        mov     word ptr [g_xformTempAngles], ax
        mov     eax, dword ptr [ecx*4 + g_nodeAngleTable+4]
        sar     eax, 2
        mov     edx, eax
        shl     edx, 6
        add     edx, eax
        lea     edx, [eax + edx*8]
        lea     eax, [eax + edx*2]
        lea     eax, [eax + eax*4]
        shl     eax, 1
        sar     eax, 12h
        neg     eax
        mov     word ptr [g_xformTempAngles+2], ax
        mov     eax, dword ptr [ecx*4 + g_nodeAngleTable+8]
        sar     eax, 2
        mov     ecx, eax
        shl     ecx, 6
        add     ecx, eax
        lea     edx, [eax + ecx*8]
        mov     ecx, [g_currentNodeIdx]
        lea     eax, [eax + edx*2]
        lea     edx, [ecx*4 + g_nodeMatrixTable]
        push    edx
        push    offset g_xformTempAngles
        lea     eax, [eax + eax*4]
        shl     eax, 1
        sar     eax, 12h
        neg     eax
        mov     word ptr [g_xformTempAngles+4], ax
        call    BuildRotMatrix_OrderB
        mov     eax, [g_xformDirtyFlags]
        add     esp, 8
        or      al, 30h
        mov     [g_xformDirtyFlags], eax
        ret
    }
}

__declspec(naked) void NodeApplyTransform_C(void)
{
    __asm {
        mov     ecx, [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + g_nodeAngleTable]
        sar     eax, 2
        mov     edx, eax
        shl     edx, 6
        add     edx, eax
        lea     edx, [eax + edx*8]
        lea     eax, [eax + edx*2]
        lea     eax, [eax + eax*4]
        shl     eax, 1
        sar     eax, 12h
        neg     eax
        mov     word ptr [g_xformTempAngles], ax
        mov     eax, dword ptr [ecx*4 + g_nodeAngleTable+4]
        sar     eax, 2
        mov     edx, eax
        shl     edx, 6
        add     edx, eax
        lea     edx, [eax + edx*8]
        lea     eax, [eax + edx*2]
        lea     eax, [eax + eax*4]
        shl     eax, 1
        sar     eax, 12h
        neg     eax
        mov     word ptr [g_xformTempAngles+2], ax
        mov     eax, dword ptr [ecx*4 + g_nodeAngleTable+8]
        sar     eax, 2
        mov     ecx, eax
        shl     ecx, 6
        add     ecx, eax
        lea     edx, [eax + ecx*8]
        mov     ecx, [g_currentNodeIdx]
        lea     eax, [eax + edx*2]
        lea     edx, [ecx*4 + g_nodeMatrixTable]
        push    edx
        push    offset g_xformTempAngles
        lea     eax, [eax + eax*4]
        shl     eax, 1
        sar     eax, 12h
        neg     eax
        mov     word ptr [g_xformTempAngles+4], ax
        call    BuildRotMatrix_OrderC
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
