/**
 * High-resolution timer init.
 *
 * Used by the per-frame profiler + audio scheduling. Runs once at
 * boot; can be no-op'd by setting g_timerInitedSkip beforehand
 * (debug shim that bypasses QPC on hardware that misreports it).
 */
#include "platform/win32.h"
#include <mmsystem.h>

/* The 1e6 divisor used to convert QPC frequency to ticks-per-usec.
 * Sits in .rdata in the original (0x004d2aa0); we let the linker
 * place ours wherever the .rdata pool ends up - bytes-on-disk are
 * the same and the matching diff masks the relocation. */
static const double k_qpcDivisor = 1000000.0;

/*
 * @addr 0x004c4470
 *
 * The init block uses xor eax, eax + a3 [moffset], eax for the
 * LARGE_INTEGER halves but c7 05 imm32 imm32 for the double. Pure C
 * compiles all four halves as c7 stores (10 bytes each), which adds
 * up to ten bytes more than the original. Pinning the byte sequence
 * via __asm to keep the eax-reuse pattern.
 */
__declspec(naked) void Timer_Init(void)
{
    __asm {
        mov     eax, dword ptr [g_timerInitedSkip]
        sub     esp, 8
        test    eax, eax
        jne     epi
        push    1
        call    dword ptr [timeBeginPeriod]
        xor     eax, eax
        ; Force 4-byte lea ecx, [esp+0] (8d 4c 24 00); MASM compresses
        ; to the 3-byte form 8d 0c 24 otherwise.
        _emit   8Dh
        _emit   4Ch
        _emit   24h
        _emit   00h
        mov     dword ptr [g_qpcStart], eax            ; LowPart = 0
        push    ecx
        mov     dword ptr [g_qpcUsPerTick], 0
        mov     dword ptr [g_qpcUsPerTick + 4], 0
        mov     dword ptr [g_qpcStart + 4], eax        ; HighPart = 0
        call    dword ptr [QueryPerformanceFrequency]
        test    eax, eax
        je      epi
        mov     eax, dword ptr [esp + 4]
        test    eax, eax
        jl      skip_div
        jg      do_div
        ; cmp dword ptr [esp+0], 0x3e8 (long form, 8 bytes); MASM
        ; would otherwise compress to [esp].
        _emit   81h
        _emit   7Ch
        _emit   24h
        _emit   00h
        _emit   0E8h
        _emit   03h
        _emit   00h
        _emit   00h
        jbe     skip_div
do_div:
        ; fild qword ptr [esp+0] (long form, 4 bytes).
        _emit   0DFh
        _emit   6Ch
        _emit   24h
        _emit   00h
        fdivr   qword ptr [k_qpcDivisor]      ; st0 = 1e6 / li (us per tick)
        fstp    qword ptr [g_qpcUsPerTick]
skip_div:
        push    offset g_qpcStart
        call    dword ptr [QueryPerformanceCounter]
epi:
        add     esp, 8
        ret
    }
}
