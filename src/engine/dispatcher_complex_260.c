/**
 * 2 "complex multi-call dispatcher with bit gates" (260 bytes each).
 *
 * Pattern (simplified):
 *   ; PUSH g_pendingNodeType
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_pendingNodeType]
 *   inc     eax
 *   push    ebx
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   call    SetupA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .late_pop                  ; long jne (rel32=0xd7)
 *   mov     al, [g_xformDirtyFlags]
 *   mov     ebx, 4
 *   test    bl, al
 *   jne     .skip_first_path           ; long jne (rel32=0x8d)
 *   ; First sub-path
 *   mov     edx, [g_scaledInit_00542044]
 *   mov     eax, [g_xformEntityIdx]
 *   mov     [edx*4 + 0x38], eax
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     [g_pendingNodeType], ecx
 *   call    Worker                     ; per-helper
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .late_pop                  ; long jne (rel32=0x95)
 *   test    [g_xformDirtyFlags], bl
 *   jne     .second_init               ; short
 *   mov     edx, [g_pendingNodeType]
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     [edx*4 + 0x18], eax
 *   mov     edx, [g_scaledInit_00542044]
 *   mov     ecx, [g_pendingNodeType]
 *   mov     [edx*4 + 0x18], ecx
 *   mov     eax, [g_pendingNodeType]
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     .after_init
 * .second_init:
 *   mov     ecx, [g_pendingNodeType]
 *   mov     [g_scaledInit_00542044], ecx
 * .after_init:
 * .skip_first_path:
 *   call    SetupB
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .late_pop                  ; (skip pop+xor, just ret)
 *   mov     [g_scaledInit_00542044], 0
 * .late_pop:
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_xformDirtyFlags]
 *   or      ecx, ebx                   ; set bit 2
 *   mov     edx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     eax, [g_scaledInit_00542044]
 *   test    eax, eax
 *   mov     [g_pendingNodeType], edx
 *   mov     [g_xformDirtyFlags], ecx
 *   je      .ret_with_xor
 *   mov     eax, ecx
 *   xor     eax, ebx
 *   mov     [g_xformDirtyFlags], eax
 * .ret_with_xor:
 *   pop     ebx
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern u32 g_pendingNodeType;
extern packed_ptr g_xformEntityIdx;

extern void BootPhaseGateBracketedInit_004060c0(void);
extern void MStackBracket1_TreeWalkRecursive2_00406dd0(void);
extern void FramePauseScaledStore_00406c10(void);
extern void MStackPush2ChainLLInsert_00406790(void);

#define DC260_BODY(WORKER_FN)                                                  \
    __asm {                                                                    \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     ecx, dword ptr [g_pendingNodeType]                       \
        __asm inc     eax                                                      \
        __asm push    ebx                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     dword ptr [eax*4 + 0], ecx                               \
        __asm call    BootPhaseGateBracketedInit_004060c0                                            \
        __asm mov     eax, dword ptr [g_framePauseFlag]                        \
        __asm test    eax, eax                                                 \
        __asm _emit   0fh                                                      \
        __asm _emit   85h                                                      \
        __asm _emit   0d7h                                                     \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm mov     al, byte ptr [g_xformDirtyFlags]                         \
        __asm mov     ebx, 4                                                   \
        __asm _emit   84h                                                      \
        __asm _emit   0c3h                                                   \
        __asm _emit   0fh                                                      \
        __asm _emit   85h                                                      \
        __asm _emit   8dh                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm mov     edx, dword ptr [g_scaledInit_00542044]                   \
        __asm mov     eax, dword ptr [g_xformEntityIdx]                        \
        __asm mov     dword ptr [edx*4 + 0x38], eax                            \
        __asm mov     ecx, dword ptr [g_scaledInit_00542044]                   \
        __asm mov     dword ptr [g_pendingNodeType], ecx                       \
        __asm call    WORKER_FN                                                \
        __asm mov     eax, dword ptr [g_framePauseFlag]                        \
        __asm test    eax, eax                                                 \
        __asm _emit   0fh                                                      \
        __asm _emit   85h                                                      \
        __asm _emit   95h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm _emit   00h                                                      \
        __asm test    byte ptr [g_xformDirtyFlags], bl                         \
        __asm _emit   75h                                                      \
        __asm _emit   31h                                                      \
        __asm mov     edx, dword ptr [g_pendingNodeType]                       \
        __asm mov     eax, dword ptr [g_scaledInit_00542044]                   \
        __asm mov     dword ptr [edx*4 + 0x18], eax                            \
        __asm mov     edx, dword ptr [g_scaledInit_00542044]                   \
        __asm mov     ecx, dword ptr [g_pendingNodeType]                       \
        __asm mov     dword ptr [edx*4 + 0x18], ecx                            \
        __asm mov     eax, dword ptr [g_pendingNodeType]                       \
        __asm mov     dword ptr [g_scaledInit_00542044], eax                   \
        __asm _emit   0ebh                                                     \
        __asm _emit   24h                                                      \
        __asm mov     ecx, dword ptr [g_pendingNodeType]                       \
        __asm mov     dword ptr [g_scaledInit_00542044], ecx                   \
        __asm call    MStackPush2ChainLLInsert_00406790                                            \
        __asm mov     eax, dword ptr [g_framePauseFlag]                        \
        __asm test    eax, eax                                                 \
        __asm _emit   75h                                                      \
        __asm _emit   42h                                                      \
        __asm mov     dword ptr [g_scaledInit_00542044], 0                     \
        __asm mov     eax, dword ptr [g_matrixStackTop]                        \
        __asm mov     ecx, dword ptr [g_xformDirtyFlags]                       \
        __asm or      ecx, ebx                                                 \
        __asm mov     edx, dword ptr [eax*4 + 0]                               \
        __asm dec     eax                                                      \
        __asm mov     dword ptr [g_matrixStackTop], eax                        \
        __asm mov     eax, dword ptr [g_scaledInit_00542044]                   \
        __asm test    eax, eax                                                 \
        __asm mov     dword ptr [g_pendingNodeType], edx                       \
        __asm mov     dword ptr [g_xformDirtyFlags], ecx                       \
        __asm _emit   74h                                                      \
        __asm _emit   09h                                                      \
        __asm mov     eax, ecx                                                 \
        __asm xor     eax, ebx                                                 \
        __asm mov     dword ptr [g_xformDirtyFlags], eax                       \
        __asm pop     ebx                                                      \
        __asm ret                                                              \
    }

/* @addr 0x00407030 */
__declspec(naked) void DispatcherComplex260_00407030(void) { DC260_BODY(MStackBracket1_TreeWalkRecursive2_00406dd0) }

/* @addr 0x00407400 */
__declspec(naked) void DispatcherComplex260_00407400(void) { DC260_BODY(FramePauseScaledStore_00406c10) }
