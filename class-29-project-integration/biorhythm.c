/**
 * Module : biorhythm.c
 * Program: Biorhythm calculator
 * Author : Javier Iparraguirre
 *
 * Functions that calculate the biorhythms
 */

#include <math.h>
#include "biorhythm.h"
#include "globaldata.h"

// Constants local to the module: length of each cycle in days
#define PHYSICAL_PERIOD 23
#define EMOTIONAL_PERIOD 28
#define INTELLECTUAL_PERIOD 33

// Prototypes of the local functions of the module
static void calculatePhysical(void);
static void calculateEmotional(void);
static void calculateIntellectual(void);
static int calculateJulianDay(int day, int month, int year);

/**
 * Calculates the three biorhythms
 * Input : the two dates stored in the global variables
 * Output: the global arrays where the biorhythms are stored
 */
void calculateBiorhythms(void)
{
    calculatePhysical();
    calculateEmotional();
    calculateIntellectual();
}

/**
 * Physical biorhythm calculator
 * Uses two dates: the birthday and the date of the calculation.
 * The function is calculated DAYS times. The first day is DAYS/2
 * days before the date of the calculation, and the last one is
 * DAYS/2 days after it.
 * Input :
 *     Global variables: birthDay, birthMonth, birthYear,
 *                       targetDay, targetMonth, targetYear
 * Output:
 *     Global array: physical[i]  0 <= i < DAYS
 */
static void calculatePhysical(void)
{
    // Convert the dates to Julian day numbers
    int julian1 = calculateJulianDay(birthDay, birthMonth, birthYear);
    int julian2 = calculateJulianDay(targetDay, targetMonth, targetYear);

    // Days lived at the first position of the array (index 0)
    int daysDifference = julian2 - julian1;
    int tInitial = daysDifference - DAYS / 2;

    // Calculate the biorhythm
    int i;
    for (i = 0; i < DAYS; i++)
    {
        double t = (double)(tInitial + i);
        physical[i] = sin(2 * PI * t / PHYSICAL_PERIOD);
    }
}

/**
 * Emotional biorhythm calculator
 * Same as calculatePhysical(), with the emotional period.
 * Output:
 *     Global array: emotional[i]  0 <= i < DAYS
 */
static void calculateEmotional(void)
{
    // Convert the dates to Julian day numbers
    int julian1 = calculateJulianDay(birthDay, birthMonth, birthYear);
    int julian2 = calculateJulianDay(targetDay, targetMonth, targetYear);

    // Days lived at the first position of the array (index 0)
    int daysDifference = julian2 - julian1;
    int tInitial = daysDifference - DAYS / 2;

    // Calculate the biorhythm
    int i;
    for (i = 0; i < DAYS; i++)
    {
        double t = (double)(tInitial + i);
        emotional[i] = sin(2 * PI * t / EMOTIONAL_PERIOD);
    }
}

/**
 * Intellectual biorhythm calculator
 * Same as calculatePhysical(), with the intellectual period.
 * Output:
 *     Global array: intellectual[i]  0 <= i < DAYS
 */
static void calculateIntellectual(void)
{
    // Convert the dates to Julian day numbers
    int julian1 = calculateJulianDay(birthDay, birthMonth, birthYear);
    int julian2 = calculateJulianDay(targetDay, targetMonth, targetYear);

    // Days lived at the first position of the array (index 0)
    int daysDifference = julian2 - julian1;
    int tInitial = daysDifference - DAYS / 2;

    // Calculate the biorhythm
    int i;
    for (i = 0; i < DAYS; i++)
    {
        double t = (double)(tInitial + i);
        intellectual[i] = sin(2 * PI * t / INTELLECTUAL_PERIOD);
    }
}

/**
 * Converts a Gregorian date into a Julian day number.
 * Julian day numbers count the days consecutively since
 * January 1st, 4713 BC, so subtracting two of them gives the
 * number of days between two dates.
 * Algorithm: Claus Tondering, Calendar FAQ (www.tondering.dk)
 */
static int calculateJulianDay(int day, int month, int year)
{
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;

    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}
