# Class 03 — Algorithms and Sequences

## Concepts covered

| Concept | Description |
|---|---|
| **Algorithm** | A finite sequence of steps that always produces a correct result |
| **Sequential structure** | Instructions execute in the exact order they are written |
| **Variable** | A named storage location that holds a value of a specific type |
| **Data types** | `int` for integers, `double` for floating-point numbers |
| **Identifier rules** | Start with letter/`_`; letters and digits only; case-sensitive; no reserved keywords |
| **Assignment** | `=` writes a new value into a variable, replacing the previous one |
| **Console I/O** | `printf` to print output; `scanf` to read input |

## Format specifiers

| Type | `scanf` | `printf` |
|---|---|---|
| `int` | `%d` | `%d` |
| `double` | `%lf` | `%lf` or `%.2lf` (2 decimal places) |

## Build and run

```bash
gcc main.c -o main
./main
```

## Sample output

```
=== Weight gain calculator ===

Enter your age (years)        : 30
Enter your birth weight (kg)  : 3.3
Enter your current weight (kg): 65.0

--- Results ---
Age           : 30 years
Current weight: 65.00 kg
Weight gain   : 61.70 kg
```

## Exercises

1. Add a variable `height` (in meters) and print the BMI: `bmi = weight / (height * height)`.
2. Declare a variable `name_length` of type `int`, assign it a value directly (no `scanf`), and print it.
3. Swap the order of the two `scanf` calls and observe what happens to the output — why?
