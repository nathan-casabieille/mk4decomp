/**
 * SDL2 backend for the MK4 platform abstraction layer (TARGET=sdl).
 *
 * Implements include/platform/pal.h on a desktop SDL2 window: an SDL_Renderer
 * with a streaming RGB-555 texture for the engine's native framebuffer, the
 * SDL audio device for the DirectSound replacement, and SDL keyboard/mouse +
 * timer for input/time. The engine's rasterizer (Glide/DDraw/D3D) maps onto
 * MK4_PalBlit555 for now; a GL path replaces it as the draw call sites convert.
 *
 * Compiled only for TARGET=sdl; the matching build never sees this file.
 */
#include "platform/pal.h"

#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

static SDL_Window   *s_win;
static SDL_Renderer *s_ren;
static SDL_Texture  *s_fb;          /* RGB-555 streaming framebuffer */
static int           s_fb_w, s_fb_h;
static SDL_AudioDeviceID s_audio;
static int           s_quit;

int MK4_PalInit(const mk4_pal_config *cfg)
{
    int w = cfg && cfg->width  ? cfg->width  : 640;
    int h = cfg && cfg->height ? cfg->height : 480;
    Uint32 flags = SDL_WINDOW_SHOWN | (cfg && cfg->fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
        return -1;
    s_win = SDL_CreateWindow(cfg && cfg->title ? cfg->title : "Mortal Kombat 4",
                             SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                             w, h, flags);
    if (!s_win)
        return -1;
    s_ren = SDL_CreateRenderer(s_win, -1,
                               SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!s_ren)
        s_ren = SDL_CreateRenderer(s_win, -1, 0);   /* software fallback */
    if (!s_ren)
        return -1;
    SDL_RenderSetLogicalSize(s_ren, w, h);
    s_quit = 0;
    return 0;
}

void MK4_PalShutdown(void)
{
    if (s_audio) { SDL_CloseAudioDevice(s_audio); s_audio = 0; }
    if (s_fb)    { SDL_DestroyTexture(s_fb);  s_fb  = NULL; }
    if (s_ren)   { SDL_DestroyRenderer(s_ren); s_ren = NULL; }
    if (s_win)   { SDL_DestroyWindow(s_win);   s_win = NULL; }
    SDL_Quit();
}

/* --- Video -------------------------------------------------------------- */
void MK4_PalFrameBegin(void)
{
    SDL_SetRenderDrawColor(s_ren, 0, 0, 0, 255);
    SDL_RenderClear(s_ren);
}

void MK4_PalFramePresent(void)
{
    SDL_RenderPresent(s_ren);
}

/* GAMMA. The game HAS this setting - the GRAPHICS options screen steps
 * 0x543a94 between 2 and 0x62 and calls Helper_RendererPostInit with it -
 * and the original applies it through a Win32 gamma ramp, which is why the
 * port left that a stub: SDL has no equivalent per-window ramp. Applying it
 * in the final blit is this backend's version of the same knob.
 *
 * The scale is the game's own: 0x32 is neutral, 2 is darkest, 0x62 the
 * brightest. MK4_GAMMA overrides it for a run.
 *
 * This BRIGHTENS a finished frame; it does not put light in a scene. The
 * main menu is dim because its scene has no camera (see
 * src/game/main_menu_screen.c), and gamma is how a player would compensate,
 * not a fix for that. */
static int s_gamma = 0x32;               /* the game's neutral value */
static unsigned short s_gammaLut[0x8000];
static int s_gammaLutFor = -1;

void MK4_PalSetGamma(int g)
{
    if (g < 2) g = 2;
    if (g > 0x62) g = 0x62;             /* the game's own range */
    s_gamma = g;
}

/* The env override is a DIAGNOSTIC and is deliberately not clamped to the
 * game's range: the main menu currently renders at 1/16 brightness because
 * its scene has no camera, and no in-range gamma rescues a 1/31 signal.
 * MK4_GAMMA above 0x62 is a way to LOOK at such a frame, not a setting the
 * game would ever produce. */
void MK4_PalSetGammaRaw(int g)
{
    if (g < 2) g = 2;
    if (g > 2000) g = 2000;
    s_gamma = g;
}

static void gamma_build(void)
{
    double e;
    int v, ramp[32];
    unsigned int t;

    if (s_gammaLutFor == s_gamma)
        return;
    s_gammaLutFor = s_gamma;
    /* 0x32 -> exponent 1.0 (identity); higher values lift the midtones */
    e = 50.0 / (double)s_gamma;
    for (v = 0; v < 32; v++) {
        double n = pow((double)v / 31.0, e) * 31.0 + 0.5;
        ramp[v] = (int)n;
        if (ramp[v] > 31) ramp[v] = 31;
        if (ramp[v] < 0) ramp[v] = 0;
    }
    for (t = 0; t < 0x8000u; t++)
        s_gammaLut[t] = (unsigned short)(
              (ramp[(t >> 10) & 0x1f] << 10)
            | (ramp[(t >> 5) & 0x1f] << 5)
            |  ramp[t & 0x1f]);
}

/* the presented look of one pixel, for the diagnostic PPM dump */
unsigned short MK4_PalGammaMap(unsigned short px)
{
    if (s_gamma == 0x32)
        return px;
    gamma_build();
    return s_gammaLut[px & 0x7fff];
}

void MK4_PalBlit555(const unsigned short *pixels, int w, int h)
{
    static unsigned short *conv;
    static int conv_n;

    if (!pixels || w <= 0 || h <= 0)
        return;
    if (s_gamma != 0x32) {
        int n = w * h, i;

        gamma_build();
        if (conv_n < n) {
            free(conv);
            conv = (unsigned short *)malloc((size_t)n * 2);
            conv_n = conv ? n : 0;
        }
        if (conv) {
            for (i = 0; i < n; i++)
                conv[i] = s_gammaLut[pixels[i] & 0x7fff];
            pixels = conv;
        }
    }
    if (!s_fb || w != s_fb_w || h != s_fb_h) {
        if (s_fb)
            SDL_DestroyTexture(s_fb);
        s_fb = SDL_CreateTexture(s_ren, SDL_PIXELFORMAT_RGB555,
                                 SDL_TEXTUREACCESS_STREAMING, w, h);
        s_fb_w = w;
        s_fb_h = h;
    }
    if (s_fb) {
        SDL_UpdateTexture(s_fb, NULL, pixels, w * 2);
        SDL_RenderCopy(s_ren, s_fb, NULL, NULL);
    }
}

/* --- Input -------------------------------------------------------------- */
int MK4_PalPumpEvents(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT)
            s_quit = 1;
        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            s_quit = 1;
    }
    return s_quit ? 0 : 1;
}

int MK4_PalKeyDown(int mk4_vk)
{
    /* The engine's MK4 virtual-key codes map to SDL scancodes here; the
     * mapping table fills in as the input call sites convert. For now treat
     * mk4_vk as an SDL scancode directly. */
    const Uint8 *st = SDL_GetKeyboardState(NULL);
    if (mk4_vk < 0 || mk4_vk >= SDL_NUM_SCANCODES)
        return 0;
    return st[mk4_vk] ? 1 : 0;
}

void MK4_PalMouse(int *x, int *y, unsigned *buttons)
{
    int mx, my;
    Uint32 b = SDL_GetMouseState(&mx, &my);
    if (x) *x = mx;
    if (y) *y = my;
    if (buttons) *buttons = (unsigned)b;
}

/* --- Time --------------------------------------------------------------- */
unsigned MK4_PalTicksMs(void)        { return (unsigned)SDL_GetTicks(); }
void     MK4_PalDelayMs(unsigned ms) { SDL_Delay(ms); }

/* --- Audio -------------------------------------------------------------- */
int MK4_PalAudioOpen(int freq, int channels, int bits)
{
    SDL_AudioSpec want, have;
    SDL_memset(&want, 0, sizeof(want));
    want.freq = freq ? freq : 22050;
    want.format = (bits == 8) ? AUDIO_U8 : AUDIO_S16SYS;
    want.channels = channels ? (Uint8)channels : 2;
    want.samples = 1024;
    s_audio = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    if (s_audio == 0)
        return -1;
    SDL_PauseAudioDevice(s_audio, 0);
    return 0;
}

void MK4_PalAudioSubmit(const void *pcm, int nbytes)
{
    if (s_audio && pcm && nbytes > 0)
        SDL_QueueAudio(s_audio, pcm, (Uint32)nbytes);
}

void MK4_PalAudioClose(void)
{
    if (s_audio) { SDL_CloseAudioDevice(s_audio); s_audio = 0; }
}

/* --- Process ------------------------------------------------------------ */
void MK4_PalExit(int code)
{
    MK4_PalShutdown();
    exit(code);
}
