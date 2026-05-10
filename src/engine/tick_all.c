/**
 * Top-of-frame entity tick.
 *
 * On the first frame (g_tickInitFlag == 0) it walks five fixed
 * entity sub-trees in turn (priming g_currentNodeIdx via the
 * `addr >> 2` scaled-base trick), each followed by a Helper_TickInner
 * (or Helper_TickAlt if a particular sticky flag is set) call. The
 * sequence aborts if g_framePauseFlag becomes non-zero. On every
 * subsequent frame only the "main" sub-tree at 0x538070 is walked.
 * Tail decrements g_tickDecay (clamped to 0).
 */
#include "game/tick.h"
#include "engine/scenegraph.h"

/*
 * @addr 0x004b9e50
 *
 * Naked + __asm: the 5-pass sequence reuses bx (low 16 of ebx=0) as
 * a literal zero plus a setne-into-byte mask + dec idiom that pure
 * C wouldn't reproduce identically. The "fall through to main"
 * structure (long-form jne over the whole first-frame block) is
 * also fail-first/success-second.
 */
__declspec(naked) void TickAllEntities(void)
{
    __asm {
        push    ebx
        push    esi
        call    Helper_PreTick
        xor     ebx, ebx
        push    ebx
        mov     dword ptr [g_tickX1], ebx
        call    Helper_TickInit
        mov     dl, byte ptr [g_tickByteFlag]
        add     esp, 4
        xor     eax, eax
        cmp     dl, bl
        setne   al
        mov     dword ptr [g_tickFlagZ], eax
        mov     eax, dword ptr [g_tickW1]
        cmp     eax, 0x100
        mov     dword ptr [g_tickX2], ebx
        mov     dword ptr [g_tickX3], eax
        jbe     skip_clamp
        mov     dword ptr [g_tickX3], 0x100
skip_clamp:
        mov     eax, dword ptr [g_tickInitFlag]
        mov     esi, offset Helper_FightSceneCallback
        cmp     eax, ebx
        jne     main_pass
        mov     eax, 0x53a738
        sar     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        cmp     dword ptr [eax*4], ebx
        je      pass2
        mov     word ptr [g_tickCurMask], 0xffc0
        mov     dword ptr [g_walkCallback], esi
        call    Helper_TickInner
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     exit
pass2:
        mov     ecx, 0x53a1e0
        mov     word ptr [g_tickCurMask], bx
        sar     ecx, 2
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_walkCallback], esi
        call    Helper_TickInner
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     exit
        mov     edx, dword ptr [g_tickCurConfig]
        mov     ecx, 0x541e50
        mov     al, byte ptr [edx + 4]
        mov     dword ptr [g_walkCallback], esi
        neg     al
        sbb     eax, eax
        and     al, 0xa0
        add     eax, 0x60
        mov     word ptr [g_tickCurMask], ax
        mov     eax, dword ptr [g_tickFlagV]
        sar     ecx, 2
        cmp     eax, ebx
        mov     dword ptr [g_currentNodeIdx], ecx
        je      use_inner3
        call    Helper_TickAlt
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     exit
        jmp     pass4
use_inner3:
        call    Helper_TickInner
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     exit
pass4:
        mov     eax, dword ptr [g_tickFlagF]
        xor     edx, edx
        cmp     eax, 7
        mov     eax, dword ptr [g_tickCurConfig]
        setne   dl
        dec     edx
        xor     ecx, ecx
        and     edx, 0xfffff800
        mov     word ptr [g_tickCurMask], dx
        mov     cx, word ptr [eax + 2]
        mov     edx, 0x535df0
        mov     dword ptr [g_tickX1], ecx
        sar     edx, 2
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_walkCallback], esi
        cmp     byte ptr [eax + 5], bl
        je      use_inner4
        call    Helper_TickAlt
        cmp     dword ptr [g_framePauseFlag], ebx
        ; orig uses short-form jne (75 79); MASM's __asm only emits
        ; long-form for forward jcc, so we _emit the bytes directly.
        _emit   75h
        _emit   79h
        jmp     SHORT pass5
use_inner4:
        call    Helper_TickInner
        cmp     dword ptr [g_framePauseFlag], ebx
        _emit   75h
        _emit   6Ah
pass5:
        mov     eax, 0x53a2c0
        mov     dword ptr [g_walkCallback], esi
        sar     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        call    Helper_TickInner
        cmp     dword ptr [g_framePauseFlag], ebx
        _emit   75h
        _emit   4Ah
main_pass:
        mov     ecx, 0x538070
        mov     word ptr [g_tickCurMask], 0x40
        sar     ecx, 2
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_walkCallback], esi
        call    Helper_TickInner
        cmp     dword ptr [g_framePauseFlag], ebx
        _emit   75h
        _emit   20h
        cmp     dword ptr [g_tickInitFlag], ebx
        _emit   75h
        _emit   05h
        call    Helper_TickReinit
        mov     eax, dword ptr [g_tickDecay]
        dec     eax
        mov     dword ptr [g_tickDecay], eax
        _emit   79h
        _emit   06h
        mov     dword ptr [g_tickDecay], ebx
exit:
        pop     esi
        pop     ebx
        ret
    }
}
