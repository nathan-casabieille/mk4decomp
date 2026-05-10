/**
 * Thirty-third batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
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
extern void func_00421f40(void);
__declspec(naked) void ScaledInitOrSelfPtr_00421f00(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   05h
        jmp     func_00421f40
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00421f00
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x00428950 (64b): same shape, store=own, jmp=0x428850 */
extern void func_00428850(void);
__declspec(naked) void ScaledInitOrSelfPtr_00428950(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   05h
        jmp     func_00428850
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00428950
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x00429680 (64b): same shape, store=own, jmp=0x41f780 */
extern void func_0041f780(void);
__declspec(naked) void ScaledInitOrSelfPtr_00429680(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   05h
        jmp     func_0041f780
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00429680
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x00442d90 (64b): same shape, store=own, jmp=0x442dd0 */
extern void func_00442dd0(void);
__declspec(naked) void ScaledInitOrSelfPtr_00442d90(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   05h
        jmp     func_00442dd0
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x00442d90
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
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
extern void func_00458ba0(void);
extern void func_00458030(void);
extern void func_004580a0(void);
extern void func_00458160(void);
extern void func_00458440(void);
__declspec(naked) void QuadCallPauseJmp_00457ff0(void) {
    __asm {
        call    func_00458ba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2fh
        call    func_00458030
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   21h
        call    func_004580a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    func_00458160
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_00458440
        ret
    }
}
