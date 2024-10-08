# Set paths
$root = Get-Location
$furnacepath = Join-Path $root "furnace"
$buildpath = Join-Path $furnacepath "build"
$executable = Join-Path $root "exe"

# Ensure build directory exists
if (-not (Test-Path $buildpath)) {
    New-Item -Path $buildpath -ItemType Directory
}

# Ensure exe directory exists
if (-not (Test-Path $executable)) {
    New-Item -Path $executable -ItemType Directory
}

# Sync and update submodules
Set-Location $furnacepath
git submodule sync
git submodule update --init --recursive

# Reset CMake cache
Set-Location $buildpath
if (Test-Path "CMakeCache.txt") {
    Remove-Item "CMakeCache.txt"
}

# Run CMake and build the project
cmake ..
make -j (Get-WmiObject -Query "SELECT NumberOfLogicalProcessors FROM Win32_Processor").NumberOfLogicalProcessors

# Copy build output to executable directory
Set-Location $root
Copy-Item -Recurse -Force "$buildpath\furnace" $executable
Copy-Item -Recurse -Force "$buildpath\extern" $executable

Write-Host "Build complete"
