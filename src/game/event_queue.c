/**
 * Game event queue.
 */
#include "game/tick.h"
#include "engine/scenegraph.h"

/*
 * Walk the event queue from the cached head, processing each event:
 * allocate a node (via AllocNode using the cached pending type),
 * update the entity-chain chain head, advance to the next slot.
 * On reaching the end of the queue, tail-call DispatchEventQueue_Commit.
 *
 * If g_framePauseFlag flips during the walk the inner update is
 * skipped (the dispatcher unwinds gracefully on the next pass).
 *
 * @addr 0x0045c820
 */
__declspec(naked) void DispatchEventQueue(void)
{
    __asm {
        mov     eax, [g_eventQueueActive]
        mov     ecx, 0053A508h                    ; raw end-of-queue addr
        shr     ecx, 2                             ; pack ptr -> idx
        mov     [g_xformEntityIdx], eax
        mov     [g_eventQueueTotal], ecx
        ; Long jmp + 3-nop padding to align inner_loop on a 16-byte boundary
        _emit   0E9h
        _emit   03h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     ecx, [g_eventQueueHead]
        mov     eax, [g_xformEntityIdx]
        push    esi
        cmp     ecx, eax
        push    edi
        mov     [g_eventQueueEnd], ecx
        je      tail_commit
        mov     edi, 11h
        xor     esi, esi
inner_loop:
        mov     eax, dword ptr [eax*4 + g_xformChainTable]
        mov     [g_eventQueueWorkType], edi
        mov     [g_pendingNodeType], eax
        call    AllocNode
        cmp     [g_framePauseFlag], esi
        jne     pop_and_ret
        mov     ecx, [g_xformEntityIdx]
        mov     [g_walkCallback], esi
        mov     dword ptr [ecx*4 + g_xformChainTable], esi
        mov     eax, [g_xformEntityIdx]
        mov     ecx, [g_eventQueueTotal]
        inc     eax
        cmp     eax, ecx
        mov     [g_xformEntityIdx], eax
        jne     skip_wrap
        mov     eax, 0053A4B8h
        shr     eax, 2
        mov     [g_xformEntityIdx], eax
skip_wrap:
        mov     ecx, [g_eventQueueHead]
        cmp     ecx, eax
        mov     [g_eventQueueEnd], ecx
        jne     inner_loop
tail_commit:
        call    DispatchEventQueue_Commit
pop_and_ret:
        pop     edi
        pop     esi
        ret
    }
}

/*
 * Promote the pending event-queue snapshot into the active slot.
 * Called at the end of each fight frame after DispatchEventQueue
 * has finished filling Pending.
 *
 * @addr 0x0045c8d0
 */
void DispatchEventQueue_Commit(void)
{
    g_eventQueueActive = g_eventQueuePending;
}
