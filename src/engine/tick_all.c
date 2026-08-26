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
#include "portable/ghidra_types.h"
#include "engine/scenegraph.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_tickByteFlag (*(unsigned int *)MK4_VA(unsigned int, 0x543720u))
#define g_tickCurConfig (*(unsigned int *)MK4_VA(unsigned int, 0xab4e2cu))
#define g_tickCurMask (*(unsigned int *)MK4_VA(unsigned int, 0xab4e20u))
#define g_tickDecay (*(unsigned int *)MK4_VA(unsigned int, 0xab4e64u))
#define g_tickFlagF (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_tickFlagV (*(unsigned int *)MK4_VA(unsigned int, 0x541ec0u))
#define g_tickFlagZ (*(unsigned int *)MK4_VA(unsigned int, 0xab4e40u))
#define g_tickInitFlag (*(unsigned int *)MK4_VA(unsigned int, 0xab4e70u))
#define g_tickW1 (*(unsigned int *)MK4_VA(unsigned int, 0x543550u))
#define g_tickX1 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d98u))
#define g_tickX2 (*(unsigned int *)MK4_VA(unsigned int, 0xab51f4u))
#define g_tickX3 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e68u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/*
 * @addr 0x004b9e50
 *

 * Naked + __asm: the 5-pass sequence reuses bx (low 16 of ebx=0) as
 * a literal zero plus a setne-into-byte mask + dec idiom that pure
 * C wouldn't reproduce identically. The "fall through to main"
 * structure (long-form jne over the whole first-frame block) is
 * also fail-first/success-second.
 */

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin.
 *
 * Five fixed sub-trees on the first frame, then only the "main" one at
 * 0x538070 every frame after. Each pass primes g_currentNodeIdx with a
 * CONSTANT packed pointer (`mov eax, VA; sar eax, 2`), so the literals below
 * are `VA >> 2` and MK4_NODE turns them back into arena addresses.
 *
 * Every pass is followed by a g_framePauseFlag test that abandons the rest of
 * the sequence - hence the single shared exit.
 *
 * Two mask idioms need spelling out. In pass 3:
 *
 *     neg al ; sbb eax, eax ; and al, 0xa0 ; add eax, 0x60
 *
 * neg sets CF when the byte is non-zero, sbb turns that into 0 or -1, and the
 * 0xa0/0x60 pair makes the result 0x60 for a zero byte and 0 otherwise (0xa0
 * plus 0x60 carries out of the low byte and the 0xff... above it wraps to 0).
 * In pass 4, `setne dl ; dec edx ; and edx, 0xfffff800` is -1 when the flag
 * IS 7 and 0 otherwise, so the mask is 0xf800 or 0.
 *
 * g_tickW1's clamp is `jbe`, i.e. UNSIGNED; the g_tickDecay floor is `jns`,
 * i.e. signed - hence the (int) there and not here.
 *
 * The walk callback is spelled RenderSceneGraphIterate, not the
 * Helper_FightSceneCallback the naked branch names: both are 0x004ba1c0, and
 * only the former is a real entry in config/symbols.yaml, so it is the one the
 * co-exec harness and the VA -> native trampoline can resolve.
 */
extern void RenderSceneGraphIterate(void);
void TickAllEntities(void)
{
    unsigned char *cfg;
    unsigned int   w;

    Helper_PreTick();
    g_tickX1 = 0;
    Helper_TickInit(0);
    g_tickFlagZ = (g_tickByteFlag != 0);
    w = g_tickW1;
    g_tickX2 = 0;
    g_tickX3 = w;
    if (w > 0x100u)
        g_tickX3 = 0x100;

    if (g_tickInitFlag == 0) {
        /* pass 1 - only when the sub-tree head is non-empty */
        g_currentNodeIdx = 0x53a738 >> 2;
        if (*MK4_NODE(unsigned int, g_currentNodeIdx) != 0) {
            g_tickCurMask = 0xffc0;
            g_walkCallback = (unsigned int)&RenderSceneGraphIterate;
            Helper_TickInner();
            if (g_framePauseFlag != 0)
                return;
        }

        /* pass 2 */
        g_tickCurMask = 0;
        g_currentNodeIdx = 0x53a1e0 >> 2;
        g_walkCallback = (unsigned int)&RenderSceneGraphIterate;
        Helper_TickInner();
        if (g_framePauseFlag != 0)
            return;

        /* pass 3 */
        cfg = (unsigned char *)MK4_PTR(g_tickCurConfig);
        g_walkCallback = (unsigned int)&RenderSceneGraphIterate;
        g_tickCurMask = (unsigned short)(cfg[4] != 0 ? 0 : 0x60);
        g_currentNodeIdx = 0x541e50 >> 2;
        if (g_tickFlagV == 0)
            Helper_TickInner();
        else
            Helper_TickAlt();
        if (g_framePauseFlag != 0)
            return;

        /* pass 4 */
        g_tickCurMask = (unsigned short)(g_tickFlagF == 7 ? 0xf800 : 0);
        cfg = (unsigned char *)MK4_PTR(g_tickCurConfig);
        g_tickX1 = *(unsigned short *)(cfg + 2);
        g_currentNodeIdx = 0x535df0 >> 2;
        g_walkCallback = (unsigned int)&RenderSceneGraphIterate;
        if (cfg[5] == 0)
            Helper_TickInner();
        else
            Helper_TickAlt();
        if (g_framePauseFlag != 0)
            return;

        /* pass 5 */
        g_walkCallback = (unsigned int)&RenderSceneGraphIterate;
        g_currentNodeIdx = 0x53a2c0 >> 2;
        Helper_TickInner();
        if (g_framePauseFlag != 0)
            return;
    }

    /* main sub-tree, every frame */
    g_tickCurMask = 0x40;
    g_currentNodeIdx = 0x538070 >> 2;
    g_walkCallback = (unsigned int)&RenderSceneGraphIterate;
    Helper_TickInner();
    if (g_framePauseFlag != 0)
        return;

    if (g_tickInitFlag == 0)
        Helper_TickReinit();

    g_tickDecay--;
    if ((int)g_tickDecay < 0)
        g_tickDecay = 0;
}
#else
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
#endif
