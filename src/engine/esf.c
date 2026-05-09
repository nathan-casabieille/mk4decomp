/**
 * ESF (Eurocom Sound Format) loader.
 */
#include "engine/esf.h"
#include "engine/fsys.h"

/*
 * Close the currently-open ESF file. Idempotent: handle == 0 is a
 * no-op except for clearing the slot.
 *
 * @addr 0x004b1200
 */
void ESF_Close(void)
{
    if (g_esf_handle != 0) {
        FSYS_fclose(g_esf_handle);
    }
    g_esf_handle = 0;
}
