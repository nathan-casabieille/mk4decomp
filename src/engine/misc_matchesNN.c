/**
 * Forty-ninth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_pendingNodeType;

/* @addr 0x00428560 (85b)
 *   inc fightGroupHead[+0x28]; load fightGroupHead[+0x24] → scaled;
 *   or dirty |= 4; cmp [scaled+4], walk; if !=, dirty ^= 4 (clear).
 */
void ScaledStoreOrFlagXor_00428560(void) {
    unsigned int v;
    unsigned int s;
    v = *(unsigned int *)(g_fightGroupHead * 4 + 0x28) + 1;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = v;
    s = *(unsigned int *)(g_fightGroupHead * 4 + 0x24);
    g_scaledInit_00542044 = s;
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    if (*(unsigned int *)(s * 4 + 4) != (unsigned int)g_walkCallback) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
}

/* @addr 0x00436250 (85b)
 *   load g_state_00535ddc; if <= 0x30000 jmp T1 else jmp T2;
 *   nop * 5; call F; if zero: inc g_state_004d57ac; set walk=2;
 *     push 0x004335f0 onto stack[idx*4]; jmp T3;
 *   else: ret; nop; jmp T4.
 */
extern unsigned int g_state_00535ddc_nn;
extern void func_00433b60(void);
extern void func_00438f30(void);
extern int func_00439890(void);
extern void HitReactionStateCluster_004335f0(void);
extern void func_00471200(void);
extern void func_00436290(void);
/* @addr 0x00436250 (27b): if state_ddc > 0x30000 tail-jmp func_00433b60,
 * else tail-jmp func_00438f30. Entry A of the original 85-byte packed
 * block; entries B (call + mstack-push) and C (single tail-jmp) live in
 * func_00436270 / func_004362a0. The 5-byte nop gap is filled by 0x90-fill. */
void CmpRangeJmpStateInit_00436250(void) {
    int v = (int)g_state_00535ddc_nn;
    g_walkCallback = (void (*)(void))v;
    if (v > 0x30000) {
        func_00433b60();
        return;
    }
    func_00438f30();
}

/* @addr 0x00436270 (47b): call func_00439890; if non-zero ret;
 * else mstack-push HitReactionStateCluster_004335f0, set walkCallback=2,
 * tail-jmp func_00471200. Orphan sub-entry. */
void func_00436270(void) {
    if (func_00439890() != 0) return;
    g_walkCallback = (void (*)(void))2;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) =
        (unsigned int)&HitReactionStateCluster_004335f0;
    func_00471200();
}

/* @addr 0x004362a0 (5b): orphan tail-jmp into func_00436290. */
void func_004362a0(void) {
    func_00436290();
}

/* @addr 0x004460c0 (85b)
 *   clear walk and scaled[+0x1c]; load scaled[+0x0c]; if non-zero,
 *   set walk = 0x004460c0; call F; pause → ret;
 *   clear dirty bit 1; ret.
 */
extern void func_004bae90_nn(void);
void ScaledClear1cTestWalkCall_004460c0(void) {
    unsigned int cb;
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x1c) = 0;
    cb = *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x0c);
    g_walkCallback = (void (*)(void))cb;
    if (cb != 0) {
        g_walkCallback = (void (*)(void))ScaledClear1cTestWalkCall_004460c0;
        func_004bae90_nn();
        if (g_framePauseFlag != 0) {
            return;
        }
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffeu;
}

/* @addr 0x00446bf0 (85b)
 *   push g_eventQueueCurrent, push 0x6666; call F; add esp 8; store eax → eventQueueCurrent;
 *   set walk = 0xf5c; call F2; pause → ret;
 *   load walk, current; walk += 0x10000; push current, push walk; store walk;
 *   call F3; add esp 8; store eax → eventQueueCurrent.
 */
extern u32 g_eventQueueCurrent;
extern int func_00404ae0(int, int);
extern int func_00404ad0(int, int);
extern void func_004ab730(void);
void PushImmCallSetCallAdjustCall_00446bf0(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    eax
        push    0x6666
        call    func_00404ae0
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], 0xf5c
        call    func_004ab730
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   24h
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    func_00404ad0
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        }
}

/* @addr 0x004a1940 (85b)
 *   ScaledInitOrSelfPtrSetType variant with extra side-effect:
 *     also clears [fightGroupHead*4 + 0x6c] before recursing.
 */
extern void func_0041f780_nn(void);
void ScaledInitOrSelfPtrSetType14_004a1940(void) {
    unsigned int *base = (unsigned int *)(g_baseSel_00542060 * 4);
    unsigned int prev = base[0x84 / 4];
    base[0x84 / 4] = 0;
    if (prev != 0) {
        func_0041f780_nn();
        return;
    }
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x6c) = 0;
    base[8 / 4] = 0x004a1940;
    base[0x84 / 4] = 1;
    g_pendingNodeType = 0x14;
    g_framePauseFlag = 1;
}

/* @addr 0x004ba6c0 (85b)
 *   testb 0x10,[dirty]; if set: load g_pendingNodeType; lea ecx=[eax*4 + 0];
 *   load *ecx; copy 4 dwords from there into globals 0x7af990..0x7af9a0;
 *   load dirty; load word ecx[+0x10]; mask 0xef; store; ret 0.
 */
extern unsigned int g_state_007af990;
extern unsigned int g_state_007af994;
extern unsigned int g_state_007af998;
extern unsigned int g_state_007af99c;
extern unsigned short g_word_007af9a0;
void DirtyTestScaledCopy_004ba6c0(void) {
    __asm {
        test    byte ptr [g_xformDirtyFlags], 0x10
        _emit   74h
        _emit   49h
        mov     eax, dword ptr [g_pendingNodeType]
        lea     ecx, [eax*4 + 0]
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_state_007af990], edx
        mov     eax, dword ptr [ecx + 4]
        mov     dword ptr [g_state_007af994], eax
        mov     edx, dword ptr [ecx + 8]
        mov     dword ptr [g_state_007af998], edx
        mov     eax, dword ptr [ecx + 0x0c]
        mov     dword ptr [g_state_007af99c], eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     cx,  word  ptr [ecx + 0x10]
        and     al,  0xef
        mov     word  ptr [g_word_007af9a0], cx
        mov     dword ptr [g_xformDirtyFlags], eax
        xor     eax, eax
        }
}
