/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041aa40 (60b)
 *   mov     ecx, [g_xformEntityIdx]
 *   mov     eax, [g_scaledInit_00542044]
 *   shl     ecx, 2
 *   shl     eax, 2
 *   mov     edx, [ecx + 0x30]
 *   neg     edx
 *   mov     [g_walkCallback], edx
 *   mov     [eax + 0x30], edx
 *   mov     edx, [ecx + 0x34]
 *   neg     edx
 *   mov     [g_walkCallback], edx
 *   mov     [eax + 0x34], edx
 *   mov     ecx, [ecx + 0x38]
 *   neg     ecx
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x38], ecx
 *   ret
 */
extern packed_ptr g_xformEntityIdx;
void Copy3FieldsNeg_0041aa40(void) {
    unsigned char *src;
    unsigned char *dst;
    int v;
    dst = (unsigned char *)g_scaledInit_00542044;
    src = (unsigned char *)g_xformEntityIdx;
    src = (unsigned char *)((unsigned int)src << 2);
    dst = (unsigned char *)((unsigned int)dst << 2);
    v = -*(int *)(src + 0x30);
    g_walkCallback = (void (*)(void))v;
    *(int *)(dst + 0x30) = v;
    v = -*(int *)(src + 0x34);
    g_walkCallback = (void (*)(void))v;
    *(int *)(dst + 0x34) = v;
    v = -*(int *)(src + 0x38);
    g_walkCallback = (void (*)(void))v;
    *(int *)(dst + 0x38) = v;
}
