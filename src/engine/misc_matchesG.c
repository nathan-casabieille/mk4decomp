/**
 * Sixteenth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00401310 (33b): list iteration with append?
 *   cmp     [0x004ffdec], 0
 *   jne     +0x17
 *   mov     ecx, 0x004ffdec
 *   mov     eax, ecx
 *   add     eax, 0x0c
 *   mov     [ecx], 1
 *   nop * 1 (00)
 *   mov     ecx, eax
 *   cmp     [eax], -1
 *   jne     -0x10
 *   ret
 *
 * Hmm let me re-decode bytes: 833decfd4f00ff 7417 b9ecfd4f00 8bc1 83c00c c701000000 00 8bc8 8338ff 75f0 c3
 * 833d ecfd4f00 ff   = cmp dword [0x004ffdec], -1
 * 74 17               = je +0x17
 * b9 ec fd 4f 00      = mov ecx, 0x004ffdec
 * 8b c1               = mov eax, ecx
 * 83 c0 0c            = add eax, 0x0c
 * c7 01 00 00 00 00   = mov [ecx], 0
 * 8b c8               = mov ecx, eax
 * 83 38 ff            = cmp [eax], -1
 * 75 f0               = jne -0x10
 * c3                  = ret
 *
 * Actually wait: c7 01 + 4 bytes = mov [ecx], imm32. Let me check:
 *   c7 /0 = mov r/m32, imm32. With modr/m=01, mod=00 reg=000 rm=001 → mov [ecx], imm32.
 *   c7 01 00 00 00 00 = mov [ecx], 0  (5 bytes? Wait c7 01 + 4 = 6 bytes, but counted 5).
 *   Actually c7 01 takes 6 bytes total (1 opcode + 1 modr/m + 4 imm32).
 *
 * Hmm let me recount: 833decfd4f00ff = 7 bytes
 * 7417 = 2 bytes
 * b9ecfd4f00 = 5 bytes
 * 8bc1 = 2 bytes
 * 83c00c = 3 bytes
 * c701000000 = 5 bytes only? c7 01 00 00 00 00 = 6 bytes.
 *   Hex: c7 01 00 00 00 00. The byte string "c701000000" has length 10/2 = 5 bytes.
 *   So I'm miscounting: c7 01 00 00 00 = 5 bytes, but that's only `c7` opcode + `01` modr/m + `00 00 00` (3 bytes of imm32). Need 4 bytes for imm32.
 *   Re-look: "c701000000 008bc8" - the body has `c7 01 00 00 00 00 8b c8` = c7 01 00 00 00 00 (6 bytes) then 8b c8. OK my hex string parsing was wrong.
 *
 * Total: 7+2+5+2+3+6+2+3+2+1 = 33 ✓
 */
extern int g_list_004ffdec;
__declspec(naked) void ListInitLoop_00401310(void) {
    __asm {
        cmp     dword ptr [g_list_004ffdec], -1
        _emit   74h
        _emit   17h
        mov     ecx, OFFSET g_list_004ffdec
        mov     eax, ecx
        add     eax, 0x0c
        mov     dword ptr [ecx], 0
        mov     ecx, eax
        cmp     dword ptr [eax], -1
        _emit   75h
        _emit   0f0h
        ret
    }
}

/* @addr 0x00401370 (34b)
 *   push    edi
 *   mov     ecx, 0x0c
 *   xor     eax, eax
 *   mov     edi, 0x00523ae8
 *   rep     stosd
 *   mov     ecx, 0x0c
 *   mov     eax, 0x7fffffff
 *   mov     edi, 0x00523b28
 *   rep     stosd
 *   pop     edi
 *   ret
 */
__declspec(naked) void Init0AndMax_00401370(void) {
    __asm {
        push    edi
        mov     ecx, 0x0c
        xor     eax, eax
        mov     edi, 0x00523ae8
        rep     stosd
        mov     ecx, 0x0c
        mov     eax, 0x7fffffff
        mov     edi, 0x00523b28
        rep     stosd
        pop     edi
        ret
    }
}

/* @addr 0x0041fcc0 (37b)
 *   mov     eax, [esp+4]
 *   push    esi
 * .loop:
 *   mov     edx, [eax]
 *   mov     ecx, [eax + 4]
 *   add     eax, 4
 *   add     eax, 4
 *   test    ecx, ecx
 *   jne     .skip1
 *   test    edx, edx
 *   je      .ret
 * .skip1:
 *   mov     esi, [edx]
 *   sar     ecx, 2
 *   or      esi, ecx
 *   mov     [edx], esi
 *   jmp     .loop
 * .ret:
 *   pop     esi
 *   ret
 */
__declspec(naked) void OrListLoop_0041fcc0(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        mov     edx, dword ptr [eax]
        mov     ecx, dword ptr [eax + 4]
        add     eax, 4
        add     eax, 4
        test    ecx, ecx
        _emit   75h
        _emit   04h
        test    edx, edx
        _emit   74h
        _emit   0bh
        mov     esi, dword ptr [edx]
        sar     ecx, 2
        or      esi, ecx
        mov     dword ptr [edx], esi
        _emit   0ebh
        _emit   0e2h
        pop     esi
        ret
    }
}

/* @addr 0x004265a0 (41b): copy/set 4-stride
 *   mov     eax, [g_xformEntityIdx]
 *   mov     edx, [g_scaledInit_00542044]
 *   lea     ecx, [eax*4 + 0]
 *   lea     eax, [edx*4 + 0]
 * .loop:
 *   mov     dl, [eax]
 *   add     eax, 4
 *   mov     [ecx], dl
 *   inc     ecx
 *   mov     edx, [eax - 4]   ; just to set ZF? actually it's mov edx, [eax+0xfc]
 *   test    edx, edx
 *   jne     .loop
 *   ret
 *
 * Wait actually: 8b 50 fc = mov edx, [eax-4]. Let me re-decode:
 * Body: a1 482054 00 8b15 442054 00 8d0c85 00000000 8d0495 00000000 8a10 83c004 8811 41 8b50fc 85d2 75f1 c3
 * 5+6+7+7+2+3+2+1+3+2+2+1 = 41 ✓
 */
__declspec(naked) void CopyByteUntilNull_004265a0(void) {
    __asm {
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_scaledInit_00542044]
        lea     ecx, [eax*4 + 0]
        lea     eax, [edx*4 + 0]
        mov     dl, byte ptr [eax]
        add     eax, 4
        mov     byte ptr [ecx], dl
        inc     ecx
        mov     edx, dword ptr [eax - 4]
        test    edx, edx
        _emit   75h
        _emit   0f1h
        ret
    }
}

/* @addr 0x00434530 (34b)
 *   mov     eax, [g_state_0053a51c]
 *   cmp     eax, 8
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   jmp     T1
 *   test    eax, eax
 *   jne     +5
 *   jmp     T2
 *   jmp     +0x0e
 */
extern unsigned int g_state_0053a51c;
extern void func_00434983(void);
extern void func_004348e1(void);
extern void func_0043454c(void);
__declspec(naked) void TriBranchJmp_00434530(void) {
    __asm {
        mov     eax, dword ptr [g_state_0053a51c]
        cmp     eax, 8
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_00434983
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004348e1
        jmp     func_0043454c
    }
}

/* @addr 0x004398f0 (38b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x74]
 *   cmp     eax, 0x200e
 *   mov     [g_eventQueueWorkType], eax
 *   je      .skip
 *   xor     eax, eax
 *   ret
 * .skip:
 *   call    F
 *   mov     eax, 1
 *   ret
 */
extern u32 g_eventQueueWorkType;
extern void func_00439998(void);
__declspec(naked) void ScaledCmp200eCallBool_004398f0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x74]
        cmp     eax, 0x200e
        mov     dword ptr [g_eventQueueWorkType], eax
        _emit   74h
        _emit   03h
        xor     eax, eax
        ret
        call    func_00439998
        mov     eax, 1
        ret
    }
}

/* @addr 0x00439b50 (39b)
 *   mov     [g_walkCallback], 0x258
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      .doit
 *   jmp     T
 * .doit:
 *   ret    (actually fall-through to next; je 5 then jmp tail)
 *
 * Wait let me re-check: c7 05 6c 20 54 00 58 02 00 00 e8 31 1b 07 00 a1 6c 1e 54 00 85 c0 75 0e f6 05 8c 20 54 00 01 74 05 e9 aa 00 00 00 c3
 * Decoded:
 * - mov [g_walkCallback], 0x258
 * - call F
 * - mov eax, [g_framePauseFlag]
 * - test eax, eax
 * - jne +0xe (taken if pause)
 * - test byte [g_xformDirtyFlags], 1
 * - je +5 (taken if NOT dirty)
 * - jmp T
 * - ret
 */
extern void AudioVolumeRescale_004ab690(void);
extern void func_00439bff(void);
void Set258Call_PauseDirtyJmp_00439b50(void) {
    g_walkCallback = (void (*)(void))0x258;
    AudioVolumeRescale_004ab690();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) == 0) return;
    func_00439bff();
}

/* @addr 0x00439320 (38b)
 *   push    0x005422f8
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], 0x2147
 *   jmp     T
 *   ret
 */
extern int IterLoad_00491050(void *);
extern void *g_data_005422f8;
extern void ScaledOrStore_004903d0(void);
void PushCallSet2147Jmp_00439320(void) {
    IterLoad_00491050(&g_data_005422f8);
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x2147;
    ScaledOrStore_004903d0();
}

/* @addr 0x00446150 (44b)
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [g_fightGroupHead], eax
 *   mov     [g_scaledInit_00542044], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     .ret
 *   jmp     T
 *   ret
 */
extern void func_004085f0(void);
extern void func_004058a0(void);
__declspec(naked) void TripleSetCallPauseDirtyJmp_00446150(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_fightGroupHead], eax
        mov     dword ptr [g_scaledInit_00542044], eax
        call    func_004085f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0eh
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     func_004058a0
        ret
    }
}

/* @addr 0x004462c0 (38b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x5c]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     eax, [eax*4 + 0x38]
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x28], eax
 *   ret
 */
__declspec(naked) void ScaledChainStore_004462c0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x5c]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     eax, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x28], eax
        ret
    }
}

/* @addr 0x00446320 (36b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, 2
 *   mov     eax, [eax*4 + 0x5c]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [eax*4 + 0x1c], ecx
 *   ret
 */
__declspec(naked) void ScaledStoreConst2_00446320(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, 2
        mov     eax, dword ptr [eax*4 + 0x5c]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0x1c], ecx
        ret
    }
}
