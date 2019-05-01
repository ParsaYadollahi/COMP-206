#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z;
    z = x+y;
    printf("%d\n", z);
    return z;
}