/**
 * FSYS - asset archive subsystem.
 *
 * See include/engine/fsys.h for the public API and
 * analysis/notes/architecture.md for the on-disk layout.
 */
#include "engine/fsys.h"
#include "platform/install.h"  /* for ShowErrorMessage */

extern int sprintf(char *buf, const char *fmt, ...);  /* CRT */

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
 * Open a file in the asset archive. Normalizes the path, hashes
 * it, then binary-searches g_fsys_entries[] for a matching hash.
 * Returns a handle (entry-index + 1).
 *
 * Equivalent C (compiles to 176 bytes; original is 177 due to a
 * different register allocation MSVC SP3 doesn't pick from any
 * variable-naming variant we tried):
 *
 *     hash = FSYS_HashName(FSYS_NormalizePath(path));
 *     hi   = g_fsys_entry_count;
 *     lo   = 0;
 *     mid  = hi >> 1;
 *     if (hash == g_fsys_entries[mid].hash) goto verify;
 *     while (lo < hi - 1) {
 *         if (hash >= g_fsys_entries[mid].hash) lo = mid;
 *         else                                  hi = mid;
 *         mid = (lo + hi) >> 1;
 *         if (hash == g_fsys_entries[mid].hash) goto verify;
 *     }
 *  verify:
 *     if (hash != g_fsys_entries[mid].hash) {
 *         char buf[1024];
 *         sprintf(buf, "FSYS_fopen(\"%s\")", path);
 *         ShowErrorMessage(buf);
 *     }
 *     g_fsys_files[mid + 1] = 0;
 *     return mid + 1;
 *
 * Pinned via __asm to match the original register choices
 * (ecx=lo, edi=hi, esi=mid, ebp=temp).
 *
 * @addr 0x004b1e00
 */
static const char k_fopen_errfmt[] = "FSYS_fopen(\"%s\")";

__declspec(naked) int FSYS_fopen(const char *path, const char *mode)
{
    __asm {
        sub     esp, 400h               ; errbuf[1024]
        push    ebx
        mov     ebx, [esp+408h]         ; ebx = path
        push    ebp
        push    esi
        push    edi
        push    ebx
        call    FSYS_NormalizePath
        add     esp, 4
        push    eax
        call    FSYS_HashName           ; eax = hash
        mov     esi, [g_fsys_entry_count]
        add     esp, 4
        mov     edi, esi                ; edi = hi
        xor     ecx, ecx                ; ecx = lo = 0
        sar     esi, 1                  ; esi = mid = hi/2
        lea     edx, [esi+esi*2]
        mov     edx, dword ptr [edx*4 + g_fsys_entries+8]
        cmp     eax, edx
        je      verify

loop_top:
        lea     ebp, [edi-1]             ; ebp = hi - 1
        cmp     ecx, ebp
        jge     verify
        cmp     eax, edx                 ; cmp hash vs cached entries[mid].hash
        jae     go_right
        ; go_left: hi = mid, mid = (lo + mid) / 2
        mov     edi, esi
        sub     esi, ecx
        sar     esi, 1
        add     esi, ecx
        jmp     reload_mid_hash
go_right:
        ; lo = mid, mid = (mid + hi) / 2
        mov     edx, esi
        mov     esi, edi
        sub     esi, ecx
        sar     esi, 1
        add     esi, ecx
        mov     ecx, edx
reload_mid_hash:
        lea     edx, [esi+esi*2]
        mov     edx, dword ptr [edx*4 + g_fsys_entries+8]
        cmp     eax, edx
        jne     loop_top                 ; mismatch -> continue loop

verify:
        lea     ecx, [esi+esi*2]
        cmp     eax, dword ptr [ecx*4 + g_fsys_entries+8]
        je      do_init
        ; Not found -> sprintf + ShowErrorMessage
        push    ebx
        lea     edx, [esp+14h]            ; &errbuf[0] (after pushes)
        push    offset k_fopen_errfmt
        push    edx
        call    sprintf
        add     esp, 0Ch
        lea     eax, [esp+10h]
        push    eax
        call    ShowErrorMessage
        add     esp, 4
do_init:
        mov     dword ptr [esi*4 + g_fsys_files+4], 0
        lea     eax, [esi+1]              ; return = mid + 1
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 400h
        ret
    }
}

/*
 * Open a file, read it whole into the caller's buffer, close.
 * Reports "FSYS_fload()" via ShowErrorMessage if the read returned
 * any count other than 1. No return value; callers don't check.
 *
 * @addr 0x004b2160
 */
void FSYS_fload(const char *path, void *buf, u32 size)
{
    int fh;
    int n;

    fh = FSYS_fopen(path, "rb");
    n = FSYS_fread(buf, size, 1, fh);
    FSYS_fclose(fh);
    if (n != 1) {
        ShowErrorMessage("FSYS_fload()");
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
 * Equivalent C:
 *
 *     int hash = 0, shift = 0, i = 0;
 *     while (normalized_path[i] != 0) {
 *         hash += (int)(signed char)normalized_path[i] << shift;
 *         shift += 8;
 *         if (shift > 24) shift = 0;
 *         i++;
 *     }
 *     return (u32)(hash + i);
 *
 * The C version is 49/50 bytes (1 SIB encoding diff in the final
 * `lea eax, [esi+edx]`). __asm pins the exact byte.
 *
 * @addr 0x004b1f50
 */
__declspec(naked) u32 FSYS_HashName(const char *normalized_path)
{
    __asm {
        push    esi
        push    edi
        mov     edi, [esp+12]
        xor     esi, esi              ; hash = 0
        xor     ecx, ecx              ; shift = 0
        xor     edx, edx              ; i = 0
        mov     al, byte ptr [edi]
        test    al, al
        jz      end_hash
loop_top:
        movsx   eax, al
        shl     eax, cl
        add     ecx, 8                ; shift += 8
        add     esi, eax              ; hash += eax
        cmp     ecx, 18h               ; cmp shift, 24
        jle     skip_reset
        xor     ecx, ecx              ; shift = 0
skip_reset:
        mov     al, byte ptr [edx+edi+1]
        inc     edx                   ; i++
        test    al, al
        jnz     loop_top
end_hash:
        lea     eax, [esi+edx]        ; return hash + i
        pop     edi
        pop     esi
        ret
    }
}
