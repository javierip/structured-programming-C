# Class 28 - Bitwise Operations

Examples of bitwise operators and bit manipulation in C.

## Files

- **[main.c](./main.c)**: Prints values in binary to show the bitwise operators (`~`, `&`, `|`, `^`), masks to turn bits off, on or flip them, and the shift operators (`<<`, `>>`). Ends with two ways to pack three color bytes into one integer: a structure with bit fields, and by hand with shifts and masks.

Values are written in hexadecimal (each hex digit is 4 bits), because binary literals such as `0b1010` are only standard since C23.

## Build

```sh
gcc main.c -o main.exe
```

## Run

```sh
./main.exe
```
