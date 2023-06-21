/* Program: Rock paper scissors
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int ROCK = 1;
    const int PAPER = 2;  
    const int SCISSORS = 3;

    int userPlay;
    int machinePlay;

    // Ask user to play
    printf("\n");
    printf("Let's play rock paper scissors!\n\n");
    printf("Insert:\n\n");
    printf("    1. rock\n");
    printf("    2. paper\n");
    printf("    3. scissors\n");
    printf("\n");
    printf("Option? ");
    scanf("%d", &userPlay);
    printf("\n");

    // Machine play
    machinePlay = 2;

    printf("One, two, three...\n");

    // Evaluate and print results

    if (userPlay == ROCK && machinePlay == ROCK)
        printf("Tie! The computer chose Rock. \n");
    if (userPlay == ROCK && machinePlay == PAPER)
        printf("You lost! The computer chose Paper.\n");
    if (userPlay == ROCK && machinePlay == SCISSORS)
        printf("You win! The computer chose Scissors. \n");

    if (userPlay == PAPER && machinePlay == ROCK)
        printf("You win! The computer chose Rock. \n");
    if (userPlay == PAPER && machinePlay == PAPER)
        printf("Tie! The computer chose Paper.\n");
    if (userPlay == PAPER && machinePlay == SCISSORS)
        printf("You lost! The computer chose Scissors. \n");

    if (userPlay == SCISSORS && machinePlay == ROCK)
        printf("You lost! The computer chose Rock. \n");
    if (userPlay == SCISSORS && machinePlay == PAPER)
        printf("You win! The computer chose Paper.\n");
    if (userPlay == SCISSORS && machinePlay == SCISSORS)
        printf("Tie! The computer chose Scissors. \n");

    printf("\n");
    printf("End of program.\n\n");

    return 0;
}
