/**
 * Twenty-third batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404df0 (47b)
 *   mov     eax, [esp+4]
 *   test    eax, eax
 *   je      .ret
 *   mov     ecx, [eax*4 + 0x54]
 *   mov     [0x00ab4e50], ecx
 *   mov     edx, [eax*4 + 0x58]
 *   mov     [0x00ab4e54], edx
 *   mov     eax, [eax*4 + 0x5c]
 *   mov     [0x00ab4e58], eax
 *   ret
 */
extern unsigned int g_state_00ab4e50;
extern unsigned int g_state_00ab4e54;
extern unsigned int g_state_00ab4e58;
void CopyThreeFields_00404df0(unsigned int arg) {
    if (arg == 0) return;
    g_state_00ab4e50 = *(unsigned int *)(arg * 4 + 0x54);
    g_state_00ab4e54 = *(unsigned int *)(arg * 4 + 0x58);
    g_state_00ab4e58 = *(unsigned int *)(arg * 4 + 0x5c);
}

/* @addr 0x004051b0 (47b)
 *   xor     eax, eax
 *   mov     [0x0053a188], eax
 *   mov     [0x0053a498], eax
 *   mov     [0x0053a79c], eax
 *   mov     [0x00537f08], eax
 *   mov     [0x0053a380], eax
 *   mov     eax, 1
 *   mov     [g_walkCallback], eax
 *   mov     [0x00535d08], eax
 *   jmp     T
 */
extern unsigned int g_state_0053a188;
extern unsigned int g_state_0053a498;
extern unsigned int g_state_0053a79c;
extern unsigned int g_state_00537f08;
extern unsigned int g_state_0053a380;
extern unsigned int g_state_00535d08;
extern void func_00404efb(void);
void Init6Globals_004051b0(void) {
    g_state_0053a188 = 0;
    g_state_0053a498 = 0;
    g_state_0053a79c = 0;
    g_state_00537f08 = 0;
    g_state_0053a380 = 0;
    g_walkCallback = (void (*)(void))1;
    g_state_00535d08 = 1;
    func_00404efb();
}

/* @addr 0x00405880 (49b)
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     edx, [g_walkCallback]
 *   mov     [g_eventQueueCurrent], 0xfffffff0
 *   mov     eax, [ecx*4 + 0x20]
 *   and     eax, 0xfffffff0
 *   or      eax, edx
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [ecx*4 + 0x20], eax
 *   ret
 */
void ScaledMaskOrStore_00405880(void) {
    unsigned int idx = g_scaledInit_00542044;
    unsigned int walk = (unsigned int)g_walkCallback;
    unsigned int v;
    g_eventQueueCurrent = 0xf0ffffff;
    v = (*(unsigned int *)(idx * 4 + 0x20) & 0xf0ffffff) | walk;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x20) = v;
}

/* @addr 0x004078f0 (48b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax*4 + 0x28], ecx
 *   mov     edx, [g_fightGroupHead]
 *   add     edx, 0x0a
 *   mov     [g_state_00541dc4], edx
 *   ret
 */
extern unsigned int g_state_00541dc4;
extern void BootChainPushAddSignFlag_004077b0(void);
void CallPauseScaledStoreAdd_004078f0(void) {
    BootChainPushAddSignFlag_004077b0();
    if (g_framePauseFlag != 0) return;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = (unsigned int)g_walkCallback;
    g_state_00541dc4 = g_fightGroupHead + 0x0a;
}

/* @addr 0x004111d0 (50b)
 *   mov     al, byte ptr [0x004f360c]
 *   test    al, al
 *   je      +0x12
 *   mov     eax, 0x004d5c38
 *   shr     eax, 2
 *   mov     [g_eventQueueIdx], eax
 *   jmp     +0x25
 *   ret
 *   nop * 4
 *   mov     eax, 0x004d5c20
 *   shr     eax, 2
 *   mov     [g_eventQueueIdx], eax
 *   jmp     +0x0e
 */
extern unsigned char g_byte_004f360c;
extern void func_004111fa(void);
extern void func_00411202(void);
__declspec(naked) void TestByteSelectInit_004111d0(void) {
    __asm {
        mov     al, byte ptr [g_byte_004f360c]
        test    al, al
        _emit   74h
        _emit   12h
        mov     eax, 0x004d5c38
        shr     eax, 2
        mov     dword ptr [g_eventQueueIdx], eax
        jmp     func_004111fa
        ret
        nop
        nop
        nop
        nop
        mov     eax, 0x004d5c20
        shr     eax, 2
        mov     dword ptr [g_eventQueueIdx], eax
        jmp     func_00411202
    }
}

/* @addr 0x00428730 (48b)
 *   mov     eax, [esp+4]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     ecx, [eax*4 + 0]
 *   inc     eax
 *   mov     [g_eventQueueTotal], eax
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     [eax*4 + 0x24], ecx
 *   jmp     T
 */
extern void func_00429868(void);
void IterStepScaledStore24_00428730(int arg) {
    unsigned int packed = (unsigned int)(arg >> 2);
    unsigned int v;
    g_eventQueueTotal = packed;
    v = *(unsigned int *)(packed * 4);
    packed++;
    g_eventQueueTotal = packed;
    g_scaledInit_00542044 = v;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x24) = v;
    func_00429868();
}

/* @addr 0x0042c3b0 (48b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, 0x0042c3d0
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [ecx*4 + 0], eax
 *   ret
 *   nop * 8
 *   mov     eax, 2
 *   mov     [g_walkCallback], eax
 *   mov     [g_state_00537e94], eax
 *   ret
 */
extern unsigned int g_state_00537e94;
__declspec(naked) void StoreLitRetSet2_0042c3b0(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0x0042c3d0
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [ecx*4 + 0x44], eax
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_00537e94], eax
        ret
    }
}

/* @addr 0x004406e0 (47b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0x70]
 *   mov     [g_walkCallback], ecx
 *   mov     edx, [eax*4 + 0x4c]
 *   add     ecx, edx
 *   mov     [g_eventQueueCurrent], ecx
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x70], ecx
 *   ret
 */
__declspec(naked) void ScaledAddStore_004406e0(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 0x70]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0x4c]
        add     ecx, edx
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x70], ecx
        ret
    }
}

/* @addr 0x00446120 (46b)
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [g_fightGroupHead], eax
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x78]
 *   mov     [g_eventQueueEnd], ecx
 *   mov     edx, [eax*4 + 0x5c]
 *   mov     [g_scaledInit_00542044], edx
 *   jmp     T
 */
extern void func_00405e90(void);
void CopyScaledTriple_00446120(void) {
    unsigned int base;
    g_fightGroupHead = g_eventQueueIdx;
    base = g_baseSel_00542060;
    g_eventQueueEnd = *(unsigned int *)(base * 4 + 0x78);
    g_scaledInit_00542044 = *(unsigned int *)(base * 4 + 0x5c);
    func_00405e90();
}

/* @addr 0x00446350 (46b): same shape with offsets 0x5c->disp, 0x78->disp swapped */
extern void func_00405ce0(void);
void CopyScaledTriple_00446350(void) {
    unsigned int base = g_baseSel_00542060;
    g_scaledInit_00542044 = *(unsigned int *)(base * 4 + 0x5c);
    g_eventQueueIdx = *(unsigned int *)(base * 4 + 0x78);
    g_fightGroupHead = g_eventQueueEnd;
    func_00405ce0();
}

/* @addr 0x00458880 (46b)
 *   mov     eax, [0x0053a278]
 *   mov     [g_eventQueueIdx], eax
 *   inc     eax
 *   cmp     eax, 0x28
 *   mov     [g_walkCallback], eax
 *   jl      .skip
 *   mov     [g_walkCallback], 0
 *   mov     [g_eventQueueEnd], 1
 *   jmp     T
 */
extern unsigned int g_state_0053a278;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueEnd;
extern void func_00458886(void);
void IncCmp28StoreOrJmp_00458880(void) {
    int v = (int)g_state_0053a278;
    g_eventQueueIdx = (unsigned int)v;
    v++;
    g_walkCallback = (void (*)(void))v;
    if (v >= 0x28) {
        g_walkCallback = 0;
    }
    g_eventQueueEnd = 1;
    func_00458886();
}

/* @addr 0x0045f570 (48b)
 *   call    F
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, [g_eventQueueEnd]
 *   cmp     eax, ecx
 *   mov     eax, [g_xformDirtyFlags]
 *   je      +0x0d
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   mov     eax, 1
 *   ret
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   xor     eax, eax
 *   ret
 */
extern void CmpP1ScaledLoad74_0045f5d0(void);
int CallCmpDirtyTrueOrFalse_0045f570(void) {
    CmpP1ScaledLoad74_0045f5d0();
    if (g_eventQueueCurrent != g_eventQueueEnd) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
        return 1;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
    return 0;
}

/* @addr 0x0045f5a0 (48b): same shape, swapped: jne (75) instead of je (74) */
extern void func_0045f5d0_b(void);
int CallCmpDirtyTrueOrFalse_0045f5a0(void) {
    func_0045f5d0_b();
    if (g_eventQueueCurrent == g_eventQueueEnd) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
        return 1;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
    return 0;
}
