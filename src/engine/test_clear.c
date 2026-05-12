#include "engine/scenegraph.h"
extern void tail(void);

void Try1(void) {
    unsigned int idx = g_fightGroupHead;
    g_walkCallback = (void(*)(void))0;
    *(unsigned int *)(idx * 4 + 0x28) = 0;
    tail();
}

void Try2(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int z = 0;
    g_walkCallback = (void(*)(void))z;
    *(unsigned int *)(idx * 4 + 0x28) = z;
    tail();
}
