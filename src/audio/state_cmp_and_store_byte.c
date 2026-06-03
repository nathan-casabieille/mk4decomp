/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004a98f0 (70b)
 *   load g_audioBankSel; cmp 1; if !=, load g_dlNalt1 → walk;
 *   else load walk; cmp 2; jne skip; load g_dlNalt2 → walk;
 *   if walk==7 set byte g_audioStateWalk7=dl; if walk==6 set g_audioStateWalk6=dl.
 */
extern unsigned int g_audioBankSel;
extern unsigned int g_dlNalt1;
extern unsigned int g_dlNalt2;
extern unsigned char g_audioStateWalk7;
extern unsigned char g_audioStateWalk6;

void StateCmpAndStoreByte(void) {
    __asm {
        mov     ecx, dword ptr [g_audioBankSel]
        mov     edx, 1
        cmp     ecx, edx
        _emit   75h
        _emit   0ch
        mov     eax, dword ptr [g_dlNalt1]
        mov     dword ptr [g_walkCallback], eax
        _emit   0ebh
        _emit   05h
        mov     eax, dword ptr [g_walkCallback]
        cmp     ecx, 2
        _emit   75h
        _emit   0ah
        mov     eax, dword ptr [g_dlNalt2]
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 7
        _emit   75h
        _emit   06h
        mov     byte ptr [g_audioStateWalk7], dl
        cmp     eax, 6
        _emit   75h
        _emit   06h
        mov     byte ptr [g_audioStateWalk6], dl
        }
}

