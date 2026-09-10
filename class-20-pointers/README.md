# Class 20 - Pointers

Examples of pointers in C: pointer arithmetic, arrays, and passing arguments to functions.

## Files

- **[main-simple-pointers.c](./main-simple-pointers.c)**: Walks an array of integers in four ways: with an index, with pointer arithmetic in a `while` loop, with pointer arithmetic in a `for` loop, and by using the array name as a pointer. Prints the address and the value of every element.
- **[main-pointers.c](./main-pointers.c)**: Functions that take pointers as arguments. Shows the difference between passing by value and by reference, returns two results through pointer arguments (`cartesian_to_polar`), and sorts an array of pointers (`int *ptr[]`) by the values they point to, leaving the data untouched.

## Build

```sh
gcc main-simple-pointers.c -o main-simple-pointers.exe
gcc main-pointers.c -o main-pointers.exe -lm
```

`main-pointers.c` uses `sqrt` and `atan2`, so it needs the math library (`-lm`).
