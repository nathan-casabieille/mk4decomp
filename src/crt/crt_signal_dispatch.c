/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004c9750 (77b)
 *   CRT signal/setjmp dispatch: arg = -2 → IAT[0x4d2118],
 *   -3 → IAT[0x4d2110], -4 → fetch [0xf9fc20] (no IAT call);
 *   each path sets the [0xf9fadc] flag to 1 first.
 */
extern unsigned int g_dispatchSave1440;
extern unsigned int g_dispatchSave1448;
extern unsigned int g_iat_GetACP;
extern unsigned int g_iat_GetOEMCP;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int CRTSignalDispatch(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    g_dispatchSave1440 = 1;
                    /* WARNING: Could not recover jumptable at 0x004c976d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    g_dispatchSave1440 = 1;
                    /* WARNING: Could not recover jumptable at 0x004c9782. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = g_dispatchSave1448;
  }
  g_dispatchSave1440 = (uint)bVar2;
  return param_1;
}
#else
__declspec(naked) void CRTSignalDispatch(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     dword ptr [g_dispatchSave1440], 0
        cmp     eax, -2
        _emit   75h
        _emit   10h
        mov     dword ptr [g_dispatchSave1440], 1
        jmp     dword ptr [g_iat_GetOEMCP]
        cmp     eax, -3
        _emit   75h
        _emit   10h
        mov     dword ptr [g_dispatchSave1440], 1
        jmp     dword ptr [g_iat_GetACP]
        cmp     eax, -4
        _emit   75h
        _emit   0fh
        mov     eax, dword ptr [g_dispatchSave1448]
        mov     dword ptr [g_dispatchSave1440], 1
        ret
    }
}
#endif
