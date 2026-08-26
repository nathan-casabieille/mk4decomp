/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "engine/render_types.h"
#include "game/tick.h"

extern unsigned int g_screenH;
extern unsigned int g_menuRestoreSlot;
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
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP1Y;
extern s16 g_vtxScreenP2X;
extern s16 g_vtxScreenP2Y;
extern s16 g_vtxScreenX;
extern s16 g_vtxScreenY;
extern u16 g_vtxColorCopy;
extern u16 g_vtxColorSaved;
extern u16 g_vtxColor;
extern unsigned int g_dispatchSave1501;
extern unsigned int g_dispatchSave1559;
extern unsigned int g_dispatchSave1570;
extern unsigned int g_dispatchSave1574;
extern unsigned int g_dispatchSave1576;
extern void AdvanceTriStripRing(s16 v0, s16 v1, s16 v2);
extern void AltCamMatrixProject(int *vec, int mode);
extern void Helper_DrawCursor(void *entry);
extern void MatVec2Multiply(void);
extern int MaxOfThree(void);
extern int MinOfThree(void);
extern void ProjectTwoVertices(void);
extern void ProjectVertex(void);
extern void TransformVertex(short x, short y, short z);
extern void TristripBatchEmit3Cap(int block, int a1, int a2);

/*
 * @addr 0x004bb250 - per-block triangle-strip mesh walker.
 *
 * NON-COAXABLE: kept naked. This is the central consumer of the .geo
 * mesh format (see geo_block / geo_vertex / geo_strip_header in
 * include/engine/geo.h). Mapping the raw offsets to those struct
 * fields (edi = block ptr from [esp+0x20]):
 *
 *   mov eax,[edi+8]            ; block->ofs_b
 *   mov ecx,[edi+4]            ; block->ofs_a
 *   lea ebx,[eax+edi+8]        ; header = (geo_strip_header*)(block+8+ofs_b)
 *   lea edi,[edi+ecx+4]        ; verts  = (geo_vertex*)(block+4+ofs_a)
 *
 * Strip loop (L_b2f2):
 *   mov bp,[ebx]; add ebx,2    ; flag  = header->flag  (bit 0 winding, bit 8 draw-flag)
 *   movsx eax,[ebx]; add ebx,2 ; count = header->count; if (count < 0) end of block
 *
 * Vertex reads off `edi` (12-byte geo_vertex, advances 0x18 = 2 verts):
 *   [edi+0..4]   v0.pos_x/y/z   -> tri-strip ring
 *   [edi+6..0xa] v0.nrm_x/y/z   -> TransformVertex (rotation)
 *   [edi+0xc..0x10] v1.pos      ; [edi+0x14..0x1e] v1.nrm
 *
 * Output side (esi = DrawEntry, see include/engine/render_types.h): writes
 * the three projected screen verts as packed X:low/Y:high dwords to
 * +0/+4/+8 (DrawEntry.x0/y0, x1/y1, x2/y2), the facing/valid bit into
 * flags (+0x1a bit 0x400), and the shaded RGB555 colors to +0x14/+0x16/
 * +0x18, then tail-calls SubmitDrawEntry. This function is the bridge
 * from the .geo mesh format to the draw queue.
 */
#ifdef NON_MATCHING
/* Co-exec verified (tools/decomp/verify_mesh.py).
 *
 * The .geo main-path emitter. Same shape as TristripBatchEmit but it also
 * shades every vertex through TransformVertex, applies a depth attenuation to
 * the three vertex colours, and folds g_dispatchSave1559 into the sort key.
 *
 * Block layout (decoded in tools/geo_mesh.py): ofs_a / ofs_b at block+4 /
 * block+8 are RELATIVE TO THEIR OWN FIELD. Vertices are 12 bytes - 3 s16
 * position then 3 s16 normal - but the normal reaches TransformVertex as
 * (x=+8, y=+0xa, z=+6), and a strip opens by consuming TWO of them (edi += 0x18).
 *
 * TRANSCRIBED QUIRK: for the SECOND base vertex the original reads the normal
 * z from [edi+0x1e], not [edi+0x12] where a 12-byte stride would put it - i.e.
 * it reaches into the NEXT vertex. Reproduced exactly; do not "fix" it.
 */
void DrawMeshBlock(int block, int a1, int a2)
{
    unsigned char *strip, *vtx, *entry, *strip_save;
    int count, parity, atten, bit8, cross, valid, key;
    unsigned int flags;

    if (g_inLoopStep != 0)
        return;
    if (g_menuRestoreSlot == 0) {              /* the non-mesh fast path */
        TristripBatchEmit3Cap(block, a1, a2);
        return;
    }
    if (*(int *)MK4_PTR(block + 4) == 0)
        return;

    if (g_dispatchSave1570 != 0 && (int)g_dispatchSave1574 < 0)
        AltCamMatrixProject((int *)&g_dispatchSave1501, 1);

    /* depth attenuation step: orig cdq / and edx,7 / add / sar 3 / dec */
    atten = (int)g_dispatchSave1576;
    if (atten >= 0x10)
        atten = ((atten + ((atten >> 31) & 7)) >> 3) - 1;
    else
        atten = 0;

    strip = (unsigned char *)MK4_PTR(block + 8 + *(int *)MK4_PTR(block + 8));
    vtx   = (unsigned char *)MK4_PTR(block + 4 + *(int *)MK4_PTR(block + 4));
    entry = (unsigned char *)MK4_PTR(g_dualC + 4);
    MatVec2Multiply();

    for (;;) {                                  /* per strip */
        flags = *(unsigned short *)strip;
        strip += 2;
        bit8 = (int)((flags >> 8) & 1);
        parity = (int)(flags & 1);
        if (a1 != 0)
            parity = (parity == 0);
        count = *(short *)strip;
        strip += 2;
        if (count < 0)                          /* negative count terminates */
            return;
        strip_save = strip;

        /* --- open the strip on two vertices --- */
        *(short *)&g_dispatchSave1626 = 0;
        *(short *)&g_vtxIn1_y = 0;
        *(short *)&g_vtxIn2_y = 0;
        *(short *)&g_vtxIn2_x = *(short *)(vtx + 0);
        *(short *)&g_vtxIn1_z = *(short *)(vtx + 2);
        *(short *)&g_vtxIn2_z = *(short *)(vtx + 4);
        TransformVertex(*(short *)(vtx + 8), *(short *)(vtx + 0xa),
                        *(short *)(vtx + 6));
        *(short *)&g_triStripX0 = *(short *)(vtx + 0xc);
        *(short *)&g_triStripX1 = *(short *)(vtx + 0xe);
        *(short *)&g_triStripX2 = *(short *)(vtx + 0x10);
        TransformVertex(*(short *)(vtx + 0x14), *(short *)(vtx + 0x16),
                        *(short *)(vtx + 0x1e));   /* see the quirk note */
        ProjectTwoVertices();
        count = count + 1;
        vtx += 0x18;

        do {                                    /* one triangle per vertex */
            AdvanceTriStripRing(*(short *)(vtx + 0), *(short *)(vtx + 2),
                                *(short *)(vtx + 4));
            TransformVertex(*(short *)(vtx + 8), *(short *)(vtx + 0xa),
                            *(short *)(vtx + 6));
            ProjectVertex();

            /* backface: sign of the 2D cross product of the two screen edges */
            cross = ((int)*(short *)&g_vtxScreenY - (int)*(short *)&g_vtxScreenP1Y)
                  * ((int)*(short *)&g_vtxScreenP2X - (int)*(short *)&g_vtxScreenP1X)
                  - ((int)*(short *)&g_vtxScreenP2Y - (int)*(short *)&g_vtxScreenP1Y)
                  * ((int)*(short *)&g_vtxScreenX - (int)*(short *)&g_vtxScreenP1X);
            valid = (cross <= 0);
            g_vtxValid = (unsigned int)valid;

            /* orig: sete dl (valid==0) / movsx eax,bp / cmp / JE skip - so a
               triangle is emitted only when the parity DIFFERS from the
               backface result. */
            if (parity != (valid == 0)
                && (int)g_vtxOut1_z > 0 && (int)g_vtxOut2_z > 0
                && (int)g_vtxOut_z > 0) {
                unsigned short *c0, *c1, *c2, *fl;

                *(unsigned int *)(entry + 0) = g_vtxScreenP1X;   /* packed X|Y */
                *(unsigned int *)(entry + 4) = g_vtxScreenP2X;
                *(unsigned int *)(entry + 8) = g_vtxScreenX;
                fl = (unsigned short *)(entry + 0x1a);
                *fl = (unsigned short)((*fl & 0xfbff)
                                       | (unsigned)((valid & 1) << 10));
                c0 = (unsigned short *)(entry + 0x14);
                c1 = (unsigned short *)(entry + 0x16);
                c2 = (unsigned short *)(entry + 0x18);
                *c0 = *(unsigned short *)&g_vtxColorCopy;
                *c1 = *(unsigned short *)&g_vtxColorSaved;
                *c2 = *(unsigned short *)&g_vtxColor;

                if ((short)atten < 0x20) {
                    /* scale each 5-bit channel by atten/32, in place. One
                       accessor per word: mixing widths here would let -O2 hoist
                       the reads and drop every insert but the last. */
                    int d = (short)atten;
                    unsigned short *cp[3];
                    int k;
                    cp[0] = c0; cp[1] = c1; cp[2] = c2;
                    for (k = 0; k < 3; k++) {
                        unsigned short *w = cp[k];
                        int t;
                        t = (((int)((*w >> 0xa) & 0x1f) * d) >> 5) & 0x1f;
                        *w = (unsigned short)((*w & 0x83ff) | (unsigned)(t << 0xa));
                        t = (((int)((*w >> 5) & 0x1f) * d) >> 5) & 0x1f;
                        *w = (unsigned short)((*w & 0xfc1f) | (unsigned)(t << 5));
                        t = ((int)(*w & 0x1f) * d) >> 5;
                        *w = (unsigned short)(*w ^ ((unsigned)(t ^ *w) & 0x1f));
                    }
                }

                key = (a2 == 0) ? MinOfThree() : MaxOfThree();
                *(unsigned short *)(entry + 0x12) =
                    (unsigned short)((g_dispatchSave1559 << 5) + (unsigned)key);
                *fl = (unsigned short)((*fl & 0xfe7f)
                                       | (unsigned)((bit8 & 3) << 7) | 0x10u);

                if (g_dispatchSave1570 != 0) {  /* clamp Y to the horizon */
                    short h = *(short *)&g_screenH;
                    if (*(short *)(entry + 2) > h)  *(short *)(entry + 2) = h;
                    if (*(short *)(entry + 6) > h)  *(short *)(entry + 6) = h;
                    if (*(short *)(entry + 0xa) > h) *(short *)(entry + 0xa) = h;
                }
                Helper_DrawCursor(entry);
            }

            vtx += 0xc;
            entry += 0x1c;
            parity = (parity == 0);
            count--;
        } while (count != 0);

        strip = strip_save;
    }
}
#else
__declspec(naked) void DrawMeshBlock(void)
{
    __asm {
        mov      eax, dword ptr [g_inLoopStep]
        sub      esp, 0xc
        test     eax, eax
        push     ebx
        push     ebp
        push     esi
        push     edi
        jne      L_b280
        mov      eax, dword ptr [g_menuRestoreSlot]
        test     eax, eax
        jne      L_b288
        mov      eax, dword ptr [esp + 0x28]
        mov      ecx, dword ptr [esp + 0x24]
        mov      edx, dword ptr [esp + 0x20]
        push     eax
        push     ecx
        push     edx
        call     TristripBatchEmit3Cap
        add      esp, 0xc
    L_b280:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    L_b288:
        mov      edi, dword ptr [esp + 0x20]
        mov      eax, dword ptr [edi + 4]
        test     eax, eax
        je       L_b280
        mov      eax, dword ptr [g_dispatchSave1570]
        test     eax, eax
        je       L_b2b4
        mov      eax, dword ptr [g_dispatchSave1574]
        test     eax, eax
        jge      L_b2b4
        push     1
        push     OFFSET g_dispatchSave1501
        call     AltCamMatrixProject
        add      esp, 8
    L_b2b4:
        mov      eax, dword ptr [g_dispatchSave1576]
        cmp      eax, 0x10
        jl       L_b2ce
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        mov      dword ptr [esp + 0x10], eax
        jmp      L_b2d6
    L_b2ce:
        mov      dword ptr [esp + 0x10], 0
    L_b2d6:
        mov      eax, dword ptr [edi + 8]
        mov      ecx, dword ptr [edi + 4]
        mov      edx, dword ptr [g_pendingNodeType]
        lea      ebx, [eax + edi + 8]
        lea      edi, [edi + ecx + 4]
        lea      esi, [edx + 4]
        call     MatVec2Multiply
    L_b2f2:
        mov      bp, word ptr [ebx]
        xor      ecx, ecx
        mov      eax, ebp
        add      ebx, 2
        shr      eax, 8
        and      al, 1
        and      ebp, 1
        mov      byte ptr [esp + 0x20], al
        mov      eax, dword ptr [esp + 0x24]
        cmp      eax, ecx
        je       L_b31a
        xor      eax, eax
        cmp      bp, cx
        sete     al
        mov      ebp, eax
    L_b31a:
        movsx    eax, word ptr [ebx]
        add      ebx, 2
        cmp      eax, ecx
        mov      dword ptr [esp + 0x14], eax
        mov      dword ptr [esp + 0x18], ebx
        jl       L_b280
        mov      word ptr [g_dispatchSave1626], cx
        mov      word ptr [g_vtxIn1_y], cx
        mov      word ptr [g_vtxIn2_y], cx
        mov      cx, word ptr [edi]
        mov      word ptr [g_vtxIn2_x], cx
        mov      dx, word ptr [edi + 2]
        mov      word ptr [g_vtxIn1_z], dx
        mov      ax, word ptr [edi + 4]
        mov      word ptr [g_vtxIn2_z], ax
        mov      cx, word ptr [edi + 6]
        mov      dx, word ptr [edi + 0xa]
        mov      ax, word ptr [edi + 8]
        push     ecx
        push     edx
        push     eax
        call     TransformVertex
        mov      cx, word ptr [edi + 0xc]
        add      esp, 0xc
        mov      word ptr [g_triStripX0], cx
        mov      dx, word ptr [edi + 0xe]
        mov      word ptr [g_triStripX1], dx
        mov      ax, word ptr [edi + 0x10]
        mov      word ptr [g_triStripX2], ax
        mov      cx, word ptr [edi + 0x1e]
        mov      dx, word ptr [edi + 0x16]
        mov      ax, word ptr [edi + 0x14]
        push     ecx
        push     edx
        push     eax
        call     TransformVertex
        add      esp, 0xc
        call     ProjectTwoVertices
        mov      ecx, dword ptr [esp + 0x14]
        add      edi, 0x18
        inc      ecx
        mov      dword ptr [esp + 0x14], ecx
    L_b3c3:
        mov      dx, word ptr [edi + 4]
        mov      ax, word ptr [edi + 2]
        mov      cx, word ptr [edi]
        push     edx
        push     eax
        push     ecx
        call     AdvanceTriStripRing
        mov      dx, word ptr [edi + 6]
        mov      ax, word ptr [edi + 0xa]
        mov      cx, word ptr [edi + 8]
        add      esp, 0xc
        push     edx
        push     eax
        push     ecx
        call     TransformVertex
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        sub      edx, ebx
        test     edx, edx
        setle    al
        xor      edx, edx
        mov      dword ptr [g_vtxValid], eax
        test     eax, eax
        movsx    eax, bp
        sete     dl
        cmp      eax, edx
        je       L_b656
        mov      eax, dword ptr [g_triStripRingB]
        test     eax, eax
        jle      L_b656
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_b656
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_b656
        mov      ecx, dword ptr [g_triStripRingA]
        mov      dword ptr [esi], ecx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      cx, word ptr [esi + 0x1a]
        mov      dword ptr [esi + 4], edx
        mov      eax, dword ptr [g_vtxScreenX]
        and      ecx, 0xfbff
        mov      dword ptr [esi + 8], eax
        mov      dl, byte ptr [g_vtxValid]
        and      edx, 1
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [esi + 0x1a], cx
        mov      ax, word ptr [g_vtxColorCopy]
        mov      word ptr [esi + 0x14], ax
        mov      cx, word ptr [g_vtxColorSaved]
        mov      eax, dword ptr [esp + 0x10]
        mov      word ptr [esi + 0x16], cx
        mov      dx, word ptr [g_vtxColor]
        cmp      ax, 0x20
        mov      word ptr [esi + 0x18], dx
        jge      L_b5cd
        mov      cx, word ptr [esi + 0x14]
        movsx    edx, ax
        mov      eax, ecx
        and      ecx, 0x83ff
        shr      eax, 0xa
        and      eax, 0x1f
        imul     eax, edx
        sar      eax, 5
        and      eax, 0x1f
        shl      eax, 0xa
        or       eax, ecx
        mov      ecx, eax
        and      eax, 0xfc1f
        shr      ecx, 5
        and      ecx, 0x1f
        imul     ecx, edx
        sar      ecx, 5
        and      ecx, 0x1f
        shl      ecx, 5
        or       ecx, eax
        mov      eax, ecx
        and      eax, 0x1f
        imul     eax, edx
        sar      eax, 5
        xor      al, cl
        and      eax, 0x1f
        xor      eax, ecx
        mov      cx, word ptr [esi + 0x16]
        mov      word ptr [esi + 0x14], ax
        mov      eax, ecx
        shr      eax, 0xa
        and      eax, 0x1f
        and      ecx, 0x83ff
        imul     eax, edx
        sar      eax, 5
        and      eax, 0x1f
        shl      eax, 0xa
        or       eax, ecx
        mov      ecx, eax
        and      eax, 0xfc1f
        shr      ecx, 5
        and      ecx, 0x1f
        imul     ecx, edx
        sar      ecx, 5
        and      ecx, 0x1f
        shl      ecx, 5
        or       ecx, eax
        mov      eax, ecx
        and      eax, 0x1f
        imul     eax, edx
        sar      eax, 5
        xor      al, cl
        and      eax, 0x1f
        xor      eax, ecx
        mov      cx, word ptr [esi + 0x18]
        mov      word ptr [esi + 0x16], ax
        mov      eax, ecx
        shr      eax, 0xa
        and      eax, 0x1f
        and      ecx, 0x83ff
        imul     eax, edx
        sar      eax, 5
        and      eax, 0x1f
        shl      eax, 0xa
        or       eax, ecx
        mov      ecx, eax
        and      eax, 0xfc1f
        shr      ecx, 5
        and      ecx, 0x1f
        imul     ecx, edx
        sar      ecx, 5
        and      ecx, 0x1f
        shl      ecx, 5
        or       ecx, eax
        mov      eax, ecx
        and      eax, 0x1f
        imul     eax, edx
        sar      eax, 5
        xor      al, cl
        and      eax, 0x1f
        xor      eax, ecx
        mov      word ptr [esi + 0x18], ax
    L_b5cd:
        mov      eax, dword ptr [esp + 0x28]
        test     eax, eax
        jne      L_b5dc
        call     MinOfThree
        jmp      L_b5e1
    L_b5dc:
        call     MaxOfThree
    L_b5e1:
        mov      word ptr [esi + 0x12], ax
        mov      ecx, dword ptr [g_dispatchSave1559]
        shl      ecx, 5
        mov      dx, word ptr [esi + 0x1a]
        add      ecx, eax
        mov      al, byte ptr [esp + 0x20]
        mov      word ptr [esi + 0x12], cx
        and      al, 3
        and      edx, 0xfe7f
        movsx    cx, al
        shl      ecx, 7
        or       edx, ecx
        or       edx, 0x10
        mov      word ptr [esi + 0x1a], dx
        mov      eax, dword ptr [g_dispatchSave1570]
        test     eax, eax
        je       L_b64d
        mov      ax, word ptr [g_screenH]
        cmp      word ptr [esi + 2], ax
        jle      L_b633
        mov      word ptr [esi + 2], ax
        mov      ax, word ptr [g_screenH]
    L_b633:
        cmp      word ptr [esi + 6], ax
        jle      L_b643
        mov      word ptr [esi + 6], ax
        mov      ax, word ptr [g_screenH]
    L_b643:
        cmp      word ptr [esi + 0xa], ax
        jle      L_b64d
        mov      word ptr [esi + 0xa], ax
    L_b64d:
        push     esi
        call     Helper_DrawCursor
        add      esp, 4
    L_b656:
        mov      eax, dword ptr [esp + 0x14]
        add      edi, 0xc
        xor      edx, edx
        test     bp, bp
        sete     dl
        add      esi, 0x1c
        dec      eax
        mov      ebp, edx
        mov      dword ptr [esp + 0x14], eax
        jne      L_b3c3
        mov      ebx, dword ptr [esp + 0x18]
        jmp      L_b2f2
    }
}
#endif
