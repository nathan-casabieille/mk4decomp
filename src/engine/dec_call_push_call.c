/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_phaseTimer;

/* @addr 0x00466090 (61b)
 *   dec g_walkCallback; store both walk and g_dispatchVar15
 *   je → jmp T1; mov [g_walkCallback], 6
 *   call F; pause → ret; push lit; call F2; add esp,4; ret
 */
extern unsigned int g_dispatchVar15;
extern void TripleBlockInstallSelf(void);
extern void AndShlStore(void);
extern int ArgSarStoreJmp(void *);
extern unsigned int g_dispatchSave1278;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DecCallPushCall(void)

{
  g_dispatchVar15 = g_walkCallback + -1;
  if (g_dispatchVar15 != 0) {
    g_walkCallback = g_dispatchVar15;
    ArgSarStoreJmp(0x4ea948);
    return;
  }
  g_walkCallback = 6;
  AndShlStore();
  if (g_framePauseFlag == 0) {
    ArgSarStoreJmp(0x4ea990);
  }
  return;
}
#else
__declspec(naked) void DecCallPushCall(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_dispatchVar15], eax
        je      short L_dcpc_body
        jmp     TripleBlockInstallSelf
L_dcpc_body:
        mov     dword ptr [g_walkCallback], 6
        call    AndShlStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_dcpc_ret
        push    OFFSET g_dispatchSave1278
        call    ArgSarStoreJmp
        add     esp, 4
L_dcpc_ret:
        ret
    }
}
#endif
