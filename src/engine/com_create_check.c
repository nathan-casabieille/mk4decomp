/**
 * 2 "COM-style create + null-check + bool return" helpers (28 bytes).
 *
 * Calls DirectDrawCreate (via IAT thunk) which fills the IDirectDraw*
 * out-slot, then returns (slot != NULL) as a bool.
 *
 * The creator is declared __stdcall so MSVC omits the post-call
 * `add esp, 0Ch`; the original binary has no stack cleanup after
 * the call, so cdecl + manual sub would not match.
 */
#include "engine/com.h"

extern Mk4ComObj *g_comptr_0058c860;
extern Mk4ComObj *g_comptr_0058c8e0;
extern int __stdcall func_004d12cc(int a, Mk4ComObj **out, int b);

/* @addr 0x004afb30 */
int DDraw3_Create(void) {
    func_004d12cc(0, &g_comptr_0058c860, 0);
    return g_comptr_0058c860 != 0;
}

/* @addr 0x004b0360 */
int DDraw5_Create(void) {
    func_004d12cc(0, &g_comptr_0058c8e0, 0);
    return g_comptr_0058c8e0 != 0;
}
