#!/bin/bash
set -e  # stop on first error

# --- Safety Check ---
# Ensure the script is run from the 'Engine/' directory (where the primake5.lua file is)
if [ ! -f "./premake5.lua" ]; then
    echo "Error: Must run this script from the project root directory ('Engine/')."
    exit 1
fi
# --------------------

echo "[1] Make Clean..."
make clean

echo "[2] Deleting Makefiles..."
# Use rm without -r when deleting specific files
rm -f ./Makefile ./Engine/Makefile ./Sandbox/Makefile

echo "[3] Deleting bin/bin-int directories..."
# Use -rf here because 'bin' and 'bin-int' are directories with contents
rm -rf bin bin-int

echo "Cleanup complete."
