# Sablefish
## Overview
Sablefish is a free, open-source chess engine. Although currently under early development, Sablefish will be a top rival to Stockfish (maybe...)

## Licensing
Sablefish is free and distributed under the MIT License. See `LICENSE` for details.

## Development Environment Setup
Pre-requisites:
* Code Editor -- Visual Studio Code (VSCode) is recommended
* C++20 Compiler
* CMake

### Code Editor
VSCode is the recommended editor for building Sablefish, as it is a lightweight alternative to Visual Studio and it can easily support the MSVC compiler and CMake.

To clone the Sablefish repository, open a Terminal window, navigate to a folder where you want your local copy to exist, and run the following command:

`git clone https://github.com/corbin-phipps/Sablefish.git`

### Compiler
A C++ compiler with support for C++ 20 library features is required to build Sablefish.

For Windows, the Visual Studio 2022 Build Tools will provide the necessary requirements. Under the "Individual Components" tab at the top of the Visual Studio Installer, select:
* C++ CMake tools for Windows
* MSVC v143 - VS 2022 C++ x64/x86 build tools (Latest)
* C++ Build Tools core features
* C++ core features

For Linux, g++ or llvm/clang can likely be used, although this has not been tested.

### CMake
CMake is used to manage the build process for Sablefish.

For seamless CMake integration into VSCode, install the CMake Tools extension.

### How to Build
Once you have the CMake Tools extension installed in VSCode and the Sablefish repo cloned, open the VSCode Command Palette with `Ctrl+Shift+p` and select `CMake: Delete Cache and Reconfigure`. This will produce a `build` directory with the necessary build files.

Next, select `CMake: Build` to build the Sablefish project. This will build all CMake targets with the Debug configuration.

### How to Run
Once the project is built, the project's executable (`app.exe`) and the project's tests (CTests) are available to run.

#### Project Executable
In a Terminal window, navigate to `Sablefish/build/apps/Debug` and run `./app.exe` to run the project. For now, this simply prints a welcome message and an empty board.

#### CTests
In VSCode, open the Command Palette with `Ctrl+Shift+p` and select `CMake: Run Tests` to run the available Sablefish tests.
