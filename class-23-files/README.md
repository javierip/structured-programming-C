# Class 23 - File Operations

Simple C programs demonstrating file I/O operations in C.

## Programs

### text-example.c
Demonstrates text file operations including:
- Creating text files with `fprintf`
- Reading text files with `fscanf`
- File error handling
- File size calculation
- Different display modes

### structures-example.c
Shows binary file operations with structures:
- Writing structures to binary files
- Reading structures from binary files
- Structure data persistence

## Key Concepts

- File pointers (`FILE*`)
- File opening modes (`"r"`, `"w"`, `"rb"`, `"wb"`)
- Error checking (`NULL` pointer validation)
- File positioning (`fseek`, `ftell`)
- Formatted I/O (`fprintf`, `fscanf`)
- Binary I/O (`fread`, `fwrite`)

## Compilation

```bash
gcc -o text-example text-example.c
gcc -o main structures-example.c
```

## Usage

```bash
./text-example    # Text file operations demo
./main           # Binary file operations demo
```

## Learning Objectives

- File handling in C
- Error checking best practices
- Text vs binary file operations
- File positioning and size calculation
- Structured data persistence
