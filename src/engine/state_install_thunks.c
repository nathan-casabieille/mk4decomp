/*
 * Fight-mode state-install thunks - NATIVE BUILD ONLY.
 *
 * The three fight tables at 0x004e9250..0x004e934f are {bitmask, handler VA}
 * pairs, and FightFrameStep_Inner calls the handler whose bit is set. Every one
 * of the 22 handlers below is the same fourteen bytes:
 *
 *     push <descriptor VA> ; call StateInstallOrForward_0048e6b* ; add esp, 4 ; ret
 *
 * with the descriptors laid out at 0x004e8b50 on a 0x38 stride. None of them
 * has a symbols.yaml entry - they sit inside the 3478-byte blob the map calls
 * PendingMatch_ZeroNDwords - so MK4_ResolveCode had no native target for any of
 * them and the whole fight-mode dispatch resolved to the reporting no-op.
 *
 * They are registered through config/codeptr_extras.yaml rather than by
 * splitting that blob in symbols.yaml, so the matching build is untouched.
 */

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#endif

#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void StateInstallOrForward_0048e6b0(int arg);
extern void StateInstallOrForward_0048e6e0(int arg);

void Thunk_StateInstall_0045ca00(void) { StateInstallOrForward_0048e6b0(0x4e8b50); }
void Thunk_StateInstall_0045ca60(void) { StateInstallOrForward_0048e6b0(0x4e8b88); }
void Thunk_StateInstall_0045ca80(void) { StateInstallOrForward_0048e6b0(0x4e8bc0); }
void Thunk_StateInstall_0045caa0(void) { StateInstallOrForward_0048e6b0(0x4e8bf8); }
void Thunk_StateInstall_0045cac0(void) { StateInstallOrForward_0048e6b0(0x4e8c30); }
void Thunk_StateInstall_0045cb40(void) { StateInstallOrForward_0048e6b0(0x4e8c68); }
void Thunk_StateInstall_0045cbe0(void) { StateInstallOrForward_0048e6b0(0x4e8ca0); }
void Thunk_StateInstall_0045cc90(void) { StateInstallOrForward_0048e6b0(0x4e8cd8); }
void Thunk_StateInstall_0045cd00(void) { StateInstallOrForward_0048e6b0(0x4e8d10); }
void Thunk_StateInstall_0045cda0(void) { StateInstallOrForward_0048e6b0(0x4e8d48); }
void Thunk_StateInstall_0045cdb0(void) { StateInstallOrForward_0048e6e0(0x4e8d88); }
void Thunk_StateInstall_0045ce40(void) { StateInstallOrForward_0048e6b0(0x4e8dc8); }
void Thunk_StateInstall_0045ced0(void) { StateInstallOrForward_0048e6e0(0x4e8e00); }
void Thunk_StateInstall_0045cf30(void) { StateInstallOrForward_0048e6e0(0x4e8e38); }
void Thunk_StateInstall_0045cf50(void) { StateInstallOrForward_0048e6e0(0x4e8e70); }
void Thunk_StateInstall_0045cf70(void) { StateInstallOrForward_0048e6e0(0x4e8ea8); }
void Thunk_StateInstall_0045cf90(void) { StateInstallOrForward_0048e6e0(0x4e8ee0); }
void Thunk_StateInstall_0045d010(void) { StateInstallOrForward_0048e6e0(0x4e8f18); }
void Thunk_StateInstall_0045d0b0(void) { StateInstallOrForward_0048e6e0(0x4e8f50); }
void Thunk_StateInstall_0045d450(void) { StateInstallOrForward_0048e6e0(0x4e8f88); }
void Thunk_StateInstall_0045d4c0(void) { StateInstallOrForward_0048e6e0(0x4e8fc0); }
void Thunk_StateInstall_0045d560(void) { StateInstallOrForward_0048e6e0(0x4e8ff8); }
#endif /* NON_MATCHING */
