# Class 23 - Integration

Example that combines structures, pointers, dynamic memory and binary files: a linked list saved to a file and loaded back.

## Files

- **[main.c](./main.c)**: Builds a linked list of three nodes (`1 2 3`) with `malloc` and writes the `int` value of each node to `linked_list.dat` with `fwrite`. Then frees the list, reads the file back with `fread`, rebuilds a new list by appending each value at the tail, prints it and frees it.

Only the data is saved, not the `next` pointers: memory addresses are meaningless once the program ends, so the links are rebuilt when the file is loaded.

## Build

```sh
gcc main.c -o main.exe
```

## Run

```sh
./main.exe
```

The program creates `linked_list.dat` (12 bytes: three `int` values) in the directory it runs from. Expected output:

```
Linked list saved to file.
Linked list: 1 2 3
Linked list loaded from file.
Linked list: 1 2 3
```
