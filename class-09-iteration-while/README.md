# Class 09 - Iteration: while

Examples of repetition structures in C: `while`, `do-while`, `break`, and `continue`.

## Programs

### main-while.c — Secret Number

A guessing game where the user tries to find a randomly generated number.

- A secret number between 0 and 99 is generated with `rand()`
- The user enters guesses until the correct number is found
- Feedback is given on each wrong guess (too high / too low)

**Concepts:** `while`, `rand()`, `srand()`, `time()`

---

### main-do-while.c — Sports Selector

Displays a sport selection menu that repeats until the user exits.

- A menu is shown with sport options
- The user selects an option and sees the chosen sport
- The loop continues until the exit option is selected

**Concepts:** `do-while`, menu-driven loops

---

### main-break.c — Break Example

Reads values and prints their double, stopping when the user enters -1.

- The loop runs indefinitely until `-1` is entered
- `break` is used to exit the loop on the sentinel value

**Concepts:** `while`, `break`, sentinel value

---

### main-continue.c — Continue Example

Demonstrates skipping iterations with `continue` inside a `while` loop.

**Concepts:** `while`, `continue`

