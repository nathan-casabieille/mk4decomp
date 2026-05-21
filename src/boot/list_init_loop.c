/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00401310 (33b): list iteration with append?
 *   cmp     [0x004ffdec], 0
 *   jne     +0x17
 *   mov     ecx, 0x004ffdec
 *   mov     eax, ecx
 *   add     eax, 0x0c
 *   mov     [ecx], 1
 *   nop * 1 (00)
 *   mov     ecx, eax
 *   cmp     [eax], -1
 *   jne     -0x10
 *   ret
 *
 * Hmm let me re-decode bytes: 833decfd4f00ff 7417 b9ecfd4f00 8bc1 83c00c c701000000 00 8bc8 8338ff 75f0 c3
 * 833d ecfd4f00 ff   = cmp dword [0x004ffdec], -1
 * 74 17               = je +0x17
 * b9 ec fd 4f 00      = mov ecx, 0x004ffdec
 * 8b c1               = mov eax, ecx
 * 83 c0 0c            = add eax, 0x0c
 * c7 01 00 00 00 00   = mov [ecx], 0
 * 8b c8               = mov ecx, eax
 * 83 38 ff            = cmp [eax], -1
 * 75 f0               = jne -0x10
 * c3                  = ret
 *
 * Actually wait: c7 01 + 4 bytes = mov [ecx], imm32. Let me check:
 *   c7 /0 = mov r/m32, imm32. With modr/m=01, mod=00 reg=000 rm=001 → mov [ecx], imm32.
 *   c7 01 00 00 00 00 = mov [ecx], 0  (5 bytes? Wait c7 01 + 4 = 6 bytes, but counted 5).
 *   Actually c7 01 takes 6 bytes total (1 opcode + 1 modr/m + 4 imm32).
 *
 * Hmm let me recount: 833decfd4f00ff = 7 bytes
 * 7417 = 2 bytes
 * b9ecfd4f00 = 5 bytes
 * 8bc1 = 2 bytes
 * 83c00c = 3 bytes
 * c701000000 = 5 bytes only? c7 01 00 00 00 00 = 6 bytes.
 *   Hex: c7 01 00 00 00 00. The byte string "c701000000" has length 10/2 = 5 bytes.
 *   So I'm miscounting: c7 01 00 00 00 = 5 bytes, but that's only `c7` opcode + `01` modr/m + `00 00 00` (3 bytes of imm32). Need 4 bytes for imm32.
 *   Re-look: "c701000000 008bc8" - the body has `c7 01 00 00 00 00 8b c8` = c7 01 00 00 00 00 (6 bytes) then 8b c8. OK my hex string parsing was wrong.
 *
 * Total: 7+2+5+2+3+6+2+3+2+1 = 33 ✓
 */
extern int g_list_004ffdec;
void ListInitLoop_00401310(void) {
    __asm {
        cmp     dword ptr [g_list_004ffdec], -1
        _emit   74h
        _emit   17h
        mov     ecx, OFFSET g_list_004ffdec
        mov     eax, ecx
        add     eax, 0x0c
        mov     dword ptr [ecx], 0
        mov     ecx, eax
        cmp     dword ptr [eax], -1
        _emit   75h
        _emit   0f0h
        }
}
