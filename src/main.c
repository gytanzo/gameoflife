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
            grid[i] = ' ';
            i += 1;
            x += 1;
        }
        else {
            grid[i] = ' ';
            i += 1;
            x += 1;
        }
    }
}

int neighborCount(char *grid, int index){
    int neighborNW = index - 82;
    int neighborN = index - 81;
    int neighborNE = index - 80;
    int neighborW = index - 1;
    int neighborE = index + 1;
    int neighborSW = index + 80;
    int neighborS = index + 81;
    int neighborSE = index + 82;
    int neighborCount = 0;
    if (neighborNW >= 0 && grid[neighborNW] == 'X'){
        neighborCount += 1;
    }
    if (neighborN >= 0 && grid[neighborN] == 'X'){
        neighborCount += 1;
    }
    if (neighborNE >= 0 && grid[neighborNE] == 'X'){
        neighborCount += 1;
    }
    if (neighborW >= 0 && grid[neighborW] == 'X'){
        neighborCount += 1;
    }
    if (neighborE <= 1944 && grid[neighborE] == 'X'){
        neighborCount += 1;
    }
    if (neighborSW <= 1944 && grid[neighborSW] == 'X'){
        neighborCount += 1;
    }
    if (neighborS <= 1944 && grid[neighborS] == 'X'){
        neighborCount += 1;
    }
    if (neighborSE <= 1944 && grid[neighborSE] == 'X'){
        neighborCount += 1;
    }
    return neighborCount;
}


int main(int argc, char *argv[]){
    char arr[24][81];
    char *grid = &arr[0][0];
    printGrid(grid);
    if (argc >= 2 && argc <= 3){
        int i = 0, x = 0, y = 0;
        char **matrix = parse_life(argv[1]);
        while (i != 1944){
            while (y != 24){
                while (x != 80){
                    char cell = matrix[y][x];
                    if (grid[i] != cell){
                        grid[i] = 'X';;
                    }
                    printf("%c", grid[i]);
                    x += 1;
                    i += 1;
                }
                grid[i] = '\n';
                printf("%c", grid[i]);
                x = 0;
                y += 1;
                i += 1;
            }
        }

        /* Here is where you are now: You have (hopefully) implemented a working function that correctly determines how
           many neighbors a particular cell has. In the limited testing you did, it seems to have worked perfectly.
           The next step is to set up a 3D array as seen in 5.2 so you can output alternating matricies. It is
           possible (and likely, at a second glance) that you will need to make the printing grid part of your main
           a helper function to allow you to easily and efficently print multiple consecutive graphs. Just some food
           for thought. Don't forget to start studying for math! */
        
        /* For a still block, the coordinates are 930, 931, 1011, and 1012. */
        
        /* Code for part three goes here */
        
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
