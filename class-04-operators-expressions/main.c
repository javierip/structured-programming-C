/* Program: Operators and Expressions
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <math.h> // Include this library to use math functions like sqrt()

/*
 * This simple program demonstrates how arithmetic operators work
 * and the different numeric variable types in C.
 */
int main() {
    // === 1. Variable Declaration ===

    // Fixed-point types (integers only)
    int counter = 20;
    int divisor = 6;

    // Floating-point type (numbers with a decimal part)
    double decimal_number = 7.5;
    double float_result;

    printf("--- Arithmetic Operations Demo ---\n\n");

    // === 2. Basic Arithmetic Operators ===

    // Addition, Subtraction, and Multiplication
    int sum = counter + 10;
    int product = divisor * 3;
    printf("Addition (20 + 10): %d\n", sum);
    printf("Product (6 * 3): %d\n", product);
    printf("Subtraction (20 - 6): %d\n", counter - divisor);


    // === 3. Integer Division Behavior ===

    // Dividing two integers performs integer division:
    // the decimal part is discarded (truncated).
    int integer_division = counter / divisor; // 20 / 6 = 3.33...
    printf("\nInteger Division (20 / 6): %d\n", integer_division); // Result is 3!

    // The modulo operator (%) returns the remainder of integer division
    int remainder = counter % divisor; // Remainder of 20 / 6
    printf("Modulo Operator (20 %% 6): %d\n", remainder); // Result is 2 (6*3=18, 20-18=2)


    // === 4. Type Conversion (Casting) ===

    // To get a decimal result, at least one operand must be cast
    // to a floating-point type. This is called explicit type coercion or 'casting'.
    float_result = (double)counter / divisor;
    printf("\nDivision with Casting ((double)20 / 6): %.2f\n", float_result); // Now the result is 3.33!


    // === 5. Precedence and Library Functions ===

    // Using a math library function (sqrt)
    // The inner addition (decimal_number + 1.5) is evaluated first due to parentheses.
    float_result = sqrt(decimal_number + 1.5); // sqrt(7.5 + 1.5) = sqrt(9.0)
    printf("\nSquare root of (7.5 + 1.5): %.2f\n", float_result);

    return 0;
}
