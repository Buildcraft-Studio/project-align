#!/bin/bash

root="$(pwd)"
furnacepath="${root}/furnace"
buildpath="${furnacepath}/build"
executable="${root}/exe"

# Ensure build directory exists
if [ ! -d "$buildpath" ]; then
    mkdir -p "$buildpath"
fi

# Ensure exe directory exists
if [ ! -d "$executable" ]; then
    mkdir -p "$executable"
fi

# Sync and update submodules
cd "$furnacepath" || exit
git submodule sync
git submodule update --init --recursive

# Reset CMake cache
cd "$buildpath" || exit
if [ -f "CMakeCache.txt" ]; then
    rm CMakeCache.txt
fi

# Build project
cmake ../
make -j$(nproc)

# Copy build output to executable directory
cd "$root" || exit
cp -rf "${buildpath}/furnace" "$executable"
cp -rf "${buildpath}/extern" "$executable"

echo "Build complete"
