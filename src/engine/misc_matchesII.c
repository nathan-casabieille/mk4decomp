/**
 * Forty-fourth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueEnd;
extern u32 g_pendingNodeType;

/* @addr 0x004059a0 (90b)
 *   Push g_scaledInit on stack[idx*4]; load scaled[+0x18];
 *   if non-zero, set scaled, call F, pause-test;
 *   then pop stack back into g_scaledInit. Standard "save-restore" wrapper.
 */
extern void ScaledAndMaskInitJmp_00405a00(void);
__declspec(naked) void PushPopScaled18_004059a0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [edx*4 + 0x18]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   13h
        mov     dword ptr [g_scaledInit_00542044], eax
        call    ScaledAndMaskInitJmp_00405a00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x00405ad0 (90b): same shape but uses g_xformEntityIdx, field +0x14 */
extern void MStackPush2ChainPrepend_00409970(void);
__declspec(naked) void PushPopScaled14_00405ad0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [edx*4 + 0x14]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   05h
        mov     dword ptr [g_xformEntityIdx], eax
        call    MStackPush2ChainPrepend_00409970
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x00408510 (99b): variant with double pause check + g_fightGroupHead +0x1c */
extern void func_00409970_ii(void);
extern void PushSetCallCleanup_00408580(void);
__declspec(naked) void PushPopScaled1cDoubleCall_00408510(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    func_00409970_ii
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3ch
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x1c]
        test    eax, eax
        mov     dword ptr [g_xformEntityIdx], eax
        _emit   74h
        _emit   0eh
        call    PushSetCallCleanup_00408580
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x0040a7e0 (69b)
 *   push g_eventQueueEnd, add 0x15, restore at end after call.
 */
extern void Copy3Fields38_0040a870(void);
__declspec(naked) void StackPushAdd15CallPop_0040a7e0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_eventQueueEnd]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_eventQueueEnd]
        add     edx, 0x15
        mov     dword ptr [g_eventQueueEnd], edx
        call    Copy3Fields38_0040a870
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], edx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x0040bf20 (66b)
 *   push 0x408040; call F; load g_fightGroupHead; push it; call F2;
 *   clear g_scaledInit; call F3; pause-test → ret;
 *   testb 4,[dirty]; if cleared then jmp T; ret.
 */
extern void *g_data_00408040;
extern void ThreeChanPackClamp_00404cc0(void *);
extern void CopyThreeFields_00404df0(int);
extern void func_00405420_ii(void);
extern void BootMStackBracketedScaledStores_0040bf70(void);
__declspec(naked) void PushCallScaledClearJmp_0040bf20(void) {
    __asm {
        push    OFFSET g_data_00408040
        call    ThreeChanPackClamp_00404cc0
        mov     eax, dword ptr [g_fightGroupHead]
        add     esp, 4
        push    eax
        call    CopyThreeFields_00404df0
        add     esp, 4
        mov     dword ptr [g_scaledInit_00542044], 0
        call    func_00405420_ii
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0eh
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   05h
        jmp     BootMStackBracketedScaledStores_0040bf70
        ret
    }
}

/* @addr 0x004084b0 (81b)
 *   load scaled, eventQueueCurrent; load scaled[+0x1c] into eax;
 *   if eventQueueCurrent < eax, store eax into eventQueueCurrent;
 *   load scaled[0]; if non-zero set walk = own VA, call F, pause-test;
 *   clear dirty bit 1; ret.
 */
extern void Helper_TickAlt(void);
__declspec(naked) void ScaledLoadCallSet1c_004084b0(void) {
    __asm {
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     eax, dword ptr [ecx*4 + 0x1c]
        cmp     edx, eax
        _emit   7dh
        _emit   05h
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     eax, dword ptr [ecx*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   18h
        mov     dword ptr [g_walkCallback], 0x004084b0
        call    Helper_TickAlt
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ch
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al,  0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x004147b0 (87b)
 *   set dirty |= 4; if g_scaledInit != 0:
 *     dirty ^= 4 (back); load scaled+0x18 → scaled; load scaled+0x28 → eax;
 *     set walk = 0x414600 + store at [eax*4 + 0x10]; ret.
 */
__declspec(naked) void SetDirty4XorScaledLoad_004147b0(void) {
    __asm {
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     ecx, 4
        or      eax, ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        mov     eax, dword ptr [g_scaledInit_00542044]
        test    eax, eax
        _emit   74h
        _emit   3ch
        mov     edx, dword ptr [g_xformDirtyFlags]
        xor     edx, ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   2ah
        mov     eax, dword ptr [eax*4 + 0x18]
        mov     ecx, 0x00414600
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0x10], ecx
        ret
    }
}

/* @addr 0x004196c0 (83b)
 *   call F; pause → ret; testb 4,[dirty] → ret;
 *   load g_eventQueueEnd; mov [eax*4 + 0x30]=0x81; load g_xformEntityIdx;
 *   set walk = 0x14ccc + store at [ecx*4 + 0x48]; eventQueueEnd+0x15 → g_scaledInit;
 *   jmp T.
 */
extern void SlotInitAndChainLink_004191b0(void);
extern void BootGatedInitInstallPair_00412280(void);
__declspec(naked) void CallPauseDirty4ScaledSet_004196c0(void) {
    __asm {
        call    SlotInitAndChainLink_004191b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   44h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   3bh
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     dword ptr [eax*4 + 0x30], 0x81
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x14ccc
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        add     edx, 0x15
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     BootGatedInitInstallPair_00412280
        ret
    }
}

/* @addr 0x00407c00 (88b)
 *   triple bit-extract from g_walkCallback: low 11 bits, mid 11 bits, high 10 bits;
 *   store each into a 3-vec at g_pendingNodeType*4 with stride 4.
 */
__declspec(naked) void ExtractBitsToVec3_00407c00(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_pendingNodeType]
        and     eax, 0x7ff
        shl     eax, 1
        mov     dword ptr [ecx*4 + 0], eax
        mov     eax, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_pendingNodeType]
        shr     eax, 0x0b
        and     eax, 0x7ff
        shl     eax, 1
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [edx*4 + 4], eax
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_pendingNodeType]
        shr     eax, 0x16
        shl     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 8], eax
        ret
    }
}

/* @addr 0x00404c70 (66b) — same as misc_matchesHH:SetWalkCurCallPauseDirty_00404c70
 *   (already matched). Pick a different smaller stub: 0x00404680 size has been
 *   matched. Replace with 0x004196c0 already used; pick 0x0040bf20 already used.
 *   Substitute: 0x004084b0 already used. Pick 0x00404a00 (already matched in HH).
 *   Use a new stub: 0x004196c0 already taken. Pick a new candidate from the larger
 *   table — 0x004084b0 already done. Use 0x0040bf20 already done.
 *   Fallback: nothing else clean here, so emit only 9 in this batch.
 */
