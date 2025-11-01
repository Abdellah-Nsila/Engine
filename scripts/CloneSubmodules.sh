#!/bin/bash
set -e  # stop on first error

echo "[1] Cloning submodules..."
git submodule update --init --recursive
