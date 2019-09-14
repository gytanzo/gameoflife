#include <stdio.h>

int main(int argc, char *argv[]){
    int x = 42;
    int *px = &x;

    *px = 31;
    
    printf("%d\n", *px);
    return 0;
}
