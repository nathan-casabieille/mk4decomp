/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_dispatchSave835_004f4b54;
extern unsigned int g_dispatchSave836_004f4b70;
extern unsigned int g_dispatchSave837_004f4b80;
extern unsigned int g_dispatchSave838_004f4b94;
extern unsigned int g_dispatchSave839_004f4ba8;
extern unsigned int g_dispatchSave840_004f4bbc;
extern unsigned int g_dispatchSave841_004f4bd0;
extern unsigned int g_dispatchSave842_004f4be8;
extern unsigned int g_dispatchSave843_004f4bfc;
extern unsigned int g_dispatchSave844_004f4c18;
extern unsigned int g_dispatchSave845_004f4c2c;
extern unsigned int g_dispatchSave846_004f4c40;
extern unsigned int g_dispatchSave847_004f4c50;
extern unsigned int g_dispatchSave848_004f4c68;
extern unsigned int g_dispatchSave849_004f4c7c;
extern unsigned int g_dispatchSave850_004f4c8c;
extern unsigned int g_dispatchSave851_004f4c9c;
extern unsigned int g_dispatchSave852_004f4cb0;
extern unsigned int g_dispatchSave853_004f4cc0;
extern unsigned int g_dispatchSave854_004f4cdc;
extern unsigned int g_dispatchSave855_004f4cec;
extern unsigned int g_dispatchSave856_004f4d04;
extern unsigned int g_dispatchSave857_004f4d14;
extern unsigned int g_dispatchSave858_004f4d28;
extern unsigned int g_dispatchSave859_004f4d3c;
extern unsigned int g_dispatchSave860_004f4d50;
extern unsigned int g_dispatchSave861_004f4d64;
extern unsigned int g_dispatchSave862_004f4d74;
extern unsigned int g_dispatchSave863_004f4d88;
extern unsigned int g_dispatchSave864_004f4d9c;
extern unsigned int g_dispatchSave865_004f4db8;
extern int g_renderer1_active;
extern unsigned int g_glideFnTable;
extern unsigned int g_data_007b0004;
extern unsigned int g_data_007b0008;
extern unsigned int g_iat_007b000c;
extern unsigned int g_iat_007b0010;
extern unsigned int g_data_007b0014;
extern unsigned int g_data_007b0018;
extern unsigned int g_data_007b001c;
extern unsigned int g_data_007b0020;
extern unsigned int g_data_007b0024;
extern unsigned int g_data_007b0028;
extern unsigned int g_data_007b002c;
extern unsigned int g_iat_007b0030;
extern unsigned int g_data_007b0034;
extern unsigned int g_data_007b0038;
extern unsigned int g_PeekMessageA_007b003c;
extern unsigned int g_iat_007b0040;
extern unsigned int g_data_007b0044;
extern unsigned int g_data_007b0048;
extern unsigned int g_data_007b004c;
extern unsigned int g_iat_indirect_007b0050;
extern unsigned int g_iat_indirect_007b0054;
extern unsigned int g_data_007b0058;
extern unsigned int g_data_007b005c;
extern unsigned int g_iat_indirect_007b0060;
extern unsigned int g_data_007b0064;
extern unsigned int g_data_007b0068;
extern unsigned int g_data_007b006c;
extern unsigned int g_data_007b0070;
extern unsigned int g_data_007b0074;
extern unsigned int g_data_007b0078;
extern unsigned int g_iat_004d2050;
extern unsigned int g_iat_004d2058;

__declspec(naked) void Helper_GlideOpen(void)
{
    __asm {
        mov      eax, dword ptr [g_renderer1_active]
        push     esi
        test     eax, eax
        jne      L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        test     eax, eax
        jne      L_4f52
        push     OFFSET g_dispatchSave865_004f4db8
        call     dword ptr [g_iat_004d2050]
        test     eax, eax
        mov      dword ptr [g_glideFnTable], eax
        je       L_4f52
        mov      esi, dword ptr [g_iat_004d2058]
        push     OFFSET g_dispatchSave864_004f4d9c
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0004], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave863_004f4d88
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0008], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave862_004f4d74
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_iat_007b000c], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave861_004f4d64
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_iat_007b0010], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave860_004f4d50
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0014], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave859_004f4d3c
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0018], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave858_004f4d28
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b001c], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave857_004f4d14
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0020], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave856_004f4d04
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0024], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave855_004f4cec
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0028], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave854_004f4cdc
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b002c], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave853_004f4cc0
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_iat_007b0030], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave852_004f4cb0
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0034], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave851_004f4c9c
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0038], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave850_004f4c8c
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_PeekMessageA_007b003c], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave849_004f4c7c
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_iat_007b0040], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave848_004f4c68
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0044], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave847_004f4c50
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0048], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave846_004f4c40
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b004c], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave845_004f4c2c
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_iat_indirect_007b0050], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave844_004f4c18
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_iat_indirect_007b0054], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave843_004f4bfc
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0058], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave842_004f4be8
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b005c], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave841_004f4bd0
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_iat_indirect_007b0060], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave840_004f4bbc
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0064], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave839_004f4ba8
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0068], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave838_004f4b94
        push     ecx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b006c], eax
        je       L_4f52
        mov      edx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave837_004f4b80
        push     edx
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0070], eax
        je       L_4f52
        mov      eax, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave836_004f4b70
        push     eax
        call     esi
        test     eax, eax
        mov      dword ptr [g_data_007b0074], eax
        je       L_4f52
        mov      ecx, dword ptr [g_glideFnTable]
        push     OFFSET g_dispatchSave835_004f4b54
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

