# Class 25 - Dynamic Memory

Example of dynamic memory in C with `malloc` and `free`.

## Files

- **[main.c](./main.c)**: Asks how many points are needed and allocates an array of `Point` structures with `malloc`, checking the result against `NULL`. Loads the points from the keyboard, sorts them by distance to the origin with selection sort, and releases the memory with `free`.

## Build

The `-lm` flag links the math library (`sqrt`); it is required on Linux and macOS.

```sh
gcc main.c -o main.exe -lm
```

## Run

```sh
./main.exe
```
