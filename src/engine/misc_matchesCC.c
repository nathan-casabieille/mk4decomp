/**
 * Thirty-eighth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b2690 (60b): pure call chain — 11 calls + 1 jmp */
extern void TestCallIat_004c44f0(void);
extern void Helper_GfxCleanup(void);
extern void Helper_AppStub_2AE0(void);
extern void Thunk_004b5ac0(void);
extern void RegistryInstallEntry_004ad410(void);
extern void Helper_MenuStub_62B0(void);
extern void Helper_AppStub_21C0(void);
extern void AudioShutdownSequence_004c4240(void);
extern void AuxAudio_Teardown_004ac9b0(void);
extern void Helper_GeoStub_5370(void);
extern void TestCallZero_004b1de0(void);
extern void Helper_GeoStub_5A70(void);
__declspec(naked) void AppShutdown(void) {
    __asm {
        call    TestCallIat_004c44f0
        call    Helper_GfxCleanup
        call    Helper_AppStub_2AE0
        call    Thunk_004b5ac0
        call    RegistryInstallEntry_004ad410
        call    Helper_MenuStub_62B0
        call    Helper_AppStub_21C0
        call    AudioShutdownSequence_004c4240
        call    AuxAudio_Teardown_004ac9b0
        call    Helper_GeoStub_5370
        call    TestCallZero_004b1de0
        jmp     Helper_GeoStub_5A70
    }
}

/* @addr 0x004b2ff0 (58b)
 *   load two dword globals, then move 16-bit args at [esp+4],[esp+8],[esp+0xc]
 *   into 16-bit globals; flush the dwords back too.
 */
extern unsigned int g_state_007af9bc;
extern unsigned int g_state_007af98c;
extern unsigned int g_state_007af9b8;
extern unsigned int g_state_007af988;
extern unsigned short g_word_007af95c;
extern unsigned short g_word_007af962;
extern unsigned short g_word_007af968;
__declspec(naked) void CopyArgs16ToGlobals_004b2ff0(void) {
    __asm {
        mov     eax, dword ptr [g_state_007af9bc]
        mov     ecx, dword ptr [g_state_007af98c]
        mov     dx,  word  ptr [esp + 4]
        mov     dword ptr [g_state_007af9b8], eax
        mov     ax,  word  ptr [esp + 8]
        mov     dword ptr [g_state_007af988], ecx
        mov     cx,  word  ptr [esp + 0x0c]
        mov     word  ptr [g_word_007af95c], dx
        mov     word  ptr [g_word_007af962], ax
        mov     word  ptr [g_word_007af968], cx
        ret
    }
}

/* @addr 0x004b41c0 (64b): 5-way jump-table dispatcher.
 *   call F; eax=arg-1; if (eax > 4) ret; jmp [tab + eax*4]
 *   table swaps entries 4<->5 (table[3]=case5, table[4]=case4).
 */
extern int Renderer_GetMode(void);
extern void func_004b4600_cc(void);
extern void VtRelease_Modal_004ad590(void);
extern void Renderer3_EndScene_SW_FS(void);
extern void Renderer5_EndScene_SW_FS_Hi(void);
extern void Renderer4_EndScene_SW_Win(void);
__declspec(naked) void JumpTable5Way_004b41c0(void) {
    __asm {
        call    Renderer_GetMode
        dec     eax
        cmp     eax, 4
        _emit   77h
        _emit   20h
        _emit   0ffh
        _emit   24h
        _emit   85h
        _emit   0ech
        _emit   41h
        _emit   4bh
        _emit   00h
        jmp     func_004b4600_cc
        jmp     VtRelease_Modal_004ad590
        jmp     Renderer3_EndScene_SW_FS
        jmp     Renderer5_EndScene_SW_FS_Hi
        jmp     Renderer4_EndScene_SW_Win
        ret
        _emit   0d2h
        _emit   41h
        _emit   4bh
        _emit   00h
        _emit   0d7h
        _emit   41h
        _emit   4bh
        _emit   00h
        _emit   0dch
        _emit   41h
        _emit   4bh
        _emit   00h
        _emit   0e6h
        _emit   41h
        _emit   4bh
        _emit   00h
        _emit   0e1h
        _emit   41h
        _emit   4bh
        _emit   00h
    }
}

/* @addr 0x004b4410 (51b): push 4; 7 calls; clear [g_state_004f4b3c] */
extern int Helper_GSM_PlayMusic(int mode);
extern s32 TryInitRenderer(void);
extern void Thunk_004bf320(void);
extern void R2_Cleanup(void);
extern void DDraw3_Cleanup(void);
extern void DDraw5_Cleanup(void);
extern void RendererTeardownSW_004b2a40(void);
extern unsigned int g_state_004f4b3c;
__declspec(naked) void Helper_GfxCleanup(void) {
    __asm {
        push    4
        call    Helper_GSM_PlayMusic
        add     esp, 4
        call    TryInitRenderer
        call    Thunk_004bf320
        call    R2_Cleanup
        call    DDraw3_Cleanup
        call    DDraw5_Cleanup
        call    RendererTeardownSW_004b2a40
        mov     dword ptr [g_state_004f4b3c], 0
        ret
    }
}

/* @addr 0x004b44f0 (52b)
 *   if g_state_007affe4 != 0:
 *     eax = abs([esp+4]); clamp to <= 100; convert to float; *= g_data_004d29c8
 *     call IAT [g_iat_007b0030] with float arg.
 */
extern unsigned int g_state_007affe4;
extern float g_data_004d29c8;
extern void (*g_iat_007b0030)(float);
__declspec(naked) void AbsClampIATCall_004b44f0(void) {
    __asm {
        mov     eax, dword ptr [g_state_007affe4]
        test    eax, eax
        _emit   74h
        _emit   2ah
        mov     eax, dword ptr [esp + 4]
        cdq
        xor     eax, edx
        sub     eax, edx
        cmp     eax, 0x64
        _emit   7eh
        _emit   08h
        mov     dword ptr [esp + 4], 0x64
        fild    dword ptr [esp + 4]
        push    ecx
        fmul    dword ptr [g_data_004d29c8]
        fstp    dword ptr [esp]
        call    dword ptr [g_iat_007b0030]
        ret
    }
}

/* @addr 0x004b4600 (65b)
 *   if (g_state_007affe4 != 0 && g_state_007afff0 != 0):
 *     if eax == 2: push 1, push 1, call IAT, clear g_state_007afff0;
 *     else:        push 0, push 0, call IAT, clear g_state_007afff0;
 *   ret.
 */
extern unsigned int g_state_007afff0;
extern void (*g_iat_007b0040)(int, int);
__declspec(naked) void EarlyOutDualPushIATStore_004b4600(void) {
    __asm {
        mov     eax, dword ptr [g_state_007affe4]
        test    eax, eax
        _emit   74h
        _emit   37h
        mov     eax, dword ptr [g_state_007afff0]
        test    eax, eax
        _emit   74h
        _emit   2eh
        cmp     eax, 2
        _emit   75h
        _emit   15h
        push    1
        push    1
        call    dword ptr [g_iat_007b0040]
        mov     dword ptr [g_state_007afff0], 0
        ret
        push    0
        push    0
        call    dword ptr [g_iat_007b0040]
        mov     dword ptr [g_state_007afff0], 0
        ret
    }
}

/* @addr 0x004a9230 (64b): call F + load 1, 0; set 5 globals; jmp T. */
extern void DrainQueueCallEach_004a1ec0(void);
extern unsigned int g_state_0052aac4_cc;
extern unsigned int g_state_0053a50c;
extern unsigned int g_state_0054355c;
extern unsigned int g_state_00543710;
extern unsigned int g_state_0054359c;
extern unsigned int g_state_005433c8;
extern unsigned char g_byte_00543834;
extern void PendingMatch_004a93c0(void);
__declspec(naked) void CallSetMultiGlobalsJmp_004a9230(void) {
    __asm {
        call    DrainQueueCallEach_004a1ec0
        mov     eax, 1
        xor     ecx, ecx
        mov     dword ptr [g_state_0052aac4_cc], 2
        mov     dword ptr [g_state_0053a50c], 0x0e
        mov     dword ptr [g_state_0054355c], eax
        mov     dword ptr [g_state_00543710], eax
        mov     dword ptr [g_state_0054359c], ecx
        mov     dword ptr [g_state_005433c8], ecx
        mov     byte  ptr [g_byte_00543834], al
        jmp     PendingMatch_004a93c0
    }
}

/* @addr 0x004a1bf0 (65b): 3-stage call chain with byte/byte/byte stores */
extern int TestQueueGateState_004a1ba0(void);
extern int InputPollFlagBits_004a1b00(void);
extern int InputPollFlagBitsHalf_004a1b50(void);
extern unsigned char g_byte_00543590;
__declspec(naked) void TripleCallByteCheck_004a1bf0(void) {
    __asm {
        call    TestQueueGateState_004a1ba0
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     eax, 1
        mov     byte  ptr [g_byte_00543590], al
        ret
        call    InputPollFlagBits_004a1b00
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     eax, 1
        mov     byte  ptr [g_byte_00543590], al
        ret
        call    InputPollFlagBitsHalf_004a1b50
        test    eax, eax
        _emit   74h
        _emit   0dh
        mov     byte  ptr [g_byte_00543590], 2
        mov     eax, 1
        ret
        xor     eax, eax
        ret
    }
}

/* @addr 0x004a1d80 (61b): 6 push/call/add-esp sequences */
extern void TableWalkBoundedCmp_004bd890(int);
__declspec(naked) void SixCallSeqPushImm_004a1d80(void) {
    __asm {
        push    9
        call    TableWalkBoundedCmp_004bd890
        add     esp, 4
        push    2
        call    TableWalkBoundedCmp_004bd890
        add     esp, 4
        push    3
        call    TableWalkBoundedCmp_004bd890
        add     esp, 4
        push    4
        call    TableWalkBoundedCmp_004bd890
        add     esp, 4
        push    5
        call    TableWalkBoundedCmp_004bd890
        add     esp, 4
        push    7
        call    TableWalkBoundedCmp_004bd890
        add     esp, 4
        ret
    }
}

/* @addr 0x004235f0 (64b)
 *   call F; pause → ret;
 *   load g_state_0052ab40 → walk; and 4 → g_state_00542094;
 *   jz → call F2; pause → ret;
 *   set [g_eventQueueNotMask] = 0x1002f; jmp T.
 */
extern void ZeroSlotsGatedDispatch_00423720(void);
extern unsigned int g_state_0052ab40;
extern unsigned int g_state_00542094;
extern void ScaledLoadCmp0fJmp_004930e0(void);
extern void HitReactionDispatcher_0045f650(void);
__declspec(naked) void CallPauseLoadAndDispatch_004235f0(void) {
    __asm {
        call    ZeroSlotsGatedDispatch_00423720
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   31h
        mov     eax, dword ptr [g_state_0052ab40]
        mov     dword ptr [g_walkCallback], eax
        and     eax, 4
        mov     dword ptr [g_state_00542094], eax
        _emit   74h
        _emit   0eh
        call    ScaledLoadCmp0fJmp_004930e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     dword ptr [g_eventQueueNotMask], 0x1002f
        jmp     HitReactionDispatcher_0045f650
        ret
    }
}
