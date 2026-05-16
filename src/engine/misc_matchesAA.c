/**
 * Thirty-sixth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueEnd;

/* @addr 0x0049d2d0 (52b)
 *   triple copy from a[0..8] into b[4..0xc] with each pass
 *   echoing through g_walkCallback.
 */
__declspec(naked) void ScaledTripleCopy4_0049d2d0(void) {
    __asm {
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        shl     eax, 2
        shl     ecx, 2
        mov     edx, dword ptr [eax]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 4], edx
        mov     edx, dword ptr [eax + 4]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 8], edx
        mov     eax, dword ptr [eax + 8]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx + 0x0c], eax
        ret
    }
}

/* @addr 0x0049d340 (52b): same shape, offsets shift to 0x10/0x14/0x18 */
__declspec(naked) void ScaledTripleCopy10_0049d340(void) {
    __asm {
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        shl     eax, 2
        shl     ecx, 2
        mov     edx, dword ptr [eax]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x10], edx
        mov     edx, dword ptr [eax + 4]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx + 0x14], edx
        mov     eax, dword ptr [eax + 8]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx + 0x18], eax
        ret
    }
}

/* @addr 0x00494140 (61b)
 *   arg sar 2 → g_eventQueueTotal; scaled load [baseSel*4 + 0x30] → g_walkCallback
 *   scaled load [arg*4 + 0] → g_xformEntityIdx; if walk!=0 also load +4.
 */
__declspec(naked) void ArgScaledTestStore_00494140(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [g_baseSel_00542060]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [ecx*4 + 0x30]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0]
        test    ecx, ecx
        mov     dword ptr [g_xformEntityIdx], edx
        _emit   74h
        _emit   0ch
        mov     eax, dword ptr [eax*4 + 4]
        mov     dword ptr [g_xformEntityIdx], eax
        ret
    }
}

/* @addr 0x004949b0 (55b)
 *   arg sar 2 → g_eventQueueEnd; +3 → g_eventQueueTotal;
 *   load [eax*4 + 0]; store at [baseSel*4 + 0x6c]; clear g_eventQueueTotal; jmp T.
 */
extern void MoveDispatch4StateFsm_00494a60(void);
__declspec(naked) void ArgScaledChain_004949b0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [g_baseSel_00542060]
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        add     eax, 3
        mov     dword ptr [g_eventQueueTotal], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [ecx*4 + 0x6c], eax
        mov     dword ptr [g_eventQueueTotal], 0
        jmp     MoveDispatch4StateFsm_00494a60
    }
}

/* @addr 0x00490740 (51b)
 *   load fightGroupHead*4 into eax; xor ecx,ecx → g_walkCallback;
 *   set [eax+0x6c]=0; reload walk into ecx; set [eax+0x70]=ecx; etc. for 0x74, 0x4c
 *   then jmp.
 */
extern void ZeroThreeSlots_00490780(void);
__declspec(naked) void ScaledZeroFour_00490740(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        shl     eax, 2
        xor     ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x6c], ecx
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x70], ecx
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x74], edx
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x4c], ecx
        jmp     ZeroThreeSlots_00490780
    }
}

/* @addr 0x004911f0 (57b)
 *   scaled chain: baseSel*4 + 0x40 → g_scaledInit; deref *4 → g_eventQueueNotMask
 *   reload baseSel*4 + 0x44 → g_scaledInit; deref *4 → g_eventQueueChild
 */
__declspec(naked) void ScaledChainDouble_004911f0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x40]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     ecx, dword ptr [ecx*4 + 0]
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     eax, dword ptr [eax*4 + 0x44]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_eventQueueChild], edx
        ret
    }
}

/* @addr 0x00491950 (54b)
 *   set 5 to walk and g_state_0052aac4; call F1; pause → ret;
 *   testb 1, dirty; jne ret-skip; jmp T;
 *   call F2; jmp T2.
 */
extern unsigned int g_state_0052aac4_aa;
extern void DualTestDirtyToggle_004282c0(void);
extern void func_0041f780_aa(void);
extern void IncCapped3e7_00491920(void);
extern void RoundStartCluster_004919c0(void);
__declspec(naked) void Set5CallPauseTestByteJmpCall_00491950(void) {
    __asm {
        mov     eax, 5
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_0052aac4_aa], eax
        call    DualTestDirtyToggle_004282c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   75h
        _emit   05h
        jmp     func_0041f780_aa
        call    IncCapped3e7_00491920
        jmp     RoundStartCluster_004919c0
        ret
    }
}

/* @addr 0x004923b0 (63b)
 *   push ebx; do { push 0x1e; call F1; add esp; push 0x1e; call F2;
 *                  load dirty flag; bl=4; if (dirty & bl) break; } while (1)
 *   pop ebx; ret
 */
extern void SaveCallRestore_004049d0(int);
extern void SaveCallRestoreOrXor_00404a00(int);
__declspec(naked) void Push1eCallTestDirtyLoop_004923b0(void) {
    __asm {
        push    ebx
        push    0x1e
        call    SaveCallRestore_004049d0
        add     esp, 4
        push    0x1e
        call    SaveCallRestoreOrXor_00404a00
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     bl, 4
        add     esp, 4
        test    al, bl
        _emit   75h
        _emit   1dh
        push    0x1e
        call    SaveCallRestore_004049d0
        add     esp, 4
        push    0x1e
        call    SaveCallRestoreOrXor_00404a00
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        test    al, bl
        _emit   74h
        _emit   0e3h
        pop     ebx
        ret
    }
}

/* @addr 0x0048f2a0 (63b)
 *   load 3 globals; push esi (saving callee reg); cmp/conditional store dance;
 *   pop esi; ret.
 */
extern unsigned int g_state_00538158;
extern unsigned int g_state_00535d04;
extern unsigned int g_state_0053a774;
__declspec(naked) void ScaledLoadCmpStoreXfm_0048f2a0(void) {
    __asm {
        mov     eax, dword ptr [g_state_00538158]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_state_00535d04]
        push    esi
        mov     esi, dword ptr [g_state_0053a774]
        cmp     ecx, eax
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   74h
        _emit   10h
        cmp     ecx, eax
        mov     dword ptr [g_walkCallback], edx
        _emit   74h
        _emit   06h
        mov     dword ptr [g_eventQueueCurrent], esi
        pop     esi
        ret
    }
}

/* @addr 0x0046a1e0 (65b)
 *   set 0xa → walk; call F; pause → ret;
 *   load g_fightGroupHead, g_state_00538158; cmp; set 0x26 (or 0x27 if !eq); jmp T.
 */
extern void SpecialAnimBuilder_004937b0(void);
extern void func_00489ff0_aa(void);
__declspec(naked) void Set0xaCmpEqSet0x26Jmp_0046a1e0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x0a
        call    SpecialAnimBuilder_004937b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   28h
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_state_00538158]
        cmp     eax, ecx
        mov     dword ptr [g_walkCallback], 0x26
        _emit   74h
        _emit   0ah
        mov     dword ptr [g_walkCallback], 0x27
        jmp     func_00489ff0_aa
        ret
    }
}
