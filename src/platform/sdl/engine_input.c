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

unsigned int Input_PollJoystick(int which)
{
    static SDL_GameController *pads[2];
    static int tried;
    SDL_GameController *c;
    unsigned int bits = 0;
    int i;

    if (!tried) {
        tried = 1;
        if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) == 0) {
            int slot = 0;
            for (i = 0; i < SDL_NumJoysticks() && slot < 2; i++)
                if (SDL_IsGameController(i))
                    pads[slot++] = SDL_GameControllerOpen(i);
        }
    }
    if (which < 0 || which > 1)
        return 0;
    c = pads[which];
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
