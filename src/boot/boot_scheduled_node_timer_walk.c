/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;
#endif

extern void StoreTwoCall(int, int);
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;
#endif

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void PushSetCallPop(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;
#endif

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave105;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
/* g_matrixStackTop is a REAL host symbol (src/data.c defines it), so a file
 * that does not alias it here pushes and pops a word in __DATA while the 97
 * files that DO alias it - including the boot helper that sets the packed
 * base 0x14e05a, and RecordListIterMStack, this file's own caller - use the
 * arena slot at 0x4d57ac. Two storages for one stack pointer. */
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave105 (*(unsigned int *)MK4_VA(unsigned int, 0x535d14u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueChild (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_extra_0052ab3c (*(unsigned int *)MK4_VA(unsigned int, 0x52ab3cu))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_gameMode (*(unsigned int *)MK4_VA(unsigned int, 0x543800u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch2088 (*(unsigned int *)MK4_VA(unsigned int, 0x542088u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void NodeUnlink();

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BootScheduledNodeTimerWalk(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = g_extra_0052ab3c;
  do {
    while( true ) {
      if (iVar2 == 0) {
        g_framePauseFlag = 0;
        return;
      }
      if (((g_gameMode == 0) || (g_gameMode == *(int *)MK4_PTR((iVar2 + 0xd8)))) ||
         (*(int *)MK4_PTR((iVar2 + 0xe0)) == 0x11)) break;
LAB_0041f6ef:
#ifdef TARGET_SDL
      { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        int nx = *(int *)MK4_PTR((iVar2 + 0xe4));
        if (getenv("MK4_TRACE_PUMP") && nx != 0 &&
            !((unsigned)nx >= 0x53e368u && (unsigned)nx < 0x541d68u))
            SDL_Log("PUMP bad link: node 0x%x +0xe4 -> 0x%x (cb 0x%x)", iVar2, nx,
                    *(int *)MK4_PTR((iVar2 + 0xd8))); }
#endif
      iVar2 = *(int *)MK4_PTR((iVar2 + 0xe4));
    }
    *(short *)MK4_PTR((iVar2 + 0xdc)) = *(short *)MK4_PTR((iVar2 + 0xdc)) + -1;
    if (*(short *)MK4_PTR((iVar2 + 0xdc)) < 1) {
      g_baseSel = iVar2 >> 2;
      g_eventQueueNotMask = MK4_NODE_AT(undefined4, g_baseSel, 0x14);
      g_eventQueueChild = MK4_NODE_AT(undefined4, g_baseSel, 0x18);
      g_cj_00542054 = MK4_NODE_AT(undefined4, g_baseSel, 0x24);
      g_cj_00542058 = MK4_NODE_AT(undefined4, g_baseSel, 0x28);
      g_walkCallback = MK4_NODE_AT(undefined4, g_baseSel, 8);
      g_cj_0054205c = MK4_NODE_AT(undefined4, g_baseSel, 0x2c);
      g_currentNodeFlags = MK4_NODE_AT(undefined4, g_baseSel, 0x1c);
      g_xformScratch2088 = MK4_NODE_AT(undefined4, g_baseSel, 0x20);
      *(undefined4 *)MK4_PTR((iVar2 + 0xd8)) = MK4_NODE_AT(undefined4, g_baseSel, 8);
      g_framePauseFlag = 0;
      g_dispatchSave105 = *(undefined4 *)MK4_PTR((iVar2 + 0xd8));
#ifdef TARGET_SDL
      /* MK4_TRACE_BADCB: a node whose callback is not a plausible code VA.
       * Under the arena a host pointer written into a code slot shows up
       * here as an ASLR-varying value, and MK4_ResolveCode then reports it
       * as "not linked natively" with no way to tell WHICH node carried it.
       * This names the node, its tag and its work type. */
      { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        static unsigned n;
        unsigned int cb = *(unsigned int *)MK4_PTR(iVar2 + 0xd8);
        if (getenv("MK4_TRACE_BADCB") && n < 12
            && (cb < 0x401000u || cb >= 0x4d0000u)) { n++;
            SDL_Log("BADCB node=%x cb=%08x tag=%x wt=%x st=%x plus8=%08x",
                    iVar2, cb,
                    *(unsigned int *)MK4_PTR(iVar2 + 0xc),
                    *(unsigned int *)MK4_PTR(iVar2 + 0xe0),
                    *(unsigned int *)MK4_PTR(iVar2 + 0x84),
                    *(unsigned int *)MK4_PTR(iVar2 + 8)); } }
#endif
#ifdef TARGET_SDL
      /* MK4_TRACE_DISPATCH: one line per controller the pump actually runs,
       * so two builds can be diffed to see which callback stops firing. */
      { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        static unsigned int seq;
        if (getenv("MK4_TRACE_DISPATCH"))
            SDL_Log("DISP #%u node=%x cb=%08x", seq++, iVar2,
                    *(unsigned int *)MK4_PTR(iVar2 + 0xd8)); }
#endif
      /* Node +0xd8 holds a stored CODE VA, so it needs both seams: MK4_PTR to
       * read the slot out of the arena, and MK4_ResolveCode to turn the VA it
       * contains into the native function. */
      ((void (*)(void))MK4_ResolveCode(*(unsigned int *)MK4_PTR(iVar2 + 0xd8)))();
#ifdef TARGET_SDL
      /* MK4_TRACE_PAD: the input aggregate at 0x4d50b8. The ORIGINAL never
       * writes it in any direct encoding - a full sweep of the image finds
       * zero write-form references - so the game only reads it and the native
       * publisher is its only writer. Yet it reads 1 in engine_frame.c and 0
       * in the loader on the SAME frame, so something between them clears it
       * indirectly. Report every change with the callback that had just run. */
      { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        static int tr = -1; static unsigned char last; static unsigned n;
        unsigned char pad;
        if (tr < 0) tr = getenv("MK4_TRACE_PAD") != 0;
        pad = *(unsigned char *)MK4_VA(unsigned char, 0x4d50b8u);
        if (tr && pad != last && n < 30) { n++;
            extern unsigned int g_mk4FrameNo;
            SDL_Log("PAD f=%u %02x -> %02x after cb=%08x node=%x", g_mk4FrameNo,
                    last, pad, *(unsigned int *)MK4_PTR(iVar2 + 0xd8), iVar2); }
        last = pad; }
      /* MK4_TRACE_SLOT0: node 0x53e368 is the shared root screen slot - eight
       * different controllers run on it in one front-end pass. A controller
       * that re-arms it (+8 = self) only gets its visit if nothing else
       * writes +8 before the node's +0xdc timer expires, so a lost re-arm is
       * invisible unless the slot's +8 is watched. Report every change, with
       * the callback that had just run. */
      { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        static int tr = -1; static unsigned int last; static unsigned n;
        unsigned int plus8;
        if (tr < 0) tr = getenv("MK4_TRACE_SLOT0") != 0;
        plus8 = *(unsigned int *)MK4_VA(unsigned int, 0x53e368u + 8u);
        if (tr && plus8 != last && n < 300) { n++;
            SDL_Log("SLOT0 +8 %08x -> %08x after cb=%08x (timer=%d)", last,
                    plus8, *(unsigned int *)MK4_PTR(iVar2 + 0xd8),
                    (int)*(short *)MK4_VA(short, 0x53e368u + 0xdcu)); }
        last = plus8; }
      /* MK4_TRACE_GAMEMODE: the pump's filter at 0x543800 decides which
       * controllers run at all - 0 means "no filter", so everything
       * installed anywhere is dispatched, the mode-select menu included,
       * even while the select and the tower are on screen. It is set to a
       * controller VA (or -1) when a mode takes over the world, and it goes
       * back to 0 one frame after MK4_MAIN_MENU sets it. Report the
       * transition and name the callback that had just run, which is the
       * only practical way to find the writer: scanning the image for the
       * store gives false positives that straddle instruction boundaries. */
      { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        static int tr = -1; static unsigned int last; static unsigned n;
        unsigned int gm;
        if (tr < 0) tr = getenv("MK4_TRACE_GAMEMODE") != 0;
        gm = g_gameMode;
        if (tr && gm != last && n < 24) { n++;
            SDL_Log("GAMEMODE %08x -> %08x after cb=%08x node=%x", last, gm,
                    *(unsigned int *)MK4_PTR(iVar2 + 0xd8), iVar2); }
        last = gm; }
      /* MK4_TRACE_MSTACK: the matrix-stack pointer at 0x4d57ac is a packed
       * node index, so its live value is around 0x150000. A controller that
       * leaves it below the packed floor has cleared it, and the NEXT mstack
       * push then writes through index 0 or 1 - which is arena + 4, the wild
       * address three separate crash captures landed on. Naming the callback
       * that cleared it turns that crash into a one-line report. */
      { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        static unsigned n; static int armed;
        unsigned int top = (unsigned int)g_matrixStackTop;
        /* 0 is the legitimate value before the stack is set up at boot, so
         * arm on the first sane reading and only report a fall AFTER that. */
        if (top >= 0x100000u) armed = 1;
        if (armed && getenv("MK4_TRACE_MSTACK") && top < 0x100000u && n < 8) { n++;
            SDL_Log("MSTACK CLEARED to %08x by cb=%08x node=%x", top,
                    *(unsigned int *)MK4_PTR(iVar2 + 0xd8), iVar2); } }
      /* MK4_TRACE_REGISTRY: the record registry's first slot at 0x543200 is
       * a node handle; if a controller leaves a small integer there, the
       * unbounded hunt in MStackPushTableWalk dereferences it and dies at
       * arena + 4. Watch it across dispatches and name the writer. */
      { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        static unsigned int last = 0xffffffffu; static unsigned n;
        unsigned int r0 = *(unsigned int *)MK4_VA(unsigned int, 0x543200u);
        if (getenv("MK4_TRACE_REGISTRY") && r0 != last && n < 16) { n++;
            SDL_Log("REGISTRY[0] %08x -> %08x after cb=%08x node=%x%s",
                    last, r0, g_dispatchSave105, iVar2,
                    (r0 != 0 && r0 < 0x100000u) ? "  <-- NOT A HANDLE" : "");
            last = r0; }
        else if (r0 != last) last = r0; }
#endif
#ifdef TARGET_SDL
      /* MK4_TRACE_BADIDX: a controller that LEAVES a packed index outside the
       * arena. g_currentNodeIdx and g_xformEntityIdx are VA>>2, so anything
       * outside [0x100000, 0x8e8000) is not addressable - and the walks that
       * consume them (BootChainStreamWalkExtract, Helper_TickAlt) multiply by
       * four and deref with no bound, so the process dies several frames
       * later somewhere else entirely. This names the controller that left
       * it, which is the part the backtrace cannot tell you. */
      { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        static unsigned n;
        unsigned int cur = *(unsigned int *)MK4_VA(unsigned int, 0x542044u);
        unsigned int ent = *(unsigned int *)MK4_VA(unsigned int, 0x542048u);
        int badCur = (cur != 0 && (cur < 0x100000u || cur >= 0x8e8000u));
        int badEnt = (ent != 0 && (ent < 0x100000u || ent >= 0x8e8000u));
        if (getenv("MK4_TRACE_BADIDX") && n < 12 && (badCur || badEnt)) { n++;
            SDL_Log("BADIDX after cb=%08x node=%x: currentNodeIdx=%08x%s "
                    "xformEntityIdx=%08x%s", g_dispatchSave105, iVar2,
                    cur, badCur ? " BAD" : "", ent, badEnt ? " BAD" : ""); } }
#endif
#ifdef TARGET_SDL
      /* MK4_TRACE_SELFLINK: the entity list headed at 0x535df0 must never
       * contain a node whose next (+0) points at itself - Helper_TickAlt
       * walks it to a 0 terminator and a self-link live-locks the frame.
       * Checked right after every dispatch so the controller that created
       * it is the one named. */
      { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
        static int seen;
        if (!seen && getenv("MK4_TRACE_SELFLINK")) {
            unsigned int h = *(unsigned int *)MK4_VA(unsigned int, 0x535df0u);
            if (h != 0 && *(unsigned int *)MK4_PTR(h * 4u) == h) { seen = 1;
                SDL_Log("SELFLINK head=%x after cb=%08x", h, g_dispatchSave105); } } }
#endif
      if ((*(int *)MK4_PTR((iVar2 + 0xd8)) != -1) && (*(int *)MK4_PTR((iVar2 + 0xd8)) != 0)) {
        *(undefined4 *)MK4_PTR((iVar2 + 0xd8)) = MK4_NODE_AT(undefined4, g_baseSel, 8);
        iVar1 = g_baseSel * 4;
        *(undefined4 *)MK4_PTR((iVar1 + 0x14)) = g_eventQueueNotMask;
        *(undefined4 *)MK4_PTR((iVar1 + 0x18)) = g_eventQueueChild;
        *(undefined4 *)MK4_PTR((iVar1 + 0x1c)) = g_currentNodeFlags;
        *(undefined4 *)MK4_PTR((iVar1 + 0x20)) = g_xformScratch2088;
        *(undefined4 *)MK4_PTR((iVar1 + 0x10)) = g_dualC;
        *(undefined4 *)MK4_PTR((iVar1 + 0x24)) = g_cj_00542054;
        *(undefined4 *)MK4_PTR((iVar1 + 0x28)) = g_cj_00542058;
        *(undefined4 *)MK4_PTR((iVar1 + 0x2c)) = g_cj_0054205c;
        *(undefined2 *)MK4_PTR((iVar2 + 0xdc)) = (undefined2)g_dualC;
      }
    }
    if (*(int *)MK4_PTR((iVar2 + 0xd8)) != -1) goto LAB_0041f6ef;
    iVar1 = *(int *)MK4_PTR((iVar2 + 0xe4));
    /* NodeUnlink wants a HOST pointer - it compares MK4_UNPTR(node) against
     * the slot table - so the VA form silently freed nothing and every node
     * ScaledNeg1SetPause marked with -1 at +0xd8 stayed allocated. On the
     * character select that is one leaked node per direction event: hold a
     * key and the 64 slots fill, after which AllocateNode spins forever
     * looking for a free one. `sample` on the hung process put every stack
     * in AllocateNode under EventQueueDrainLoop.
     *
     * This was left as the VA form on 2026-08-31 because fixing it alone
     * dropped MK4_BOOT_MATCH from 307200 to 2759 px. That regression was a
     * symptom of the cosine table and the missing walk-compare predicate,
     * both since fixed; with those in place the unlink is correct here too
     * and the boot path is unchanged. */
    NodeUnlink(MK4_PTR(iVar2));
    iVar2 = iVar1;
  } while( true );
}
#else
__declspec(naked) void BootScheduledNodeTimerWalk(void)
{
    __asm
    {
        push    ebx
        push    esi
        mov     esi, dword ptr [g_nodeListTail]
        xor     ebx, ebx
        cmp     esi, ebx
        je      L_bsntw_done
        push    edi
        push    ebp
        or      ebp, 0xffffffff
    L_bsntw_loop:
        mov     eax, dword ptr [g_gameMode]
        cmp     eax, ebx
        je      short L_bsntw_proc
        cmp     eax, dword ptr [esi + 0xd8]
        je      short L_bsntw_proc
        cmp     dword ptr [esi + 0xe0], 0x11
        jne     L_bsntw_nextNode
    L_bsntw_proc:
        dec     word ptr [esi + 0xdc]
        cmp     word ptr [esi + 0xdc], bx
        jg      L_bsntw_checkDead
        mov     eax, esi
        sar     eax, 2
        mov     dword ptr [g_baseSel], eax
        mov     ecx, dword ptr [eax*4 + 0x14]
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     edx, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_eventQueueChild], edx
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     edx, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_eventQueueIdx], edx
        mov     ecx, dword ptr [eax*4 + 8]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0x2c]
        mov     dword ptr [g_fightGroupHead], edx
        mov     ecx, dword ptr [eax*4 + 0x1c]
        mov     dword ptr [g_currentNodeFlags], ecx
        mov     edx, dword ptr [eax*4 + 0x20]
        mov     dword ptr [g_xformScratch2088], edx
        mov     eax, dword ptr [eax*4 + 8]
        mov     dword ptr [esi + 0xd8], eax
        mov     dword ptr [g_framePauseFlag], ebx
        mov     ecx, dword ptr [esi + 0xd8]
        mov     dword ptr [g_dispatchSave105], ecx
        call    dword ptr [esi + 0xd8]
        mov     eax, dword ptr [esi + 0xd8]
        cmp     eax, ebp
        je      short L_bsntw_checkDead
        cmp     eax, ebx
        jbe     short L_bsntw_checkDead
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [edx*4 + 8]
        mov     dword ptr [esi + 0xd8], eax
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_eventQueueNotMask]
        lea     eax, [ecx*4]
        mov     dword ptr [eax + 0x14], edx
        mov     ecx, dword ptr [g_eventQueueChild]
        mov     dword ptr [eax + 0x18], ecx
        mov     edx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [eax + 0x1c], edx
        mov     ecx, dword ptr [g_xformScratch2088]
        mov     dword ptr [eax + 0x20], ecx
        mov     edx, dword ptr [g_pendingNodeType]
        mov     dword ptr [eax + 0x10], edx
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [eax + 0x24], ecx
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [eax + 0x28], edx
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax + 0x2c], ecx
        mov     dx, word ptr [g_pendingNodeType]
        mov     word ptr [esi + 0xdc], dx
    L_bsntw_checkDead:
        cmp     dword ptr [esi + 0xd8], ebp
        jne     short L_bsntw_nextNode
        mov     edi, dword ptr [esi + 0xe4]
        push    esi
        call    NodeUnlink
        add     esp, 4
        mov     esi, edi
        jmp     short L_bsntw_loopEnd
    L_bsntw_nextNode:
        mov     esi, dword ptr [esi + 0xe4]
    L_bsntw_loopEnd:
        cmp     esi, ebx
        jne     L_bsntw_loop
        pop     ebp
        pop     edi
    L_bsntw_done:
        mov     dword ptr [g_framePauseFlag], ebx
        pop     esi
        pop     ebx
        ret
    }
}
#endif
