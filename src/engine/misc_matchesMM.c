/**
 * Forty-eighth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern u32 g_eventQueueEnd;
extern u32 g_eventQueueIdx;
extern u32 g_pendingNodeType;

/* @addr 0x0041fd10 (91b)
 *   call F0; set g_state_0053a1f0=2; call F1; pause → ret;
 *   call F2; pause → ret; call F3; pause → ret; call F4; pause → ret;
 *   call F5; pause → ret; jmp T.
 */
extern unsigned int g_state_0053a1f0;
extern void Wrapper_0041fd00(void);
extern void func_0041f260(void);
extern void func_004135b0(void);
extern void func_00481fc0(void);
extern void func_00422280(void);
extern void func_0040517a(void);
extern void func_004012f0(void);
void Set2FiveCallPauseJmp_0041fd10(void) {
    Wrapper_0041fd00();
    g_state_0053a1f0 = 2;
    func_0041f260();
    if (g_framePauseFlag) return;
    func_004135b0();
    if (g_framePauseFlag) return;
    func_00481fc0();
    if (g_framePauseFlag) return;
    func_00422280();
    if (g_framePauseFlag) return;
    func_0040517a();
    if (g_framePauseFlag) return;
    func_004012f0();
}

/* @addr 0x00438b90 (91b)
 *   push g_currentNodeFlags onto stack[idx*4]; 3-call pause chain;
 *   pop stack value back into g_currentNodeFlags.
 */
extern u32 g_currentNodeFlags;
extern void func_0049072e(void);
extern void func_00490c0a(void);
extern void func_0046121e(void);
__declspec(naked) void PushPop84TripleCall_00438b90(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_currentNodeFlags]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    func_0049072e
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   34h
        call    func_00490c0a
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   26h
        call    func_0046121e
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_currentNodeFlags], edx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x004be630 (91b)
 *   6× push 0, push imm; call F; add esp 8; ret. Pattern of 6 unique 2-arg calls.
 */
extern void func_00513ac8(int, int);
void SixDoublePushCall_004be630(void) {
    func_00513ac8(0x138, 0);
    func_00513ac8(0x333, 0);
    func_00513ac8(0x3ec, 0);
    func_00513ac8(0x3f0, 0);
    func_00513ac8(0x3f7, 0);
    func_00513ac8(0x420, 0);
}

/* @addr 0x004923f0 (91b)
 *   inc g_state_004d57ac; push g_eventQueueCurrent; load walk;
 *   dec walk; if walk<0 jmp shift-amount path; else fall through.
 *   Computes shifted-mod via [g_state_0053a470 + ecx*4] table.
 */
extern unsigned int g_eventQueueCurrent_mm;
extern unsigned int g_state_0053a470;
__declspec(naked) void PushPopWalkDecMod_004923f0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_eventQueueCurrent_mm]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_walkCallback]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        _emit   78h
        _emit   1dh
        mov     edx, eax
        mov     eax, dword ptr [g_state_0053a470]
        lea     ecx, [edx*4 + 0]
        shr     eax, cl
        and     eax, 0x0f
        mov     dword ptr [g_eventQueueCurrent_mm], eax
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_eventQueueCurrent_mm], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
    }
}

/* @addr 0x0048c210 (73b)
 *   mov eax = 0x00541d70 >> 2 → g_scaledInit; clear walk;
 *   set g_state_0053a1ac=3; load walk → ecx; store at [eax*4 + 0];
 *   load g_scaledInit, g_state_0053a1ac; inc both, store back; if not zero loop back.
 */
extern unsigned int g_data_00541d70;
extern unsigned int g_state_0053a1ac;
__declspec(naked) void ScaledIncLoopState3_0048c210(void) {
    __asm {
        mov     eax, OFFSET g_data_00541d70
        mov     dword ptr [g_walkCallback], 0
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_state_0053a1ac], 3
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_state_0053a1ac]
        inc     eax
        dec     ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_state_0053a1ac], ecx
        _emit   79h
        _emit   0d9h
        ret
    }
}

/* @addr 0x004ab2a0 (89b)
 *   push esi; load g_eventQueueCurrent → esi; if !esi: store esi → walk, ret;
 *   load walk; if in range [-0x8000, 0x8000): walk = (walk<<16)/esi via idiv;
 *   else: 64-bit shift via __aullshl + 64-bit signed mod via 0x004c5690.
 */
extern unsigned int g_eventQueueCurrent_mm2;
extern void func_004c5740_mm(void);
extern int Alldiv_004c5690(int, int, int, int);
__declspec(naked) void RangeMulMod_004ab2a0(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [g_eventQueueCurrent_mm2]
        test    esi, esi
        push    edi
        _emit   75h
        _emit   09h
        mov     dword ptr [g_walkCallback], esi
        pop     edi
        pop     esi
        ret
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0xffff8000
        _emit   7ch
        _emit   15h
        cmp     eax, 0x00008000
        _emit   7dh
        _emit   0eh
        shl     eax, 0x10
        cdq
        idiv    esi
        mov     dword ptr [g_walkCallback], eax
        pop     edi
        pop     esi
        ret
        cdq
        mov     ecx, 0x10
        call    func_004c5740_mm
        mov     ecx, eax
        mov     eax, esi
        mov     edi, edx
        cdq
        push    edx
        push    eax
        push    edi
        push    ecx
        call    Alldiv_004c5690
        pop     edi
        mov     dword ptr [g_walkCallback], eax
        pop     esi
        ret
    }
}

/* @addr 0x0049d8e0 (89b)
 *   load g_baseSel and g_fightGroupHead, scaled by 4;
 *   six cross-stores: [edx + N] from [eax + M] for (M,N) pairs at +0x38..+0x4c → +0x54..+0x74.
 */
void SixCrossStores_0049d8e0(void) {
    unsigned char *src = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned char *dst = (unsigned char *)(g_fightGroupHead * 4);
    unsigned int v;
    v = *(unsigned int *)(src + 0x38); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x54) = v;
    v = *(unsigned int *)(src + 0x3c); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x58) = v;
    v = *(unsigned int *)(src + 0x40); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x5c) = v;
    v = *(unsigned int *)(src + 0x44); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x6c) = v;
    v = *(unsigned int *)(src + 0x48); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x70) = v;
    v = *(unsigned int *)(src + 0x4c); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x74) = v;
}
