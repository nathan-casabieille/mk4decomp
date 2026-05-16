/**
 * 2 "COM init multi-call sequence" helpers (77 bytes each).
 *
 * Pattern:
 *   call    Step1
 *   call    Step2
 *   call    Step3
 *   push    0
 *   call    Step4                                  ; 1-arg
 *   add     esp, 4
 *   call    Step5
 *   call    Step6
 *   mov     eax, [g_state]
 *   mov     [g_lock], 0
 *   test    eax, eax
 *   je      .done
 *   push    1
 *   push    0
 *   push    0
 *   call    [iat]                                  ; release/reset
 *   mov     [g_state], 0
 * .done:
 *   ret
 *
 * The mov [g_state] AND mov [g_lock]=0 happen unconditionally; if
 * state was set, an external IAT call clears state first.
 */

extern void *g_iat_004d2210;

extern void *g_state_0058c884;
extern void *g_lock_0058c874;
extern void *g_state_0058c904;
extern void *g_lock_0058c8f4;

extern void Renderer3_EndScene_SW_FS(void);
extern void ComRelease_004afb10(void);
extern void ComReleasePair_004afcd0(void);
extern void DSoundModeSetup_004afd10(int);
extern void ComReleaseCapture_004afb50(void);
extern void DSoundBufferInit146_004afa60(void);

extern void Renderer5_EndScene_SW_FS_Hi(void);
extern void ComRelease_004b0340(void);
extern void ComReleasePair_004b0500(void);
extern void DSoundModeSetup_004b0540(int);
extern void ComReleaseCapture_004b0380(void);
extern void DSoundBufferInit146_004b0290(void);

/* @addr 0x004afa10 */
__declspec(naked) void ComInitSequence_004afa10(void) {
    __asm {
        call    Renderer3_EndScene_SW_FS
        call    ComRelease_004afb10
        call    ComReleasePair_004afcd0
        push    0
        call    DSoundModeSetup_004afd10
        add     esp, 4
        call    ComReleaseCapture_004afb50
        call    DSoundBufferInit146_004afa60
        mov     eax, dword ptr [g_state_0058c884]
        mov     dword ptr [g_lock_0058c874], 0
        test    eax, eax
        _emit   74h
        _emit   0ch
        push    1
        push    0
        push    0
        call    dword ptr [g_iat_004d2210]
        mov     dword ptr [g_state_0058c884], 0
        ret
    }
}

/* @addr 0x004b0240 */
__declspec(naked) void ComInitSequence_004b0240(void) {
    __asm {
        call    Renderer5_EndScene_SW_FS_Hi
        call    ComRelease_004b0340
        call    ComReleasePair_004b0500
        push    0
        call    DSoundModeSetup_004b0540
        add     esp, 4
        call    ComReleaseCapture_004b0380
        call    DSoundBufferInit146_004b0290
        mov     eax, dword ptr [g_state_0058c904]
        mov     dword ptr [g_lock_0058c8f4], 0
        test    eax, eax
        _emit   74h
        _emit   0ch
        push    1
        push    0
        push    0
        call    dword ptr [g_iat_004d2210]
        mov     dword ptr [g_state_0058c904], 0
        ret
    }
}
