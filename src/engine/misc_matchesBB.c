/**
 * Thirty-seventh batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueEnd;
extern packed_ptr g_fightGroupHead;

/* @addr 0x004ac040 (54b): triple cross-store at offsets 0x54/0x58/0x5c */
__declspec(naked) void ScaledTripleCopy54_004ac040(void) {
    __asm {
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     eax, dword ptr [g_fightGroupHead]
        shl     ecx, 2
        shl     eax, 2
        mov     edx, dword ptr [ecx + 0x54]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x54], edx
        mov     edx, dword ptr [ecx + 0x58]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x58], edx
        mov     ecx, dword ptr [ecx + 0x5c]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x5c], ecx
        ret
    }
}

/* @addr 0x004a12e0 (63b)
 *   push 0x22f; call F1; add esp; call F2; pause → ret;
 *   push 0x15; push lit; call F3; mov ax,[m16]; add esp 8; push eax;
 *   call F4; add esp 4; jmp T; ret.
 */
extern void TripleStageRollback_00404a50(int);
extern void RoundWinTransition_0049e7e0(void);
extern int func_0049cb40_bb(void *, int);
extern int TaggedSceneDispatch_004be690(int);
extern void *g_data_004a0060;
extern unsigned short g_word_004e2860;
extern void InstallSelf3WaySubDec_004a1320(void);
__declspec(naked) void PushCallPauseStorePushDispatch_004a12e0(void) {
    __asm {
        push    0x22f
        call    TripleStageRollback_00404a50
        add     esp, 4
        call    RoundWinTransition_0049e7e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   23h
        push    0x15
        push    OFFSET g_data_004a0060
        call    func_0049cb40_bb
        mov     ax, word ptr [g_word_004e2860]
        add     esp, 8
        push    eax
        call    TaggedSceneDispatch_004be690
        add     esp, 4
        jmp     InstallSelf3WaySubDec_004a1320
        ret
    }
}

/* @addr 0x004a1790 (54b)
 *   load fightGroupHead; set g_eventQueueWorkType=0x01020000;
 *   set [eax*4 + 0x30]=0x25b; reload fightGroupHead → ecx;
 *   mov eax,0xfffb0000; store walk and [ecx*4 + 0x6c]=eax; jmp T.
 */
extern u32 g_eventQueueWorkType;
extern void AudioInstall3StateSubXform_004a17d0(void);
void SetWorkType02CountFFB_004a1790(void) {
    g_eventQueueWorkType = 0x01020000;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x30) = 0x25b;
    g_walkCallback = (void(*)(void))0xfffb0000;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x6c) = 0xfffb0000;
    AudioInstall3StateSubXform_004a17d0();
}

/* @addr 0x004a1a10 (55b)
 *   push 0x25a; call F; load dirty al; add esp; test al,4;
 *   jz +5 → jmp T1; load g_scaledInit → ecx; mov eax,0xfffb0000;
 *   store walk and [ecx*4 + 0x6c]; jmp T2.
 */
extern void func_00404a00_bb(int);
extern void func_0041f780_bb(void);
extern void InstallSelfPauseGate_004a1a50(void);
void PushCallTestByte4Jmp_004a1a10(void) {
    func_00404a00_bb(0x25a);
    if ((g_xformDirtyFlags & 4) != 0) {
        func_0041f780_bb();
        return;
    }
    g_walkCallback = (void (*)(void))0xfffb0000;
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x6c) = 0xfffb0000;
    InstallSelfPauseGate_004a1a50();
}

/* @addr 0x004a1d50 (48b)
 *   8-iteration loop reading triplets from [0x004f2fd4 - 4 ..],
 *   writing AND-NOT result into [src1] and replacing [src2] with NOT(src1).
 */
extern unsigned int g_table_004f2fd4[];
__declspec(naked) void Helper_TickFrame_Misc(void) {
    __asm {
        push    ebx
        push    esi
        push    edi
        mov     ecx, OFFSET g_table_004f2fd4
        mov     esi, 8
loop_start:
        mov     eax, dword ptr [ecx - 4]
        mov     edx, dword ptr [ecx + 4]
        add     ecx, 0x0c
        mov     eax, dword ptr [eax]
        mov     edi, dword ptr [edx]
        not     eax
        not     edi
        mov     ebx, eax
        and     ebx, edi
        mov     edi, dword ptr [ecx - 0x0c]
        dec     esi
        mov     dword ptr [edi], ebx
        mov     dword ptr [edx], eax
        _emit   75h
        _emit   0e1h
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}

/* @addr 0x004a30f0 (48b)
 *   table-walk: esi iterates over 0x004f3260..0x004f33c8 step 0x24;
 *   reads sbyte → adds to g_baseSel_00542060 to form ecx;
 *   stores [ecx*4 + 0] into g_scaledInit; calls 0x406790; loop.
 */
extern signed char g_table_004f3260[];
extern void MStackPush2ChainLLInsert_00406790(void);
__declspec(naked) void TableWalkChainCall_004a30f0(void) {
    __asm {
        push    esi
        mov     esi, OFFSET g_table_004f3260
loop_start2:
        movsx   eax, byte ptr [esi]
        mov     ecx, dword ptr [g_baseSel_00542060]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4 + 0]
        mov     dword ptr [g_scaledInit_00542044], edx
        call    MStackPush2ChainLLInsert_00406790
        add     esi, 0x24
        cmp     esi, 0x004f33c8
        _emit   72h
        _emit   0d8h
        pop     esi
        ret
    }
}

/* @addr 0x004ab630 (53b)
 *   load g_walkCallback; store to g_state_00538150;
 *   call F; pause-test → ret;
 *   load walk; and 0xffff; imul g_state_00538150; shr 16; store walk.
 */
extern unsigned int g_state_00538150;
extern void DualAddSar_004ab600(void);
void StorePauseImulShr16_004ab630(void) {
    g_state_00538150 = (unsigned int)g_walkCallback;
    DualAddSar_004ab600();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_walkCallback = (void (*)(void))((((unsigned int)g_walkCallback & 0xffff) * g_state_00538150) >> 16);
}

/* @addr 0x004ab750 (62b)
 *   load walk; store g_state_00538130; double eax; if neg → neg eax;
 *   store walk; call F; pause-test → ret;
 *   load g_state_00538130 - walk → walk.
 */
extern unsigned int g_state_00538130;
extern void AudioMixerStep_004ab700(void);
__declspec(naked) void StoreDoubleNegPauseSubStore_004ab750(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_state_00538130], eax
        add     eax, eax
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   7dh
        _emit   07h
        neg     eax
        mov     dword ptr [g_walkCallback], eax
        call    AudioMixerStep_004ab700
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        mov     eax, dword ptr [g_state_00538130]
        mov     ecx, dword ptr [g_walkCallback]
        sub     ecx, eax
        mov     dword ptr [g_walkCallback], ecx
        ret
    }
}

/* @addr 0x004ae950 (57b)
 *   if g_state_0058c7e0 != 0 && g_state_0058c7ec == 0:
 *     call F; if g_state_0058c7b4 != 0 && g_state_0058c7b0 != 0:
 *       call [edx + 0x2c](eax, ecx, 1); store result.
 */
extern unsigned int g_state_0058c7e0;
extern unsigned int g_state_0058c7ec;
extern unsigned int g_state_0058c7b4;
extern unsigned int g_state_0058c7b0;
extern unsigned int g_state_0058c7dc;
extern void Renderer2_EndScene_D3D(void);
void Renderer2_PresentFrame(void) {
    unsigned int cb;
    void *p;
    if (!g_state_0058c7e0) return;
    if (g_state_0058c7ec) return;
    Renderer2_EndScene_D3D();
    cb = g_state_0058c7b4;
    if (!cb) return;
    p = (void *)g_state_0058c7b0;
    if (!p) return;
    g_state_0058c7dc = ((unsigned int (__stdcall **)(void*, unsigned int, int))(*(void**)p))[11](p, cb, 1);
}

/* @addr 0x004af650 (56b)
 *   if g_state_0058c7d4 != 0:
 *     load [eax]; call vtable[+8](eax); store ret to g_state_0058c7dc;
 *   load g_state_0058c7c4; clear g_state_0058c7d4;
 *   if g_state_0058c7c4 != 0: call vtable[+8](eax);
 *   clear g_state_0058c7c4; ret.
 */
extern unsigned int g_state_0058c7d4;
extern unsigned int g_state_0058c7c4;
void DualVtable8Call_004af650(void) {
    void *p1 = g_state_0058c7d4;
    void *p2;
    if (p1) {
        g_state_0058c7dc = ((unsigned int (__stdcall **)(void*))(*(void**)p1))[2](p1);
    }
    p2 = g_state_0058c7c4;
    g_state_0058c7d4 = 0;
    if (p2) {
        ((unsigned int (__stdcall **)(void*))(*(void**)p2))[2](p2);
    }
    g_state_0058c7c4 = 0;
}
