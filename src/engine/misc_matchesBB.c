/**
 * Thirty-seventh batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_fightGroupHead;

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
extern void func_00404a50(int);
extern void func_0049e7e0(void);
extern int func_0049cb40_bb(void *, int);
extern int func_004be690(int);
extern void *g_data_004a0060;
extern unsigned short g_word_004e2860;
extern void func_004a1320(void);
__declspec(naked) void PushCallPauseStorePushDispatch_004a12e0(void) {
    __asm {
        push    0x22f
        call    func_00404a50
        add     esp, 4
        call    func_0049e7e0
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
        call    func_004be690
        add     esp, 4
        jmp     func_004a1320
        ret
    }
}

/* @addr 0x004a1790 (54b)
 *   load fightGroupHead; set g_eventQueueWorkType=0x01020000;
 *   set [eax*4 + 0x30]=0x25b; reload fightGroupHead → ecx;
 *   mov eax,0xfffb0000; store walk and [ecx*4 + 0x6c]=eax; jmp T.
 */
extern unsigned int g_eventQueueWorkType;
extern void func_004a17d0(void);
__declspec(naked) void SetWorkType02CountFFB_004a1790(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_eventQueueWorkType], 0x01020000
        mov     dword ptr [eax*4 + 0x30], 0x25b
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0xfffb0000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x6c], eax
        jmp     func_004a17d0
    }
}

/* @addr 0x004a1a10 (55b)
 *   push 0x25a; call F; load dirty al; add esp; test al,4;
 *   jz +5 → jmp T1; load g_scaledInit → ecx; mov eax,0xfffb0000;
 *   store walk and [ecx*4 + 0x6c]; jmp T2.
 */
extern void func_00404a00_bb(int);
extern void func_0041f780_bb(void);
extern void func_004a1a50(void);
__declspec(naked) void PushCallTestByte4Jmp_004a1a10(void) {
    __asm {
        push    0x25a
        call    func_00404a00_bb
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        test    al, 4
        _emit   74h
        _emit   05h
        jmp     func_0041f780_bb
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, 0xfffb0000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x6c], eax
        jmp     func_004a1a50
    }
}

/* @addr 0x004a1d50 (48b)
 *   8-iteration loop reading triplets from [0x004f2fd4 - 4 ..],
 *   writing AND-NOT result into [src1] and replacing [src2] with NOT(src1).
 */
extern unsigned int g_table_004f2fd4[];
__declspec(naked) void AndNotLoop_004a1d50(void) {
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
extern void func_00406790(void);
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
        call    func_00406790
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
extern void func_004ab600(void);
__declspec(naked) void StorePauseImulShr16_004ab630(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_state_00538150], eax
        call    func_004ab600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ch
        mov     ecx, dword ptr [g_walkCallback]
        and     ecx, 0xffff
        imul    ecx, dword ptr [g_state_00538150]
        shr     ecx, 0x10
        mov     dword ptr [g_walkCallback], ecx
        ret
    }
}

/* @addr 0x004ab750 (62b)
 *   load walk; store g_state_00538130; double eax; if neg → neg eax;
 *   store walk; call F; pause-test → ret;
 *   load g_state_00538130 - walk → walk.
 */
extern unsigned int g_state_00538130;
extern void func_004ab700(void);
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
        call    func_004ab700
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
extern void func_004adc20(void);
__declspec(naked) void QuadTestVtableCall_004ae950(void) {
    __asm {
        mov     eax, dword ptr [g_state_0058c7e0]
        test    eax, eax
        _emit   74h
        _emit   2fh
        mov     eax, dword ptr [g_state_0058c7ec]
        test    eax, eax
        _emit   75h
        _emit   26h
        call    func_004adc20
        mov     ecx, dword ptr [g_state_0058c7b4]
        test    ecx, ecx
        _emit   74h
        _emit   17h
        mov     eax, dword ptr [g_state_0058c7b0]
        test    eax, eax
        _emit   74h
        _emit   0eh
        mov     edx, dword ptr [eax]
        push    1
        push    ecx
        push    eax
        call    dword ptr [edx + 0x2c]
        mov     dword ptr [g_state_0058c7dc], eax
        ret
    }
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
__declspec(naked) void DualVtable8Call_004af650(void) {
    __asm {
        mov     eax, dword ptr [g_state_0058c7d4]
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 8]
        mov     dword ptr [g_state_0058c7dc], eax
        mov     eax, dword ptr [g_state_0058c7c4]
        mov     dword ptr [g_state_0058c7d4], 0
        test    eax, eax
        _emit   74h
        _emit   06h
        mov     edx, dword ptr [eax]
        push    eax
        call    dword ptr [edx + 8]
        mov     dword ptr [g_state_0058c7c4], 0
        ret
    }
}
