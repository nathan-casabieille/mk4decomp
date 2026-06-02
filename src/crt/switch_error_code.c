/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004cf6d0 (40b)
 *   switch (arg) { case 1: errno=0x21; default: ret; case 2..3: errno=0x22; }
 */
extern int *Crt_errno(void);
void SwitchErrorCode(int arg) {
    int *errno_ptr;
    switch (arg) {
    case 1:
        errno_ptr = Crt_errno();
        *errno_ptr = 0x21;
        return;
    case 2:
    case 3:
        errno_ptr = Crt_errno();
        *errno_ptr = 0x22;
        return;
    }
}
