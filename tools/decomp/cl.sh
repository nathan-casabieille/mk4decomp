#!/usr/bin/env bash
#
# Wrapper that invokes MSVC 5.0's CL.EXE inside the MK4DECOMP Whisky
# bottle. Translates Unix-style paths to Wine paths, sets INCLUDE / LIB /
# PATH for the compiler, and forwards arguments.
#
# Usage:  cl.sh /Iinclude /c src/foo.c /Fobuild/foo.obj
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
. "$ROOT/config/msvc50.env" 2>/dev/null || {
    echo "ERROR: config/msvc50.env not found. Run ./tools/decomp/setup-msvc50.sh first." >&2
    exit 1
}

# Use the WINEPREFIX from the bottle path directly (bypasses bottle-name lookup).
# Fall back to whisky shellenv if the path-based approach doesn't set wine64 in PATH.
WHISKY_WINE_BIN="$HOME/Library/Application Support/com.isaacmarovitz.Whisky/Libraries/Wine/bin"
if [ -x "$WHISKY_WINE_BIN/wine64" ]; then
    export PATH="$WHISKY_WINE_BIN:$PATH"
    export WINE="wine64"
else
    eval "$(whisky shellenv "$MSVC50_BOTTLE" 2>/dev/null)" || true
fi
export WINEPREFIX="$MSVC50_PREFIX"
export WINEMSYNC=1

# Set MSVC env vars (CL.EXE reads these natively).
export WINEDEBUG=-all
WINE_INCLUDE='C:\MSVC5\Include'
WINE_LIB='C:\MSVC5\Lib'
WINE_PATH='C:\MSVC5\Bin;C:\windows\system32'

# Translate any host-relative paths in the args to Wine-relative form.
# Quick approach: just cd into the project root inside Wine via Z: drive.
WINE_ROOT="Z:$ROOT"
WINE_ROOT="${WINE_ROOT//\//\\}"

# Run with environment threaded into Wine.
exec wine64 \
    cmd /c \
    "set INCLUDE=$WINE_INCLUDE&& set LIB=$WINE_LIB&& set PATH=$WINE_PATH;%PATH%&& cd /d $WINE_ROOT&& C:\\MSVC5\\Bin\\CL.EXE $*"
