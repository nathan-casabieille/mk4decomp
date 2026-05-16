/**
 * Forty-fifth batch of one-off matches.
 * 83b/95b cluster of "CallPauseDirty4ScaledSet" / "DualCallPauseAddrSetRecurse"
 * variants from the entity-init dispatch table.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_eventQueueWorkType;
extern u32 g_pendingNodeType;

extern void SlotInitAndChainLink_004191b0(void);
extern void BootGatedInitInstallPair_00412280(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);

/* === 83b cluster: CallPauseDirty4ScaledSetVariant === */

/* @addr 0x00419780 (83b): val1=0x83, imm=0x11999 */
__declspec(naked) void CallPauseDirty4ScaledSet_00419780(void) {
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
        mov     dword ptr [eax*4 + 0x30], 0x83
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x11999
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        add     edx, 0x15
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     BootGatedInitInstallPair_00412280
        ret
    }
}

/* @addr 0x00419840 (83b): val1=0x86, imm=0x11999 */
__declspec(naked) void CallPauseDirty4ScaledSet_00419840(void) {
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
        mov     dword ptr [eax*4 + 0x30], 0x86
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x11999
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        add     edx, 0x15
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     BootGatedInitInstallPair_00412280
        ret
    }
}

/* @addr 0x00419980 (83b): val1=0x87, imm=0x11999 */
__declspec(naked) void CallPauseDirty4ScaledSet_00419980(void) {
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
        mov     dword ptr [eax*4 + 0x30], 0x87
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x11999
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        add     edx, 0x15
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     BootGatedInitInstallPair_00412280
        ret
    }
}

/* @addr 0x00419a40 (83b): val1=0x82, imm=0x11999 */
__declspec(naked) void CallPauseDirty4ScaledSet_00419a40(void) {
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
        mov     dword ptr [eax*4 + 0x30], 0x82
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x11999
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        add     edx, 0x15
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     BootGatedInitInstallPair_00412280
        ret
    }
}

/* @addr 0x00419b00 (83b): val1=0x88, imm=0x13333 */
__declspec(naked) void CallPauseDirty4ScaledSet_00419b00(void) {
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
        mov     dword ptr [eax*4 + 0x30], 0x88
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x13333
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        add     edx, 0x15
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     BootGatedInitInstallPair_00412280
        ret
    }
}

/* === 95b cluster: DualCallPauseAddrSetRecurseSet === */

extern void func_004196c0_jj(void);
extern void func_00419780_jj(void);
extern void func_00419840_jj(void);
extern void func_00419980_jj(void);
extern void func_00419a40_jj(void);
extern void func_00419b00_jj(void);
extern unsigned int g_data_004d7918;
extern unsigned int g_data_004d78e8;
extern unsigned int g_data_004d7ac8;
extern unsigned int g_data_004d7b58;
extern unsigned int g_data_004d79d8;
extern unsigned int g_data_004d79a8;
extern unsigned int g_data_004d7978;
extern unsigned int g_data_004d7948;
extern unsigned int g_data_004d7a98;
extern unsigned int g_data_004d7a68;
extern unsigned int g_data_004d7a38;
extern unsigned int g_data_004d7a08;

/* @addr 0x00419720 (95b): addr1=0x4d7918/0xa, recurse 0x4196c0, addr2=0x4d78e8/9 */
__declspec(naked) void DualCallPauseAddrSetRecurse_00419720(void) {
    __asm {
        call    MStackPush2RunCountdown_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   50h
        call    MStackBracket7_DispatchAndChain_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   42h
        mov     eax, OFFSET g_data_004d7918
        mov     dword ptr [g_eventQueueWorkType], 0x0a
        shr     eax, 2
        mov     dword ptr [g_pendingNodeType], eax
        call    func_004196c0_jj
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        mov     ecx, OFFSET g_data_004d78e8
        mov     dword ptr [g_eventQueueWorkType], 0x09
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], ecx
        jmp     func_004196c0_jj
        ret
    }
}

/* @addr 0x004197e0 (95b): addr1=0x4d7ac8/6, recurse 0x419780, addr2=0x4d7b58/5 */
__declspec(naked) void DualCallPauseAddrSetRecurse_004197e0(void) {
    __asm {
        call    MStackPush2RunCountdown_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   50h
        call    MStackBracket7_DispatchAndChain_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   42h
        mov     eax, OFFSET g_data_004d7ac8
        mov     dword ptr [g_eventQueueWorkType], 0x06
        shr     eax, 2
        mov     dword ptr [g_pendingNodeType], eax
        call    func_00419780_jj
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        mov     ecx, OFFSET g_data_004d7b58
        mov     dword ptr [g_eventQueueWorkType], 0x05
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], ecx
        jmp     func_00419780_jj
        ret
    }
}

/* @addr 0x004198a0 (95b): addr1=0x4d79d8/0xc, recurse 0x419840, addr2=0x4d79a8/0xb */
__declspec(naked) void DualCallPauseAddrSetRecurse_004198a0(void) {
    __asm {
        call    MStackPush2RunCountdown_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   50h
        call    MStackBracket7_DispatchAndChain_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   42h
        mov     eax, OFFSET g_data_004d79d8
        mov     dword ptr [g_eventQueueWorkType], 0x0c
        shr     eax, 2
        mov     dword ptr [g_pendingNodeType], eax
        call    func_00419840_jj
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        mov     ecx, OFFSET g_data_004d79a8
        mov     dword ptr [g_eventQueueWorkType], 0x0b
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], ecx
        jmp     func_00419840_jj
        ret
    }
}

/* @addr 0x004199e0 (95b): addr1=0x4d7978/0xe, recurse 0x419980, addr2=0x4d7948/0xd */
__declspec(naked) void DualCallPauseAddrSetRecurse_004199e0(void) {
    __asm {
        call    MStackPush2RunCountdown_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   50h
        call    MStackBracket7_DispatchAndChain_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   42h
        mov     eax, OFFSET g_data_004d7978
        mov     dword ptr [g_eventQueueWorkType], 0x0e
        shr     eax, 2
        mov     dword ptr [g_pendingNodeType], eax
        call    func_00419980_jj
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        mov     ecx, OFFSET g_data_004d7948
        mov     dword ptr [g_eventQueueWorkType], 0x0d
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], ecx
        jmp     func_00419980_jj
        ret
    }
}

/* @addr 0x00419aa0 (95b): addr1=0x4d7a98/8, recurse 0x419a40, addr2=0x4d7a68/7 */
__declspec(naked) void DualCallPauseAddrSetRecurse_00419aa0(void) {
    __asm {
        call    MStackPush2RunCountdown_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   50h
        call    MStackBracket7_DispatchAndChain_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   42h
        mov     eax, OFFSET g_data_004d7a98
        mov     dword ptr [g_eventQueueWorkType], 0x08
        shr     eax, 2
        mov     dword ptr [g_pendingNodeType], eax
        call    func_00419a40_jj
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        mov     ecx, OFFSET g_data_004d7a68
        mov     dword ptr [g_eventQueueWorkType], 0x07
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], ecx
        jmp     func_00419a40_jj
        ret
    }
}

/* @addr 0x00419b60 (95b): addr1=0x4d7a38/0x10, recurse 0x419b00, addr2=0x4d7a08/0xf */
__declspec(naked) void DualCallPauseAddrSetRecurse_00419b60(void) {
    __asm {
        call    MStackPush2RunCountdown_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   50h
        call    MStackBracket7_DispatchAndChain_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   42h
        mov     eax, OFFSET g_data_004d7a38
        mov     dword ptr [g_eventQueueWorkType], 0x10
        shr     eax, 2
        mov     dword ptr [g_pendingNodeType], eax
        call    func_00419b00_jj
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        mov     ecx, OFFSET g_data_004d7a08
        mov     dword ptr [g_eventQueueWorkType], 0x0f
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], ecx
        jmp     func_00419b00_jj
        ret
    }
}
