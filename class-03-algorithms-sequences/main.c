/* Program: Variables and Sequences
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu.ar
 *
 * Demonstrates: variable declaration, the assignment instruction,
 * the sequential control structure, and console I/O with scanf/printf.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    /* --- Variable declarations ---
     * Every variable must be declared before it is used.
     * Syntax:  <type> <identifier>;
     *
     *   int    -> integer numbers  (e.g. 30)
     *   double -> floating-point numbers (e.g. 65.5)
     *
     * Identifier rules:
     *   - Must start with a letter or underscore (_)
     *   - Subsequent characters: letters or digits only
     *   - Case-sensitive: age != Age
     *   - Cannot be a reserved keyword (int, double, return, ...)
     */
    int    age;
    double birth_weight, current_weight, weight_gain;

    /* --- Sequential structure ---
     * Instructions execute in the exact order they are written.
     * Changing the order changes (or breaks) the result.
     */

    printf("=== Weight gain calculator ===\n\n");

    /* INPUT: scanf reads a value from the keyboard into a variable.
     *   %d  -> format specifier for int
     *   %lf -> format specifier for double
     *   &   -> address-of operator: tells scanf WHERE to store the value
     */
    printf("Enter your age (years)       : ");
    scanf("%d", &age);

    printf("Enter your birth weight (kg) : ");
    scanf("%lf", &birth_weight);

    printf("Enter your current weight (kg): ");
    scanf("%lf", &current_weight);

    /* ASSIGNMENT: writing a variable overwrites its previous value.
     * The right-hand side is evaluated first, then stored in weight_gain.
     */
    weight_gain = current_weight - birth_weight;

    /* OUTPUT: printf prints values to the console.
     *   %d   -> int
     *   %.2lf -> double, 2 decimal places
     */
    printf("\n--- Results ---\n");
    printf("Age           : %d years\n",   age);
    printf("Current weight: %.2lf kg\n",   current_weight);
    printf("Weight gain   : %.2lf kg\n",   weight_gain);

    return 0;
}
