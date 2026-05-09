#!/usr/bin/env bash
#
# Wrapper that invokes MSVC 5.0's LINK.EXE inside the MK4DECOMP bottle.
# Same shape as cl.sh.
#
# Usage:  link.sh /OUT:build/MK4.matching.exe build/foo.obj build/bar.obj
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
. "$ROOT/config/msvc50.env" 2>/dev/null || {
    echo "ERROR: config/msvc50.env not found. Run ./tools/decomp/setup-msvc50.sh first." >&2
    exit 1
}

eval "$(whisky shellenv "$MSVC50_BOTTLE" 2>/dev/null)"
export WINEDEBUG=-all

WINE_LIB='C:\MSVC5\Lib'
WINE_PATH='C:\MSVC5\Bin;C:\windows\system32'

WINE_ROOT="Z:$ROOT"
WINE_ROOT="${WINE_ROOT//\//\\}"

exec wine64 \
    cmd /c \
    "set LIB=$WINE_LIB&& set PATH=$WINE_PATH;%PATH%&& cd /d $WINE_ROOT&& C:\\MSVC5\\Bin\\LINK.EXE $*"
