/* Raw-byte fragments for inter-function code that doesn't map back to
 * a structured C source. Each fragment is placed by synth at a fixed VA.
 * The literal bytes assume the VA in symbols.yaml is unchanged; if a
 * fragment moves, re-dump it from orig.
 */

/* @addr 0x004c4588 (24b game) - Dead-thunk: 8 nops + jmp +0x0b + 11 nops. The jmp targets the next function
 * (CallTwoSumShl_004c45a0). Has no callers in orig - likely a leftover
 * patch slot or alias entry.
 */
__declspec(naked) void DeadThunk_004c4588(void) {
    __asm {
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0xe9
        _emit    0x0b
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
    }
}

/* @addr 0x004c5457 (89b game) - WinMain __except continuation: SEH filter + handler body that includes a
 * format-and-display error message path. Our reconstructed WinMain compiles
 * with an empty __except {} body, so MSVC only emits 41 bytes of unwinder
 * (extracted via WinMain symbol). The remaining 89 bytes of orig handler
 * code (format-print on exception) are dumped raw here so synth places
 * them at the fixed VA.
 */
__declspec(naked) void WinMainExceptHandler_004c5457(void) {
    __asm {
        _emit    0x8b
        _emit    0x45
        _emit    0xec
        _emit    0x89
        _emit    0x45
        _emit    0xe4
        _emit    0xc3
        _emit    0x8b
        _emit    0x65
        _emit    0xe8
        _emit    0x8b
        _emit    0x4d
        _emit    0xe4
        _emit    0x8b
        _emit    0x01
        _emit    0x8b
        _emit    0x50
        _emit    0x0c
        _emit    0x52
        _emit    0x8b
        _emit    0x00
        _emit    0x50
        _emit    0x68
        _emit    0xc8
        _emit    0xfd
        _emit    0x4f
        _emit    0x00
        _emit    0x8d
        _emit    0x8d
        _emit    0xe4
        _emit    0xfb
        _emit    0xff
        _emit    0xff
        _emit    0x51
        _emit    0xe8
        _emit    0x02
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x10
        _emit    0x8d
        _emit    0x95
        _emit    0xe4
        _emit    0xfb
        _emit    0xff
        _emit    0xff
        _emit    0x52
        _emit    0xe8
        _emit    0x33
        _emit    0xf4
        _emit    0xff
        _emit    0xff
        _emit    0x83
        _emit    0xc4
        _emit    0x04
        _emit    0xc7
        _emit    0x45
        _emit    0xfc
        _emit    0xff
        _emit    0xff
        _emit    0xff
        _emit    0xff
        _emit    0x33
        _emit    0xc0
        _emit    0x8b
        _emit    0x4d
        _emit    0xf0
        _emit    0x64
        _emit    0x89
        _emit    0x0d
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5b
        _emit    0x8b
        _emit    0xe5
        _emit    0x5d
        _emit    0xc2
        _emit    0x10
        _emit    0x00
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
    }
}

