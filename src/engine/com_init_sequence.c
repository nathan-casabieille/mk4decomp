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

extern void (__stdcall *g_iat_004d2210)(int, int, int);

extern int g_renderer3_surface_active;
extern void *g_lock_0058c874;
extern int g_renderer5_surface_active;
extern void *g_lock_0058c8f4;

extern void Renderer3_EndScene_SW_FS(void);
extern void ComRelease_004afb10(void);
extern void ComReleasePair_004afcd0(void);
extern void DDraw3_CreateSurface(int);
extern void ComReleaseCapture_004afb50(void);
extern void DSoundBufferInit146_004afa60(void);

extern void Renderer5_EndScene_SW_FS_Hi(void);
extern void ComRelease_004b0340(void);
extern void ComReleasePair_004b0500(void);
extern void DDraw5_CreateSurface(int);
extern void ComReleaseCapture_004b0380(void);
extern void DSoundBufferInit146_004b0290(void);

/* @addr 0x004afa10 */
void DDraw3_Cleanup(void) {
    void *state;
    Renderer3_EndScene_SW_FS();
    ComRelease_004afb10();
    ComReleasePair_004afcd0();
    DDraw3_CreateSurface(0);
    ComReleaseCapture_004afb50();
    DSoundBufferInit146_004afa60();
    state = g_renderer3_surface_active;
    g_lock_0058c874 = (void *)0;
    if (state != 0) {
        g_iat_004d2210(0, 0, 1);
    }
    g_renderer3_surface_active = (void *)0;
}

/* @addr 0x004b0240 */
void DDraw5_Cleanup(void) {
    void *state;
    Renderer5_EndScene_SW_FS_Hi();
    ComRelease_004b0340();
    ComReleasePair_004b0500();
    DDraw5_CreateSurface(0);
    ComReleaseCapture_004b0380();
    DSoundBufferInit146_004b0290();
    state = g_renderer5_surface_active;
    g_lock_0058c8f4 = (void *)0;
    if (state != 0) {
        g_iat_004d2210(0, 0, 1);
    }
    g_renderer5_surface_active = (void *)0;
}
