/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueEnd;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueWorkType;
extern u32 g_pendingNodeType;
extern u32 g_eventQueueNotMask;

/* @addr 0x004a98f0 (70b)
 *   load g_state_00537f94; cmp 1; if !=, load g_state_00537f48 → walk;
 *   else load walk; cmp 2; jne skip; load g_state_005380e0 → walk;
 *   if walk==7 set byte g_byte_0054372c=dl; if walk==6 set g_byte_00543724=dl.
 */
extern unsigned int g_state_00537f94;
extern unsigned int g_state_00537f48_ll;
extern unsigned int g_state_005380e0_ll;
extern unsigned char g_byte_0054372c;
extern unsigned char g_byte_00543724;
void StateCmpAndStoreByte_004a98f0(void) {
    __asm {
        mov     ecx, dword ptr [g_state_00537f94]
        mov     edx, 1
        cmp     ecx, edx
        _emit   75h
        _emit   0ch
        mov     eax, dword ptr [g_state_00537f48_ll]
        mov     dword ptr [g_walkCallback], eax
        _emit   0ebh
        _emit   05h
        mov     eax, dword ptr [g_walkCallback]
        cmp     ecx, 2
        _emit   75h
        _emit   0ah
        mov     eax, dword ptr [g_state_005380e0_ll]
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 7
        _emit   75h
        _emit   06h
        mov     byte ptr [g_byte_0054372c], dl
        cmp     eax, 6
        _emit   75h
        _emit   06h
        mov     byte ptr [g_byte_00543724], dl
        }
}
