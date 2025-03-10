#!/bin/bash
# filepath: clean_executables.sh

# Get the git repo root directory, regardless of where we are
REPO_ROOT=$(git rev-parse --show-toplevel 2>/dev/null)

if [ -z "$REPO_ROOT" ]; then
    echo "Error: Not in a git repository!"
    exit 1
fi

echo "Cleaning .out files from repository at $REPO_ROOT..."

# Change to the repository root
cd "$REPO_ROOT"

# Find and delete all .out files
find . -type f -name "*.out" -print -delete

echo "Cleanup complete!"