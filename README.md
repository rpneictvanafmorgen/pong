# Pong C++ Example

A small beginner-friendly Pong project written in C++ with [raylib](https://www.raylib.com/).

The goal of this project is to show the basic pieces of a simple game:

- creating a window
- running a game loop
- reading keyboard input
- moving objects over time
- checking collisions
- tracking score

## Controls

- `W`: move the left paddle up
- `S`: move the left paddle down
- `Esc`: close the game

## Requirements

Install these first:

- CMake 3.20 or newer
- A C++ compiler
  - Windows: Visual Studio 2022 with "Desktop development with C++"
  - macOS: Xcode command line tools
  - Linux: GCC or Clang

raylib is downloaded automatically by CMake the first time you configure the project.

## Build And Run

From this folder:

```powershell
.\scripts\run.ps1
```

Or run the CMake commands directly:

```powershell
cmake -S . -B build
cmake --build build
.\build\Debug\pong.exe
```

If you are using a single-config generator such as Ninja or Makefiles, the executable may be here instead:

```powershell
.\build\pong.exe
```

## Windows Setup Notes

If `cmake` is not recognized in PowerShell, install it:

```powershell
winget install Kitware.CMake
```

If you do not have a C++ compiler yet, install Visual Studio 2022 and select the workload named **Desktop development with C++**.

## Suggested Exercises

Good beginner changes to try:

- make the computer paddle slower or faster
- change the paddle colors
- add a winning score
- add a start screen
- let a second player control the right paddle with arrow keys
- make the ball speed reset after someone scores
