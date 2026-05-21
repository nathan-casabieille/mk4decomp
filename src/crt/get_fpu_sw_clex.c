/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004cf720 (17b)
 *   push    ebp
 *   mov     ebp, esp
 *   push    ecx
 *   fld     qword ptr [ebp+8]
 *   fstp    qword ptr [ebp-2]      ; actually fistp via dbe2 ?
 *   ; Actually 0xdb 0xe2 is fnclex... no wait
 *   ; 0xdb /2 with mod=11 reg=100 rm=010 = ... actually let me just use _emit
 *   movsx   eax, word ptr [ebp-2]
 *   mov     esp, ebp
 *   pop     ebp
 *   ret
 *
 * Bytes: 558bec51dd7dfedbe20fbf45fe8be55dc3
 *   55              push ebp
 *   8b ec           mov ebp, esp
 *   51              push ecx
 *   dd 7d fe        fnstsw [ebp-2]? wait dd /7 mod=01 = fnstsw
 *   actually dd 7d fe = fnstsw word ptr [ebp-2]?
 *   dd is x87 group; 7d means /7 with disp8. 7d = mod=01 reg=111 rm=101 (ebp+disp8)
 *   /7 of dd is fnstsw m16 - yes, fnstsw [ebp-2]
 *   db e2           fnclex (if e2)? Actually db is x87, e2 = no /r form...
 *   db e2 = FNCLEX is db e2. Yes.
 *   Wait actually fnclex = db e2, fclex = 9b db e2. So this is fnclex.
 *   Hmm but the earlier instruction was fld qword and now fnclex? Let me re-decode.
 *
 * Actually re-read:
 *   55 8b ec 51 dd 7d fe db e2 0f bf 45 fe 8b e5 5d c3
 * - 55       push ebp
 * - 8b ec    mov ebp, esp
 * - 51       push ecx
 * - dd 7d fe fstp qword ptr [ebp-2]  ?? no, dd /7 = fstp - but fstp needs specific size
 *   Actually dd = x87, /7 in modr/m means group; let me look up:
 *   dd /0 = fld m64
 *   dd /1 = fisttp m64
 *   dd /2 = fst m64
 *   dd /3 = fstp m64
 *   dd /7 = fnstsw m16
 *   So dd 7d fe = fnstsw [ebp-2]
 * - db e2    fnclex (if e2 means /4 with no operand) actually fnclex = db e2 yes
 * - 0f bf 45 fe   movsx eax, word ptr [ebp-2]
 * - 8b e5    mov esp, ebp
 * - 5d       pop ebp
 * - c3       ret
 *
 * So this is "get fpu status word + clear exceptions, return as int".
 * However, that's only 17 bytes, matching.
 */
__declspec(naked) void GetFpuSwClex_004cf720(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        push    ecx
        fnstsw  word ptr [ebp - 2]
        fnclex
        movsx   eax, word ptr [ebp - 2]
        mov     esp, ebp
        pop     ebp
        ret
    }
}
