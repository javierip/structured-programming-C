# Class 21 - Strings

Examples of strings in C using the functions from `<string.h>`.

## Files

- **[main.c](./main.c)**: Compares two strings with `strcmp` and joins them with `strcpy` and `strcat`.
- **[main-strings-II.c](./main-strings-II.c)**: Stores names in a matrix of characters (`char data[][LINE_LENGTH]`) and sorts them alphabetically with insertion sort, using `strcmp` to compare and `strcpy` to move each name.
- **[main-locale.c](./main-locale.c)** (in Spanish): Spanish text in UTF-8, where `strlen` counts bytes (`"año"` is 4) and `toupper` does not convert `ñ`. Uses `setlocale` from `<locale.h>` to print numbers (`1234,56`) and dates in Spanish.

The source of `main-locale.c` is UTF-8: Visual Studio needs the `/utf-8` option, and Linux needs a Spanish locale (`sudo locale-gen es_AR.UTF-8`).

## Build

```sh
gcc main.c -o main.exe
gcc main-strings-II.c -o main-strings-II.exe
gcc main-locale.c -o main-locale.exe
```

## Run

```sh
./main.exe
./main-strings-II.exe
./main-locale.exe
```
