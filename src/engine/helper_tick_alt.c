/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1566;
extern unsigned int g_dispatchSave1575;
extern unsigned int g_dispatchSave1576;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1566 (*(unsigned int *)MK4_VA(unsigned int, 0xab4db8u))
#define g_dispatchSave1575 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e5cu))
#define g_dispatchSave1576 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e60u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_siblingTable ((unsigned int *)MK4_VA(unsigned int, 0x0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif

extern void ZeroEightFields(void);

#ifdef NON_MATCHING
/* Portable twin of Helper_TickAlt's entry routine (the sibling walk, L_ilw),
 * verified via verify_coexec at-rest + a seeded sibling chain. Sister of
 * Helper_TickInner: initial node from field +0, stride from field +8 (no +2),
 * and the saved callback (edi) is restored into g_walkCallback before each
 * call. The packed L_amw_entry routine that follows in the naked body has no
 * portable caller (no reloc/symbol/extras reference to its internal address),
 * so it stays matching-only in the naked branch. The two finish paths (L_ilw_done's
 * pre-OR and L_ilw_setMask) converge to the same net effect; transcribed as
 * the converged form. */
void Helper_TickAlt(void)
{
#ifdef TARGET_SDL
    /* MK4_TRACE_TICKALT: calls and dispatched callbacks per frame. The tick
     * walk is re-entrant - a node's callback can start another walk - so
     * "the frame got slow" is a question about depth, not about node count. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      extern unsigned int g_mk4FrameNo;
      static unsigned calls, lastFrame;
      if (getenv("MK4_TRACE_TICKALT")) {
          if (g_mk4FrameNo != lastFrame) {
              if (calls > 400)
                  SDL_Log("TICKALT f%u calls=%u", lastFrame, calls);
              lastFrame = g_mk4FrameNo; calls = 0;
          }
          calls++; } }
#endif
    unsigned int saved_cb = g_walkCallback;              /* edi: saved callback */
    unsigned int idx      = g_currentNodeIdx;
    unsigned int cur      = g_siblingTable[idx];         /* eax = node[idx].f0 */
    unsigned int stride   = g_siblingTable[idx + 2];     /* ebp = node[idx].f8 */
    unsigned int last     = cur;                         /* ebx */

    g_walkCallback = cur;
    if (cur != 0) {
#ifdef TARGET_SDL
        /* MK4_TRACE_CYCLE: the sibling walk is unbounded in the original,
         * which is correct there because the chain is always acyclic. Under
         * the port a mis-linked chain turns this into a live-lock inside one
         * frame - the whole app stops with `sample` pointing here. With the
         * env set, count the hops and dump the first ones when the walk runs
         * past any plausible chain length. */
        unsigned int trc_hops = 0, trc_first[8]; int trc_on;
        { extern char *getenv(const char *); trc_on = getenv("MK4_TRACE_CYCLE") != 0; }
#endif
        for (;;) {
            unsigned int walkIdx = stride + cur;         /* ecx = ebp + eax */
            unsigned int sib;
#ifdef TARGET_SDL
            if (trc_on) {
                if (trc_hops < 8) trc_first[trc_hops] = cur;
                if (++trc_hops > 4096u) {
                    extern void SDL_Log(const char *, ...);
                    SDL_Log("CYCLE idx=%x (VA %x) head=%x stride=%x cb=%x "
                            "node0=%x node4=%x node8=%x",
                            idx, idx * 4u, g_siblingTable[idx], stride, saved_cb,
                            g_siblingTable[cur], g_siblingTable[cur + 1],
                            g_siblingTable[cur + 2]);
                    break;
                }
            }
#endif
            g_currentNodeIdx = cur;                      /* eax */
            sib = g_siblingTable[walkIdx];               /* esi = node[walkIdx].f0 */
            g_currentNodeIdx = cur;                      /* eax (redundant store) */
            g_walkCallback = saved_cb;                   /* edi restored before call */
            ((void (*)(void))MK4_ResolveCode(saved_cb))();
            if (g_framePauseFlag) goto ret;              /* L_ilw_ret: no dirty update */
            if (g_xformDirtyFlags & 1) break;            /* L_ilw_setMask -> finish */
            cur  = sib;
            last = sib;
            g_walkCallback = sib;
            if (sib == 0) break;                         /* L_ilw_done -> finish */
        }
    }
    g_xformDirtyFlags |= 4;
    g_currentNodeIdx = last;                             /* ebx */
    if (last != 0)
        g_xformDirtyFlags ^= 4;
ret:
    return;
}
#else
__declspec(naked) void Helper_TickAlt(void)
{
    __asm
    {
        mov     ecx, dword ptr [g_currentNodeIdx]
        push    ebx
        push    ebp
        push    esi
        mov     eax, dword ptr [ecx*4]
        push    edi
        mov     edi, dword ptr [g_walkCallback]
        mov     dword ptr [g_walkCallback], eax
        mov     ebp, dword ptr [ecx*4 + 8]
        mov     ebx, eax
        test    eax, eax
        je      short L_ilw_done
    L_ilw_loop:
        lea     ecx, [ebp + eax]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     esi, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_walkCallback], edi
        call    edi
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_ilw_ret
        test    byte ptr [g_xformDirtyFlags], 1
        jne     short L_ilw_setMask
        mov     eax, esi
        mov     ebx, esi
        test    esi, esi
        mov     dword ptr [g_walkCallback], eax
        jne     short L_ilw_loop
    L_ilw_done:
        mov     ecx, dword ptr [g_xformDirtyFlags]
        mov     eax, 4
        or      ecx, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        jmp     short L_ilw_finish
    L_ilw_setMask:
        mov     eax, 4
    L_ilw_finish:
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_currentNodeIdx], ebx
        or      edx, eax
        test    ebx, ebx
        mov     dword ptr [g_xformDirtyFlags], edx
        je      short L_ilw_ret
        mov     ecx, edx
        xor     ecx, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
    L_ilw_ret:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_amw_entry:
        mov     eax, dword ptr [g_xformEntityIdx]
        push    ebx
        mov     ebx, dword ptr [g_tickW1]
        push    esi
        mov     esi, dword ptr [eax*4 + 0x14]
        mov     eax, ebx
        cdq
        push    edi
        mov     edi, dword ptr [g_eventQueueIdx]
        sub     eax, edx
        mov     ecx, dword ptr [edi*4 + 0x64]
        mov     dword ptr [g_dispatchSave1576], ebx
        sar     eax, 1
        mov     dword ptr [g_dispatchSave1575], eax
        lea     eax, [esi + esi*4]
        mov     dword ptr [g_tickDecay], 2
        lea     edx, [eax + eax*4]
        lea     eax, [esi + edx*8]
        shl     eax, 4
        add     eax, esi
        shl     eax, 5
        sub     eax, esi
        add     ecx, eax
        mov     eax, dword ptr [edi*4 + 0x54]
        cmp     eax, 0x10000
        jl      short L_amw_negC
        add     ecx, 0x6487
        jmp     short L_amw_testNeg
    L_amw_negC:
        add     ecx, 0xc90
    L_amw_testNeg:
        test    ecx, ecx
        jge     short L_amw_wrapHigh
        mov     edx, 0x6487d
        mov     eax, 0xa2f99905
        sub     edx, ecx
        mul     edx
        shr     edx, 0x12
        lea     eax, [edx + edx*4]
        lea     eax, [eax + eax*4]
        lea     eax, [edx + eax*8]
        shl     eax, 4
        add     eax, edx
        shl     eax, 6
        sub     eax, edx
        lea     ecx, [ecx + eax*2]
    L_amw_wrapHigh:
        cmp     ecx, 0x6487e
        jl      short L_amw_check
        mov     eax, 0xa2f99905
        mul     ecx
        shr     edx, 0x12
    L_amw_unrollSub:
        sub     ecx, 0x6487e
        dec     edx
        jne     short L_amw_unrollSub
    L_amw_check:
        test    ecx, ecx
        jl      short L_amw_setNeg
        cmp     ecx, 0x330cf
        jge     short L_amw_setNeg
        mov     eax, dword ptr [g_dispatchSave1566]
        test    eax, eax
        je      short L_amw_skipCall
        call    ZeroEightFields
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_amw_setNeg:
        mov     dword ptr [g_currentNodeIdx], 0xffffffff
    L_amw_skipCall:
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
#endif

