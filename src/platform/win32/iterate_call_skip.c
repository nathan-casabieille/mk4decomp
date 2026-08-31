/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#endif

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004c4210 (37b)
 *   push    esi
 *   push    edi
 *   xor     esi, esi
 *   mov     edi, 0x00f8fade
 * .loop:
 *   test    byte ptr [edi], 4
 *   jne     .skip
 *   push    esi
 *   call    F
 *   add     esp, 4
 * .skip:
 *   inc     esi
 *   add     edi, 0x1c
 *   cmp     si, 0x0898
 *   jl      .loop
 *   pop     edi
 *   pop     esi
 *   ret
 */
extern int Helper_AudioStop(int);
void IterateCallSkip(void) {
    int i = 0;
    /* 0xf8fade is a VA (the audio-channel flag bytes, stride 0x1c); the
     * lift's raw host pointer faulted the moment the match sequencer's
     * teardown first reached this walk under the arena. */
#ifdef MK4_ARENA
    unsigned char *p = MK4_VA(unsigned char, 0x00f8fadeu);
#else
    unsigned char *p = (unsigned char *)0x00f8fade;
#endif
    do {
        if ((*p & 4) == 0) {
            Helper_AudioStop(i);
        }
        i++;
        p += 0x1c;
    } while ((short)i < 0x0898);
}
