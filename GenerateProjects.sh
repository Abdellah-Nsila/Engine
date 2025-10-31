#!/bin/bash
set -e  # stop on first error

echo "[1/3] Generating Makefiles..."
./vendor/bin/premake/premake5 gmake

echo "[2/3] Building (Debug)..."
make config=debug -j$(nproc)

echo "[3/3] Running Sandbox..."
./bin/Debug-linux-x86_64/Sandbox/Sandbox
