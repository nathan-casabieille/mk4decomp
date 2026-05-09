# Acquiring MSVC 5.0 for the matching build

To rebuild MK4.EXE byte-for-byte we need the exact toolchain Eurocom
used in 1998: **Microsoft Visual C++ 5.0 Professional (or Enterprise),
SP3** - i.e. the Optimizing Compiler build 11.00.7022.

This file is a guide. We don't ship Microsoft's binaries here. You
provide your own copy.

## DO NOT use the Learning Edition

The Visual C++ 5.0 Learning Edition CD looks tempting (cheaper, more
common), but it ships a stripped-down CL.EXE called the **Standard
Compiler**. You can recognise it from the banner:

```
Microsoft (R) 32-bit C/C++ Standard Compiler Version 11.00.xxxx
                              ^^^^^^^^
                              wrong - this is the LE
```

The Standard Compiler silently rejects `/Og /Oi /Oy /Os /Ob1 ...`
and only ever applies `/Ot /Ob0` to the back-end. Even with `/O2`
you get unoptimised output: full prologue, locals on the stack, no
register promotion. MK4.EXE was built with the Optimizing Compiler;
matching is impossible with the LE.

The Pro / Enterprise editions ship the right tool:

```
Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 11.00.7022
                              ^^^^^^^^^^
                              this is what you want (SP3 build)
```

## What you actually need (minimum file set)

For a matching build we don't need the full IDE, just the
command-line toolchain:

```
Bin/
  CL.EXE         driver
  C1.DLL         C front-end
  C1XX.DLL       C++ front-end (only if any .cpp files)
  C2.EXE         C back-end / optimizer
  LINK.EXE       linker
  CVTRES.EXE     resource converter (LINK calls it)
  LIB.EXE        librarian (optional)
  DUMPBIN.EXE    PE inspector (optional, useful for diffing)

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

## Where to legally obtain MSVC 5.0

**Option 1: eBay / used software resellers**
Visual Studio 5.0 Professional CDs come up regularly, around 50-100
USD. Pick a disc that already includes SP3 (the back of the box or
the disc label usually mentions it).

**Option 2: Old MSDN subscription archives**
If you (or your employer) had an MSDN subscription in the late 90s,
the disc archives include MSVC 5.0 Professional + service packs.

**Option 3: Internet Archive**
MSVC 5.0 has been uploaded to archive.org under various names
("Visual Studio 97 Professional", "Visual C++ 5.0 Professional").
Legally the binaries remain Microsoft IP and you should be aware
of that.

**Option 4: Use MSVC 6.0 with caveats**
MSVC 6.0 is more available. Downside: linker 6.0 produces noticeably
different binaries. Not recommended for the matching target. Fine for
the portable target.

## After installation

1. Run `./tools/decomp/setup-msvc50.sh` to create the Whisky bottle.

2. Mount your MSVC 5.0 Professional CD or ISO and copy the files
   into the bottle:

   ```sh
   . config/msvc50.env
   ROOT=$MSVC50_ROOT
   SRC=/Volumes/VC50PROCD1/DEVSTUDIO   # adjust to your mount point

   # Bin
   cp "$SRC/VC/BIN/CL.EXE"       "$ROOT/Bin/"
   cp "$SRC/VC/BIN/C1.DLL"       "$ROOT/Bin/"
   cp "$SRC/VC/BIN/C1XX.DLL"     "$ROOT/Bin/"
   cp "$SRC/VC/BIN/C2.EXE"       "$ROOT/Bin/"
   cp "$SRC/VC/BIN/LINK.EXE"     "$ROOT/Bin/"
   cp "$SRC/VC/BIN/CVTRES.EXE"   "$ROOT/Bin/"
   cp "$SRC/VC/BIN/LIB.EXE"      "$ROOT/Bin/"
   cp "$SRC/VC/BIN/DUMPBIN.EXE"  "$ROOT/Bin/"
   cp "$SRC/VC/BIN/MSVCRT.DLL"   "$ROOT/Bin/"

   # DLL deps from elsewhere on the CD
   cp "$SRC/SHAREDIDE/BIN/MSPDB50.DLL"  "$ROOT/Bin/"
   cp "$SRC/SHAREDIDE/BIN/MSDIS100.DLL" "$ROOT/Bin/"
   cp "$SRC/VC/REDIST/MSVCP50.DLL"      "$ROOT/Bin/"

   # Lib + Include (everything)
   cp "$SRC/VC/LIB/"*.LIB    "$ROOT/Lib/"
   cp -R "$SRC/VC/INCLUDE/"* "$ROOT/Include/"
   ```

3. Verify:
   ```sh
   ./tools/decomp/test-toolchain.sh
   ```
   Expect output ending with `Toolchain OK (hello.exe returned 42)`.

4. Sanity-check the compiler build by running CL.EXE with no args:
   ```
   $ ./tools/decomp/cl.sh
   Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 11.00.7022 for 80x86
   ```
   The word **Optimizing** must appear (not "Standard"), and the
   build should be **7022** (SP3). If you see "Standard Compiler"
   you're on the Learning Edition - go back and source Pro/Ent.

## Compiler build numbers

The third dotted-number group on the CL banner identifies the
service pack level:

- `11.00.0000` = RTM (Visual C++ 5.0 original)
- `11.00.7016` = SP1
- `11.00.7022` = SP2 / SP3 (rebadged)

MK4 (released July 1998) was almost certainly built with SP3, so
you want 7022. The Pro CD on archive.org ("VCPP-5.00.iso", labeled
"Visual C++ 5.0 Professional") already ships 7022 - no patch needed.
