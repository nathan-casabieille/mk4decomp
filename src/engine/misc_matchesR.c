/**
 * Twenty-seventh batch of one-off matches.
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c38d0 (43b)
 *   push    esi
 *   xor     ecx, ecx
 *   xor     eax, eax
 *   mov     esi, 0x00f9eb80
 * .loop:
 *   cmp     word ptr [esi], -1
 *   je      .skip
 *   mov     edx, 1
 *   shl     edx, cl
 *   jmp     .merge
 * .skip:
 *   xor     edx, edx
 * .merge:
 *   or      eax, edx
 *   add     esi, 4
 *   inc     ecx
 *   cmp     esi, 0x00f9ebc0
 *   jl      .loop
 *   pop     esi
 *   ret
 */
int BuildMaskFromArray_004c38d0(void) {
    int i = 0;
    int mask = 0;
    int p = 0x00f9eb80;
    while (p < 0x00f9ebc0) {
        mask |= (*(short *)p != -1) ? (1 << i) : 0;
        p += 4;
        i++;
    }
    return mask;
}

/* @addr 0x004c4420 (41b)
 *   mov     ax, word ptr [esp+4]
 *   cmp     ax, 0x0898
 *   jae     +0x1d
 *   movsx   eax, ax
 *   mov     ecx, eax
 *   shl     ecx, 3
 *   sub     ecx, eax
 *   lea     eax, [ecx*4 + 0x00f8fade]
 *   mov     cl, [ecx*4 + 0x00f8fade]
 *   or      cl, 4
 *   mov     [eax], cl
 *   ret
 */
extern unsigned int g_data_00f8fade;
void TableSetBit_004c4420(short idx) {
    if ((unsigned short)idx < 0x0898) {
        *(unsigned char *)((&g_data_00f8fade) + idx * 7) |= 4;
    }
}

/* @addr 0x004c58b0 (40b)
 *   push    esi
 *   mov     esi, [esp+8]
 *   push    edi
 *   push    esi
 *   call    F1
 *   add     esp, 4
 *   push    esi
 *   call    F2
 *   add     esp, 4
 *   mov     edi, eax
 *   push    esi
 *   call    F3
 *   add     esp, 4
 *   mov     eax, edi
 *   pop     edi
 *   pop     esi
 *   ret
 */
extern void RangePathIATDispatch_004c6ff0(int);
extern int Helper_FRead(int);
extern void RangePathIATDispatch_004c7060(int);
int Helper_FTell(int arg) {
    int saved;
    RangePathIATDispatch_004c6ff0(arg);
    saved = Helper_FRead(arg);
    RangePathIATDispatch_004c7060(arg);
    return saved;
}

/* @addr 0x004c5dd0 (48b): MSVC CRT __chkstk (a.k.a. __alloca_probe).
 *
 * Stack-probing helper inserted automatically by MSVC at the prologue
 * of any function that allocates more than 4 KB on the stack. Cannot
 * be expressed in pure C - the argument arrives in EAX (non-cdecl ABI),
 * and the body directly mutates ESP and uses `push eax; ret` to splice
 * the original return address back after the stack adjustment. This
 * function is shipped verbatim from MSVC 5.0's CRT (chkstk.asm in
 * libc.lib / libcmt.lib); the orig MK4.EXE links it statically. Keep
 * naked.
 *
 *   push    ecx                  ; save scratch
 *   cmp     eax, 0x1000          ; if request <= 1 page, skip the probe loop
 *   lea     ecx, [esp+8]         ; ecx = original esp (before the push ecx + ret addr)
 *   jb      .commit
 * .probe_loop:
 *   sub     ecx, 0x1000          ; step down one page
 *   sub     eax, 0x1000          ; account for the page
 *   test    [ecx], eax           ; probe the page (forces VM commit by page fault)
 *   cmp     eax, 0x1000
 *   jae     .probe_loop
 * .commit:
 *   sub     ecx, eax             ; ecx = final new esp
 *   mov     eax, esp             ; eax = current esp (= addr of saved ecx)
 *   test    [ecx], eax           ; final probe at the new bottom
 *   mov     esp, ecx             ; commit the stack adjustment
 *   mov     ecx, [eax]           ; restore caller's ecx (from the saved slot at old top)
 *   mov     eax, [eax+4]         ; eax = caller's return address
 *   push    eax                  ; push it back so ret picks it up
 *   ret
 *   int 3                        ; unreachable padding
 */
__declspec(naked) void Helper_ChkStk(void) {
    __asm {
        push    ecx
        cmp     eax, 0x1000
        lea     ecx, [esp + 8]
        _emit   72h
        _emit   14h
        sub     ecx, 0x1000
        sub     eax, 0x1000
        test    dword ptr [ecx], eax
        cmp     eax, 0x1000
        _emit   73h
        _emit   0ech
        sub     ecx, eax
        mov     eax, esp
        test    dword ptr [ecx], eax
        mov     esp, ecx
        mov     ecx, dword ptr [eax]
        mov     eax, dword ptr [eax + 4]
        push    eax
        ret
        _emit   0cch
    }
}

/* @addr 0x004c6940 (32b)
 *   push    esi
 *   mov     esi, [esp+8]
 *   push    edi
 *   mov     edi, [esp+0x10]
 *   cmp     esi, edi
 *   jae     .ret
 * .loop:
 *   mov     eax, [esi]
 *   test    eax, eax
 *   je      .skip
 *   call    eax
 * .skip:
 *   add     esi, 4
 *   cmp     esi, edi
 *   jb      .loop
 * .ret:
 *   pop     edi
 *   pop     esi
 *   ret
 */
void IterFnPtrs_004c6940(void (**start)(void), void (**end)(void)) {
    while (start < end) {
        void (*f)(void) = *start;
        if (f != 0) f();
        start++;
    }
}

/* @addr 0x004c6ec0 (32b)
 *   mov     eax, [0x00f9f854]
 *   test    eax, eax
 *   je      .skip
 *   mov     ecx, [esp+4]
 *   push    ecx
 *   call    eax
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, 1
 *   ret
 * .ret:
 *   xor     eax, eax
 *   ret
 */
extern int (*g_state_00f9f854)(int);
int IndirectCall_004c6ec0(int arg) {
    if (g_state_00f9f854 != 0 && g_state_00f9f854(arg) != 0) {
        return 1;
    }
    return 0;
}

/* @addr 0x004c6f20 (43b): four indirect calls
 *   mov     eax, [g_iat_005200b4]
 *   push    esi
 *   mov     esi, [iat]
 *   push    eax
 *   call    esi
 *   mov     ecx, [g_iat_005200a4]
 *   push    ecx
 *   call    esi
 *   mov     edx, [g_iat_00520094]
 *   push    edx
 *   call    esi
 *   mov     eax, [g_iat_00520074]
 *   push    eax
 *   call    esi
 *   pop     esi
 *   ret
 */
extern void *g_iat_005200b4;
extern void *g_iat_005200a4;
extern void *g_iat_00520094;
extern void *g_iat_00520074;
extern void (__stdcall *g_iat_004d215c)(void *);
void FourIndirectCalls_004c6f20(void) {
    void (__stdcall *f)(void *) = g_iat_004d215c;
    f(g_iat_005200b4);
    f(g_iat_005200a4);
    f(g_iat_00520094);
    f(g_iat_00520074);
}

/* @addr 0x004c89b0 (41b): strchr-like search
 *   push    esi
 *   mov     esi, [esp+0x0c]
 *   test    esi, esi
 *   je      .ret
 *   mov     edx, [esp+8]
 *   push    edi
 *   mov     edi, edx
 *   or      ecx, -1
 *   xor     eax, eax
 *   add     edx, esi
 *   repne   scasb
 *   not     ecx
 *   push    ecx
 *   push    edx
 *   push    esi
 *   call    F
 *   add     esp, 0x0c
 *   pop     edi
 * .ret:
 *   pop     esi
 *   ret
 */
extern int func_004ca0a0(void *, const char *, int);
extern unsigned int strlen(const char *);
#pragma intrinsic(strlen)
void StrSearchCall_004c89b0(char *arg1, int arg2) {
    if (arg2 == 0) return;
    func_004ca0a0(arg1 + arg2, arg1, strlen(arg1) + 1);
}

/* @addr 0x004c9800 (50b)
 *   push    edi
 *   mov     ecx, 0x40
 *   xor     eax, eax
 *   mov     edi, 0x00f9f8c0
 *   rep     stosd
 *   stosb
 *   xor     eax, eax
 *   pop     edi
 *   mov     [0x00f9fac8], eax
 *   mov     [0x00fa0dc4], eax
 *   mov     [0x00f9facc], eax
 *   mov     [0x00f9fad0], eax
 *   mov     [0x00f9fad4], eax
 *   mov     [0x00f9fad8], eax
 *   ret
 */
extern unsigned int g_state_00f9fac8;
extern unsigned int g_state_00fa0dc4;
extern unsigned int g_state_00f9facc;
extern unsigned int g_state_00f9fad0;
extern unsigned int g_state_00f9fad4;
extern unsigned int g_state_00f9fad8;
extern unsigned int g_data_00f9f8c0;
extern void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
void InitGlobalsAndZero_004c9800(void) {
    memset(&g_data_00f9f8c0, 0, 0x40 * 4 + 1);
    g_state_00f9fac8 = 0;
    g_state_00fa0dc4 = 0;
    g_state_00f9facc = 0;
    g_state_00f9fad0 = 0;
    g_state_00f9fad4 = 0;
    g_state_00f9fad8 = 0;
}

/* @addr 0x004cc2b0 (43b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [g_state_00fa0ee0]
 *   cmp     eax, ecx
 *   jb      +3
 *   xor     eax, eax
 *   ret
 *   mov     ecx, eax
 *   and     eax, 0x1f
 *   sar     ecx, 5
 *   lea     edx, [eax + eax*8]
 *   mov     eax, [ecx*4 + 0x00fa0de0]
 *   mov     al, byte ptr [eax + edx + 4]
 *   and     eax, 0x40
 *   ret
 */
extern unsigned int g_state_00fa0ee0;
extern unsigned int g_table_00fa0de0[];
int TestHandleBit_004cc2b0(int handle) {
    int hi;
    int lo;
    unsigned char *base;
    if ((unsigned int)handle >= g_state_00fa0ee0) return 0;
    hi = handle >> 5;
    lo = handle & 0x1f;
    base = (unsigned char *)g_table_00fa0de0[hi];
    return base[lo * 9 * 4 + 4] & 0x40;
}
