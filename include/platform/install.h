/**
 * Install validation - registry check + Config blob.
 *
 * Reads HKLM\Software\GT Interactive\Mortal Kombat 4\1.00 to confirm
 * the game was installed via SETUP and to load persistent settings
 * (the "Config" 588-byte blob, XOR-obfuscated).
 *
 * Lives in `platform/` because it's heavily Win32 registry-coupled.
 * The portable build either replaces this with a no-op (run unconditionally)
 * or with a SDL_RWops-based config file loader.
 *
 * See analysis/notes/architecture.md ("Install validation chain").
 */
#ifndef MK4_PLATFORM_INSTALL_H
#define MK4_PLATFORM_INSTALL_H

#include "../types.h"
#include "win32.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MK4_REGISTRY_KEY  "Software\\GT Interactive\\Mortal Kombat 4\\1.00"
#define MK4_CONFIG_SIZE   0x24c     /* 588 bytes */
#define MK4_CONFIG_SEED   0x43464729 /* 'FCG)' - Eurocom dev tag, hash seed */

/* g_configBuffer:
 *   [0..3]    stored hash (or 0xFFFFFFFF to skip validation)
 *   [4..583]  XOR-obfuscated payload (XOR key: byte[i] = (i * 123) & 0xff)
 *   [584..587] tail / unused */
extern u8   g_configBuffer[MK4_CONFIG_SIZE];   /* 0x00543928 */
extern char g_installPath[1024];               /* 0x00543b78 */
extern s32  g_installValidated;                /* 0x00543f78 */
extern s32  g_configValidationCounter;         /* 0x0054392c */

int  CheckInstallPath(void);                   /* 0x004acc50 */
s32  ValidateInstall(void);                    /* 0x004ad270 */
s32  ComputeConfigHash(void);                  /* 0x004ad210 */
void DeobfuscateConfig(void);                  /* 0x004ad250 */
void ResetConfigToDefaults(void);              /* 0x004acf90 */
void ShowErrorMessage(const char *msg);        /* 0x004c48c0 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_PLATFORM_INSTALL_H */
