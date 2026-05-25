/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004bd960 (45b): rep stosd 3 blocks
 *   push    edi
 *   mov     ecx, 0x6f
 *   xor     eax, eax
 *   mov     edi, 0x00ab4e78
 *   rep     stosd
 *   mov     ecx, 7
 *   mov     edi, 0x00ab4e00
 *   rep     stosd
 *   stosw
 *   mov     ecx, 0xc0
 *   xor     eax, eax
 *   mov     edi, 0x00ab44f8
 *   rep     stosd
 *   pop     edi
 *   ret
 */
extern unsigned int g_dispatchSave1578_00ab4e78;
extern unsigned int g_dispatchSave1568_00ab4e00;
extern unsigned int g_dispatchSave1513_00ab44f8;
extern void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
void AppInit_Misc4(void) {
    memset(&g_dispatchSave1578_00ab4e78, 0, 0x6f * 4);
    memset(&g_dispatchSave1568_00ab4e00, 0, 7 * 4 + 2);
    memset(&g_dispatchSave1513_00ab44f8, 0, 0xc0 * 4);
}

