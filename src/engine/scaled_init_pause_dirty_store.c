/**
 * 2 "scaled init + call + pause/dirty guarded scaled store" (56b).
 *
 * Pattern:
 *   mov     eax, IMM_PTR
 *   shr     eax, 2
 *   mov     [g_xformEntityIdx], eax
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte ptr [g_xformDirtyFlags], 4
 *   jne     .ret
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     edx, [g_scaledInit_00542044]
 *   mov     [ecx*4 + 0x5c], edx
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

extern void func_00406dd0(void);
extern void func_00406c10(void);

/* @addr 0x00445f00 */
__declspec(naked) void ScaledInitPauseDirtyStore_00445f00(void) {
    __asm {
        mov     eax, 0x00511444
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    func_00406dd0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ch
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   13h
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [ecx*4 + 0x5c], edx
        ret
    }
}

/* @addr 0x00446240 */
__declspec(naked) void ScaledInitPauseDirtyStore_00446240(void) {
    __asm {
        mov     eax, 0x004ec8f8
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    func_00406c10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ch
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   13h
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [ecx*4 + 0x5c], edx
        ret
    }
}
