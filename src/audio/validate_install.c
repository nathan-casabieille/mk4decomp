/**
 * Three-stage install validator.
 *
 * 1. CheckInstallPath: registry lookup + SetCurrentDirectoryA.
 * 2. GetModuleFileName / split path / GetDriveTypeA: bail unless
 *    the EXE lives on a fixed (= installed) drive.
 * 3. RegOpenKeyEx + RegQueryValueEx on the "Config" value, with
 *    a 588-byte expected size + checksum cross-check.
 * Result is cached in g_validInstall.
 */
#include "audio/sound.h"
#include "platform/win32.h"
#include "engine/render.h"

static const char $SG_bs[]      = "\\";
static const char $SG_subkey[]  = "Software\\GT Interactive\\Mortal Kombat 4\\1.00";
static const char $SG_config[]  = "Config";
static const char $SG_short[]   = "\x15";

/*
 * @addr 0x004ad270
 *
 * Naked + __asm: dual rep scasb / rep movsd path concatenation
 * for the GetDriveType pre-call, plus very specific stack
 * cleanup pacing.
 */
__declspec(naked) s32 ValidateInstall(void)
{
    __asm {
        sub     esp, 0x418
        mov     eax, dword ptr [g_validInstall]
        push    ebp
        push    esi
        push    edi
        test    eax, eax
        mov     dword ptr [esp + 0xc], 0
        jz      do_check
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebp
        add     esp, 0x418
        ret
do_check:
        call    CheckInstallPath
        test    eax, eax
        jne     check_drive
        mov     eax, dword ptr [esp + 0xc]
        test    eax, eax
        jz      no_hkey
        push    eax
        call    dword ptr [RegCloseKey]
no_hkey:
        push    offset $SG_short
        call    ShowErrorMessage
        add     esp, 4
        mov     dword ptr [g_validInstall], 0
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        add     esp, 0x418
        ret
check_drive:
        lea     eax, [esp + 0x24]
        push    0x400
        push    eax
        call    Helper_StrCopy
        push    eax
        call    dword ptr [GetModuleFileNameA]
        push    0
        push    0
        lea     ecx, [esp + 0x1c]
        push    0
        lea     edx, [esp + 0x30]
        push    ecx
        push    edx
        call    Helper_SplitPath
        mov     edi, offset $SG_bs
        or      ecx, -1
        xor     eax, eax
        add     esp, 0x14
        repne   scasb
        not     ecx
        sub     edi, ecx
        lea     edx, [esp + 0x14]
        mov     esi, edi
        mov     ebp, ecx
        mov     edi, edx
        or      ecx, -1
        repne   scasb
        mov     ecx, ebp
        dec     edi
        shr     ecx, 2
        rep     movsd
        mov     ecx, ebp
        push    edx
        and     ecx, 3
        rep     movsb
        call    dword ptr [GetDriveTypeA]
        cmp     eax, 3
        je      open_key
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        add     esp, 0x418
        ret
open_key:
        lea     eax, [esp + 0xc]
        push    eax
        push    0x20019
        push    0
        push    offset $SG_subkey
        push    0x80000002
        call    dword ptr [RegOpenKeyExA]
        mov     eax, dword ptr [esp + 0xc]
        mov     edi, dword ptr [RegCloseKey]
        test    eax, eax
        jz      close_test
        lea     ecx, [esp + 0x10]
        mov     esi, 0x24c
        push    ecx
        push    offset g_configBuffer
        push    0
        push    0
        push    offset $SG_config
        push    eax
        mov     dword ptr [esp + 0x28], esi
        call    dword ptr [RegQueryValueExA]
        test    eax, eax
        jne     maybe_close
        cmp     dword ptr [esp + 0x10], esi
        jne     maybe_close
        mov     edx, dword ptr [esp + 0xc]
        push    edx
        call    edi
        call    Helper_ValidateB
        call    Helper_ValidateA
        mov     ecx, dword ptr [g_configBuffer]
        cmp     ecx, eax
        je      bump_checksum
        cmp     ecx, -1
        je      bump_checksum
maybe_close:
        mov     eax, dword ptr [esp + 0xc]
close_test:
        test    eax, eax
        jz      do_reset
        push    eax
        call    edi
do_reset:
        call    ResetConfigToDefaults
        mov     eax, 1
        mov     dword ptr [g_validInstall], eax
        pop     edi
        pop     esi
        pop     ebp
        add     esp, 0x418
        ret
bump_checksum:
        mov     eax, dword ptr [g_configChecksum]
        pop     edi
        inc     eax
        pop     esi
        mov     dword ptr [g_configChecksum], eax
        mov     eax, 1
        mov     dword ptr [g_validInstall], eax
        pop     ebp
        add     esp, 0x418
        ret
    }
}
