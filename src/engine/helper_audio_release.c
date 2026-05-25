/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_data_004ffd50;
extern u8 g_audioChannelTable[];
extern unsigned int g_obj_size_00f8fad8;
extern unsigned int g_data_00f8fadc;
extern unsigned int g_flags_00f8fade;
extern void * g_dsoundContext;
extern unsigned int g_data_00f9efd8;
extern u32 g_dsoundFieldE4;
extern u32 g_dsoundFieldE8;
extern void ESF_Close(void);
extern void ESF_Open(void);
extern void ESF_ReadData(void);
extern void Helper_AudioStop(void);
extern void Helper_Sprintf(void);

extern unsigned int g_data_00f8facc;

__declspec(naked) void Helper_AudioRelease(void)
{
    __asm {
        sub      esp, 0x138
        push     ebx
        mov      ebx, dword ptr [esp + 0x140]
        push     ebp
        xor      edx, edx
        push     esi
        cmp      bx, 0x898
        push     edi
        mov      dword ptr [esp + 0x14], edx
        mov      dword ptr [esp + 0x10], edx
        jae      L_3700
        movsx    eax, bx
        mov      esi, eax
        shl      esi, 3
        sub      esi, eax
        shl      esi, 2
        mov      al, byte ptr [esi + g_flags_00f8fade]
        test     al, 2
        je       L_34e0
        and      al, 0xfd
        mov      byte ptr [esi + g_flags_00f8fade], al
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x138
        ret
    L_34e0:
        mov      eax, dword ptr [esi + g_audioChannelTable]
        lea      ebp, [esi + g_audioChannelTable]
        cmp      eax, edx
        jne      L_3700
        mov      ecx, 7
        xor      eax, eax
        mov      edi, ebp
        rep stosd
        cmp      dword ptr [g_data_00f9efd8], 0x64
        jle      L_351d
        mov      eax, dword ptr [g_dsoundContext]
        mov      dword ptr [g_data_00f9efd8], edx
        cmp      eax, edx
        je       L_351d
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x1c]
    L_351d:
        and      ebx, 0xffff
        lea      edx, [esp + 0x48]
        push     ebx
        push     OFFSET g_data_004ffd50
        push     edx
        call     Helper_Sprintf
        add      esp, 0xc
        lea      eax, [esp + 0x2c]
        lea      ecx, [esp + 0x28]
        lea      edx, [esp + 0x44]
        push     eax
        push     ecx
        lea      eax, [esp + 0x50]
        push     edx
        push     eax
        call     ESF_Open
        mov      edx, dword ptr [esp + 0x3c]
        mov      dword ptr [esi + g_obj_size_00f8fad8], eax
        mov      word ptr [esi + g_data_00f8fadc], 0
        mov      al, byte ptr [esi + g_flags_00f8fade]
        add      esp, 0x10
        and      al, 0xf9
        xor      ecx, ecx
        mov      ebx, 1
        test     edx, edx
        setne    cl
        xor      cl, al
        xor      edx, edx
        and      cl, bl
        mov      dword ptr [esp + 0x18], edx
        xor      cl, al
        mov      dword ptr [esp + 0x1c], edx
        mov      byte ptr [esi + g_flags_00f8fade], cl
        mov      ecx, dword ptr [esp + 0x44]
        mov      dword ptr [esp + 0x20], edx
        mov      eax, dword ptr [esp + 0x28]
        mov      dword ptr [esp + 0x24], edx
        mov      word ptr [esp + 0x26], cx
        shr      cx, 3
        mov      word ptr [esp + 0x24], cx
        mov      ecx, dword ptr [esp + 0x24]
        and      ecx, 0xffff
        mov      dword ptr [esp + 0x1c], eax
        imul     eax, ecx
        mov      dword ptr [esp + 0x30], edx
        mov      dword ptr [esp + 0x20], eax
        mov      eax, dword ptr [esi + g_obj_size_00f8fad8]
        mov      dword ptr [esp + 0x34], edx
        mov      dword ptr [esp + 0x38], edx
        mov      dword ptr [esp + 0x38], eax
        mov      eax, dword ptr [g_dsoundContext]
        mov      dword ptr [esp + 0x3c], edx
        lea      ecx, [esp + 0x18]
        mov      dword ptr [esp + 0x40], edx
        test     eax, eax
        mov      word ptr [esp + 0x18], bx
        mov      word ptr [esp + 0x1a], bx
        mov      dword ptr [esp + 0x30], 0x14
        mov      dword ptr [esp + 0x34], 0xe2
        mov      dword ptr [esp + 0x40], ecx
        je       L_3619
        mov      edx, dword ptr [eax]
        push     0
        lea      ecx, [esp + 0x34]
        push     ebp
        push     ecx
        push     eax
        call     dword ptr [edx + 0xc]
    L_3619:
        mov      eax, dword ptr [ebp]
        test     eax, eax
        je       L_36fb
        mov      edx, dword ptr [eax]
        push     0
        push     eax
        call     dword ptr [edx + 0x34]
        mov      eax, dword ptr [ebp]
        push     0
        push     eax
        mov      ecx, dword ptr [eax]
        call     dword ptr [ecx + 0x44]
        mov      eax, dword ptr [ebp]
        push     0
        push     eax
        mov      edx, dword ptr [eax]
        call     dword ptr [edx + 0x40]
        mov      eax, dword ptr [ebp]
        push     0
        push     eax
        mov      ecx, dword ptr [eax]
        call     dword ptr [ecx + 0x3c]
        mov      eax, dword ptr [ebp]
        push     2
        push     0
        lea      ecx, [esp + 0x18]
        mov      edx, dword ptr [eax]
        push     0
        push     ecx
        lea      ecx, [esp + 0x24]
        push     ecx
        push     0
        push     0
        push     eax
        call     dword ptr [edx + 0x2c]
        mov      ecx, dword ptr [esp + 0x14]
        test     ecx, ecx
        je       L_368d
        mov      edx, dword ptr [esp + 0x10]
        mov      eax, dword ptr [esi + g_obj_size_00f8fad8]
        cmp      edx, eax
        jb       L_368d
        push     ecx
        call     ESF_ReadData
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 4
    L_368d:
        mov      eax, dword ptr [ebp]
        mov      edi, dword ptr [esp + 0x10]
        push     0
        push     0
        mov      edx, dword ptr [eax]
        push     edi
        push     ecx
        push     eax
        call     dword ptr [edx + 0x4c]
        lea      edi, [esi + g_data_00f8facc]
    L_36a6:
        mov      eax, dword ptr [g_dsoundContext]
        mov      edx, dword ptr [ebp]
        push     edi
        push     edx
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x14]
        cmp      dword ptr [edi], 0
        je       L_36c6
        inc      ebx
        add      edi, 4
        cmp      ebx, 4
        jl       L_36a6
        jmp      L_36d6
    L_36c6:
        mov      eax, dword ptr [esp + 0x14c]
        push     eax
        call     Helper_AudioStop
        add      esp, 4
    L_36d6:
        cmp      dword ptr [ebp], 0
        je       L_36fb
        mov      ecx, dword ptr [esi + g_obj_size_00f8fad8]
        mov      edx, dword ptr [g_dsoundFieldE4]
        mov      eax, dword ptr [g_dsoundFieldE8]
        add      edx, ecx
        inc      eax
        mov      dword ptr [g_dsoundFieldE4], edx
        mov      dword ptr [g_dsoundFieldE8], eax
    L_36fb:
        call     ESF_Close
    L_3700:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x138
        ret
    }
}

