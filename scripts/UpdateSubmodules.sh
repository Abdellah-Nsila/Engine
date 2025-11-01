#!/bin/bash
set -e  # stop on first error

echo "[1] Updating submodules..."
git submodule update --remote --merge
