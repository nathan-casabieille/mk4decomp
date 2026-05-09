/**
 * Install / config helpers.
 */
#include "platform/install.h"

/*
 * Compute the validation hash over g_configBuffer bytes 4..0x247.
 * Magic seed 0x43464729 is "GFCB" (some Eurocom acronym in
 * little-endian). Each byte is sign-extended and shifted into the
 * accumulator by (i mod 23).
 *
 * @addr 0x004ad210
 */
s32 ComputeConfigHash(void)
{
    s32 hash = 0x43464729;
    unsigned int i;
    for (i = 4; i < 0x248; i++) {
        hash += (s32)(signed char)g_configBuffer[i] << (i % 23);
    }
    return hash;
}

/*
 * XOR-stream deobfuscation of g_configBuffer (588 bytes).
 * Each byte is XORed with (i * 0x7b) interpreted as signed char.
 *
 * @addr 0x004ad250
 */
void DeobfuscateConfig(void)
{
    unsigned int i;
    for (i = 0; i < 0x24c; i++) {
        g_configBuffer[i] ^= (signed char)((signed char)i * (signed char)0x7b);
    }
}
