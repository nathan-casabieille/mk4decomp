/**
 * EXE integrity check used at audio init.
 *
 * Reads our own EXE via GetModuleFileNameA + fopen("rb"), computes
 * a 64-bit hash of (some prefix of) the file, and validates it
 * against two compile-time constants. -10 on mismatch.
 */
#include "audio/sound.h"
#include "platform/win32.h"

/*
 * @addr 0x004aca60
 */
s32 GetExeDirectory(void)
{
    char path[1024];
    s32  rc;

    if (GetModuleFileNameA(GetModuleHandleA(NULL), path, sizeof(path)) == 0) {
        return -1;
    }
    rc = Helper_ComputeExeHash(path);
    if (rc != 0) {
        return rc;
    }
    do {
        if (g_exeIntegrityValueA != g_exeIntegrityRefA) break;
        if (g_exeIntegrityValueB != g_exeIntegrityRefB) break;
        return 0;
    } while (0);
    return -10;
}
