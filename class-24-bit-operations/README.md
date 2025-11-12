# Class 24 - Bitwise Operations

A C program demonstrating bitwise operators and bit manipulation techniques.

## Description

This program demonstrates fundamental bitwise operations in C, including:
- Basic bitwise operators (NOT, AND, OR, XOR)
- Bit masking techniques
- Shift operators (left and right)
- Bit fields in structures

## Program Structure

### Functions

**`printBinary(unsigned int value)`**
- Prints a 32-bit integer in binary format
- Groups bits in sets of 4 for readability

**`demoBitwiseOperators()`**
- Demonstrates NOT (~), AND (&), OR (|), and XOR (^) operators
- Shows how each operator affects bit patterns

**`demoMasks()`**
- Shows how to use masks to manipulate specific bits
- Demonstrates turning bits on/off and flipping bits

**`demoShift()`**
- Demonstrates left shift (<<) and right shift (>>) operators
- Shows logical shift (unsigned) vs arithmetic shift (signed)

**`demoBitFields()`**
- Shows how to use bit fields in structures
- Demonstrates compact data storage with RGB color example

## Key Concepts

- Bitwise operators: `~`, `&`, `|`, `^`
- Shift operators: `<<`, `>>`
- Bit masking for selective bit manipulation
- Bit fields for memory-efficient structures
- Logical vs arithmetic right shift

## Compilation

```bash
gcc -o main main.c
```

## Usage

```bash
./main
```

## Output

The program displays binary representations of values and demonstrates how different bitwise operations affect them.

## Learning Objectives

- Understanding bitwise operations
- Bit manipulation techniques
- Memory-efficient data structures
- Low-level data representation

## Author

Javier Iparraguirre  
E-mail: jiparraguirre@frbb.utn.edu
