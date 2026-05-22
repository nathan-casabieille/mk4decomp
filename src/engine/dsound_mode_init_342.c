/**
 * 2 "DirectSound mode-init with format probing" helpers (342 bytes each).
 *
 * Pattern:
 *   sub     esp, 0x90
 *   push    esi, edi
 *   ; Zero 0x6c bytes of stack scratch
 *   mov     ecx, 0x1b
 *   xor     eax, eax
 *   lea     edi, [esp+0x2c]
 *   rep     stosd
 *
 *   mov     eax, [g_iface_main]
 *   ; Init DDPIXELFORMAT-like struct on stack
 *   mov     [esp+0x2c], 0x6c
 *   test    eax, eax
 *   mov     [esp+0x30], 0x21
 *   mov     [esp+0x94], 0x4218
 *   mov     [esp+0x40], 2          ; DDPF_RGB
 *   je      .skip_call1
 *   mov     ecx, [eax]
 *   push    0
 *   lea     edx, [esp+0x30]
 *   push    OFFSET g_iface_sec     ; pointer to second iface slot
 *   push    edx
 *   push    eax
 *   call    [ecx + 0x18]            ; vtable[6]
 *   mov     [g_ret_slot], eax
 * .skip_call1:
 *   mov     eax, [g_iface_main]
 *   mov     ecx, [g_ret_slot]
 *   test    ecx, ecx
 *   je      .skip_call2
 *   test    eax, eax
 *   mov     [esp+0x40], 1          ; switch to DDPF_FOURCC
 *   je      .skip_call2
 *   mov     ecx, [eax]
 *   push    0
 *   lea     edx, [esp+0x30]
 *   push    OFFSET g_iface_sec
 *   push    edx
 *   push    eax
 *   call    [ecx + 0x18]
 *   mov     [g_ret_slot], eax
 * .skip_call2:
 *   mov     edx, [g_iface_sec]
 *   mov     [esp+8], 4
 *   test    edx, edx
 *   je      .skip_call3
 *   mov     eax, [edx]
 *   lea     ecx, [esp+8]
 *   push    OFFSET g_iface_sec3
 *   push    ecx
 *   push    edx
 *   call    [eax + 0x30]            ; vtable[12]
 *   mov     edx, [g_iface_sec]
 *   mov     [g_ret_slot], eax
 * .skip_call3:
 *   ; Zero next struct (32 bytes)
 *   mov     ecx, 8
 *   xor     eax, eax
 *   lea     edi, [esp+0xc]
 *   rep     stosd
 *
 *   test    edx, edx
 *   mov     [esp+0xc], 0x20         ; DDSURFACEDESC.dwSize
 *   je      .skip_call4
 *   mov     eax, [edx]
 *   lea     ecx, [esp+0xc]
 *   push    ecx
 *   push    edx
 *   call    [eax + 0x54]            ; vtable[21]
 *   mov     edx, [g_iface_sec]
 *   mov     [g_ret_slot], eax
 * .skip_call4:
 *   ; Examine pixel-format masks
 *   mov     eax, [esp+0x1c]         ; dwRBitMask
 *   mov     ecx, [esp+0x24]         ; dwGBitMask (?)
 *   mov     esi, [esp+0x20]         ; or whatever
 *   cmp     eax, 0xf800
 *   jne     .check_555
 *   cmp     esi, 0x7e0
 *   jne     .check_555
 *   cmp     ecx, 0x1f
 *   jne     .check_555
 *   mov     [g_flag], 1            ; 565 mode
 *   jmp     .after_format
 * .check_555:
 *   cmp     eax, 0x7c00
 *   jne     .fail
 *   cmp     esi, 0x3e0
 *   jne     .fail
 *   cmp     ecx, 0x1f
 *   jne     .fail
 *   mov     [g_flag], 0            ; 555 mode
 * .after_format:
 *   test    edx, edx
 *   je      .fail
 *   mov     eax, [g_iface_sec3]
 *   test    eax, eax
 *   je      .fail
 *   mov     eax, 1
 *   pop     edi
 *   pop     esi
 *   add     esp, 0x90
 *   ret
 * .fail:
 *   pop     edi
 *   xor     eax, eax
 *   pop     esi
 *   add     esp, 0x90
 *   ret
 */

#define DSMI_BODY(MAIN, SEC, RET, EXTRA, FLAG, SEC3)                            \
    extern unsigned int MAIN;                                                   \
    extern unsigned int SEC;                                                    \
    extern unsigned int RET;                                                    \
    extern unsigned int EXTRA;                                                  \
    extern unsigned int FLAG;                                                   \
    extern unsigned int SEC3;                                                   \
    __asm {                                                                     \
        __asm sub     esp, 0x90                                                 \
        __asm push    esi                                                       \
        __asm push    edi                                                       \
        __asm mov     ecx, 0x1b                                                 \
        __asm xor     eax, eax                                                  \
        __asm lea     edi, [esp + 0x2c]                                         \
        __asm rep     stosd                                                     \
        __asm mov     eax, dword ptr [MAIN]                                     \
        __asm mov     dword ptr [esp + 0x2c], 0x6c                              \
        __asm test    eax, eax                                                  \
        __asm mov     dword ptr [esp + 0x30], 0x21                              \
        __asm mov     dword ptr [esp + 0x94], 0x4218                            \
        __asm mov     dword ptr [esp + 0x40], 2                                 \
        __asm _emit   74h                                                       \
        __asm _emit   1ch                                                       \
        __asm mov     ecx, dword ptr [eax]                                      \
        __asm push    0                                                         \
        __asm lea     edx, [esp + 0x30]                                         \
        __asm push    OFFSET SEC                                                \
        __asm push    edx                                                       \
        __asm push    eax                                                       \
        __asm call    dword ptr [ecx + 0x18]                                    \
        __asm mov     dword ptr [RET], eax                                      \
        __asm mov     eax, dword ptr [MAIN]                                     \
        __asm mov     ecx, dword ptr [RET]                                      \
        __asm test    ecx, ecx                                                  \
        __asm _emit   74h                                                       \
        __asm _emit   23h                                                       \
        __asm test    eax, eax                                                  \
        __asm mov     dword ptr [esp + 0x40], 1                                 \
        __asm _emit   74h                                                       \
        __asm _emit   17h                                                       \
        __asm mov     ecx, dword ptr [eax]                                      \
        __asm push    0                                                         \
        __asm lea     edx, [esp + 0x30]                                         \
        __asm push    OFFSET SEC                                                \
        __asm push    edx                                                       \
        __asm push    eax                                                       \
        __asm call    dword ptr [ecx + 0x18]                                    \
        __asm mov     dword ptr [RET], eax                                      \
        __asm mov     edx, dword ptr [SEC]                                      \
        __asm mov     dword ptr [esp + 8], 4                                    \
        __asm test    edx, edx                                                  \
        __asm _emit   74h                                                       \
        __asm _emit   1bh                                                       \
        __asm mov     eax, dword ptr [edx]                                      \
        __asm lea     ecx, [esp + 8]                                            \
        __asm push    OFFSET EXTRA                                              \
        __asm push    ecx                                                       \
        __asm push    edx                                                       \
        __asm call    dword ptr [eax + 0x30]                                    \
        __asm mov     edx, dword ptr [SEC]                                      \
        __asm mov     dword ptr [RET], eax                                      \
        __asm mov     ecx, 8                                                    \
        __asm xor     eax, eax                                                  \
        __asm lea     edi, [esp + 0x0c]                                         \
        __asm rep     stosd                                                     \
        __asm test    edx, edx                                                  \
        __asm mov     dword ptr [esp + 0x0c], 0x20                              \
        __asm _emit   74h                                                       \
        __asm _emit   16h                                                       \
        __asm mov     eax, dword ptr [edx]                                      \
        __asm lea     ecx, [esp + 0x0c]                                         \
        __asm push    ecx                                                       \
        __asm push    edx                                                       \
        __asm call    dword ptr [eax + 0x54]                                    \
        __asm mov     edx, dword ptr [SEC]                                      \
        __asm mov     dword ptr [RET], eax                                      \
        __asm mov     eax, dword ptr [esp + 0x1c]                               \
        __asm mov     ecx, dword ptr [esp + 0x24]                               \
        __asm mov     esi, dword ptr [esp + 0x20]                               \
        __asm cmp     eax, 0xf800                                               \
        __asm _emit   75h                                                       \
        __asm _emit   19h                                                       \
        __asm cmp     esi, 0x7e0                                                \
        __asm _emit   75h                                                       \
        __asm _emit   11h                                                       \
        __asm cmp     ecx, 0x1f                                                 \
        __asm _emit   75h                                                       \
        __asm _emit   0ch                                                       \
        __asm mov     dword ptr [FLAG], 1                                       \
        __asm _emit   0ebh                                                      \
        __asm _emit   1eh                                                       \
        __asm cmp     eax, 0x7c00                                               \
        __asm _emit   75h                                                       \
        __asm _emit   32h                                                       \
        __asm cmp     esi, 0x3e0                                                \
        __asm _emit   75h                                                       \
        __asm _emit   2ah                                                       \
        __asm cmp     ecx, 0x1f                                                 \
        __asm _emit   75h                                                       \
        __asm _emit   25h                                                       \
        __asm mov     dword ptr [FLAG], 0                                       \
        __asm test    edx, edx                                                  \
        __asm _emit   74h                                                       \
        __asm _emit   17h                                                       \
        __asm mov     eax, dword ptr [SEC3]                                     \
        __asm test    eax, eax                                                  \
        __asm _emit   74h                                                       \
        __asm _emit   0eh                                                       \
        __asm mov     eax, 1                                                    \
        __asm pop     edi                                                       \
        __asm pop     esi                                                       \
        __asm add     esp, 0x90                                                 \
        __asm ret                                                               \
        __asm pop     edi                                                       \
        __asm xor     eax, eax                                                  \
        __asm pop     esi                                                       \
        __asm add     esp, 0x90                                                 \
        __asm ret                                                               \
    }

/* @addr 0x004afb70 */

__declspec(naked) void DDraw3_SetCooperativeLevel(void) {
    DSMI_BODY(g_dsmi_b70_main, g_dsmi_b70_sec, g_dsmi_b70_ret,
              g_dsmi_b70_extra, g_dsmi_b70_flag, g_dsmi_b70_sec3)
}

/* @addr 0x004b03a0 */
__declspec(naked) void DDraw5_SetCooperativeLevel(void) {
    DSMI_BODY(g_dsmi_3a0_main, g_dsmi_3a0_sec, g_dsmi_3a0_ret,
              g_dsmi_3a0_extra, g_dsmi_3a0_flag, g_dsmi_3a0_sec3)
}
