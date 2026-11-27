/**
 * Module : globaldata.c
 * Program: Biorhythm calculator
 * Author : Javier Iparraguirre
 *
 * Definitions of the global variables shared by all the modules
 */

#include "globaldata.h"

// First date: birthday
int birthDay;
int birthMonth;
int birthYear;

// Second date: date of the calculation
int targetDay;
int targetMonth;
int targetYear;

// Calculated biorhythms
double physical[DAYS];
double emotional[DAYS];
double intellectual[DAYS];
