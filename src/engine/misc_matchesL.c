/**
 * Twenty-first batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0049a620 (44b)
 *   mov     [g_walkCallback], 0x43
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void func_00489fe6_l(void);
extern void func_00410dd8(void);
extern void func_0049a64a(void);
__declspec(naked) void Set43DualCallJmp_0049a620(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x43
        call    func_00489fe6_l
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    func_00410dd8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0049a64a
        ret
    }
}

/* @addr 0x0049d310 (42b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_walkCallback]
 *   shl     eax, 2
 *   mov     [eax + 4], ecx
 *   mov     edx, [g_eventQueueCurrent]
 *   mov     [eax + 8], edx
 *   mov     ecx, [g_eventQueueWorkType]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x0c], ecx
 *   ret
 */
extern u32 g_eventQueueWorkType;
__declspec(naked) void ScaledStoreThree_0049d310(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_walkCallback]
        shl     eax, 2
        mov     dword ptr [eax + 4], ecx
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax + 8], edx
        mov     ecx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x0c], ecx
        ret
    }
}

/* @addr 0x0049fa20 (36b): same shape as 0x0042ee10 / 0x00464320 - cmp 3 / dirty manip */
extern unsigned int g_state_0052aac4_l;
__declspec(naked) void Cmp3DirtyToggle_0049fa20(void) {
    __asm {
        mov     eax, dword ptr [g_state_0052aac4_l]
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 3
        mov     eax, dword ptr [g_xformDirtyFlags]
        _emit   74h
        _emit   08h
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x004a1120 (36b)
 *   mov     eax, [g_walkCallback]
 *   inc     eax
 *   cmp     eax, 0x0f
 *   mov     [g_walkCallback], eax
 *   ja      +5
 *   jmp     T
 *   mov     [g_walkCallback], 1
 *   jmp     T2
 */
extern void func_004a1141(void);
extern void func_004a1136(void);
__declspec(naked) void IncWrap0fJmp_004a1120(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        inc     eax
        cmp     eax, 0x0f
        mov     dword ptr [g_walkCallback], eax
        _emit   77h
        _emit   05h
        jmp     func_004a1141
        mov     dword ptr [g_walkCallback], 1
        jmp     func_004a1136
    }
}

/* @addr 0x004a1ae0 (32b)
 *   test    byte ptr [0x004d50b8], 0x22
 *   je      .skip
 *   mov     eax, 1
 *   ret
 * .skip:
 *   mov     eax, [0x004d50b4]
 *   and     eax, 0x4040
 *   neg     eax
 *   sbb     eax, eax
 *   neg     eax
 *   ret
 */
extern unsigned char g_byte_004d50b8[1];
extern unsigned int g_state_004d50b4;
__declspec(naked) void TestByteOrAndCheck_004a1ae0(void) {
    __asm {
        test    byte ptr [g_byte_004d50b8], 0x22
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        mov     eax, dword ptr [g_state_004d50b4]
        and     eax, 0x4040
        neg     eax
        sbb     eax, eax
        neg     eax
        ret
    }
}

/* @addr 0x004aa3f0 (32b)
 *   mov     edx, [esp+4]
 *   push    esi
 *   mov     eax, edx
 *   mov     ecx, 3
 *   mov     esi, [eax + 4]
 *   mov     [eax], esi
 *   add     eax, 4
 *   dec     ecx
 *   jne     -10
 *   mov     eax, [esp+0x0c]
 *   pop     esi
 *   mov     [edx + 0x0c], eax
 *   ret
 */
__declspec(naked) void ShiftDownThreeAndAppend_004aa3f0(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        mov     eax, edx
        mov     ecx, 3
        mov     esi, dword ptr [eax + 4]
        mov     dword ptr [eax], esi
        add     eax, 4
        dec     ecx
        _emit   75h
        _emit   0f5h
        mov     eax, dword ptr [esp + 0x0c]
        pop     esi
        mov     dword ptr [edx + 0x0c], eax
        ret
    }
}

/* @addr 0x004aa410 (32b)
 *   mov     eax, [esp+4]
 *   mov     ecx, eax
 *   sar     eax, 0x10
 *   and     ecx, 0xffff
 *   and     eax, 0xffff
 *   mov     [g_walkCallback], ecx
 *   mov     [g_eventQueueCurrent], eax
 *   ret
 */
__declspec(naked) void SplitInt32_004aa410(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, eax
        sar     eax, 0x10
        and     ecx, 0xffff
        and     eax, 0xffff
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        ret
    }
}

/* @addr 0x004aa990 (41b)
 *   mov     eax, [g_walkCallback]
 *   mov     ecx, [eax*4 + 0x004f3f40]
 *   sar     ecx, 2
 *   mov     [g_xformEntityIdx], ecx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void *g_table_004f3f40[];
extern void *g_table_004f3f90[];
extern void func_004073f0(void);
extern void func_004093f0(void);
__declspec(naked) void TableLookupCallJmp_004aa990(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [eax*4 + g_table_004f3f40]
        sar     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    func_004073f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_004093f0
        ret
    }
}

/* @addr 0x004aa9c0 (41b): same shape with table=0x004f3f90 */
extern void func_00407420(void);
extern void MStackPush2GatedTail_00409420(void);
__declspec(naked) void TableLookupCallJmp_004aa9c0(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [eax*4 + g_table_004f3f90]
        sar     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        call    func_00407420
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     MStackPush2GatedTail_00409420
        ret
    }
}

/* @addr 0x004ab300 (31b)
 *   mov     ecx, [g_eventQueueCurrent]
 *   test    ecx, ecx
 *   jne     +7
 *   mov     [g_walkCallback], ecx
 *   ret
 *   mov     eax, [g_walkCallback]
 *   cdq
 *   idiv    ecx
 *   mov     [g_walkCallback], eax
 *   ret
 */
__declspec(naked) void DivBy_004ab300(void) {
    __asm {
        mov     ecx, dword ptr [g_eventQueueCurrent]
        test    ecx, ecx
        _emit   75h
        _emit   07h
        mov     dword ptr [g_walkCallback], ecx
        ret
        mov     eax, dword ptr [g_walkCallback]
        cdq
        idiv    ecx
        mov     dword ptr [g_walkCallback], eax
        ret
    }
}
