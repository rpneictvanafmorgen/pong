$ErrorActionPreference = "Stop"

if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    Write-Host "CMake is not installed or is not on PATH."
    Write-Host "Install it from https://cmake.org/download/ or with:"
    Write-Host "  winget install Kitware.CMake"
    exit 1
}

cmake -S . -B build
cmake --build build

$debugExe = Join-Path $PSScriptRoot "..\build\Debug\pong.exe"
$releaseExe = Join-Path $PSScriptRoot "..\build\Release\pong.exe"
$singleConfigExe = Join-Path $PSScriptRoot "..\build\pong.exe"

if (Test-Path $debugExe) {
    & $debugExe
} elseif (Test-Path $releaseExe) {
    & $releaseExe
} elseif (Test-Path $singleConfigExe) {
    & $singleConfigExe
} else {
    Write-Host "Build finished, but pong.exe was not found in the usual locations."
    Write-Host "Look inside the build folder for the generated executable."
    exit 1
}
