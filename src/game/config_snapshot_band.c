/**
 * The CONFIG SNAPSHOT / RESTORE pair - the first thing every front-end
 * controller tick runs, and a weak no-op until now (MK4_TRACE_STUBS counted
 * 159 hits of Config_RestoreGlobals in a 200-frame menu run, one per menu
 * tick plus the sub-screens').
 *
 * The two are a mirrored pair around one gate, g_gsmFlag (0x543930) and
 * g_configInitGate (0x543f7c):
 *
 *   Config_RestoreGlobals (0x4acce0) - if EITHER is clear, raise both, take
 *     a snapshot first when g_gsmFlag was the clear one (so the very first
 *     entry saves the live state before overwriting it), then copy the saved
 *     block back over the live globals. The six values at the tail are
 *     restored on EVERY call, gate or no gate: they are the options screens'
 *     settings, and 0x4f3608 among them is the round/ovr limit the fight
 *     gates compare against.
 *   Config_SnapshotGlobals (0x4ace60) - the exact inverse of the gated part,
 *     and it runs only when BOTH gate words are already set.
 *
 * The bulk is 0x3c dwords at 0x543934 <-> 0x53a53c and 21 bytes (5 dwords
 * plus the trailing movsb the original schedules late) at 0x543a6c <->
 * 0x4f3f28, then two dozen scalars.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes from
 * the naked bodies in src/audio/audio_restore_globals.c and
 * src/audio/audio_snapshot_globals.c. Neither file is in the native list.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

#define GB(addr)  (*MK4_VA(unsigned char, (addr)))
#define GW(addr)  (*MK4_VA(unsigned int,  (addr)))

#define g_gsmFlag         GW(0x543930u)
#define g_configInitGate  GW(0x543f7cu)

static void config_copy(unsigned int dst, unsigned int src,
                        unsigned int dwords, int trailingByte)
{
    unsigned int i;

    for (i = 0; i < dwords; i++)
        GW(dst + i * 4u) = GW(src + i * 4u);
    if (trailingByte)
        GB(dst + dwords * 4u) = GB(src + dwords * 4u);
}

/* 0x4ace60 - live globals -> the saved block. Runs only with both gates up. */
void Config_SnapshotGlobals(void)
{
    if (g_gsmFlag == 0 || g_configInitGate == 0)
        return;

    config_copy(0x543934u, 0x53a53cu, 0x3c, 0);
    config_copy(0x543a6cu, 0x4f3f28u, 5, 1);

    GB(0x543a24u) = GB(0x4f3238u);
    GW(0x543a28u) = GW(0x4f31ccu);
    GW(0x543a2cu) = GW(0x4f31d0u);
    GW(0x543a30u) = GW(0x5437f8u);
    GW(0x543a34u) = GW(0x5437fcu);
    GW(0x543a38u) = GW(0x4f3234u);
    GB(0x543a3cu) = GB(0x543724u);
    GB(0x543a3du) = GB(0x54372cu);
    GB(0x543a3eu) = GB(0x543730u);
    GW(0x543a40u) = GW(0x543734u);
    GW(0x543a44u) = GW(0x543738u);
    GW(0x543a48u) = GW(0x54373cu);
    GW(0x543a4cu) = GW(0x543740u);
    GW(0x543a50u) = GW(0x4f3814u);
    GW(0x543a54u) = GW(0x4f3818u);
    GW(0x543a58u) = GW(0x4f381cu);
    GW(0x543a5cu) = GW(0x4f3820u);
    GW(0x543a60u) = GW(0x4f3ae4u);
    GW(0x543a64u) = GW(0x4f3ae8u);
    GW(0x543a68u) = GW(0x52ab40u);
}

/* 0x4acce0 - the saved block -> the live globals, plus the options tail */
void Config_RestoreGlobals(void)
{
    if (g_gsmFlag == 0 || g_configInitGate == 0) {
        int wasClear = (g_gsmFlag == 0);

        g_gsmFlag = 1;
        g_configInitGate = 1;
        if (wasClear)
            Config_SnapshotGlobals();

        config_copy(0x53a53cu, 0x543934u, 0x3c, 0);
        config_copy(0x4f3f28u, 0x543a6cu, 5, 1);

        GB(0x4f3238u) = GB(0x543a24u);
        GW(0x4f31ccu) = GW(0x543a28u);
        GW(0x4f31d0u) = GW(0x543a2cu);
        GW(0x5437f8u) = GW(0x543a30u);
        GW(0x5437fcu) = GW(0x543a34u);
        GW(0x4f3234u) = GW(0x543a38u);
        GB(0x543724u) = GB(0x543a3cu);
        GB(0x54372cu) = GB(0x543a3du);
        GB(0x543730u) = GB(0x543a3eu);
        GW(0x543734u) = GW(0x543a40u);
        GW(0x543738u) = GW(0x543a44u);
        GW(0x54373cu) = GW(0x543a48u);
        GW(0x543740u) = GW(0x543a4cu);
        GW(0x4f3814u) = GW(0x543a50u);
        GW(0x4f3818u) = GW(0x543a54u);
        GW(0x4f381cu) = GW(0x543a58u);
        GW(0x4f3820u) = GW(0x543a5cu);
        GW(0x4f3ae4u) = GW(0x543a60u);
        GW(0x4f3ae8u) = GW(0x543a64u);
        GW(0x52ab40u) = GW(0x543a68u);
    }

    /* the options screens' settings, restored unconditionally */
    GB(0x4f360cu) = GB(0x543ab4u);
    GB(0x4f3610u) = GB(0x543ab4u);
    GW(0x4f3608u) = GW(0x543ab0u);
    GW(0x4f3404u) = GW(0x543aacu);
    GW(0x53a1f0u) = GW(0x543a9cu);
    GW(0x4f361cu) = GW(0x543aa0u);
}

#endif /* NON_MATCHING */
