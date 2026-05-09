# Acquiring MSVC 5.0 for the matching build

To rebuild MK4.EXE byte-for-byte we need the exact toolchain Eurocom
used in 1998: Microsoft Visual C++ 5.0 (linker version 5.10), most
likely SP3.

This file is a guide. We don't ship Microsoft's binaries here. You
provide your own copy.

## What you actually need (minimum file set)

For a matching build we don't need the full IDE, just the command-line
toolchain. The minimum file set:

```
Bin/
  CL.EXE         driver
  C1.DLL         C front-end (note: DLL on the Learning Edition CD)
  C2.EXE         C back-end / optimizer
  C1XX.DLL       C++ front-end (only if any .cpp files)
  LINK.EXE       linker
  CVTRES.EXE     resource converter (LINK calls it)
  LIB.EXE        librarian (optional)

  Bin DLL deps (LINK / CL fail to load without these):
  MSPDB50.DLL    debug-info helper       (in SHAREDIDE/BIN/ on CD)
  MSDIS100.DLL   disassembler helper     (in SHAREDIDE/BIN/ on CD)
  MSVCP50.DLL    Visual C++ standard C++ runtime  (in VC/REDIST/)
  MSVCRT.DLL     Visual C++ C runtime    (in VC/BIN/)

Lib/
  LIBC.LIB       single-threaded CRT
  LIBCMT.LIB     multi-threaded CRT  (MK4 uses this, built with /MT)
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

## Linker version caveat (RTM vs 5.10)

MK4.EXE was linked with **LINK.EXE 5.10** (PE header
MinorLinkerVersion=10), which came with MSVC 5.0 SP3 (1998). The
Visual C++ Learning Edition CD ships with **LINK.EXE 5.00.7022**
(RTM, 1997). The compiler is the same major version but the linker
is older.

In practice this means:
- Per-function asm produced by CL.EXE should still match (compiler
  side is the same)
- The PE header and link-step bytes will differ slightly (linker
  version field, possibly section-layout details)
- Our diff tool will count those as mismatches even if the C is
  correct

For the first matching pass we proceed with whatever LINK we have.
If final-pass byte parity is needed, swap in LINK.EXE from MSVC 5.0
SP3 (see "Service pack" below).

## Where to legally obtain MSVC 5.0

**Option 1: eBay / used software resellers**
Visual Studio 5.0 Professional CDs come up regularly, around 50-100
USD. The CD includes everything we need plus the SP3 patches.

**Option 2: Visual C++ Learning Edition CD**
Cheaper / easier to find. Has the compiler but ships with linker
5.00 (not 5.10). Good enough to start matching, may need to source
SP3 LINK.EXE separately later.

**Option 3: Old MSDN subscription archives**
If you (or your employer) had an MSDN subscription in the late 90s,
the disc archives include MSVC 5.0 + service packs.

**Option 4: Internet Archive**
MSVC 5.0 has been uploaded to archive.org under various names ("Visual
Studio 97", "Visual C++ 5.0", "Visual C++ Learning Edition 5.0"). Legally
the binaries remain Microsoft IP and you should be aware of that.

**Option 5: Use MSVC 6.0 with caveats**
MSVC 6.0 is more available. Downside: linker 6.0 produces noticeably
different binaries. Not recommended for the matching target. Fine for
the portable target.

## After installation

1. Run `./tools/decomp/setup-msvc50.sh` to create the Whisky bottle.

2. Mount your MSVC 5.0 CD or ISO and copy the files into the bottle.
   Example for the Learning Edition CD layout (`DEVSTUDIO/`):

   ```sh
   . config/msvc50.env
   ROOT=$MSVC50_ROOT

   # Bin
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/VC/BIN/CL.EXE      "$ROOT/Bin/"
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/VC/BIN/LINK.EXE    "$ROOT/Bin/"
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/VC/BIN/C1.DLL      "$ROOT/Bin/"
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/VC/BIN/C1XX.DLL    "$ROOT/Bin/"
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/VC/BIN/C2.EXE      "$ROOT/Bin/"
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/VC/BIN/CVTRES.EXE  "$ROOT/Bin/"
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/VC/BIN/LIB.EXE     "$ROOT/Bin/"
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/VC/BIN/MSVCRT.DLL  "$ROOT/Bin/"

   # DLL deps from elsewhere on the CD
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/SHAREDIDE/BIN/MSPDB50.DLL  "$ROOT/Bin/"
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/SHAREDIDE/BIN/MSDIS100.DLL "$ROOT/Bin/"
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/VC/REDIST/MSVCP50.DLL      "$ROOT/Bin/"

   # Lib + Include (everything)
   cp /Volumes/VC50LRNCD1/DEVSTUDIO/VC/LIB/*.LIB    "$ROOT/Lib/"
   cp -R /Volumes/VC50LRNCD1/DEVSTUDIO/VC/INCLUDE/* "$ROOT/Include/"
   ```

3. Verify:
   ```sh
   ./tools/decomp/test-toolchain.sh
   ```
   Expect output ending with `Toolchain OK (hello.exe returned 42)`.

## Service pack

MSVC 5.0 SP3 (1998) is the latest SP. MK4 was released July 1998 so
likely built against SP3.

You can identify your CL.EXE's exact build by running it with no args:

```
$ ./tools/decomp/cl.sh
Microsoft (R) 32-bit C/C++ ... Compiler Version 11.00.0000 for 80x86
                                                       ^^^^^^^^^^^
                                                       this is the build
```

Compiler build numbers (the third dotted-number group):
- `11.00.0000` = RTM (Visual C++ 5.0 original)
- `11.00.7016` = SP1
- `11.00.7022` = SP2 / SP3 (rebadged)

The Learning Edition CD ships RTM. SP3 patches must be applied
separately if you want exact MK4 toolchain parity.
