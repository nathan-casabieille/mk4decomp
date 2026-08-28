/**
 * Scene-graph allocator wrappers.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"   /* g_framePauseFlag */
#include "portable/mem_model.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackA ((unsigned int *)MK4_VA(unsigned int, 0x0u))
#define g_matrixStackB ((unsigned int *)MK4_VA(unsigned int, 0x0u))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_siblingTable ((unsigned int *)MK4_VA(unsigned int, 0x0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformChainTable ((unsigned int *)MK4_VA(unsigned int, 0x0u))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformLoopCounter (*(unsigned int *)MK4_VA(unsigned int, 0x53a1acu))
#define g_xformTempAngles ((unsigned int *)MK4_VA(unsigned int, 0xab5208u))
#endif


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
extern void InitOrAllZeroLoopback(void);


#ifdef NON_MATCHING
/* Portable twin (verified via verify_coexec - fixed 9-iteration loop, no
 * callback, so the at-rest arena exercises the whole walk). Pushes
 * currentNodeIdx + xformLoopCounter onto the two parallel matrix stacks,
 * descends to a child chain (xformEntityIdx -= 0xF, then follow node field at
 * byte +0x28), copies 9 chain entries from the child range into the
 * currentNodeIdx range, then pops both stacks. g_siblingTable / g_xformChainTable
 * are the same base-0 packed-ptr space (word k at index k); +0x28 is +10 words. */
void NodeApplyMatrix(void) {
    int          top;
    unsigned int eidx, cur, v;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    g_matrixStackA[top] = g_currentNodeIdx;          /* push currentNodeIdx */
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    g_matrixStackB[top] = g_xformLoopCounter;        /* push loop counter */

    eidx = g_xformEntityIdx - 0xF;
    g_xformLoopCounter = 8;
    g_xformEntityIdx = eidx;
    eidx = g_siblingTable[eidx + 10] + 6;            /* node[eidx].f28 + 6 */
    g_xformEntityIdx = eidx;

    g_walkCallback = g_xformChainTable[eidx];        /* preload chain[eidx] */
    eidx = eidx + 1;
    g_xformEntityIdx = eidx;

    for (;;) {
        v = g_xformChainTable[eidx];                 /* read child chain entry */
        g_walkCallback = v;
        eidx = eidx + 1;
        g_xformEntityIdx = eidx;
        cur = g_currentNodeIdx;
        g_xformChainTable[cur] = v;                  /* write into currentNodeIdx slot */
        g_currentNodeIdx = cur + 1;
        g_xformLoopCounter = g_xformLoopCounter - 1; /* dec (memory round-trip, as orig) */
        if ((int)g_xformLoopCounter < 0)             /* jns: signed test (counter is int) */
            break;
    }

    top = g_matrixStackTop;
    g_xformLoopCounter = g_matrixStackB[top];        /* pop loop counter */
    top = top - 1;
    g_matrixStackTop = top;
    g_currentNodeIdx = g_matrixStackA[top];          /* pop currentNodeIdx */
    g_matrixStackTop = top - 1;
}
#else
void NodeApplyMatrix(void) {
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
        }
}
#endif

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
#ifdef NON_MATCHING
/* Portable twin (verified against the original via verify_coexec on seeded
 * node state). g_siblingTable is the base-0 packed-ptr node pool: word at
 * packed index k is g_siblingTable[k]; node `idx` fields f0/f4/f8 are
 * g_siblingTable[idx + 0/1/2]. The saved callback (ebx) is the ORIGINAL
 * g_walkCallback captured at entry; the global is reused as walk scratch. */
void Helper_TickInner(void)
{
    /* ebx: the saved callback. It is a stored CODE VA, so it needs the
     * trampoline - identity everywhere else, the native function under the
     * arena. Calling it raw jumps to an unmapped address, which is what
     * the walk did the first time a scene list was non-empty. */
    void (*cb)(void) = (void (*)(void))MK4_ResolveCode(g_walkCallback);
    unsigned int idx     = g_currentNodeIdx;
    unsigned int cur     = g_siblingTable[idx + 1];      /* eax = node[idx].f4 */
    unsigned int next_off = g_siblingTable[idx + 2] + 2; /* edi = node[idx].f8 + 2 */
    unsigned int last    = cur;                          /* ebp */

    g_walkCallback = cur;
    if (cur != 0) {
        for (;;) {
            unsigned int walkIdx = next_off + cur;       /* ecx = edi + eax */
            unsigned int sib;
            g_currentNodeIdx = walkIdx;
            sib = g_siblingTable[walkIdx];               /* esi = node[walkIdx].f0 */
            g_currentNodeIdx = cur;                      /* eax */
            cb();
            if (g_framePauseFlag) goto done;
            if (g_xformDirtyFlags & 1) goto post_walk;
            cur  = sib;
            last = sib;
            g_walkCallback = sib;
            if (sib == 0) break;
        }
    }
post_walk:
    g_xformDirtyFlags |= 4;
    g_currentNodeIdx = last;                             /* ebp */
    if (last != 0)
        g_xformDirtyFlags ^= 4;
done:
    return;
}
#else
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
#endif

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
    s16 *angles = (s16 *)MK4_PTR((g_xformEntityIdx * 4));
    g_xformTempAngles[0] = -angles[0];
    g_xformTempAngles[1] = -angles[2];
    g_xformTempAngles[2] = -angles[4];
    BuildRotMatrix_OrderA(g_xformTempAngles, (s16 *)MK4_PTR((g_currentNodeIdx * 4)));
    g_xformDirtyFlags |= 0x30;
}

/*
 * Non-Direct variant of NodeApplyTransform_A: same shape as the
 * _Direct family but each s32 angle is first converted from the
 * engine's stored angle unit (16.16 radians, full circle ~= 2*pi<<16,
 * wrapped to the 0x6487e period - see analysis/notes/scenegraph.md)
 * into the 12-bit BAM the sine LUT indexes:
 *
 *     bam = ((x >> 2) * 10430) >> 18    (= x * 4096 / (2*pi<<16))
 *
 * 10430 / 2^20 = 1/100.53 = 4096 / (2*pi<<16). The result is negated
 * and truncated to 16 bits. (The _Direct family skips this - its
 * inputs are already BAM.)
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
    s32 *angles = (s32 *)MK4_PTR((g_xformEntityIdx * 4));
    g_xformTempAngles[0] = (s16)-(((angles[0] >> 2) * 10430) >> 18);
    g_xformTempAngles[1] = (s16)-(((angles[1] >> 2) * 10430) >> 18);
    g_xformTempAngles[2] = (s16)-(((angles[2] >> 2) * 10430) >> 18);
    BuildRotMatrix_OrderA(g_xformTempAngles, (s16 *)MK4_PTR((g_currentNodeIdx * 4)));
    g_xformDirtyFlags |= 0x30;
}

void NodeApplyTransform_B(void)
{
    s32 *angles = (s32 *)MK4_PTR((g_xformEntityIdx * 4));
    g_xformTempAngles[0] = (s16)-(((angles[0] >> 2) * 10430) >> 18);
    g_xformTempAngles[1] = (s16)-(((angles[1] >> 2) * 10430) >> 18);
    g_xformTempAngles[2] = (s16)-(((angles[2] >> 2) * 10430) >> 18);
    BuildRotMatrix_OrderB(g_xformTempAngles, (s16 *)MK4_PTR((g_currentNodeIdx * 4)));
    g_xformDirtyFlags |= 0x30;
}

void NodeApplyTransform_C(void)
{
    s32 *angles = (s32 *)MK4_PTR((g_xformEntityIdx * 4));
    g_xformTempAngles[0] = (s16)-(((angles[0] >> 2) * 10430) >> 18);
    g_xformTempAngles[1] = (s16)-(((angles[1] >> 2) * 10430) >> 18);
    g_xformTempAngles[2] = (s16)-(((angles[2] >> 2) * 10430) >> 18);
    BuildRotMatrix_OrderC(g_xformTempAngles, (s16 *)MK4_PTR((g_currentNodeIdx * 4)));
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
#ifdef NON_MATCHING
#include "portable/mem_model.h"


/* Portable twin.
 *
 * g_matrixStackA and g_matrixStackB are both base-0 in extras_map, i.e. the
 * SAME packed-pointer table: the two "parallel stacks" are one stack pushed
 * twice, which is why g_matrixStackTop is incremented twice on the way in and
 * decremented twice on the way out. g_xformChainTable is base-0 too, so every
 * `[reg*4 + table]` here is a plain packed-pointer deref.
 *
 * The scratch is 12 bytes the original takes off its own stack (`sub esp, 0Ch`)
 * and hands on as a PACKED POINTER (`lea eax, [esp]; sar eax, 2`). A C local
 * cannot carry that on a 64-bit host - see MK4_ALLOCA in mem_model.h - so it
 * comes from the arena-resident scratch stack instead.
 *
 * The swap is in the copy: chain[1] and chain[2] land in the other's slot.
 *
 * `paused` sits BEFORE the `add esp, 0Ch`, so the stack is released on both
 * paths; only the two matrix-stack pops are skipped when the frame is paused
 * (the caller is expected to unwind it). */
void NodeApplyTransform_B_Swapped(void)
{
    unsigned int *scratch = (unsigned int *)MK4_ALLOCA(12);
    unsigned int  sp = MK4_UNPTR(scratch) >> 2;
    unsigned int  e;

    *MK4_NODE(unsigned int, ++g_matrixStackTop) = g_xformEntityIdx;
    *MK4_NODE(unsigned int, ++g_matrixStackTop) = g_pendingNodeType;

    e = g_xformEntityIdx;
    g_pendingNodeType = sp;
    g_walkCallback = MK4_NODE_AT(unsigned int, e, 0);
    MK4_NODE_AT(unsigned int, sp, 0) = g_walkCallback;

    g_walkCallback = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 4);
    MK4_NODE_AT(unsigned int, g_pendingNodeType, 8) = g_walkCallback;

    g_walkCallback = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 8);
    MK4_NODE_AT(unsigned int, g_pendingNodeType, 4) = g_walkCallback;

    g_xformEntityIdx = g_pendingNodeType;
    NodeApplyTransform_B();

    if (g_framePauseFlag == 0) {
        g_pendingNodeType = *MK4_NODE(unsigned int, g_matrixStackTop);
        g_matrixStackTop--;
        g_xformEntityIdx = *MK4_NODE(unsigned int, g_matrixStackTop);
        g_matrixStackTop--;
    }
    MK4_ALLOCA_FREE(12);
}
#else
void NodeApplyTransform_B_Swapped(void) {
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
        }
}
#endif

/*
 * Like NodeApplyTransform_C but without the per-axis negation
 * (so the resulting rotation matrix is the inverse).
 *
 * @addr 0x004bdfb0
 */
void NodeApplyTransform_C_Inverse(void)
{
    s32 *angles = (s32 *)MK4_PTR((g_xformEntityIdx * 4));
    g_xformTempAngles[0] = (s16)(((angles[0] >> 2) * 10430) >> 18);
    g_xformTempAngles[1] = (s16)(((angles[1] >> 2) * 10430) >> 18);
    g_xformTempAngles[2] = (s16)(((angles[2] >> 2) * 10430) >> 18);
    BuildRotMatrix_OrderC(g_xformTempAngles, (s16 *)MK4_PTR((g_currentNodeIdx * 4)));
    g_xformDirtyFlags |= 0x30;
}

void NodeApplyTransform_B_Direct(void)
{
    s16 *angles = (s16 *)MK4_PTR((g_xformEntityIdx * 4));
    g_xformTempAngles[0] = -angles[0];
    g_xformTempAngles[1] = -angles[2];
    g_xformTempAngles[2] = -angles[4];
    BuildRotMatrix_OrderB(g_xformTempAngles, (s16 *)MK4_PTR((g_currentNodeIdx * 4)));
    g_xformDirtyFlags |= 0x30;
}

void NodeApplyTransform_C_Direct(void)
{
    s16 *angles = (s16 *)MK4_PTR((g_xformEntityIdx * 4));
    g_xformTempAngles[0] = -angles[0];
    g_xformTempAngles[1] = -angles[2];
    g_xformTempAngles[2] = -angles[4];
    BuildRotMatrix_OrderC(g_xformTempAngles, (s16 *)MK4_PTR((g_currentNodeIdx * 4)));
    g_xformDirtyFlags |= 0x30;
}


/* @addr 0x004bdc70 (48b game) - dispatch on 3-entry probe at (g_xformEntityIdx*4)+{0,4,8}.
 * If any of the 3 entries is non-zero, tail-jmp NodeApplyTransform_B (the immediately
 * following function at 0x004bdca0, encoded as e9 01 00 00 00); else tail-jmp
 * InitOrAllZeroLoopback. The trailing 0x90 byte at offset 47 is orig padding
 * that the synth's 0x90-fill restores. */
void DispatchProbeOrTransformB(void) {
    unsigned int idx = g_xformEntityIdx;
    if (*(unsigned int *)MK4_PTR((idx * 4 + 0)) == 0 &&
        *(unsigned int *)MK4_PTR((idx * 4 + 4)) == 0 &&
        *(unsigned int *)MK4_PTR((idx * 4 + 8)) == 0) {
        InitOrAllZeroLoopback();
        return;
    }
    NodeApplyTransform_B();
}

/* @addr 0x004bddc0 (48b game) - sibling of DispatchProbeOrTransformB: same dispatch pattern,
 * but second tail-jmp targets NodeApplyTransform_C instead of _B (rel32=0xa1).
 */
void DispatchProbeOrTransformC(void) {
    unsigned int idx = g_xformEntityIdx;
    if (*(unsigned int *)MK4_PTR((idx * 4 + 0)) == 0 &&
        *(unsigned int *)MK4_PTR((idx * 4 + 4)) == 0 &&
        *(unsigned int *)MK4_PTR((idx * 4 + 8)) == 0) {
        InitOrAllZeroLoopback();
        return;
    }
    NodeApplyTransform_C();
}
