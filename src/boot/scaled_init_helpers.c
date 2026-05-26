/**
 * Boot-phase scaled-init field manipulators.
 *
 * Three hybrid/pure-C helpers that read or modify the scaled-init / dirty-flag
 * state during boot. Two are hybrid because of MSVC SP3 flag-preservation
 * across stores; one is pure C.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004084b0 (81b)
 *   load scaled, eventQueueCurrent; load scaled[+0x1c] into eax;
 *   if eventQueueCurrent < eax, store eax into eventQueueCurrent;
 *   load scaled[0]; if non-zero set walk = own VA, call F, pause-test;
 *   clear dirty bit 1; ret.
 */
extern void Helper_TickAlt(void);
extern void BootGatedInitInstallPair_00412280(void);
extern void SlotInitAndChainLink_004191b0(void);

void ScaledLoadCallSet1c_004084b0(void) {
    __asm {
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     eax, dword ptr [ecx*4 + 0x1c]
        cmp     edx, eax
        _emit   7dh
        _emit   05h
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     eax, dword ptr [ecx*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   18h
        mov     dword ptr [g_walkCallback], 0x004084b0
        call    Helper_TickAlt
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ch
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al,  0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        }
}

/* @addr 0x004147b0 (87b)
 *   set dirty |= 4; if g_scaledInit != 0:
 *     dirty ^= 4 (back); load scaled+0x18 → scaled; load scaled+0x28 → eax;
 *     set walk = 0x414600 + store at [eax*4 + 0x10]; ret.
 */
void SetDirty4XorScaledLoad_004147b0(void) {
    __asm {
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     ecx, 4
        or      eax, ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        mov     eax, dword ptr [g_scaledInit_00542044]
        test    eax, eax
        _emit   74h
        _emit   3ch
        mov     edx, dword ptr [g_xformDirtyFlags]
        xor     edx, ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   2ah
        mov     eax, dword ptr [eax*4 + 0x18]
        mov     ecx, 0x00414600
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0x10], ecx
        }
}

/* @addr 0x004196c0 (83b)
 *   call F; pause → ret; testb 4,[dirty] → ret;
 *   load g_eventQueueEnd; mov [eax*4 + 0x30]=0x81; load g_xformEntityIdx;
 *   set walk = 0x14ccc + store at [ecx*4 + 0x48]; eventQueueEnd+0x15 → g_scaledInit;
 *   jmp T.
 */
void CallPauseDirty4ScaledSet_004196c0(void) {
    SlotInitAndChainLink_004191b0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    ((FightGroupNode *)(g_eventQueueEnd * 4))->tag = 0x81;
    g_walkCallback = (void(*)(void))0x14ccc;
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x48) = 0x14ccc;
    g_scaledInit_00542044 = g_eventQueueEnd + 0x15;
    BootGatedInitInstallPair_00412280();
}

