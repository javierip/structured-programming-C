# Class 05 — Information Representation

Covers how data is stored and represented in memory: number bases, character encoding, data type sizes, and implicit vs. explicit type conversion.

## Concepts Covered

| Concept | Description |
| --- | --- |
| **Binary representation** | Numbers are stored in base 2; conversion from decimal uses successive division by 2, reading remainders bottom-up |
| **Hexadecimal** | Base-16 notation used as a compact way to express binary values; printed with `%X` |
| **ASCII encoding** | Each `char` is stored as a numeric value (0–127); the same byte can be printed as a character (`%c`), decimal (`%d`), or hex (`%X`) |
| **`char` type** | Stores a single character as 1 byte; its integer value is its ASCII code |
| **Data type sizes** | Each type occupies a fixed number of bytes: `char` 1, `short` 2, `int` 4, `long` 8, `double` 8 |
| **`sizeof` operator** | Returns the size in bytes of a type or variable at compile time |
| **Implicit conversion** | Happens automatically when mixing types; integer division truncates the decimal part even when assigned to `double` |
| **Explicit casting** | `(double)` forces a value to be treated as floating-point before the operation, preserving the decimal result |
| **Type limits** | `<limits.h>` provides constants like `INT_MAX`, `INT_MIN`, `LONG_MAX`, `LLONG_MAX` |
| **Overflow** | Assigning a value outside a type's range wraps around silently (e.g. `LONG_MAX` into `short` gives `-1`) |

## Format Specifiers

| Specifier | Prints |
| --- | --- |
| `%c` | Character |
| `%d` | Signed decimal integer |
| `%ld` | Signed `long` decimal |
| `%lld` | Signed `long long` decimal |
| `%lf` | `double` |
| `%4.2lf` | `double` with width 4 and 2 decimal places |
| `%X` | Unsigned hexadecimal (uppercase) |

## Key Takeaway: Implicit vs. Explicit Conversion

```c
int a = 5, b = 10;

double result = a / b;            // implicit: int division = 0, then 0 stored as 0.000000
double result = (double)a / b;   // explicit: 5.0 / 10 = 0.500000
```

Implicit conversion happens **after** the operation — the division is already truncated. Explicit casting happens **before**, changing how the operation is evaluated.

## Build and Run

```bash
sh build.sh
```

The script compiles the program, places the binary in `output/`, and runs it automatically.

## Sample Output

```text
 Silent and explicit conversions
Result of int division 0.000000
...
```
