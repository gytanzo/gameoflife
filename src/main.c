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

void evolution(char *grid, int index){
    int neighbors = neighborCount(grid, index);
    char currentState = grid[index];
    if (currentState == '\n'){
        grid[index] = '\n';
    }
    else if (currentState == 'X'){
        if (neighbors == 2 || neighbors == 3){
            grid[index] = 'X';
        }
        else {
            grid[index] = ' ';
        }
    }
    else if (currentState == ' '){
        if (neighbors == 3){
            grid[index] = 'X';
        }
        else {
            grid[index] = ' ';
        }
    }
}

int main(int argc, char *argv[]){
    char arr[24][81];
    char *grid = &arr[0][0];
    char grids[2][24][81];
    char *gridsFirst = &grids[0][0][0];
    char *gridsSecond = &grids[1][0][0];
    int finalGeneration = *argv[2] - '0';
    int y = 0, x = 0;
    printGrid(grid);
    if (argc >= 2 && argc <= 3){
        int i = 0;
        char **matrix = parse_life(argv[1]);
        while (i != 1944){
            while (y != 24){
                while (x != 80){
                    char cell = matrix[y][x];
                    if (grid[i] != cell){
                        grid[i] = 'X';
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
        
        
        int currentGeneration = 0;
        x = 0;
        y = 0;

        printGrid(gridsFirst);
        printGrid(gridsSecond);

        if (finalGeneration != 0){
            while (y != 24){
                while (x != 80){
                    grids[0][y][x] = arr[y][x];
                    x += 1;
                }
                grids[0][y][x] = '\n';
                x = 0;
                y += 1;
            }

            int j = 0;
            gridsSecond = gridsFirst;

            while (j != 1944){
                evolution(gridsSecond, j);
                printf("%c", gridsSecond[j]);
                j += 1;
            }

            currentGeneration = 1;

            while (currentGeneration != finalGeneration){
                gridsFirst = gridsSecond;
                int k = 0;
                while(k != 1944){
                    evolution(gridsSecond, k);
                    printf("%c", gridsSecond[k]);
                    k += 1;
                }
                currentGeneration += 1;
            }
        }
        return 0;
    }
    else if (argc <= 1){
        puts("Error: Invalid input (Reason: Too few arguments)");
        return 1;
    }
    else if (argc >= 3) {
        puts("Error: Invalid input (Reason: Too many arguments)");
        return 1;
    }
}
