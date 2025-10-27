# Class 23 - File Operations

A simple C program demonstrating binary file operations with structures.

## Description

This program shows how to:

- Create an array of Student structures
- Save structures to a binary file
- Read structures from a binary file
- Display the data

## Structure

The `Student` structure contains:

- `id`: Student ID number
- `name`: Student name (up to 50 characters)
- `weight`: Student weight (float value)

## Compilation

```bash
gcc -o main main.c
```

## Execution

```bash
./main
```

## Output

The program will:

1. Generate 10 student records
2. Save them to `data.bin`
3. Read them back from the file
4. Display the results in a formatted table
