/**
 * COM vtable-call seam for NON_MATCHING twins (audio/video platform glue).
 *
 * The DirectSound / DirectDraw / Direct3D wrappers invoke COM interface
 * methods by the classic vtable dispatch: load the object's vtable pointer
 * (`*iface`), index a method slot by byte offset, and call it with `iface`
 * as the implicit `this` argument. Ghidra renders that as
 *
 *     (**(code **)(*iface + 0x18))(iface, args)
 *
 * which cannot compile while `code` is a plain byte. ghidra_postprocess.py
 * rewrites the `**(code **)` lead-in to `*(MK4ComMethod *)`, turning the
 * expression into a typed call through the method slot:
 *
 *     (*(MK4ComMethod *)(*iface + 0x18))(iface, args)
 *
 * This is a faithful transcription of the original asm dispatch (no
 * behaviour change), so it is correct on any target where `iface` holds a
 * real COM object - i.e. the Windows/mingw portable build, which links the
 * real DirectX. A native non-Windows backend is the PAL's job (Phase 2,
 * src/platform/): it populates these interface pointers with its own vtables
 * (SDL audio / a GL renderer), and this same call site dispatches into them
 * unchanged. The seam is the call mechanism; the backends are downstream.
 *
 * COM methods are __stdcall (callee cleans the stack); the typedef must say
 * so or a cdecl call site would corrupt the stack. The empty parameter list
 * is K&R "unspecified" - each rewritten call site passes the exact argument
 * list Ghidra recovered, and the __stdcall callee cleans its own fixed args.
 */
#ifndef MK4_PORTABLE_COM_H
#define MK4_PORTABLE_COM_H

#ifdef NON_MATCHING

#if defined(_WIN32) || defined(__stdcall)
typedef int(__stdcall *MK4ComMethod)();
#else
/* Non-Windows backend: no stdcall ABI; the PAL supplies cdecl thunks. */
typedef int (*MK4ComMethod)();
#endif

#endif /* NON_MATCHING */

#endif /* MK4_PORTABLE_COM_H */
