#include "engine/scenegraph.h"
extern void tail(void);

/* var1: minimal */
void Try1(void) {
    g_walkCallback = (void(*)(void))*(unsigned int *)(g_fightGroupHead * 4 + 0x28);
    tail();
}

/* var2: intermediate idx local */
void Try2(void) {
    unsigned int idx = g_fightGroupHead;
    g_walkCallback = (void(*)(void))*(unsigned int *)(idx * 4 + 0x28);
    tail();
}

/* var3: intermediate value local */
void Try3(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x28);
    g_walkCallback = (void(*)(void))v;
    tail();
}

/* var4: int return type */
int Try4(void) {
    unsigned int idx = g_fightGroupHead;
    g_walkCallback = (void(*)(void))*(unsigned int *)(idx * 4 + 0x28);
    tail();
    return 0;
}
