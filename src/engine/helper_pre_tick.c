/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b9770 (197b engine.render) - dispatch + reorder + scaled chain copy.
 *   call DispatchScaledLEA; ecx = [0x52ab10] + 0x18; g_scaledInit = packed_ptr(0xab4878);
 *   g_xformEntityIdx = ecx; call NodeApplyTransform; pause? -> tail copy.
 *   push 0xab4d58, 0xab4878; call Word9Reorder; add esp, 8.
 *   Two memcpy-shl4 loops: [0x52aa90 .. +9 dwords] = [0xab4878 .. +9 words]*16;
 *     [0x537f50 .. +9 dwords] = [0xab4d58 .. +9 words]*16.
 *   ecx = [0x52ab10] + 0x15 (packed_ptr ofs); g_xformEntityIdx = ecx;
 *   [0xab4d18..0x20] = chain[ecx+0..+8]; [0xab4e24] = chain[ecx+0x58].
 */
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_load_0052ab10;
extern unsigned int g_dispatchSave1551_00ab4d18;
extern unsigned int g_dispatchSave1552_00ab4d1c;
extern unsigned int g_dispatchSave1553_00ab4d20;
extern unsigned int g_dispatchSave1569_00ab4e24;
extern void DispatchScaledLEA_004b8f50(void);
extern void Word9Reorder_004b3b30(void);

extern unsigned int g_data_004d57ac_arr;

void Helper_PreTick(void) {
    __asm {
        call    DispatchScaledLEA_004b8f50
        mov     ecx, dword ptr [g_load_0052ab10]
        mov     eax, 0x00ab4878
        sar     eax, 2
        add     ecx, 0x18
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        call    NodeApplyTransform_C
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   91h
        _emit   00h
        _emit   00h
        _emit   00h
        push    0x00ab4d58
        push    0x00ab4878
        call    Word9Reorder_004b3b30
        add     esp, 8
        mov     ecx, 0x0052aa90
        mov     eax, 0x00ab4878
        movsx   edx, word ptr [eax]
        shl     edx, 4
        mov     [ecx], edx
        add     eax, 2
        add     ecx, 4
        cmp     eax, 0x00ab488a
        _emit   7ch
        _emit   0ebh
        mov     ecx, 0x00537f50
        mov     eax, 0x00ab4d58
        movsx   edx, word ptr [eax]
        shl     edx, 4
        mov     [ecx], edx
        add     eax, 2
        add     ecx, 4
        cmp     eax, 0x00ab4d6a
        _emit   7ch
        _emit   0ebh
        mov     ecx, dword ptr [g_load_0052ab10]
        lea     eax, [ecx + 0x15]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, [eax*4 + g_data_004d57ac_arr]
        mov     dword ptr [g_dispatchSave1551_00ab4d18], edx
        mov     edx, [eax*4 + 4]
        mov     dword ptr [g_dispatchSave1552_00ab4d1c], edx
        mov     eax, [eax*4 + 8]
        mov     dword ptr [g_dispatchSave1553_00ab4d20], eax
        mov     ecx, [ecx*4 + 0x58]
        mov     dword ptr [g_dispatchSave1569_00ab4e24], ecx
        }
}


