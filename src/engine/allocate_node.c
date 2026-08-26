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

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueChild (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_eventQueueEnd (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_eventQueueIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_nodeAllocCounter (*(unsigned int *)MK4_VA(unsigned int, 0x541e64u))
#define g_nodeListTail (*(unsigned int *)MK4_VA(unsigned int, 0x52ab3cu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformScratch2088 (*(unsigned int *)MK4_VA(unsigned int, 0x542088u))
#endif


/*
 * @addr 0x0041f290
 *

 * Naked + __asm: the long chain of `mov edx, [g_currentNodeIdx];
 * mov [edx*4+N], reg` repeats reload + indexed store ~30 times in a
 * row. MSVC SP3 will not produce that exact reload pattern from a
 * natural C body (it would CSE the load into a register).
 */

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin.
 *
 * Slot i lives at 0x0053e368 + i * 0xe8; its header is the last 0x14 bytes of
 * the slot, i.e. node + 0xd4:
 *
 *     +0xd4  magic       0x12345678
 *     +0xd8  ptr_field   the type; ZERO means the slot is free
 *     +0xdc  type_word   u16
 *     +0xe0  worktype
 *     +0xe4  next_link   forward link, and the field NodeUnlink unlinks
 *
 * The free scan and the list walk are both bounded by an ADDRESS compare
 * (0x541e40 = 0x53e440 + 64 * 0xe8), so they are fixed 64-slot loops - and
 * writing them as counts is what keeps the bound right once the table is
 * relocated into the arena.
 *
 * The original re-loads g_currentNodeIdx before each of the ~30 field stores.
 * Nothing it writes can alias that global (node fields top out at +0x84, well
 * below the 0x53e368 table), so the twin holds the index in a local.
 *
 * The `cmp esi, ecx` for the list-splice sits three stores ahead of its `je`
 * (MSVC scheduling flags across independent stores); order is immaterial here.
 *
 * Signature spelled in base C types, not u32: the co-exec harness compiles the
 * twin body with only ghidra_types.h in scope.
 */
void *AllocateNode(unsigned int type)
{
    unsigned char *slot0 = (unsigned char *)MK4_VA(unsigned char, 0x0053e368u);
    unsigned int   last  = g_nodeListTail;
    unsigned char *node, *hdr;
    unsigned int   idx, i, f;

    /* walk to the end of the list */
    if (last != 0) {
        unsigned int nxt = *(unsigned int *)MK4_PTR(last + 0xe4);

        while (nxt != 0) {
            last = nxt;
            nxt = *(unsigned int *)MK4_PTR(last + 0xe4);
        }
    }

    /* first slot whose ptr_field is zero */
    for (i = 0; i < 64; i++)
        if (*(unsigned int *)(slot0 + i * 0xe8 + 0xd8) == 0)
            break;
    if (i == 64) {
        g_currentNodeIdx = 0;
        g_xformDirtyFlags |= 5;
        return 0;
    }

    node = slot0 + i * 0xe8;
    hdr  = node + 0xd4;

    *(unsigned short *)(hdr + 0x08) = 0;                   /* type_word */
    *(unsigned int   *)(hdr + 0x04) = type;                /* ptr_field */
    *(unsigned int   *)(hdr + 0x0c) = g_eventQueueWorkType;
    *(unsigned int   *)(hdr + 0x10) = 0;                   /* next_link */
    if (last != 0)
        *(unsigned int *)MK4_PTR(last + 0xe4) = MK4_UNPTR(node);
    else
        g_nodeListTail = MK4_UNPTR(node);
    *(unsigned int *)(hdr + 0x00) = 0x12345678;

    idx = MK4_UNPTR(node) >> 2;
    g_currentNodeIdx = idx;

    MK4_NODE_AT(unsigned int, idx, 0x84) = 0;
    MK4_NODE_AT(unsigned int, idx, 0x10) = 0;
    MK4_NODE_AT(unsigned int, idx, 0x08) = g_pendingNodeType;
    MK4_NODE_AT(unsigned int, idx, 0x0c) = g_eventQueueWorkType;
    g_walkCallback = idx + 0x22;
    MK4_NODE_AT(unsigned int, idx, 0x04) = idx + 0x22;
    MK4_NODE_AT(unsigned int, idx, 0x24) = g_eventQueueEnd;
    MK4_NODE_AT(unsigned int, idx, 0x28) = g_eventQueueIdx;
    MK4_NODE_AT(unsigned int, idx, 0x2c) = g_fightGroupHead;
    MK4_NODE_AT(unsigned int, idx, 0x14) = g_eventQueueNotMask;
    MK4_NODE_AT(unsigned int, idx, 0x18) = g_eventQueueChild;
    MK4_NODE_AT(unsigned int, idx, 0x1c) = g_currentNodeFlags;
    MK4_NODE_AT(unsigned int, idx, 0x20) = g_xformScratch2088;
    for (f = 0x30; f <= 0x80; f += 4)
        MK4_NODE_AT(unsigned int, idx, f) = 0;

    g_nodeAllocCounter++;
    g_xformDirtyFlags &= ~5u;
    return node;
}
#else
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
#endif
