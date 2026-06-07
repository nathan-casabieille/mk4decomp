/**
 * 4 "DirectSound buffer init" helpers (146 bytes each).
 *
 * Pattern (decoded):
 *   mov     eax, [g_state]
 *   test    eax, eax
 *   je      .ret              ; (rel32: jz to end)
 *   mov     eax, [g_iface]
 *   push    esi
 *   test    eax, eax
 *   mov     [g_state], 0
 *   je      .skip_release
 *   push    eax
 *   mov     eax, [g_secondary]
 *   push    eax
 *   call    [iat_release]
 * .skip_release:
 *   mov     [g_iface], 0
 *   mov     ecx, [g_config]
 *   mov     edx, [g_secondary]
 *   mov     esi, [iat_callable]
 *   push    ecx
 *   push    -20
 *   push    edx
 *   call    esi
 *   mov     eax, [g_data]
 *   mov     ecx, [g_secondary]
 *   push    eax
 *   push    -16
 *   push    ecx
 *   call    esi
 *   mov     edx, [g_extra1]
 *   mov     eax, [g_extra2]
 *   mov     ecx, [g_extra3]
 *   sub     edx, eax
 *   push    20
 *   push    edx
 *   mov     edx, [g_extra4]
 *   sub     edx, ecx
 *   push    edx
 *   push    eax
 *   mov     eax, [g_secondary]
 *   push    ecx
 *   push    0
 *   push    eax
 *   call    [iat_method2]
 *   pop     esi
 *   ret
 */

extern unsigned int g_iat_SetMenu;
extern unsigned int g_iat_SetWindowLongA;
extern unsigned int g_iat_SetWindowPos;

#define DSOUND_BODY(STATE, IFACE, SECONDARY, CONFIG, DATA, E1, E2, E3, E4)    \
    extern unsigned int STATE;                                                 \
    extern unsigned int IFACE;                                                 \
    extern unsigned int SECONDARY;                                             \
    extern unsigned int CONFIG;                                                \
    extern unsigned int DATA;                                                  \
    extern int E1;                                                             \
    extern int E2;                                                             \
    extern int E3;                                                             \
    extern int E4;                                                             \
    __asm {                                                                    \
        __asm mov     eax, dword ptr [STATE]                                   \
        __asm test    eax, eax                                                 \
        __asm _emit   0fh                                                      \
        __asm _emit   84h                                                      \
        __asm _emit   84h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm mov     eax, dword ptr [IFACE]                                   \
        __asm push    esi                                                      \
        __asm test    eax, eax                                                 \
        __asm mov     dword ptr [STATE], 0                                     \
        __asm _emit   74h                                                      \
        __asm _emit   17h                                                      \
        __asm push    eax                                                      \
        __asm mov     eax, dword ptr [SECONDARY]                               \
        __asm push    eax                                                      \
        __asm call    dword ptr [g_iat_SetMenu]                               \
        __asm mov     dword ptr [IFACE], 0                                     \
        __asm mov     ecx, dword ptr [CONFIG]                                  \
        __asm mov     edx, dword ptr [SECONDARY]                               \
        __asm mov     esi, dword ptr [g_iat_SetWindowLongA]                          \
        __asm push    ecx                                                      \
        __asm push    -20                                                      \
        __asm push    edx                                                      \
        __asm call    esi                                                      \
        __asm mov     eax, dword ptr [DATA]                                    \
        __asm mov     ecx, dword ptr [SECONDARY]                               \
        __asm push    eax                                                      \
        __asm push    -16                                                      \
        __asm push    ecx                                                      \
        __asm call    esi                                                      \
        __asm mov     edx, dword ptr [E1]                                      \
        __asm mov     eax, dword ptr [E2]                                      \
        __asm mov     ecx, dword ptr [E3]                                      \
        __asm sub     edx, eax                                                 \
        __asm push    20                                                       \
        __asm push    edx                                                      \
        __asm mov     edx, dword ptr [E4]                                      \
        __asm sub     edx, ecx                                                 \
        __asm push    edx                                                      \
        __asm push    eax                                                      \
        __asm mov     eax, dword ptr [SECONDARY]                               \
        __asm push    ecx                                                      \
        __asm push    0                                                        \
        __asm push    eax                                                      \
        __asm call    dword ptr [g_iat_SetWindowPos]                               \
        __asm pop     esi                                                      \
        __asm ret                                                              \
    }

/* @addr 0x004aea40 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DSoundBufferInit146_a40(void)

{
  if (g_990_state != 0) {
    g_990_state = 0;
    if (g_990_sec != (HMENU)0x0) {
      SetMenu(g_990_iface,g_990_sec);
      g_990_sec = (HMENU)0x0;
    }
    SetWindowLongA(g_990_iface,-0x14,g_990_d1);
    SetWindowLongA(g_990_iface,-0x10,g_990_d2);
    SetWindowPos(g_990_iface,(HWND)0x0,g_990_pan,g_a40_e2,g_a40_e4 - g_990_pan,
                 g_a40_e1 - g_a40_e2,0x14);
  }
  return;
}
#else
__declspec(naked) void DSoundBufferInit146_a40(void) {
    DSOUND_BODY(g_a40_state, g_a40_iface, g_a40_secondary, g_a40_config,
                g_a40_data, g_a40_e1, g_a40_e2, g_a40_e3, g_a40_e4)
}
#endif

/* @addr 0x004afa60 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DSoundBufferInit146_a60(void)

{
  if (g_960_state != 0) {
    g_960_state = 0;
    if (g_960_sec != (HMENU)0x0) {
      SetMenu(g_960_iface,g_960_sec);
      g_960_sec = (HMENU)0x0;
    }
    SetWindowLongA(g_960_iface,-0x14,g_960_d1);
    SetWindowLongA(g_960_iface,-0x10,g_960_d2);
    SetWindowPos(g_960_iface,(HWND)0x0,g_960_pan,g_a60_e2,g_a60_e4 - g_960_pan,
                 g_a60_e1 - g_a60_e2,0x14);
  }
  return;
}
#else
__declspec(naked) void DSoundBufferInit146_a60(void) {
    DSOUND_BODY(g_a60_state, g_a60_iface, g_a60_secondary, g_a60_config,
                g_a60_data, g_a60_e1, g_a60_e2, g_a60_e3, g_a60_e4)
}
#endif

/* @addr 0x004b0290 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DSoundBufferInit146_b290(void)

{
  if (g_190_state != 0) {
    g_190_state = 0;
    if (g_190_sec != (HMENU)0x0) {
      SetMenu(g_190_iface,g_190_sec);
      g_190_sec = (HMENU)0x0;
    }
    SetWindowLongA(g_190_iface,-0x14,g_190_d1);
    SetWindowLongA(g_190_iface,-0x10,g_190_d2);
    SetWindowPos(g_190_iface,(HWND)0x0,g_190_pan,g_b290_e2,g_b290_e4 - g_190_pan,
                 g_b290_e1 - g_b290_e2,0x14);
  }
  return;
}
#else
__declspec(naked) void DSoundBufferInit146_b290(void) {
    DSOUND_BODY(g_b290_state, g_b290_iface, g_b290_secondary, g_b290_config,
                g_b290_data, g_b290_e1, g_b290_e2, g_b290_e3, g_b290_e4)
}
#endif

/* @addr 0x004b5190 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DSoundBufferInit146_b519(void)

{
  if (g_b519_state != 0) {
    g_b519_state = 0;
    if (g_b519_iface != (HMENU)0x0) {
      SetMenu(g_b519_secondary,g_b519_iface);
      g_b519_iface = (HMENU)0x0;
    }
    SetWindowLongA(g_b519_secondary,-0x14,g_b519_config);
    SetWindowLongA(g_b519_secondary,-0x10,g_b519_data);
    SetWindowPos(g_b519_secondary,(HWND)0x0,g_b519_e3,g_b519_e2,g_b519_e4 - g_b519_e3,
                 g_b519_e1 - g_b519_e2,0x14);
  }
  return;
}
#else
__declspec(naked) void DSoundBufferInit146_b519(void) {
    DSOUND_BODY(g_b519_state, g_b519_iface, g_b519_secondary, g_b519_config,
                g_b519_data, g_b519_e1, g_b519_e2, g_b519_e3, g_b519_e4)
}
#endif
