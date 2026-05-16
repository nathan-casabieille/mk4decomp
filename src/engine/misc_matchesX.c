/**
 * Thirty-third batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_pendingNodeType;
extern const int g_sinTable[];
extern void Mul10Tail_00404af0(void);

/* @addr 0x0041f1f0 (54b)
 *   mov     eax, [g_eventQueueWorkType]
 *   push    eax
 *   push    0x028be602
 *   call    Mul10Tail
 *   sar     eax, 0x10
 *   sub     eax, 0x400
 *   add     esp, 8
 *   and     eax, 0xfff
 *   mov     [g_eventQueueWorkType], eax
 *   mov     ecx, [eax*4 + g_sinTable]
 *   sar     ecx, 0x0c
 *   mov     [g_walkCallback], ecx
 *   ret
 */
__declspec(naked) void RandSarMod0xFFFSub400_0041f1f0(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueWorkType]
        push    eax
        push    0x028be602
        call    Mul10Tail_00404af0
        sar     eax, 0x10
        sub     eax, 0x400
        add     esp, 8
        and     eax, 0xfff
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     ecx, dword ptr [eax*4 + g_sinTable]
        sar     ecx, 0x0c
        mov     dword ptr [g_walkCallback], ecx
        ret
    }
}

/* @addr 0x0041f230 (49b): same shape, no `sub`, esp adjust earlier */
__declspec(naked) void RandSarMod0xFFF_0041f230(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueWorkType]
        push    eax
        push    0x028be602
        call    Mul10Tail_00404af0
        sar     eax, 0x10
        and     eax, 0xfff
        add     esp, 8
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     ecx, dword ptr [eax*4 + g_sinTable]
        sar     ecx, 0x0c
        mov     dword ptr [g_walkCallback], ecx
        ret
    }
}

/* @addr 0x00421f00 (64b)
 *   mov     eax, [g_baseSel_00542060]
 *   shl     eax, 2
 *   mov     ecx, [eax + 0x84]
 *   mov     [eax + 0x84], 0
 *   test    ecx, ecx
 *   je      +5
 *   jmp     +0x1f
 *   mov     ecx, 1
 *   mov     [eax + 8], 0x00421f00
 *   mov     [eax + 0x84], ecx
 *   mov     [g_pendingNodeType], ecx
 *   mov     [g_framePauseFlag], ecx
 *   ret
 */
extern void InstallSelfStackReset_00421f40(void);
void ScaledInitOrSelfPtr_00421f00(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int ptr = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (ptr) {
        InstallSelfStackReset_00421f40();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_00421f00;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00428950 (64b): same shape, store=own, jmp=0x428850 */
extern void CallPauseDirty1JmpDirty4StackPush_00428850(void);
void ScaledInitOrSelfPtr_00428950(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int ptr = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (ptr) {
        CallPauseDirty1JmpDirty4StackPush_00428850();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_00428950;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00429680 (64b): same shape, store=own, jmp=0x41f780 */
extern void StackPopDispatchTagged_0041f780(void);
void ScaledInitOrSelfPtr_00429680(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int ptr = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (ptr) {
        StackPopDispatchTagged_0041f780();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_00429680;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00442d90 (64b): same shape, store=own, jmp=0x442dd0 */
extern void DualSeqLoopDispatch_00442dd0(void);
void ScaledInitOrSelfPtr_00442d90(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int ptr = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (ptr) {
        DualSeqLoopDispatch_00442dd0();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_00442d90;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x004250f0 (61b)
 *   3-component vector subtract: out[i] = a[i] - b[i] across i=0,1,2
 *   a = [g_xformEntityIdx*4], b = [g_pendingNodeType*4],
 *   out = [g_currentNodeIdx*4]
 */
__declspec(naked) void TripleSubVec3_004250f0(void) {
    __asm {
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_pendingNodeType]
        mov     eax, dword ptr [g_scaledInit_00542044]
        push    esi
        shl     ecx, 2
        shl     edx, 2
        mov     esi, dword ptr [ecx]
        push    edi
        mov     edi, dword ptr [edx]
        shl     eax, 2
        sub     esi, edi
        mov     dword ptr [eax], esi
        mov     esi, dword ptr [ecx + 4]
        mov     edi, dword ptr [edx + 4]
        sub     esi, edi
        pop     edi
        mov     dword ptr [eax + 4], esi
        mov     ecx, dword ptr [ecx + 8]
        mov     esi, dword ptr [edx + 8]
        sub     ecx, esi
        pop     esi
        mov     dword ptr [eax + 8], ecx
        ret
    }
}

/* @addr 0x00425130 (61b)
 *   3-component vector add: out[i] = a[i] + b[i] across i=0,1,2
 *   (variant of 0x004250f0 with `add` and slight reg reordering)
 */
__declspec(naked) void TripleAddVec3_00425130(void) {
    __asm {
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_pendingNodeType]
        mov     eax, dword ptr [g_scaledInit_00542044]
        push    esi
        shl     ecx, 2
        shl     edx, 2
        push    edi
        mov     edi, dword ptr [ecx]
        mov     esi, dword ptr [edx]
        shl     eax, 2
        add     esi, edi
        mov     dword ptr [eax], esi
        mov     esi, dword ptr [ecx + 4]
        mov     edi, dword ptr [edx + 4]
        add     esi, edi
        pop     edi
        mov     dword ptr [eax + 4], esi
        mov     edx, dword ptr [edx + 8]
        mov     esi, dword ptr [ecx + 8]
        add     edx, esi
        pop     esi
        mov     dword ptr [eax + 8], edx
        ret
    }
}

/* @addr 0x00439520 (64b)
 *   inc g_state_004d57ac, store callback to stack[idx*4],
 *   call IAT [g_iatPtr_00542058], pause-test, restore
 */
extern unsigned int g_state_004d57ac;
extern void (*g_iatPtr_00542058)(void);
__declspec(naked) void IncStoreCallIATDec_00439520(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_eventQueueChild]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    dword ptr [g_iatPtr_00542058]
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_eventQueueChild], edx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x00457ff0 (62b)
 *   call F1; pause-test +0x2f → ret
 *   call F2; pause-test +0x21 → ret
 *   call F3; pause-test +0x13 → ret
 *   call F4; pause-test +0x05 → ret
 *   jmp     T
 *   ret
 */
extern void DoublePackedPtrInstall_00458ba0(void);
extern void DualPathCallSetup_00458030(void);
extern void TriplePackedTagged_004580a0(void);
extern void CameraProjectionInitSweep_00458160(void);
extern void SpawnTrioInitCluster_00458440(void);
void QuadCallPauseJmp_00457ff0(void) {
    DoublePackedPtrInstall_00458ba0();
    if (g_framePauseFlag != 0) {
        return;
    }
    DualPathCallSetup_00458030();
    if (g_framePauseFlag != 0) {
        return;
    }
    TriplePackedTagged_004580a0();
    if (g_framePauseFlag != 0) {
        return;
    }
    CameraProjectionInitSweep_00458160();
    if (g_framePauseFlag != 0) {
        return;
    }
    SpawnTrioInitCluster_00458440();
}
