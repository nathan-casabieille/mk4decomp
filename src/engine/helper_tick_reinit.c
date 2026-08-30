/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_eventQueueSeed;
extern u32 g_inLoopStep;
extern unsigned int g_dispatchSave1626[];
extern s16 g_vtxIn2_x;
extern unsigned int g_triStripX0;
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn1_z;
extern unsigned int g_triStripX1;
extern s16 g_vtxIn2_y;
extern s16 g_vtxIn2_z;
extern unsigned int g_triStripX2;
extern unsigned int g_triStripRingB;
extern s32 g_vtxOut2_z;
extern s32 g_vtxOut_z;
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af9a0;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP1Y;
extern s16 g_vtxScreenP2X;
extern s16 g_vtxScreenP2Y;
extern s16 g_vtxScreenX;
extern s16 g_vtxScreenY;
extern unsigned int g_dispatchSave1513;
extern unsigned int g_camRotXBam;
extern unsigned int g_camRotZBam;
extern unsigned int g_vtxMatBase;
extern unsigned int g_dispatchSave1530;
extern unsigned int g_dispatchSave1531;
extern unsigned int g_dispatchSave1532;
extern unsigned int g_dispatchSave1533;
extern unsigned int g_dispatchSave1554;
extern unsigned int g_dispatchSave1555;
extern unsigned int g_dispatchSave1556;
extern unsigned int g_dispatchSave1557;
extern unsigned int g_dispatchSave1558;
#endif
#ifndef NON_MATCHING
extern void AdvanceTriStripRing(void);
#endif
#ifndef NON_MATCHING
extern void Helper_DrawCursor(void);
#endif
#ifndef NON_MATCHING
extern void Init16BitFields(void);
#endif
#ifndef NON_MATCHING
extern void Mat3x3VecMul(void);
#endif
#ifndef NON_MATCHING
extern void MaxOfThree(void);
#endif
#ifndef NON_MATCHING
extern void ProjectTwoVertices(void);
#endif
#ifndef NON_MATCHING
extern void ProjectVertex(void);
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_camRotXBam (*(unsigned int *)MK4_VA(unsigned int, 0xab47f8u))
#define g_camRotZBam (*(unsigned int *)MK4_VA(unsigned int, 0xab47fcu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1513 (*(unsigned int *)MK4_VA(unsigned int, 0xab44f8u))
#define g_dispatchSave1530 (*(unsigned int *)MK4_VA(unsigned int, 0xab487cu))
#define g_dispatchSave1531 (*(unsigned int *)MK4_VA(unsigned int, 0xab4880u))
#define g_dispatchSave1532 (*(unsigned int *)MK4_VA(unsigned int, 0xab4884u))
#define g_dispatchSave1533 (*(unsigned int *)MK4_VA(unsigned int, 0xab4888u))
#define g_dispatchSave1554 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d58u))
#define g_dispatchSave1555 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d5cu))
#define g_dispatchSave1556 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d60u))
#define g_dispatchSave1557 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d64u))
#define g_dispatchSave1558 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d68u))
#define g_dispatchSave1626 ((unsigned int *)MK4_VA(unsigned int, 0x7af958u))
#define g_eventQueueSeed (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_inLoopStep (*(unsigned int *)MK4_VA(unsigned int, 0x7af92cu))
#define g_mat3x3_007af994 (*(short *)MK4_VA(short, 0x7af994u))
#define g_mat3x3_007af998 (*(short *)MK4_VA(short, 0x7af998u))
#define g_mat3x3_007af99c (*(short *)MK4_VA(short, 0x7af99cu))
#define g_mat3x3_007af9a0 (*(short *)MK4_VA(short, 0x7af9a0u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_tickX2 (*(unsigned int *)MK4_VA(unsigned int, 0xab51f4u))
#define g_triStripRingA (*(unsigned int *)MK4_VA(unsigned int, 0x7af9b4u))
#define g_triStripRingB (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_triStripX0 (*(short *)MK4_VA(short, 0x7af95cu))
#define g_triStripX1 (*(short *)MK4_VA(short, 0x7af962u))
#define g_triStripX2 (*(short *)MK4_VA(short, 0x7af968u))
#define g_vtxIn1_y (*(short *)MK4_VA(short, 0x7af95eu))
#define g_vtxIn1_z (*(short *)MK4_VA(short, 0x7af960u))
#define g_vtxIn2_x (*(short *)MK4_VA(short, 0x7af95au))
#define g_vtxIn2_y (*(short *)MK4_VA(short, 0x7af964u))
#define g_vtxIn2_z (*(short *)MK4_VA(short, 0x7af966u))
#define g_vtxMat ((short *)MK4_VA(short, 0x7af990u))
#define g_vtxMatBase (*(unsigned int *)MK4_VA(unsigned int, 0xab4878u))
#define g_vtxOut2_z (*(int *)MK4_VA(int, 0x7af988u))
#define g_vtxOut_z (*(int *)MK4_VA(int, 0x7af98cu))
#define g_vtxScreenP1Y (*(short *)MK4_VA(short, 0x7af9b6u))
#define g_vtxScreenP2X (*(unsigned int *)MK4_VA(unsigned int, 0x7af9b8u))
#define g_vtxScreenP2Y (*(short *)MK4_VA(short, 0x7af9bau))
#define g_vtxScreenX (*(unsigned int *)MK4_VA(unsigned int, 0x7af9bcu))
#define g_vtxScreenY (*(short *)MK4_VA(short, 0x7af9beu))
#define g_vtxTransX (*(int *)MK4_VA(int, 0x7af9a4u))
#define g_vtxTransY (*(int *)MK4_VA(int, 0x7af9a8u))
#define g_vtxTransZ (*(int *)MK4_VA(int, 0x7af9acu))
#define g_vtxValid (*(int *)MK4_VA(int, 0x7af9b0u))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void Init16BitFields(void);
extern void Mat3x3VecMul(int *in, int *out);
extern void ProjectTwoVertices(void);
extern void ProjectVertex(void);
extern int  MaxOfThree(void);
extern void AdvanceTriStripRing(s16 v0, s16 v1, s16 v2);
extern void Helper_DrawCursor(void *entry);

/* Portable twin of GameTick's last engine blocker, written from the
 * disassembly. Despite the name it EMITS: the ground strips. For each PAIR of
 * s16 vec3s in the camera table at 0x00ab44f8 (g_tickX2 / 2 pairs - the rows
 * CameraSetupAndCullFan wrote), both endpoints are rotated through the wt
 * matrix (Mat3x3VecMul on the 0x00ab4d58 snapshot), corrected sideways by the
 * camera's X and Z BAM angles - x' = x - ((y + half) * rotX >> 12), z' = z -
 * ((y + half) * rotZ >> 12), with `half` the s16 extracted from bits 8..23 of
 * the seed node's +0x58 - and the segment between them becomes a quad: the
 * strip is widened by a quarter of its own span on each side, projected under
 * the ALTERNATE matrix at 0x00ab4878, and submitted as two tris.
 *
 * The record's colour bytes are (0x1c, 0x64) three times, its colour word is
 * ZERO, and its flags start at 0xf; the sort key is MaxOfThree() before every
 * submit, with no g_tickCurMask fallback - unlike every other emitter.
 *
 * Seeding note: g_eventQueueSeed's +0x58 supplies `half`; the vec3 pairs are
 * whatever the camera left in the table. */
void Helper_TickReinit(void)
{
    unsigned int tbl, count;
    unsigned int rec[7];
    int in[3], out1[3], out2[3];
    int half, rotx, rotz;
    int sx1, z1, sx2, z2, dq, dz4;
    int p1x, p1y, p2x, p2y, sx, sy, valid;

    if (g_inLoopStep != 0)
        return;
    if (g_tickX2 == 0)
        return;

    Init16BitFields();
    count = (unsigned int)((int)g_tickX2 / 2);

    g_vtxTransX = 0;
    g_vtxTransY = 0;
    g_vtxTransZ = 0;
    g_currentNodeIdx = g_eventQueueSeed;
    half = (int)(short)((int)(MK4_NODE_AT(unsigned int, g_eventQueueSeed, 0x58)
                              << 8) >> 16);

    ((unsigned char *)rec)[0xc]  = 0x1c;
    ((unsigned char *)rec)[0xd]  = 0x64;
    ((unsigned char *)rec)[0xe]  = 0x1c;
    ((unsigned char *)rec)[0xf]  = 0x64;
    ((unsigned char *)rec)[0x10] = 0x1c;
    ((unsigned char *)rec)[0x11] = 0x64;
    ((unsigned short *)rec)[0xa] = 0;              /* +0x14: colour word */
    ((unsigned short *)rec)[0xd] = 0xf;            /* +0x1a: flags       */
    ((unsigned short *)rec)[0xb] = 0; ((unsigned short *)rec)[0xc] = 0;

    if ((int)count <= 0)
        return;

    tbl = 0xab44f8u;
    while (count != 0) {
        rotx = (int)*MK4_VA(short, 0xab47f8u);     /* g_camRotXBam */
        rotz = (int)*MK4_VA(short, 0xab47fcu);     /* g_camRotZBam */

        *MK4_VA(unsigned int, 0x7af990u) = *MK4_VA(unsigned int, 0xab4d58u);
        *MK4_VA(unsigned int, 0x7af994u) = *MK4_VA(unsigned int, 0xab4d58 + 4u);
        *MK4_VA(unsigned int, 0x7af998u) = *MK4_VA(unsigned int, 0xab4d58 + 8u);
        *MK4_VA(unsigned int, 0x7af99cu) = *MK4_VA(unsigned int, 0xab4d58 + 0xcu);
        *MK4_VA(unsigned short, 0x7af9a0u) = *MK4_VA(unsigned short, 0xab4d58 + 0x10u);

        in[0] = (int)*MK4_VA(short, tbl);
        in[1] = (int)*MK4_VA(short, tbl + 2);
        in[2] = (int)*MK4_VA(short, tbl + 4);
        Mat3x3VecMul(in, out1);
        g_xformEntityIdx = (unsigned int)out1[1];
        g_currentNodeIdx = (unsigned int)out1[0];
        g_pendingNodeType = (unsigned int)out1[2];
        sx1 = out1[0] + (((-(out1[1] + half)) * rotx) >> 12);
        z1  = out1[2] + (((-(out1[1] + half)) * rotz) >> 12);
        tbl += 6;

        in[0] = (int)*MK4_VA(short, tbl);
        in[1] = (int)*MK4_VA(short, tbl + 2);
        in[2] = (int)*MK4_VA(short, tbl + 4);
        Mat3x3VecMul(in, out2);
        g_xformEntityIdx = (unsigned int)out2[1];
        g_currentNodeIdx = (unsigned int)out2[0];
        g_pendingNodeType = (unsigned int)out2[2];
        sx2 = out2[0] + (((-(out2[1] + half)) * rotx) >> 12);
        z2  = out2[2] + (((-(out2[1] + half)) * rotz) >> 12);
        tbl += 6;

        dq  = (sx2 - sx1) / 4;                     /* cdq/and/sar: signed */
        dz4 = (z2 - z1) / 4;

        *MK4_VA(short, 0x7af958u) = (short)(sx1 - dz4);
        *MK4_VA(short, 0x7af95eu) = (short)-half;
        *MK4_VA(short, 0x7af964u) = (short)(z1 + dq);
        *MK4_VA(short, 0x7af95au) = (short)(sx1 + dz4);
        *MK4_VA(short, 0x7af960u) = (short)-half;
        *MK4_VA(short, 0x7af966u) = (short)(z1 - dq);
        *MK4_VA(short, 0x7af95cu) = (short)(sx2 - dz4);
        *MK4_VA(short, 0x7af962u) = (short)-half;
        *MK4_VA(short, 0x7af968u) = (short)(z2 + dq);

        *MK4_VA(unsigned int, 0x7af990u) = *MK4_VA(unsigned int, 0xab4878u);
        *MK4_VA(unsigned int, 0x7af994u) = *MK4_VA(unsigned int, 0xab4878 + 4u);
        *MK4_VA(unsigned int, 0x7af998u) = *MK4_VA(unsigned int, 0xab4878 + 8u);
        *MK4_VA(unsigned int, 0x7af99cu) = *MK4_VA(unsigned int, 0xab4878 + 0xcu);
        *MK4_VA(unsigned short, 0x7af9a0u) = *MK4_VA(unsigned short, 0xab4878 + 0x10u);

        ProjectTwoVertices();
        p1x = (int)*MK4_VA(short, 0x7af9b4u);
        p1y = (int)*MK4_VA(short, 0x7af9b6u);
        p2x = (int)*MK4_VA(short, 0x7af9b8u);
        p2y = (int)*MK4_VA(short, 0x7af9bau);
        sx  = (int)*MK4_VA(short, 0x7af9bcu);
        sy  = (int)*MK4_VA(short, 0x7af9beu);
        valid = ((sy - p1y) * (p2x - p1x) - (p2y - p1y) * (sx - p1x)) <= 0;
        rec[0] = *MK4_VA(unsigned int, 0x7af9b4u);
        rec[1] = *MK4_VA(unsigned int, 0x7af9b8u);
        rec[2] = *MK4_VA(unsigned int, 0x7af9bcu);
        *MK4_VA(unsigned int, 0x7af9b0u) = (unsigned int)valid;
        ((unsigned short *)rec)[0xd] = (unsigned short)
            ((((unsigned short *)rec)[0xd] & 0xfbffu) | ((unsigned)valid << 10));
        ((unsigned short *)rec)[9] = (unsigned short)MaxOfThree();
        if ((int)*MK4_VA(int, 0x7af984u) > 0 && (int)*MK4_VA(int, 0x7af988u) > 0
            && (int)*MK4_VA(int, 0x7af98cu) > 0)
            Helper_DrawCursor(rec);

        AdvanceTriStripRing((short)(sx2 + dz4), (short)-half,
                            (short)(z2 - dq));
        ProjectVertex();
        p1x = (int)*MK4_VA(short, 0x7af9b4u);
        p1y = (int)*MK4_VA(short, 0x7af9b6u);
        p2x = (int)*MK4_VA(short, 0x7af9b8u);
        p2y = (int)*MK4_VA(short, 0x7af9bau);
        sx  = (int)*MK4_VA(short, 0x7af9bcu);
        sy  = (int)*MK4_VA(short, 0x7af9beu);
        valid = ((sy - p1y) * (p2x - p1x) - (p2y - p1y) * (sx - p1x)) <= 0;
        rec[0] = *MK4_VA(unsigned int, 0x7af9b4u);
        rec[1] = *MK4_VA(unsigned int, 0x7af9b8u);
        rec[2] = *MK4_VA(unsigned int, 0x7af9bcu);
        *MK4_VA(unsigned int, 0x7af9b0u) = (unsigned int)valid;
        ((unsigned short *)rec)[0xd] = (unsigned short)
            ((((unsigned short *)rec)[0xd] & 0xfbffu) | ((unsigned)valid << 10));
        ((unsigned short *)rec)[9] = (unsigned short)MaxOfThree();
        if ((int)*MK4_VA(int, 0x7af984u) > 0 && (int)*MK4_VA(int, 0x7af988u) > 0
            && (int)*MK4_VA(int, 0x7af98cu) > 0)
            Helper_DrawCursor(rec);

        count--;
    }
}
#else
__declspec(naked) void Helper_TickReinit(void)
{
    __asm {
        mov      eax, dword ptr [g_inLoopStep]
        sub      esp, 0x64
        push     ebx
        push     esi
        xor      esi, esi
        push     edi
        cmp      eax, esi
        jne      L_cc3c
        cmp      dword ptr [g_tickX2], esi
        je       L_cc3c
        call     Init16BitFields
        mov      eax, dword ptr [g_tickX2]
        mov      ecx, dword ptr [g_vtxMatBase]
        cdq
        mov      dword ptr [g_vtxMat], ecx
        mov      ecx, dword ptr [g_dispatchSave1531]
        sub      eax, edx
        mov      edx, dword ptr [g_dispatchSave1530]
        mov      dword ptr [g_mat3x3_007af998], ecx
        mov      cx, word ptr [g_dispatchSave1533]
        mov      dword ptr [g_mat3x3_007af994], edx
        mov      edx, dword ptr [g_dispatchSave1532]
        mov      word ptr [g_mat3x3_007af9a0], cx
        mov      ecx, dword ptr [g_eventQueueSeed]
        mov      dword ptr [g_mat3x3_007af99c], edx
        mov      dword ptr [g_vtxTransX], esi
        mov      dword ptr [g_vtxTransY], esi
        mov      dword ptr [g_vtxTransZ], esi
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      edi, dword ptr [ecx*4 + 0x58]
        shl      edi, 8
        sar      edi, 0x10
        mov      ecx, edi
        mov      ebx, OFFSET g_dispatchSave1513
        neg      ecx
        mov      dword ptr [esp + 0xc], ecx
        mov      cl, 0x1c
        sar      eax, 1
        mov      byte ptr [esp + 0x5e], cl
        mov      byte ptr [esp + 0x60], cl
        mov      byte ptr [esp + 0x5c], cl
        mov      cl, 0x64
        cmp      eax, esi
        mov      dword ptr [esp + 0x18], edi
        mov      word ptr [esp + 0x64], si
        mov      word ptr [esp + 0x6a], 0xf
        mov      byte ptr [esp + 0x5f], cl
        mov      byte ptr [esp + 0x61], cl
        mov      byte ptr [esp + 0x5d], cl
        jle      L_cc3c
        push     ebp
        mov      dword ptr [esp + 0x18], eax
        jmp      L_c8c5
    L_c8c1:
        mov      edi, dword ptr [esp + 0x1c]
    L_c8c5:
        mov      edx, dword ptr [g_dispatchSave1554]
        mov      ecx, dword ptr [g_dispatchSave1556]
        mov      eax, dword ptr [g_dispatchSave1555]
        mov      dword ptr [g_vtxMat], edx
        mov      edx, dword ptr [g_dispatchSave1557]
        mov      dword ptr [g_mat3x3_007af998], ecx
        movsx    ecx, word ptr [ebx]
        mov      dword ptr [g_mat3x3_007af99c], edx
        mov      dword ptr [g_mat3x3_007af994], eax
        movsx    edx, word ptr [ebx + 2]
        mov      ax, word ptr [g_dispatchSave1558]
        mov      dword ptr [esp + 0x24], ecx
        mov      word ptr [g_mat3x3_007af9a0], ax
        mov      dword ptr [esp + 0x28], edx
        movsx    eax, word ptr [ebx + 4]
        lea      ecx, [esp + 0x30]
        lea      edx, [esp + 0x24]
        push     ecx
        push     edx
        mov      dword ptr [esp + 0x34], eax
        call     Mat3x3VecMul
        mov      eax, dword ptr [esp + 0x3c]
        mov      ecx, dword ptr [esp + 0x38]
        movsx    ebp, word ptr [g_camRotXBam]
        mov      dword ptr [g_xformEntityIdx], eax
        add      eax, edi
        neg      eax
        mov      esi, eax
        mov      dword ptr [g_currentNodeIdx], ecx
        imul     esi, ebp
        sar      esi, 0xc
        add      esi, ecx
        mov      edx, dword ptr [esp + 0x40]
        movsx    ecx, word ptr [g_camRotZBam]
        imul     eax, ecx
        sar      eax, 0xc
        add      ebx, 6
        add      eax, edx
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [esp + 0x28], eax
        movsx    edx, word ptr [ebx]
        movsx    eax, word ptr [ebx + 2]
        movsx    ecx, word ptr [ebx + 4]
        add      esp, 8
        mov      dword ptr [esp + 0x3c], edx
        mov      dword ptr [esp + 0x40], eax
        lea      edx, [esp + 0x48]
        lea      eax, [esp + 0x3c]
        push     edx
        push     eax
        mov      dword ptr [esp + 0x4c], ecx
        call     Mat3x3VecMul
        mov      eax, dword ptr [esp + 0x54]
        mov      ecx, dword ptr [esp + 0x50]
        movsx    ebp, word ptr [g_camRotXBam]
        mov      dword ptr [g_xformEntityIdx], eax
        add      eax, edi
        neg      eax
        mov      edi, eax
        mov      dword ptr [g_currentNodeIdx], ecx
        imul     edi, ebp
        sar      edi, 0xc
        add      edi, ecx
        mov      edx, dword ptr [esp + 0x58]
        movsx    ecx, word ptr [g_camRotZBam]
        imul     eax, ecx
        sar      eax, 0xc
        add      eax, edx
        mov      dword ptr [g_pendingNodeType], edx
        mov      ecx, eax
        mov      eax, edi
        sub      eax, esi
        add      esp, 8
        cdq
        and      edx, 3
        add      ebx, 6
        add      eax, edx
        mov      dword ptr [esp + 0x14], ecx
        mov      ebp, eax
        mov      eax, ecx
        sar      ebp, 2
        mov      ecx, dword ptr [esp + 0x20]
        sub      eax, ecx
        cdq
        and      edx, 3
        add      eax, edx
        mov      edx, esi
        sar      eax, 2
        sub      edx, eax
        mov      dword ptr [esp + 0x20], eax
        mov      word ptr [g_dispatchSave1626], dx
        mov      dx, word ptr [esp + 0x10]
        mov      word ptr [g_vtxIn1_y], dx
        lea      edx, [ebp + ecx]
        mov      word ptr [g_vtxIn2_y], dx
        lea      edx, [eax + esi]
        mov      word ptr [g_vtxIn2_x], dx
        mov      edx, dword ptr [esp + 0x10]
        sub      ecx, ebp
        mov      word ptr [g_vtxIn1_z], dx
        mov      word ptr [g_vtxIn2_z], cx
        mov      ecx, edi
        mov      word ptr [g_triStripX1], dx
        mov      edx, dword ptr [esp + 0x14]
        sub      ecx, eax
        mov      word ptr [g_triStripX0], cx
        mov      ecx, dword ptr [g_vtxMatBase]
        lea      eax, [ebp + edx]
        mov      edx, dword ptr [g_dispatchSave1530]
        mov      word ptr [g_triStripX2], ax
        mov      eax, dword ptr [g_dispatchSave1531]
        mov      dword ptr [g_vtxMat], ecx
        mov      ecx, dword ptr [g_dispatchSave1532]
        mov      dword ptr [g_mat3x3_007af994], edx
        mov      dx, word ptr [g_dispatchSave1533]
        mov      dword ptr [g_mat3x3_007af998], eax
        mov      dword ptr [g_mat3x3_007af99c], ecx
        mov      word ptr [g_mat3x3_007af9a0], dx
        call     ProjectTwoVertices
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    esi, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      esi, eax
        imul     edx, esi
        movsx    esi, word ptr [g_vtxScreenP2Y]
        sub      esi, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     esi, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, esi
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [esp + 0x54], ecx
        mov      ecx, dword ptr [esp + 0x6e]
        mov      dword ptr [esp + 0x58], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        and      ecx, 0xfbff
        mov      dword ptr [esp + 0x5c], eax
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [esp + 0x6e], cx
        call     MaxOfThree
        mov      word ptr [esp + 0x66], ax
        mov      eax, dword ptr [g_triStripRingB]
        test     eax, eax
        jle      L_cb5a
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_cb5a
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_cb5a
        lea      eax, [esp + 0x54]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_cb5a:
        mov      eax, dword ptr [esp + 0x14]
        mov      edx, dword ptr [esp + 0x20]
        mov      ecx, dword ptr [esp + 0x10]
        sub      eax, ebp
        push     eax
        add      edx, edi
        push     ecx
        push     edx
        call     AdvanceTriStripRing
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    esi, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      esi, eax
        imul     edx, esi
        movsx    esi, word ptr [g_vtxScreenP2Y]
        sub      esi, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     esi, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, esi
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [esp + 0x54], ecx
        mov      ecx, dword ptr [esp + 0x6e]
        mov      dword ptr [esp + 0x58], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        and      ecx, 0xfbff
        mov      dword ptr [esp + 0x5c], eax
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [esp + 0x6e], cx
        call     MaxOfThree
        mov      word ptr [esp + 0x66], ax
        mov      eax, dword ptr [g_triStripRingB]
        test     eax, eax
        jle      L_cc2c
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_cc2c
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_cc2c
        lea      eax, [esp + 0x54]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_cc2c:
        mov      eax, dword ptr [esp + 0x18]
        dec      eax
        mov      dword ptr [esp + 0x18], eax
        jne      L_c8c1
        pop      ebp
    L_cc3c:
        pop      edi
        pop      esi
        pop      ebx
        add      esp, 0x64
        ret
    }
}

#endif
