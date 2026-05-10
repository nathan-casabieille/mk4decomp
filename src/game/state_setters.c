/**
 * 13 trivial "set state index N" helpers.
 *
 * Each is 16 bytes: store the constant N into g_walkCallback (as
 * a packed function-pointer-shaped int) and into g_walkStateIndex.
 * Reverse-engineered as a uniform pattern from a contiguous 16-byte
 * stride of stubs at 0x00461860..0x00461920.
 */
#include "engine/scenegraph.h"

#define DECL_SETTER(addr_hex, name, value) \
    /* @addr 0x##addr_hex */ \
    void name(void) { \
        g_walkCallback   = (void (*)(void))(value); \
        g_walkStateIndex = (value); \
    }

DECL_SETTER(00461860, Helper_SetState_1A, 0x1a)
DECL_SETTER(00461870, Helper_SetState_10, 0x10)
DECL_SETTER(00461880, Helper_SetState_0F, 0x0f)
DECL_SETTER(00461890, Helper_SetState_0E, 0x0e)
DECL_SETTER(004618a0, Helper_SetState_0C, 0x0c)
DECL_SETTER(004618b0, Helper_SetState_0B, 0x0b)
DECL_SETTER(004618c0, Helper_SetState_09, 0x09)
DECL_SETTER(004618d0, Helper_SetState_07, 0x07)
DECL_SETTER(004618e0, Helper_SetState_06, 0x06)
DECL_SETTER(004618f0, Helper_SetState_05, 0x05)
DECL_SETTER(00461900, Helper_SetState_04, 0x04)
DECL_SETTER(00461910, Helper_SetState_03, 0x03)
DECL_SETTER(00461920, Helper_SetState_02, 0x02)
