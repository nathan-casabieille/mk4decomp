/**
 * 2 "two-gate COM call with refcount capture" helpers (39 bytes).
 *
 * Pattern:
 *   mov     eax, [g_X]
 *   test    eax, eax
 *   je      .ret
 *   call    Setup
 *   mov     eax, [g_Y]                ; iface
 *   test    eax, eax
 *   je      .ret
 *   mov     ecx, [eax]
 *   push    1
 *   push    0
 *   push    eax
 *   call    [ecx + 0x2c]              ; vtable[11]
 *   mov     [g_Z], eax                ; capture refcount
 * .ret:
 *   ret
 */

extern unsigned int g_state_0058c874;
extern unsigned int g_state_0058c8f4;
extern void *g_comptr_0058c864;
extern void *g_comptr_0058c8e4;
extern unsigned int g_comret_0058c878;
extern unsigned int g_comret_0058c8f8;

extern void Renderer3_EndScene_SW_FS(void);
extern void Renderer5_EndScene_SW_FS_Hi(void);

/* @addr 0x004af690 */
void Renderer3_PresentFrame(void) {
    void *p;
    if (!g_state_0058c874) return;
    Renderer3_EndScene_SW_FS();
    p = g_comptr_0058c864;
    if (!p) return;
    g_comret_0058c878 = ((unsigned int (__stdcall **)(void*, int, int))(*(void**)p))[11](p, 0, 1);
}

/* @addr 0x004afec0 */
void Renderer5_PresentFrame(void) {
    void *p;
    if (!g_state_0058c8f4) return;
    Renderer5_EndScene_SW_FS_Hi();
    p = g_comptr_0058c8e4;
    if (!p) return;
    g_comret_0058c8f8 = ((unsigned int (__stdcall **)(void*, int, int))(*(void**)p))[11](p, 0, 1);
}
