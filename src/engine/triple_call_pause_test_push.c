/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00482e60 (70b)
 *   3 calls + pause-test chain; testb 1,[dirty] → ret;
 *   push 0x4ee2f0; call F4; add esp 4; ret.
 */
extern void CjTableThresholdDispatch_00488f00(void);
extern void func_00484572(void);
extern void func_004ae794(void);
extern void ArgSarStoreJmp_004594f0(void);
extern unsigned int g_dispatchSave1309_004ee2f0;

void TripleCallPauseTestPush_00482e60(void) {
    __asm {
        call    CjTableThresholdDispatch_00488f00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   37h
        call    func_00484572
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        call    func_004ae794
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        _emit   0e9h
        _emit   18h
        _emit   00h
        _emit   00h
        _emit   00h
        push    OFFSET g_dispatchSave1309_004ee2f0
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        }
}

