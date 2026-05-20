/**
 * Forty-seventh batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueEnd;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueWorkType;
extern u32 g_pendingNodeType;
extern u32 g_eventQueueNotMask;

/* @addr 0x00473070 (73b)
 *   Push g_eventQueueCurrent on stack[idx*4]; set g_eventQueueCurrent = -1;
 *   call F; pause-test → ret; pop stack value back into g_eventQueueCurrent.
 */
extern void Helper_TickFrame_PostFight(void);
void PushPopCurrentSetFFFFFFFF_00473070(void) {
    unsigned int top;
    top = g_state_004d57ac + 1;
    g_state_004d57ac = top;
    *(unsigned int *)(top * 4) = g_eventQueueCurrent;
    g_eventQueueCurrent = 0xffffffff;
    Helper_TickFrame_PostFight();
    if (g_framePauseFlag != 0) return;
    top = g_state_004d57ac;
    g_eventQueueCurrent = *(unsigned int *)(top * 4);
    g_state_004d57ac = top - 1;
}

/* @addr 0x0047d510 (73b)
 *   Push g_eventQueueNotMask on stack[idx*4]; set g_walkCallback = 0xc;
 *   call F; pause-test → ret; pop stack value back into g_eventQueueNotMask.
 */
extern void func_0048a150(void);
void PushPopNotMaskSetWalk0xc_0047d510(void) {
    unsigned int top;
    top = g_state_004d57ac + 1;
    g_state_004d57ac = top;
    *(unsigned int *)(top * 4) = g_eventQueueNotMask;
    g_walkCallback = (void (*)(void))0x0c;
    func_0048a150();
    if (g_framePauseFlag != 0) return;
    top = g_state_004d57ac;
    g_eventQueueNotMask = *(unsigned int *)(top * 4);
    g_state_004d57ac = top - 1;
}

/* @addr 0x0041aa80 (70b)
 *   set workType = 2; pendingNodeType = 0x4d7b28>>2; call F;
 *   pause → ret; testb 4,[dirty] → ret;
 *   load g_xformEntityIdx; set walk = 0x14ccc and store at [ecx*4 + 0x48]; ret.
 */
extern unsigned int g_data_004d7b28;
extern void func_00419190(void);
void SetWorkTypeScaledCallStoreCcc_0041aa80(void) {
    g_eventQueueWorkType = 2;
    g_pendingNodeType = (unsigned int)&g_data_004d7b28 >> 2;
    func_00419190();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    g_walkCallback = (void (*)(void))0x14ccc;
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x48) = 0x14ccc;
}

/* @addr 0x00445fb0 (70b)
 *   load g_eventQueueIdx; set walk=0xa, store eax → g_fightGroupHead;
 *   call F; pause → ret;
 *   copy g_scaledInit → g_xformEntityIdx; baseSel*4 + 0x5c → g_scaledInit; jmp T.
 */
extern void func_00408c98(void);
extern void func_004084d0(void);
void SetWalk0xaCrossStore_00445fb0(void) {
    g_fightGroupHead = g_eventQueueIdx;
    g_walkCallback = (void (*)(void))0xa;
    func_00408c98();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = g_scaledInit_00542044;
    g_scaledInit_00542044 = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x5c);
    func_004084d0();
}

/* @addr 0x00482e60 (70b)
 *   3 calls + pause-test chain; testb 1,[dirty] → ret;
 *   push 0x4ee2f0; call F4; add esp 4; ret.
 */
extern void CjTableThresholdDispatch_00488f00(void);
extern void func_00484572(void);
extern void func_004ae794(void);
extern int LoadSetFpJmp_00409400(void *);
extern void *g_data_004ee2f0;
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
        push    OFFSET g_data_004ee2f0
        call    LoadSetFpJmp_00409400
        add     esp, 4
        }
}

/* @addr 0x004839d0 (70b)
 *   call F1; pause-test → ret; call F2; pause → ret;
 *   testb 4,[dirty]; jz +0x1b →ret; inc g_state_004d57ac;
 *   push 0x00483a20 onto stack[idx*4]; jmp T.
 */
extern void func_0047f860(void);
extern void func_00484342(void);
extern void InstallSelfOrChainJmp_00483a20(void);
extern void func_0042b988(void);
void CallPauseDirty4StackPushFn_004839d0(void) {
    func_0047f860();
    if (g_framePauseFlag != 0) return;
    func_00484342();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) {
        g_state_004d57ac++;
        *(unsigned int *)(g_state_004d57ac * 4) = (unsigned int)&InstallSelfOrChainJmp_00483a20;
        func_0042b988();
        return;
    }
    InstallSelfOrChainJmp_00483a20();
}

/* @addr 0x00489e90 (70b)
 *   copy g_scaledInit → g_pendingNodeType; load g_state_0052d74c;
 *   if non-neg call F1; pause → ret; load g_state_00538068 → g_xformEntityIdx;
 *   if signed: jmp T1.
 */
extern unsigned int g_state_0052d74c;
extern unsigned int g_state_00538068;
extern void func_00489c60(void);
extern void func_00489c30(void);
void ScaledStateNegCallPauseLoad_00489e90(void) {
    int v;
    g_pendingNodeType = g_scaledInit_00542044;
    v = (int)g_state_0052d74c;
    g_walkCallback = (void (*)(void))v;
    if (v < 0) {
        func_00489c60();
        if (g_framePauseFlag != 0) return;
    }
    v = (int)g_state_00538068;
    g_pendingNodeType = g_xformEntityIdx;
    g_walkCallback = (void (*)(void))v;
    if (v < 0) {
        func_00489c30();
    }
}

/* @addr 0x0048e330 (70b)
 *   load g_fightGroupHead, g_state_00538158; cmp; load g_state_00537f48;
 *   jne skip; load g_state_005380e0 → walk;
 *   load dirty | 4; cmp eax,6; if eq: dirty stays; else: dirty ^= 4;
 *   ret.
 */
extern unsigned int g_state_00538158_ll;
extern unsigned int g_state_00537f48;
extern unsigned int g_state_005380e0;
void LoadCmpStateOrDirtyToggle_0048e330(void) {
    unsigned int v = g_state_00537f48;
    g_walkCallback = (void (*)(void))v;
    if (g_fightGroupHead != g_state_00538158_ll) {
        v = g_state_005380e0;
        g_walkCallback = (void (*)(void))v;
    }
    g_xformDirtyFlags |= 4;
    if (v != 6) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
}

/* @addr 0x004a98f0 (70b)
 *   load g_state_00537f94; cmp 1; if !=, load g_state_00537f48 → walk;
 *   else load walk; cmp 2; jne skip; load g_state_005380e0 → walk;
 *   if walk==7 set byte g_byte_0054372c=dl; if walk==6 set g_byte_00543724=dl.
 */
extern unsigned int g_state_00537f94;
extern unsigned int g_state_00537f48_ll;
extern unsigned int g_state_005380e0_ll;
extern unsigned char g_byte_0054372c;
extern unsigned char g_byte_00543724;
void StateCmpAndStoreByte_004a98f0(void) {
    __asm {
        mov     ecx, dword ptr [g_state_00537f94]
        mov     edx, 1
        cmp     ecx, edx
        _emit   75h
        _emit   0ch
        mov     eax, dword ptr [g_state_00537f48_ll]
        mov     dword ptr [g_walkCallback], eax
        _emit   0ebh
        _emit   05h
        mov     eax, dword ptr [g_walkCallback]
        cmp     ecx, 2
        _emit   75h
        _emit   0ah
        mov     eax, dword ptr [g_state_005380e0_ll]
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 7
        _emit   75h
        _emit   06h
        mov     byte ptr [g_byte_0054372c], dl
        cmp     eax, 6
        _emit   75h
        _emit   06h
        mov     byte ptr [g_byte_00543724], dl
        }
}

/* @addr 0x004ac520 (70b)
 *   if g_state_00543904 != 0:
 *     call F; if ret == 0:
 *       load g_state_005438e8; push 0,2,0x808,it,IAT;
 *     if g_state_00543900 == 0: clear via IAT [g_iat_00...4022240];
 *     g_state_00543900 = ret; clear g_state_00543904.
 */
extern unsigned int g_state_00543904;
extern unsigned int g_state_00543900;
extern unsigned int g_state_005438e8;
extern int func_004ac318(void);
extern void (__stdcall *g_iat_004d2244)(int, int, int, int);
extern int (__stdcall *g_iat_004d2240)(void);
void Helper_TitleEnterStateC(void) {
    if (g_state_00543904 != 0 && func_004ac318() != 0) {
        g_iat_004d2244((int)g_state_005438e8, 0x808, 2, 0);
    }
    if (g_state_00543900 == 0) {
        g_state_00543900 = (unsigned int)g_iat_004d2240();
    }
    g_state_00543904 = 0;
}
