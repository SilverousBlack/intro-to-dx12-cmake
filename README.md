# Introduction to 3D Game Programming with DirectX 12 source code

## Introduction

This is an unofficial fork of the [sample code repo]((https://github.com/d3dcoder/d3d12book)) for [Frank D. Luna's](http://www.d3dcoder.net/default.htm) excellent book [Introduction to 3D Game Programming with DirectX 12](http://www.d3dcoder.net/d3d12.htm). No representation is made that the source code belongs to me, it's simply reproduced here for convenience (so you don't need to dig up the physical media of the book) and remains the copyright of Frank D. Luna.

## Building

### Prerequisites
- [x] Working [CMake](CMake.org) installation
- [x] Windows SDK (*preferably the latest* or `v10+`)[^1]
- [x] Working `Win32API`-compatible compiler (`MinGW`, `MSVC`, `Clang`) installation
- [x] GPU with DirectX 12 support (see your `dxdiag` for more details)

### Setup

1. Make a build directory
```cmd
$(REPOSITORY_DIRECTORY)> mkdir build
$(REPOSITORY_DIRECTORY)> cd build
```

2. Configure CMake project
```cmd
$(REPOSITORY_DIRECTORY)/build> cmake ../.
```

### Building and Targets

```cmd
$(REPOSITORY_DIRECTORY)/build> cmake --build . 
```
- Generic build-all command `ALL_BUILD` - bulk builds everything in the ***CURRENT*** target configuration (default: `Debug`).
  - Specify target with `--target [TARGET]` (e.g. `cmake --build . --target ch1.vector_algebra.playground`). 
  - Specify configuration with `--config [CONFIG]` (`Debug` | `Release` | `MinSizeRel` | `RelWithDebInfo`)

```cmd
$(REPOSITORY_DIRECTORY)/build> cmake --build . --target build-all
```
- Full Build-All Command `build-all` - bulk builds everything in ***ALL*** the target configurations.

[^1]: Sample applications shown here rely heavily on the `Win32API` (`windows.h`) and are designed to be run on a Windows machine as `DirectX` is owned by Microsoft. 

## Changes

Migrated to CMake.

## Considerations

If you're a novice looking to learn game development, this book and repo is probably not the best place to start, and you might be better off looking at resources for building games in Unreal Engine or Unity. This repo is mainly useful for professional and amateur game engine and graphics programmers wanting to learn how to work with DirectX 12. Needless to say, building a 3D game or rendering engine is _a lot of hard work_, and this book really only touches on the DX12 rendering aspect of such an engine, without touching on things like design, sound, gameplay, etc, so don't expect to master game development purely using this resource. 

## Additional resources

### General
* [Official book site](http://d3dcoder.net/default.htm)
* [Microsoft's DirectX Developer Blog](https://devblogs.microsoft.com/directx/)
* [Ryosuke's Learning DirectX 12 in 2023](https://whoisryosuke.com/blog/2023/learning-directx-12-in-2023/)

### Guides and tutorials
* [MSDN's Direct3D 12 Programming Guide](https://docs.microsoft.com/en-us/windows/win32/direct3d12/directx-12-programming-guide)
* [Jeremiah van Oosten's DirectX 12 tutorial](https://github.com/jpvanoosten/LearningDirectX12/tree/v0.0.1)
* [Braynzar Soft's DirectX 12 tutorials](https://www.braynzarsoft.net/viewtutorial/q16390-04-directx-12-braynzar-soft-tutorials)

### Samples
* [GPUOpen-LibrariesAndSDK's D3D12 sample](https://github.com/GPUOpen-LibrariesAndSDKs/HelloD3D12)
* [Microsoft's DirectX graphics samples](https://github.com/microsoft/DirectX-Graphics-Samples)
* [Microsoft's XBox ATG samples](https://github.com/microsoft/Xbox-ATG-Samples) and [GDK samples](https://github.com/microsoft/Xbox-GDK-Samples/)

### Related technologies

* [Microsoft's DirectXTK12](https://github.com/Microsoft/DirectXTK12) and [Chuck Walbourn's samples](https://github.com/walbourn/directxtk-samples)
