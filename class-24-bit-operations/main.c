/* Program: Bitwise operations demonstration
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h> 
#include <stdint.h>

// Function to print a 32-bit integer in binary format
// Displays bits grouped in sets of 4 for readability
void printBinary(unsigned int value) {
    unsigned int mask = 0x80000000; 

    printf("\t");

    for (int i = 0; i < 32; i++) {
        
        if (value & mask) {
            printf("1");
        } else {
            printf("0");
        }
        
        mask = mask >> 1;
        
        if ((i + 1) % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

// Demonstrates basic bitwise operators: NOT, AND, OR, XOR
void demoBitwiseOperators() {
    printf("## 1. Basic Bitwise Operators ##\n\n");

    unsigned int X = 0b11001101;
    unsigned int Y = 0b11011100;

    printf("Value X:\n");
    printBinary(X);
    printf("Value Y:\n");
    printBinary(Y);
    printf("\n");

    // NOT operator inverts all bits
    printf("Negation ~X (Inverts all bits):\n");
    printBinary(~X);

    // AND operator: result is 1 only when both bits are 1
    printf("AND (X & Y):\n");
    printBinary(X & Y);

    // OR operator: result is 1 when at least one bit is 1
    printf("OR (X | Y):\n");
    printBinary(X | Y);

    // XOR operator: result is 1 when bits are different
    printf("XOR (X ^ Y):\n");
    printBinary(X ^ Y);
    
    printf("\n-------------------------------------------------\n");
}

// Demonstrates the use of masks to manipulate specific bits
void demoMasks() {
    printf("## 2. Using Masks ##\n\n");
    
    unsigned int originalValue = 0b10101010;
    printf("Original Value:\n");
    printBinary(originalValue);
    printf("\n");

    // AND mask: used to turn off (set to 0) specific bits
    unsigned int mask_and = 0b11110000;
    printf("AND Mask (to turn off the 4 low bits):\n");
    printBinary(mask_and);
    printf("Result (value & mask_and):\n");
    printBinary(originalValue & mask_and);
    printf("\n");

    // OR mask: used to turn on (set to 1) specific bits
    unsigned int mask_or = 0b00001111;
    printf("OR Mask (to turn on the 4 low bits):\n");
    printBinary(mask_or);
    printf("Result (value | mask_or):\n");
    printBinary(originalValue | mask_or);
    printf("\n");

    // XOR mask: used to flip (toggle) specific bits
    unsigned int mask_xor = 0b00001111;
    printf("XOR Mask (to flip the 4 low bits):\n");
    printBinary(mask_xor);
    printf("Result (value ^ mask_xor):\n");
    printBinary(originalValue ^ mask_xor);
    
    printf("\n-------------------------------------------------\n");
}

// Demonstrates left and right shift operators
void demoShift() {
    printf("## 3. Shift Operators ##\n\n");

    // Left shift: moves bits to the left, zeros enter from the right
    // Equivalent to multiplying by powers of 2
    unsigned int X_left = 0b00000001;
    printf("Original (X_left = 1):\n");
    printBinary(X_left);
    printf("X_left << 3 (Move 3 to the left):\n");
    printBinary(X_left << 3);
    printf("\n");

    // Right shift on unsigned: logical shift, zeros enter from the left
    // Equivalent to dividing by powers of 2
    unsigned int X_right_unsigned = 0b10001000;
    printf("Original (X_right_unsigned = 136):\n");
    printBinary(X_right_unsigned);
    printf("X_right_unsigned >> 2 (Logical shift):\n");
    printBinary(X_right_unsigned >> 2);
    printf("\n");

    // Right shift on signed: arithmetic shift, sign bit is preserved
    signed int X_right_signed = 0b10000000000000000000000000001000;
    printf("Original (X_right_signed, negative):\n");
    printBinary((unsigned int)X_right_signed);
    printf("X_right_signed >> 2 (Arithmetic shift):\n");
    printBinary((unsigned int)(X_right_signed >> 2));

    printf("\n-------------------------------------------------\n");
}

// Demonstrates structures with bit fields for compact data storage
void demoBitFields() {
    printf("## 4. Structures with Bit Fields ##\n\n");

    // Bit fields allow specifying the exact number of bits for each field
    // This enables efficient packing of data into a single word
    typedef struct {
        unsigned int red   : 8;
        unsigned int green : 8;
        unsigned int blue  : 8;
    } Color;

    Color myColor;

    myColor.red   = 0xFF;
    myColor.green = 0x00;
    myColor.blue  = 0xCC;

    printf("Assigned values:\n");
    printf("Red: 0x%X\n", myColor.red);
    printf("Green: 0x%X\n", myColor.green);
    printf("Blue: 0x%X\n", myColor.blue);
    printf("\n");

    printf("Total size of 'Color' structure: %lu bytes\n\n", sizeof(Color));

    // View the packed integer representation
    unsigned int *pColorInteger = (unsigned int *)&myColor;
    
    printf("Integer representation (Hex):\n\t0x%08X\n", *pColorInteger);
    printf("Integer representation (Binary):\n");
    printBinary(*pColorInteger);

    printf("\n-------------------------------------------------\n");
}

int main() {
    demoBitwiseOperators();
    demoMasks();
    demoShift();
    demoBitFields();
    
    return 0;
}