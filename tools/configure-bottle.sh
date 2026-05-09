#!/usr/bin/env bash
#
# Configures a Whisky bottle so that game/MK4.EXE runs without the
# "Mortal Kombat 4 is not installed. Run SETUP from the CD." popup.
#
# What this does (discovered by reverse-engineering the binary):
#   1. Sets Win98 compatibility on MK4.EXE and SETUP.EXE - the 1998
#      InstallShield SETUP refuses post-NT versions, and several startup
#      paths in MK4.EXE behave better in Win98 mode.
#   2. Writes the registry state MK4.EXE checks at startup. Two values are
#      queried (confirmed via WINEDEBUG=+reg trace):
#         - Path   (REG_SZ)     : install directory (chdir target)
#         - Config (REG_BINARY) : 588-byte settings blob normally written by
#                                 SETUP.EXE. A zero-filled blob is enough to
#                                 pass the existence check; in-game settings
#                                 will fall back to defaults.
#      MK4.EXE is a 32-bit binary; on wine64, HKLM\Software\* is redirected
#      to HKLM\Software\Wow6432Node\* for 32-bit processes - that's where we
#      write. HKCU is also written defensively.
#
# Assumes:
#   - Whisky is installed and a bottle named WINMK4 exists.
#   - The game files have been copied to drive_c/Games/MK4/.
#
# Usage: ./tools/configure-bottle.sh [BOTTLE_NAME]

set -euo pipefail

BOTTLE="${1:-WINMK4}"
INSTALL_PATH='C:\Games\MK4'
REG_KEY='Software\GT Interactive\Mortal Kombat 4\1.00'

if ! command -v whisky >/dev/null 2>&1; then
  echo "ERROR: whisky CLI not found. Run ./tools/setup-macos.sh first." >&2
  exit 1
fi

eval "$(whisky shellenv "$BOTTLE")"

echo "==> Setting Win98 compat for SETUP.EXE and MK4.EXE"
wine64 reg add 'HKCU\Software\Wine\AppDefaults\SETUP.EXE' /v Version /d win98 /f >/dev/null 2>&1
wine64 reg add 'HKCU\Software\Wine\AppDefaults\MK4.EXE'   /v Version /d win98 /f >/dev/null 2>&1

echo "==> Writing GT Interactive install key (HKLM + HKCU, under Wow6432Node for 32-bit visibility)"
WOW_KEY="Software\\Wow6432Node\\GT Interactive\\Mortal Kombat 4\\1.00"
CONFIG_BLOB=$(python3 -c 'print("00" * 588)')

for hive in HKLM HKCU; do
  wine64 reg add "${hive}\\${WOW_KEY}" /v Path /d "${INSTALL_PATH}" /f >/dev/null 2>&1
  wine64 reg add "${hive}\\${WOW_KEY}" /v Config /t REG_BINARY /d "${CONFIG_BLOB}" /f >/dev/null 2>&1
  # Also write to the un-redirected location, harmless and useful if Wine
  # behavior changes:
  wine64 reg add "${hive}\\${REG_KEY}" /v Path /d "${INSTALL_PATH}" /f >/dev/null 2>&1
  wine64 reg add "${hive}\\${REG_KEY}" /v Config /t REG_BINARY /d "${CONFIG_BLOB}" /f >/dev/null 2>&1
done

echo "==> Done. Launch MK4.EXE from the bottle."
