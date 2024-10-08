#!/bin/bash

# Set the root directory relative to the script's location
root="$(dirname "$(realpath "$0")")"
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

# License
if [  -f "${buildpath}/LICENSE" ]; then
    rm -rf "${buildpath}/LICENSE"
fi
# Build project
cmake ../
make -j$(nproc)

# Copy build output to executable directory
cd "$root" || exit
cp -rf "${buildpath}/furnace" "$executable"
cp -rf "${buildpath}/extern" "$executable"
cp "${furnacepath}/LICENSE" "$executable"

echo "Build complete"
