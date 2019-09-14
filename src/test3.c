#include <stdio.h>

int main(int argc, char *argv[]){
    char arr[24][80];
    char *grid = &arr[0][0];
    int i = 0;

    while (i != 1920){
        grid[i] = 'a';
        i += 1;
    }

    printf("%c\n", grid[458]);
}
