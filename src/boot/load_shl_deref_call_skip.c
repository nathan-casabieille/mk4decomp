/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0041f810 (28b)
 *   mov     eax, [g_pendingNodeType]
 *   shl     eax, 2
 *   mov     ecx, [eax + 0xd8]
 *   test    ecx, ecx
 *   je      .ret
 *   push    eax
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern void NodeUnlink(unsigned int);
void LoadShlDerefCallSkip(void) {
    unsigned int p = g_pendingNodeType * 4;
    if (((ScenegraphNode *)p)->ptr_field) {
        NodeUnlink(p);
    }
}
