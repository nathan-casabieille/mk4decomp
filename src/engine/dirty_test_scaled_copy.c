/**
 * Auto-split from misc_matchesNN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ba6c0 (85b)
 *   testb 0x10,[dirty]; if set: load g_pendingNodeType; lea ecx=[eax*4 + 0];
 *   load *ecx; copy 4 dwords from there into globals 0x7af990..0x7af9a0;
 *   load dirty; load word ecx[+0x10]; mask 0xef; store; ret 0.
 */
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c;
extern unsigned short g_word_007af9a0;
void DirtyTestScaledCopy_004ba6c0(void) {
    __asm {
        test    byte ptr [g_xformDirtyFlags], 0x10
        _emit   74h
        _emit   49h
        mov     eax, dword ptr [g_pendingNodeType]
        lea     ecx, [eax*4 + 0]
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_vtxMat], edx
        mov     eax, dword ptr [ecx + 4]
        mov     dword ptr [g_mat3x3_007af994], eax
        mov     edx, dword ptr [ecx + 8]
        mov     dword ptr [g_mat3x3_007af998], edx
        mov     eax, dword ptr [ecx + 0x0c]
        mov     dword ptr [g_mat3x3_007af99c], eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     cx,  word  ptr [ecx + 0x10]
        and     al,  0xef
        mov     word  ptr [g_word_007af9a0], cx
        mov     dword ptr [g_xformDirtyFlags], eax
        xor     eax, eax
        }
}
