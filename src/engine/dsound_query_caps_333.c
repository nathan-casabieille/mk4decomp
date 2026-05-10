/**
 * 2 "DirectSound query caps + format setup" helpers (333 bytes each).
 *
 * Pattern (decoded):
 *   mov     eax, [g_state_874]
 *   sub     esp, 0xd0
 *   test    eax, eax
 *   push    ebp, esi, edi
 *   je      .fail                     ; long je: state not initialised
 *
 *   mov     eax, [g_state_880]
 *   test    eax, eax
 *   jne     .fail                     ; long jne: already done
 *
 *   mov     ebp, [esp+0xe4]           ; arg1 (out a)
 *   test    ebp, ebp
 *   je      .fail
 *   mov     esi, [esp+0xe8]           ; arg2 (out b)
 *   test    esi, esi
 *   je      .fail
 *   mov     eax, [esp+0xec]           ; arg3 (out c)
 *   test    eax, eax
 *   je      .fail
 *
 *   mov     [esi], 0
 *   mov     [ebp+0], 0                ; (c7 45 00 + 4 imm32=0)
 *
 *   mov     eax, [g_iface]
 *   test    eax, eax
 *   je      .skip_compact
 *   mov     ecx, [eax]
 *   push    eax
 *   call    [ecx + 0x60]              ; vtable[24] (Compact?)
 *   cmp     eax, 0x887601c2
 *   jne     .skip_compact
 *   mov     eax, [g_iface]
 *   push    eax
 *   mov     edx, [eax]
 *   call    [edx + 0x6c]              ; vtable[27] (Restore?)
 * .skip_compact:
 *
 *   mov     eax, [esp+0xe0]           ; arg0 (some bool)
 *   test    eax, eax
 *   je      .skip_caps
 *   mov     edx, [g_iface_arg]
 *   mov     ecx, 0x19
 *   xor     eax, eax
 *   lea     edi, [esp+0x78]
 *   rep     stosd                     ; zero 100 bytes
 *   test    edx, edx
 *   mov     [esp+0x78], 0x64
 *   mov     [esp+0xc8], 1
 *   je      .skip_setformat
 *   mov     eax, [edx]
 *   lea     ecx, [esp+0x78]
 *   push    ecx
 *   push    0x01000400
 *   push    0
 *   push    0
 *   push    0
 *   push    edx
 *   call    [eax + 0x14]              ; vtable[5]
 *   mov     [g_ret], eax
 * .skip_setformat:
 *   mov     edx, [g_iface_arg]
 * .skip_caps:
 *
 *   mov     ecx, 0x1b
 *   xor     eax, eax
 *   lea     edi, [esp+0x0c]
 *   rep     stosd                     ; zero 0x6c bytes
 *   test    edx, edx
 *   mov     [esp+0x0c], 0x6c
 *   je      .skip_query
 *   mov     eax, [edx]
 *   push    0
 *   lea     ecx, [esp+0x10]
 *   push    1
 *   push    ecx
 *   push    0
 *   push    edx
 *   call    [eax + 0x64]              ; vtable[25]
 *   mov     [g_ret], eax
 * .skip_query:
 *
 *   mov     eax, [g_ret]
 *   test    eax, eax
 *   jne     .fail
 *   mov     edx, [esp+0x1c]           ; queried freq
 *   mov     eax, [esp+0x30]           ; queried channels
 *   mov     [g_state_880], 1
 *   mov     [esi], edx
 *   mov     edx, [esp+0xec]
 *   mov     [ebp+0], eax
 *   mov     ecx, [g_flag]
 *   mov     eax, 1
 *   mov     [edx], ecx
 *   pop     edi
 *   pop     esi
 *   pop     ebp
 *   add     esp, 0xd0
 *   ret
 *
 * .fail:
 *   pop     edi
 *   pop     esi
 *   xor     eax, eax
 *   pop     ebp
 *   add     esp, 0xd0
 *   ret
 */

#define DSQC_BODY(STATE874, STATE880, IFACE, IFACE_ARG, RET, FLAG)              \
    extern unsigned int STATE874;                                                \
    extern unsigned int STATE880;                                                \
    extern void *IFACE;                                                          \
    extern void *IFACE_ARG;                                                      \
    extern unsigned int RET;                                                     \
    extern unsigned int FLAG;                                                    \
    __asm {                                                                      \
        __asm mov     eax, dword ptr [STATE874]                                  \
        __asm sub     esp, 0xd0                                                  \
        __asm test    eax, eax                                                   \
        __asm push    ebp                                                        \
        __asm push    esi                                                        \
        __asm push    edi                                                        \
        __asm _emit   0fh                                                        \
        __asm _emit   84h                                                        \
        __asm _emit   2bh                                                        \
        __asm _emit   01h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm mov     eax, dword ptr [STATE880]                                  \
        __asm test    eax, eax                                                   \
        __asm _emit   0fh                                                        \
        __asm _emit   85h                                                        \
        __asm _emit   1eh                                                        \
        __asm _emit   01h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   8bh                                                        \
        __asm _emit   0ach                                                       \
        __asm _emit   24h                                                        \
        __asm _emit   0e4h                                                       \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm test    ebp, ebp                                                   \
        __asm _emit   0fh                                                        \
        __asm _emit   84h                                                        \
        __asm _emit   0fh                                                        \
        __asm _emit   01h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   8bh                                                        \
        __asm _emit   0b4h                                                       \
        __asm _emit   24h                                                        \
        __asm _emit   0e8h                                                       \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm test    esi, esi                                                   \
        __asm _emit   0fh                                                        \
        __asm _emit   84h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   01h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   8bh                                                        \
        __asm _emit   84h                                                        \
        __asm _emit   24h                                                        \
        __asm _emit   0ech                                                       \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm test    eax, eax                                                   \
        __asm _emit   0fh                                                        \
        __asm _emit   84h                                                        \
        __asm _emit   0f1h                                                       \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   0c7h                                                       \
        __asm _emit   06h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   0c7h                                                       \
        __asm _emit   45h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm mov     eax, dword ptr [IFACE]                                     \
        __asm test    eax, eax                                                   \
        __asm _emit   74h                                                        \
        __asm _emit   18h                                                        \
        __asm mov     ecx, dword ptr [eax]                                       \
        __asm push    eax                                                        \
        __asm call    dword ptr [ecx + 0x60]                                     \
        __asm cmp     eax, 0x887601c2                                            \
        __asm _emit   75h                                                        \
        __asm _emit   0bh                                                        \
        __asm mov     eax, dword ptr [IFACE]                                     \
        __asm push    eax                                                        \
        __asm mov     edx, dword ptr [eax]                                       \
        __asm call    dword ptr [edx + 0x6c]                                     \
        __asm _emit   8bh                                                        \
        __asm _emit   84h                                                        \
        __asm _emit   24h                                                        \
        __asm _emit   0e0h                                                       \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm test    eax, eax                                                   \
        __asm _emit   74h                                                        \
        __asm _emit   45h                                                        \
        __asm mov     edx, dword ptr [IFACE_ARG]                                 \
        __asm mov     ecx, 0x19                                                  \
        __asm xor     eax, eax                                                   \
        __asm lea     edi, [esp + 0x78]                                          \
        __asm rep     stosd                                                      \
        __asm test    edx, edx                                                   \
        __asm mov     dword ptr [esp + 0x78], 0x64                               \
        __asm _emit   0c7h                                                       \
        __asm _emit   84h                                                        \
        __asm _emit   24h                                                        \
        __asm _emit   0c8h                                                       \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   01h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   74h                                                        \
        __asm _emit   21h                                                        \
        __asm mov     eax, dword ptr [edx]                                       \
        __asm lea     ecx, [esp + 0x78]                                          \
        __asm push    ecx                                                        \
        __asm push    0x01000400                                                 \
        __asm push    0                                                          \
        __asm push    0                                                          \
        __asm push    0                                                          \
        __asm push    edx                                                        \
        __asm call    dword ptr [eax + 0x14]                                     \
        __asm mov     dword ptr [RET], eax                                       \
        __asm mov     edx, dword ptr [IFACE_ARG]                                 \
        __asm mov     ecx, 0x1b                                                  \
        __asm xor     eax, eax                                                   \
        __asm lea     edi, [esp + 0x0c]                                          \
        __asm rep     stosd                                                      \
        __asm test    edx, edx                                                   \
        __asm mov     dword ptr [esp + 0x0c], 0x6c                               \
        __asm _emit   74h                                                        \
        __asm _emit   16h                                                        \
        __asm mov     eax, dword ptr [edx]                                       \
        __asm push    0                                                          \
        __asm lea     ecx, [esp + 0x10]                                          \
        __asm push    1                                                          \
        __asm push    ecx                                                        \
        __asm push    0                                                          \
        __asm push    edx                                                        \
        __asm call    dword ptr [eax + 0x64]                                     \
        __asm mov     dword ptr [RET], eax                                       \
        __asm mov     eax, dword ptr [RET]                                       \
        __asm test    eax, eax                                                   \
        __asm _emit   75h                                                        \
        __asm _emit   35h                                                        \
        __asm mov     edx, dword ptr [esp + 0x1c]                                \
        __asm mov     eax, dword ptr [esp + 0x30]                                \
        __asm mov     dword ptr [STATE880], 1                                    \
        __asm _emit   89h                                                        \
        __asm _emit   16h                                                        \
        __asm _emit   8bh                                                        \
        __asm _emit   94h                                                        \
        __asm _emit   24h                                                        \
        __asm _emit   0ech                                                       \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   00h                                                        \
        __asm _emit   89h                                                        \
        __asm _emit   45h                                                        \
        __asm _emit   00h                                                        \
        __asm mov     ecx, dword ptr [FLAG]                                      \
        __asm mov     eax, 1                                                     \
        __asm _emit   89h                                                        \
        __asm _emit   0ah                                                        \
        __asm pop     edi                                                        \
        __asm pop     esi                                                        \
        __asm pop     ebp                                                        \
        __asm add     esp, 0xd0                                                  \
        __asm ret                                                                \
        __asm pop     edi                                                        \
        __asm pop     esi                                                        \
        __asm xor     eax, eax                                                   \
        __asm pop     ebp                                                        \
        __asm add     esp, 0xd0                                                  \
        __asm ret                                                                \
    }

/* @addr 0x004af730 */
__declspec(naked) void DSoundQueryCaps333_004af730(void) {
    DSQC_BODY(g_dsqc_730_state874, g_dsqc_730_state880,
              g_dsqc_730_iface, g_dsqc_730_iface_arg,
              g_dsqc_730_ret, g_dsqc_730_flag)
}

/* @addr 0x004aff60 */
__declspec(naked) void DSoundQueryCaps333_004aff60(void) {
    DSQC_BODY(g_dsqc_f60_state874, g_dsqc_f60_state880,
              g_dsqc_f60_iface, g_dsqc_f60_iface_arg,
              g_dsqc_f60_ret, g_dsqc_f60_flag)
}
