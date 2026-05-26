/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004ac520 (70b)
 *   if g_timerFlag != 0:
 *     call F; if ret == 0:
 *       load g_audioPreState; push 0,2,0x808,it,IAT;
 *     if g_audioState00 == 0: clear via IAT [g_iat_00...4022240];
 *     g_audioState00 = ret; clear g_timerFlag.
 */
extern u32 g_timerFlag;
extern u32 g_audioState00;
extern u32 g_audioPreState;
extern int Helper_AuxAudio_PostInit(void);
extern void (__stdcall *g_iat_004d2244)(int, int, int, int);
extern int (__stdcall *g_iat_004d2240)(void);
void Helper_TitleEnterStateC(void) {
    if (g_timerFlag != 0 && Helper_AuxAudio_PostInit() != 0) {
        g_iat_004d2244((int)g_audioPreState, 0x808, 2, 0);
    }
    if (g_audioState00 == 0) {
        g_audioState00 = (unsigned int)g_iat_004d2240();
    }
    g_timerFlag = 0;
}

