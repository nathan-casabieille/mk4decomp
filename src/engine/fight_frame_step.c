/**
 * Inner per-frame entity step.
 *
 * Walks the fight-scene sibling list off the current head pointer,
 * AND-merging child masks into the working state. Exits early via
 * the bare `ret` path if the head equals the previous one (XOR=0);
 * otherwise pushes esi/edi, walks the linked list of siblings (via
 * the [base*4 + 0] / [base*4 + 4] indirection), updating the queue
 * cursor and clamping it to the secondary range when it reaches the
 * primary end.
 */
#include "engine/scenegraph.h"

/*
 * @addr 0x0045c6c0
 *
 * Naked + __asm: scaled-base addressing pattern (`[reg*4 + disp]`
 * with the table address kept as `addr >> 2` in the register) makes
 * the natural C form unrepresentable; the asymmetric epilogue
 * (early-out as bare `ret` versus `pop esi; mov; pop edi; ret`)
 * also requires a hand-rolled tail.
 */
__declspec(naked) void FightFrameStep_Inner(void)
{
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [eax*4]
        and     eax, 0xffff
        mov     dword ptr [g_walkCallback], eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [edx*4]
        mov     dword ptr [g_eventQueueWorkType], edx
        mov     dword ptr [ecx*4], eax
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [ecx*4], eax
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, eax
        xor     eax, ecx
        mov     dword ptr [g_currentNodeFlags], edx
        mov     dword ptr [g_eventQueueCurrent], eax
        je      end
        not     ecx
        mov     dword ptr [g_eventQueueNotMask], ecx
        push    edi
        and     ecx, eax
        push    esi
        mov     esi, ecx
        jne     branch_a
        mov     edx, dword ptr [g_eventQueueTotal]
        mov     esi, eax
        mov     dword ptr [g_pendingNodeType], edx
        jmp     next
branch_a:
        and     edx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [g_currentNodeFlags], edx
        and     esi, edx
next:
        mov     ecx, dword ptr [g_eventQueueHead]
        mov     eax, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_eventQueueChild], esi
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [eax*4]
        test    edx, edx
        mov     dword ptr [g_walkCallback], edx
        je      bail
loop_top:
        mov     edi, esi
        and     edi, edx
        mov     dword ptr [g_eventQueueCurrent], edi
        je      skip_inner
        mov     eax, dword ptr [eax*4 + 4]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [ecx*4], eax
        mov     ecx, dword ptr [g_eventQueueIdx]
        mov     eax, 0x53a508
        inc     ecx
        shr     eax, 2
        cmp     ecx, eax
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     dword ptr [g_eventQueueEnd], eax
        jne     skip_clamp
        mov     ecx, 0x53a4b8
        shr     ecx, 2
        mov     dword ptr [g_eventQueueIdx], ecx
skip_clamp:
        mov     esi, dword ptr [g_eventQueueChild]
        mov     eax, dword ptr [g_walkCallback]
        cmp     esi, eax
        je      bail
        mov     eax, dword ptr [g_xformEntityIdx]
skip_inner:
        add     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [eax*4]
        test    edx, edx
        mov     dword ptr [g_walkCallback], edx
        jne     loop_top
bail:
        pop     esi
        mov     dword ptr [g_eventQueueHead], ecx
        pop     edi
end:
        ret
    }
}
