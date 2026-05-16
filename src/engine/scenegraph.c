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
__declspec(naked) void Helper_TickInner(void)
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
 * point - load three 16-bit angles from a packed-pointer angle
 * record at (g_xformEntityIdx*4)+{0,4,8}, negate each into the
 * scratch buffer, then call BuildRotMatrix_Order{A,B,C} with that
 * buffer + the matrix slot at g_currentNodeIdx*4. Marks
 * g_xformDirtyFlags |= 0x30.
 *
 * The three *_Direct functions are identical except for which
 * BuildRotMatrix_Order* they tail-call. g_xformEntityIdx and
 * g_currentNodeIdx are packed_ptr values: the *4 reconstructs a
 * real address (the disp32 in the original disassembly is 0, so
 * there is no symbolic base table - just raw pointer arithmetic).
 *
 * @addr 0x004bdc00 / 0x004bdd50 / 0x004bdf40
 */
void NodeApplyTransform_A_Direct(void)
{
    s16 *angles = (s16 *)(g_xformEntityIdx * 4);
    g_xformTempAngles[0] = -angles[0];
    g_xformTempAngles[1] = -angles[2];
    g_xformTempAngles[2] = -angles[4];
    BuildRotMatrix_OrderA(g_xformTempAngles, (s16 *)(g_currentNodeIdx * 4));
    g_xformDirtyFlags |= 0x30;
}

/*
 * Non-Direct variant of NodeApplyTransform_A: same shape as the
 * _Direct family but each s32 angle is first pre-scaled by the
 *
 *     y = ((x >> 2) * 10430) >> 18    (~ x / 100.58)
 *
 * magic before being negated and truncated to 16 bits. Likely
 * converts an internal "centi-degrees"-ish unit before handing it
 * to BuildRotMatrix.
 *
 * MSVC SP3 lowers the * 10430 multiplication into a strength-
 * reduced lea/shl/add chain (10430 = 2 * 5 * 1043 = 2 * 5 * (1 +
 * 521*2) = 2 * (5215)); reproduced by writing the multiplication
 * directly as `* 10430` in source.
 *
 * @addr 0x004bdb50 / 0x004bdca0 / 0x004bde90
 */
void NodeApplyTransform_A(void)
{
    s32 *angles = (s32 *)(g_xformEntityIdx * 4);
    g_xformTempAngles[0] = (s16)-(((angles[0] >> 2) * 10430) >> 18);
    g_xformTempAngles[1] = (s16)-(((angles[1] >> 2) * 10430) >> 18);
    g_xformTempAngles[2] = (s16)-(((angles[2] >> 2) * 10430) >> 18);
    BuildRotMatrix_OrderA(g_xformTempAngles, (s16 *)(g_currentNodeIdx * 4));
    g_xformDirtyFlags |= 0x30;
}

void NodeApplyTransform_B(void)
{
    s32 *angles = (s32 *)(g_xformEntityIdx * 4);
    g_xformTempAngles[0] = (s16)-(((angles[0] >> 2) * 10430) >> 18);
    g_xformTempAngles[1] = (s16)-(((angles[1] >> 2) * 10430) >> 18);
    g_xformTempAngles[2] = (s16)-(((angles[2] >> 2) * 10430) >> 18);
    BuildRotMatrix_OrderB(g_xformTempAngles, (s16 *)(g_currentNodeIdx * 4));
    g_xformDirtyFlags |= 0x30;
}

void NodeApplyTransform_C(void)
{
    s32 *angles = (s32 *)(g_xformEntityIdx * 4);
    g_xformTempAngles[0] = (s16)-(((angles[0] >> 2) * 10430) >> 18);
    g_xformTempAngles[1] = (s16)-(((angles[1] >> 2) * 10430) >> 18);
    g_xformTempAngles[2] = (s16)-(((angles[2] >> 2) * 10430) >> 18);
    BuildRotMatrix_OrderC(g_xformTempAngles, (s16 *)(g_currentNodeIdx * 4));
    g_xformDirtyFlags |= 0x30;
}

/*
 * Push the current entity + pending-node-type onto the matrix stack,
 * swap three "chain" entries through the walk-callback scratch slot,
 * call NodeApplyTransform_B, then pop the stack. If the frame pause
 * flag is set after the inner call, the function exits without
 * popping (leaving the stack one-deep, which the caller is expected
 * to clean up before resuming).
 *
 * @addr 0x004be130
 */
__declspec(naked) void NodeApplyTransform_B_Swapped(void)
{
    __asm {
        mov     eax, [g_matrixStackTop]
        mov     ecx, [g_xformEntityIdx]
        sub     esp, 0Ch
        inc     eax
        mov     [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_matrixStackA], ecx
        mov     eax, [g_matrixStackTop]
        mov     edx, [g_pendingNodeType]
        inc     eax
        mov     [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_matrixStackB], edx
        mov     ecx, [g_xformEntityIdx]
        ; Force lea eax, [esp+0] with disp8 to match the original
        ; encoding (MASM normally optimises away the +0).
        _emit   8Dh
        _emit   44h
        _emit   24h
        _emit   00h
        sar     eax, 2
        mov     [g_pendingNodeType], eax
        mov     ecx, dword ptr [ecx*4 + g_xformChainTable]
        mov     [g_walkCallback], ecx
        mov     dword ptr [eax*4 + g_xformChainTable], ecx
        mov     edx, [g_xformEntityIdx]
        mov     ecx, [g_pendingNodeType]
        mov     eax, dword ptr [edx*4 + g_xformChainTable+4]
        mov     [g_walkCallback], eax
        mov     dword ptr [ecx*4 + g_xformChainTable+8], eax
        mov     edx, [g_xformEntityIdx]
        mov     ecx, [g_pendingNodeType]
        mov     eax, dword ptr [edx*4 + g_xformChainTable+8]
        mov     [g_walkCallback], eax
        mov     dword ptr [ecx*4 + g_xformChainTable+4], eax
        mov     edx, [g_pendingNodeType]
        mov     [g_xformEntityIdx], edx
        call    NodeApplyTransform_B
        mov     eax, [g_framePauseFlag]
        test    eax, eax
        jne     paused
        mov     eax, [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + g_matrixStackA]
        dec     eax
        mov     [g_pendingNodeType], ecx
        mov     [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4 + g_matrixStackB]
        dec     eax
        mov     [g_xformEntityIdx], edx
        mov     [g_matrixStackTop], eax
paused:
        add     esp, 0Ch
        ret
    }
}

/*
 * Like NodeApplyTransform_C but without the per-axis negation
 * (so the resulting rotation matrix is the inverse).
 *
 * @addr 0x004bdfb0
 */
void NodeApplyTransform_C_Inverse(void)
{
    s32 *angles = (s32 *)(g_xformEntityIdx * 4);
    g_xformTempAngles[0] = (s16)(((angles[0] >> 2) * 10430) >> 18);
    g_xformTempAngles[1] = (s16)(((angles[1] >> 2) * 10430) >> 18);
    g_xformTempAngles[2] = (s16)(((angles[2] >> 2) * 10430) >> 18);
    BuildRotMatrix_OrderC(g_xformTempAngles, (s16 *)(g_currentNodeIdx * 4));
    g_xformDirtyFlags |= 0x30;
}

void NodeApplyTransform_B_Direct(void)
{
    s16 *angles = (s16 *)(g_xformEntityIdx * 4);
    g_xformTempAngles[0] = -angles[0];
    g_xformTempAngles[1] = -angles[2];
    g_xformTempAngles[2] = -angles[4];
    BuildRotMatrix_OrderB(g_xformTempAngles, (s16 *)(g_currentNodeIdx * 4));
    g_xformDirtyFlags |= 0x30;
}

void NodeApplyTransform_C_Direct(void)
{
    s16 *angles = (s16 *)(g_xformEntityIdx * 4);
    g_xformTempAngles[0] = -angles[0];
    g_xformTempAngles[1] = -angles[2];
    g_xformTempAngles[2] = -angles[4];
    BuildRotMatrix_OrderC(g_xformTempAngles, (s16 *)(g_currentNodeIdx * 4));
    g_xformDirtyFlags |= 0x30;
}
