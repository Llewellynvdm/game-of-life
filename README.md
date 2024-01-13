# Game of life
This is a demonstration in C++ of a game called [Game of life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) created by John Horton Conway in 1970

### The Game Rules
> At each step in time, the following transitions occur:
1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

## Building and Running

### Prerequisites

- CMake (Minimum Version 3.16)
- A C++ compiler (e.g., GCC, Clang)

### Building the Project

1. **Clone the repository**:
   ```bash
   git clone https://git.vdm.dev/Llewellyn/game-of-life.git
   ```
2. **Navigate to the project directory**:
   ```bash
   cd game-of-life
   ```
3. **Create and enter the build directory**:
   ```bash
   mkdir build && cd build
   ```
4. **Generate build system files with CMake**:
   ```bash
   cmake ..
   ```
5. **Compile the project**:
   ```bash
   cmake --build .
   ```
   
6. **Running the Project**:
   - After building, run the executable from the build directory.
   ```bash
   ./game-of-life
   ```

## License & Copyright
- Written by [Llewellyn van der Merwe](https://github.com/Llewellynvdm), April 2020
- Copyright (C) 2020. All Rights Reserved
- License [GNU/GPL Version 2 or later](http://www.gnu.org/licenses/gpl-2.0.html)

### Thank You! (2020/04)
- Originally Forked [Mario Talevski](https://github.com/MarioTalevski/game-of-life)
- [Champlain College](https://www.champlain.edu/) [SDEV-240-81A](https://classlist.champlain.edu/show/course/number/SDEV_240)
