/**
 * 2 "DirectSound axis/pan setup with clamps" helpers (123 bytes each).
 *
 * Pattern (decoded):
 *   mov     eax, [g_state]
 *   test    eax, eax
 *   je      .ret
 *   mov     eax, [g_iface]
 *   push    edi
 *   push    esi
 *   mov     esi, [iat_methodA]
 *   push    8
 *   push    -20
 *   push    eax
 *   call    esi
 *   mov     ecx, [g_iface]
 *   push    0x90000000
 *   push    -16
 *   push    ecx
 *   call    esi
 *   mov     esi, [iat_methodB]
 *   push    1
 *   call    esi
 *   cmp     eax, 0x1e0
 *   jge     .clamp1_skip
 *   mov     edi, 0x1e0
 *   jmp     .after_clamp1
 * .clamp1_skip:
 *   push    1
 *   call    esi
 *   mov     edi, eax
 * .after_clamp1:
 *   push    0
 *   call    esi
 *   cmp     eax, 0x280
 *   jge     .clamp2_skip
 *   mov     eax, 0x280
 *   jmp     .after_clamp2
 * .clamp2_skip:
 *   push    0
 *   call    esi
 * .after_clamp2:
 *   mov     edx, [g_iface]
 *   push    0x44
 *   push    edi
 *   push    eax
 *   push    0
 *   push    0
 *   push    0
 *   push    edx
 *   call    [iat_methodC]
 *   pop     esi
 *   pop     edi
 * .ret:
 *   ret
 */

extern unsigned int g_iat_SetWindowPos;
extern unsigned int g_iat_SetWindowLongA;
extern unsigned int g_iat_GetSystemMetrics;

#define DS_BODY(STATE, IFACE)                                                  \
    extern unsigned int STATE;                                                  \
    extern unsigned int IFACE;                                                 \
    __asm {                                                                     \
        __asm mov     eax, dword ptr [STATE]                                    \
        __asm test    eax, eax                                                  \
        __asm _emit   74h                                                       \
        __asm _emit   71h                                                       \
        __asm mov     eax, dword ptr [IFACE]                                    \
        __asm push    edi                                                        \
        __asm push    esi                                                        \
        __asm mov     esi, dword ptr [g_iat_SetWindowLongA]                           \
        __asm push    8                                                          \
        __asm push    -20                                                        \
        __asm push    eax                                                        \
        __asm call    esi                                                        \
        __asm mov     ecx, dword ptr [IFACE]                                    \
        __asm push    0x90000000                                                 \
        __asm push    -16                                                        \
        __asm push    ecx                                                        \
        __asm call    esi                                                        \
        __asm mov     esi, dword ptr [g_iat_GetSystemMetrics]                           \
        __asm push    1                                                          \
        __asm call    esi                                                        \
        __asm cmp     eax, 0x1e0                                                \
        __asm _emit   7dh                                                       \
        __asm _emit   07h                                                       \
        __asm mov     edi, 0x1e0                                                \
        __asm _emit   0ebh                                                      \
        __asm _emit   06h                                                       \
        __asm push    1                                                          \
        __asm call    esi                                                        \
        __asm mov     edi, eax                                                   \
        __asm push    0                                                          \
        __asm call    esi                                                        \
        __asm cmp     eax, 0x280                                                \
        __asm _emit   7dh                                                       \
        __asm _emit   07h                                                       \
        __asm mov     eax, 0x280                                                \
        __asm _emit   0ebh                                                      \
        __asm _emit   04h                                                       \
        __asm push    0                                                          \
        __asm call    esi                                                        \
        __asm mov     edx, dword ptr [IFACE]                                    \
        __asm push    0x44                                                       \
        __asm push    edi                                                        \
        __asm push    eax                                                        \
        __asm push    0                                                          \
        __asm push    0                                                          \
        __asm push    0                                                          \
        __asm push    edx                                                        \
        __asm call    dword ptr [g_iat_SetWindowPos]                                \
        __asm pop     esi                                                        \
        __asm pop     edi                                                        \
        __asm ret                                                                \
    }

/* @addr 0x004aec10 */
__declspec(naked) void DSoundSetAxisPan123_004aec10(void) {
    DS_BODY(g_dsap_c10_state, g_dsap_c10_iface)
}

/* @addr 0x004b50a0 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DSoundSetAxisPan123_004b50a0(void)

{
  int iVar1;
  int iVar2;
  
  if (g_b519_state != 0) {
    SetWindowLongA(g_b519_secondary,-0x14,8);
    SetWindowLongA(g_b519_secondary,-0x10,-0x70000000);
    iVar1 = GetSystemMetrics(1);
    if (iVar1 < 0x1e0) {
      iVar1 = 0x1e0;
    }
    else {
      iVar1 = GetSystemMetrics(1);
    }
    iVar2 = GetSystemMetrics(0);
    if (iVar2 < 0x280) {
      iVar2 = 0x280;
    }
    else {
      iVar2 = GetSystemMetrics(0);
    }
    SetWindowPos(g_b519_secondary,(HWND)0x0,0,0,iVar2,iVar1,0x44);
  }
  return;
}
#else
__declspec(naked) void DSoundSetAxisPan123_004b50a0(void) {
    DS_BODY(g_dsap_5a0_state, g_dsap_5a0_iface)
}
#endif
