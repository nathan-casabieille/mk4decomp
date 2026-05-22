/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_data_0052ab04;
extern unsigned int g_data_0052ab08;
extern unsigned int g_data_0052ab10;
extern unsigned int g_data_0052ab50;
extern unsigned int g_data_0052d720;
extern unsigned int g_data_0052d738;
extern unsigned int g_data_0052d74c;
extern unsigned int g_data_00535d60;
extern unsigned int g_data_00535d68;
extern unsigned int g_data_00535ddc;
extern unsigned int g_data_00535de8;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;
extern unsigned int g_data_00537e94;
extern unsigned int g_data_00537ef4;
extern unsigned int g_data_00538068;
extern unsigned int g_data_00538158;
extern unsigned int g_data_0053815c;
extern unsigned int g_data_0053a42c;
extern unsigned int g_data_0053a730;
extern unsigned int g_data_0053a7b4;
extern unsigned int g_data_00541d68;
extern unsigned int g_data_00541dc4;
extern unsigned int g_data_00541e6c;
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542048;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_00542070;
extern unsigned int g_data_00542074;
extern unsigned int g_data_00542078;
extern unsigned int g_data_0054207c;
extern unsigned int g_data_00542080;
extern unsigned int g_data_00542084;
extern unsigned int g_data_00542094;
extern void DualInstallCallSwap_00489cd0(void);
extern void DualInstallCallSwap_00490c80(void);
extern void FpuSqrtMul_004ab350(void);
extern void GeoTransformDispatchAndApply_00489840(void);
extern void Mul10Tail_00404af0(void);
extern void RangeMulMod_004ab2a0(void);
extern void ScaledStateNegCallPauseLoad_00489e90(void);

__declspec(naked) void Helper_PerPlayerTick(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00538158]
        mov      ecx, dword ptr [g_data_0053815c]
        push     esi
        push     edi
        test     eax, eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [g_data_00542048], ecx
        je       L_983c
        test     ecx, ecx
        je       L_983c
        mov      edx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_data_0054206c], edx
        mov      esi, dword ptr [eax*4 + 0x5c]
        mov      dword ptr [g_data_00542070], esi
        mov      eax, dword ptr [ecx*4 + 0x54]
        mov      dword ptr [g_data_00542074], eax
        mov      ecx, dword ptr [ecx*4 + 0x5c]
        lea      edi, [eax + edx]
        sub      eax, edx
        sar      edi, 1
        mov      dword ptr [g_data_0052ab04], edi
        lea      edi, [ecx + esi]
        sar      edi, 1
        sub      ecx, esi
        push     eax
        push     eax
        mov      dword ptr [g_data_0052ab08], edi
        mov      dword ptr [g_data_00542074], eax
        mov      dword ptr [g_data_00542078], ecx
        mov      dword ptr [g_data_0054207c], eax
        mov      dword ptr [g_data_00542080], ecx
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_data_00542074], eax
        mov      eax, dword ptr [g_data_00542078]
        push     eax
        push     eax
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_00542074]
        add      esp, 8
        add      ecx, eax
        mov      dword ptr [g_data_00542078], eax
        mov      dword ptr [g_data_00542074], ecx
        call     FpuSqrtMul_004ab350
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_983c
        mov      edx, dword ptr [g_data_0054206c]
        test     edx, edx
        mov      dword ptr [g_data_00535ddc], edx
        je       L_9569
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [eax*4 + 0x40]
        mov      eax, dword ptr [g_data_00542048]
        mov      dword ptr [g_data_00542070], ecx
        mov      eax, dword ptr [eax*4 + 0x40]
        or       eax, ecx
        mov      dword ptr [g_data_00542074], eax
        and      eax, 0x80
        mov      dword ptr [g_data_00542094], eax
        jne      L_9569
        mov      ecx, dword ptr [g_data_0054207c]
        mov      dword ptr [g_data_00542084], edx
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_00542070], edx
        call     RangeMulMod_004ab2a0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_983c
        mov      eax, dword ptr [g_data_0054206c]
        mov      edx, dword ptr [g_data_00542080]
        mov      dword ptr [g_data_00535e78], eax
        mov      dword ptr [g_data_0054206c], edx
        neg      eax
        mov      dword ptr [g_data_00535e70], eax
        mov      eax, dword ptr [g_data_00542084]
        mov      dword ptr [g_data_00542070], eax
        call     RangeMulMod_004ab2a0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_983c
        mov      ecx, dword ptr [g_data_0054206c]
        mov      edx, dword ptr [g_data_00542044]
        mov      esi, ecx
        neg      ecx
        mov      eax, ecx
        mov      dword ptr [g_data_00535e7c], esi
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_00535e74], eax
        mov      edx, dword ptr [edx*4 + 0x40]
        mov      eax, dword ptr [g_data_00542048]
        mov      dword ptr [g_data_0054206c], edx
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_data_00542070], eax
        or       eax, edx
        and      eax, 0x80
        mov      dword ptr [g_data_00542094], eax
        jne      L_9569
        mov      edx, dword ptr [g_data_0053a42c]
        lea      eax, [edx - 1]
        test     eax, eax
        jge      L_9415
        xor      eax, eax
    L_9415:
        test     eax, eax
        mov      dword ptr [g_data_0053a42c], eax
        jne      L_9569
        mov      edx, dword ptr [g_data_0052ab04]
        mov      edi, dword ptr [g_data_00535e78]
        lea      eax, [esi + edx]
        mov      esi, dword ptr [g_data_0052ab08]
        add      edx, ecx
        mov      ecx, esi
        mov      dword ptr [g_data_0054207c], edx
        add      esi, edi
        mov      dword ptr [g_data_0052d738], edx
        mov      edx, dword ptr [g_data_00535d68]
        sub      ecx, edi
        mov      dword ptr [g_data_00542080], esi
        mov      dword ptr [g_data_00535de8], eax
        mov      dword ptr [g_data_0052ab50], esi
        mov      esi, dword ptr [g_data_00535d60]
        sub      eax, edx
        mov      dword ptr [g_data_0052d720], ecx
        sub      ecx, esi
        push     eax
        push     eax
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [g_data_00542070], esi
        mov      dword ptr [g_data_00542074], eax
        mov      dword ptr [g_data_00542078], ecx
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_data_00542074], eax
        mov      eax, dword ptr [g_data_00542078]
        push     eax
        push     eax
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_00542074]
        mov      edi, dword ptr [g_data_0054206c]
        mov      esi, dword ptr [g_data_00542080]
        mov      dword ptr [g_data_00542078], eax
        add      ecx, eax
        mov      eax, dword ptr [g_data_0054207c]
        add      esp, 8
        mov      dword ptr [g_data_00542074], ecx
        mov      ecx, dword ptr [g_data_00542070]
        sub      eax, edi
        sub      esi, ecx
        push     eax
        push     eax
        mov      dword ptr [g_data_0054207c], eax
        mov      dword ptr [g_data_00542080], esi
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_data_0054207c], eax
        mov      eax, dword ptr [g_data_00542080]
        push     eax
        push     eax
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_data_0054207c]
        mov      esi, dword ptr [g_data_00542074]
        mov      ecx, dword ptr [g_data_0052d720]
        add      edx, eax
        add      esp, 8
        mov      dword ptr [g_data_00542080], eax
        mov      eax, dword ptr [g_data_00535de8]
        cmp      esi, edx
        mov      dword ptr [g_data_0054207c], edx
        jle      L_9531
        mov      eax, dword ptr [g_data_0052d738]
        mov      ecx, dword ptr [g_data_0052ab50]
    L_9531:
        mov      esi, dword ptr [g_data_0052ab08]
        mov      edx, dword ptr [g_data_0052ab04]
        mov      dword ptr [g_data_00535d60], ecx
        mov      dword ptr [g_data_00535d68], eax
        sub      ecx, esi
        sub      eax, edx
        mov      dword ptr [g_data_00542074], edx
        mov      dword ptr [g_data_00542078], esi
        mov      dword ptr [g_data_00542070], ecx
        mov      dword ptr [g_data_0053a7b4], eax
        mov      dword ptr [g_data_00541d68], ecx
    L_9569:
        mov      ecx, dword ptr [g_data_00535e7c]
        mov      eax, dword ptr [g_data_0052ab10]
        test     ecx, ecx
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_data_0054206c], ecx
        jne      L_959e
        mov      edx, dword ptr [eax*4 + 0x5c]
        mov      eax, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_00542080], edx
        mov      eax, dword ptr [eax*4 + 0x5c]
        jmp      L_9613
    L_959e:
        mov      ecx, dword ptr [g_data_00535e78]
        mov      dword ptr [g_data_00542070], ecx
        call     RangeMulMod_004ab2a0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_983c
        mov      eax, dword ptr [g_data_00542044]
        mov      esi, dword ptr [g_data_0054204c]
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_data_00542074], ecx
        mov      edx, dword ptr [eax*4 + 0x5c]
        mov      dword ptr [g_data_00542078], edx
        mov      eax, dword ptr [esi*4 + 0x54]
        mov      dword ptr [g_data_0054207c], eax
        mov      esi, dword ptr [esi*4 + 0x5c]
        sub      eax, ecx
        sub      esi, edx
        mov      edx, dword ptr [g_data_0054206c]
        push     eax
        push     edx
        mov      dword ptr [g_data_0054207c], eax
        mov      dword ptr [g_data_00542080], esi
        call     Mul10Tail_00404af0
        add      esp, 8
    L_9613:
        mov      edx, dword ptr [g_data_00542080]
        xor      ecx, ecx
        cmp      edx, eax
        jle      L_9624
        mov      ecx, 1
    L_9624:
        mov      edx, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_0053a730], ecx
        mov      ecx, dword ptr [g_data_00535e78]
        xor      edi, edi
        mov      dword ptr [g_data_0054207c], edi
        mov      dword ptr [g_data_0054206c], ecx
        mov      eax, dword ptr [edx*4 + 0x6c]
        test     eax, eax
        mov      dword ptr [g_data_00542070], eax
        jne      L_9670
        mov      ecx, dword ptr [g_data_00535e7c]
        mov      dword ptr [g_data_0054206c], ecx
        mov      eax, dword ptr [edx*4 + 0x74]
        test     eax, eax
        mov      dword ptr [g_data_00542070], eax
        je       L_96b8
    L_9670:
        mov      esi, ecx
        mov      edx, eax
        test     ecx, ecx
        mov      dword ptr [g_data_00542074], esi
        jge      L_9686
        neg      esi
        mov      dword ptr [g_data_00542074], esi
    L_9686:
        test     eax, eax
        jge      L_968e
        mov      edx, eax
        neg      edx
    L_968e:
        add      edx, esi
        add      eax, ecx
        mov      dword ptr [g_data_00542078], edx
        mov      dword ptr [g_data_00542070], eax
        jns      L_96a6
        neg      eax
        mov      dword ptr [g_data_00542070], eax
    L_96a6:
        cmp      eax, edx
        jne      L_96b1
        mov      edi, 0x10000
        cmp      eax, edx
    L_96b1:
        jge      L_96b8
        mov      edi, 0xffff0000
    L_96b8:
        mov      ecx, dword ptr [g_data_00535e70]
        mov      edx, dword ptr [g_data_00542048]
        mov      dword ptr [g_data_0052d74c], edi
        xor      edi, edi
        mov      dword ptr [g_data_0054207c], edi
        mov      dword ptr [g_data_0054206c], ecx
        mov      eax, dword ptr [edx*4 + 0x6c]
        test     eax, eax
        mov      dword ptr [g_data_00542070], eax
        jne      L_9704
        mov      ecx, dword ptr [g_data_00535e74]
        mov      dword ptr [g_data_0054206c], ecx
        mov      eax, dword ptr [edx*4 + 0x74]
        test     eax, eax
        mov      dword ptr [g_data_00542070], eax
        je       L_9758
    L_9704:
        mov      esi, ecx
        mov      edx, eax
        test     ecx, ecx
        mov      dword ptr [g_data_00542074], esi
        jge      L_971a
        neg      esi
        mov      dword ptr [g_data_00542074], esi
    L_971a:
        test     eax, eax
        jge      L_9722
        mov      edx, eax
        neg      edx
    L_9722:
        add      edx, esi
        add      eax, ecx
        mov      dword ptr [g_data_00542078], edx
        mov      dword ptr [g_data_00542070], eax
        jns      L_973a
        neg      eax
        mov      dword ptr [g_data_00542070], eax
    L_973a:
        cmp      eax, edx
        jne      L_974b
        mov      edi, 0x10000
        cmp      eax, edx
        mov      dword ptr [g_data_0054207c], edi
    L_974b:
        jge      L_9758
        mov      edi, 0xffff0000
        mov      dword ptr [g_data_0054207c], edi
    L_9758:
        mov      eax, dword ptr [g_data_00537ef4]
        mov      dword ptr [g_data_00538068], edi
        dec      eax
        mov      ecx, eax
        mov      dword ptr [g_data_0054206c], eax
        test     eax, eax
        mov      dword ptr [g_data_00541dc4], ecx
        jge      L_977c
        xor      eax, eax
        mov      dword ptr [g_data_0054206c], eax
    L_977c:
        test     ecx, ecx
        mov      dword ptr [g_data_00537ef4], eax
        jge      L_97ba
        call     DualInstallCallSwap_00489cd0
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_983c
        mov      eax, dword ptr [g_data_00535ddc]
        cmp      eax, 0x60000
        mov      dword ptr [g_data_0054206c], eax
        jle      L_97ba
        call     ScaledStateNegCallPauseLoad_00489e90
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_983c
    L_97ba:
        mov      ecx, dword ptr [g_data_00542044]
        mov      edx, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [ecx*4 + 0x58]
        mov      dword ptr [g_data_00542070], ecx
        mov      eax, dword ptr [edx*4 + 0x58]
        sub      eax, ecx
        mov      dword ptr [g_data_00542074], eax
        jns      L_97ea
        neg      eax
        mov      dword ptr [g_data_00542074], eax
    L_97ea:
        cmp      eax, 0xb333
        jg       L_9837
        mov      eax, dword ptr [g_data_00537e94]
        dec      eax
        mov      ecx, eax
        mov      dword ptr [g_data_00542074], eax
        test     eax, eax
        mov      dword ptr [g_data_00541dc4], ecx
        jge      L_980f
        xor      eax, eax
        mov      dword ptr [g_data_00542074], eax
    L_980f:
        test     ecx, ecx
        mov      dword ptr [g_data_00537e94], eax
        jge      L_9837
        mov      eax, dword ptr [g_data_00535ddc]
        cmp      eax, 0x8000
        mov      dword ptr [g_data_0054206c], eax
        jge      L_9837
        call     GeoTransformDispatchAndApply_00489840
        mov      eax, dword ptr [g_data_00541e6c]
        test     eax, eax
        jne      L_983c
    L_9837:
        call     DualInstallCallSwap_00490c80
    L_983c:
        pop      edi
        pop      esi
        ret      
    }
}

