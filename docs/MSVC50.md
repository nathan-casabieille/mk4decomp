# Acquiring MSVC 5.0 for the matching build

To rebuild MK4.EXE byte-for-byte we need the **exact** toolchain Eurocom
used in 1998: Microsoft Visual C++ 5.0 (linker version 5.10), most likely
SP3.

This file is a guide — we don't ship Microsoft's binaries here. You
provide your own copy.

## What you actually need (minimum file set)

For a matching build we don't need the full IDE — just the command-line
toolchain. The minimum file set:

```
Bin/
  CL.EXE         — driver
  C1.EXE         — C front-end  (preprocessing + parsing)
  C2.EXE         — C back-end   (codegen + optimizer)
  C1XX.EXE       — C++ front-end (only if any .cpp files)
  LINK.EXE       — linker (5.10)
  ML.EXE         — assembler (only if .asm sources)
  MSPDB50.DLL    — debug-info helper (LINK calls it)

Lib/
  LIBC.LIB       single-threaded CRT
  LIBCMT.LIB     multi-threaded CRT  (MK4 uses this — built with /MT)
  OLDNAMES.LIB
  KERNEL32.LIB
  USER32.LIB
  GDI32.LIB
  ADVAPI32.LIB
  WINMM.LIB
  DDRAW.LIB      DirectDraw 5/6
  DSOUND.LIB
  UUID.LIB

Include/
  C runtime headers (stdio.h, string.h, ...)
  Win32 SDK headers (windows.h, mmsystem.h, ddraw.h, dsound.h, ...)
```

The DDraw / DSound .lib + .h files come from the **DirectX 5 SDK**
(later 5.x SDKs work; 7.0+ may have ABI changes). MK4's ddraw.dll
imports are DDraw 5-era.

## Where to legally obtain MSVC 5.0

**Option 1 — eBay / used software resellers**
Visual Studio 5.0 Professional CDs come up regularly. ~$50-100 USD.
The CD includes everything we need.

**Option 2 — Old MSDN subscription archives**
If you (or your employer) had an MSDN subscription in the late 90s,
the disc archives include MSVC 5.0. The MSDN Library CDs are usually
in the back of physical archive shelves at older companies.

**Option 3 — Internet Archive / abandonware sites**
MSVC 5.0 has been uploaded to archive.org under various names. Check
"Visual Studio 97" or "Visual C++ 5.0". Microsoft's stance on this
era of tools is permissive in practice (they actively encourage moving
on to modern toolchains and don't pursue old ISO availability).

This is the **practical** route most decomp projects use, but legally
the binaries remain Microsoft's IP and you should be aware of that.

**Option 4 — Use MSVC 6.0 with caveats**
MSVC 6.0 is more available. The downside: linker 6.0 produces slightly
different binaries, and we'd lose byte-matching for sections affected
by linker output. Our diff tool would show ~5-10% non-matching bytes
even on perfect C source. Not recommended for the matching target —
fine for the portable target.

## After installation

1. Install the IDE somewhere (anywhere — we only care about the binaries).
   The default install path is `C:\Program Files\DevStudio\VC`.

2. Copy the files listed above into the Whisky bottle:

   ```sh
   BOTTLE_PREFIX=$(grep MSVC50_PREFIX config/msvc50.env | cut -d'"' -f2)
   MSVC5_ROOT="$BOTTLE_PREFIX/drive_c/MSVC5"

   # Adjust to your installation paths.
   cp /path/to/msvc5/Bin/CL.EXE     "$MSVC5_ROOT/Bin/"
   cp /path/to/msvc5/Bin/LINK.EXE   "$MSVC5_ROOT/Bin/"
   cp /path/to/msvc5/Bin/C1.EXE     "$MSVC5_ROOT/Bin/"
   cp /path/to/msvc5/Bin/C2.EXE     "$MSVC5_ROOT/Bin/"
   cp /path/to/msvc5/Bin/MSPDB50.DLL "$MSVC5_ROOT/Bin/"

   cp /path/to/msvc5/Lib/*.LIB     "$MSVC5_ROOT/Lib/"
   cp -R /path/to/msvc5/Include/*  "$MSVC5_ROOT/Include/"

   # Plus the DDraw / DSound bits from the DirectX 5 SDK:
   cp /path/to/dx5sdk/lib/DDRAW.LIB  "$MSVC5_ROOT/Lib/"
   cp /path/to/dx5sdk/lib/DSOUND.LIB "$MSVC5_ROOT/Lib/"
   cp /path/to/dx5sdk/include/ddraw.h  "$MSVC5_ROOT/Include/"
   cp /path/to/dx5sdk/include/dsound.h "$MSVC5_ROOT/Include/"
   ```

3. Verify:

   ```sh
   ./tools/decomp/test-toolchain.sh
   ```

   You should see a tiny `hello.exe` get built without errors.

## Service pack

MSVC 5.0 SP3 (1998) is the latest SP. MK4 was released July 1998 so
likely built against SP3 or possibly SP2.

You can identify your CL.EXE's exact build by running it with no args:

```
$ ./tools/decomp/cl.sh
Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 11.00.7022 for 80x86
                                                       ^^^^^^^^^^^
                                                       this is the build
```

Build numbers:
- `11.00.7022` = SP3
- `11.00.7016` = SP2
- `11.00.7011` = SP1
- `11.00.7022` = RTM (= 11.00.0)

Try SP3 first; if our diff tool shows a stubborn instruction-selection
mismatch, downgrade to SP2 or RTM and try again.
