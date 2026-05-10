/**
 * Restore the live config region to its compile-time defaults.
 *
 * Zero-clears g_configBuffer (588 bytes), copies 26 dwords from
 * g_resetCfgDefaults into g_resetCfgRegion as 13 interleaved pairs
 * (alternating ecx/edx), seeds 30+ individual fields with hand-picked
 * constants, then walks g_joyButtonState[16] picking the first two
 * "active" indices into g_resetCfgRegion._b68 / _b6c.
 */
#include "audio/sound.h"
#include "engine/geo.h"   /* g_joyButtonState */

/*
 * @addr 0x004acf90
 *
 * Naked + __asm: 26-dword struct copy uses an alternating
 * (edx-load, ecx-load, edx-store, ecx-store) pattern that pure C
 * struct assignment in MSVC SP3 would not interleave identically;
 * the trailing block of "individual stores" also reuses ecx/edx/eax
 * across many globals in a way no natural C body produces.
 */
__declspec(naked) void ResetConfigToDefaults(void)
{
    __asm {
        push    ebx
        push    edi
        mov     edx, dword ptr [g_resetCfgDefaults + 0x4]
        mov     ecx, 0x93
        xor     eax, eax
        mov     edi, offset g_configBuffer
        rep     stosd
        mov     ecx, dword ptr [g_resetCfgDefaults]
        mov     dword ptr [g_resetCfgRegion + 0x38], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0xc]
        mov     dword ptr [g_resetCfgRegion + 0x34], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x8]
        mov     dword ptr [g_resetCfgRegion + 0x40], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x14]
        mov     dword ptr [g_resetCfgRegion + 0x3c], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x10]
        mov     dword ptr [g_resetCfgRegion + 0x48], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x1c]
        mov     dword ptr [g_resetCfgRegion + 0x44], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x18]
        mov     dword ptr [g_resetCfgRegion + 0x50], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x24]
        mov     dword ptr [g_resetCfgRegion + 0x4c], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x20]
        mov     dword ptr [g_resetCfgRegion + 0x58], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x2c]
        mov     dword ptr [g_resetCfgRegion + 0x54], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x28]
        mov     dword ptr [g_resetCfgRegion + 0x60], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x34]
        mov     dword ptr [g_resetCfgRegion + 0x5c], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x30]
        mov     dword ptr [g_resetCfgRegion + 0x68], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x3c]
        mov     dword ptr [g_resetCfgRegion + 0x64], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x38]
        mov     dword ptr [g_resetCfgRegion + 0x70], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x44]
        mov     dword ptr [g_resetCfgRegion + 0x6c], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x40]
        mov     dword ptr [g_resetCfgRegion + 0x78], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x4c]
        mov     dword ptr [g_resetCfgRegion + 0x74], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x48]
        mov     dword ptr [g_resetCfgRegion + 0x80], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x54]
        mov     dword ptr [g_resetCfgRegion + 0x7c], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x50]
        mov     dword ptr [g_resetCfgRegion + 0x88], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x5c]
        mov     dword ptr [g_resetCfgRegion + 0x84], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x58]
        mov     dword ptr [g_resetCfgRegion + 0x90], edx
        mov     edx, dword ptr [g_resetCfgDefaults + 0x64]
        mov     dword ptr [g_resetCfgRegion + 0x8c], ecx
        mov     ecx, dword ptr [g_resetCfgDefaults + 0x60]
        mov     dword ptr [g_resetCfgRegion + 0x98], edx
        mov     dword ptr [g_resetCfgRegion + 0x94], ecx
        mov     ecx, 0x64
        mov     dword ptr [g_resetCfgRegion + 0x4], ecx
        mov     dword ptr [g_resetCfgRegion + 0xc], ecx
        or      edi, -1
        mov     eax, 1
        mov     edx, 3
        mov     ecx, 2
        or      ebx, -1
        mov     dword ptr [g_configChecksum], eax
        mov     dword ptr [g_resetCfgRegion + 0x0], eax
        mov     dword ptr [g_resetCfgRegion + 0x8], eax
        mov     dword ptr [g_resetCfgRegion + 0x20], 0x4
        mov     dword ptr [g_resetCfgRegion + 0x24], eax
        mov     dword ptr [g_resetCfgRegion + 0x1c], edx
        mov     dword ptr [g_resetCfgRegion + 0x18], ecx
        mov     dword ptr [g_resetCfgRegion + 0x28], eax
        mov     dword ptr [g_resetCfgRegion + 0x2c], ecx
        mov     dword ptr [g_resetCfgRegion + 0x30], eax
        mov     dword ptr [g_resetCfgRegion + 0x10], 0x32
        mov     dword ptr [g_resetCfgRegion + 0x14], 0x0
        mov     dword ptr [g_resetCfgRegion + 0xe8], edi
        mov     dword ptr [g_resetCfgRegion + 0xe4], ebx
        mov     dword ptr [g_resetCfgRegion + 0xa0], eax
        mov     dword ptr [g_resetCfgRegion + 0x9c], eax
        mov     eax, 5
        mov     dword ptr [g_resetCfgRegion + 0xc0], eax
        mov     dword ptr [g_resetCfgRegion + 0xbc], eax
        mov     eax, 6
        mov     dword ptr [g_resetCfgRegion + 0xa8], ecx
        mov     dword ptr [g_resetCfgRegion + 0xd8], eax
        mov     dword ptr [g_resetCfgRegion + 0xd4], eax
        mov     eax, 7
        mov     dword ptr [g_resetCfgRegion + 0xa4], ecx
        mov     dword ptr [g_resetCfgRegion + 0xe0], eax
        mov     dword ptr [g_resetCfgRegion + 0xdc], eax
        mov     eax, 8
        mov     dword ptr [g_resetCfgRegion + 0xb0], edx
        mov     dword ptr [g_resetCfgRegion + 0xc8], eax
        mov     dword ptr [g_resetCfgRegion + 0xc4], eax
        mov     eax, 9
        mov     dword ptr [g_resetCfgRegion + 0xac], edx
        mov     dword ptr [g_resetCfgRegion + 0xd0], eax
        mov     dword ptr [g_resetCfgRegion + 0xcc], eax
        mov     dword ptr [g_resetCfgRegion + 0xb8], 0x4
        mov     dword ptr [g_resetCfgRegion + 0xb4], 0x4
        xor     eax, eax
joy_loop:
        mov     cl, byte ptr [eax + g_joyButtonState]
        test    cl, cl
        je      SHORT joy_inc
        cmp     ebx, -1
        jne     SHORT try_edi
        mov     ebx, eax
        jmp     SHORT joy_inc
try_edi:
        cmp     edi, -1
        jne     SHORT joy_done
        mov     edi, eax
        mov     dword ptr [g_resetCfgRegion + 0xe8], edi
joy_inc:
        inc     eax
        cmp     eax, 0x10
        jl      SHORT joy_loop
joy_done:
        mov     dword ptr [g_resetCfgRegion + 0xe4], ebx
        pop     edi
        pop     ebx
        ret
    }
}
