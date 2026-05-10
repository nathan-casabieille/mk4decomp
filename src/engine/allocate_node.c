/**
 * Scene-graph node slot allocator.
 *
 * Walks the linked list off g_nodeListTail to its current end, then
 * scans g_nodeSlotsArea[] (64 × 0xe8-byte slots) looking for a slot
 * whose header.ptr_field is zero. On miss, ORs 5 into
 * g_xformDirtyFlags and returns 0. On hit, fills the slot's header
 * (ptr_field <- type, type_word <- 0, worktype <- g_eventQueueWorkType,
 * next_link <- 0), splices the new slot into the linked list, stamps
 * 0x12345678 into +0xd4 of the data area, primes the new node's per-
 * field state from a dozen working-state globals, and zero-clears
 * the rest of the node's u32 fields up to +0x80.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x0041f290
 *
 * Naked + __asm: the long chain of `mov edx, [g_currentNodeIdx];
 * mov [edx*4+N], reg` repeats reload + indexed store ~30 times in a
 * row. MSVC SP3 will not produce that exact reload pattern from a
 * natural C body (it would CSE the load into a register).
 */
__declspec(naked) void *AllocateNode(u32 type)
{
    __asm {
        push    esi
        mov     esi, dword ptr [g_nodeListTail]
        xor     ecx, ecx
        cmp     esi, ecx
        je      SHORT scan_slots
        mov     eax, dword ptr [esi + 0xe4]
        cmp     eax, ecx
        je      SHORT scan_slots
walk_tail:
        mov     esi, eax
        mov     eax, dword ptr [esi + 0xe4]
        cmp     eax, ecx
        jne     SHORT walk_tail
scan_slots:
        xor     edx, edx
        mov     eax, offset g_nodeSlotsHdr_ptrField
slot_loop:
        cmp     dword ptr [eax], ecx
        je      SHORT found
        add     eax, 0xe8
        inc     edx
        cmp     eax, offset g_nodeSlotsHdr_end
        jb      SHORT slot_loop
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_currentNodeIdx], ecx
        or      al, 5
        mov     dword ptr [g_xformDirtyFlags], eax
        xor     eax, eax
        pop     esi
        ret
found:
        mov     eax, edx
        shl     eax, 3
        sub     eax, edx
        lea     edx, [edx + eax*4]
        mov     eax, dword ptr [esp + 8]
        shl     edx, 3
        cmp     esi, ecx
        mov     word ptr [edx + g_nodeSlotsHdr_typeWord], cx
        mov     dword ptr [edx + g_nodeSlotsHdr_ptrField], eax
        mov     eax, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [edx + g_nodeSlotsHdr_workType], eax
        je      SHORT use_head
        lea     eax, [edx + g_nodeSlotsArea]
        mov     dword ptr [esi + 0xe4], eax
        mov     dword ptr [edx + g_nodeSlotsHdr_nextLink], ecx
        jmp     SHORT post_link
use_head:
        lea     eax, [edx + g_nodeSlotsArea]
        mov     dword ptr [edx + g_nodeSlotsHdr_nextLink], ecx
        mov     dword ptr [g_nodeListTail], eax
post_link:
        mov     dword ptr [edx + g_nodeSlotsHdr_magic], 0x12345678
        mov     edx, eax
        sar     edx, 2
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [edx*4 + 0x84], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x10], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_pendingNodeType]
        mov     dword ptr [edx*4 + 8], esi
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [edx*4 + 0xc], esi
        mov     edx, dword ptr [g_currentNodeIdx]
        lea     esi, [edx + 0x22]
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [edx*4 + 4], esi
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_eventQueueEnd]
        mov     dword ptr [edx*4 + 0x24], esi
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_eventQueueIdx]
        mov     dword ptr [edx*4 + 0x28], esi
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_fightGroupHead]
        mov     dword ptr [edx*4 + 0x2c], esi
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_eventQueueNotMask]
        mov     dword ptr [edx*4 + 0x14], esi
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_eventQueueChild]
        mov     dword ptr [edx*4 + 0x18], esi
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_currentNodeFlags]
        mov     dword ptr [edx*4 + 0x1c], esi
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_xformScratch2088]
        mov     dword ptr [edx*4 + 0x20], esi
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x30], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x34], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x38], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x3c], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x40], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x44], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x48], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x4c], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x50], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x54], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x58], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x5c], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x60], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x64], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x68], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x6c], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x70], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x74], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x78], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x7c], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x80], ecx
        mov     edx, dword ptr [g_nodeAllocCounter]
        mov     ecx, dword ptr [g_xformDirtyFlags]
        inc     edx
        and     ecx, 0xfffffffa
        mov     dword ptr [g_nodeAllocCounter], edx
        mov     dword ptr [g_xformDirtyFlags], ecx
        pop     esi
        ret
    }
}
