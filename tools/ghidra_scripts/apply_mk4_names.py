# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython
#
# Applies MK4-specific names and comments discovered through reverse
# engineering. Idempotent: re-running just re-applies the same names.

from ghidra.program.model.symbol import SourceType
from ghidra.program.model.listing import CodeUnit
from ghidra.app.cmd.function import CreateFunctionCmd

FUNCTIONS = [
    (0x004acc50, "CheckInstallPath",
     "Reads HKLM\\Software\\GT Interactive\\Mortal Kombat 4\\1.00\\Path "
     "and chdir's to it. Returns false if the open, query, or chdir fails."),

    (0x004c48c0, "ShowErrorMessage",
     "Displays a modal MessageBoxA with title 'Mortal Kombat 4 Error'. "
     "Pumps up to 1000 pending messages first to drain the queue. "
     "Used as the generic fatal-error reporter."),

    (0x004ad210, "ComputeConfigHash",
     "Hash over the 588-byte Config blob's payload (bytes 4..583). "
     "Seed = 0x43464729 ('FCG)' in ASCII, likely Eurocom dev initials). "
     "Algorithm: hash += byte[i] << (i %% 23). The first 4 bytes of the "
     "Config blob are expected to equal this hash, or be 0xFFFFFFFF (skip)."),

    (0x004ad250, "DeobfuscateConfig",
     "XOR-deobfuscates the 588-byte Config blob in place. "
     "Per-byte key: byte[i] ^= (i * 123) & 0xff. "
     "Called before ComputeConfigHash so the hash is computed on plaintext."),

    (0x004acf90, "ResetConfigToDefaults",
     "Zeros the Config buffer then restores default settings (key bindings, "
     "audio levels, gameplay options) from a constant table at 0x004f46a0. "
     "Called when the on-disk Config is missing, corrupted, or hash-invalid."),

    (0x004ad270, "ValidateInstall",
     "Top-level install validator called early at startup. "
     "1. Delegates to CheckInstallPath; on failure, calls ShowErrorMessage. "
     "2. If running from DRIVE_FIXED, also reads and hash-validates Config. "
     "3. On Config mismatch, calls ResetConfigToDefaults but still returns "
     "true (Config validation is advisory, not blocking)."),

    (0x004c53c0, "WinMain",
     "Application WinMain. Signature: WinMain(HINSTANCE hInstance, "
     "HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow). Called once "
     "by the MSVC CRT entry at 0x004c6cb0. Performs a single-instance check "
     "via CreateFileMappingA('Mortal Kombat 4'), creates the main window, "
     "calls AppInit, then enters the infinite main-loop. Exits via SEH."),

    (0x004b2500, "AppInit",
     "Application/game initializer. Called by WinMain after the main window "
     "is created, before the main loop. Orchestrates 27 internal init "
     "helpers, including ValidateInstall. No Win32 imports except "
     "timeGetTime - pure subsystem wiring (renderer, audio, input, "
     "asset manager, etc.)."),

    (0x004c5070, "CreateMainWindow",
     "Creates and shows the main game window. RegisterClassA with class "
     "'Mortal Kombat 4', icon resource 128, IDC_ARROW cursor, BLACK_BRUSH "
     "background, WndProc at 0x004c49b0. CreateWindowExA centers a "
     "(0x140 + g_winExtraW)x(0xf0 + g_winExtraH) window inside the work "
     "area (SPI_GETWORKAREA). Stores the HWND in g_hMainWindow. Calls "
     "ShowErrorMessage on RegisterClass / CreateWindow failure."),

    (0x004c52a0, "PumpMessages",
     "Standard Win32 message pump. Uses PeekMessageA/GetMessageA + "
     "TranslateMessage + DispatchMessageA, with WaitMessage when idle. "
     "Called once per main-loop iteration in WinMain. On WM_QUIT, calls "
     "ExitGame. Also called once from FUN_004be250 (subsystem unknown)."),

    (0x004c4870, "ExitGame",
     "Graceful application shutdown. CloseHandle on the single-instance "
     "FileMappingA, SendNotifyMessageA (likely broadcasting close to "
     "subsystems), then calls FUN_004c6820 (CRT _exit). Called from: "
     "WinMain (when single-instance check fails), ShowErrorMessage (after "
     "displaying a fatal error), and PumpMessages (on WM_QUIT)."),

    (0x004c49b0, "WndProc",
     "Main window procedure. Registered via RegisterClassA in "
     "CreateMainWindow. Handles all messages for the game window - "
     "WM_PAINT, WM_KEYDOWN/UP, WM_CLOSE, WM_DESTROY, etc. Yet to be "
     "decompiled in detail."),

    (0x004c4510, "QueryMicroTimer",
     "Microsecond-precision timer. Uses QueryPerformanceCounter (with "
     "timeGetTime as fallback) and __ftol to convert the ratio. Returns "
     "an absolute time in microseconds. Used as the time base for the "
     "main-loop frame timer (0x411b us = 16.667 ms = 1/60 s)."),

    (0x004b2750, "MainLoopStep",
     "Body of the main game loop, called twice per outer iteration in "
     "WinMain followed by PumpMessages. Each invocation: (a) runs four "
     "subsystem helpers FUN_004b4200(1), FUN_004b26d0, FUN_004b42e0, "
     "FUN_004b3e90; (b) runs a fixed-step catch-up loop (max 3 extra "
     "ticks) recalling FUN_004b26d0 at 0x411b us = 60 Hz; (c) Sleeps "
     "(<=16 ms) to throttle the frame rate. Calling it twice per loop "
     "yields (work) then (sleep until next 60 Hz tick) - the double-call "
     "is the frame limiter mechanism. ASM-verified at 0x004c5446 and "
     "0x004c544b."),

    (0x004b26d0, "GameLogicStep",
     "Fixed-step game logic update at 60 Hz (only function rerun by "
     "MainLoopStep's catch-up loop). Per tick: increments frame "
     "counter, calls GameStateMachine(0) to advance the current state, "
     "runs auxiliary updates (FUN_004c37f0, FUN_004ac4b0, FUN_004bd990, "
     "FUN_0041fd70), and transitions to state 0xc (= settings/options?) "
     "if a specific condition is met (FUN_004b3db0 == 4 && DAT_004ffd78 "
     "== 0). NOT called from Gfx_Init priming - pure game state update, "
     "no rendering."),

    (0x0041fd70, "GameTick",
     "The actual gameplay tick - runs every fixed-step frame from "
     "GameLogicStep. Distinct from GameStateMachine (which handles "
     "menus). Gated by g_gameMode (DAT_00543800): 0 = active fight, "
     "other = paused/menu. Per call: dispatches per-entity tick "
     "(TickEntity_A/B based on game submode), runs physics + collision "
     "if in fight, ticks general entities (FUN_004a1d50), iterates over "
     "the 4 player slots updating their flags, runs misc subsystems "
     "(FUN_00405400/04227b0/04051e0), and decays camera-shake / RGB-"
     "lighting parameters via fixed-point lerp toward 0x8000. Supports "
     "up to 4 players (slot 0..3 in g_player<N>_NodeIdx)."),

    (0x004a4170, "DebugStub_NoOp_A",
     "1-byte stub (just `ret`). Was originally a debug/test hook in "
     "development builds; stripped to a no-op for release. Called 3× "
     "from GameTick but does nothing. Real per-entity tick happens in "
     "the scene-graph callback at LAB_004ba1c0 (called by TickAllEntities)."),

    (0x0041f290, "AllocateNode",
     "Scene-graph node allocator. Maintains a 63-slot pool starting at "
     "DAT_0053e440 (ending at DAT_00541e40), each slot 232 bytes "
     "(0xe8 = 0x3a dwords). Walks an existing linked list (via field "
     "+0xe4) to find the tail, then scans the pool for a free slot "
     "(field 0 == 0). On allocation: zeros out 0x84 bytes (most of "
     "the descriptor), copies several context globals into specific "
     "fields, writes magic 0x12345678 at +0xd4, increments "
     "DAT_00541e64 (alloc count), updates DAT_0052ab3c (head ptr) or "
     "the previous tail's next pointer. On pool exhaustion: sets "
     "error bits in DAT_0054208c and returns NULL."),

    (0x0049cb60, "AllocNode",
     "15-byte wrapper around AllocateNode that pulls the node type "
     "from DAT_0054204c (current node-context global). Heavily reused: "
     "14 distinct callers across the engine (entity tick, projectile "
     "spawn, hit event, etc.)."),

    (0x0045c5c0, "FightFrameStep",
     "Top-level per-frame fight update. Runs FightFrameStep_Inner 3 "
     "times with 3 different node-context tuples (5 indices each - "
     "g_currentNodeIdx, DAT_00542048, DAT_0054204c, DAT_00542050, "
     "DAT_0054205c). Suspected role: process inputs / state for 3 "
     "controllable entities (P1, P2, and a third - possibly P3, a "
     "shared input bus, or a debug controller). Each call's indices "
     "include consecutive pairs (e.g. 0x14e928/0x14e929) suggesting "
     "(prev, curr) state pairs. Called only when g_gameMode == 0 "
     "(active fight)."),

    (0x0045c6c0, "FightFrameStep_Inner",
     "Per-entity state evolution. Reads (curr_state, prev_state, "
     "expected_mask) from 3 node fields, XORs to detect changed bits, "
     "shifts state forward (prev = curr), and iterates a 'pattern "
     "table' (advancing by 2 per step) testing whether changed bits "
     "match. On match, queues an event into the circular ring at "
     "0x14e92e..0x14e942 (= 20 slots). Likely the input → "
     "special-move detection logic: pattern table holds move sequences "
     "(D, D-F, B-F, etc.) and queues spawn events when a sequence is "
     "completed."),

    (0x0045c820, "DispatchEventQueue",
     "Drains the action event queue at DAT_0053a2f0..DAT_0053a31c "
     "(circular buffer in range 0x14e92e..0x14e942 = 20 slots). For "
     "each pending event: sets type=0x11, calls AllocNode to spawn "
     "the resulting scene-graph node (projectile, hit effect, state "
     "transition...), clears the slot, advances the read pointer with "
     "wrap. Finally calls FUN_0045c8d0 to commit the new tail to "
     "DAT_0053a31c."),

    (0x0045c8d0, "DispatchEventQueue_Commit",
     "Tiny tail commit: DAT_0053a31c = DAT_00542048 (writes back the "
     "advanced read pointer)."),

    (0x004a4150, "DebugStub_NoOp_B",
     "1-byte stub (just `ret`). Companion to DebugStub_NoOp_A - also a "
     "stripped debug hook. Called from GameTick under different submode "
     "flags but does nothing in release builds."),

    (0x004b9e50, "TickAllEntities",
     "Per-frame entity update orchestrator. Iterates 6 root scene-"
     "graph subtrees (HUD, players, effects, BG, ... at indices "
     "0x14e9ce, 0x14e878, 0x150794, 0x14d77c, 0x14e8b0, 0x14e01c) and "
     "for each calls WalkSceneGraphSiblings with the per-entity tick "
     "callback at LAB_004ba1c0 (which dispatches based on player_id "
     "/ entity type). Some subtrees use FUN_004bae90 instead for "
     "menu-vs-fight specialization."),

    (0x00405400, "FrameFinalize",
     "End-of-frame counter increment. Calls TickAllEntities, then "
     "increments DAT_0053a79c (a separate frame counter). The last "
     "call in GameTick's pipeline."),

    (0x004ba130, "WalkSceneGraphSiblings",
     "Iterates a sibling linked list. Starts at g_currentNodeIdx, "
     "follows nodes[i].field_4 as the 'next' pointer, and invokes "
     "the callback in DAT_0054206c on each node. Stops on null "
     "next-pointer or when termination flag DAT_0054208c & 1 is set. "
     "Used by TickAllEntities to walk all entity siblings in each of "
     "the 6 logical subtrees."),

    (0x004b65c0, "DrawMenu",
     "Renders a menu - list of (string, ?) pairs centered on the "
     "screen, with fade-in animation (DAT_00ab4344 ramps 0..100 over "
     "~7 frames). Calls FUN_004b21d0 (draw text) for each item. Used "
     "as a generic UI helper across most game-state handlers."),

    (0x004ac4b0, "Audio_TimerTick",
     "Schedules background audio playback. Uses timeGetTime to check "
     "if the time-since-last-trigger exceeds the configured interval; "
     "if so, calls FUN_004ac650 to fire the next sound. Called every "
     "frame from GameLogicStep."),

    (0x004c37f0, "Audio_UpdateChannels",
     "Iterates the active sound-channel array at DAT_00f9eb80, calls "
     "vtable[0x24] (Tick method) on each non-empty channel, marks "
     "finished ones for cleanup, and removes them via FUN_004c3710 "
     "(close) + FUN_004c3490 (audio file release). Called every frame "
     "from GameLogicStep."),

    (0x004b6340, "GameStateMachine",
     "MK4's main game state machine / menu dispatcher. Reads "
     "g_gameState (DAT_00ab438c) and dispatches to one of 13 per-state "
     "handlers. Param controls transitions from state 0 (idle/main "
     "menu) to states 5/6/7/8/9/0xa/0xb/0xc - each is a distinct UI "
     "screen (arcade/vs/tournament/options/...). Sub-state range "
     "0x18..0x1c are nested screens. State 4 is the active fight. "
     "Called from: GameLogicStep (per-frame tick), AppInit (init), "
     "WndProc (key/event handling), PumpMessages (WM_QUIT path)."),

    (0x004b4200, "BeginFrame",
     "First phase of the per-frame render pipeline. Dispatches to a "
     "mode-specific begin function (Glide/D3D/SW), each producing an "
     "(x, y, ?) tuple, then calls SetViewport(x, y, w, h). Width/height "
     "are mode-dependent: 320x240 for mode 4 (SW windowed), 640x480 for "
     "mode 5 (SW hi-res). Takes one flag arg (always 1 in observed "
     "callers)."),

    (0x004b42e0, "DrawScene",
     "Second phase of the per-frame render pipeline. Wraps the work in "
     "a timeGetTime accumulator (g_drawSceneTimeMs at DAT_007afa00) - "
     "this function is profiled because it's the variable-time scene "
     "render. Dispatches to a mode-specific draw function via the "
     "current renderer mode."),

    (0x004b3e90, "PresentFrame",
     "Third phase of the per-frame render pipeline. Pure dispatch on "
     "g_currentRendererMode to one of 5 mode-specific present/flip "
     "functions. Also called from WndProc on WM_PAINT (mode 4 only) "
     "- Windows asks the app to repaint, so this is the present/blit."),

    (0x004bf330, "SetViewport",
     "(suspected) Sets the rendering viewport. Called by BeginFrame "
     "with (x, y, w, h). The (x, y) come from the mode-specific begin "
     "function; (w, h) are 320x240 for mode 4 / 640x480 for modes 1, 2, 5."),

    (0x004bf460, "FlushDrawQueue",
     "Sorts and flushes the per-frame draw queue. Logic: (1) zero a "
     "1024-dword bucket array g_drawQueueBuckets; (2) iterate "
     "g_drawQueueSize entries of 28 bytes each at g_drawQueue, building "
     "a histogram of the first ushort (sort key, possibly z or material); "
     "(3) cumulative-sum the buckets (counting sort); (4) iterate the "
     "queue again, dispatching each entry to a per-renderer-mode submit "
     "function (Glide: FUN_004b46f0, D3D: FUN_004adca0). Submits the "
     "triangles using vertex floats and short coordinates. Called only "
     "by DrawScene."),

    (0x004b2930, "Renderer4_EndScene_SW_Win",
     "Per-mode end-of-scene hook for renderer mode 4 (SW windowed). "
     "Just toggles a flag - no actual surface work in this mode."),

    (0x004adc20, "Renderer2_EndScene_D3D",
     "Per-mode end-of-scene hook for renderer mode 2 (D3D card). Calls "
     "an internal helper FUN_004adc60 then a COM vtable method at "
     "offset 0x2C of an IDirect3D-like object - likely EndScene or "
     "SwapBuffers. Stores the result in DAT_0058c7dc."),

    (0x004b46a0, "Renderer1_EndScene_Glide",
     "Per-mode end-of-scene hook for renderer mode 1 (Glide). Like SW "
     "windowed: just toggles a state flag. The actual Glide finalization "
     "happens in PresentFrame's mode-1 dispatch (FUN_004b46d0)."),

    (0x004af880, "Renderer3_EndScene_SW_FS",
     "Per-mode end-of-scene hook for renderer mode 3 (SW fullscreen). "
     "Calls a COM vtable method at offset 0x80 of an IDirectDrawSurface-"
     "like object - likely Unlock or Flip."),

    (0x004b00b0, "Renderer5_EndScene_SW_FS_Hi",
     "Per-mode end-of-scene hook for renderer mode 5 (SW fullscreen "
     "hi-res). Same vtable[0x80] pattern as mode 3."),

    (0x004c3360, "SubmitDrawEntry",
     "Submits one polygon (triangle or quad) to g_drawQueue with "
     "frustum culling. Input: a 28-byte entry already in screen space "
     "(3 short XY pairs at offsets 0..10, sort key at offset 0x12, "
     "flags at offset 0x1a - bit 0x20 toggles tri/quad behavior). "
     "Frustum bounds: X in [-100, 740], Y in [-100, 580] (extended "
     "640x480 + slack on each side). Copies 28 bytes into "
     "g_drawQueue[g_drawQueueSize] then remaps the sort key via the "
     "lookup table at DAT_00b0d008. Increments g_drawQueueSize. Skips "
     "if queue is full (3000 entries max)."),

    (0x004bb250, "DrawMeshBlock",
     "Walks one mesh block of a .geo asset and submits its triangles "
     "to the draw queue. Reads two parallel arrays: a HEADER stream of "
     "(uint16 flag, int16 count) pairs at block + 8 + ofs_b (terminated "
     "by count<0), and a VERTEX stream of (short x, y, z) triples at "
     "block + 4 + ofs_a. For each header entry, transforms 2 base "
     "vertices via TransformVertex (FUN_004b3310), then iterates "
     "`count` more vertices in an inner loop, doing back-face culling "
     "via a 2D cross product test before calling SubmitDrawEntry. "
     "Vertices are 16-bit signed integers (fixed-point), not floats."),

    (0x004b3310, "TransformVertex",
     "(suspected) Transforms a model-space vertex (short x, y, z) "
     "into screen-space coordinates. Output stored in DAT_007af95a / "
     "60 / 66 etc. Used heavily by DrawMeshBlock and FUN_004bbda0."),

    (0x004b2af0, "ProjectTwoVertices",
     "Projects two model-space vertices to screen-space. Reads input "
     "from g_xformBuf_v0 (DAT_007af958/95e/964) and g_xformBuf_v1_pos "
     "(DAT_007af95a/960/966), applies the modelview matrix at "
     "DAT_007af990 + viewport offset DAT_007af9a4/8/c, then perspective "
     "divides (1/z scaled to fixed-point) and scales to screen. Outputs "
     "v0 screen XY at DAT_007af9b4 (= g_triRingScreenXY[0]), v1 at "
     "DAT_007af9b8. Outputs v0/v1 Z at DAT_007af984/988. Viewport "
     "center is hardcoded 0x140 (320) x 0xf0 (240) - half of 640x480."),

    (0x004b2e80, "ProjectVertex",
     "Projects ONE model-space vertex (in g_xformBuf at DAT_007af95c/"
     "962/968) to screen-space. Outputs at DAT_007af9bc (= "
     "g_triRingScreenXY[2]), Z at DAT_007af98c. Same modelview-proj-"
     "viewport math as ProjectTwoVertices but for the new vertex of "
     "each triangle in the strip."),

    (0x004b2fa0, "AdvanceTriStripRing",
     "Advances the triangle-strip ring buffer by one vertex. Shifts "
     "screen-XY (g_triRingScreenXY[1]→[0], [2]→[1]) and Z values "
     "(g_triRingZ[1]→[0], [2]→[1]), then stores the new vertex's "
     "model-space coords (passed as args) into the v1 slot at "
     "DAT_007af95c/962/968. After this + ProjectVertex, the ring has "
     "(prev_prev, prev, new) ready to form the next triangle."),

    # ==== 3×3 rotation matrix builders (Euler-to-matrix) ====
    # Each builds a 3x3 matrix in fixed-point (param_2[0..8]) from 3 input
    # angles (param_1[0..2]). Uses g_sinTable as a 4096-entry sine lookup
    # (BAM = binary angle, 0x1000 = 2π). The (-0x400) offset trick lets a
    # single sin table provide cos as well: lookup[a-0x400] = -cos(a).
    # The 3 helpers correspond to 3 different Euler-axis orderings, used
    # for different joint types in the skeleton.

    (0x004b3800, "BuildRotMatrix_OrderA",
     "Builds a 3x3 rotation matrix from 3 Euler angles (Order A - exact "
     "axis order TBD). Uses g_sinTable (4096-entry, BAM-indexed). Output: "
     "9 int16 matrix elements in fixed-point (>> 12 for the divisor). "
     "Used by NodeApplyTransform_A and _A_Direct (most common joint type, "
     "node types 0/3/6/7)."),

    (0x004b36c0, "BuildRotMatrix_OrderC",
     "Builds a 3x3 rotation matrix from 3 Euler angles (Order C). Same "
     "pattern as BuildRotMatrix_OrderA but with different multiplication "
     "ordering (different Euler axis sequence). Used by "
     "NodeApplyTransform_C, _C_Inverse, _C_Direct (node types 1, 3)."),

    (0x004b3940, "BuildRotMatrix_OrderB",
     "Builds a 3x3 rotation matrix from 3 Euler angles (Order B). Used "
     "by NodeApplyTransform_B, _B_Direct, _B_Swapped (node types 2, 5)."),

    # ==== ECM cinematic format (Eurocom Custom Movie) ====
    (0x004b06f0, "ECM_Open",
     "Opens an Eurocom Custom Movie (ECM) file for threaded playback. "
     "Reads a 3608-byte header (0xe18) at DAT_007aa230, validates magic "
     "0x024D4345 ('ECM\\x02'). Header layout: [0..3] magic, [4..7] frame "
     "count, [8..0xe17] array of 900 int32 group offsets (each group ~15 "
     "frames). Allocates a DirectSound secondary buffer via the audio "
     "interface in param_2 (rate selectable: 11025, 22050, 44100 Hz; "
     "16-bit PCM). Seeks past skipped groups, then spawns a worker "
     "thread (LAB_004b0a50) that streams + decodes frames in the "
     "background. Returns frame count on success or 0."),

    (0x004b0cb0, "ECM_Cleanup",
     "Stops ECM playback and releases all resources. Signals the worker "
     "thread to exit (3-sec timeout), TerminateThread+CloseHandle as a "
     "fallback. Releases the DirectSound buffer (Stop, IUnknown::Release "
     "via vtable[8]). Zeros the 3608-byte header at DAT_007aa230. "
     "Closes the file via FUN_004c5800 (fclose). Idempotent - safe to "
     "call from any error path."),

    (0x004b0a50, "ECM_PlayThread",
     "Background thread function spawned by ECM_Open. Per iteration: "
     "fread one group (size = group_offsets[(frame_idx-1)/15]) into a "
     "buffer at DAT_006f7680, calls ECM_DecodeFrame for the video "
     "portion, then locks the DirectSound buffer at offset "
     "(slot * 0xac44) and decodes the audio portion via "
     "ESF_DecodeADPCM (output = 0xac44 = 44100 bytes = 1 second @ "
     "22050 Hz mono 16-bit). Advances frame_idx by 15 per group. "
     "Handles DSERR_BUFFERLOST (0x88780096) by Restore+Stop+re-Lock+zero. "
     "Sleeps until aborted via DAT_007ab078=0."),

    (0x004b1c90, "ECM_DecodeFrame",
     "Wrapper around ECM_DecodeFrameDispatch. Initializes a small "
     "8-dword state on the stack with input and output pointers, calls "
     "the dispatcher, returns state[3] (the produced byte count) or "
     "0 on error."),

    (0x004b1bf0, "ECM_DecodeFrameDispatch",
     "Parses the frame's 12-byte 'EDL' header (via ECM_ParseFrameHeader), "
     "then dispatches on mode: mode 0 → ECM_DecodeFrame_Raw (memmove "
     "of frame_size bytes), mode 1 → ECM_DecodeFrame_Huffman (entropy "
     "decode). Returns silently on header parse error."),

    (0x004b1c30, "ECM_ParseFrameHeader",
     "Parses the 12-byte frame header at state->src: magic 'EDL' (3 "
     "bytes), then mode + flag byte (bits 0-6 = mode 0 or 1, bit 7 = "
     "flag), then frame_size (uint32), then aux/extra (uint32). On "
     "missing 'EDL' magic, sets state->error = -3. On unsupported mode, "
     "sets state->error = -4. Otherwise stores parsed fields into "
     "state and clears the error flag."),

    (0x004b1220, "ECM_DecodeFrame_Raw",
     "Mode-0 frame decoder: trivial memmove of state->frame_size bytes "
     "from (state->src + 12) to state->dst. Handles overlap correctly "
     "(forward or backward copy as needed)."),

    (0x004b1270, "ECM_DecodeFrame_Huffman",
     "Mode-1 frame decoder: variable-length Huffman entropy decoder. "
     "~2400 bytes of code. Reads a bit stream from state->src + 12, "
     "builds a 16-symbol frequency table at stack+0x40, sorts symbols "
     "by frequency, builds a prefix-code table at stack+0x53c, and "
     "decodes state->frame_size bytes to state->dst. Full algorithm "
     "TBD - see FUN_004b1270 in Ghidra for the bit-twiddling. For "
     "porting, replacing ECM with a modern container (.webm/.mp4) is "
     "more practical than re-implementing this codec."),

    # ==== ESF audio format ====
    (0x004b1090, "ESF_Open",
     "Opens an ESF audio file via FSYS_fopen, reads the 8-byte header, "
     "validates the magic 0x06465345 ('ESF\\x06') and decodes the bit-"
     "packed format DWORD: bit 29=8/16-bit, bit 30=11025/22050 Hz, "
     "bit 31=mono/stereo, bits 0-28=decoded byte count. Returns the "
     "decoded byte count and writes bits/rate/stereo to the out args. "
     "Function name is preserved verbatim from embedded debug string "
     "'ESF_Open()'."),

    (0x004b1150, "ESF_ReadData",
     "Reads PCM samples from a previously-opened ESF file. For 8-bit "
     "files, reads raw unsigned PCM directly into the destination. For "
     "16-bit files, reads (header>>2)&0x7FFFFFF bytes of IMA-ADPCM "
     "into a temporary buffer at the END of the destination, then calls "
     "ESF_DecodeADPCM to expand it 4:1 into the destination. The "
     "encoded bytes are placed at dst+decoded_size-encoded_size-1 so "
     "that decoding writes forward without overwriting yet-unread input."),

    (0x004b1200, "ESF_Close",
     "Closes the currently-opened ESF file. Calls FSYS_fclose on the "
     "handle and zeroes the global handle slot."),

    (0x004ac200, "ESF_DecodeADPCM",
     "MK4's IMA ADPCM decoder. Args: (encoded_src, decoded_dst, "
     "decoded_byte_count, state_inout). State packs (predictor<<8 | "
     "step_index) in a single uint. High nibble first, then low. "
     "Standard IMA index/step tables at 0x004f44e0 / 0x004f4520 "
     "(verified). Output is signed int16 LE (16-bit PCM)."),

    (0x004b1f90, "FSYS_fclose",
     "(suspected) Close an FSYS file handle. Called by ESF_Close to "
     "release the audio file handle."),

    (0x004b1fb0, "FSYS_fread",
     "Standard fread wrapper over the FSYS layer. Args: (buf, size, "
     "count, handle). Calls CRT helpers FUN_004c5b70 / FUN_004c5a90 "
     "internally. Used by ESF_Open, ESF_ReadData, FSYS_fload, and "
     "several others."),

    (0x004b2070, "FSYS_fseek",
     "(suspected) Seek within an FSYS file handle. Called by "
     "ESF_ReadData with offset=8, whence=0 to skip past the ESF header."),

    (0x004bf290, "BuildSortKeyLUT",
     "Initializes the per-frame sort-key lookup table (g_zSortKeyLUT). "
     "Computes LUT[i] = i / (i * C1*C2 - C3) where C1=31, C2=2^-16, "
     "C3=-1, simplifying to LUT[i] = 65536*i / (31*i + 65536) for "
     "i in [0..65535]. This is a hyperbolic z-bucketing function: "
     "near-camera z values get fine bucket resolution (i=100 → 95), "
     "far-camera get compressed (i=65535 → 2047). Output is uint16. "
     "Also pre-zeros a 4 MB buffer at DAT_00b2d010 (probably the "
     "scratch space for the sort itself), and builds a 768-byte div-by-3 "
     "table at DAT_00f70ff8 used elsewhere."),

    # ==== Scene-graph node-type handlers (9 distinct, dispatched by RenderSceneNode) ====
    # All 9 have the same skeleton: read a 3-vector (x,y,z) from the
    # current node descriptor, apply via one of 3 transform helpers,
    # then mark the transform stack dirty (DAT_0054208c |= 0x30).
    # They are NOT renderers - they manipulate the transform-stack
    # state. The actual mesh rendering happens later in the recursive
    # descent (eventually reaching DrawMeshBlock / FUN_004bb030 etc.).
    # The 9 handlers correspond to a skeleton/joint hierarchy: each
    # node applies a local rotation/translation about a named axis.

    (0x004bdb50, "NodeApplyTransform_A",
     "Default node-type handler (idx 0, 6, 7 in g_nodeDispatchTable). "
     "Reads 3 ints from the node descriptor, scales by 0x28BE/0x40000 "
     "(approx 0.00995 - likely fixed-point angle conversion), negates, "
     "stores as 3 shorts at DAT_00ab5208/520a/520c, then calls "
     "transform helper FUN_004b3800 (axis A). Sets transform-dirty bits."),

    (0x004bde90, "NodeApplyTransform_C",
     "Type-1/mode-0 handler. Same skeleton as NodeApplyTransform_A but "
     "calls transform helper FUN_004b36c0 (axis C)."),

    (0x004bdca0, "NodeApplyTransform_B",
     "Type-2/mode-0 handler. Same skeleton as NodeApplyTransform_A but "
     "calls transform helper FUN_004b3940 (axis B)."),

    (0x004bdfb0, "NodeApplyTransform_C_Inverse",
     "Type-3/mode-0 handler. Like NodeApplyTransform_C but does NOT "
     "negate the 3-vector before applying. The inverse-rotation pair "
     "of NodeApplyTransform_C."),

    (0x004be050, "NodeApplyMatrix",
     "Type-4 handler (mode-agnostic). Copies a 9-dword (3x3 matrix?) "
     "transform from a sub-descriptor pointed to by node[+0x28] into "
     "the current transform slot. Push/pop on PTR_DAT_004d57ac stack. "
     "Different from the other handlers: bypasses the (x,y,z) input "
     "and applies a pre-computed matrix wholesale."),

    (0x004be130, "NodeApplyTransform_B_Swapped",
     "Type-5 handler (mode-agnostic). Reads 3 dwords from the node "
     "descriptor, REORDERS them [a,b,c]->[a,c,b] (swaps Y/Z or B/C "
     "axes) into a local 12-byte buffer, then delegates to "
     "NodeApplyTransform_B. Likely a coordinate-system flip."),

    (0x004bdc00, "NodeApplyTransform_A_Direct",
     "Mode-1 variant (idx 0, 3, 6, 7). Skips the angle-scaling step "
     "of NodeApplyTransform_A: reads 3 SHORTS directly from the node "
     "(already pre-converted to the target format), negates, and calls "
     "transform helper FUN_004b3800. Smaller (0x62 vs 0xa3 bytes)."),

    (0x004bdf40, "NodeApplyTransform_C_Direct",
     "Mode-1 variant (idx 1). Direct-short version of "
     "NodeApplyTransform_C (helper FUN_004b36c0)."),

    (0x004bdd50, "NodeApplyTransform_B_Direct",
     "Mode-1 variant (idx 2). Direct-short version of "
     "NodeApplyTransform_B (helper FUN_004b3940)."),

    (0x004ba720, "RenderSceneNode",
     "Recursive scene-graph node renderer. Sole caller of "
     "DrawMeshBlock. ASM-verified: at 0x004ba842, computes "
     "uVar9 = (flags>>24) & 7, plus 8 if (flags & 0x100), then calls "
     "g_nodeDispatchTable[uVar9] (an array of 16 function pointers at "
     "0x004f7888 dispatching to 9 distinct per-node-type handlers in "
     "the 0x004bdb50..0x004be130 range). The recursion at 0x004bae3c "
     "handles hierarchical descent. The 'current node' is at "
     "g_currentNodeIdx (DAT_00542044), with flags at g_currentNodeFlags "
     "(DAT_00542084). Note: a SECOND indirect call exists at 0x004bab0a "
     "(via %edx, after reading from a separate node-data structure) - "
     "this is a different dispatch, used in a deeper code path."),

    # ------ FILESYS.DAT asset loader ------
    (0x004b1e00, "FSYS_fopen",
     "Open an asset by name. Calls path-normalize then hash, then "
     "binary-searches the 1024-entry hash-sorted table loaded by "
     "FSYS_Init. Returns a 1-based slot index. On miss, sprintfs "
     "'FSYS_fopen(\"%s\")' and calls ShowErrorMessage. Function name "
     "is preserved verbatim from the embedded debug format string."),

    (0x004b1ec0, "FSYS_NormalizePath",
     "Path normalizer for asset lookup. Uppercases the input in place "
     "(into static buffer DAT_007af0e0). REQUIRES a fully-qualified "
     "Windows path 'X:\\\\...' - emits 'Partial filename' fatal error "
     "otherwise. Surprising consequence: assets are hashed by their "
     "FULL dev-machine path including the leaked prefix "
     "'C:\\\\SOURCE\\\\MK4\\\\WIN\\\\'. No prefix stripping."),

    (0x004b1f50, "FSYS_HashName",
     "Asset filename hash. Reverse-engineered (see tools/fsys_hash.py). "
     "Each char is shifted into one of 4 byte positions (0, 8, 16, 24) "
     "cycling every 4 chars, then summed. Final hash = sum + length. "
     "Verified: hash('C:\\\\SOURCE\\\\MK4\\\\WIN\\\\MENU.TGA') = 0xc4cf3b08, "
     "matches FILESYS.DAT entry 790."),

    (0x004b5bc0, "Mem_Malloc",
     "Game's wrapper around the memory allocator. Function name is "
     "preserved from the embedded debug string 'Mem_Malloc()'. "
     "Used after FSYS_fopen to allocate a buffer for FSYS_fload."),

    (0x004b2160, "FSYS_fload",
     "Load an entire asset file into memory in one call. Function name "
     "is preserved from the embedded debug string 'FSYS_fload()'. "
     "Pattern: open via FSYS_fopen, allocate via Mem_Malloc, then read "
     "into the buffer."),

    (0x004bd6e0, "LoadGeoAsset_Textures",
     "Loads the texture/material table from a .geo file. Builds a path "
     "'c:\\\\source\\\\mk4\\\\win\\\\geogfx\\\\<name>' from a global table, "
     "fetches via FSYS_fload, then iterates the texture entries at "
     "geo[geo[1].DWORD + 4] (offset @04 in the file). Each entry has "
     "(uint16 w, uint16 h, uint32 size, byte data[size]) and is stored "
     "in one of 15 texture slots via FUN_004bd5f0."),

    (0x004bd5f0, "Tex_DecodeRLE16",
     "Decodes a 16-bit RLE-compressed texture into a 256-pixel-stride "
     "destination buffer at &DAT_00f4d050. Args: (slot, width, height, "
     "src). Stream format per scanline: token = uint16; if (token & "
     "0x8000) == 0: literal pixel (2 bytes); else RLE run: pixel = "
     "(token & 0x7fff) ^ g_xorKey, run_length = next byte (3 bytes total). "
     "Pixel format is RGB-555 (verified visually - Scorpion / Sub-Zero / "
     "Liu Kang / tomb stage atlases all decode to recognizable images). "
     "Calls FUN_004bf370(slot, 0, 0, w, h) at the end (suspected GPU "
     "upload / DDraw blit)."),

    (0x004b2120, "FSYS_fsize",
     "(suspected) Returns file size by name. Called right before "
     "Mem_Malloc to size the buffer for FSYS_fload."),

    # ------ Renderer init dispatch ------
    (0x004b49a0, "Renderer1_Init_Glide",
     "Renderer mode 1 = 3dfx Glide. Confirmed by: (a) ~20 calls "
     "through a global function-pointer table at DAT_007b0008..0070 "
     "- the classic LoadLibraryA('glide2x.dll')+GetProcAddress pattern; "
     "(b) screen dimensions 0x280 x 0x1e0 = 640 x 480, the canonical "
     "Glide resolution; (c) glide2x.dll appears as a string in .data. "
     "Bound to F5 in WndProc. Availability flag: DAT_00f9f7d8."),

    (0x004ad6a0, "Renderer2_Init_D3D",
     "Renderer mode 2 = Direct3D card (HW). SUSPECTED - based on F6 "
     "key binding in WndProc and the F-key UI string 'F6 - DIRECT3D "
     "CARD'. AppInit fallback chain tries this after mode 1 (Glide). "
     "12 internal callees, no direct DDRAW imports (likely abstracted "
     "through a state structure). Availability flag: DAT_00f9f7dc."),

    (0x004af8c0, "Renderer3_Init_SW_FS",
     "Renderer mode 3 = software fullscreen. SUSPECTED - F7 binding, "
     "F-key string 'F7 - SOFTWARE'. Takes 2 params (HWND + something). "
     "Same shape as Renderer5 (SW hires) - likely the resolution "
     "differs in the second param. Availability flag: DAT_00f9f7e0."),

    (0x004b00f0, "Renderer5_Init_SW_FS_Hi",
     "Renderer mode 5 = software fullscreen hi-res. SUSPECTED - F9 "
     "binding, F-key string 'F9 - SOFTWARE HIRES'. Same signature as "
     "Renderer3 (mode 3) - second param likely controls resolution. "
     "Availability flag: DAT_00f9f7e4. Note: mode 4 (windowed software) "
     "has no init function - it's the unconditional fallback."),

    # ------ AppInit subsystems ------
    (0x004c4470, "Timer_Init",
     "Initializes the high-precision timer subsystem. Sets up "
     "QueryPerformanceCounter / Frequency state and calls timeBeginPeriod "
     "to raise OS scheduling resolution. Used by QueryMicroTimer."),

    (0x004b5230, "Joystick_Init",
     "Initializes joystick input via WINMM (joyGetDevCapsA, joyGetPos). "
     "Note: the game does NOT use DirectInput - keyboard via USER32 "
     "messages, joystick via the legacy joy* APIs."),

    (0x004b1cf0, "FSYS_Init",
     "Initializes the asset archive subsystem. Opens 'filesys.dat' "
     "(see g_filesys at game/FILESYS.DAT - 24 MB). Function name is "
     "preserved verbatim from embedded debug strings 'FSYS_Init(1..3)'."),

    (0x004b4370, "Gfx_Init",
     "Initializes the graphics subsystem (window-tied; takes HWND). "
     "Name preserved from embedded debug string 'Gfx_Init()'. The "
     "actual D3D/DDraw setup happens later in TryInitRenderer."),

    (0x004ac8f0, "AuxAudio_Init",
     "Initializes the auxiliary audio mixer (auxGetDevCapsA, "
     "auxGetNumDevs, auxGetVolume). On a 1998 system this controlled "
     "the CD-Audio line-in volume - used to play CD-DA tracks 02..15."),

    (0x004aca10, "AuxAudio_SetVolume",
     "Sets the auxiliary audio (CD-DA) volume via auxSetVolume."),

    (0x004c3ef0, "DSound_Init",
     "Initializes DirectSound (DirectSoundCreate + secondary buffers). "
     "Used for in-game SFX (not music - music is CD-DA via WINMM)."),

    (0x004b22e0, "UpdateWindowTitle",
     "Updates the main window title based on game state via "
     "SetWindowTextA. Strings: 'Mortal Kombat 4', "
     "'Mortal Kombat 4 - Demo Mode', 'Mortal Kombat 4 - Waiting'."),

    (0x004aca60, "GetExeDirectory",
     "Resolves the directory of the running executable via "
     "GetModuleFileNameA + path-split. Used by AppInit to locate "
     "asset files relative to MK4.EXE."),

    (0x004b40a0, "SetRendererMode",
     "Sets the desired renderer mode (1, 2, 3, 5 are tried in order in "
     "AppInit). Tiny function - likely just stores the parameter in a "
     "global. Mode meanings to be confirmed (D3D card / Glide / "
     "software / hires)."),

    (0x004b3ed0, "TryInitRenderer",
     "Attempts to initialize the currently selected renderer. Returns "
     "a negative value on failure. AppInit's fallback chain calls this "
     "with modes 1, 2, 3, 5 (skipping 4) until one succeeds."),

    (0x0048bcf0, "DownloadPlayerChar",
     "Loads a character's geometry+textures for one of the 4 player "
     "slots (DAT_00542070 = 0..3). Reads the character roster index "
     "from per-player globals (DAT_00537f48 / 005380e0 / 0053a178 / "
     "0053a250) and the skin/variant from DAT_00541ec4 / 00541ec8. "
     "Logs via 'DOWNLOAD Player N pN char %d ...' format strings. "
     "Pushes current asset slot on the stack at PTR_DAT_004d57ac then "
     "delegates to LoadGeoAsset_Textures."),

    (0x0048bff0, "DownloadPlayerChar_Variant",
     "Variant of DownloadPlayerChar - same DOWNLOAD log strings + same "
     "per-player lookup but slightly different asset chaining (uses "
     "DAT_00542074 != 0 as an offset). Likely an alternate model for a "
     "special mode (endurance / costume swap)."),

    (0x004bd5b0, "LoadGeoAsset_Default",
     "Trivial wrapper: LoadGeoAsset_Textures(0). Called for asset slot 0."),
]

DATA = [
    (0x00543b78, "g_installPath",
     "REG_SZ buffer (1024 bytes) for the install path read from the registry."),

    (0x00543928, "g_configBuffer",
     "588-byte Config blob: [0..3] hash, [4..583] XOR-obfuscated payload, "
     "[584..587] tail."),

    (0x00543f78, "g_installValidated",
     "Cached result of ValidateInstall. 0 = not yet checked, 1 = passed."),

    (0x0054392c, "g_configValidationCounter",
     "Incremented on each successful Config hash validation."),

    (0x00f9f7c0, "g_hMainWindow",
     "HWND of the main game window. Set by the window-creation routine "
     "called from WinMain (FUN_004c5070, not yet renamed). Used as the "
     "hWnd parent for MessageBoxA in ShowErrorMessage."),

    (0x00f9f7c4, "g_hInstance",
     "Application HINSTANCE. Stored from WinMain's first parameter."),

    (0x004f4b3c, "g_currentRendererMode",
     "Current renderer mode (1..5). Set by SetRendererMode and read by "
     "BeginFrame / DrawScene / PresentFrame to dispatch to the correct "
     "Glide / D3D / SW backend. 1=Glide, 2=D3D, 3=SW FS, 4=SW windowed, "
     "5=SW FS hi-res."),

    (0x007afa00, "g_drawSceneTimeMs",
     "Accumulator for DrawScene wall-clock time, in ms. DrawScene "
     "subtracts timeGetTime() at entry and adds it at exit, so the "
     "delta tracks scene-render cost across frames. Used for profiling "
     "or adaptive throttling."),

    (0x00f85b40, "g_drawQueueSize",
     "Number of draw entries currently queued. Read by FlushDrawQueue "
     "to know how many entries to sort+submit. Reset to 0 after flush."),

    (0x00f71322, "g_drawQueue",
     "Base of the per-frame draw queue. Each entry is 28 bytes "
     "(14 ushorts). The first ushort of each entry is the sort key "
     "(probably z-depth bucket or material id, range 0..1023). "
     "Layout of the rest of the entry: TBD - has shorts (vertex coords?) "
     "and is referenced by index 0xd for some flag bits."),

    (0x00f6d050, "g_drawQueueBuckets",
     "1024-dword buffer used as the histogram for FlushDrawQueue's "
     "counting sort. Zeroed at the start of each flush, then filled "
     "with per-bucket counts, then turned into cumulative offsets."),

    (0x00f85b50, "g_viewportX",
     "Current viewport X. Set by SetViewport from BeginFrame's "
     "mode-specific begin call output."),

    (0x00f85b54, "g_viewportY",
     "Current viewport Y. Set by SetViewport from BeginFrame."),

    (0x004ffd44, "g_viewportW",
     "Current viewport width. 320 in mode 4 (windowed SW), 640 in "
     "modes 1, 2, 5 (Glide / D3D / hi-res SW)."),

    (0x004ffd48, "g_viewportH",
     "Current viewport height. 240 in mode 4, 480 in modes 1, 2, 5."),

    (0x004f7888, "g_nodeDispatchTable",
     "16-entry function pointer table dispatching scene-graph nodes "
     "by their type/mode bits in g_currentNodeFlags. Indexed by "
     "((flags >> 24) & 7) | ((flags & 0x100) ? 8 : 0). All 16 entries "
     "point to handlers in .text in the 0x004bdb50..0x004be130 range "
     "(verified). 9 distinct handlers (with aliasing): bdb50, bde90, "
     "bdca0, bdfb0, be050, be130, bdc00, bdf40, bdd50."),

    (0x00542044, "g_currentNodeIdx",
     "Current scene-graph node index, used by RenderSceneNode and its "
     "callees to access the per-node descriptor at offset (idx*4) "
     "in the global node table."),

    (0x00542084, "g_currentNodeFlags",
     "Flag word of the current scene-graph node. Layout: "
     "  bits 24-26: node type (0-7)"
     "  bit 8     : node mode (0 or 1, e.g., opaque vs alpha?)"
     "  bit 13 (0x2000): triggers a pre-call to FUN_004ba5d0"
     "  bits 4-23 (mask 0xf00004) gate an alternate code path"
     "Combined with bit 8, type+mode is used to index "
     "g_nodeDispatchTable."),

    (0x007b01a0, "g_sinTable",
     "4096-entry sine lookup table (16 KB). Each entry is a 32-bit "
     "fixed-point sin value at angle (i * 2π / 4096) i.e. BAM-indexed "
     "(binary angle measure: 0x1000 = 2π). Used by all three "
     "BuildRotMatrix_Order{A,B,C} helpers, which exploit the "
     "lookup[a-0x400] trick to get -cos(a) from the same table."),

    (0x007af990, "g_modelViewMatrix",
     "Current modelview-projection matrix in fixed-point. Read by "
     "ProjectTwoVertices and ProjectVertex. ~12 entries starting here "
     "(DAT_007af990, _994, _998, _99a, _99c, _9a0). Applied as "
     "y' = (M[6]*x + M[7]*y + M[8]*z) >> 12 + viewport_z."),

    (0x007af9a4, "g_viewportOffset",
     "Per-axis viewport offsets (X, Y, Z) added after the matrix "
     "multiply in ProjectTwoVertices/ProjectVertex. 3 shorts at "
     "DAT_007af9a4/8/c."),

    (0x007af9b4, "g_triRingScreenXY",
     "Triangle-strip ring buffer for screen-space XY coordinates. "
     "3 dword slots at DAT_007af9b4/9b8/9bc, holding (x,y) shorts "
     "for the 3 vertices of the current triangle in the strip."),

    (0x007af984, "g_triRingZ",
     "Triangle-strip ring buffer for view-space Z (depth). 3 ints at "
     "DAT_007af984/988/98c. Used for back-clipping (all 3 must be > 0) "
     "and probably as input to the sort-key lookup."),

    (0x00b0d008, "g_zSortKeyLUT",
     "128 KB lookup table (65536 entries x 2 bytes uint16) - "
     "hyperbolic z → sort bucket mapping. Built by BuildSortKeyLUT "
     "at startup. Used by SubmitDrawEntry to remap a triangle's z "
     "into a coarse 0..2047 bucket index, then by FlushDrawQueue's "
     "counting sort. Mapping: bucket = 65536*z / (31*z + 65536)."),

    (0x00b2d010, "g_sortScratch",
     "4 MB scratch buffer used during FlushDrawQueue's counting sort. "
     "Zeroed at startup (and on every rebuild?) by BuildSortKeyLUT."),

    (0x00f70ff8, "g_div3LUT",
     "768-byte lookup table where LUT[i] = i / 3, built via the "
     "compiler's reciprocal-multiplication idiom (magic 0x55555556). "
     "Probably maps vertex indices to triangle indices in the draw "
     "queue (3 vertices per triangle)."),

    (0x004f44e0, "g_imaIndexTable",
     "Standard IMA ADPCM index delta table: 16 entries × int32 = "
     "[-1,-1,-1,-1, 2,4,6,8, -1,-1,-1,-1, 2,4,6,8]. Used by "
     "ESF_DecodeADPCM. Verified to match the MS-IMA spec."),

    (0x004f4520, "g_imaStepTable",
     "Standard IMA ADPCM step size table: 89 entries × int32, "
     "exponentially spaced from 7 to 32767 (Microsoft IMA variant). "
     "Used by ESF_DecodeADPCM. Verified to match the MS-IMA spec."),

    (0x007aa230, "g_ecmHeader",
     "3608-byte (0xe18) buffer holding the current ECM file's header. "
     "Layout: [0..3] magic 'ECM\\x02', [4..7] frame count, "
     "[8..0xe17] array of 900 int32 group offsets. Zeroed by "
     "ECM_Cleanup."),

    (0x007ab04c, "g_ecmFile",
     "FILE* of the currently-playing ECM cinematic, or 0 if none."),

    (0x007ab06c, "g_ecmThread",
     "HANDLE of the ECM playback worker thread spawned by ECM_Open."),

    (0x007ab078, "g_ecmThreadActive",
     "1 while the ECM playback thread is running; cleared to 0 by "
     "ECM_Cleanup to signal a graceful shutdown."),

    (0x00ab438c, "g_gameState",
     "Current game-FSM state, read by GameStateMachine. Values: "
     "0=idle/main-menu, 4=active-fight, 5..0xc=top-level menus "
     "(arcade/vs/tournament/options/practice/credits/etc.), "
     "0x18..0x1c=nested sub-screens (character select etc.)."),

    (0x007af930, "g_frameCounter",
     "Monotonic 60 Hz frame counter, incremented once per "
     "GameLogicStep call."),

    (0x007af918, "g_gameStateResult",
     "Last return value from GameStateMachine, used by GameLogicStep "
     "to decide whether to run idle logic."),

    (0x00543800, "g_gameMode",
     "Higher-level mode flag distinct from g_gameState. 0 = active "
     "fight (gameplay running), non-zero = paused / menu / non-fight. "
     "Read by GameTick to gate physics + entity update. Set by various "
     "menu transitions."),

    (0x00538158, "g_player1NodeIdx",
     "Scene-graph node index (packed pointer/4) of player-1's "
     "character, or 0 if no P1. The character descriptor at "
     "(g_player1NodeIdx * 4) has fields: +0x30 player_id (=1), +0x34 "
     "flags, +0x58 some position component, etc."),

    (0x0053815c, "g_player2NodeIdx",
     "Scene-graph node index of player 2 (player_id=2 at +0x30)."),

    (0x00538160, "g_player3NodeIdx",
     "Scene-graph node index of player 3 (player_id=3 at +0x30). "
     "Used for the 4-player tag-team / endurance modes."),

    (0x00538164, "g_player4NodeIdx",
     "Scene-graph node index of player 4 (player_id=4 at +0x30)."),
]


def main():
    print("\n" + "=" * 60)
    print("  Applying MK4 names")
    print("=" * 60)

    fm = currentProgram.getFunctionManager()
    sym = currentProgram.getSymbolTable()
    listing = currentProgram.getListing()

    for va, name, comment in FUNCTIONS:
        addr = toAddr(va)
        func = fm.getFunctionAt(addr) or fm.getFunctionContaining(addr)
        if not func:
            # No function yet - common for pointer-only callbacks (e.g. WndProc).
            # Try to create one by disassembling/analyzing from this address.
            cmd = CreateFunctionCmd(addr)
            if cmd.applyTo(currentProgram):
                func = fm.getFunctionAt(addr)
        if not func:
            print("  [skip] no function at %s (CreateFunctionCmd failed)" % addr)
            continue
        old = func.getName()
        func.setName(name, SourceType.USER_DEFINED)
        if comment:
            func.setComment(comment)
        print("  fn   %s   %-28s -> %s" % (addr, old, name))

    for va, name, comment in DATA:
        addr = toAddr(va)
        s = sym.getPrimarySymbol(addr)
        if s is not None:
            old = s.getName()
            s.setName(name, SourceType.USER_DEFINED)
        else:
            old = "<none>"
            sym.createLabel(addr, name, SourceType.USER_DEFINED)
        if comment:
            listing.setComment(addr, CodeUnit.PLATE_COMMENT, comment)
        print("  var  %s   %-28s -> %s" % (addr, old, name))

    print("\n  Done. Ghidra DB updated; saves on script exit.\n")


main()
