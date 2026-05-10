/* Test: ESF_Open */
#include "engine/esf.h"
#include "engine/fsys.h"
#include "platform/install.h"

static const char k_esf_rb[] = "rb";
static const char k_esf_open_err[] = "ESF_Open()";

int ESF_Open(const char *filename, int *bits, int *rate, int *channels)
{
    ESF_Close();
    g_esf_magic = 0;
    g_esf_state = 0;
    g_esf_handle = FSYS_fopen(filename, k_esf_rb);
    FSYS_fread(&g_esf_magic, 8, 1, g_esf_handle);
    if (g_esf_magic != 0x06465345) {
        ShowErrorMessage(k_esf_open_err);
    }
    if (bits != NULL) {
        *bits = ((g_esf_state >> 29) & 1) ? 16 : 8;
    }
    if (rate != NULL) {
        *rate = ((g_esf_state >> 30) & 1) ? 22050 : 11025;
    }
    if (channels != NULL) {
        *channels = g_esf_state >> 31;
    }
    return g_esf_state & 0x1FFFFFFF;
}
