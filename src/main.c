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
    int i = 0, x = 0;
    while (i != 1944){
        if (i == 0){
            grid[i] = 'a';
            i += 1;
            x += 1;
        }
        if (x == 80){
            grid[i] = '\n';
            x = 0;
            i += 1;
        }
        else {
            grid[i] = 'a';
            i += 1;
            x += 1;
        }
    }
}

int main(int argc, char *argv[]){
    char arr[24][81];
    char *grid = &arr[0][0];
    printGrid(grid);
    if (argc >= 2 && argc <= 3){
        int i = 0;
        while (i != 1944){
            printf("%c", grid[i]); 
            i += 1;
        }
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
