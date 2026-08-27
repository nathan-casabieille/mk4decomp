/**
 * 2 "zero g_walkCallback + three scaled slots" helpers (41 bytes).
 *
 * Both stubs emit identical bytes; the C compiler did not deduplicate
 * them.
 *
 * Pattern:
 *   mov     eax, [g_fightGroupHead]
 *   xor     ecx, ecx
 *   shl     eax, 2                    ; eax = unpacked base
 *   mov     [g_walkCallback], ecx     ; first store of zero
 *   mov     [eax + 0x78], ecx
 *   mov     ecx, [g_walkCallback]     ; reload (still zero)
 *   mov     [eax + 0x7c], ecx
 *   mov     edx, [g_walkCallback]     ; reload (still zero)
 *   mov     [eax + 0x80], edx
 *   ret
 *
 * The reloads are wasteful but match the original codegen.
 */
#include "engine/scenegraph.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x00490780 */
void ZeroThreeSlots_00490780(void) {
    u32 base = (u32)g_fightGroupHead << 2;
    g_walkCallback = 0;
    *(u32 *)MK4_PTR((base + 0x78)) = 0;
    *(u32 *)MK4_PTR((base + 0x7c)) = (u32)*(volatile void **)&g_walkCallback;
    *(u32 *)MK4_PTR((base + 0x80)) = (u32)*(volatile void **)&g_walkCallback;
}

/* @addr 0x004ac010 */
void ZeroThreeSlots_004ac010(void) {
    u32 base = (u32)g_fightGroupHead << 2;
    g_walkCallback = 0;
    *(u32 *)MK4_PTR((base + 0x78)) = 0;
    *(u32 *)MK4_PTR((base + 0x7c)) = (u32)*(volatile void **)&g_walkCallback;
    *(u32 *)MK4_PTR((base + 0x80)) = (u32)*(volatile void **)&g_walkCallback;
}
