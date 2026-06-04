/**
 * Ghidra base typedefs for decompiled NON_MATCHING twins.
 *
 * The Ghidra pipeline (tools/decomp/ghidra_postprocess.py) emits C that
 * uses Ghidra's primitive type names. This header maps them to portable
 * fixed-width-ish C types so the twins compile under any backend. Only
 * included from files that carry a Ghidra-lifted twin (and only matters
 * under NON_MATCHING - the matching #else never sees these names).
 */
#ifndef MK4_PORTABLE_GHIDRA_TYPES_H
#define MK4_PORTABLE_GHIDRA_TYPES_H

typedef unsigned char      undefined;
typedef unsigned char      undefined1;
typedef unsigned short     undefined2;
typedef unsigned int       undefined4;
typedef unsigned long long undefined8;
typedef unsigned int       uint;
typedef unsigned short     ushort;
typedef unsigned char      uchar;
typedef unsigned char      byte;
typedef unsigned long      ulong;

#endif /* MK4_PORTABLE_GHIDRA_TYPES_H */
