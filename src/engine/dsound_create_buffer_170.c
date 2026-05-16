/**
 * 4 "DirectSound CreateSoundBuffer + setup" helpers (170 bytes each).
 *
 * Pattern (decoded):
 *   mov     eax, [g_state]
 *   test    eax, eax
 *   jne     .ret               ; already inited
 *   mov     eax, [g_iface]     ; lpDirectSound
 *   push    esi
 *   push    OFFSET g_bufdesc   ; pBufferDesc
 *   push    eax                ; this
 *   mov     [g_state], 1
 *   mov     [g_bufdesc], 0x2c  ; DSBUFFERDESC.dwSize
 *   call    [iat_create_buffer]
 *   mov     eax, [g_quality]
 *   cmp     eax, 3
 *   je      .do_setformat
 *   cmp     eax, 2
 *   jne     .skip_setformat
 * .do_setformat:
 *   mov     ecx, [g_iface]
 *   push    9
 *   push    ecx
 *   call    [iat_setformat]
 * .skip_setformat:
 *   mov     edx, [g_iface]
 *   push    OFFSET g_panstruct
 *   push    edx
 *   call    [iat_pan_setup]
 *   mov     eax, [g_iface]
 *   push    eax
 *   call    [iat_method4]
 *   mov     ecx, [g_iface]
 *   push    0
 *   push    ecx
 *   mov     [g_secondary], eax
 *   call    [iat_method5]
 *   mov     edx, [g_iface]
 *   mov     esi, [iat_method6_addr]
 *   push    -20
 *   push    edx
 *   call    esi
 *   mov     [g_data1], eax
 *   mov     eax, [g_iface]
 *   push    -16
 *   push    eax
 *   call    esi
 *   mov     [g_data2], eax
 *   pop     esi
 * .ret:
 *   ret
 */

extern void *g_iat_004d2198;   /* CreateSoundBuffer */
extern void *g_iat_004d2194;   /* SetFormat (or similar) */
extern void *g_iat_004d218c;   /* pan setup */
extern void *g_iat_004d2188;   /* method4 */
extern void *g_iat_004d2178;   /* method5 (release-and-null elsewhere) */
extern void *g_iat_004d217c;   /* method6 */

#define DSBI_BODY(STATE, IFACE, BUFDESC, QUALITY, PAN, SEC, D1, D2)            \
    extern unsigned int STATE;                                                  \
    extern void *IFACE;                                                         \
    extern unsigned int BUFDESC;                                                \
    extern unsigned int QUALITY;                                                \
    extern unsigned int PAN;                                                    \
    extern void *SEC;                                                           \
    extern unsigned int D1;                                                     \
    extern unsigned int D2;                                                     \
    __asm {                                                                     \
        __asm mov     eax, dword ptr [STATE]                                    \
        __asm test    eax, eax                                                  \
        __asm _emit   0fh                                                       \
        __asm _emit   85h                                                       \
        __asm _emit   9ch                                                       \
        __asm _emit   00h                                                       \
        __asm _emit   00h                                                       \
        __asm _emit   00h                                                       \
        __asm mov     eax, dword ptr [IFACE]                                    \
        __asm push    esi                                                       \
        __asm push    OFFSET BUFDESC                                            \
        __asm push    eax                                                       \
        __asm mov     dword ptr [STATE], 1                                      \
        __asm mov     dword ptr [BUFDESC], 0x2c                                 \
        __asm call    dword ptr [g_iat_004d2198]                                \
        __asm mov     eax, dword ptr [QUALITY]                                  \
        __asm cmp     eax, 3                                                    \
        __asm _emit   74h                                                       \
        __asm _emit   05h                                                       \
        __asm cmp     eax, 2                                                    \
        __asm _emit   75h                                                       \
        __asm _emit   0fh                                                       \
        __asm mov     ecx, dword ptr [IFACE]                                    \
        __asm push    9                                                         \
        __asm push    ecx                                                       \
        __asm call    dword ptr [g_iat_004d2194]                                \
        __asm mov     edx, dword ptr [IFACE]                                    \
        __asm push    OFFSET PAN                                                \
        __asm push    edx                                                       \
        __asm call    dword ptr [g_iat_004d218c]                                \
        __asm mov     eax, dword ptr [IFACE]                                    \
        __asm push    eax                                                       \
        __asm call    dword ptr [g_iat_004d2188]                                \
        __asm mov     ecx, dword ptr [IFACE]                                    \
        __asm push    0                                                         \
        __asm push    ecx                                                       \
        __asm mov     dword ptr [SEC], eax                                      \
        __asm call    dword ptr [g_iat_004d2178]                                \
        __asm mov     edx, dword ptr [IFACE]                                    \
        __asm mov     esi, dword ptr [g_iat_004d217c]                           \
        __asm push    -20                                                       \
        __asm push    edx                                                       \
        __asm call    esi                                                       \
        __asm mov     dword ptr [D1], eax                                       \
        __asm mov     eax, dword ptr [IFACE]                                    \
        __asm push    -16                                                       \
        __asm push    eax                                                       \
        __asm call    esi                                                       \
        __asm mov     dword ptr [D2], eax                                       \
        __asm pop     esi                                                       \
        __asm ret                                                               \
    }

/* @addr 0x004ae990 */
__declspec(naked) void R2_Init3(void) {
    DSBI_BODY(g_990_state, g_990_iface, g_990_bufdesc, g_990_qual,
              g_990_pan, g_990_sec, g_990_d1, g_990_d2)
}

/* @addr 0x004af960 */
__declspec(naked) void DDraw3_PostCreate(void) {
    DSBI_BODY(g_960_state, g_960_iface, g_960_bufdesc, g_960_qual,
              g_960_pan, g_960_sec, g_960_d1, g_960_d2)
}

/* @addr 0x004b0190 */
__declspec(naked) void DDraw5_PostCreate(void) {
    DSBI_BODY(g_190_state, g_190_iface, g_190_bufdesc, g_190_qual,
              g_190_pan, g_190_sec, g_190_d1, g_190_d2)
}

/* @addr 0x004b4f60 */
__declspec(naked) void Helper_GlideMode(void) {
    DSBI_BODY(g_f60_state, g_f60_iface, g_f60_bufdesc, g_f60_qual,
              g_f60_pan, g_f60_sec, g_f60_d1, g_f60_d2)
}
