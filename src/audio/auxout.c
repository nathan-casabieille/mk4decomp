/**
 * Auxiliary-audio (Windows multimedia auxOut) helpers.
 */
#include "audio/sound.h"
#include "platform/win32.h"
#include <mmsystem.h>

/*
 * Clamp vol to [0, 100], expand it to a 16-bit-per-channel DWORD by
 * multiplying with 0x028F028F (= 0xFFFF/100 packed in both halves),
 * and broadcast the resulting volume to every active aux device via
 * auxSetVolume.
 *
 * @addr 0x004aca10
 */
void AuxAudio_SetVolume(s32 vol)
{
    DWORD packed;
    s32   i;

    if (vol < 0)   vol = 0;
    if (vol > 100) vol = 100;
    packed = (DWORD)vol * 0x028F028FU;

    for (i = 0; i < g_auxCount; i++) {
        auxSetVolume(g_auxChannels[i].deviceId, packed);
    }
}
