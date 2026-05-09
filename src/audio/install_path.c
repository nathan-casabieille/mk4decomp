/**
 * Resolve the MK4 install directory from the registry and chdir.
 *
 * Reads HKLM\Software\GT Interactive\Mortal Kombat 4\1.00\Path
 * into g_installPath and SetCurrentDirectoryA into it. Returns 1
 * on success, 0 on any registry/chdir failure (the open key is
 * leaked on Query failure - matching original behavior).
 */
#include "audio/sound.h"
#include "platform/win32.h"

/*
 * @addr 0x004acc50
 */
s32 CheckInstallPath(void)
{
    HKEY  hkey  = NULL;
    DWORD cbData = 1024;

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE,
                      "Software\\GT Interactive\\Mortal Kombat 4\\1.00",
                      0, KEY_READ, &hkey) != 0) {
        return 0;
    }
    if (RegQueryValueExA(hkey, "Path", 0, NULL,
                         (BYTE *)g_installPath, &cbData) != 0) {
        return 0;
    }
    RegCloseKey(hkey);
    return SetCurrentDirectoryA(g_installPath) != 0 ? 1 : 0;
}
