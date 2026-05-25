/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_eq_00542098;
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af9a0;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern unsigned int g_dispatchSave1501_00ab4398;
extern unsigned int g_dispatchSave1502_00ab439c;
extern unsigned int g_dispatchSave1503_00ab43a0;
extern unsigned int g_dispatchSave1525_00ab4838;
extern unsigned int g_dispatchSave1526_00ab483c;
extern unsigned int g_dispatchSave1527_00ab4840;
extern unsigned int g_dispatchSave1528_00ab4844;
extern unsigned int g_dispatchSave1529_00ab4848;
extern unsigned int g_dispatchSave1554_00ab4d58;
extern unsigned int g_dispatchSave1555_00ab4d5c;
extern unsigned int g_dispatchSave1556_00ab4d60;
extern unsigned int g_dispatchSave1557_00ab4d64;
extern unsigned int g_dispatchSave1558_00ab4d68;
extern unsigned int g_dispatchSave1559_00ab4d9c;
extern unsigned int g_dispatchSave1570_00ab4e28;
extern unsigned int g_dispatchSave1572_00ab4e34;
extern unsigned int g_dispatchSave1573_00ab4e38;
extern unsigned int g_dispatchSave1575_00ab4e5c;
extern unsigned int g_dispatchSave1576_00ab4e60;
extern unsigned int g_dispatchSave1577_00ab4e6c;
extern unsigned int g_dispatchSave1333_00f00004;
extern void BboxProjectAndStash_004bc5a0(void);
extern void BillboardChainRender_004bb030(void);
extern void BillboardSheetDualEmit_004bbda0(void);
extern void DirtyBitTripleWriteOrCall_004ba630(void);
extern void DirtyTestScaledCopy_004ba6c0(void);
extern void DrawMeshBlock(void);
extern void LeaScaledCall_004bd510(void);
extern void MStackPushCallCallPop_00405dd0(void);
extern void MatrixTransform3x3Q12_004b3b80(void);
extern void MovesPanelEmit_004bcf60(void);
extern void TransformAccumulate_004bddf0(void);
extern void TristripBatchEmit2_004bb930(void);
extern void TristripBatchEmit3Cap_004bb680(void);
extern void TristripBatchEmit_004bbb80(void);
extern void VertexQuadBuilder_004bc470(void);
extern void VibrationFrameUpdate_004b9640(void);
extern void VtableDispatchSetDirty_004ba040(void);
extern void WtSnapshotPushCall_004bda70(void);
extern void ZBucketClampStore_004ba5d0(void);

__declspec(naked) void RenderSceneNode(void)
{
    __asm {
    L_a720:
        mov      eax, dword ptr [g_dispatchSave1573_00ab4e38]
        sub      esp, 0x20
        test     eax, eax
        push     ebx
        push     ebp
        push     esi
        push     edi
        je       L_ae67
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edi, dword ptr [eax*4 + 0x20]
        test     edi, 0x2000
        mov      dword ptr [g_currentNodeFlags], edi
        je       L_a78d
        call     ZBucketClampStore_004ba5d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
        mov      eax, dword ptr [g_eq_00542098]
        test     eax, eax
        jne      L_ae7b
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4]
        test     ecx, ecx
        mov      dword ptr [g_eventQueueWorkType], ecx
        je       L_ae67
        mov      edi, dword ptr [g_currentNodeFlags]
    L_a78d:
        mov      edx, dword ptr [g_pendingNodeType]
        mov      esi, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_eventQueueEnd]
        lea      ebp, [eax*4]
        mov      dword ptr [esp + 0x1c], edx
        mov      dword ptr [g_eventQueueTotal], edx
        mov      edx, dword ptr [ebp + 0x3c]
        mov      ebx, eax
        test     edx, edx
        mov      dword ptr [esp + 0x14], ebx
        mov      dword ptr [esp + 0x10], esi
        mov      dword ptr [esp + 0x20], ecx
        mov      dword ptr [esp + 0x18], ebp
        jne      L_a81e
        mov      edx, dword ptr [ebp + 0x40]
        test     edx, edx
        jne      L_a81e
        mov      edx, dword ptr [ebp + 0x44]
        test     edx, edx
        jne      L_a81e
        lea      eax, [esi*4]
        mov      dword ptr [g_eventQueueEnd], eax
        mov      ecx, dword ptr [eax]
        mov      dword ptr [g_vtxMat], ecx
        mov      edx, dword ptr [eax + 4]
        mov      dword ptr [g_mat3x3_007af994], edx
        mov      ecx, dword ptr [eax + 8]
        mov      dword ptr [g_mat3x3_007af998], ecx
        mov      edx, dword ptr [eax + 0xc]
        mov      dword ptr [g_mat3x3_007af99c], edx
        mov      ax, word ptr [eax + 0x10]
        mov      word ptr [g_mat3x3_007af9a0], ax
        mov      eax, dword ptr [g_xformDirtyFlags]
        and      al, 0xef
        mov      dword ptr [g_xformDirtyFlags], eax
        jmp      L_a89b
    L_a81e:
        add      eax, 0xf
        add      ecx, 0x14
        mov      dword ptr [g_xformEntityIdx], eax
        mov      eax, edi
        sar      eax, 0x18
        and      eax, 7
        mov      dword ptr [g_eventQueueEnd], ecx
        test     edi, 0x100
        je       L_a842
        add      eax, 8
    L_a842:
        mov      edx, OFFSET g_nodeDispatchTable
        sar      edx, 2
        add      eax, edx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        sar      ecx, 2
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_currentNodeIdx], ecx
        call     eax
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [esp + 0x10]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     WtSnapshotPushCall_004bda70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
    L_a89b:
        mov      eax, OFFSET g_dispatchSave1501_00ab4398
        lea      edx, [ebx + 0xc]
        sar      eax, 2
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [g_currentNodeIdx], eax
        call     TransformAccumulate_004bddf0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
        mov      eax, dword ptr [g_currentNodeFlags]
        test     eax, OFFSET g_dispatchSave1333_00f00004
        jne      L_a97c
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_dispatchSave1501_00ab4398]
        test     cl, 0x60
        je       L_a8f8
        sar      edx, 0x11
        mov      dword ptr [g_vtxTransX], edx
        mov      edx, dword ptr [g_dispatchSave1502_00ab439c]
        sar      edx, 0x11
        jmp      L_a90a
    L_a8f8:
        sar      edx, 8
        mov      dword ptr [g_vtxTransX], edx
        mov      edx, dword ptr [g_dispatchSave1502_00ab439c]
        sar      edx, 8
    L_a90a:
        mov      dword ptr [g_vtxTransY], edx
        mov      edx, dword ptr [g_dispatchSave1503_00ab43a0]
        sar      edx, 8
        mov      dword ptr [g_vtxTransZ], edx
        mov      edx, dword ptr [g_eventQueueEnd]
        sar      edx, 2
        mov      dword ptr [g_pendingNodeType], edx
        mov      edx, eax
        or       edx, ecx
        test     dl, 0x80
        jne      L_a9c4
        mov      ecx, dword ptr [ebx*4 + 0x24]
        test     ecx, ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        je       L_a9c4
        mov      ecx, dword ptr [ecx*4 + 4]
        mov      dword ptr [g_xformEntityIdx], ecx
        sar      ecx, 0xc
        and      ecx, 0x7ff
        mov      dword ptr [g_walkCallback], ecx
        je       L_a9c4
        call     DirtyTestScaledCopy_004ba6c0
        test     eax, eax
        mov      eax, dword ptr [g_currentNodeFlags]
        je       L_a9c4
        mov      ebp, dword ptr [esp + 0x18]
    L_a97c:
        or       ah, 0x20
        mov      dword ptr [g_currentNodeIdx], ebx
        mov      dword ptr [g_currentNodeFlags], eax
        mov      dword ptr [ebx*4 + 0x20], eax
        mov      eax, dword ptr [g_fightGroupHead]
        test     ah, 0x40
        jne      L_a9aa
        push     1
        call     LeaScaledCall_004bd510
        add      esp, 4
        jmp      L_adb3
    L_a9aa:
        call     MStackPushCallCallPop_00405dd0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_ab22
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x20
        ret
    L_a9c4:
        and      ah, 0xdf
        mov      dword ptr [g_currentNodeFlags], eax
        mov      dword ptr [ebx*4 + 0x20], eax
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeFlags]
        sar      eax, 2
        test     ch, 0x16
        mov      dword ptr [g_pendingNodeType], eax
        je       L_aab4
        mov      esi, 0x1000
        test     ecx, esi
        je       L_aa06
        push     ebx
        call     VtableDispatchSetDirty_004ba040
        add      esp, 4
        jmp      L_aaa7
    L_aa06:
        test     byte ptr [g_fightGroupHead], 2
        jne      L_aab4
        mov      cl, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [g_currentNodeIdx], OFFSET g_dispatchSave1525_00ab4838
        test     cl, 0x30
        je       L_aa7d
        mov      edx, dword ptr [g_dispatchSave1555_00ab4d5c]
        mov      ecx, dword ptr [g_dispatchSave1554_00ab4d58]
        mov      dword ptr [g_mat3x3_007af994], edx
        mov      edx, dword ptr [g_dispatchSave1557_00ab4d64]
        mov      dword ptr [g_vtxMat], ecx
        mov      ecx, dword ptr [g_dispatchSave1556_00ab4d60]
        mov      dword ptr [g_mat3x3_007af99c], edx
        mov      dword ptr [g_mat3x3_007af998], ecx
        mov      cx, word ptr [g_dispatchSave1558_00ab4d68]
        lea      edx, [eax*4]
        push     OFFSET g_dispatchSave1525_00ab4838
        push     edx
        mov      word ptr [g_mat3x3_007af9a0], cx
        call     MatrixTransform3x3Q12_004b3b80
        add      esp, 8
        jmp      L_aa9b
    L_aa7d:
        xor      eax, eax
        mov      dword ptr [g_dispatchSave1525_00ab4838], esi
        mov      dword ptr [g_dispatchSave1526_00ab483c], eax
        mov      dword ptr [g_dispatchSave1527_00ab4840], esi
        mov      dword ptr [g_dispatchSave1528_00ab4844], eax
        mov      dword ptr [g_dispatchSave1529_00ab4848], esi
    L_aa9b:
        mov      eax, dword ptr [g_xformDirtyFlags]
        or       al, 0x30
        mov      dword ptr [g_xformDirtyFlags], eax
    L_aaa7:
        mov      eax, OFFSET g_dispatchSave1525_00ab4838
        sar      eax, 2
        mov      dword ptr [g_pendingNodeType], eax
    L_aab4:
        mov      edx, dword ptr [g_tickW1]
        mov      ecx, dword ptr [g_dispatchSave1577_00ab4e6c]
        mov      dword ptr [g_dispatchSave1576_00ab4e60], edx
        mov      edx, dword ptr [g_tickDecay]
        test     edx, edx
        mov      dword ptr [g_dispatchSave1575_00ab4e5c], ecx
        je       L_aadc
        mov      dword ptr [g_dispatchSave1576_00ab4e60], ecx
    L_aadc:
        mov      dword ptr [g_currentNodeIdx], ebx
        mov      ecx, dword ptr [ebx*4 + 0x28]
        test     ecx, ecx
        mov      dword ptr [g_xformEntityIdx], ecx
        je       L_ab84
        mov      edx, dword ptr [ecx*4 + 0x10]
        test     edx, edx
        mov      dword ptr [g_walkCallback], edx
        je       L_ab56
        mov      esi, eax
        call     edx
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
        mov      eax, dword ptr [g_currentNodeIdx]
        test     eax, eax
        jne      L_ab40
    L_ab22:
        mov      eax, dword ptr [g_xformDirtyFlags]
        mov      dword ptr [g_dispatchSave1573_00ab4e38], 0
        and      al, 0xfe
        mov      dword ptr [g_xformDirtyFlags], eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x20
        ret
    L_ab40:
        cmp      eax, -1
        je       L_adaf
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, esi
        mov      dword ptr [g_pendingNodeType], eax
    L_ab56:
        mov      ecx, dword ptr [ecx*4]
        test     cl, 8
        mov      dword ptr [g_walkCallback], ecx
        je       L_ab72
        call     DirtyBitTripleWriteOrCall_004ba630
        mov      eax, dword ptr [g_pendingNodeType]
    L_ab72:
        mov      ecx, dword ptr [g_tickFlagZ]
        test     ecx, ecx
        je       L_ab9c
        push     ebx
        call     VibrationFrameUpdate_004b9640
        jmp      L_ab94
    L_ab84:
        mov      ecx, dword ptr [g_tickX1]
        test     ecx, ecx
        je       L_ab9c
        push     ecx
        call     Helper_TickInit
    L_ab94:
        mov      eax, dword ptr [g_pendingNodeType]
        add      esp, 4
    L_ab9c:
        test     byte ptr [g_xformDirtyFlags], 0x10
        je       L_abd5
        shl      eax, 2
        mov      ecx, dword ptr [eax]
        mov      dword ptr [g_vtxMat], ecx
        mov      edx, dword ptr [eax + 4]
        mov      dword ptr [g_mat3x3_007af994], edx
        mov      ecx, dword ptr [eax + 8]
        mov      dword ptr [g_mat3x3_007af998], ecx
        mov      edx, dword ptr [eax + 0xc]
        mov      dword ptr [g_mat3x3_007af99c], edx
        mov      ax, word ptr [eax + 0x10]
        mov      word ptr [g_mat3x3_007af9a0], ax
    L_abd5:
        mov      dword ptr [g_currentNodeIdx], ebx
        mov      eax, dword ptr [ebx*4 + 0x24]
        test     eax, eax
        mov      dword ptr [g_eventQueueTotal], eax
        jne      L_ac05
        test     dword ptr [g_fightGroupHead], 0x20000
        je       L_adaf
        call     BillboardChainRender_004bb030
        jmp      L_adaf
    L_ac05:
        mov      edi, dword ptr [eax*4 + 4]
        test     edi, edi
        mov      dword ptr [g_xformEntityIdx], edi
        jne      L_ac20
        call     MovesPanelEmit_004bcf60
        jmp      L_adaf
    L_ac20:
        mov      ebp, dword ptr [eax*4 + 0x18]
        mov      eax, dword ptr [edi + 4]
        test     eax, eax
        jle      L_adaf
        mov      ecx, ebp
        shl      ecx, 4
        lea      esi, [ecx + eax + 0xc]
        xor      ecx, ecx
        mov      cl, byte ptr [esi]
        test     cl, 0x80
        mov      dword ptr [g_dispatchSave1572_00ab4e34], ecx
        je       L_ac7f
        test     cl, 1
        je       L_ac6c
        mov      edx, dword ptr [esp + 0x10]
        lea      eax, [esi + 0x10]
        push     edx
        push     eax
        call     BillboardSheetDualEmit_004bbda0
        add      esp, 8
        mov      dword ptr [g_xformEntityIdx], edi
        mov      dword ptr [g_currentNodeIdx], ebx
    L_ac6c:
        mov      ecx, dword ptr [esp + 0x10]
        push     ecx
        push     esi
        call     BillboardSheetDualEmit_004bbda0
        add      esp, 8
        jmp      L_adaf
    L_ac7f:
        test     byte ptr [g_currentNodeFlags], 0x40
        jne      L_adaf
        xor      edx, edx
        mov      dword ptr [g_walkCallback], edx
        mov      eax, dword ptr [ebx*4 + 0x48]
        test     eax, eax
        mov      dword ptr [g_pendingNodeType], eax
        je       L_acce
        mov      ebx, dword ptr [g_fightGroupHead]
        mov      edx, esi
        sar      ebx, 0x10
        shl      edx, 5
        and      ebx, 8
        or       edx, ebx
        mov      ebx, dword ptr [eax]
        or       edx, ecx
        cmp      ebx, edx
        je       L_acf3
        mov      ebx, dword ptr [esp + 0x14]
        mov      edx, 1
        mov      dword ptr [g_walkCallback], edx
    L_acce:
        push     edx
        push     ebp
        call     VertexQuadBuilder_004bc470
        mov      eax, dword ptr [g_pendingNodeType]
        add      esp, 8
        test     eax, eax
        je       L_adaf
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_dispatchSave1572_00ab4e34]
        jmp      L_acfd
    L_acf3:
        mov      ebx, dword ptr [esp + 0x14]
        mov      edx, dword ptr [g_fightGroupHead]
    L_acfd:
        add      eax, 4
        mov      dword ptr [g_baseSel_00542060], 0x1fff
        mov      dword ptr [g_pendingNodeType], eax
        mov      eax, edx
        and      eax, 1
        mov      ebp, edx
        test     cl, 0x40
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_xformEntityIdx], OFFSET g_dispatchSave1559_00ab4d9c
        je       L_ad3c
        mov      ecx, dword ptr [edi]
        xor      edx, edx
        mov      dx, word ptr [ecx + 8]
        push     edx
        push     eax
        push     esi
        call     TristripBatchEmit2_004bb930
        jmp      L_adac
    L_ad3c:
        test     edx, 0x80000
        je       L_ad87
        test     cl, 1
        je       L_ad87
        and      edx, 0x1000
        mov      dword ptr [g_dispatchSave1570_00ab4e28], edx
        mov      ecx, dword ptr [edi]
        xor      edx, edx
        mov      dx, word ptr [ecx + 8]
        push     edx
        push     eax
        push     esi
        call     DrawMeshBlock
        add      esp, 0xc
        mov      dword ptr [g_dispatchSave1570_00ab4e28], 0
        test     ebp, 0x40000
        je       L_adaf
        mov      dword ptr [g_xformEntityIdx], ebx
        call     BboxProjectAndStash_004bc5a0
        jmp      L_adaf
    L_ad87:
        test     cl, 2
        mov      ecx, dword ptr [edi]
        je       L_ad9e
        xor      edx, edx
        mov      dx, word ptr [ecx + 8]
        push     edx
        push     eax
        push     esi
        call     TristripBatchEmit_004bbb80
        jmp      L_adac
    L_ad9e:
        xor      edx, edx
        mov      dx, word ptr [ecx + 8]
        push     edx
        push     eax
        push     esi
        call     TristripBatchEmit3Cap_004bb680
    L_adac:
        add      esp, 0xc
    L_adaf:
        mov      ebp, dword ptr [esp + 0x18]
    L_adb3:
        mov      dword ptr [g_currentNodeIdx], ebx
        mov      eax, dword ptr [ebp]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       L_ae4a
        mov      ecx, dword ptr [g_dispatchSave1502_00ab439c]
        mov      eax, dword ptr [g_dispatchSave1501_00ab4398]
        mov      edx, dword ptr [g_dispatchSave1503_00ab43a0]
        mov      dword ptr [esp + 0x28], ecx
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [esp + 0x24], eax
        mov      dword ptr [esp + 0x2c], edx
        mov      eax, dword ptr [ebx*4 + 0xc]
        sar      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        lea      ecx, [esp + 0x24]
        sar      ecx, 2
        cmp      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_pendingNodeType], ecx
        je       L_ae33
        mov      dword ptr [g_walkCallback], OFFSET RenderSceneNode
        call     Helper_TickAlt
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_ae4a
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x20
        ret
    L_ae33:
        mov      edx, dword ptr [ebp]
        mov      dword ptr [g_currentNodeIdx], edx
        call     L_a720
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ae73
    L_ae4a:
        mov      eax, dword ptr [esp + 0x1c]
        mov      ecx, dword ptr [esp + 0x10]
        mov      edx, dword ptr [esp + 0x20]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_eventQueueEnd], edx
    L_ae67:
        mov      eax, dword ptr [g_xformDirtyFlags]
        and      al, 0xfe
        mov      dword ptr [g_xformDirtyFlags], eax
    L_ae73:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x20
        ret
    L_ae7b:
        mov      edi, dword ptr [g_currentNodeFlags]
        mov      eax, dword ptr [g_currentNodeIdx]
        jmp      L_a78d
    }
}

