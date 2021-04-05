# Rotating a Cube
<!-- #region Shields -->
[![GitHub commits since latest release (by date)](https://img.shields.io/github/commits-since/nico-castell/Cube-Rotation/latest?color=informational&label=Commits%20since%20last%20release&logo=Git&style=flat-square)](https://github.com/nico-castell/Cube-Rotation/commits)
[![GitHub release](https://img.shields.io/github/v/release/nico-castell/Cube-Rotation?color=informational&label=Release&logo=GitHub&style=flat-square)](https://github.com/nico-castell/Cube-Rotation/releases)
[![GitHub](https://img.shields.io/github/license/nico-castell/Cube-Rotation?color=informational&label=License&logo=GitHub&style=flat-square)](LICENSE)
[![Lines of code](https://img.shields.io/tokei/lines/github/nico-castell/Cube-Rotation?color=informational&label=Lines%20of%20code&logo=c%2B%2B&style=flat-square)](https://github.com/nico-castell/Cube-Rotation)
<!-- #endregion -->

Use a tri-dimensional array as a cube and rotate it layer by layer.

- View [Program](src/Program.cpp).
- View [CMakeLists](CMakeLists.txt).

## Usage

### Build

The project uses *CMake* to generate build instructions. The following instructions work on **Unix-like** systems that suport **Makefiles**.

```bash
$ cd /path/to/cloned_repo
$ cmake -S . -B build
$ cd build
$ make
```

### Usage

You must first build the program to be able to run it.

```bash
$ cd /path/to/cloned_repo
$ build/cube-rotation
Original:
001 002 003     004 005 006     007 008 009
010 011 012     013 014 015     016 017 018
019 020 021     022 023 024     025 026 027

Modified:
002 003 006     001 005 009     004 007 008
011 012 015     010 014 018     013 016 017
020 021 024     019 023 027     022 025 026
```

### Modifying the cube's dimensions

To modify the size of the cube, you have to edit the [source file](src/Program.cpp):

```cpp
#include <iomanip>
#include <iostream>

#define R 3  // Rows aka Y
#define C 3  // Columns aka X
#define D 3  // Depth aka Z

/* Code... */
```

- By modifying the values defined for `R`, `C`, and `D` you can modify the dimensions of the cube.
- After modifying the file you have to recompile:
  ```bash
  $ cd /path/to/cloned_repo
  $ cd build
  $ make
  ```
- After recompiling, you can run the file again:
  ```bash
  $ cd /path/to/cloned_repo
  $ build/cube-rotation
  ```

## License

This repository is available under the [MIT License](LICENSE). All contributions to this repository are under the same license.

> Live long, and prosper  
> Spock
