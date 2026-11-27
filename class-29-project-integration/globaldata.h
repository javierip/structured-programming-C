/**
 * Header : globaldata.h
 * Program: Biorhythm calculator
 * Author : Javier Iparraguirre
 *
 * Global constants and declarations of the global variables.
 * The variables are defined in globaldata.c
 */

#ifndef GLOBALDATA_H
#define GLOBALDATA_H

// Global constants
#define DAYS 50
#define PI 3.14159

// First date: birthday
extern int birthDay;
extern int birthMonth;
extern int birthYear;

// Second date: date of the calculation
extern int targetDay;
extern int targetMonth;
extern int targetYear;

// Calculated biorhythms, one value per day
extern double physical[DAYS];
extern double emotional[DAYS];
extern double intellectual[DAYS];

#endif
