/**
 * Table-lookup IAT call wrapper.
 *
 * #pragma optimize("y", off) forces MSVC to keep the frame pointer
 * (the orig has push ebp / mov ebp, esp); /O2 alone enables /Oy and
 * would emit a frameless form using [esp+4] instead.
 */
#include "engine/scenegraph.h"

/* @addr 0x004c6fd0 (22b)
 *   push    ebp
 *   mov     ebp, esp
 *   mov     eax, [ebp+8]
 *   mov     ecx, [eax*4 + 0x00520070]
 *   push    ecx
 *   call    [iat]
 *   pop     ebp
 *   ret
 */
extern void *g_table_00520070[];
extern int (__stdcall *g_iat_004d213c)(void *);

#pragma optimize("y", off)
int TableLookupIatCall_004c6fd0(int arg) {
    return g_iat_004d213c(g_table_00520070[arg]);
}
#pragma optimize("", on)
