/**
 * Thirty-ninth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b5a80 (52b)
 *   rep stos zero-fill 0xc0000 dwords starting at 0x007b41a0;
 *   then mask + or bits, set [0x007b41a8] = 0x007b41a0 (self-link list head).
 */
extern unsigned int g_state_007b41a0;
extern unsigned int g_state_007b41a8;
__declspec(naked) void RepStosInitState_004b5a80(void) {
    __asm {
        push    edi
        mov     ecx, 0xc0000
        xor     eax, eax
        mov     edi, OFFSET g_state_007b41a0
        rep stosd
        mov     eax, dword ptr [g_state_007b41a0]
        mov     dword ptr [g_state_007b41a8], OFFSET g_state_007b41a0
        and     eax, 0xff2ffff4
        pop     edi
        or      eax, 0x002ffff4
        or      eax, 0x80000000
        mov     dword ptr [g_state_007b41a0], eax
        ret
    }
}

/* @addr 0x004b62c0 (55b)
 *   table search descending from arg-1; each entry is 8 bytes.
 *   while (eax >= 0 && tab[eax].first != 0) { if (tab[eax].second != 1) break; eax--; }
 *   complex tail computing the final index.
 */
__declspec(naked) void TableSearchDesc_004b62c0(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        mov     esi, 1
        lea     eax, [edx - 1]
        test    eax, eax
        _emit   7ch
        _emit   1ah
        mov     ecx, dword ptr [esp + 0x0c]
        lea     ecx, [ecx + eax*8]
        cmp     dword ptr [ecx], 0
        _emit   74h
        _emit   0eh
        cmp     word  ptr [ecx + 4], si
        _emit   75h
        _emit   12h
        dec     eax
        sub     ecx, 8
        test    eax, eax
        _emit   7dh
        _emit   0edh
        xor     eax, eax
        cmp     edx, esi
        setl    al
        dec     eax
        and     eax, edx
        pop     esi
        ret
    }
}

/* @addr 0x004b6300 (58b)
 *   table search ascending from arg+1; clamps arg < -1 to -1; returns count
 *   of contiguous valid entries (each 8 bytes; .second must equal 1, .next != 0).
 */
__declspec(naked) void TableSearchAsc_004b6300(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        cmp     edx, 0xffffffff
        push    edi
        _emit   7dh
        _emit   03h
        or      edx, 0xffffffff
        mov     ecx, dword ptr [esp + 0x10]
        lea     eax, [edx + 1]
        mov     esi, dword ptr [ecx + eax*8]
        lea     ecx, [ecx + eax*8]
        test    esi, esi
        _emit   74h
        _emit   16h
        mov     esi, 1
        cmp     word  ptr [ecx + 4], si
        _emit   75h
        _emit   0dh
        mov     edi, dword ptr [ecx + 8]
        add     ecx, 8
        inc     eax
        test    edi, edi
        _emit   75h
        _emit   0efh
        mov     eax, edx
        pop     edi
        pop     esi
        ret
    }
}

/* @addr 0x004bd530 (56b)
 *   if (arg && *arg) {
 *     call free([*arg], 4); call free([*arg], &g_state_00ab5204);
 *     g_state_00ab5200 = 1; *arg = 0;
 *   }
 */
extern void func_004b5ae0(int, int);
extern void func_004b5b00(int, int);
extern unsigned int g_state_00ab5200;
extern int g_data_00ab5204;
__declspec(naked) void CleanupCallTwice_004bd530(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        mov     eax, dword ptr [esi]
        test    eax, eax
        _emit   74h
        _emit   2bh
        push    4
        push    eax
        call    func_004b5ae0
        mov     eax, dword ptr [esi]
        add     esp, 8
        push    OFFSET g_data_00ab5204
        push    eax
        call    func_004b5b00
        mov     dword ptr [g_state_00ab5200], 1
        add     esp, 8
        mov     dword ptr [esi], 0
        pop     esi
        ret
    }
}

/* @addr 0x004bd850 (57b)
 *   walk table 0x00ab4e78..0x00ab5034 step 4;
 *   each entry's high bit triggers a call after clearing it
 *   into g_scaledInit_00542044; pause-test breaks the loop.
 */
extern unsigned int g_table_004ab4e78[];
extern void func_004bd5b0(void);
__declspec(naked) void TableWalkPause_004bd850(void) {
    __asm {
        push    esi
        mov     esi, OFFSET g_table_004ab4e78
loop_top:
        mov     eax, dword ptr [esi]
        test    eax, 0x80000000
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   74h
        _emit   18h
        and     eax, 0x7fffffff
        mov     dword ptr [g_scaledInit_00542044], eax
        call    func_004bd5b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0bh
        add     esi, 4
        cmp     esi, 0x00ab5034
        _emit   7ch
        _emit   0cfh
        pop     esi
        ret
    }
}

/* @addr 0x004be210 (52b)
 *   scaled load; 16-bit neg of 3 word fields at offsets 0,2,4;
 *   set g_xformDirtyFlags |= 0x30.
 */
__declspec(naked) void ScaledNegThreeWords_004be210(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        shl     eax, 2
        mov     cx,  word  ptr [eax]
        mov     dx,  word  ptr [eax + 2]
        neg     cx
        mov     word  ptr [eax], cx
        mov     cx,  word  ptr [eax + 4]
        neg     dx
        neg     cx
        mov     word  ptr [eax + 2], dx
        mov     word  ptr [eax + 4], cx
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al,  0x30
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x004c5790 (56b): set 5 vtable slots at 0x00522160..0x00522174 */
extern void *g_iat_00522160;
extern void *g_iat_00522164;
extern void *g_iat_00522168;
extern void *g_iat_0052216c;
extern void *g_iat_00522170;
extern void *g_iat_00522174;
extern void func_004c8940(void);
extern void func_004c84e0(void);
extern void func_004c8570(void);
extern void func_004c8480(void);
extern void func_004c8550(void);
__declspec(naked) void SetVtable5Slots_004c5790(void) {
    __asm {
        mov     eax, OFFSET func_004c8940
        mov     dword ptr [g_iat_00522164], OFFSET func_004c84e0
        mov     dword ptr [g_iat_00522160], eax
        mov     dword ptr [g_iat_00522168], OFFSET func_004c8570
        mov     dword ptr [g_iat_0052216c], OFFSET func_004c8480
        mov     dword ptr [g_iat_00522170], OFFSET func_004c8550
        mov     dword ptr [g_iat_00522174], eax
        ret
    }
}

/* @addr 0x004c5a90 (50b): wrapper that calls 3 functions on arg */
extern void func_004c6ff0(int);
extern int func_004c5ad0(int, int, int);
extern void func_004c7060(int);
__declspec(naked) void WrapperCallThree_004c5a90(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        push    edi
        push    esi
        call    func_004c6ff0
        mov     eax, dword ptr [esp + 0x18]
        mov     ecx, dword ptr [esp + 0x14]
        add     esp, 4
        push    eax
        push    ecx
        push    esi
        call    func_004c5ad0
        add     esp, 0x0c
        mov     edi, eax
        push    esi
        call    func_004c7060
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        ret
    }
}

/* @addr 0x004c6e60 (42b)
 *   if g_state_00f9f84c == 1, call F; then call F2(arg);
 *   call IAT [g_iat_00520060](0xff); ret.
 */
extern unsigned int g_state_00f9f84c;
extern void func_004cc030(void);
extern void func_004cc070(int);
extern void (*g_iat_00520060)(int);
__declspec(naked) void CmpCallPushIATCall_004c6e60(void) {
    __asm {
        cmp     dword ptr [g_state_00f9f84c], 1
        _emit   75h
        _emit   05h
        call    func_004cc030
        mov     eax, dword ptr [esp + 4]
        push    eax
        call    func_004cc070
        add     esp, 4
        push    0xff
        call    dword ptr [g_iat_00520060]
        add     esp, 4
        ret
    }
}

/* @addr 0x0042fea0 (64b)
 *   load g_state_0053815c; set g_eventQueueWorkType = 0x4ccc;
 *   store eax → g_scaledInit; call F; pause → ret;
 *   load g_walkCallback, g_state_00538158;
 *   store both into g_eventQueueCurrent and g_scaledInit; jmp T.
 */
extern unsigned int g_state_0053815c;
extern unsigned int g_state_00538158_dd;
extern unsigned int g_eventQueueWorkType;
extern void func_0042fee0(void);
__declspec(naked) void LoadSetCallPauseStoreJmp_0042fea0(void) {
    __asm {
        mov     eax, dword ptr [g_state_0053815c]
        mov     dword ptr [g_eventQueueWorkType], 0x4ccc
        mov     dword ptr [g_scaledInit_00542044], eax
        call    func_0042fee0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_state_00538158_dd]
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     func_0042fee0
        ret
    }
}
