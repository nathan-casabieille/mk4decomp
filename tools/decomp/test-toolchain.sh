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

# Use a directory under the project root so the wrappers (which cd into
# the project root inside Wine) can pass relative paths. Absolute Unix
# paths confuse cl.exe (it sees /tmp as an option flag).
TEST_DIR="$ROOT/build/toolchain-test"
mkdir -p "$TEST_DIR"
trap 'rm -rf "$TEST_DIR"' EXIT

cat > "$TEST_DIR/hello.c" <<'EOF'
/* Smoke test - compiles to a tiny PE main. */
int main(void) {
    return 42;
}
EOF

REL="build/toolchain-test"

echo "==> Compile..."
"$ROOT/tools/decomp/cl.sh" /nologo /c "/Fo${REL}\\hello.obj" "${REL}\\hello.c"

echo "==> Link..."
"$ROOT/tools/decomp/link.sh" /nologo /SUBSYSTEM:CONSOLE \
    "/OUT:${REL}\\hello.exe" "${REL}\\hello.obj" LIBC.LIB

echo "==> Run hello.exe (should exit 42)..."
eval "$(whisky shellenv "$MSVC50_BOTTLE" 2>/dev/null)"
set +e
WINEDEBUG=-all wine64 "$TEST_DIR/hello.exe" 2>/dev/null
RET=$?
set -e
file "$TEST_DIR/hello.exe"

if [ "$RET" = "42" ]; then
    echo
    echo "Toolchain OK (hello.exe returned 42)."
else
    echo
    echo "FAIL: hello.exe returned $RET, expected 42"
    exit 1
fi
