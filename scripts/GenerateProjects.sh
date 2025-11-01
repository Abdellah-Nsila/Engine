#!/bin/bash
set -e  # stop on first error

echo "[1] Generating Makefiles..."
./vendor/bin/premake/premake5 gmake
