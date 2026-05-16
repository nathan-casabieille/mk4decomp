/**
 * Forty-first batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x0041f7d0 (61b)
 *   walk a fixed-stride scenegraph chain from 0x0053e368 to 0x00541d68 step 0xe8;
 *   for each entry whose [+0xd8] != 0, set g_scaledInit_00542044 to (esi >> 2)
 *   and call F if it differs from g_baseSel_00542060.
 */
extern void NodeUnlink_0041f710(void *p);
__declspec(naked) void ScenegraphWalk_0041f7d0(void) {
    __asm {
        push    esi
        mov     esi, 0x0053e368
loop_top:
        mov     eax, dword ptr [esi + 0xd8]
        test    eax, eax
        _emit   74h
        _emit   1dh
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, esi
        sar     eax, 2
        cmp     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   74h
        _emit   09h
        push    esi
        call    NodeUnlink_0041f710
        add     esp, 4
        add     esi, 0xe8
        cmp     esi, 0x00541d68
        _emit   72h
        _emit   0cbh
        pop     esi
        ret
    }
}

/* @addr 0x00421be0 (61b)
 *   load g_state_0053a718; set g_eventQueueChild = 0x28;
 *   eax = state - 1; if (eax < 0x14) return-tail; else set walk=0x32
 *   call F; pause-test; jmp T.
 */
extern unsigned int g_state_0053a718;
extern void func_00489ff0_ff(void);
extern void PollThenInit_00477920(void);
void DecBoundCheckCallJmp_00421be0(void) {
    int s = (int)g_state_0053a718;
    g_eventQueueChild = 0x28;
    s--;
    g_walkCallback = (void(*)(void))s;
    g_state_0053a718 = s;
    if (s < 0x14) {
        g_walkCallback = (void(*)(void))0x32;
        func_00489ff0_ff();
        if (g_framePauseFlag) return;
    }
    PollThenInit_00477920();
}

/* @addr 0x0042afc0 (64b)
 *   modulo using 32x32->64 magic-number division: ecx %= 0x6487e (range modulus).
 *   Bound-clamps and adds offsets via g_state_004d5320..00d4d532c.
 */
extern unsigned int g_state_004d5320;
extern unsigned int g_state_004d5324;
extern unsigned int g_state_004d532c;
__declspec(naked) void ModuloMagic_0042afc0(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        mov     eax, dword ptr [g_state_004d5320]
        cmp     ecx, eax
        _emit   7eh
        _emit   0ch
        mov     edx, dword ptr [g_state_004d5324]
sub_loop:
        sub     ecx, edx
        cmp     ecx, eax
        _emit   7fh
        _emit   0fah
        mov     edx, dword ptr [g_state_004d532c]
        cmp     ecx, edx
        _emit   7fh
        _emit   1ah
        sub     edx, ecx
        mov     eax, 0xa2f99905
        add     edx, 0x6487e
        mul     edx
        shr     edx, 0x12
        imul    edx, edx, 0x6487e
        add     ecx, edx
        mov     eax, ecx
        ret
    }
}

/* @addr 0x0043c350 (62b)
 *   call F; pause-test → ret;
 *   load baseSel, scaled +0x38 → g_eventQueueEnd;
 *   testb 1,[g_xformDirtyFlags]; set g_eventQueueChild based on dirty bit.
 */
extern void MStackPush2ChainSwap_0048f090(void);
void CallPauseScaledByteSet_0043c350(void) {
    MStackPush2ChainSwap_0048f090();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_eventQueueEnd = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x38);
    g_eventQueueChild = 0xffff0000;
    if ((g_xformDirtyFlags & 1) != 0) {
        g_eventQueueChild = 0x10000;
    }
}

/* @addr 0x00446000 (61b)
 *   set g_xformEntityIdx = 0x51140c >> 2; call F; pause → ret;
 *   testb 4,[dirty]; jne ret; load baseSel, scaled, store into [ecx*4 + 0x5c]; jmp T.
 */
extern void MStackBracket1_TreeWalkRecursive2_00406dd0(void);
extern void ScaledTestPauseStore_00408860(void);
extern unsigned int g_table_0051140c;
void SpecialInitDirtyJmp_00446000(void) {
    g_xformEntityIdx = (unsigned int)&g_table_0051140c >> 2;
    MStackBracket1_TreeWalkRecursive2_00406dd0();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((g_xformDirtyFlags & 4) != 0) {
        return;
    }
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x5c) = g_scaledInit_00542044;
    ScaledTestPauseStore_00408860();
}

/* @addr 0x00460c60 (61b)
 *   call F1; pause → ret; call F2; if eax != 0 → ret;
 *   inc g_state_004d57ac; set walk=2; push 0x46f6b0 to stack[idx*4]; jmp T.
 */
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern int DualGatedStateYield_0048fc80(void);
extern unsigned int g_state_004d57ac_ff;
extern void MstackPopScaledChainPlusThunks_00471250(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
void CallPauseCallTestStackPushJmp_00460c60(void) {
    unsigned int top;
    LeaPlus22StoreSelf_0048e4d0();
    if (g_framePauseFlag != 0) {
        return;
    }
    if (DualGatedStateYield_0048fc80() != 0) {
        return;
    }
    top = g_state_004d57ac_ff;
    g_walkCallback = (void (*)(void))2;
    top++;
    g_state_004d57ac_ff = top;
    *(unsigned int *)(top * 4) = (unsigned int)&FiveCallGuardSetTail_0046f6b0;
    MstackPopScaledChainPlusThunks_00471250();
}

/* @addr 0x004c3eb0 (60b)
 *   if g_state_00f9efcc != 0:
 *     bl = clamp(arg, 0..0x64); ecx = sbyte(bl); eax = (ecx*16 + ecx)*3 = 51*ecx;
 *     ecx = (short)g_table_00f85b60[eax*8]; call vtable[edx, +0x3c](edx, ecx);
 *     g_state_00f9efec = bl.
 */
extern unsigned int *g_state_00f9efcc;
extern unsigned char g_byte_00f9efec;
extern short g_table_00f85b60[];
__declspec(naked) void Helper_TitleSetMaxVolume(void) {
    __asm {
        mov     edx, dword ptr [g_state_00f9efcc]
        test    edx, edx
        _emit   74h
        _emit   31h
        push    esi
        push    ebx
        mov     bl,  byte  ptr [esp + 0x0c]
        cmp     bl, 0x64
        _emit   76h
        _emit   02h
        mov     bl, 0x64
        movsx   ecx, bl
        mov     eax, ecx
        mov     esi, dword ptr [edx]
        shl     eax, 4
        add     eax, ecx
        lea     eax, [eax + eax*2]
        movsx   ecx, word ptr [eax*8 + g_table_00f85b60]
        push    ecx
        push    edx
        call    dword ptr [esi + 0x3c]
        mov     byte  ptr [g_byte_00f9efec], bl
        pop     ebx
        pop     esi
        ret
    }
}

/* @addr 0x004c8ae0 (51b)
 *   if (arg[3] & 0x83) && (arg[3] & 8):
 *     call F(arg[2]); arg[3] &= ~0x408; arg[0..2] = 0.
 */
extern void FreeImpl_004c55f0(int);
__declspec(naked) void BitTestFreeClear_004c8ae0(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        mov     eax, dword ptr [esi + 0x0c]
        test    al, 0x83
        _emit   74h
        _emit   25h
        test    al, 8
        _emit   74h
        _emit   21h
        mov     eax, dword ptr [esi + 8]
        push    eax
        call    FreeImpl_004c55f0
        mov     eax, dword ptr [esi + 0x0c]
        add     esp, 4
        and     eax, 0xfffffbf7
        mov     dword ptr [esi + 0x0c], eax
        xor     eax, eax
        mov     dword ptr [esi], eax
        mov     dword ptr [esi + 8], eax
        mov     dword ptr [esi + 4], eax
        pop     esi
        ret
    }
}

/* @addr 0x004cd320 (34b)
 *   arg = [esp+4]; eax = arg & 0x1f, ecx = arg >> 5;
 *   edx = eax * 9 (lea eax + eax*8);
 *   eax = g_table_00fa0de0[ecx]; ecx = eax + edx*4 + 0x0c;
 *   call IAT [g_iat_004d213c](ecx).
 */
extern unsigned int g_table_00fa0de0[];
extern void (*g_iat_004d213c)(void *);
__declspec(naked) void DivMod32IAT_004cd320(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, eax
        and     eax, 0x1f
        sar     ecx, 5
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [ecx*4 + g_table_00fa0de0]
        lea     ecx, [eax + edx*4 + 0x0c]
        push    ecx
        call    dword ptr [g_iat_004d213c]
        ret
    }
}

/* @addr 0x004ce1f0 (35b)
 *   arg1 = [esp+4]; arg2 = [esp+0xc]; ecx = arg2 + arg1;
 *   eax = (ecx < arg1 || ecx >= arg2) ? 1 : 0; *(arg3) = ecx; ret eax.
 */
__declspec(naked) void AddOverflowCheck_004ce1f0(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        mov     esi, dword ptr [esp + 0x0c]
        xor     eax, eax
        lea     ecx, [esi + edx*1]
        cmp     ecx, edx
        _emit   72h
        _emit   04h
        cmp     ecx, esi
        _emit   73h
        _emit   05h
        mov     eax, 1
        mov     edx, dword ptr [esp + 0x10]
        pop     esi
        mov     dword ptr [edx], ecx
        ret
    }
}
