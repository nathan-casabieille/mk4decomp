/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

__declspec(naked) void Helper_GlideOpen(void)
{
    __asm {
        mov      eax, dword ptr [g_data_007affe4]
        push     esi
        test     eax, eax
        jne      L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        test     eax, eax
        jne      L_4f52
        push     OFFSET g_data_004f4db8
        call     dword ptr [g_iat_004d2050]
        test     eax, eax
        mov      dword ptr [g_data_007b0000], eax
        je       L_4f52
        mov      esi, dword ptr [g_iat_004d2058]
        push     OFFSET g_data_004f4d9c
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0004], eax
        je       L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4d88
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0008], eax
        je       L_4f52
        mov      ecx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4d74
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b000c], eax
        je       L_4f52
        mov      edx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4d64
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0010], eax
        je       L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4d50
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0014], eax
        je       L_4f52
        mov      ecx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4d3c
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0018], eax
        je       L_4f52
        mov      edx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4d28
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b001c], eax
        je       L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4d14
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0020], eax
        je       L_4f52
        mov      ecx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4d04
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0024], eax
        je       L_4f52
        mov      edx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4cec
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0028], eax
        je       L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4cdc
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b002c], eax
        je       L_4f52
        mov      ecx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4cc0
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0030], eax
        je       L_4f52
        mov      edx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4cb0
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0034], eax
        je       L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4c9c
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0038], eax
        je       L_4f52
        mov      ecx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4c8c
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b003c], eax
        je       L_4f52
        mov      edx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4c7c
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0040], eax
        je       L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4c68
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0044], eax
        je       L_4f52
        mov      ecx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4c50
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0048], eax
        je       L_4f52
        mov      edx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4c40
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b004c], eax
        je       L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4c2c
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0050], eax
        je       L_4f52
        mov      ecx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4c18
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0054], eax
        je       L_4f52
        mov      edx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4bfc
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0058], eax
        je       L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4be8
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b005c], eax
        je       L_4f52
        mov      ecx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4bd0
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0060], eax
        je       L_4f52
        mov      edx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4bbc
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0064], eax
        je       L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4ba8
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0068], eax
        je       L_4f52
        mov      ecx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4b94
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b006c], eax
        je       L_4f52
        mov      edx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4b80
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0070], eax
        je       L_4f52
        mov      eax, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4b70
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0074], eax
        je       L_4f52
        mov      ecx, dword ptr [g_data_007b0000]
        push     OFFSET g_data_004f4b54
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0078], eax
        je       L_4f52
        mov      eax, 1
        pop      esi
        ret
    L_4f52:
        xor      eax, eax
        pop      esi
        ret
    }
}

