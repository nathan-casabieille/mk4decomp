/**
 * FSYS - asset archive subsystem.
 *
 * See include/engine/fsys.h for the public API and
 * analysis/notes/architecture.md for the on-disk layout.
 */
#include "engine/fsys.h"
#include "platform/install.h"  /* for ShowErrorMessage */

/*
 * Return the value stored in the file slot (= current read offset
 * after fopen / fseek / fread). Out-of-range handles return -1.
 *
 * @addr 0x004b2100
 */
int FSYS_ftell(int fh)
{
    if ((unsigned int)fh > 0x400) {
        return -1;
    }
    return g_fsys_files[fh];
}

/*
 * Normalize a path: uppercase letters, copy into the static
 * g_fsys_normalized_path buffer, validate that it begins with a
 * drive letter ("X:\..."). On a missing prefix the function calls
 * ShowErrorMessage but still returns the (partial) buffer.
 *
 * NULL or empty input returns NULL.
 *
 * Equivalent C (cleaner, but produces 112 bytes of optimized code
 * with MSVC SP3 instead of the 129 in MK4.EXE):
 *
 *     int i;
 *     char c;
 *     if (!path || !*path) return 0;
 *     for (i = 0; i < 0x3ff && path[i] != 0; i++) {
 *         c = path[i];
 *         g_fsys_normalized_path[i] = (c >= 'a' && c <= 'z')
 *             ? c - 0x20 : c;
 *     }
 *     ...
 *
 * MSVC 5.0 SP3 (build 11.00.7022) optimizes the byte spill the
 * original compile depended on (a partial-register-stall workaround
 * common to Pentium-era codegen). We can't reach the exact bytes
 * with C alone, so the body is hand-written __asm. This is a
 * standard "permuter-class" technique in matching decomp projects.
 *
 * @addr 0x004b1ec0
 */
static const char k_partial_filename[] = "Partial filename";

__declspec(naked) char *FSYS_NormalizePath(const char *path)
{
    __asm {
        mov     ecx, [esp+4]
        push    esi
        test    ecx, ecx
        jz      ret_null
        cmp     byte ptr [ecx], 0
        je      ret_null
        mov     esi, offset g_fsys_normalized_path
        xor     edx, edx
        sub     esi, ecx
loop_check:
        cmp     edx, 03FFh
        jae     end_loop
        mov     al, byte ptr [ecx]
        cmp     al, 61h               ; 'a'
        mov     [esp+8], al
        jb      as_is
        cmp     al, 7Ah               ; 'z'
        ja      as_is
        mov     eax, [esp+8]
        and     eax, 0FFh
        sub     eax, 20h              ; uppercase
        jmp     write_byte
as_is:
        mov     eax, [esp+8]
        and     eax, 0FFh
write_byte:
        mov     byte ptr [esi+ecx], al
        mov     al, byte ptr [ecx+1]
        inc     edx
        inc     ecx
        test    al, al
        jnz     loop_check
end_loop:
        mov     g_fsys_normalized_path[edx], 0
        mov     al, byte ptr [offset g_fsys_normalized_path + 1]
        cmp     al, 3Ah               ; ':'
        jne     add_prefix
        cmp     byte ptr [offset g_fsys_normalized_path + 2], 5Ch  ; '\\'
        je      ret_buf
add_prefix:
        push    offset k_partial_filename
        call    ShowErrorMessage
        add     esp, 4
ret_buf:
        mov     eax, offset g_fsys_normalized_path
        pop     esi
        ret
ret_null:
        xor     eax, eax
        pop     esi
        ret
    }
}

/*
 * Query the size of a file by name. Opens, seeks to end, reads
 * position, closes.
 *
 * @addr 0x004b2120
 */
u32 FSYS_fsize(const char *path)
{
    int fh;
    int size;

    fh = FSYS_fopen(path, "rb");
    FSYS_fseek(fh, 0, 2);
    size = FSYS_ftell(fh);
    FSYS_fclose(fh);
    return (u32)size;
}

/*
 * Free a file handle. Marks the slot as available; out-of-range
 * handles silently no-op.
 *
 * @addr 0x004b1f90
 */
int FSYS_fclose(int fh)
{
    if ((unsigned int)fh > 0x400) {
        return 0;
    }
    g_fsys_files[fh] = -1;
    return 0;
}

/*
 * Position-shifted accumulator hash. Each character is sign-extended,
 * shifted left by an 8-bit-stepping counter (0, 8, 16, 24, then back
 * to 0), and added into the running hash. The final return adds the
 * string length so two prefixes never collide.
 *
 * Match status: 49/50 bytes. The single remaining diff is the SIB
 * encoding of the final `lea eax, [esi+edx]` (0x16 vs 0x32). Both
 * forms compute the identical address; MSVC 5.0 SP3's heuristic
 * picks the opposite base/index assignment. Semantically equivalent.
 *
 * @addr 0x004b1f50
 */
u32 FSYS_HashName(const char *normalized_path)
{
    int hash = 0;
    int shift = 0;
    int i = 0;

    while (normalized_path[i] != 0) {
        hash += (int)(signed char)normalized_path[i] << shift;
        shift += 8;
        if (shift > 24) {
            shift = 0;
        }
        i++;
    }
    return (u32)(hash + i);
}
