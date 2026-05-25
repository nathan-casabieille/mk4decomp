/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_data_004f623c;
extern unsigned int g_data_00543aa8;
extern u32 g_inLoopStep;
extern unsigned int g_data_007af958[];
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
extern unsigned int g_data_00ab4398;
extern unsigned int g_data_00ab4d9c;
extern unsigned int g_data_00ab4e28;
extern unsigned int g_data_00ab4e3c;
extern unsigned int g_data_00ab4e60;
extern void AdvanceTriStripRing(void);
extern void AltCamMatrixProject_004b9840(void);
extern void Helper_DrawCursor(void);
extern void MatVec2Multiply_004b31e0(void);
extern void MaxOfThree_004b3d90(void);
extern void MinOfThree_004b3d70(void);
extern void ProjectTwoVertices(void);
extern void ProjectVertex(void);
extern void TransformVertex(void);
extern void TristripBatchEmit3Cap_004bb680(void);

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
        mov      eax, dword ptr [g_data_00543aa8]
        test     eax, eax
        jne      L_b288
        mov      eax, dword ptr [esp + 0x28]
        mov      ecx, dword ptr [esp + 0x24]
        mov      edx, dword ptr [esp + 0x20]
        push     eax
        push     ecx
        push     edx
        call     TristripBatchEmit3Cap_004bb680
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
        mov      eax, dword ptr [g_data_00ab4e28]
        test     eax, eax
        je       L_b2b4
        mov      eax, dword ptr [g_data_00ab4e3c]
        test     eax, eax
        jge      L_b2b4
        push     1
        push     OFFSET g_data_00ab4398
        call     AltCamMatrixProject_004b9840
        add      esp, 8
    L_b2b4:
        mov      eax, dword ptr [g_data_00ab4e60]
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
        call     MatVec2Multiply_004b31e0
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
        mov      word ptr [g_data_007af958], cx
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
        call     MinOfThree_004b3d70
        jmp      L_b5e1
    L_b5dc:
        call     MaxOfThree_004b3d90
    L_b5e1:
        mov      word ptr [esi + 0x12], ax
        mov      ecx, dword ptr [g_data_00ab4d9c]
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
        mov      eax, dword ptr [g_data_00ab4e28]
        test     eax, eax
        je       L_b64d
        mov      ax, word ptr [g_data_004f623c]
        cmp      word ptr [esi + 2], ax
        jle      L_b633
        mov      word ptr [esi + 2], ax
        mov      ax, word ptr [g_data_004f623c]
    L_b633:
        cmp      word ptr [esi + 6], ax
        jle      L_b643
        mov      word ptr [esi + 6], ax
        mov      ax, word ptr [g_data_004f623c]
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

