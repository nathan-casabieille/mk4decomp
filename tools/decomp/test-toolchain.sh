#!/usr/bin/env bash
#
# Smoke test for the MSVC 5.0 toolchain. Compiles a tiny .c file and
# verifies the wrapper chain works end-to-end. Run after
# setup-msvc50.sh once you've placed MSVC 5.0 binaries in the bottle.
#
# Usage:  ./tools/decomp/test-toolchain.sh
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
. "$ROOT/config/msvc50.env" 2>/dev/null || {
    echo "ERROR: setup-msvc50.sh hasn't been run yet."
    exit 1
}

# Sanity-check that CL.EXE is in the bottle.
if [ ! -f "$MSVC50_ROOT/Bin/CL.EXE" ]; then
    echo "ERROR: $MSVC50_ROOT/Bin/CL.EXE not found."
    echo "       Place MSVC 5.0 binaries in the bottle (see"
    echo "       $MSVC50_ROOT/README.txt for the layout)."
    exit 1
fi

TMP="$(mktemp -d /tmp/mk4-toolchain-test.XXXXXX)"
trap 'rm -rf "$TMP"' EXIT

cat > "$TMP/hello.c" <<'EOF'
/* Smoke test — compiles to a tiny PE main. */
int main(void) {
    return 42;
}
EOF

echo "==> Compile..."
"$ROOT/tools/decomp/cl.sh" /nologo /c /Fo"$TMP\\hello.obj" "$TMP\\hello.c"

echo "==> Link..."
"$ROOT/tools/decomp/link.sh" /nologo /SUBSYSTEM:CONSOLE /OUT:"$TMP\\hello.exe" "$TMP\\hello.obj"

echo "==> Output:"
ls -la "$TMP/"
file "$TMP/hello.exe"

echo
echo "Toolchain OK."
