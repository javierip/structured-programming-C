# Class 22 - Structures

Example of structures in C: defining a type with `typedef struct` and working with an array of structures.

## Files

- **[main.c](./main.c)**: Defines a `Person` structure (name, surname and age) and fills an array with five famous computer scientists. Prints the list, sorts it by age, and then by surname (using `strcmp`), with bubble sort. Swaps whole structures with a simple assignment (`temp = students[j+1];`).

## Build

```sh
gcc main.c -o main.exe
```

## Run

```sh
./main.exe
```
