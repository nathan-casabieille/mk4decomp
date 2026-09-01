/**
 * Native input readers (TARGET=sdl).
 *
 * The engine reads the keyboard through Input_GetAsyncKey, an 18-byte wrapper
 * around Win32's GetAsyncKeyState:
 *
 *     mov eax, [esp+4] ; push eax ; call [GetAsyncKeyState] ; shr eax, 15 ; and eax, 1
 *
 * i.e. "is this virtual key held right now", polled rather than event-driven.
 * SDL's keyboard state array is the same shape, so this is a port, not a
 * decompilation: there is nothing in the original worth transcribing except
 * the VK numbering, and the SDL scancode table below is that mapping.
 *
 * Input_PollJoystick returns a bit set the menu poll reads as
 *   0x10000000 left  0x20000000 right  0x40000000 up  0x80000000 down
 * with the low 28 bits as buttons. SDL game controllers map onto it directly.
 *
 * Both are strong definitions so they win over the weak stubs in
 * engine_autostubs.c at link time.
 */
#include <SDL2/SDL.h>
#include <stdlib.h>
#include "portable/mem_model.h"

#define JOY_FAKE_MAX 16

/* Win32 virtual-key -> SDL scancode. Only the keys the engine actually polls;
 * anything else reads as up, which is the correct answer for a key the port
 * does not bind. */
static SDL_Scancode vk_to_scancode(int vk)
{
    switch (vk) {
    case 0x08: return SDL_SCANCODE_BACKSPACE;
    case 0x09: return SDL_SCANCODE_TAB;
    case 0x0d: return SDL_SCANCODE_RETURN;
    case 0x10: return SDL_SCANCODE_LSHIFT;
    case 0x11: return SDL_SCANCODE_LCTRL;
    case 0x12: return SDL_SCANCODE_LALT;
    case 0x13: return SDL_SCANCODE_PAUSE;
    case 0x1b: return SDL_SCANCODE_ESCAPE;
    case 0x20: return SDL_SCANCODE_SPACE;
    case 0x25: return SDL_SCANCODE_LEFT;
    case 0x26: return SDL_SCANCODE_UP;
    case 0x27: return SDL_SCANCODE_RIGHT;
    case 0x28: return SDL_SCANCODE_DOWN;
    case 0x2d: return SDL_SCANCODE_INSERT;
    case 0x2e: return SDL_SCANCODE_DELETE;
    default:
        if (vk >= 0x30 && vk <= 0x39)                 /* 0-9 */
            return (SDL_Scancode)(SDL_SCANCODE_1 + (vk == 0x30 ? 9 : vk - 0x31));
        if (vk >= 0x41 && vk <= 0x5a)                 /* A-Z */
            return (SDL_Scancode)(SDL_SCANCODE_A + (vk - 0x41));
        if (vk >= 0x70 && vk <= 0x7b)                 /* F1-F12 */
            return (SDL_Scancode)(SDL_SCANCODE_F1 + (vk - 0x70));
        return SDL_SCANCODE_UNKNOWN;
    }
}

int g_mk4FakePressVk;
int g_mk4FakePressLeft;

/* Arm a scripted key press for `frames` frames (the frame loop counts it
 * down). Used by the boot-match staging to answer edge-detecting gates. */
void MK4_NativeFakeKeyPress(int vk, int frames)
{
    g_mk4FakePressVk = vk;
    g_mk4FakePressLeft = frames;
}

/* frames since boot, for the scripted-input knobs below */
static unsigned s_inputFrame;

void MK4_NativeFakeKeyTick(void)
{
    if (g_mk4FakePressLeft > 0) g_mk4FakePressLeft--;
    s_inputFrame++;
}

/* MapVirtualKeyA(vk, MAPVK_VK_TO_CHAR), the one USER32 call in AppInit_Misc1.
 * Windows returns the UPPERCASE character a virtual key types on the current
 * layout, or 0 for keys with no character. The engine calls it once per key at
 * boot to fill in the labels the KEYBOARD screen shows, so a US layout - which
 * is the VK numbering the rest of this file already assumes - is the answer. */
int MK4_MapVirtualKeyChar(int vk)
{
    if (vk >= 0x30 && vk <= 0x39)          /* '0'..'9'      */
        return vk;
    if (vk >= 0x41 && vk <= 0x5a)          /* 'A'..'Z'      */
        return vk;
    if (vk >= 0x60 && vk <= 0x69)          /* numpad 0..9   */
        return vk - 0x60 + '0';
    switch (vk) {
    case 0x20: return ' ';
    case 0x6a: return '*';
    case 0x6b: return '+';
    case 0x6d: return '-';
    case 0x6e: return '.';
    case 0x6f: return '/';
    case 0xba: return ';';
    case 0xbb: return '=';
    case 0xbc: return ',';
    case 0xbd: return '-';
    case 0xbe: return '.';
    case 0xbf: return '/';
    case 0xc0: return '`';
    case 0xdb: return '[';
    case 0xdc: return '\\';
    case 0xdd: return ']';
    case 0xde: return '\'';
    default:   return 0;
    }
}

int Input_GetAsyncKey(int vk)
{
    const Uint8 *keys;
    /* MK4_FAKE_KEY=<vk decimal> reports that one key as held. Headless runs
     * have no keyboard, so this is how the menu's navigation gets exercised -
     * it drives the real Menu_PollNavInput, the real state machine and the
     * real DrawMenu, only the key state is substituted. */
    {
        static const char *fake;
        static int checked;

        if (!checked) { checked = 1; fake = SDL_getenv("MK4_FAKE_KEY"); }
        if (fake && vk == SDL_atoi(fake))
            return 1;
        /* A scripted PRESS, as opposed to the held key above. Several of
         * the engine's gates are edge detectors (TestQueueGateState latches
         * on the first frame its key is down and refuses to fire again
         * while it stays down), so a headless run needs to be able to let
         * go. MK4_NativeFakeKeyPress arms one for a couple of frames. */
        if (g_mk4FakePressVk && vk == g_mk4FakePressVk && g_mk4FakePressLeft)
            return 1;
    }
    SDL_Scancode sc = vk_to_scancode(vk);
    int n = 0;

    if (sc == SDL_SCANCODE_UNKNOWN)
        return 0;
    keys = SDL_GetKeyboardState(&n);
    if (keys == 0 || (int)sc >= n)
        return 0;
    return keys[sc] ? 1 : 0;
}

/* Deadzone on the analog stick, so a resting controller does not read as a
 * held direction the way a digital pad would not. */
#define STICK_ON  12000

/* The two pads the backend owns, opened once on first use. */
static SDL_GameController *s_pads[2];

static void joy_open_once(void)
{
    static int tried;
    int i;

    if (tried)
        return;
    tried = 1;
    if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) == 0) {
        int slot = 0;

        for (i = 0; i < SDL_NumJoysticks() && slot < 2; i++)
            if (SDL_IsGameController(i))
                s_pads[slot++] = SDL_GameControllerOpen(i);
    }
}

/* What Joystick_Init publishes, which this backend replaces rather than
 * converts: the per-device BUTTON COUNT table at 0x7b0188 - sixteen bytes,
 * zero meaning no such device - and the per-player device assignment at
 * 0x543b68, where -1 means "no pad". The JOYSTICK options screen reads both:
 * it prints "JOY n, m BUTS" from them, refuses to bind a button while the
 * player has no device, and its CONTROLLER row cycles through the devices
 * that are present and not already claimed by the other player.
 *
 * The count is the ten face and shoulder buttons Input_PollJoystick reports
 * in the low 28 bits; the four directions live in the high nibble and are not
 * bindable, so they are not counted. */
void MK4_NativeJoystickPublish(void)
{
    unsigned char *counts = (unsigned char *)MK4_VA(unsigned char, 0x007b0188u);
    unsigned int *sel = (unsigned int *)MK4_VA(unsigned int, 0x00543b68u);
    int i;

    joy_open_once();
    for (i = 0; i < 16; i++)
        counts[i] = 0;
    for (i = 0; i < 2; i++)
        if (s_pads[i] != 0 && SDL_GameControllerGetAttached(s_pads[i]))
            counts[i] = 10;
    /* MK4_FAKE_PAD=n reports n devices with ten buttons each and no hardware
     * behind them, so the JOYSTICK screen's device cycling and its bind and
     * clear paths can be exercised on a machine with no pad plugged in.
     * MK4_FAKE_PAD_BTN=b then makes Input_PollJoystick report button b down. */
    { const char *fake = getenv("MK4_FAKE_PAD");
      if (fake) {
          int n = atoi(fake);
          if (n > JOY_FAKE_MAX) n = JOY_FAKE_MAX;
          for (i = 0; i < n; i++)
              counts[i] = 10;
      } }
    /* player n takes device n when there is one */
    for (i = 0; i < 2; i++)
        sel[i] = counts[i] ? (unsigned int)i : 0xffffffffu;
}

unsigned int Input_PollJoystick(int which)
{
    SDL_GameController *c;
    unsigned int bits = 0;
    int i;

    joy_open_once();
    { const char *fake = getenv("MK4_FAKE_PAD");
      if (fake) {
          const char *b = getenv("MK4_FAKE_PAD_BTN");
          const char *at;
          if (which < 0 || which >= atoi(fake) || b == 0)
              return 0;
          /* "n:frame" holds the button down only from that frame on, so a
             scripted run can walk the menu before the press lands */
          at = b;
          while (*at && *at != ':') at++;
          if (*at == ':' && s_inputFrame < (unsigned)atoi(at + 1))
              return 0;
          return 1u << (atoi(b) - 1);            /* the screen numbers from 1 */
      } }
    if (which < 0 || which > 1)
        return 0;
    c = s_pads[which];
    if (c == 0 || !SDL_GameControllerGetAttached(c))
        return 0;

    if (SDL_GameControllerGetButton(c, SDL_CONTROLLER_BUTTON_DPAD_LEFT) ||
        SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTX) < -STICK_ON)
        bits |= 0x10000000u;
    if (SDL_GameControllerGetButton(c, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ||
        SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTX) > STICK_ON)
        bits |= 0x20000000u;
    if (SDL_GameControllerGetButton(c, SDL_CONTROLLER_BUTTON_DPAD_UP) ||
        SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTY) < -STICK_ON)
        bits |= 0x40000000u;
    if (SDL_GameControllerGetButton(c, SDL_CONTROLLER_BUTTON_DPAD_DOWN) ||
        SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTY) > STICK_ON)
        bits |= 0x80000000u;

    /* face and shoulder buttons occupy the low 28 bits */
    for (i = 0; i < 10; i++)
        if (SDL_GameControllerGetButton(c, (SDL_GameControllerButton)i))
            bits |= 1u << i;

    return bits;
}

/* ---------------------------------------------------------------------------
 * The two "is anyone pressing anything" bytes at 0x4d50b8 / 0x4d50b4.
 *
 * Nothing in MK4's own code writes them - a linear disassembly of every
 * function finds reads only (InputPollFlagBits, InputPollFlagBitsHalf,
 * TripleByteCheck, the audio dispatchers). In the original they are filled
 * by the input layer behind DirectInput, so under the port they are the
 * backend's job, exactly like the CD-audio probe and the DirectDraw
 * surface.
 *
 * Only the two pollers' bit positions matter here, and they are a matched
 * pair one nibble apart: InputPollFlagBits reads bits 0..2 of the pad byte
 * and 4..6 of the state byte (player 1), InputPollFlagBitsHalf the same
 * bits shifted up a nibble (player 2). We publish one bit per player - "a
 * bound key is down" - taken from the SAME key map the engine's own
 * keyboard poller reads (0x543ab8, filled by ResetConfigToDefaults), so a
 * rebind moves both together.
 */
void MK4_NativeInputPublish(void)
{
    unsigned int player, b;
    unsigned char pad = 0;

    /* ACTION slots only - 4..12 (the kicks, punches, block, step in/out,
     * run and start). Slots 0..3 are UP/DOWN/LEFT/RIGHT and must NOT set
     * this byte: the game reads it as "a button is down", and
     * InputPollFlagBitsHalf turns bit 4 straight into a CONFIRM. Including
     * the directions made every arrow press in the main menu read as a
     * select, which launched a mode handler and crashed. */
    for (player = 0; player < 2; player++) {
        for (b = 4; b < 13; b++) {
            int vk = *MK4_VA(int, 0x543ab8u + b * 8u + player * 4u);

            if (vk == 0 || !Input_GetAsyncKey(vk))
                continue;
            pad |= player ? 0x10u : 0x01u;
            break;
        }
    }
    /* InputPollFlagBits reads bits 0/1 for player 1, InputPollFlagBitsHalf
     * bits 4/5 for player 2. */
    *MK4_VA(unsigned char, 0x4d50b8u) = pad;
    /* The DIRECTION word at 0x4d50b4, the original DirectInput layer's
     * publish: bit 0 up, 1 down, 2 left, 3 right for player 1, the same
     * in bits 8..11 for player 2 - the main menu's navigation reads bits
     * 0x101 / 0x202. EDGE-triggered here: the menu moves once per press,
     * matching how the original's per-frame device read behaves with its
     * own repeat handling upstream. */
    {
        static unsigned int held;
        unsigned int now = 0, b;
        static const int dir_slot[4] = { 0, 1, 2, 3 };  /* up down left right */

#ifdef TARGET_SDL
        /* MK4_ARROWS_P1=1: rebind PLAYER ONE's four directions to the arrow
         * keys. The game's own default map gives P1 W A S Z and the ARROWS
         * to player two - so on a one-player run the arrows are dead keys,
         * which is a fair thing to trip over. This writes the four arrow
         * VKs into P1's own direction slots at 0x543ab8, exactly the four
         * dwords the game's OPTIONS > KEYBOARD screen edits, and everything
         * downstream (Input_PollPlayerKeyboard, the 0x4d50a4 aggregate, the
         * select's eight-slot repeater) runs unchanged.
         *
         * It REPLACES W A S Z rather than adding to them - the map holds one
         * VK per slot per player, so there is nowhere to put a second. Off
         * by default: no measured screen changes. */
        { extern char *getenv(const char *);
          static int armed;
          if (!armed && getenv("MK4_ARROWS_P1")
              && *MK4_VA(int, 0x543ab8u) != 0) {   /* wait for the defaults */
              static const int arrows[4] = { 38, 40, 37, 39 };  /* up down left right */
              int sl;
              armed = 1;
              for (sl = 0; sl < 4; sl++)
                  *MK4_VA(int, 0x543ab8u + (unsigned)sl * 8u) = arrows[sl];
              SDL_Log("input: MK4_ARROWS_P1 - player one's directions rebound "
                      "to the arrow keys (W A S Z no longer steer)");
          } }

        /* MK4_TRACE_BINDS: the game's own key map, once. The directions and
         * the action slots for both players, as ResetConfigToDefaults left
         * them - the answer to "which key moves the cursor". */
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          static int once;
          if (!once && getenv("MK4_TRACE_BINDS")) { int sl, pl; once = 1;
              for (pl = 0; pl < 2; pl++)
                  for (sl = 0; sl < 13; sl++)
                      SDL_Log("BIND p%d slot %2d vk %d", pl + 1, sl,
                              *MK4_VA(int, 0x543ab8u + sl * 8u + pl * 4u)); } }
#endif

        for (player = 0; player < 2; player++)
            for (b = 0; b < 4; b++) {
                int vk = *MK4_VA(int, 0x543ab8u + dir_slot[b] * 8u + player * 4u);

                if (vk != 0 && Input_GetAsyncKey(vk))
                    now |= 1u << (b + player * 8);
            }
        *MK4_VA(unsigned int, 0x4d50b4u) =
            (*MK4_VA(unsigned int, 0x4d50b4u) & ~0x0f0fu) | (now & ~held);
        held = now;
    }
}
