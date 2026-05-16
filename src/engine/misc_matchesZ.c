/**
 * Thirty-fifth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;

/* @addr 0x00474b10 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x474b50 */
extern void NetEntityScanAndPunish_00474b50(void);
void ScaledInitOrSelfPtr_00474b10(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int ptr = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (ptr) {
        NetEntityScanAndPunish_00474b50();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_00474b10;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00489130 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x41f780 */
extern void func_0041f780_z(void);
void ScaledInitOrSelfPtr_00489130(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int ptr = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (ptr) {
        func_0041f780_z();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_00489130;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00474050 (63b): DoubleStackPushAndJmp variant, value=0x7d */
extern void func_004740d0_z(void);
void DoubleStackPushAndJmp7d_00474050(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_scaledInit_00542044;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_fightGroupHead;
    g_scaledInit_00542044 = 0x7d;
    func_004740d0_z();
}

/* @addr 0x00474090 (63b): DoubleStackPushAndJmp variant, value=0x7b */
extern void func_004740d0_zz(void);
void DoubleStackPushAndJmp7b_00474090(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_scaledInit_00542044;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_fightGroupHead;
    g_scaledInit_00542044 = 0x7b;
    func_004740d0_zz();
}

/* @addr 0x00475750 (62b)
 *   load g_eventQueueIdx, g_eventQueueEnd; cross-copy [+0x54] then [+0x5c].
 */
void DoubleScaledCrossStore_00475750(void) {
    unsigned int v;
    v = *(unsigned int *)(g_eventQueueIdx * 4 + 0x54);
    g_walkCallback = (void(*)(void))v;
    *(unsigned int *)(g_eventQueueEnd * 4 + 0x54) = v;
    v = *(unsigned int *)(g_eventQueueIdx * 4 + 0x5c);
    g_walkCallback = (void(*)(void))v;
    *(unsigned int *)(g_eventQueueEnd * 4 + 0x5c) = v;
}

/* @addr 0x00482740 (62b)
 *   3-level scaled chain (0x3c, 0x30, 0); cmp 0x61 → jmp T1; cmp 0x69 → jmp T2.
 */
extern void StageGameProgressCluster_00482780(void);
extern void Wrapper_0048a360(void);
void ScaledChainCmp61_00482740(void) {
    unsigned int v;
    v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x3c);
    g_scaledInit_00542044 = v;
    v = *(unsigned int *)(v * 4 + 0x30);
    g_scaledInit_00542044 = v;
    v = *(unsigned int *)(v * 4);
    g_walkCallback = (void (*)(void))v;
    if (v == 0x61) {
        StageGameProgressCluster_00482780();
        return;
    }
    if (v == 0x69) {
        return;
    }
    Wrapper_0048a360();
}

/* @addr 0x0048e2f0 (60b)
 *   push lit; call F; pause-test → ret;
 *   load g_baseSel; copy [eax*4+0x7c]→g_walkCallback, [eax*4+0x80]→g_currentNodeFlags;
 *   jmp [g_scaledInit_00542044]; ret.
 */
extern void *g_data_004f1290;
extern int ArgScaledLoadCmpP1_0048e550(void *);
__declspec(naked) void PushCallPauseScaledJmpInd_0048e2f0(void) {
    __asm {
        push    OFFSET g_data_004f1290
        call    ArgScaledLoadCmpP1_0048e550
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   25h
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x7c]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0x80]
        mov     dword ptr [g_currentNodeFlags], edx
        jmp     dword ptr [g_scaledInit_00542044]
        ret
    }
}

/* @addr 0x0048e740 (62b)
 *   scaled chain 0x3c → 0x74; and 0xf000; cmp 0x4000;
 *   if eq: or al,1 → store dirty;  else and al,0xfe → store dirty.
 */
void ScaledChainAndF000DirtyToggle_0048e740(void) {
    unsigned int v;
    v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x3c);
    g_scaledInit_00542044 = v;
    v = *(unsigned int *)(v * 4 + 0x74) & 0xf000;
    g_walkCallback = (void(*)(void))v;
    if (v == 0x4000) {
        g_xformDirtyFlags = g_xformDirtyFlags | 1;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}

/* @addr 0x00490290 (55b)
 *   load g_fightGroupHead, g_eventQueueNotMask; or eax with [ecx*4+0x40];
 *   store both eventQueueCurrent and back to [ecx*4+0x40];
 *   load g_state_004d57ac; pop top into eventQueueNotMask; dec ; store.
 */
void OrStoreDecStackPop_00490290(void) {
    unsigned int v = g_eventQueueNotMask | *(unsigned int *)(g_fightGroupHead * 4 + 0x40);
    g_eventQueueCurrent = v;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x40) = v;
    g_eventQueueNotMask = *(unsigned int *)(g_state_004d57ac * 4);
    g_state_004d57ac--;
}

/* @addr 0x0048ac70 (65b)
 *   init g_fightGroupHead from g_state_0052ab10, set g_eventQueueChild = 0x48acb0
 *   (callback ptr to inline ret stub at end), set g_eventQueueTotal = head+0x15;
 *   call F1; pause → ret;
 *   call F2; pause → ret; jmp T;
 *   ret; nop nop; ret  (the inline 0x48acb0 stub fits in the tail)
 */
extern unsigned int g_state_0052ab10;
extern void func_0048acb0(void);
extern void IndirectDispatchCjStore_0048ae50(void);
extern void LazyAllocOrPush_0048abe0(void);
extern void func_0041f780_zz(void);
/* This is a packed-helpers block: the main entry runs at 0x48ac70, but
 * the unreachable trailing `ret; nop; nop; ret` at 0x48acb0 is the body
 * of the inline `func_0048acb0` callback referenced by g_eventQueueChild.
 * Converting the main to pure C would drop the trailing entry; kept as
 * naked to preserve both. */
__declspec(naked) void InitStateDualCall48ac70_0048ac70(void) {
    __asm {
        mov     eax, dword ptr [g_state_0052ab10]
        mov     dword ptr [g_eventQueueChild], OFFSET func_0048acb0
        mov     dword ptr [g_fightGroupHead], eax
        add     eax, 0x15
        mov     dword ptr [g_eventQueueTotal], eax
        call    IndirectDispatchCjStore_0048ae50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    LazyAllocOrPush_0048abe0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0041f780_zz
        ret
        nop
        nop
        ret
    }
}
