#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* attempt 1: natural |= 1 */
void Try1(void) {
    unsigned int idx = g_scaledInit_00542044;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x34) | 1;
    g_walkCallback = (void(*)(void))v;
    *(unsigned int *)(idx * 4 + 0x34) = v;
}

/* attempt 2: low-byte only OR through cast */
void Try2(void) {
    unsigned int idx = g_scaledInit_00542044;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x34);
    *((unsigned char *)&v) |= 1;
    g_walkCallback = (void(*)(void))v;
    *(unsigned int *)(idx * 4 + 0x34) = v;
}

/* attempt 3: composed via union-ish split */
void Try3(void) {
    unsigned int idx = g_scaledInit_00542044;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x34);
    v = (v & 0xFFFFFF00u) | ((v | 1u) & 0xFFu);
    g_walkCallback = (void(*)(void))v;
    *(unsigned int *)(idx * 4 + 0x34) = v;
}
