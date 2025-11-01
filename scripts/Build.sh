#!/bin/bash
set -e  # stop on first error

echo "[1] Building (Debug)..."
make config=debug -j$(nproc)

echo "[2] Running Sandbox..."
./bin/Debug-linux-x86_64/Sandbox/Sandbox
