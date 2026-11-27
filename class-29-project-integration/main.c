/**
 * Module : main.c
 * Program: Biorhythm calculator
 * Author : Javier Iparraguirre
 * E-mail : jiparraguirre@frbb.utn.edu.ar
 *
 * Main program: reads the dates and calls the other modules.
 * Based on an original program by Ricardo Coppo.
 */

#define _CRT_SECURE_NO_WARNINGS

// Standard libraries and the other modules of the program
#include <stdio.h>
#include <stdlib.h>
#include "biorhythm.h"
#include "reports.h"
#include "globaldata.h"

// Prototypes of the local functions of the module.
// "static" limits their visibility to this module only
static void readDates(void);
static void readDate(const char *prompt, int *day, int *month, int *year);

/**
 * Main program
 * The user enters the birth date and the date of the calculation.
 * The program plots the physical, emotional and intellectual
 * curves in the terminal.
 */
int main(void)
{
    readDates();
    calculateBiorhythms();
    printReports();

    return 0;
}

/**
 * Reads the birth date and the date of the calculation.
 * They are stored in global variables used by the other modules.
 */
static void readDates(void)
{
    readDate("Birth date       [dd mm yyyy]? ", &birthDay, &birthMonth, &birthYear);
    readDate("Calculation date [dd mm yyyy]? ", &targetDay, &targetMonth, &targetYear);
    printf("\n");
}

/**
 * Reads one date and exits the program if it is not valid
 */
static void readDate(const char *prompt, int *day, int *month, int *year)
{
    printf("%s", prompt);
    if (scanf("%d %d %d", day, month, year) != 3 ||
        *day < 1 || *day > 31 || *month < 1 || *month > 12)
    {
        printf("Invalid date\n");
        exit(EXIT_FAILURE);
    }
}
