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

You need two tools before you can build the project:

- **CMake 3.20 or newer**: generates the build files for your computer.
- **A C++ compiler**: turns the source code into an executable program.

raylib is downloaded automatically by CMake the first time you configure the project.

### Windows

Install CMake from PowerShell:

```powershell
winget install Kitware.CMake
```

Install a C++ compiler:

1. Download and install [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/).
2. In the installer, select **Desktop development with C++**.
3. Finish the install, then restart PowerShell so it can find the new tools.

To check your setup:

```powershell
cmake --version
```

If `cmake` is still not recognized, restart your terminal or your computer.

### macOS

Install the Xcode command line tools:

```bash
xcode-select --install
```

Install CMake with Homebrew:

```bash
brew install cmake
```

### Linux

On Ubuntu or Debian:

```bash
sudo apt update
sudo apt install build-essential cmake
```

On Fedora:

```bash
sudo dnf install gcc-c++ cmake
```

On Arch Linux:

```bash
sudo pacman -Syu base-devel cmake
```

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

## Suggested Exercises

Good beginner changes to try:

- make the computer paddle slower or faster
- change the paddle colors
- add a winning score
- add a start screen
- let a second player control the right paddle with arrow keys
- make the ball speed reset after someone scores
