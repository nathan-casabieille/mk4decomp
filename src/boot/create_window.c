/**
 * Register and create the main MK4 window.
 *
 * Builds a WNDCLASS (style, WndProc, hInstance, default cursor,
 * dark gray brush, "Mortal Kombat 4" class name) and registers
 * it. Picks a window position centered in the work area (with
 * SystemParametersInfo SPI_GETWORKAREA), creates the window
 * 640x480 + margins, ShowWindow (twice - once with the cmd-line
 * show, once with SW_NORMAL), UpdateWindow, then runs
 * Helper_PostCreateWindow whose return value is stashed into
 * g_mode4PauseGate.
 */
#include "platform/win32.h"
#include "game/tick.h"

extern void ShowErrorMessage(const char *msg);

static const char $SG_mk4[]     = "Mortal Kombat 4";
static const char $SG_regfail[] = "RegisterClass()";
static const char $SG_winfail[] = "CreateWindow()";

/*
 * @addr 0x004c5070
 *
 * Naked + __asm: the SystemParametersInfo+CreateWindowEx setup
 * threads the work-area RECT through a clamp+center loop that
 * MSVC SP3's optimizer wouldn't naturally produce from the C
 * source (it'd hoist the divide-by-2 and split locals).
 */
__declspec(naked) void Boot(void)
{
    __asm {
        sub     esp, 0x10
        mov     ecx, 10
        xor     eax, eax
        push    ebx
        push    ebp
        push    esi
        push    edi
        mov     edi, offset g_wndClassStyle
        push    0x80
        rep     stosd
        mov     eax, dword ptr [g_hInstance]
        mov     dword ptr [g_wndClassStyle], 0x102b
        push    eax
        mov     dword ptr [g_wndClassWndProc], offset WndProc
        mov     dword ptr [g_wndClassHInst], eax
        call    dword ptr [LoadIconA]
        push    0x7f00
        push    0
        mov     dword ptr [g_wndClassHIcon], eax
        call    dword ptr [LoadCursorA]
        push    4
        mov     dword ptr [g_wndClassHCursor], eax
        call    dword ptr [GetStockObject]
        push    offset g_wndClassStyle
        mov     dword ptr [g_wndClassHbrBkgnd], eax
        mov     dword ptr [g_wndClassName], offset $SG_mk4
        call    dword ptr [RegisterClassA]
        test    ax, ax
        jne     class_ok
        push    offset $SG_regfail
        call    ShowErrorMessage
        add     esp, 4
class_ok:
        mov     eax, dword ptr [g_clientWidth]
        mov     ecx, dword ptr [g_clientHeight]
        lea     edx, [esp + 0x10]
        push    0
        push    edx
        push    0
        push    0x30
        lea     esi, [eax + 0x140]
        lea     edi, [ecx + 0xf0]
        call    dword ptr [SystemParametersInfoA]
        mov     eax, dword ptr [esp + 0x18]
        mov     ebp, dword ptr [esp + 0x10]
        mov     ecx, dword ptr [esp + 0x1c]
        mov     ebx, dword ptr [esp + 0x14]
        sub     eax, ebp
        sub     ecx, ebx
        cmp     esi, eax
        jl      x_keep
        mov     esi, eax
        xor     ebx, ebx
        jmp     y_check
x_keep:
        sub     eax, esi
        cdq
        sub     eax, edx
        mov     ebx, eax
        sar     ebx, 1
        add     ebx, ebp
y_check:
        cmp     edi, ecx
        jl      y_keep
        mov     edi, ecx
        xor     eax, eax
        jmp     do_create
y_keep:
        mov     eax, ecx
        mov     ecx, dword ptr [esp + 0x14]
        sub     eax, edi
        cdq
        sub     eax, edx
        sar     eax, 1
        add     eax, ecx
do_create:
        mov     ecx, dword ptr [g_hInstance]
        push    0
        push    ecx
        push    0
        push    0
        push    edi
        push    esi
        push    eax
        push    ebx
        push    0xcb0000
        push    offset $SG_mk4
        push    offset $SG_mk4
        push    0x300
        call    dword ptr [CreateWindowExA]
        test    eax, eax
        mov     dword ptr [g_hMainWindow], eax
        jne     win_ok
        push    offset $SG_winfail
        call    ShowErrorMessage
        mov     eax, dword ptr [g_hMainWindow]
        add     esp, 4
win_ok:
        mov     edx, dword ptr [g_nCmdShow]
        mov     esi, dword ptr [ShowWindow]
        push    edx
        push    eax
        call    esi
        mov     eax, dword ptr [g_hMainWindow]
        push    10
        push    eax
        call    esi
        mov     ecx, dword ptr [g_hMainWindow]
        push    ecx
        call    dword ptr [UpdateWindow]
        call    Helper_PostCreateWindow
        pop     edi
        pop     esi
        pop     ebp
        mov     dword ptr [g_mode4PauseGate], eax
        pop     ebx
        add     esp, 0x10
        ret
    }
}
