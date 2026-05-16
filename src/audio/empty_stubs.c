/**
 * Empty placeholder functions left in the shipping binary.
 *
 * Each compiles to a single `ret` (0xc3) - one byte. Likely
 * compiled-out debug callbacks (printf-like trace hooks) and
 * post-action hooks that became no-ops in the final build.
 * Each is named based on where it gets called from and whether
 * an existing header has already given it a meaningful name.
 *
 * Putting them in one file is a packaging convenience - they
 * span several subsystems but every match is trivially the
 * same single-byte `c3`.
 */
#include "audio/sound.h"
#include "engine/geo.h"
#include "engine/ecm.h"
#include "engine/render.h"
#include "game/statemachine.h"

/* @addr 0x0048bfe0 - "DOWNLOAD Player N" debug print (varargs).
 * The orig is a single `c3` ret with no return-value materialisation,
 * so we declare it `void` here even though callers ignore an
 * implicit `eax` if there were one. */
void Helper_DownloadDebugPrint(const char *fmt, ...) {}

/* @addr 0x004a2960 - audio subsystem placeholder. */
void Helper_AudioStub_2960(void) {}

/* @addr 0x004a4140 - audio subsystem placeholder. */
void Helper_AudioStub_4140(void) {}

/* @addr 0x004a4160 - audio subsystem placeholder. */
void Helper_AudioStub_4160(void) {}

/* @addr 0x004aedb0 - renderer-2 init slot 10 (post-init no-op). */
void R2_Init10(void) {}

/* @addr 0x004afb00 - install / config-area placeholder. */
void DDraw3_GetSurface(void) {}

/* @addr 0x004b0330 - ECM placeholder. */
void DDraw5_GetSurface(void) {}

/* @addr 0x004b21c0 - app-init placeholder. */
void Helper_AppStub_21C0(void) {}

/* @addr 0x004b2890 - app-init placeholder. */
void Helper_AppStub_2890(void) {}

/* @addr 0x004b2ae0 - app-init placeholder. */
void Helper_AppStub_2AE0(void) {}

/* @addr 0x004b5370 - geo / asset-loader placeholder. */
void Helper_GeoStub_5370(void) {}

/* @addr 0x004b5a70 - geo / asset-loader placeholder. */
void Helper_GeoStub_5A70(void) {}

/* @addr 0x004b5ad0 - post-allocation hook (rebuilds free-list shadow caches). */
void Helper_MemMalloc_Post(void) {}

/* @addr 0x004b62b0 - menu-state placeholder. */
void Helper_MenuStub_62B0(void) {}

/* @addr 0x004b8eb0 - menu-state placeholder. */
void Helper_MenuStub_8EB0(void) {}

/* @addr 0x004bd6d0 - geo-asset post-load hook (called by LoadGeoAsset_Textures). */
void Helper_GeoLoadPost(void) {}
