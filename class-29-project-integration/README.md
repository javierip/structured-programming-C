# Class 29 - Project Integration

A biorhythm calculator split into several modules, to show how a C project is organized in `.c` and `.h` files. The user enters a birth date and a calculation date, and the program plots the physical (P), emotional (E) and intellectual (I) cycles for the 50 days around the calculation date.

Author: Javier Iparraguirre, based on an original program by Ricardo Coppo.

## Files

- **[main.c](./main.c)**: Reads the dates and calls the other modules.
- **[biorhythm.c](./biorhythm.c)** / **[.h](./biorhythm.h)**: Converts the dates into Julian day numbers and calculates each cycle with `sin`.
- **[reports.c](./reports.c)** / **[.h](./reports.h)**: Plots the three cycles in the terminal.
- **[globaldata.c](./globaldata.c)** / **[.h](./globaldata.h)**: Global variables shared by the modules (`extern` in the header, definition in the `.c` file).

Functions declared `static` are only visible inside their own module.

## Build and run with make

```sh
make        # build
make run    # build and run
make clean  # delete generated files
```

On Windows with MinGW, use `mingw32-make`.

## Build and run with Visual Studio

Open [biorhythm.sln](./biorhythm.sln) and press `Ctrl+F5`.
