/**
 * Twelfth batch of one-off matches (final small ones).
 */
#include "engine/scenegraph.h"

/* @addr 0x00438160 (6b): jmp [g_eventQueueChild]  (indirect jump through global) */
void IndirectJmp_00438160(void) {
    ((void (*)(void))g_eventQueueChild)();
}

/* @addr 0x00460400 (30b)
 *   mov     eax, 0x3333
 *   mov     [g_eventQueueIdx], 0x00460490
 *   mov     [g_xformScratch2088], eax
 *   mov     [g_currentNodeFlags], eax
 *   jmp     T
 */
extern u32 g_xformScratch2088;
extern u32 g_currentNodeFlags;
extern u32 g_eventQueueIdx;
extern void func_0042ac0a(void);
void Init3333Jmp_00460400(void) {
    unsigned int v = 0x3333;
    g_eventQueueIdx = 0x00460490;
    g_xformScratch2088 = v;
    g_currentNodeFlags = v;
    func_0042ac0a();
}

/* @addr 0x004c6fd0 (22b)
 *   push    ebp
 *   mov     ebp, esp
 *   mov     eax, [ebp+8]
 *   mov     ecx, [eax*4 + 0x00520070]
 *   push    ecx
 *   call    [iat]
 *   pop     ebp
 *   ret
 *
 * #pragma optimize("y", off) forces MSVC to keep the frame pointer
 * (the orig has push ebp / mov ebp, esp); /O2 alone enables /Oy and
 * would emit a frameless form using [esp+4] instead.
 */
extern void *g_table_00520070[];
extern int (__stdcall *g_iat_004d213c)(void *);

#pragma optimize("y", off)
int TableLookupIatCall_004c6fd0(int arg) {
    return g_iat_004d213c(g_table_00520070[arg]);
}
#pragma optimize("", on)
