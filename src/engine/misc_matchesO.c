/**
 * Twenty-fourth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0042fc40 (50b)
 *   mov     eax, [g_eventQueueWorkType]
 *   mov     ecx, [g_acc_00542078]
 *   sub     eax, 0x0a3d
 *   cmp     ecx, eax
 *   mov     [g_eventQueueWorkType], eax
 *   jle     +5
 *   jmp     T1
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T2
 *   ret
 */
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern void func_0042fb6c(void);
extern void func_0042fc62(void);
extern void func_0042f87c(void);
__declspec(naked) void SubCmpCallPauseJmp_0042fc40(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueWorkType]
        mov     ecx, dword ptr [g_acc_00542078]
        sub     eax, 0x0a3d
        cmp     ecx, eax
        mov     dword ptr [g_eventQueueWorkType], eax
        _emit   7eh
        _emit   05h
        jmp     func_0042fb6c
        call    func_0042fc62
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0042f87c
        ret
    }
}

/* @addr 0x00431da0 (47b)
 *   mov     eax, [g_eventQueueChild]
 *   add     eax, 0x00011f1f
 *   mov     [g_eventQueueWorkType], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x11
 *   mov     ecx, [g_walkCallback]
 *   mov     [g_eventQueueCurrent], ecx
 *   jmp     T
 *   ret
 */
extern void func_0042440c(void);
extern void func_00432522(void);
void AddStoreCallPauseJmp_00431da0(void) {
    g_eventQueueWorkType = g_eventQueueChild + 0x0001921f;
    func_0042440c();
    if (g_framePauseFlag != 0) return;
    g_eventQueueCurrent = (unsigned int)g_walkCallback;
    func_00432522();
}

/* @addr 0x004362b0 (49b)
 *   call    F
 *   test    eax, eax
 *   jne     +0x27
 *   mov     eax, [g_state_00535ddc]
 *   cmp     eax, 0x00030000
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     T1
 *   cmp     eax, 0x00018000
 *   jge     +5
 *   jmp     +0x15
 *   jmp     T2
 *   ret
 */
extern unsigned int g_state_00535ddc;
extern int func_00436090(void);
extern void func_00430b96(void);
extern void func_00436324(void);
extern void func_004362cf(void);
void Cmp30000And18000_004362b0(void) {
    unsigned int v;
    if (func_00436090() != 0) return;
    v = g_state_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if ((int)v > 0x30000) {
        func_00430b96();
        return;
    }
    if ((int)v < 0x18000) {
        func_004362cf();
        return;
    }
    func_00436324();
}

/* @addr 0x00436ff0 (48b)
 *   mov     [g_walkCallback], 0x14
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_walkCallback]
 *   add     eax, 8
 *   mov     [g_walkCallback], eax
 *   mov     [g_eventQueueChild], eax
 *   jmp     +1
 *   ret
 */
extern void CallPauseInc_004ab670(void);
extern void func_004370f4(void);
void Set14CallAddJmp_00436ff0(void) {
    unsigned int v;
    g_walkCallback = (void (*)(void))0x14;
    CallPauseInc_004ab670();
    if (g_framePauseFlag != 0) return;
    v = (unsigned int)g_walkCallback + 8;
    g_walkCallback = (void (*)(void))v;
    g_eventQueueChild = v;
    func_004370f4();
}

/* @addr 0x004389b0 (48b)
 *   mov     eax, [g_eventQueueChild]
 *   dec     eax
 *   mov     [g_eventQueueChild], eax
 *   jne     +0x22
 *   mov     [g_walkCallback], 0x18
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0a
 *   mov     [g_eventQueueChild], 0x0d
 *   ret
 */
extern void func_004385f4(void);
void DecJneSetCallSetJmp_004389b0(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        _emit   75h
        _emit   22h
        mov     dword ptr [g_walkCallback], 0x18
        call    func_004385f4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ah
        mov     dword ptr [g_eventQueueChild], 0x0d
        }
}

/* @addr 0x00438ea0 (46b)
 *   push    0x004e4890
 *   call    F
 *   add     esp, 4
 *   ret
 *   nop * 2
 *   push    0x004e48d0
 *   call    F
 *   add     esp, 4
 *   ret
 *   nop * 2
 *   push    0x004e4910
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern void *g_data_004e4890;
extern void *g_data_004e48d0;
extern void *g_data_004e4910;
extern int func_004399be(void *);
extern int func_004399be_b(void *);
extern int func_004399be_c(void *);
void TripleStubPushCall_00438ea0(void) {
    __asm {
        push    OFFSET g_data_004e4890
        call    func_004399be
        add     esp, 4
        ret
        nop
        nop
        push    OFFSET g_data_004e48d0
        call    func_004399be_b
        add     esp, 4
        ret
        nop
        nop
        push    OFFSET g_data_004e4910
        call    func_004399be_c
        add     esp, 4
        }
}

/* @addr 0x00460910 (46b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_eventQueueCurrent]
 *   cmp     eax, 0x1010
 *   je      +0x13
 *   cmp     eax, 0x1011
 *   je      +0x0c
 *   cmp     eax, 0x0400
 *   je      +5
 *   jmp     +3
 *   ret
 */
extern void func_0048fc10(void);
extern void func_00460941(void);
void CallPauseTriCmpJmp_00460910(void) {
    unsigned int v;
    func_0048fc10();
    if (g_framePauseFlag != 0) return;
    v = g_eventQueueCurrent;
    if (v == 0x1010) return;
    if (v == 0x1011) return;
    if (v == 0x0400) return;
    func_00460941();
}

/* @addr 0x00461220 (50b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax*4 + 0x24], ecx
 *   mov     edx, [g_fightGroupHead]
 *   mov     [g_eventQueueIdx], edx
 *   jmp     T
 *   ret
 */
extern void StateDispatchTable_00490fc0(void);
extern void func_00406ad0(void);
void CallPauseScaledStoreCopyJmp_00461220(void) {
    StateDispatchTable_00490fc0();
    if (g_framePauseFlag != 0) return;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x24) = (unsigned int)g_walkCallback;
    g_scaledInit_00542044 = g_fightGroupHead;
    func_00406ad0();
}

/* @addr 0x00464800 (47b)
 *   mov     eax, 0x0050b10c
 *   shr     eax, 2
 *   mov     [g_scaledInit_00542044], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     ecx, 0x0051131c     ; was 0x00511310 + 0xc?
 *   shr     ecx, 2
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     T
 *   ret
 */
extern void func_004bd5a4(void);
extern void func_004bd584(void);
extern int g_data_0050b10c;
extern int g_data_00511310;
void DualScaledLitInitJmp_00464800(void) {
    g_scaledInit_00542044 = ((unsigned int)&g_data_0050b10c) >> 2;
    func_004bd5a4();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = ((unsigned int)&g_data_00511310) >> 2;
    func_004bd584();
}

/* @addr 0x00470310 (46b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x18]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0x34]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      +0x0c
 *   neg     eax
 *   mov     [g_walkCallback], eax
 *   jmp     +3
 *   ret
 */
extern void func_00470342(void);
void ScaledChainNegStore_00470310(void) {
    unsigned int s;
    unsigned int v;
    s = *(unsigned int *)(g_fightGroupHead * 4 + 0x18);
    g_scaledInit_00542044 = s;
    v = *(unsigned int *)(s * 4 + 0x34);
    g_walkCallback = (void (*)(void))v;
    if (v == 0) return;
    v = (unsigned int)-(int)v;
    g_walkCallback = (void (*)(void))v;
    func_00470342();
}

/* @addr 0x00470500 (48b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret2
 *   call    F3
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void func_00488282(void);
extern void func_00490e82(void);
extern void func_00490c14(void);
extern void func_00470309(void);
void TripleCallPauseJmp_00470500(void) {
    func_00488282();
    if (g_framePauseFlag != 0) return;
    func_00490e82();
    if (g_framePauseFlag != 0) return;
    func_00490c14();
    if (g_framePauseFlag != 0) return;
    func_00470309();
}

/* @addr 0x00480ef0 (47b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   je      +0x17
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, 7
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x28], eax
 *   ret
 */
extern void func_004b85e0(void);
void CallPauseDirtyScaledSet7_00480ef0(void) {
    func_004b85e0();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) == 0) return;
    g_walkCallback = (void (*)(void))7;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 7;
}
