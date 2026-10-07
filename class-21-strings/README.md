# Class 21 - Strings

Examples of strings in C using the functions from `<string.h>`.

## Files

- **[main.c](./main.c)**: Compares two strings with `strcmp` and joins them with `strcpy` and `strcat`.
- **[main-strings-II.c](./main-strings-II.c)**: Stores names in a matrix of characters (`char data[][LINE_LENGTH]`) and sorts them alphabetically with insertion sort, using `strcmp` to compare and `strcpy` to move each name.

## Build

```sh
gcc main.c -o main.exe
gcc main-strings-II.c -o main-strings-II.exe
```

## Run

```sh
./main.exe
./main-strings-II.exe
```
