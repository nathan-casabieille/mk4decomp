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

void MK4_PalBlit555(const unsigned short *pixels, int w, int h)
{
    if (!pixels || w <= 0 || h <= 0)
        return;
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
