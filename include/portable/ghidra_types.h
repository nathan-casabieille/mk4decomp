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

/* Only needed by the portable (NON_MATCHING) twins. Kept entirely out of
 * the matching build: MSVC 5.0 is C89 and rejects `long long`, and the
 * #include sits outside the per-function #ifdef, so the header body MUST
 * be inert under matching. */
#ifdef NON_MATCHING

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

/* Ghidra uses `code` as the element type for function-pointer casts, e.g.
 * `*(code **)(node + off) = target;` to store/load a continuation address.
 * Mapping it to a byte lets those pointer store/loads compile and preserves
 * the stored address value, while a genuine indirect *call* through a
 * `code *` (`(*(code *)p)()`) stays a compile error - so the injector's
 * compile gate still bails on real indirect-call FSM continuations, which
 * belong to the Phase-C hard cluster, not the mechanical store/load twins. */
typedef unsigned char      code;

/* x87 80-bit extended values and the odd-width signed byte Ghidra emits. */
typedef long double        float10;
typedef long double        unkbyte10;
typedef signed char        sbyte;

/* Ghidra emits bool/true/false; provide them for pre-C23 C backends. In
 * C23+ they are built-in keywords (defining them is an error), so skip. */
#if !defined(__cplusplus) && (!defined(__STDC_VERSION__) || __STDC_VERSION__ < 202311L)
typedef int bool;
#define true  1
#define false 0
#endif

#endif /* NON_MATCHING */

#endif /* MK4_PORTABLE_GHIDRA_TYPES_H */
