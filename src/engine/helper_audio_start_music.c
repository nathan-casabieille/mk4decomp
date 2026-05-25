/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004c3960 (362b engine.render) - texture-slot allocator + dispatch.
 *   Reads short slot-id at [esp+0x10]; if >= 0x898 returns -1. Indexes
 *   the per-slot 0x1c-byte record at g_audioChannelTable (idx * 0x1c via
 *   lea/sub/shl ladder). Falls through if the slot table pointer is
 *   NULL or, when g_audioMute is non-zero, the +0x16 flag bit 0 is
 *   clear. Reads the cursor word at [+0x14] and the per-cursor byte at
 *   [cursor + +0x17] - if non-zero a slot is busy, return -1. Allocates
 *   a new free slot via FreeSlotFinder_004c3900 → byte index; on found
 *   writes (slot-id, cursor) into the 4-byte entries at g_audioChannelQueue
 *   indexed by free-slot. If two byte args [esp+0x18] and [esp+0x1c]
 *   are both <= 0x64, looks up a (arg1*25 + arg2 - based) offset in the
 *   table at g_table_00f85b60 and indirect-calls the vtables at +0x3c
 *   and +0x40 of two different slot pointers. Then on no-render mode
 *   ([g_f9efd4] == 0), calls vtable +0x30 with (slot, 0, 0, flag). Marks
 *   the cursor byte at [cursor + +0x17] = 1, advances cursor (mod 4).
 */
extern unsigned int g_table_00f85b60;
extern unsigned int g_data_00f85b62;
extern u8 g_audioChannelTable[];
extern unsigned int g_data_00f8fadc;
extern unsigned int g_flags_00f8fade;
extern unsigned int g_flags_00f8fadf;
extern u16 g_audioChannelQueue[];
extern unsigned int g_data_00f9eb82;
extern u8 g_audioMute;
extern void FreeSlotFinder_004c3900(void);

__declspec(naked) void Helper_AudioStartMusic(void) {
    __asm {
        push    ebx
        push    ebp
        push    esi
        mov     si, word ptr [esp + 0x10]
        cmp     si, 0x898
        push    edi
        jae     L_tsa_failNeg
        movsx   ebx, si
        lea     ebp, [ebx*8]
        sub     ebp, ebx
        shl     ebp, 2
        mov     eax, dword ptr [ebp + g_audioChannelTable]
        test    eax, eax
        je      L_tsa_failNeg
        mov     al, byte ptr [g_audioMute]
        test    al, al
        je      short L_tsa_skipFlag
        test    byte ptr [ebp + g_flags_00f8fade], 1
        je      L_tsa_failNeg
    L_tsa_skipFlag:
        movsx   eax, word ptr [ebp + g_data_00f8fadc]
        mov     cl, byte ptr [eax + ebp + g_flags_00f8fadf]
        test    cl, cl
        jne     L_tsa_failNeg
        call    FreeSlotFinder_004c3900
        mov     cl, al
        cmp     cl, 0xff
        mov     byte ptr [esp + 0x14], cl
        je      L_tsa_failNeg
        mov     di, word ptr [ebp + g_data_00f8fadc]
        movsx   eax, cl
        shl     eax, 2
        mov     word ptr [eax + g_audioChannelQueue], si
        mov     word ptr [eax + g_data_00f9eb82], di
        mov     al, byte ptr [esp + 0x18]
        cmp     al, 0x64
        ja      short L_tsa_skipPairCalls
        mov     dl, byte ptr [esp + 0x1c]
        cmp     dl, 0x64
        ja      short L_tsa_skipPairCalls
        lea     esi, [ebx*8]
        sub     esi, ebx
        movsx   ecx, di
        mov     edi, esi
        movsx   eax, al
        add     edi, ecx
        movsx   edx, dl
        mov     ecx, dword ptr [edi*4 + g_audioChannelTable]
        lea     edi, [eax + eax*4]
        lea     edi, [edi + edi*4]
        lea     edi, [eax + edi*4]
        mov     eax, dword ptr [ecx]
        add     edi, edx
        shl     edi, 2
        movsx   edx, word ptr [edi + g_table_00f85b60]
        push    edx
        push    ecx
        call    dword ptr [eax + 0x3c]
        movsx   eax, word ptr [ebp + g_data_00f8fadc]
        movsx   edx, word ptr [edi + g_data_00f85b62]
        add     esi, eax
        push    edx
        mov     esi, dword ptr [esi*4 + g_audioChannelTable]
        push    esi
        mov     ecx, dword ptr [esi]
        call    dword ptr [ecx + 0x40]
        mov     cl, byte ptr [esp + 0x14]
    L_tsa_skipPairCalls:
        mov     al, byte ptr [g_audioMute]
        test    al, al
        jne     short L_tsa_markCursor
        movsx   ecx, word ptr [ebp + g_data_00f8fadc]
        lea     eax, [ebx*8]
        sub     eax, ebx
        add     eax, ecx
        mov     cl, byte ptr [ebp + g_flags_00f8fade]
        and     ecx, 1
        mov     eax, dword ptr [eax*4 + g_audioChannelTable]
        push    ecx
        push    0
        push    0
        mov     edx, dword ptr [eax]
        push    eax
        call    dword ptr [edx + 0x30]
        mov     cl, byte ptr [esp + 0x14]
    L_tsa_markCursor:
        movsx   edx, word ptr [ebp + g_data_00f8fadc]
        mov     byte ptr [edx + ebp + g_flags_00f8fadf], 1
        movsx   eax, word ptr [ebp + g_data_00f8fadc]
        inc     eax
        cdq
        xor     eax, edx
        sub     eax, edx
        and     eax, 3
        xor     eax, edx
        sub     eax, edx
        mov     word ptr [ebp + g_data_00f8fadc], ax
        mov     al, cl
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_tsa_failNeg:
        pop     edi
        pop     esi
        pop     ebp
        or      al, 0xff
        pop     ebx
        ret
    }
}

