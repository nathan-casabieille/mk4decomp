/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c57d0 (48b)
 *   push    ebp
 *   mov     ebp, esp
 *   add     esp, -12
 *   wait
 *   fnstcw  word ptr [ebp-2]
 *   wait
 *   mov     ax, word ptr [ebp-2]
 *   or      ah, 0x0c
 *   mov     word ptr [ebp-4], ax
 *   fldcw   word ptr [ebp-4]
 *   fistp   qword ptr [ebp-12]
 *   fldcw   word ptr [ebp-2]
 *   mov     eax, [ebp-12]
 *   mov     edx, [ebp-8]
 *   leave
 *   ret
 *   nop * 8 (int 3 padding)
 */
__declspec(naked) void DoubleToInt64_004c57d0(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        add     esp, -12
        fstcw   word ptr [ebp - 2]
        wait
        mov     ax, word ptr [ebp - 2]
        or      ah, 0x0c
        mov     word ptr [ebp - 4], ax
        fldcw   word ptr [ebp - 4]
        fistp   qword ptr [ebp - 12]
        fldcw   word ptr [ebp - 2]
        mov     eax, dword ptr [ebp - 12]
        mov     edx, dword ptr [ebp - 8]
        leave
        ret
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
    }
}
