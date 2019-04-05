#include <stdio.h>
#include <stdlib.h>
#define Success = 0;

unsigned int stringLength(char *ptr){
    unsigned int length = 0;
    while (*ptr != '\0'){
        ptr++;
        length++;
    }
    return length;
}
int main(){
    char* s = "Testing an output";
    printf("%d\n" , stringLength(s)); // Result should be 17
}