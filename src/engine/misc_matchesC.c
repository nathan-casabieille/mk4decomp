/**
 * Twelfth batch of one-off matches (final small ones).
 */
#include "engine/scenegraph.h"

/* @addr 0x00438160 (6b): jmp [g_eventQueueChild]  (indirect jump through global) */
__declspec(naked) void IndirectJmp_00438160(void) {
    __asm {
        jmp     dword ptr [g_eventQueueChild]
    }
}

/* @addr 0x00460400 (30b)
 *   mov     eax, 0x3333
 *   mov     [g_eventQueueIdx], 0x00460490
 *   mov     [g_xformScratch2088], eax
 *   mov     [g_currentNodeFlags], eax
 *   jmp     T
 */
extern unsigned int g_xformScratch2088;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_eventQueueIdx;
extern void func_0042ac0a(void);
__declspec(naked) void Init3333Jmp_00460400(void) {
    __asm {
        mov     eax, 0x3333
        mov     dword ptr [g_eventQueueIdx], 0x00460490
        mov     dword ptr [g_xformScratch2088], eax
        mov     dword ptr [g_currentNodeFlags], eax
        jmp     func_0042ac0a
    }
}

/* @addr 0x004c6fd0 (22b)
 *   push    ebp
 *   mov     ebp, esp
 *   mov     eax, [ebp+8]
 *   mov     ecx, [eax*4 + 0x00520070]
 *   push    edx
 *   push    ecx
 *   call    [iat]
 *   pop     ebp
 *   ret
 */
extern void *g_table_00520070;
extern void *g_iat_004d213c;
__declspec(naked) void TableLookupIatCall_004c6fd0(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        mov     eax, dword ptr [ebp + 8]
        mov     ecx, dword ptr [eax*4 + g_table_00520070]
        push    ecx
        call    dword ptr [g_iat_004d213c]
        pop     ebp
        ret
    }
}
