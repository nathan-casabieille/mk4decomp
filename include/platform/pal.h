/**
 * Platform Abstraction Layer (PAL) - the boundary between the portable MK4
 * engine and the host (window / video / audio / input / time / files).
 *
 * Exactly one backend implements this interface, selected by TARGET at build
 * time (src/platform/<target>/): `sdl` = SDL2 + OpenGL desktop, `web` =
 * Emscripten (later), `win32` = the original Win32/Glide/DSound layer (the
 * matching build never sees this header). The engine calls ONLY through these
 * functions, so porting is implementing this contract once per backend - see
 * src/platform/README.md for how it maps onto the original 91 Win32 IAT slots
 * + the Glide / DirectSound surface.
 *
 * This is interface only: no engine type leaks in, no backend type leaks out.
 */
#ifndef MK4_PLATFORM_PAL_H
#define MK4_PLATFORM_PAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* --- Lifecycle ---------------------------------------------------------- */
typedef struct mk4_pal_config {
    int          width;        /* backbuffer / window width  (e.g. 640) */
    int          height;       /* backbuffer / window height (e.g. 480) */
    int          fullscreen;   /* 0 = windowed */
    const char  *title;
} mk4_pal_config;

/* Bring up window + GL context + audio device + input. 0 on success. */
int  MK4_PalInit(const mk4_pal_config *cfg);
void MK4_PalShutdown(void);

/* --- Video -------------------------------------------------------------- */
/* The rasterizer (Glide/DirectDraw/Direct3D in the original) lands behind
 * these: begin a frame, upload the engine's framebuffer/draw lists, present.
 * The skeleton clears + swaps; the GL/Glide translation is filled in as the
 * renderer call sites convert. */
void MK4_PalFrameBegin(void);
void MK4_PalFramePresent(void);
/* Blit a 16bpp (RGB-555, the engine's native) software framebuffer. */
void MK4_PalBlit555(const unsigned short *pixels, int w, int h);

/* --- Input -------------------------------------------------------------- */
/* Pump the host event queue. Returns 0 when the user requested quit. */
int  MK4_PalPumpEvents(void);
/* Key state by MK4 virtual-key (the engine's GetAsyncKeyState replacement);
 * 1 if currently down. */
int  MK4_PalKeyDown(int mk4_vk);
void MK4_PalMouse(int *x, int *y, unsigned *buttons);

/* --- Time --------------------------------------------------------------- */
unsigned MK4_PalTicksMs(void);          /* timeGetTime / QueryPerformanceCounter */
void     MK4_PalDelayMs(unsigned ms);

/* --- Audio -------------------------------------------------------------- */
/* DirectSound replacement: open a stream, push PCM, close. The mixer stays
 * in the engine; the PAL only owns the device. */
int  MK4_PalAudioOpen(int freq, int channels, int bits);
void MK4_PalAudioSubmit(const void *pcm, int nbytes);
void MK4_PalAudioClose(void);

/* --- Process ------------------------------------------------------------ */
void MK4_PalExit(int code);             /* ExitProcess */

/* --- Engine entry points the main loop drives -------------------------- */
/* Provided by the engine (portable C) as its call sites convert. The SDL main
 * loop calls Init once then Frame each vsync. Until the engine provides them,
 * the backend links weak no-op stubs so the window/loop runs standalone. */
int  MK4_GameInit(int argc, char **argv);
void MK4_GameFrame(void);
void MK4_GameShutdown(void);

#ifdef __cplusplus
}
#endif

#endif /* MK4_PLATFORM_PAL_H */
