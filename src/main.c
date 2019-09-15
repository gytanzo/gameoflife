#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "life.h"

/* Be sure to read life.h and the other given source files to understand
 * what they provide and how they fit together.  You don't have to
 * understand all of the code, but you should understand how to call
 * parse_life() and clearterm().
 */

/* This is where your program will start.  You should make sure that it
 * is capable of accepting either one or two arguments; the first
 * argument (which is required) is a starting state in one of the Life
 * formats supported by parse_life(), and the second (which is optional)
 * is a number of generations to run before printing output and stopping.
 *
 * The autograder will always call your program with two arguments.  The
 * one-argument format (as described in the handout) is for your own
 * benefit!
 */

void printGrid(char *grid){
    int i = 0;
    while (i != 1920){ /* There are 1920 grids in an 80x24 grid */
        grid[i] = 'a'; /* I am using a's to make it more visible */
        i += 1; 
    }
}

/* This code does indeed print the correct amount of "a"s, at exactly 1920. The problem is I cannot figure out a method to seperate them in to x and y values.  Right now, I just get 1920 consecutive a's. */

int main(int argc, char *argv[]){
    char arr[24][80];
    char *grid = &arr[0][0];
    printGrid(grid);
    if (argc >= 2 && argc <= 3){
        return 0;
    }
    else if (argc <= 1){
        puts("Error: Invalid input (Reason: Too few arguments)");
        return 1;
    }
    else {
        puts("Error: Invalid input (Reason: Too many arguments)");
        return 1;
    }
}
