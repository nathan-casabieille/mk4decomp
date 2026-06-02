/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004c58b0 (40b)
 *   push    esi
 *   mov     esi, [esp+8]
 *   push    edi
 *   push    esi
 *   call    F1
 *   add     esp, 4
 *   push    esi
 *   call    F2
 *   add     esp, 4
 *   mov     edi, eax
 *   push    esi
 *   call    F3
 *   add     esp, 4
 *   mov     eax, edi
 *   pop     edi
 *   pop     esi
 *   ret
 */
extern void RangePathIATDispatch_Lock(int);
extern int FileTellAdjusted(int);
extern void RangePathIATDispatch_TableLookupIatCall(int);
int Helper_FTell(int arg) {
    int saved;
    RangePathIATDispatch_Lock(arg);
    saved = FileTellAdjusted(arg);
    RangePathIATDispatch_TableLookupIatCall(arg);
    return saved;
}

