/**
 * Module : reports.c
 * Program: Biorhythm calculator
 * Author : Javier Iparraguirre
 *
 * Functions that print the biorhythms
 */

#include <stdio.h>
#include "reports.h"
#include "globaldata.h"

// Constants local to the module
#define LINE_WIDTH 70 // characters of the plot
#define CENTER 35     // column of the value 0
#define AMPLITUDE 20  // columns from 0 to +1 (or -1)

// Prototypes of the local functions of the module
static void printAxis(void);
static int toColumn(double value);

/**
 * Prints the biorhythm curves
 * The values were calculated in the biorhythm module and stored in
 * three global arrays. Each day is one line: it is prepared in memory
 * (array line[]) to place the characters BEFORE printing it.
 * Each value between -1 and +1 is converted into a column between
 * CENTER - AMPLITUDE and CENTER + AMPLITUDE.
 */
void printReports(void)
{
    int i, j;
    char line[LINE_WIDTH + 1]; // + 1 for the '\0' at the end

    printf("P: physical (23 days)  E: emotional (28 days)  I: intellectual (33 days)\n");
    printf("Day 0 is the date of the calculation\n\n");

    // Header
    printAxis();

    // Body: one line per day
    for (i = 0; i < DAYS; i++)
    {
        // Clear the line and draw the vertical axis
        for (j = 0; j < LINE_WIDTH; j++)
            line[j] = ' ';
        line[LINE_WIDTH] = '\0';
        line[CENTER] = '|';

        line[toColumn(physical[i])] = 'P';
        line[toColumn(emotional[i])] = 'E';
        line[toColumn(intellectual[i])] = 'I';

        // Days before (-) or after (+) the date of the calculation
        printf("%+4d %s\n", i - DAYS / 2, line);
    }

    // Footer
    printAxis();
}

/**
 * Converts a biorhythm value (-1 to +1) into a column of the line
 */
static int toColumn(double value)
{
    return (int)(value * AMPLITUDE + CENTER);
}

/**
 * Prints a horizontal axis on the screen
 */
static void printAxis(void)
{
    int i;

    printf("     "); // same width as the day number of each line
    for (i = 0; i < LINE_WIDTH; i++)
        printf("-");
    printf(">\n");
}
