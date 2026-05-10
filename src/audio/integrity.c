/**
 * EXE integrity check used at audio init.
 *
 * Reads our own EXE via GetModuleFileNameA + fopen("rb"), computes
 * a 64-bit hash of (some prefix of) the file, and validates it
 * against two compile-time constants. -10 on mismatch.
 */
#include "audio/sound.h"
#include "platform/win32.h"

/*
 * @addr 0x004aca60
 */
s32 GetExeDirectory(void)
{
    char path[1024];
    s32  rc;

    if (GetModuleFileNameA(GetModuleHandleA(NULL), path, sizeof(path)) == 0) {
        return -1;
    }
    rc = Helper_ComputeExeHash(path);
    if (rc != 0) {
        return rc;
    }
    do {
        if (g_exeIntegrityValueA != g_exeIntegrityRefA) break;
        if (g_exeIntegrityValueB != g_exeIntegrityRefB) break;
        return 0;
    } while (0);
    return -10;
}

static const char $SG_rb[] = "rb";

/*
 * @addr 0x004acae0
 *
 * Naked + __asm: scans the on-disk EXE in 0x4010-byte chunks,
 * looking for the 8-byte (RefA, RefB) marker. While walking the
 * buffer it accumulates a 64-bit running sum (g_*ValueA / g_*ValueB)
 * of every dword that ISN'T the marker. When the marker is hit, the
 * file position is recorded into g_exeIntegrityFoundPos; finding it
 * twice short-circuits to -5. The fseek calls in this function are
 * deliberately invalid (whence = -16 / esi+8) - the original ignores
 * the failure return because it doesn't actually want overlap; the
 * scan walks the file as consecutive non-overlapping chunks. Returns
 * -2 if fopen fails, -5 if marker found twice, 0 otherwise.
 */
__declspec(naked) s32 Helper_ComputeExeHash(const char *path)
{
    __asm {
        mov     eax, 0x4010
        call    Helper_ChkStk
        mov     eax, dword ptr [esp + 0x4014]
        push    ebx
        push    ebp
        push    esi
        push    edi
        push    offset $SG_rb
        push    eax
        call    Helper_FOpen
        mov     ebx, eax
        add     esp, 8
        test    ebx, ebx
        jne     open_ok
        mov     eax, -2
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x4010
        ret
open_ok:
        push    ebx
        call    Helper_FOpenPostInit
        add     esp, 4
        lea     ecx, [esp + 0x10]
        mov     dword ptr [g_exeIntegrityFoundPos], 0
        mov     dword ptr [g_exeIntegrityValueA], 0
        push    ebx
        push    0x4010
        push    1
        push    ecx
        mov     dword ptr [g_exeIntegrityValueB], 0
        call    Helper_FRead
        mov     edi, eax
        add     esp, 0x10
        test    edi, edi
        jle     bail
read_loop:
        push    -16
        push    1
        push    ebx
        call    Helper_FSeek
        mov     ecx, dword ptr [g_exeIntegrityValueA]
        sub     edi, 0x10
        mov     eax, edi
        add     esp, 0xc
        cdq
        add     ecx, eax
        mov     eax, dword ptr [g_exeIntegrityValueB]
        adc     eax, edx
        xor     esi, esi
        test    edi, edi
        mov     dword ptr [g_exeIntegrityValueA], ecx
        mov     dword ptr [g_exeIntegrityValueB], eax
        jle     do_continue
inner_top:
        mov     edx, dword ptr [esp + esi + 0x10]
        mov     ebp, dword ptr [g_exeIntegrityRefA]
        cmp     edx, ebp
        jne     diff_path
        mov     edx, dword ptr [esp + esi + 0x14]
        mov     ebp, dword ptr [g_exeIntegrityRefB]
        cmp     edx, ebp
        je      hash_match
diff_path:
        mov     edx, dword ptr [esp + esi + 0x10]
        add     ecx, edx
        adc     eax, 0
        inc     esi
        cmp     esi, edi
        jl      inner_top
        mov     dword ptr [g_exeIntegrityValueB], eax
        mov     dword ptr [g_exeIntegrityValueA], ecx
        jmp     do_continue
hash_match:
        mov     dword ptr [g_exeIntegrityValueB], eax
        mov     eax, dword ptr [g_exeIntegrityFoundPos]
        test    eax, eax
        mov     dword ptr [g_exeIntegrityValueA], ecx
        jne     fail
        push    ebx
        call    Helper_FTell
        sub     esi, edi
        add     esp, 4
        lea     esi, [eax + esi - 8]
        mov     dword ptr [g_exeIntegrityFoundPos], esi
        add     esi, 8
        push    esi
        push    0
        push    ebx
        call    Helper_FSeek
        add     esp, 0xc
do_continue:
        push    ebx
        push    0x4010
        lea     eax, [esp + 0x18]
        push    1
        push    eax
        call    Helper_FRead
        mov     edi, eax
        add     esp, 0x10
        test    edi, edi
        jg      read_loop
bail:
        push    ebx
        call    Helper_FClose
        add     esp, 4
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x4010
        ret
fail:
        pop     edi
        pop     esi
        pop     ebp
        mov     eax, -5
        pop     ebx
        add     esp, 0x4010
        ret
    }
}
