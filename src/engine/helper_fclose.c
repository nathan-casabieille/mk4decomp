/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#endif


/* @addr 0x004c5800 (61b)
 *   if (arg[0xc] & 0x40) zero arg[0xc] and return -1;
 *   else: call 0x4c6ff0(arg); call 0x4c5840(arg) → save eax;
 *   call 0x4c7060(arg); restore eax; return.
 */
extern void func_004c6ff0_hh(void *);
extern int FCloseImpl(void *);
extern void func_004c7060_hh(void *);
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
undefined4 Helper_FClose(int param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)MK4_PTR((param_1 + 0xc)) & 0x40) != 0) {
    *(undefined4 *)MK4_PTR((param_1 + 0xc)) = 0;
    return 0xffffffff;
  }
  RangePathIATDispatch_Lock(param_1);
  uVar1 = FCloseImpl(param_1);
  RangePathIATDispatch_TableLookupIatCall(param_1);
  return uVar1;
}
#else
__declspec(naked) void Helper_FClose(void) {
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        push    edi
        or      edi, 0xffffffff
        test    byte ptr [esi + 0x0c], 0x40
        _emit   74h
        _emit   0ch
        mov     dword ptr [esi + 0x0c], 0
        mov     eax, edi
        pop     edi
        pop     esi
        ret
        push    esi
        call    func_004c6ff0_hh
        add     esp, 4
        push    esi
        call    FCloseImpl
        add     esp, 4
        mov     edi, eax
        push    esi
        call    func_004c7060_hh
        add     esp, 4
        mov     eax, edi
        pop     edi
        pop     esi
        ret
    }
}
#endif

