/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_state_00537e94;
extern packed_ptr g_fightGroupHead;

/* @addr 0x00466090 (61b)
 *   dec g_walkCallback; store both walk and g_state_0053a238
 *   je → jmp T1; mov [g_walkCallback], 6
 *   call F; pause → ret; push lit; call F2; add esp,4; ret
 */
extern unsigned int g_state_0053a238;
extern void TripleBlockInstallSelf_00465ef0(void);
extern void AndShlStore_00409280(void);
extern int ArgSarStoreJmp_004594f0(void *);
extern void *g_data_004ea990;
__declspec(naked) void DecCallPushCall_00466090(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_0053a238], eax
        je      short L_dcpc_body
        jmp     TripleBlockInstallSelf_00465ef0
L_dcpc_body:
        mov     dword ptr [g_walkCallback], 6
        call    AndShlStore_00409280
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_dcpc_ret
        push    OFFSET g_data_004ea990
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
L_dcpc_ret:
        ret
    }
}
