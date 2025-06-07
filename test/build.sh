#!/bin/bash
set -e
# Find script directory (test/), then project root
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"
cmake -DLOGGER_BUILD_TEST=ON "$PROJECT_ROOT"
cmake --build .
./test/logger_test
