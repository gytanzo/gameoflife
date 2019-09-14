#include <stdio.h>

int main(int argc, char *argv[]){
    int arr[3][4] = {
        {0, 1, 2, 3} ,
        {4, 5, 6, 7} ,
        {8, 9, 10, 11}
    };

    int *grid = &arr[0][0];
    grid[5] = 9;
    
    
    printf("%d\n", grid[5]);
}
