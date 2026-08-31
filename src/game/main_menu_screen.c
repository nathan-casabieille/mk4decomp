/**
 * The MAIN MENU - the mode select screen: ARCADE / TEAM / ENDURANCE /
 * TOURNAMENT / PRACTICE / EXIT GAME. PendingMatch_004a2a80 is its
 * controller (the name is the auto-namer's); the attract sequencer
 * (0x401b70) chains it when the title cycle decides to show the menu, and
 * MK4_MAIN_MENU=<frame> in the SDL backend schedules it directly.
 *
 * The screen is SCENE NODES, not a DrawMenu overlay: VoiceMixerTickDispatch
 * (also misnamed) walks the mode table at 0x4f308c - ten rows of 0x1c
 * bytes: text, x (written back), y << 16, colour flags, nav bytes, the
 * MODE HANDLER, and a slot id - and builds one text object per row through
 * the text band, parking each node at controller[+id*4]. Rows 6..9 are the
 * corner markers, shifted +-0xf0.
 *
 * Controller states:
 *   0  reset the mode-config global block; a set 0x543718 means "restart
 *      into the game" (GameMode_EnterScene), a set 0x4f3198 detours to the
 *      hi-score chain, else fall into 1.
 *   1,2  FiveTableWalkInit passes, then the menu background .geo pair
 *      (0x503308, 0x506c50) through the real loader; park as 3.
 *   3  BUILD: the two title records placed (the logo via the 0x508404 /
 *      0x508420 record walks), the menu rows, selection = 0, the 0x708
 *      idle countdown; park as 4.
 *   4  INPUT: VoiceTableInit repaints, DualBitFlagAudioChain moves the
 *      selection by the rows' nav bytes on the 0x4d50b4 up/down bits,
 *      ScaledAudioDualShuffle parks the highlight node (0x5437f0) beside
 *      the selected row, TripleCallByteCheck confirms - the row's handler
 *      is parked in 0x543574 and the fade (InstallSelfPackedF80) chains to
 *      state 5. The idle countdown chains to 8 (the attract demo) instead.
 *   5..7  call the parked mode handler.
 *   8+  pop back to the attract sequencer.
 *
 * SetNodePosFromTriple is the real content of the Title_PressStartScreen
 * symbol (it just plants a position triple); the same symbol packs the
 * PRESS-START blinker controller at 0x4a2090.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void GuardedSetupCallTailJmp(unsigned int textVA, unsigned int y);
extern void Push16Call(void);
extern void PushSetCallPop(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void LoadGeoAsset_Default(void);
extern void StackPopDispatchTagged(void);
extern void BootInitGuardedCallChain(void);
extern void CopyGlobal(void);
extern void DualAddSar(void);
extern int  TripleCallByteCheck(void);
extern void *MK4_ResolveCode(unsigned int va);
extern void Helper_AudioStub_2960(int pan);
extern void SetJmp_Push16Call_004a1ad0(void);
extern void TableWalkBoundedCmp(int kind);
extern void AudioStateClearAndChainStep(void);
/* still-hollow leaves, weak no-ops until converted */
extern void Config_RestoreGlobals(void);
extern void GameMode_EnterScene(void);
extern void InstallSelfStateMachine6(void);
extern void InstallSelfPackedF80(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_padBitsP12      (*(unsigned int *)MK4_VA(unsigned int, 0x4d50b4u))
#define g_menuCursorNode  (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_modeHandler     (*(unsigned int *)MK4_VA(unsigned int, 0x543574u))
#define g_titleLogoNode   (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_titleSubNode    (*(unsigned int *)MK4_VA(unsigned int, 0x535e6cu))
#define g_restartFlag     (*(unsigned int *)MK4_VA(unsigned int, 0x543718u))
#define g_hiscoreFlag     (*(unsigned int *)MK4_VA(unsigned int, 0x4f3198u))
#define g_skipByte        (*(unsigned char *)MK4_VA(unsigned char, 0x4f319cu))

#define MODE_TABLE 0x4f308cu                     /* 10 rows * 0x1c */
#define MENU_VA    0x4a2a80u

static unsigned int mm_row(unsigned int i) { return MODE_TABLE + i * 0x1cu; }

/* FiveTableWalkInit (0x403c90): the menu/title SCENE RESET - clear the
 * five record kinds, then load the shared scene .geo at 0x506c20 TWICE
 * (the second load is the original's, not a slip), reset the audio chain
 * and the title node's transform. This carries the menu's CAMERA: with it
 * hollow, CameraSetupAndCullFan never runs, nothing calls
 * Color15BitPacker(0x50,0x50,0x50), every queue record ships a zero colour
 * word, and the shade-0 CLUT page paints the whole screen black. That is
 * the entire reason the main menu came up unreadable. */
void FiveTableWalkInit(void)
{
    unsigned int node;

    TableWalkBoundedCmp(2);
    TableWalkBoundedCmp(3);
    TableWalkBoundedCmp(4);
    TableWalkBoundedCmp(5);
    TableWalkBoundedCmp(7);
    BootInitGuardedCallChain();
    if (g_framePauseFlag != 0) return;

    g_currentNodeIdx = 0x506c20u >> 2;
    LoadGeoAsset_Default();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = 0x506c20u >> 2;
    LoadGeoAsset_Default();
    if (g_framePauseFlag != 0) return;

    AudioStateClearAndChainStep();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = 0;
    CopyGlobal();
    if (g_framePauseFlag != 0) return;

    node = g_titleLogoNode;
    g_currentNodeIdx = node;
    MK4_NODE_AT(unsigned int, node, 0x60) = 0;
    MK4_NODE_AT(unsigned int, node, 0x64) = 0;
    MK4_NODE_AT(unsigned int, node, 0x68) = 0;
    MK4_NODE_AT(unsigned int, node, 0x54) = 0;
    MK4_NODE_AT(unsigned int, node, 0x58) = 0;
    g_walkSlot6c = 0xfff88000u;
    MK4_NODE_AT(unsigned int, node, 0x5c) = 0xfff88000u;
}

/* spawn a record instance and place it - the row-marker dragons beside the
 * six mode lines, registered in the array at 0x543750 */
void AudioInitArgs3(unsigned int recVA, unsigned int x, unsigned int y,
                    unsigned int z)
{
    unsigned int node, n;

    g_xformEntityIdx = recVA >> 2;
    DispatcherComplex260_FramePauseScaledStore();
    if (g_framePauseFlag != 0) return;
    node = g_currentNodeIdx;
    if (node == 0) return;
    n = *MK4_VA(unsigned int, 0x543748u);
    *MK4_VA(unsigned int, 0x543750u + n * 4u) = node;
    *MK4_VA(unsigned int, 0x543748u) = n + 1;
    MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0();
    if (g_framePauseFlag != 0) return;
    node = g_currentNodeIdx;
    MK4_NODE_AT(unsigned int, node, 0x54) = x;
    MK4_NODE_AT(unsigned int, node, 0x58) = y;
    MK4_NODE_AT(unsigned int, node, 0x5c) = z;
}

/* the SELECTION CURSOR: spawned once from its record, parked in 0x5437f0,
 * parked offscreen until ScaledAudioDualShuffle moves it beside a row */
void AudioBindEntry(unsigned int recVA)
{
    unsigned int node;

    if (g_menuCursorNode != 0)
        return;
    g_xformEntityIdx = recVA >> 2;
    DispatcherComplex260_FramePauseScaledStore();
    if (g_framePauseFlag != 0) return;
    node = g_currentNodeIdx;
    if (node == 0) return;
    g_menuCursorNode = node;
    MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0();
    if (g_framePauseFlag != 0) return;
    node = g_currentNodeIdx;
    MK4_NODE_AT(unsigned int, node, 0x54) = 0;
    MK4_NODE_AT(unsigned int, node, 0x58) = 0xf0600000u;
    MK4_NODE_AT(unsigned int, node, 0x5c) = 0x10000;
}

void SetNodePosFromTriple(unsigned int node, unsigned int tripleVA)
{
    MK4_NODE_AT(unsigned int, node, 0x54) = *MK4_VA(unsigned int, tripleVA);
    MK4_NODE_AT(unsigned int, node, 0x58) = *MK4_VA(unsigned int, tripleVA + 4u);
    MK4_NODE_AT(unsigned int, node, 0x5c) = *MK4_VA(unsigned int, tripleVA + 8u);
}

/* 0x4a2090, packed in the same symbol: the PRESS START blinker - toggles
 * the tracked colour word between 0x1f4 and 0x287 every 0xf ticks */
void PressStartBlinker_004a2090(void)
{
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    if (cmd != 0) {
        unsigned int slot = g_slot54;
        unsigned int v = *(unsigned int *)MK4_PTR(slot * 4);

        *(unsigned int *)MK4_PTR(slot * 4) =
            (v != 0x870000u) ? 0x1f40000u : (0x1f40000u + 0xfe930000u);
    }
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x4a2090u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 0xf;
    g_framePauseFlag = 1;
}

/* the menu items: one text object per mode-table row, node parked at
 * controller[+id*4] */
void VoiceMixerTickDispatch(void)
{
    unsigned int i, row, node;

    /* the six row markers (one dragon per mode line, y - 5), then the
     * selection cursor */
    for (i = 0; i < 6; i++) {
        unsigned int y = *MK4_VA(unsigned int, mm_row(i) + 8u);

        AudioInitArgs3(0x515964u, 0, y - 0x50000u, 0x10000);
    }
    AudioBindEntry(0x4f62f8u);

    for (i = 0; i < 10; i++) {
        row = mm_row(i);
        g_walkSlot6c = *MK4_VA(unsigned int, row + 8u);      /* y << 16 */
        g_currentNodeIdx = *MK4_VA(unsigned int, row);
        GuardedSetupCallTailJmp(*MK4_VA(unsigned int, row),
                                *MK4_VA(unsigned int, row + 8u));
        node = g_currentNodeIdx;
        if (i >= 6 && i <= 9) {
            if (i < 8)
                MK4_NODE_AT(unsigned int, node, 0x54) -= 0xf00000u;
            else
                MK4_NODE_AT(unsigned int, node, 0x54) += 0xf00000u;
        }
        MK4_NODE_AT(unsigned int, node, 0x5c) =
            *MK4_VA(unsigned int, row + 0xcu);
        /* write the final x back into the table, park the node in the
         * controller's slot for this row */
        *MK4_VA(unsigned int, row + 4u) =
            MK4_NODE_AT(unsigned int, node, 0x54);
        g_slot70 = (unsigned int)(int)*MK4_VA(signed char, row - 4u);
        *(unsigned int *)MK4_PTR(
            (g_baseSel + (unsigned int)(int)*MK4_VA(signed char, row - 4u)) * 4) = node;
    }
}

/* repaint every row from the table; a non-zero arg also resets y */
void VoiceTableInit(int reset_y)
{
    unsigned int i, row, node;

    for (i = 0; i < 10; i++) {
        row = mm_row(i);
        node = *(unsigned int *)MK4_PTR(
            (g_baseSel + (unsigned int)(int)*MK4_VA(signed char, row - 4u)) * 4);
        g_currentNodeIdx = node;
        g_walkSlot6c = MK4_NODE_AT(unsigned int, node, 0x58);
        MK4_NODE_AT(unsigned int, node, 0x54) = *MK4_VA(unsigned int, row + 4u);
        if (reset_y != 0)
            MK4_NODE_AT(unsigned int, node, 0x58) = *MK4_VA(unsigned int, row + 8u);
        MK4_NODE_AT(unsigned int, node, 0x5c) = *MK4_VA(unsigned int, row + 0xcu);
        MK4_NODE_AT(unsigned int, node, 0x6c) = 0;
        MK4_NODE_AT(unsigned int, node, 0x70) = 0;
    }
}

/* navigation: the rows' nav bytes at row+0x10 (up) / row+0x11 (down),
 * driven by the pad bits 1/2 (either player's byte) */
void DualBitFlagAudioChain(void)
{
    unsigned int bits = g_padBitsP12;
    unsigned int sel, row;
    int tgt;

    if ((bits & 0x101u) != 0) {
        sel = MK4_NODE_AT(unsigned int, g_baseSel, 0x30);
        row = mm_row(sel);
        tgt = (int)*MK4_VA(signed char, row - 0xcu);
        g_walkSlot6c = (unsigned int)tgt;
        if (tgt != -1) {
            MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = (unsigned int)tgt;
            SetJmp_Push16Call_004a1ad0();
        }
        g_slot80 = 0x708;
        Helper_AudioStub_2960(0x160000);
        bits = g_padBitsP12;
    }
    if ((bits & 0x202u) != 0) {
        sel = MK4_NODE_AT(unsigned int, g_baseSel, 0x30);
        row = mm_row(sel);
        tgt = (int)*MK4_VA(signed char, row - 0xbu);
        g_walkSlot6c = (unsigned int)tgt;
        if (tgt != -1) {
            MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = (unsigned int)tgt;
            SetJmp_Push16Call_004a1ad0();
        }
        g_slot80 = 0x708;
        Helper_AudioStub_2960(-0x160000);
    }
}

/* the highlight: park the cursor node beside the selected row */
void ScaledAudioDualShuffle(void)
{
    unsigned int sel = MK4_NODE_AT(unsigned int, g_baseSel, 0x30);
    unsigned int row = mm_row(sel);
    unsigned int item, cur;

    item = *(unsigned int *)MK4_PTR(
        (g_baseSel + (unsigned int)(int)*MK4_VA(signed char, row - 4u)) * 4);
    g_currentNodeIdx = item;
    cur = g_menuCursorNode;
    MK4_NODE_AT(unsigned int, cur, 0x58) =
        MK4_NODE_AT(unsigned int, item, 0x58) - 0x50000u;
    MK4_NODE_AT(unsigned int, cur, 0x5c) =
        MK4_NODE_AT(unsigned int, item, 0x5c);
}

void PendingMatch_004a2a80(void)
{
    unsigned int cmd, q;

    Config_RestoreGlobals();
    cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

#ifdef TARGET_SDL
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      if (getenv("MK4_TRACE_MM"))
          SDL_Log("MM cmd=%u sel=%u pause=%u", cmd,
                  MK4_NODE_AT(unsigned int, g_baseSel, 0x30), g_framePauseFlag); }
#endif

    switch (cmd) {
    case 0: {                                    /* 0x4a2d4a: mode reset */
        static const unsigned int zeros[] = {
            0x543744u, 0x543388u, 0x543714u, 0x543568u, 0x54356cu,
            0x543438u, 0x54355cu, 0x543710u, 0x543838u, 0x543374u,
            0x54338cu, 0x54337cu, 0x543378u, 0x543390u, 0x543380u,
            0x541ec4u, 0x541ec8u, 0x52ab40u, 0x543400u,
        };
        unsigned int i, restart;

        TableWalkBoundedCmp(8);
        *MK4_VA(unsigned int, 0x542004u) = 0;
        *MK4_VA(unsigned int, 0x53a498u) = 0;
        g_walkSlot6c = 0;
        CopyGlobal();
        *MK4_VA(unsigned int, 0x543564u) = *MK4_VA(unsigned int, 0x4f361cu);
        *MK4_VA(unsigned int, 0x543594u) = *MK4_VA(unsigned int, 0x4f361cu);
        restart = g_restartFlag;
        *MK4_VA(unsigned char, 0x543720u) = 0;
        *MK4_VA(unsigned int, 0x54370cu) = 1;
        for (i = 0; i < sizeof zeros / sizeof zeros[0]; i++)
            *MK4_VA(unsigned int, zeros[i]) = 0;
        *MK4_VA(unsigned char, 0x4d5714u) = 1;
        g_restartFlag = 0;
        if (restart != 0) {
            *MK4_VA(unsigned char, 0x543590u) =
                *MK4_VA(unsigned char, 0x5433f8u);
            GameMode_EnterScene();
            return;
        }
        *MK4_VA(unsigned int, 0x52aac4u) = 2;
        *MK4_VA(unsigned int, 0x53a50cu) = 1;
        if (g_hiscoreFlag != 0) {
            g_hiscoreFlag = 0;
            MK4_NODE_AT(unsigned int, g_baseSel, 8) = MENU_VA;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
            q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
            g_currentNodeIdx = q;
            *(unsigned int *)MK4_PTR(q * 4) = MENU_VA + 0x1000000u;
            g_currentNodeIdx = q + 1;
            MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
            MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
            InstallSelfStateMachine6();
            g_framePauseFlag = 1;
            return;
        }
        goto state1_body;
    }

    case 1:
    state1_body:                                 /* 0x4a2ea1 */
        FiveTableWalkInit();
        if (g_framePauseFlag != 0) return;
        if (g_skipByte != 0) {
            g_skipByte = 0;
            g_slot80 = 0;
        }
        goto state2_body;

    case 2:
    state2_body:                                 /* 0x4a2ecd */
        FiveTableWalkInit();
        if (g_framePauseFlag != 0) return;
        g_currentNodeIdx = 0x503308u >> 2;       /* the menu background */
        LoadGeoAsset_Default();
        if (g_framePauseFlag != 0) return;
        g_currentNodeIdx = 0x506c50u >> 2;
        LoadGeoAsset_Default();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = MENU_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 3;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;

    case 3:                                      /* 0x4a2ab3: BUILD */
        g_currentNodeIdx = g_titleLogoNode;
        SetNodePosFromTriple(g_titleLogoNode, 0x4f3050u);
        MK4_NODE_AT(unsigned int, g_titleLogoNode, 0x60) = 0xffffe000u;
        g_currentNodeIdx = g_titleSubNode;
        g_walkSlot6c = 0xf333;
        MK4_NODE_AT(unsigned int, g_titleSubNode, 0x3c) = 0xf333;
        SetNodePosFromTriple(g_titleSubNode, 0x4f3030u);
        g_xformEntityIdx = 0x508404u >> 2;
        DispatcherComplex260_FramePauseScaledStore();
        if (g_framePauseFlag != 0) return;
        if ((*MK4_VA(unsigned int, 0x54208cu) & 4u) == 0) {
            g_walkSlot6c = 0xff9c0000u;
            MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = 0xff9c0000u;
            PushSetCallPop();
            if (g_framePauseFlag != 0) return;
        }
        g_xformEntityIdx = 0x508420u >> 2;
        DispatcherComplex260_FramePauseScaledStore();
        if (g_framePauseFlag != 0) return;
        if ((*MK4_VA(unsigned int, 0x54208cu) & 4u) == 0) {
            g_walkSlot6c = 0x640000u;
            MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = 0x640000u;
            PushSetCallPop();
            if (g_framePauseFlag != 0) return;
        }
        g_slot74 = 0x51;
        Push16Call();
        VoiceMixerTickDispatch();
#ifdef TARGET_SDL
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          if (getenv("MK4_TRACE_MM")) {
              unsigned int it = *(unsigned int *)MK4_PTR((g_baseSel + 0xe) * 4);
              unsigned int gl = it ? MK4_NODE_AT(unsigned int, it, 0x18) : 0;
              SDL_Log("MM build: font4 tbl=0x%x  ARCADE node=0x%x pos=(%x,%x,%x) kind=0x%x glyph=0x%x rec=0x%x",
                      *MK4_VA(unsigned int, 0x541fd8u + 16u), it,
                      it ? MK4_NODE_AT(unsigned int, it, 0x54) : 0,
                      it ? MK4_NODE_AT(unsigned int, it, 0x58) : 0,
                      it ? MK4_NODE_AT(unsigned int, it, 0x5c) : 0,
                      it ? MK4_NODE_AT(unsigned int, it, 0x30) : 0,
                      gl, gl ? MK4_NODE_AT(unsigned int, gl, 0xc) : 0); } }
#endif
        VoiceTableInit(0);
        MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = 0;   /* selection */
        g_slot80 = 0x708;                        /* idle countdown */
        goto rearm4;

    case 4:                                      /* 0x4a2be4: INPUT */
        VoiceTableInit(0);
        DualBitFlagAudioChain();
        ScaledAudioDualShuffle();
        if (TripleCallByteCheck() != 0) {
            unsigned int sel = MK4_NODE_AT(unsigned int, g_baseSel, 0x30);
            /* the row struct is anchored 0xc BELOW the text field: nav
             * bytes at -0xc, HANDLER at -8, slot id at -4 - reading the
             * handler at +0x14 fetched the NEXT row's (the audit's
             * symmetric diff on 0x4f3084 is what caught it) */
            unsigned int handler = *MK4_VA(unsigned int, mm_row(sel) - 8u);

            g_currentNodeIdx = handler;
            if (handler != 0) {
                g_slot74 = 0x32a;                /* the select sound */
                Push16Call();
                g_modeHandler = handler;
                VoiceTableInit(0);
                g_slot70 = 0x20;
                MK4_NODE_AT(unsigned int, g_baseSel, 8) = MENU_VA;
                MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 5;
                q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
                g_currentNodeIdx = q;
                *(unsigned int *)MK4_PTR(q * 4) = MENU_VA + 0x5000000u;
                g_currentNodeIdx = q + 1;
                MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
                MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
                InstallSelfPackedF80();          /* the fade out */
                g_framePauseFlag = 1;
                return;
            }
        }
        if ((int)(g_slot80 - 1) > 0) {           /* idle countdown */
            g_slot80 -= 1;
            goto rearm4;
        }
        g_slot80 = 0x3c;                         /* demo kick-in */
        VoiceTableInit(0);
        g_slot70 = 0x20;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = MENU_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 8;
        q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
        g_currentNodeIdx = q;
        *(unsigned int *)MK4_PTR(q * 4) = MENU_VA + 0x8000000u;
        g_currentNodeIdx = q + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
        InstallSelfPackedF80();
        g_framePauseFlag = 1;
        return;

    rearm4:
        DualAddSar();
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = MENU_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 4;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;

    case 5:
    case 6:
    case 7:                                      /* 0x4a2c84: LAUNCH */
        ((void (*)(void))MK4_ResolveCode(g_modeHandler))();
        return;

    default:                                     /* 0x4a2f31: back out */
        g_slot74 = 0;
        Push16Call();
        if (g_framePauseFlag != 0) return;
        BootInitGuardedCallChain();
        StackPopDispatchTagged();
        return;
    }
}

#endif /* NON_MATCHING */
