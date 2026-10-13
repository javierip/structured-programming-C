# Dynamic memory examples

## Contents

* `main.c`: asks how many 2D points are needed, allocates an array of `Point` structs with `malloc`, loads the points from the keyboard, sorts them by distance to the origin (selection sort) and releases the memory with `free`.

## Concepts

* `typedef struct` to define the `Point` type.
* `malloc` to reserve memory at runtime and checking its result against `NULL`.
* `free` to release the memory, and setting the pointer to `NULL` afterwards.
* Using a pointer as an array (`Point *arr` and `Point arr[]` are equivalent as parameters).
* Validating `scanf` input and clearing the input buffer.

## Build

The program uses `sqrt` from `<math.h>`, so on Linux and macOS you must link the math library with `-lm`.

Linux / macOS / MinGW (gcc):

```sh
gcc -std=c99 -Wall -Wextra main.c -o points -lm
```

Windows with Visual Studio (from a *Developer Command Prompt*):

```bat
cl /W4 main.c /Fe:points.exe
```

## Run

Linux / macOS:

```sh
./points
```

Windows:

```bat
points.exe
```

## Example session

```text
How many points will you need? 3

Point 0:
   x= 3
   y= 4

Point 1:
   x= 1
   y= 1

Point 2:
   x= -6
   y= 0


Loaded array
p[0]: X=   3.00  Y=   4.00 Dist=   5.00
p[1]: X=   1.00  Y=   1.00 Dist=   1.41
p[2]: X=  -6.00  Y=   0.00 Dist=   6.00


Sorted array
p[0]: X=   1.00  Y=   1.00 Dist=   1.41
p[1]: X=   3.00  Y=   4.00 Dist=   5.00
p[2]: X=  -6.00  Y=   0.00 Dist=   6.00
```
