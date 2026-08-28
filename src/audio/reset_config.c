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
#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* @addr 0x004acf90 (634b) - NATIVE twin; the matching build keeps the
 * __asm body below (an alternating-register copy MSVC will not reproduce).
 *
 * The config reset: clears the 0x93-dword settings block at 0x543928,
 * copies the 26 default key bindings from the table at 0x4f46a0 into the
 * live key map at 0x543ab8 (the map Input_PollPlayerKeyboard reads - the
 * classic MK4 defaults, W/A/S/D and the arrows plus numpad), stamps the
 * default volumes and button assignments, then scans the 16-entry joystick
 * presence table at 0x7b0188 and hands the first two present sticks to
 * player 0 and player 1 (-1 when none). */
void ResetConfigToDefaults(void)
{
    unsigned int i;
    int p0 = -1, p1 = -1;

    for (i = 0; i < 0x93; i++)
        *MK4_VA(unsigned int, 0x543928u + i * 4u) = 0;

    *MK4_VA(unsigned int, 0x543abcu) = *MK4_VA(unsigned int, 0x4f46a4u);
    *MK4_VA(unsigned int, 0x543ab8u) = *MK4_VA(unsigned int, 0x4f46a0u);
    *MK4_VA(unsigned int, 0x543ac4u) = *MK4_VA(unsigned int, 0x4f46acu);
    *MK4_VA(unsigned int, 0x543ac0u) = *MK4_VA(unsigned int, 0x4f46a8u);
    *MK4_VA(unsigned int, 0x543accu) = *MK4_VA(unsigned int, 0x4f46b4u);
    *MK4_VA(unsigned int, 0x543ac8u) = *MK4_VA(unsigned int, 0x4f46b0u);
    *MK4_VA(unsigned int, 0x543ad4u) = *MK4_VA(unsigned int, 0x4f46bcu);
    *MK4_VA(unsigned int, 0x543ad0u) = *MK4_VA(unsigned int, 0x4f46b8u);
    *MK4_VA(unsigned int, 0x543adcu) = *MK4_VA(unsigned int, 0x4f46c4u);
    *MK4_VA(unsigned int, 0x543ad8u) = *MK4_VA(unsigned int, 0x4f46c0u);
    *MK4_VA(unsigned int, 0x543ae4u) = *MK4_VA(unsigned int, 0x4f46ccu);
    *MK4_VA(unsigned int, 0x543ae0u) = *MK4_VA(unsigned int, 0x4f46c8u);
    *MK4_VA(unsigned int, 0x543aecu) = *MK4_VA(unsigned int, 0x4f46d4u);
    *MK4_VA(unsigned int, 0x543ae8u) = *MK4_VA(unsigned int, 0x4f46d0u);
    *MK4_VA(unsigned int, 0x543af4u) = *MK4_VA(unsigned int, 0x4f46dcu);
    *MK4_VA(unsigned int, 0x543af0u) = *MK4_VA(unsigned int, 0x4f46d8u);
    *MK4_VA(unsigned int, 0x543afcu) = *MK4_VA(unsigned int, 0x4f46e4u);
    *MK4_VA(unsigned int, 0x543af8u) = *MK4_VA(unsigned int, 0x4f46e0u);
    *MK4_VA(unsigned int, 0x543b04u) = *MK4_VA(unsigned int, 0x4f46ecu);
    *MK4_VA(unsigned int, 0x543b00u) = *MK4_VA(unsigned int, 0x4f46e8u);
    *MK4_VA(unsigned int, 0x543b0cu) = *MK4_VA(unsigned int, 0x4f46f4u);
    *MK4_VA(unsigned int, 0x543b08u) = *MK4_VA(unsigned int, 0x4f46f0u);
    *MK4_VA(unsigned int, 0x543b14u) = *MK4_VA(unsigned int, 0x4f46fcu);
    *MK4_VA(unsigned int, 0x543b10u) = *MK4_VA(unsigned int, 0x4f46f8u);
    *MK4_VA(unsigned int, 0x543b1cu) = *MK4_VA(unsigned int, 0x4f4704u);
    *MK4_VA(unsigned int, 0x543b18u) = *MK4_VA(unsigned int, 0x4f4700u);
    *MK4_VA(unsigned int, 0x543a88u) = 0x64;
    *MK4_VA(unsigned int, 0x543a90u) = 0x64;
    *MK4_VA(unsigned int, 0x54392cu) = 1;
    *MK4_VA(unsigned int, 0x543a84u) = 1;
    *MK4_VA(unsigned int, 0x543a8cu) = 1;
    *MK4_VA(unsigned int, 0x543aa4u) = 4;
    *MK4_VA(unsigned int, 0x543aa8u) = 1;
    *MK4_VA(unsigned int, 0x543aa0u) = 3;
    *MK4_VA(unsigned int, 0x543a9cu) = 2;
    *MK4_VA(unsigned int, 0x543aacu) = 1;
    *MK4_VA(unsigned int, 0x543ab0u) = 2;
    *MK4_VA(unsigned int, 0x543ab4u) = 1;
    *MK4_VA(unsigned int, 0x543a94u) = 0x32;
    *MK4_VA(unsigned int, 0x543a98u) = 0;
    *MK4_VA(int, 0x543b6cu) = -1;   /* both stick slots start unassigned */
    *MK4_VA(unsigned int, 0x543b24u) = 1;
    *MK4_VA(unsigned int, 0x543b20u) = 1;
    *MK4_VA(unsigned int, 0x543b44u) = 5;
    *MK4_VA(unsigned int, 0x543b40u) = 5;
    *MK4_VA(unsigned int, 0x543b2cu) = 2;
    *MK4_VA(unsigned int, 0x543b5cu) = 6;
    *MK4_VA(unsigned int, 0x543b58u) = 6;
    *MK4_VA(unsigned int, 0x543b28u) = 2;
    *MK4_VA(unsigned int, 0x543b64u) = 7;
    *MK4_VA(unsigned int, 0x543b60u) = 7;
    *MK4_VA(unsigned int, 0x543b34u) = 3;
    *MK4_VA(unsigned int, 0x543b4cu) = 8;
    *MK4_VA(unsigned int, 0x543b48u) = 8;
    *MK4_VA(unsigned int, 0x543b30u) = 3;
    *MK4_VA(unsigned int, 0x543b54u) = 9;
    *MK4_VA(unsigned int, 0x543b50u) = 9;
    *MK4_VA(unsigned int, 0x543b3cu) = 4;
    *MK4_VA(unsigned int, 0x543b38u) = 4;

    for (i = 0; i < 0x10; i++) {
        if (*MK4_VA(unsigned char, 0x7b0188u + i) == 0) continue;
        if (p0 == -1) { p0 = (int)i; continue; }
        if (p1 == -1) {
            p1 = (int)i;
            *MK4_VA(int, 0x543b6cu) = p1;
        }
        break;
    }
    *MK4_VA(int, 0x543b68u) = p0;
}
#else
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
#endif
