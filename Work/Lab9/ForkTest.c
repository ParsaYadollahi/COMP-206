#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int x = 1;
    
    if (fork() == 0){
        printf("Child has x = %d\n", ++x);
    } else {
        printf("Parent has x = %d\n ", --x);
    }
}