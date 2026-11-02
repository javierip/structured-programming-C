/* Program: Bitwise operations demonstration
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 *
 * Values are written in hexadecimal (standard C); the comment next to
 * each one shows its bits. Each hex digit is exactly 4 bits.
 */

#include <stdio.h>

// Prints the 32 bits of value, grouped in sets of 4 for readability
void printBinary(unsigned int value) {
    unsigned int mask = 0x80000000; // 1 in the highest bit (bit 31)

    printf("\t");

    for (int i = 0; i < 32; i++) {
        if (value & mask) {
            printf("1");
        } else {
            printf("0");
        }

        mask = mask >> 1; // move the 1 to the next bit to check

        if ((i + 1) % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

void printSeparator(void) {
    printf("\n-------------------------------------------------\n");
}

// Basic bitwise operators: NOT, AND, OR, XOR
void demoBitwiseOperators(void) {
    printf("## 1. Basic Bitwise Operators ##\n\n");

    unsigned int X = 0xCD; // 1100 1101
    unsigned int Y = 0xDC; // 1101 1100

    printf("Value X:\n");
    printBinary(X);
    printf("Value Y:\n");
    printBinary(Y);
    printf("\n");

    printf("NOT ~X (inverts all bits):\n");
    printBinary(~X);

    printf("AND X & Y (1 only if both bits are 1):\n");
    printBinary(X & Y);

    printf("OR X | Y (1 if at least one bit is 1):\n");
    printBinary(X | Y);

    printf("XOR X ^ Y (1 if the bits are different):\n");
    printBinary(X ^ Y);

    printSeparator();
}

// Masks select which bits an operation changes
void demoMasks(void) {
    printf("## 2. Using Masks ##\n\n");

    unsigned int value = 0xAA; // 1010 1010
    printf("Original value:\n");
    printBinary(value);
    printf("\n");

    unsigned int maskAnd = 0xF0; // 1111 0000
    printf("AND mask (turns off the 4 low bits):\n");
    printBinary(maskAnd);
    printf("Result value & maskAnd:\n");
    printBinary(value & maskAnd);
    printf("\n");

    unsigned int maskOr = 0x0F; // 0000 1111
    printf("OR mask (turns on the 4 low bits):\n");
    printBinary(maskOr);
    printf("Result value | maskOr:\n");
    printBinary(value | maskOr);
    printf("\n");

    unsigned int maskXor = 0x0F; // 0000 1111
    printf("XOR mask (flips the 4 low bits):\n");
    printBinary(maskXor);
    printf("Result value ^ maskXor:\n");
    printBinary(value ^ maskXor);

    printSeparator();
}

// Shift operators move all the bits left or right
void demoShift(void) {
    printf("## 3. Shift Operators ##\n\n");

    // Left shift: zeros enter from the right. x << n is x * 2^n
    unsigned int a = 1;
    printf("a = %u:\n", a);
    printBinary(a);
    printf("a << 3 = %u (1 * 2^3):\n", a << 3);
    printBinary(a << 3);
    printf("\n");

    // Right shift on unsigned: zeros enter from the left. x >> n is x / 2^n
    unsigned int b = 136; // 1000 1000
    printf("b = %u:\n", b);
    printBinary(b);
    printf("b >> 2 = %u (136 / 2^2):\n", b >> 2);
    printBinary(b >> 2);
    printf("\n");

    // Right shift on a negative signed value: gcc, clang and Visual Studio
    // copy the sign bit (arithmetic shift), but the C standard leaves it to
    // the compiler. Prefer unsigned types for bit manipulation.
    int c = -8;
    printf("c = %d (negative numbers use two's complement):\n", c);
    printBinary((unsigned int)c);
    printf("c >> 2 = %d (the sign bit is copied):\n", c >> 2);
    printBinary((unsigned int)(c >> 2));

    printSeparator();
}

// Bit fields: the compiler packs several small fields into one word
void demoBitFields(void) {
    printf("## 4. Structures with Bit Fields ##\n\n");

    typedef struct {
        unsigned int red   : 8; // 8 bits each: values from 0 to 255
        unsigned int green : 8;
        unsigned int blue  : 8;
    } Color;

    Color myColor;

    myColor.red   = 0xFF;
    myColor.green = 0x00;
    myColor.blue  = 0xCC;

    printf("Red:   0x%02X\n", (unsigned int)myColor.red);
    printf("Green: 0x%02X\n", (unsigned int)myColor.green);
    printf("Blue:  0x%02X\n", (unsigned int)myColor.blue);
    printf("Size of Color: %zu bytes (3 fields in one int)\n",
           sizeof(Color));

    printSeparator();
}

// The same packing done by hand with shifts and masks.
// Unlike bit fields, here we decide exactly where each byte goes.
void demoPacking(void) {
    printf("## 5. Packing Bytes with Shifts and Masks ##\n\n");

    unsigned int red = 0xFF, green = 0x00, blue = 0xCC;

    // Pack: shift each byte to its place and join them with OR
    unsigned int color = (red << 16) | (green << 8) | blue;

    printf("color = (red << 16) | (green << 8) | blue = 0x%06X\n", color);
    printBinary(color);
    printf("\n");

    // Unpack: shift the byte down and keep only 8 bits with & 0xFF
    printf("Red:   (color >> 16) & 0xFF = 0x%02X\n", (color >> 16) & 0xFF);
    printf("Green: (color >> 8)  & 0xFF = 0x%02X\n", (color >> 8) & 0xFF);
    printf("Blue:   color        & 0xFF = 0x%02X\n", color & 0xFF);

    printSeparator();
}

int main(void) {
    demoBitwiseOperators();
    demoMasks();
    demoShift();
    demoBitFields();
    demoPacking();

    return 0;
}
