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

extern unsigned int g_iat_004d2178;
extern unsigned int g_iat_004d21a0;
extern unsigned int g_iat_004d2190;

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
        __asm call    dword ptr [g_iat_004d2178]                               \
        __asm mov     dword ptr [IFACE], 0                                     \
        __asm mov     ecx, dword ptr [CONFIG]                                  \
        __asm mov     edx, dword ptr [SECONDARY]                               \
        __asm mov     esi, dword ptr [g_iat_004d21a0]                          \
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
        __asm call    dword ptr [g_iat_004d2190]                               \
        __asm pop     esi                                                      \
        __asm ret                                                              \
    }

/* @addr 0x004aea40 */

__declspec(naked) void DSoundBufferInit146_004aea40(void) {
    DSOUND_BODY(g_a40_state, g_a40_iface, g_a40_secondary, g_a40_config,
                g_a40_data, g_a40_e1, g_a40_e2, g_a40_e3, g_a40_e4)
}

/* @addr 0x004afa60 */
__declspec(naked) void DSoundBufferInit146_004afa60(void) {
    DSOUND_BODY(g_a60_state, g_a60_iface, g_a60_secondary, g_a60_config,
                g_a60_data, g_a60_e1, g_a60_e2, g_a60_e3, g_a60_e4)
}

/* @addr 0x004b0290 */
__declspec(naked) void DSoundBufferInit146_004b0290(void) {
    DSOUND_BODY(g_b290_state, g_b290_iface, g_b290_secondary, g_b290_config,
                g_b290_data, g_b290_e1, g_b290_e2, g_b290_e3, g_b290_e4)
}

/* @addr 0x004b5190 */
__declspec(naked) void DSoundBufferInit146_004b5190(void) {
    DSOUND_BODY(g_b519_state, g_b519_iface, g_b519_secondary, g_b519_config,
                g_b519_data, g_b519_e1, g_b519_e2, g_b519_e3, g_b519_e4)
}
