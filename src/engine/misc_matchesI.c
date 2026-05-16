/**
 * Eighteenth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00446380 (42b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     +0x12
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     [eax*4 + 0x4c], ecx
 *   ret
 */
extern void BootPhaseGateBracketedInit_004060c0(void);
void CallPauseDirtyScaledStore_00446380(void) {
    BootPhaseGateBracketedInit_004060c0();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x4c) = g_scaledInit_00542044;
}

/* @addr 0x00453750 (38b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0x24]
 *   mov     [g_xformEntityIdx], ecx
 *   jmp     T
 *   ret
 */
extern void DirtyDoubleDeref_00408cb0(void);
extern void func_00407310(void);
void CallPauseScaledStoreXJmp_00453750(void) {
    DirtyDoubleDeref_00408cb0();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x24);
    func_00407310();
}

/* @addr 0x0045f440 (38b)
 *   mov     eax, [g_X]
 *   mov     ecx, [g_Y]
 *   not     eax
 *   not     ecx
 *   and     eax, 0xffff
 *   and     ecx, 0xffff
 *   mov     [g_walkCallback], eax
 *   mov     [g_eventQueueCurrent], ecx
 *   ret
 */
extern unsigned int g_state_004d50a4;
extern unsigned int g_state_004d50a8;
void NotMaskStorePair_0045f440(void) {
    unsigned int a = ~g_state_004d50a4 & 0xffff;
    unsigned int b = ~g_state_004d50a8 & 0xffff;
    g_walkCallback      = (void(*)(void))a;
    g_eventQueueCurrent = b;
}

/* @addr 0x0046ea70 (39b)
 *   cmp     [g_xformScratch2088], 1
 *   jne     +0x1d
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x70]
 *   cmp     eax, 0x20e
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern u32 g_xformScratch2088;
extern void func_0047d960(void);
void DirtyTestScaledCmpJmp_0046ea70(void) {
    unsigned int v;
    if (g_xformScratch2088 != 1) return;
    v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x70);
    g_walkCallback = (void (*)(void))v;
    if (v != 0x20e) return;
    func_0047d960();
}

/* @addr 0x004708a0 (31b)
 *   mov     eax, [g_xformEntityIdx]
 *   mov     [eax*4 + 0x5c], 0xc
 *   mov     [g_walkCallback], 0x58
 *   jmp     T
 */
extern void func_0048a000(void);
void ScaledStoreCSet58Jmp_004708a0(void) {
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x5c) = 0x0c;
    g_walkCallback = (void (*)(void))0x58;
    func_0048a000();
}

/* @addr 0x00470f60 (35b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x40]
 *   mov     [g_walkCallback], eax
 *   and     eax, 0x200
 *   mov     [g_xformScratch94], eax
 *   je      .skip
 *   jmp     T
 * .skip:
 *   ret
 */
extern unsigned int g_xformScratch94;
extern void func_00490374(void);
void ScaledAndCheckJmp_00470f60(void) {
    unsigned int v = *(unsigned int *)(g_fightGroupHead * 4 + 0x40);
    unsigned int masked;
    g_walkCallback = (void (*)(void))v;
    masked = v & 0x200;
    g_xformScratch94 = masked;
    if (masked == 0) return;
    func_00490374();
}

/* @addr 0x00472860 (36b)
 *   mov     [g_walkCallback], 2
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .skip
 *   inc     dword ptr [g_walkCallback]
 *   jmp     T
 * .skip:
 *   ret
 */
extern void func_004ab620(void);
extern void func_00489f7e(void);
__declspec(naked) void Set2CallIncJmp_00472860(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 2
        call    func_004ab620
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0bh
        inc     dword ptr [g_walkCallback]
        jmp     func_00489f7e
        ret
    }
}

/* @addr 0x00472890 (37b)
 *   mov     [g_walkCallback], 4
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .skip
 *   add     dword ptr [g_walkCallback], 0x42
 *   jmp     T
 * .skip:
 *   ret
 */
extern void func_004ab620_b(void);
extern void func_00489f7e_b(void);
__declspec(naked) void Set4CallAddJmp_00472890(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 4
        call    func_004ab620_b
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ch
        add     dword ptr [g_walkCallback], 0x42
        jmp     func_00489f7e_b
        ret
    }
}

/* @addr 0x00473450 (44b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x18]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     +4
 */
extern void func_00473461(void);
__declspec(naked) void ScaledLoadDirtyOrSetJmp_00473450(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [eax*4 + 0x18]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     func_00473461
    }
}

/* @addr 0x00475790 (36b)
 *   mov     eax, [g_eventQueueIdx]
 *   mov     ecx, [eax*4 + 0x3c]
 *   mov     [g_walkCallback], ecx
 *   mov     edx, [eax*4 + 0x44]
 *   mov     [g_eventQueueCurrent], edx
 *   jmp     +0x0c
 */
extern void func_004757a4(void);
void DualScaledLoadStoreJmp_00475790(void) {
    unsigned int idx = g_eventQueueIdx;
    g_walkCallback = (void (*)(void))*(unsigned int *)(idx * 4 + 0x3c);
    g_eventQueueCurrent = *(unsigned int *)(idx * 4 + 0x44);
    func_004757a4();
}

/* @addr 0x00476e00 (32b)
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     eax, [ecx*4 + 0x20]
 *   or      al, 4
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x20], eax
 *   jmp     T
 */
extern void func_00476e1d(void);
__declspec(naked) void ScaledOr4Jmp_00476e00(void) {
    __asm {
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [ecx*4 + 0x20]
        or      al, 4
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        jmp     func_00476e1d
    }
}

/* @addr 0x00476fe0 (32b): same shape, and al, 0xfb */
extern void func_00476ffd(void);
__declspec(naked) void ScaledAndFBJmp_00476fe0(void) {
    __asm {
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [ecx*4 + 0x20]
        and     al, 0xfb
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        jmp     func_00476ffd
    }
}

/* @addr 0x004809b0 (40b)
 *   mov     [g_walkCallback], 0x1d
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], 0x16
 *   jmp     T
 *   ret
 */
extern void func_00489fe6(void);
extern void func_0048d46e(void);
void Set1dCallSet16Jmp_004809b0(void) {
    g_walkCallback = (void (*)(void))0x1d;
    func_00489fe6();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x16;
    func_0048d46e();
}

/* @addr 0x00480d20 (44b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x38]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0x54]
 *   mov     [g_walkCallback], ecx
 *   mov     edx, [eax*4 + 0x5c]
 *   mov     [g_eventQueueCurrent], edx
 *   ret
 */
void ScaledChainTwoStores_00480d20(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x38);
    g_scaledInit_00542044 = v;
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x54);
    g_eventQueueCurrent = *(unsigned int *)(v * 4 + 0x5c);
}

/* @addr 0x004838d0 (44b)
 *   mov     [g_walkCallback], 0x1f4
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      +5
 *   jmp     T1
 *   jmp     +5
 *   ret
 */
extern void AudioVolumeRescale_004ab690(void);
extern void func_004874f0(void);
extern void func_00483906(void);
__declspec(naked) void Set1f4CallDirtyJmp_004838d0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x01f4
        call    AudioVolumeRescale_004ab690
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_004874f0
        jmp     func_00483906
        ret
    }
}

/* @addr 0x00483b50 (36b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, [ecx*4 + 0x7c]
 *   dec     eax
 *   mov     [g_walkCallback], eax
 *   jns     +7
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x7c], eax
 *   ret
 */
__declspec(naked) void ScaledDecOrZero_00483b50(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 0x7c]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        _emit   79h
        _emit   07h
        xor     eax, eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x7c], eax
        ret
    }
}

/* @addr 0x00487180 (41b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x30]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      +0x0e
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void func_004ab608(void);
extern void func_004871b1(void);
__declspec(naked) void ScaledTestCallPauseJmp_00487180(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x30]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   0eh
        call    func_004ab608
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004871b1
        ret
    }
}

/* @addr 0x004887d0 (42b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   push    0x004ef080
 *   call    F3
 *   add     esp, 4
 *   ret
 */
extern void func_00489520(void);
extern void Wrapper_0048a280(void);
extern int func_004594d0(void *p);
extern void *g_data_004ef080;
__declspec(naked) void TwoCallsPushCall_004887d0(void) {
    __asm {
        call    func_00489520
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        call    Wrapper_0048a280
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    OFFSET g_data_004ef080
        call    func_004594d0
        add     esp, 4
        ret
    }
}
